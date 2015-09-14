/*
 *  RBT FPGA driver
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <asm/uaccess.h>


#define RBT_VER_OFFSET		0
#define RBT_SYS_OFFSET		1
#define RBT_INT_OFFSET		2
#define RBT_TPRD_OFFSET		3
#define RBT_PPRD_OFFSET		4
#define RBT_TCNT_OFFSET		5
#define RBT_PCTRL_OFFSET	8
#define RBT_PDDAT_OFFSET	9
#define RBT_PMODE_OFFSET	10
#define RBT_CABSTA_OFFSET	11
#define RBT_CZSTA_OFFSET	12
#define RBT_CMODE_OFFSET	13
#define RBT_SLCON_OFFSET	14
#define RBT_UMUX_OFFSET		15

#define RBT_PnPRD_OFFSET(n)		(0x10+4*(n))
#define RBT_PnCNT_OFFSET(n)		(0x11+4*(n))
#define RBT_PnPRDD_OFFSET(n)	(0x12+4*(n))
#define RBT_PnACC_OFFSET(n)		(0x13+4*(n))
#define RBT_CnDAT_OFFSET(n)		(0x30+2*(n))
#define RBT_CnZDL_OFFSET(n)		(0x31+2*(n))

#define RBT_INPUT_OFFSET	(0x40)
#define RBT_OUTPUT_OFFSET	(0x60)


#define RBT_VER_ID			0x11
#define GET_RBT_VER_ID(x)	(((x)>>8)&0xff)
#define GET_RBT_VER_MAJOR(x)	(((x)>>4)&0xf)
#define GET_RBT_VER_MINOR(x)	((x)&0xf)
#define RBT_SYS_TEN			(1<<2)
#define RBT_SYS_IEN			(1<<1)
#define RBT_SYS_OEN			(1<<0)

#define PULSE_CH_NUM		8
#define RBT_CLK				(135000000/4)

#define PULSE_BUFFER_SIZE	4

#define CYCLE_INC(d)	(((d)+1)&(PULSE_BUFFER_SIZE-1))
#define IS_CYCLE_BUFFER_FULL(buffer)	(CYCLE_INC((buffer).head) == ((buffer).tail))
#define IS_CYCLE_BUFFER_EMPTY(buffer)	((buffer).head == (buffer).tail)

#define DEVICE_NAME		"rbt-fpga"

#ifndef IRQF_NO_SOFTIRQ_CALL
#define IRQF_NO_SOFTIRQ_CALL 0	//for non-RT kernel
#endif

#ifdef CONFIG_PREEMPT_RT_FULL
#include <linux/wait-simple.h>

#define wait_queue_head_t			struct swait_head
#undef init_waitqueue_head
#define init_waitqueue_head(x)		init_swait_head(x)
#undef wait_event_interruptible
#define wait_event_interruptible(wq, condition) 	swait_event_interruptible(wq, condition)
#undef wake_up_interruptible
#define wake_up_interruptible(x)	swait_wake_interruptible(x)
#endif

typedef struct fpga_pulse{
	uint16_t	count[PULSE_CH_NUM];
	uint16_t	period[PULSE_CH_NUM];
	uint16_t	prdd[PULSE_CH_NUM];
	uint16_t	dir;
}fpga_pulse_t;

typedef struct fpga_encoder{
	uint16_t	low16;
	uint16_t	high16;
	uint16_t	z_low16;
	uint16_t	z_high16;
}fpga_encoder_t;

struct rbt_info {
	uint16_t __iomem *iobase;
	unsigned long iosize;
	raw_spinlock_t lock;
	fpga_pulse_t pulse[PULSE_BUFFER_SIZE];
	unsigned int frame_size;
	unsigned int prd_cnt;
	int pulse_running;
	unsigned int break_time;
	unsigned int max_break_time;
	wait_queue_head_t wq;
	int head;
	int tail;
	fpga_encoder_t encoder[PULSE_CH_NUM];

	unsigned int irq;

	unsigned int offset;
	unsigned int interrupt_lost;
	unsigned int pulse_queue_break;
	struct miscdevice io_miscdev;
	struct miscdevice axis_io_miscdev;
	struct miscdevice pulse_miscdev;
	struct miscdevice encoder_miscdev;
};

static struct rbt_info *rbt_info_p;

static inline void rbt_fpga_writew(struct rbt_info *info,
		uint16_t val, unsigned int off)
{
	__raw_writew(val, info->iobase + off);
}

static inline uint16_t rbt_fpga_readw(struct rbt_info *info,
		unsigned int off)
{
	return __raw_readw(info->iobase + off);
}

inline fpga_pulse_t* GetFreePulseBuffer(struct rbt_info *info)
{
	fpga_pulse_t* pdata;

	if(IS_CYCLE_BUFFER_FULL(*info)){
		return NULL;
	}

	pdata = &info->pulse[info->head];
	info->head = CYCLE_INC(info->head);

	return pdata;
}

inline fpga_pulse_t* GetPulseData(struct rbt_info *info)
{
	fpga_pulse_t* pdata;

	if(IS_CYCLE_BUFFER_EMPTY(*info)){
		return NULL;
	}

	pdata = &info->pulse[info->tail];
	info->tail = CYCLE_INC(info->tail);

	return pdata;
}

/*
 * /sys/devices/platform/rbt_fpga.N
 *   /freq          read-write pwm output frequency (0 = disable output)
 *   /pulse	   write pulse, 16bit * channel_number
 */
static ssize_t rbt_fpga_get_freq(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);
	unsigned long tprd = rbt_fpga_readw(info, RBT_TPRD_OFFSET);
	unsigned long pprd = rbt_fpga_readw(info, RBT_PPRD_OFFSET);

	return sprintf(buf, "%ld\n", RBT_CLK/(pprd+1)/(tprd+1));
}

static int rbt_fpga_set_freq_reg(struct rbt_info *info, unsigned long freq)
{
	uint16_t tprd, pprd=135, rbtsys;

	tprd = (RBT_CLK/pprd/freq) - 1;

	if (tprd > 0xffff)
		tprd = 0xffff;
	if (tprd < 1)
		tprd = 1;

	info->prd_cnt = (tprd+1)*pprd;

	rbtsys = rbt_fpga_readw(info, RBT_SYS_OFFSET);
	rbtsys &= ~(RBT_SYS_TEN|RBT_SYS_IEN);
	rbt_fpga_writew(info, rbtsys, RBT_SYS_OFFSET);
	rbt_fpga_writew(info, pprd-1, RBT_PPRD_OFFSET);
	rbt_fpga_writew(info, tprd, RBT_TPRD_OFFSET);
	rbtsys |= RBT_SYS_TEN|RBT_SYS_IEN;
	rbt_fpga_writew(info, rbtsys, RBT_SYS_OFFSET);

	return 0;
}

static ssize_t rbt_fpga_set_freq(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	unsigned long freq;
	int err;

	err = strict_strtol(buf, 10, &freq);
	if (err)
		return -EINVAL;

	if (freq > (RBT_CLK/2))
		return -EINVAL;

	rbt_fpga_set_freq_reg(info, freq);

	return count;
}

static inline void rbt_fpga_push_pulse(struct rbt_info *info, 
	fpga_pulse_t *pulse, int32_t *data)
{
	int i;
	uint16_t dir=0;
	int32_t d;
	uint32_t t;
	for(i=0;i<info->frame_size;i++){
		d = data[i];
		if(d<0){
			d = -d;
			dir |= (1<<i);
		}
		pulse->count[i] = d;
		if(d!=0){
			pulse->period[i] = info->prd_cnt/d;
			t = (((uint32_t)info->prd_cnt)<<15)/d - (((uint32_t)pulse->period[i])<<15);
			if(t>=32768)
				t = 32767;
			pulse->prdd[i] = t;
		}
	}
	pulse->dir = dir<<8;
}

static ssize_t rbt_fpga_get_address(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "0x%x\n", info->offset);
}

static ssize_t rbt_fpga_set_address(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	unsigned long offset;
	int err;

	err = strict_strtol(buf, 0, &offset);
	if (err)
		return -EINVAL;

	if (offset > (PAGE_SIZE/2))
		return -EINVAL;

	info->offset = offset;

	return count;
}

static ssize_t rbt_fpga_get_data(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "0x%x:0x%x\n", info->offset, rbt_fpga_readw(info, info->offset));
}

static ssize_t rbt_fpga_set_data(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	unsigned long val;
	int err;

	err = strict_strtol(buf, 0, &val);
	if (err)
		return -EINVAL;

	rbt_fpga_writew(info, val, info->offset);

	return count;
}

static ssize_t rbt_fpga_regdump(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	unsigned long i, n=0;
	for(i=0;i<info->iosize/2;i++){
		if((i&0x7)==0)
			n += sprintf(buf+n, "0x%04lx: ", i);
		n += sprintf(buf+n, "0x%04x", rbt_fpga_readw(info, i));
		if((i&0x7)==7)
			n += sprintf(buf+n, "\n");
		else
			n += sprintf(buf+n, ",");
	}

	return n;
}

static ssize_t rbt_fpga_errordump(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "interrupt lost: %d\npulse queue break: %d\nmax break tick: %d\n", 
		info->interrupt_lost, info->pulse_queue_break, info->max_break_time);
}

static const char *rbt_fpga_mode_str[]={"yaskawa", "wr-rs232", "wr-rs485", "em-rs485"};
static ssize_t rbt_fpga_get_uartmode(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);
	uint32_t mode = rbt_fpga_readw(info, RBT_UMUX_OFFSET)&0xf;
	int i,n=0;

	if(mode >= ARRAY_SIZE(rbt_fpga_mode_str))
		n += sprintf(buf+n, "uart mode error %d\n", mode);

	for(i=0;i<ARRAY_SIZE(rbt_fpga_mode_str);i++){
		n += sprintf(buf+n, "%c%s\n", mode==i?'*':' ', rbt_fpga_mode_str[i]);
	}
	return n;
}

static ssize_t rbt_fpga_set_uartmode(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);
	uint16_t umux = rbt_fpga_readw(info, RBT_UMUX_OFFSET)&(~0xf);

	int i;
	for(i=0;i<ARRAY_SIZE(rbt_fpga_mode_str);i++){
		if(strncmp(rbt_fpga_mode_str[i], buf, strlen(rbt_fpga_mode_str[i]))==0){
			umux |= i;
			rbt_fpga_writew(info, umux, RBT_UMUX_OFFSET);
			return count;
		}
	}

	return -EINVAL;
}

static ssize_t rbt_fpga_get_uartchannel(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);
	int n = (rbt_fpga_readw(info, RBT_UMUX_OFFSET)>>4)&0xf;

	return sprintf(buf, "%d\n", n);
}

static ssize_t rbt_fpga_set_uartchannel(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);
	unsigned long val;
	int err;

	err = strict_strtol(buf, 0, &val);
	if (err)
		return -EINVAL;

	val = (rbt_fpga_readw(info, RBT_UMUX_OFFSET)&(~0xf0))|((val&0xf)<<4);
	rbt_fpga_writew(info, val, RBT_UMUX_OFFSET);

	return count;
}

static DEVICE_ATTR(freq, S_IWUSR | S_IRUGO,rbt_fpga_get_freq, rbt_fpga_set_freq);
static DEVICE_ATTR(address, S_IWUSR | S_IRUGO, rbt_fpga_get_address, rbt_fpga_set_address);
static DEVICE_ATTR(data, S_IWUSR | S_IRUGO, rbt_fpga_get_data, rbt_fpga_set_data);
static DEVICE_ATTR(regdump, S_IWUSR | S_IRUGO, rbt_fpga_regdump, NULL);
static DEVICE_ATTR(error, S_IWUSR | S_IRUGO, rbt_fpga_errordump, NULL);
static DEVICE_ATTR(uartmode, S_IWUSR | S_IRUGO,rbt_fpga_get_uartmode, rbt_fpga_set_uartmode);
static DEVICE_ATTR(uartchannel, S_IWUSR | S_IRUGO,rbt_fpga_get_uartchannel, rbt_fpga_set_uartchannel);

static struct attribute *rbt_fpga_attrs[] = {
	&dev_attr_freq.attr,
	&dev_attr_address.attr,
	&dev_attr_data.attr,
	&dev_attr_regdump.attr,
	&dev_attr_error.attr,
	&dev_attr_uartmode.attr,
	&dev_attr_uartchannel.attr,
	NULL
};

static const struct attribute_group rbt_fpga_sysfs_files = {
	.attrs	= rbt_fpga_attrs,
};

static void rbt_fpga_sync_encoder(struct rbt_info *info)
{
	//must in spin lock
	static unsigned int index=0;
	uint16_t e, diff, last=info->encoder[index].low16;

	e = rbt_fpga_readw(info, RBT_CnDAT_OFFSET(index));
	diff = e-last;
	if(diff<32768 && e<last){
		info->encoder[index].high16++;
	}
	else if(diff>=32768 && e>last){
		info->encoder[index].high16--;
	}

	index++;
	if(index>=PULSE_CH_NUM)
		index=0;
}

static irqreturn_t rbt_fpga_irq_handler(int irq, struct rbt_info *info)
{
	unsigned long flags;
	uint16_t rbtsys;
	fpga_pulse_t *pulse;

	raw_spin_lock_irqsave(&info->lock,flags);
	pulse = GetPulseData(info);

	if(info->frame_size>=PULSE_CH_NUM)
		printk("frame size %d\n", info->frame_size);

#if 1
	if(pulse){
		//write pulse into FPGA
		int i;
		for(i=0;i<info->frame_size;i++){
			if(pulse->count[i]){
				rbt_fpga_writew(info, pulse->prdd[i]-1, RBT_PnPRDD_OFFSET(i));
				rbt_fpga_writew(info, pulse->count[i]-1, RBT_PnCNT_OFFSET(i));
				rbt_fpga_writew(info, pulse->period[i]-1, RBT_PnPRD_OFFSET(i));
			}
		}
		rbt_fpga_writew(info, pulse->dir, RBT_PDDAT_OFFSET);
		wake_up_interruptible(&info->wq);
		if(info->break_time){
			printk("pulse queue %d break %d tick\n", ++info->pulse_queue_break, info->break_time);
			info->break_time = 0;
		}
	}
	else if(info->pulse_running){
		info->break_time++;
		if(info->break_time > info->max_break_time)
			info->max_break_time = info->break_time;
	}
#else
	//write pulse into FPGA
	rbt_fpga_writew(info, 20-1, RBT_PnCNT_OFFSET(3));
	rbt_fpga_writew(info, info->prd_cnt/20, RBT_PnPRD_OFFSET(3));

	rbt_fpga_writew(info, 0, RBT_PDDAT_OFFSET);
	wake_up_interruptible(&info->wq);
#endif
	rbt_fpga_sync_encoder(info);

	raw_spin_unlock_irqrestore(&info->lock,flags);
	
	rbt_fpga_writew(info, 0x1, RBT_INT_OFFSET);
	rbtsys = rbt_fpga_readw(info, RBT_SYS_OFFSET);
	if(rbtsys&(1<<3)){
		if(info->interrupt_lost<100 || (info->interrupt_lost%100)==0)
			printk("interrput lost %d\n", info->interrupt_lost);
		info->interrupt_lost++;
		rbtsys &=~(1<<3);
		rbt_fpga_writew(info, rbtsys, RBT_SYS_OFFSET);
	}
	
	return IRQ_HANDLED;
}

static ssize_t rbt_fpga_pulse_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;
	fpga_pulse_t *pulse;
	int ret;
	unsigned long flags;
	char pulse_data[PULSE_CH_NUM*sizeof(int32_t)];

	if(count>sizeof(pulse_data)){
		printk("%s: frame size can't big than %d error\n", 
			__FUNCTION__, sizeof(pulse_data));
		return -EINVAL;
	}

	copy_from_user(pulse_data, buf, count);

	if(count==1 && pulse_data[0]==0){	//pulse stop
		info->pulse_running=0;
		return count;
	}

	ret = wait_event_interruptible(info->wq, !IS_CYCLE_BUFFER_FULL(*info));
	if(ret<0)
		return ret;

	raw_spin_lock_irqsave(&info->lock,flags);

	pulse = GetFreePulseBuffer(info);
	if(pulse==NULL){
		raw_spin_unlock_irqrestore(&info->lock,flags);
		printk("wait out but buffer full\n");
		return count;
	}

	if(info->frame_size==0){
		info->frame_size = count/sizeof(int32_t);
		if(info->frame_size>PULSE_CH_NUM){
			raw_spin_unlock_irqrestore(&info->lock,flags);
			return -EINVAL;
		}
			
	}
	else if(info->frame_size != count/sizeof(int32_t)){
		raw_spin_unlock_irqrestore(&info->lock,flags);
		printk("%s: frame size error\n", __FUNCTION__);
		return -EINVAL;
	}
	info->pulse_running=1;

	rbt_fpga_push_pulse(info, pulse, (int32_t*)pulse_data);
	raw_spin_unlock_irqrestore(&info->lock,flags);
	
	return count;
}

static const struct file_operations pulse_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= noop_llseek,
	.write		= rbt_fpga_pulse_write,
};

static int __init rbt_fpga_init_pulse(struct rbt_info *info)
{
	int ret;

	if(request_irq(info->irq, (irq_handler_t)rbt_fpga_irq_handler, 
		IRQF_TRIGGER_LOW|IRQF_NO_THREAD|IRQF_DISABLED|IRQF_NOBALANCING|IRQF_NO_SOFTIRQ_CALL, DEVICE_NAME, info)<0){
		printk("RBT FPGA request irq %d failed!\n", info->irq);
		return -ENXIO;
	}

	rbt_fpga_set_freq_reg(info, 1000);

	/* Setup the miscdevice */
	info->pulse_miscdev.minor = MISC_DYNAMIC_MINOR;
	info->pulse_miscdev.name = "pulse";
	info->pulse_miscdev.fops = &pulse_fops;

	ret = misc_register(&info->pulse_miscdev);
	if(ret<0){
		printk("Failed to register fpga io device\n");
		free_irq(info->irq, info);
		return ret;
	}

	//write 0x5555 for QEI mode
	rbt_fpga_writew(info, 0x5555, RBT_CMODE_OFFSET);
	return 0;
}

#define IO_NUM_16BYTE	3	//16
#define FPGA_COMMON_IO_OFF	13

static ssize_t rbt_fpga_io_read(struct file *file, 
	char __user *buf, size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;/*container_of(file->private_data,
					     struct rbt_info, io_miscdev);*/

	int i;
	uint16_t tbuf[IO_NUM_16BYTE];

	if(count!=IO_NUM_16BYTE*2)
		return -EINVAL;

//	memcpy_fromio(tmp, info->base+RBT_INPUT_OFFSET+5, count);
	for(i=0;i<IO_NUM_16BYTE;i++)
		tbuf[i] = rbt_fpga_readw(info, RBT_INPUT_OFFSET+FPGA_COMMON_IO_OFF+i);
	copy_to_user(buf, tbuf, count);

	return count;
}

static ssize_t rbt_fpga_io_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	/*
	 * The miscdevice layer puts our struct miscdevice into the
	 * filp->private_data field. We use this to find our private
	 * data and then overwrite it with our own private structure.
	 */
	struct rbt_info *info = rbt_info_p;/*container_of(file->private_data,
					     struct rbt_info, io_miscdev);*/
	int i;
	uint16_t tbuf[IO_NUM_16BYTE];

	if(count!=IO_NUM_16BYTE*2)
		return -EINVAL;

	copy_from_user(tbuf, buf, count);
	for(i=0;i<IO_NUM_16BYTE;i++)
		rbt_fpga_writew(info, tbuf[i], RBT_OUTPUT_OFFSET+FPGA_COMMON_IO_OFF+i);

	return count;
}

static const struct file_operations io_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= noop_llseek,
	.read		= rbt_fpga_io_read,
	.write		= rbt_fpga_io_write,
};

typedef struct{
	unsigned int word_offset;
	unsigned int bit_offset;
}offset_table_t;

static const offset_table_t offset_table[]={
	{// 0
		.word_offset=12,
		.bit_offset=12,
	},
	{// 1
		.word_offset=12,
		.bit_offset=8,
	},
	{// 2
		.word_offset=12,
		.bit_offset=4,
	},
	{// 3
		.word_offset=12,
		.bit_offset=0,
	},
	{// 4
		.word_offset=11,
		.bit_offset=12,
	},
	{// 5
		.word_offset=11,
		.bit_offset=8,
	},
	{// 6
		.word_offset=11,
		.bit_offset=4,
	},
	{// 7
		.word_offset=11,
		.bit_offset=0,
	},
};

static ssize_t rbt_axis_io_read(struct file *file, 
	char __user *buf, size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;/*container_of(file->private_data,
					     struct rbt_info, io_miscdev);*/
	uint16_t v;
	unsigned int wordoff, bitoff;

	if(count!=1 || *ppos >= ARRAY_SIZE(offset_table))
		return -EINVAL;

	wordoff=offset_table[*ppos].word_offset+RBT_INPUT_OFFSET;
	bitoff=offset_table[*ppos].bit_offset;
	
	v = ~rbt_fpga_readw(info, wordoff)>>bitoff;
	v &= 0xf;

	put_user(v, buf);
	return count;
}

static ssize_t rbt_axis_io_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;/*container_of(file->private_data,
					     struct rbt_info, io_miscdev);*/
	uint16_t v, t;
	unsigned int wordoff, bitoff;

	if(count!=1 || *ppos >= ARRAY_SIZE(offset_table))
		return -EINVAL;

	wordoff=offset_table[*ppos].word_offset+RBT_OUTPUT_OFFSET;
	bitoff=offset_table[*ppos].bit_offset;

	get_user(v, buf);
	v = ~v;
	v &= 0xf;
	
	t = rbt_fpga_readw(info, wordoff);
	t &= ~(0xf<<bitoff);
	t |= (v<<bitoff);
	rbt_fpga_writew(info, t, wordoff);

	return count;
}

static const struct file_operations axis_io_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= default_llseek,
	.read		= rbt_axis_io_read,
	.write		= rbt_axis_io_write,
};

#if 0
#include <linux/random.h>

#define FPGA_OUTPUT_IO_SIZE	16
static void rbt_fpga_test_io(struct rbt_info *info)
{
	uint16_t wbuf[FPGA_OUTPUT_IO_SIZE], rbuf[FPGA_OUTPUT_IO_SIZE];
	int i=0,n=0, err=0;

	for(;;n++){
		for(i=0;i<FPGA_OUTPUT_IO_SIZE;i++){
			wbuf[i] = random32();
		}
		memcpy(info->iobase+RBT_OUTPUT_OFFSET, wbuf, sizeof(wbuf));

		p=wbuf;
		for(i=0;i<FPGA_OUTPUT_IO_SIZE;i++,p++){
			v = rbt_fpga_readw(info, RBT_OUTPUT_OFFSET+i);
			if(*p != v){
				printk("#######0x%x -> 0x%x@%d\n", *p, v, i);
				err++;
			}
		}
		if((n%10000)==0)
			printk("test %d err=%d\n", n, err);
	}
}
#endif

static int __init rbt_fpga_init_io(struct rbt_info *info)
{
	uint16_t val = rbt_fpga_readw(info, RBT_SYS_OFFSET);
	int ret;
	
	memset_io(info->iobase+RBT_OUTPUT_OFFSET, 0xff, 32);
	msleep(10);
	printk("RBT FPGA enable IO\n");
	rbt_fpga_writew(info, val|RBT_SYS_OEN, RBT_SYS_OFFSET);

	/* Setup the miscdevice */
	info->io_miscdev.minor = MISC_DYNAMIC_MINOR;
	info->io_miscdev.name = "rbtio";
	info->io_miscdev.fops = &io_fops;

	info->axis_io_miscdev.minor = MISC_DYNAMIC_MINOR;
	info->axis_io_miscdev.name = "axisio";
	info->axis_io_miscdev.fops = &axis_io_fops;
	
	ret = misc_register(&info->io_miscdev);
	if(ret<0){
		printk("Failed to register fpga io device\n");
		return ret;
	}

	ret = misc_register(&info->axis_io_miscdev);
	if(ret<0){
		printk("Failed to register fpga axis io device\n");
		return ret;
	}

	//rbt_fpga_test_io(info);
	
	return 0;
}

static ssize_t rbt_fpga_encoder_read(struct file *file, 
	char __user *buf, size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;
	unsigned long flags;
	fpga_encoder_t v;
	unsigned int i, end;
	uint16_t diff;

	end = (*ppos+count)/sizeof(fpga_encoder_t);
	if((count%sizeof(fpga_encoder_t))!=0 || 
		(*ppos%sizeof(fpga_encoder_t))!=0 || end > PULSE_CH_NUM)
		return -EINVAL;

	raw_spin_lock_irqsave(&info->lock,flags);

	for(i = *ppos/sizeof(fpga_encoder_t);i<end;i++){
		v.low16=rbt_fpga_readw(info, RBT_CnDAT_OFFSET(i));
		v.z_low16=rbt_fpga_readw(info, RBT_CnZDL_OFFSET(i));
		v.high16=info->encoder[i].high16;
		diff = v.low16 - v.z_low16;
		if(diff<32768 && v.low16<v.z_low16)
			v.z_high16=v.high16-1;
		else if(diff>=32768 && v.low16>v.z_low16)
			v.z_high16=v.high16+1;
		else
			v.z_high16=v.high16;

		copy_to_user(buf, &v, sizeof(v));
		buf+=sizeof(fpga_encoder_t);
	}

	raw_spin_unlock_irqrestore(&info->lock,flags);
	*ppos+=count;

	return count;
}

/*
static ssize_t rbt_fpga_encoder_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;
	fpga_encoder_t v;
	unsigned long flags;
	unsigned int i, end;

	end = (*ppos+count)/sizeof(fpga_encoder_t);
	if((count%sizeof(fpga_encoder_t))!=0 || 
		(*ppos%sizeof(fpga_encoder_t))!=0 || end >= PULSE_CH_NUM)
		return -EINVAL;

	raw_spin_lock_irqsave(&info->lock,flags);

	for(i = *ppos/sizeof(fpga_encoder_t);i<end;i++){
		copy_from_user(&v, buf, sizeof(v));
		buf+=sizeof(fpga_encoder_t);

		info->encoder[i].high16 = v.high16;
		info->encoder[i].z_high16 = v.z_high16;
		rbt_fpga_writew(info, v.low16, RBT_CnDAT_OFFSET(i));
	}
	raw_spin_unlock_irqrestore(&info->lock,flags);

	return count;
}*/

static const struct file_operations encoder_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= default_llseek,
	.read		= rbt_fpga_encoder_read,
//	.write		= rbt_fpga_encoder_write,
};
static int __init rbt_fpga_init_encoder(struct rbt_info *info)
{
	int ret;

	/* Setup the miscdevice */
	info->encoder_miscdev.minor = MISC_DYNAMIC_MINOR;
	info->encoder_miscdev.name = "encoder";
	info->encoder_miscdev.fops = &encoder_fops;

	ret = misc_register(&info->encoder_miscdev);
	if(ret<0){
		printk("Failed to register fpga encoder device\n");
		return ret;
	}
	
	return 0;
}

static int __init rbt_fpga_probe(struct platform_device *pdev)
{
	struct rbt_info *info;
	struct resource *res;
	uint16_t v;
	int err;

	info = kzalloc(sizeof(struct rbt_info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	raw_spin_lock_init(&info->lock);
	init_waitqueue_head(&info->wq);
	info->frame_size=0;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (res == NULL) {
		err = -ENXIO;
		goto fail_no_mem_resource;
	}

	res = request_mem_region(res->start, resource_size(res), pdev->name);
	if (res == NULL) {
		err = -EBUSY;
		goto fail_no_mem_resource;
	}

	info->iobase = ioremap(res->start, resource_size(res));
	if (info->iobase == NULL) {
		err = -ENXIO;
		goto fail_no_ioremap;
	}
	info->iosize=256;//resource_size(res);

	err = platform_get_irq(pdev, 0);
	if(err<0)
		goto fail_no_rbt_fpga;
	info->irq = err;
	
	v = rbt_fpga_readw(info, RBT_VER_OFFSET);
	if(GET_RBT_VER_ID(v)!=RBT_VER_ID){
		err = -ENXIO;
		printk("Can't find RBT FPGA Chip ret=0x%x!\n", v);
		goto fail_no_rbt_fpga;
	}

	err = rbt_fpga_init_pulse(info);
	if(err<0)
		goto fail_no_rbt_fpga;

	err = rbt_fpga_init_io(info);
	if(err<0)
		goto fail_no_rbt_fpga;

	err = rbt_fpga_init_encoder(info);
	if(err<0)
		goto fail_no_rbt_fpga;

	rbt_info_p = info;

	err = sysfs_create_group(&pdev->dev.kobj, &rbt_fpga_sysfs_files);
	if (err)
		goto fail_no_sysfs;

	platform_set_drvdata(pdev, info);

	dev_info(&pdev->dev, "RBT FPGA@0x%x irq(%d), firmware version %d.%d\n",
		res->start, info->irq, GET_RBT_VER_MAJOR(v), GET_RBT_VER_MINOR(v));

	return 0;

	sysfs_remove_group(&pdev->dev.kobj, &rbt_fpga_sysfs_files);
fail_no_sysfs:
	free_irq(info->irq, info);
fail_no_rbt_fpga:
	iounmap(info->iobase);
fail_no_ioremap:
	release_mem_region(res->start, resource_size(res));
fail_no_mem_resource:
	kfree(info);
	return err;
}

static int __exit rbt_fpga_remove(struct platform_device *pdev)
{
	struct rbt_info *info = platform_get_drvdata(pdev);
	struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	free_irq(info->irq, info);
	platform_set_drvdata(pdev, NULL);
	sysfs_remove_group(&pdev->dev.kobj, &rbt_fpga_sysfs_files);
	iounmap(info->iobase);
	release_mem_region(res->start, resource_size(res));
	kfree(info);

	return 0;
}

static struct of_device_id of_rbt_fpga_match[] = {
	{
		.compatible	= "rbctrl-fpga",
	},
	{ },
};
MODULE_DEVICE_TABLE(of, of_rbt_fpga_match);

static struct platform_driver rbt_fpga_driver = {
	.driver		= {
		.name	= DEVICE_NAME,
		.owner	= THIS_MODULE,
		.of_match_table = of_rbt_fpga_match,
	},
	.probe		= rbt_fpga_probe,
	.remove		= __exit_p(rbt_fpga_remove),
};

static int __init rbt_fpga_init(void)
{
	return platform_driver_register(&rbt_fpga_driver);
}

static void __exit rbt_fpga_exit(void)
{
	platform_driver_unregister(&rbt_fpga_driver);
}

late_initcall(rbt_fpga_init);
module_exit(rbt_fpga_exit);

MODULE_DESCRIPTION("RBT FPGA driver");
MODULE_LICENSE("GPL");
