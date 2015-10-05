/****************************************************************************/
/*                                                                          */
/*        LITTLE_JL100_DEF.H : Common header of JL-100 access driver        */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*       Defines:                                                           */
/*          Definetion of Host Interface registers                          */
/*                                                                          */
/******** Copyright(C) 2007 Yaskawa Electric Corporation ********************/
/*                                                                          */
/*       Ver 1.00  :  2007.12.20  Initial coding  T.soeda                   */
/*                                                                          */
/****************************************************************************/
#ifndef		JL100_DEF_H_
#define		JL100_DEF_H_



/***********************************************************************/
/*   Type definition                                                   */
/***********************************************************************/
#ifndef		SHORT
typedef		short          SHORT;
#endif		/* SHORT */
#ifndef		USHORT
typedef		unsigned short USHORT;
#endif		/* USHORT */
#ifndef		LONG
typedef		long           LONG;
#endif		/* LONG */
#ifndef		ULONG
typedef		unsigned long  ULONG;
#endif		/* ULONG */
#ifndef		VULONG
typedef		volatile unsigned long	VULONG;
#endif		/* VULONG */
#ifndef		VOID
typedef		void           VOID;
#endif		/* VOID */
#ifndef		INT
typedef		int            INT;
#endif		/* int */
#ifndef		UINT
typedef		unsigned int   UINT;
#endif		/* UINT */
#ifndef		UCHAR
typedef		unsigned char   UCHAR;
#endif		/* UCHAR */



/***********************************************************************/
/*      HOST I/F register bit pattern definition                       */
/***********************************************************************/

/* CMD register */
#define JL100_CMD_GTX_R			0x00000001
#define JL100_CMD_RBX_R			0x00000002
#define JL100_CMD_CBX_R			0x00000004
#define JL100_CMD_TX_R			0x00000008		/* for only async mode CMD regs */
#define JL100_CMD_C1MTX_R		0x00000010
#define JL100_CMD_C1MRX_R		0x00000020
#define JL100_CMD_C1ABT_R		0x00000040
#define JL100_CMD_RX_R			0x00000080		/* for only async mode CMD regs */
#define JL100_CMD_C2MTX_R		0x00000100
#define JL100_CMD_C2MRX_R		0x00000200
#define JL100_CMD_C2ABT_R		0x00000400
#define JL100_CMD_WD_R			0x00001000
#define JL100_CMD_GTIM_RST		0x00004000
#define JL100_CMD_RST_ASC		0x00008000
#define JL100_CMD_P_MOD_R		0x00010000
#define JL100_CMD_DTCT_R		0x00020000
#define JL100_CMD_PAR_R			0x00040000
#define JL100_CMD_DLY_R			0x00080000
#define JL100_CMD_SCNF_R		0x00100000
#define JL100_CMD_C_START_R		0x00200000
#define JL100_CMD_A_START_R		0x00400000

/* STS register */
#define JL100_STS_COM_ENA		0x00000001
#define JL100_STS_M3_MOD		0x00000002
#define JL100_STS_FM_MOD		0x00000004
#define JL100_STS_PRGSEL		0x00000008
#define JL100_STS_TEST0			0x00000010
#define JL100_STS_RDY			0x00002000
#define JL100_STS_ERRL			0x00004000
#define JL100_STS_ERR			0x00008000

/* INTS register & IMK register */
#define JL100_INTS_GTX_I		0x00000001
#define JL100_INTS_TX_I			0x00000008		/* for only async mode INTS regs */
#define JL100_INTS_C1MTX_I		0x00000010
#define JL100_INTS_C1MRX_I		0x00000020
#define JL100_INTS_C1ABT_I		0x00000040
#define JL100_INTS_RX_I			0x00000080		/* for only async mode INTS regs */
#define JL100_INTS_C2MTX_I		0x00000100
#define JL100_INTS_C2MRX_I		0x00000200
#define JL100_INTS_C2ABT_I		0x00000400
#define JL100_INTS_TIM1			0x00000800
#define JL100_INTS_TXEN_I		0x00002000
#define JL100_INTS_TXST_I		0x00004000
#define JL100_INTS_SFR			0x00008000
#define JL100_INTS_P_MOD_I		0x00010000
#define JL100_INTS_DTCT_I		0x00020000
#define JL100_INTS_PAR_I		0x00040000
#define JL100_INTS_DLY_I		0x00080000
#define JL100_INTS_SCNF_I		0x00100000
#define JL100_INTS_C_START_I	0x00200000
#define JL100_INTS_A_START_I	0x00400000
#define JL100_INTS_RX_TMC		0x01000000

/* ESTS register */
#define JL100_ESTS_FCS_ERR		0x00000001
#define JL100_ESTS_SCNF_ERR		0x00000002
#define JL100_ESTS_PAR_ERR		0x00000004
#define JL100_ESTS_TMCYCOVR		0x00000008
#define JL100_ESTS_AXIS_NO_ERR	0x00000010
#define JL100_ESTS_ADDSTN_ERR	0x00000020
#define JL100_ESTS_RXLEN_ERR	0x00000100
#define JL100_ESTS_RFO_ERR		0x00000200
#define JL100_ESTS_RUR_ERR		0x00000400
#define JL100_ESTS_RXSM_ERR		0x00000800
#define JL100_ESTS_WDTOVR		0x00008000
#define JL100_ESTS_TXTIM_OVR	0x00010000
#define JL100_ESTS_RXTX_ERR		0x00020000
#define JL100_ESTS_TXRX_ERR		0x00040000
#define JL100_ESTS_RXRX_ERR		0x00080000
#define JL100_ESTS_TXSM_UNDER	0x00100000
#define JL100_ESTS_TXSM_OVER	0x00200000
#define JL100_ESTS_TFO_ERR		0x02000000
#define JL100_ESTS_TUR_ERR		0x04000000
#define JL100_ESTS_TXSM_ERR		0x08000000
#define JL100_ESTS_TX_ERROR		0x0E3F0000
#define JL100_ESTS_RX_ERROR		0x00000F01

/* MOD register */
#define JL100_MOD_TYPE_SLV		0x00000000
#define JL100_MOD_TYPE_MONSLV	0x00000001
#define JL100_MOD_TYPE_MULTISLV	0x00000001
#define JL100_MOD_TYPE_C1MST	0x00000002
#define JL100_MOD_TYPE_C2MST	0x00000003
#define JL100_MOD_INTLV_LVL		0x00000000
#define JL100_MOD_INTLV_PLS		0x00000800
#define JL100_MOD_ESYNC			0x00001000
#define JL100_MOD_MDIO_EN		0x00004000
#define JL100_MOD_INT_FR		0x00008000

/* CID register */
#define JL100_CID				0x0000100A
#define JL100_CID_LO_ADR		0x100A
#define JL100_CID_HI_ADR		0x0000

/* CRCV1 register */
#define JL100_CRCV1_00			0x00000001

#define DEF_C1_MST				0
#define DEF_C2_MST				1

#define C1MST_ADR				0x0001
#define C2MST_ADR				0x0002

#define COM_MODE_SYNC			0				/* Communication mode : SYNC */
#define COM_MODE_ASYNC			1				/* Communication mode : ASYNC */

#define WORD_SIZE				2
#define DWORD_SIZE				4

#define SYNC_FRAME_SIZE			32
#define HEADER_SIZE				8
#define ASYNC_HEADER_SIZE		12
#define FCS_SIZE				4

#define IOMAP_SIZE				16
#define USER_IOMAP_SIZE			8



/***********************************************************************/
/*      Default parameter definition                                   */
/***********************************************************************/
/* RAM top address definition */
#define DEF_DOWNLOAD_SRAM_TOP_ADR	0x4000	/* Download SRAM top address */
#define DEF_DOWNLOAD_SRAM_SIZE		0x4000	/* Download SRAM size */
#define DEF_SRAM_TOP_ADR		0x8000		/* SRAM top address */
#define DEF_SRAM_SIZE			0x8000		/* SRAM SIZE : 32Kbyte */

/* Register parameter */
#define DEF_IMK_REG				0
#define DEF_PARS_ADR			0x7b00		/* Communication parameter area top address */

/* Communication parameter */
#define DEF_MA_MSK0				0xFFFF
#define DEF_MA_MSK1				DEF_MA_MSK0	/* default : not use multicast address */
#define DEF_SRCH_TIME			0xFFFF
#define DEF_MSG_PTR				0x5000
#define DEF_C1MSG_SZ			1536
#define DEF_C2MSG_SZ			1536
#define DEF_IFGSET				0
#define DEF_MAX_FRM				2
#define DEF_IOMAP_PTR			0x7c00

/* C1 */
#define DEF_C1_MA0				0x0001
#define DEF_C1_MA1				DEF_C1_MA0	/* default : not use multicast address */
#define DEF_C1_MA_MAX			62
#define DEF_C1_MAX_RTRY			1
#define DEF_C1_DLY_CNT			1			/* default : min */
#define DEF_TRSP_BASE_TIME		1500
#define DEF_COMPAR_RESERVE2_10NS	222
#define DEF_COMPAR_RESERVE2_100NS	20
#define DEF_COMPAR_RESERVE2_1US		0

/* C2 */
#define DEF_C2_MA0				0x0002
#define DEF_C2_MA1				DEF_C2_MA0	/* default : not use multicast address */
#define DEF_C2_MA_MAX			62
#define DEF_C2_MAX_RTRY			0
#define DEF_C2_DLY_CNT			0

/* Common */
#define DEF_PROTSEL_SYNC		0
#define DEF_PROTSEL_ASYNC		1
#define DEF_DLYFRM_WAIT_CNT		0x0023
#define DEF_DLYAPP_WAIT_CNT		0x056D

#define COM_START_TOUT			3000000		/* Async com. start reqest timeout(time unit:usec) */
#define ASYNC_REQ_POLL_TIME		500			/* Async com. start reqest Pollin time(time unit:usec) */



/***********************************************************************/
/*      Error Code definition                                          */
/***********************************************************************/
#ifndef LIB_OK
#define	LIB_OK				0
#endif
#ifndef LIB_NG
#define LIB_NG				-1
#endif

#define RCVING_MSG			0x0001
#define SNDING_MSG			0x0002
#define RCVING_FRAME		0x0001
#define SNDING_FRAME		0x0002
#define RECEIVED_FRAME		0x0003
#define ASYNC_RCV_OK		0x0001
#define RCVED_TMC_FRAME		0x0001
#define NOT_RCV_TMC_FRAME	0x0000

/* Error type definition */
#define ERROR_TYPE_USER		0x1000		/* user setting error */
#define ERROR_TYPE_COM		0x2000		/* communication error */
#define ERROR_TYPE_SYS		0x3000		/* system error */

/* Error code of initial function */
#define ERROR_INVALID_USRPAR		(ERROR_TYPE_USER | 0x00)
#define ERROR_TOUT_MODE_SET			(ERROR_TYPE_SYS  | 0x01)
#define ERROR_TOUT_USRPRM_SET		(ERROR_TYPE_SYS  | 0x02)
#define ERROR_REQ_SIZE_OVER			(ERROR_TYPE_USER | 0x04)
#define ERROR_INVALID_HIFPTR		(ERROR_TYPE_USER | 0x05)
#define ERROR_RAM_SIZE_OVER			(ERROR_TYPE_USER | 0x06)
#define ERROR_INVALID_TMCYC			(ERROR_TYPE_USER | 0x07)
#define ERROR_TOUT_CSTART			(ERROR_TYPE_SYS  | 0x08)
#define ERROR_TOUT_ASTART			(ERROR_TYPE_SYS  | 0x09)
#define ERROR_INFM_CMODE			(ERROR_TYPE_SYS  | 0x0A)
#define ERROR_WRONG_SEQ				(ERROR_TYPE_USER | 0x0B)
#define ERROR_SLV_AXIS_NO			(ERROR_TYPE_USER | 0x0C)
#define ERROR_IOMAP_SIZE			(ERROR_TYPE_USER | 0x0D)
#define ERROR_VERIFY_MICRO			(ERROR_TYPE_SYS  | 0x0E)
#define ERROR_PHY_RESET				(ERROR_TYPE_USER | 0x0F)
#define ERROR_RESET_ASIC			(ERROR_TYPE_COM  | 0x10)
#define ERROR_TX_FRM				(ERROR_TYPE_COM  | 0x11)

/* Error code of link communication function */
#define ERROR_TOUT_CHANG_RBUFF		(ERROR_TYPE_SYS  | 0x1a)
#define ERROR_TOUT_CHANG_CBUFF		(ERROR_TYPE_SYS  | 0x1c)
#define ERROR_INVALID_STNO			(ERROR_TYPE_USER | 0x1e)
#define ERROR_REQ_SIZE				(ERROR_TYPE_USER | 0x1f)
#define ERROR_INVALID_SIZE			(ERROR_TYPE_USER | 0x20)
#define ERROR_INVALID_FTYPE			(ERROR_TYPE_USER | 0x21)
#define ERROR_TOUT_RCV_FRAME		(ERROR_TYPE_SYS  | 0x22)
#define ERROR_TOUT_SEND_FRAME		(ERROR_TYPE_SYS  | 0x23)
#define ERROR_SEND_SYNCFRAM			(ERROR_TYPE_USER | 0x26)
#define ERROR_MDIO_BUSY				(ERROR_TYPE_SYS  | 0x27)
#define ERROR_NOT_SYNC				(ERROR_TYPE_SYS  | 0x28)
#define ERROR_GBL_NOT_RCV			(ERROR_TYPE_COM  | 0x29)
#define ERROR_TOUT_CMD_GTX			(ERROR_TYPE_SYS  | 0x2a)
#define ERROR_ASYNC_FTYPE			(ERROR_TYPE_COM  | 0x2b)

/* Error code of message communication function */
#define ERROR_MSG_ABORT				(ERROR_TYPE_USER | 0x30)
#define ERROR_MSG_OVERFLOW			(ERROR_TYPE_USER | 0x31)
#define ERROR_SNDING_MSG			(ERROR_TYPE_USER | 0x32)
#define ERROR_REQ_MSG_SIZE			(ERROR_TYPE_USER | 0x33)
#define ERROR_RCVING_MSG			(ERROR_TYPE_USER | 0x34)
#define ERROR_ABT_MSG				(ERROR_TYPE_SYS  | 0x35)
#define ERROR_BUSY_MSG				(ERROR_TYPE_SYS  | 0x36)
#define	ERROR_MSG_UNDERFLOW			(ERROR_TYPE_USER | 0x37)
#define ERROR_MSG_DIV_OVER			(ERROR_TYPE_USER | 0x38)



/***********************************************************************/
/*	Process code definition for processing sequence check              */
/***********************************************************************/
#define PROC_INITIAL				0x0001
#define PROC_REQ_DETECT_SLV			0x0002
#define PROC_CHK_DETECT_SLV_CMP		0x0004
#define PROC_REQ_MEASUR_TRANSDLY	0x0008
#define PROC_CHK_TRANSDLY_CMP		0x0010
#define PROC_INFM_CMODE				0x0020
#define PROC_INFM_CMODE_CMP			0x0040
#define PROC_GET_CMODE				0x0040
#define PROC_START_SYNC				0x0080



/***********************************************************************/
/*	Status number(IOMAP) definition(slave/C2master)                    */
/***********************************************************************/
#define STSNUM_PON					0x0000	/* Status number : power on */
#define STSNUM_WAIT_PARS_MOD		0x0001	/* Status number : waiting set PARS and MOD */
#define STSNUM_WAIT_PAR				0x0002	/* Status number : waiting set COM PARAM and IOMAP */
#define STSNUM_WAIT_DTCT			0x0021	/* Status number : waitnig request detect slave */
#define STSNUM_DETECTED				0x0022	/* Status number : detected slave */
#define STSNUM_AXISNUM_ERR			0x0023	/* Status number : some slave has same axis number  */
#define STSNUM_WAIT_MEASURE_DLY		0x0024	/* Status number : waiting request transdlay measure */
#define STSNUM_WAIT_DLY_APPFRM		0x0025	/* Status number : waiting measure dly appoint frame */
#define STSNUM_WAIT_DLY_MFRM		0x0026	/* Status number : waiting measure dly frame */
#define STSNUM_WAIT_TMCFRM			0x0027	/* Status number : waiting transmisson cycle frame */
#define STSNUM_WAIT_SYNC_START		0x0040	/* Status number : waiting sync start */
#define STSNUM_SYNC_COM				0x0050	/* Status number : in sync communication */
#define STSNUM_ASYNC_COM			0x0060	/* Status number : in async communication */



/***********************************************************************/
/*	Status definition				                                   */
/***********************************************************************/
#define WAIT_SETUP					1		/*  */
#define WAIT_ASIC_READY				1		/*  */
#define WAIT_CMP_DETECT				2		/*  */
#define MEASURING_TRANSDLY			3		/*  */
#define WAIT_TRANSCYC_FRM			4		/*  */
#define WAIT_SLV_RSP				5		/*  */



/***********************************************************************/
/*	Message communication status definition                            */
/***********************************************************************/
#define MSG_SND_ABORT		0x8001
#define MSG_UNDERFLOW		0x8003
#define MSG_SND_BUSY		0x8005
#define MSG_DIV_OVER		0x8007
#define MSG_ABORT			0x8002
#define MSG_OVERFLOW		0x8004
#define MSG_BUSY			0x8006



/***********************************************************************/
/*	Async. communication status definition                             */
/***********************************************************************/
#define ASYNC_RCV_CMP		0x0001
#define ASYNC_RCV_ERROR		0x0002
#define ASYNC_RCV_TIMOUT	0x0003
#define ASYNC_SND_CMP		0x0001
#define ASYNC_SND_ERROR		0x0002
#define ASYNC_SND_TIMOUT	0x0003



/***********************************************************************/
/*	Frame type definition			                                   */
/***********************************************************************/
#define FTYPE_SYNC					0x1000	/* Frame type of SYNC frame */
#define FTYPE_CR					0x2000	/* Frame type of CMD/RSP frame */
#define FTYPE_STATUS				0x6000	/* Frame type of STATUS frame */
#define FTYPE_TMC					0x7000	/* Frame type of TRANSMIT CYCLIC TIME frame */
#define FTYPE_MSG					0xC000	/* Frame type of MESSAGE frame */



/***********************************************************************/
/*	IOMAP member code definition						               */
/***********************************************************************/
#define AXIS_ADR	0x0001
#define T_RSP		0x0002
#define CD_LEN		0x0003
#define RD_LEN		0x0004
#define STS_NUM		0x0005
#define TR_DLY		0x0006



/***********************************************************************/
/*	Communication Parameter member code definition		               */
/***********************************************************************/
#define T_MCYC					1		/* COM PAR code definition : transission cycle*/
#define T_UNIT					2		/* COM PAR code definition : time unit */
#define PROT_SEL				3		/* COM PAR code definition : protcol select */
#define C2_DLY					4		/* COM PAR code definition : c2 delay time */



/***********************************************************************/
/*	T_UNIT code definition								               */
/***********************************************************************/
#define	TUNIT_10NSEC			0		/* time unit for range (t_mcyc < 500us) */
#define TUNIT_100NSEC			1		/* time unit for range (500us < t_mcyc < 4ms) */
#define TUNIT_1USEC				2		/* time unit for range (4ms < t_mcyc) */



/***********************************************************************/
/*	Structure of HOST I/F registers                                    */
/***********************************************************************/
typedef struct _JL100_HOST_IF_REGS {
	volatile ULONG cmd;			/* Command */
	volatile ULONG sts;			/* Status */
	volatile ULONG ints;		/* Interrupt Status */
	volatile ULONG imk;			/* Interrupt Mask (same as Interruput Status) */
	volatile ULONG ests;		/* Error Status */
	volatile ULONG mod;			/* Mode Setting */
	volatile ULONG cid;			/* Chip ID */
	volatile ULONG pars;		/* Communication Parameter Top Address */
	volatile ULONG sti1;		/* Connection Status 1 */
	volatile ULONG sti2;		/* Connection Status 2 */
	volatile ULONG crcv1;		/* Command Data Receive Status 1 */
	volatile ULONG crcv2;		/* Command Data Receive Status 2 */
	volatile ULONG rrcv1;		/* Response Data Receive Status 1 */
	volatile ULONG rrcv2;		/* Response Data Receive Status 2 */
	volatile ULONG cbadr;		/* Command Data Buffer Top Address */
	volatile ULONG rbadr;		/* Response Data Buffer Top Address */
	volatile ULONG gtim;		/* Global Time */
	volatile ULONG idly;		/* Interrupt Delay Time */
	volatile ULONG m3_gar;		/* MII address register for M3 */
	volatile ULONG m3_gdr;		/* MII data register for M3 */
	volatile ULONG reserved1;	/* Reserve */
	volatile ULONG reserved2;	/* Reserve */
	volatile ULONG reserved3;	/* Reserve */
	volatile ULONG reserved4;	/* Reserve */
	volatile ULONG test;		/* Test Mode */
} JL100_HOST_IF_REGS;



/***********************************************************************/
/*    Communication Parameter                                          */
/***********************************************************************/
typedef union _JL100_COM_PAR {
	struct{
		USHORT ma0;				/* My Address */
		USHORT ma_msk0;			/* Receive address filter setting for ma0*/
		USHORT ma1;				/* Multicast Address */
		USHORT ma_msk1;			/* Receive address filter setting for ma1 */
		USHORT srch_time;		/* Serch time for detecting slave */
		USHORT ma_max;			/* Max Number of Slave */
		USHORT t_mcyc;			/* Tmcyc */
		USHORT t_unit;			/* Global Time Unit */
		USHORT prot_sel;		/* Protcol Select */
		USHORT max_rtry;		/* Number of Max Retry */
		USHORT msg_ptr;			/* C1 Message buffer area top address */
		USHORT c1msg_sz;		/* C1 Message size */
		USHORT c2msg_sz;		/* C2 Message size */
		USHORT pkt_sz;			/* Sending size of one message frame */
		USHORT wdt;				/* Watch Dog Setting */
		USHORT c2_dly;			/* C2 Master Send Start Time */
		USHORT dly_cnt;			/* Number of Transmition delay time measure */
		USHORT iomap_ptr;		/* IOMAP buffer area top address  */
		USHORT ifgset;			/* Frame gap setting */
		USHORT max_frm;			/* Max Data size of PHY transfer */
		USHORT reserve1;		/*  */
		USHORT reserve2;		/*  */
		USHORT reserve3;		/*  */
		USHORT reserve4;		/*  */
		USHORT async_req_rtry;	/* Async start request retry count */
		USHORT dummy;			/*  */
	} str;
	unsigned long ulong_ptr;
} JL100_COM_PAR;



/***********************************************************************/
/*    IOMAP Struct                                                     */
/***********************************************************************/
typedef union _JL100_IO_MAP {
	struct{
		USHORT axis_adr;		/* My axis address */
		USHORT t_rsp;			/* Response monitering time */
		USHORT cd_len;			/* Command data length */
		USHORT rd_len;			/* Response data length */
		USHORT sts_num;			/* Status number */
		USHORT tr_dly;			/* Transmission delay time */
		USHORT dummy1;			/* dummy */
		USHORT dummy2;			/* dummy */
	} str;
	unsigned long ulong_ptr;
} JL100_IO_MAP;



/***********************************************************************/
/*    IOMAP Struct(for Read/Write access)                              */
/***********************************************************************/
typedef struct _JL100_IO_MAP_DWORD {
	ULONG dword1;			/* Lo:axis_adr, Hi:t_rsp  */
	ULONG dword2;			/* Lo:cd_len,   Hi:rd_len */
	ULONG dword3;			/* Lo:sts_num,  Hi:tr_dly */
	ULONG dword4;			/* Lo:dummy1,   Hi:dummy2 */
} JL100_IO_MAP_DWORD;



/***********************************************************************/
/*    USER SETTING IOMAP PARAM Struct                                  */
/***********************************************************************/
typedef struct _JL100_USER_IOMAP {
	ULONG  t_rsp;			/* Response monitering time */
	USHORT axis_adr;		/* My axis address */
	USHORT cd_len;			/* Command data length */
	USHORT rd_len;			/* Response data length */
	USHORT cmdbuff_offset;	/* Command buffer offset */
	USHORT rspbuff_offset;	/* Response buffer offset */
	USHORT dummy;			/* dummy */
} JL100_USER_IOMAP;



/***********************************************************************/
/*    User Setting Parameter                                           */
/***********************************************************************/
typedef struct _JL100_USER_PAR {
	ULONG  mod;				/* MOD register */
	USHORT ma0;				/* My Address */
	USHORT ma_max;			/* Max Number of Slaves */
	ULONG  t_mcyc;			/* Tmcyc */
	ULONG  intoffset;		/* Interrupt delay offset time */
	ULONG  c2_dly;			/* C2 Master Send Start Time */
	USHORT prot_sel;		/* Protocol Select */
	USHORT max_rtry;		/* Max Number of Retry */
	USHORT pkt_sz;			/* Sending Data size of One Message Frame */
	USHORT wdt;				/* Watch Dog Setting */
	USHORT dly_cnt;			/* Number of Transmition delay time measure */
	USHORT reserve1;		/* Reserve */
} JL100_USER_PAR;



/***********************************************************************/
/*    Register Parameter                                               */
/***********************************************************************/
typedef union _JL100_REG_PAR {
	struct{
		ULONG mod;				/* MOD register  */
		ULONG imk;				/* IMK register  */
		ULONG pars;				/* PARS register */
		ULONG idly;				/* IDLY register */
	} str;
	unsigned long ulong_ptr;
} JL100_REG_PAR;



/***********************************************************************/
/*    Global Frame Struct                                              */
/***********************************************************************/
typedef union _JL100_GBL_FRAME {
	struct{
		USHORT da;				/* Destination address */
		USHORT sa;				/* Source address */
		USHORT msg_ctrl;		/* Message control */
		USHORT ftyp_len;		/* Frame type & length */
		ULONG  time;			/* Global time */
		USHORT idly;			/* Interrupt offset time */
		USHORT reserve;			/* Reserve */
		ULONG  fcs;				/* Frame check sequence */
	} str;
	unsigned long ulong_ptr;
} JL100_GBL_FRAME;



/***********************************************************************/
/*    Header Info Struct                                               */
/***********************************************************************/
typedef union _JL100_FRAME_HEADER {
	struct{
		USHORT da;				/* Destination address */
		USHORT sa;				/* Source address */
		USHORT msg_ctrl;		/* Message control */
		USHORT ftyp_len;		/* Frame type & length */
	} str;
	unsigned long ulong_ptr;
} JL100_FRAME_HEADER;



/***********************************************************************/
/*    Header Info Struct(for async communication)                      */
/***********************************************************************/
typedef union _JL100_FRAME_HEADER_ASYNC {
	struct{
		USHORT t_rsp;			/* Transmission response monitering time */
		USHORT stat;			/* Status */
		USHORT da;				/* Destination address */
		USHORT sa;				/* Source address */
		USHORT msg_ctrl;		/* Message control */
		USHORT ftyp_len;		/* Frame type & length */
	} str;
	unsigned long ulong_ptr;
} JL100_FRAME_HEADER_ASYNC;



/***********************************************************************/
/*    Header Info Struct(for message communication)                    */
/***********************************************************************/
typedef union _JL100_FRAME_HEADER_MSG {
	struct{
		USHORT reserve;			/* Reserve */
		USHORT stat;			/* Status */
		USHORT da;				/* Destination address */
		USHORT sa;				/* Source address */
		USHORT msg_ctrl;		/* Message control */
		USHORT ftyp_len;		/* Frame type & length */
	} str;
	unsigned long ulong_ptr;
} JL100_FRAME_HEADER_MSG;



/***********************************************************************/
/*    Channel Buffer save  Parameter                                   */
/***********************************************************************/
typedef struct _CHANNEL_INFO {
	JL100_HOST_IF_REGS *hif_reg_top;	/* Host I/F register top */
	JL100_USER_IOMAP *usr_iomap;		/* User IOMAP buffer top */
	USHORT ma0;							/* My address */
	USHORT ma1;							/* Multicast address */
	USHORT ma_max;						/* Max nods */
	USHORT t_unit;						/* Time unit */
	USHORT prot_sel;					/* Communication mode */
	USHORT max_rtry;					/* Max retry */
	USHORT msg_ptr;						/* Message buffer pointer */
	USHORT pars_data;					/* Communication Param. address */
	USHORT iomap_ptr;					/* IOMAP buffer area top address */
	USHORT c1msg_sz;					/* C1 message buffer size */
	USHORT c2msg_sz;					/* C2 message buffer size */
	USHORT pkt_sz;						/* Packet size of message */
	USHORT chk_code;					/* Check code for processing sequence */
	USHORT my_st_no;					/* My station number (for monitor slave) */
	ULONG  cid;							/* ASIC chip ID */
} CHANNEL_INFO;



/***********************************************************************/
/*    Common Structure definition                                      */
/***********************************************************************/
typedef union _DWORD {
	ULONG dword;
	struct{
		USHORT lo;
		USHORT hi;
	} word;
	struct{
		UCHAR  l_lo;
		UCHAR  l_hi;
		UCHAR  h_lo;
		UCHAR  h_hi;
	} byte;
} DWORD;



/***********************************************************************/
/*    Host I/F Register Access Macro Definition                        */
/***********************************************************************/
#define jl100_get_cmd(pJL)          	(((JL100_HOST_IF_REGS *)pJL)->cmd)
#define jl100_set_cmd(pJL, data)    	(((JL100_HOST_IF_REGS *)pJL)->cmd = (ULONG)data)
#define jl100_get_sts(pJL)          	(((JL100_HOST_IF_REGS *)pJL)->sts)
#define jl100_get_ints(pJL)         	(((JL100_HOST_IF_REGS *)pJL)->ints)
#define jl100_clear_ints(pJL, data) 	(((JL100_HOST_IF_REGS *)pJL)->ints = (ULONG)data)
#define jl100_get_imk(pJL)    			(((JL100_HOST_IF_REGS *)pJL)->imk)
#define jl100_set_imk(pJL, data)    	(((JL100_HOST_IF_REGS *)pJL)->imk = (ULONG)data)
#define jl100_get_ests(pJL)         	(((JL100_HOST_IF_REGS *)pJL)->ests)
#define jl100_clear_ests(pJL, data) 	(((JL100_HOST_IF_REGS *)pJL)->ests =(ULONG)data)
#define jl100_get_mod(pJL)          	(((JL100_HOST_IF_REGS *)pJL)->mod)
#define jl100_set_mod(pJL, data)    	(((JL100_HOST_IF_REGS *)pJL)->mod = (ULONG)data)
#define jl100_get_cid(pJL)          	(((JL100_HOST_IF_REGS *)pJL)->cid)
#define jl100_get_pars(pJL)				(((JL100_HOST_IF_REGS *)pJL)->pars)
#define jl100_set_pars(pJL, data)		(((JL100_HOST_IF_REGS *)pJL)->pars = (ULONG)data)
#define jl100_get_sti1(pJL)         	(((JL100_HOST_IF_REGS *)pJL)->sti1)
#define jl100_get_sti2(pJL)         	(((JL100_HOST_IF_REGS *)pJL)->sti2)
#define jl100_get_crcv1(pJL)			(((JL100_HOST_IF_REGS *)pJL)->crcv1)
#define jl100_get_crcv2(pJL)			(((JL100_HOST_IF_REGS *)pJL)->crcv2)
#define jl100_get_rrcv1(pJL)			(((JL100_HOST_IF_REGS *)pJL)->rrcv1)
#define jl100_get_rrcv2(pJL)			(((JL100_HOST_IF_REGS *)pJL)->rrcv2)
#define jl100_get_cbadr(pJL)			((((JL100_HOST_IF_REGS *)pJL)->cbadr) << 1)	/* << 1 : Word -> Byte */
#define jl100_get_rbadr(pJL)			((((JL100_HOST_IF_REGS *)pJL)->rbadr) << 1)	/* << 1 : Word -> Byte */
#define jl100_get_gtim(pJL)				(((JL100_HOST_IF_REGS *)pJL)->gtim)
#define jl100_get_idly(pJL)				(((JL100_HOST_IF_REGS *)pJL)->idly)
#define jl100_set_idly(pJL, data)		(((JL100_HOST_IF_REGS *)pJL)->idly = (ULONG)data)
#define jl100_get_m3gar(pJL)			(((JL100_HOST_IF_REGS *)pJL)->m3_gar)
#define jl100_set_m3gar(pJL, data)		(((JL100_HOST_IF_REGS *)pJL)->m3_gar = (ULONG)data)
#define jl100_get_m3gdr(pJL)			(((JL100_HOST_IF_REGS *)pJL)->m3_gdr)
#define jl100_set_m3gdr(pJL, data)		(((JL100_HOST_IF_REGS *)pJL)->m3_gdr = (ULONG)data)
#define jl100_get_reserved1(pJL)		(((JL100_HOST_IF_REGS *)pJL)->reserved1)
#define jl100_set_reserved1(pJL, data)	(((JL100_HOST_IF_REGS *)pJL)->reserved1 = (ULONG)data)
#define jl100_get_reserved2(pJL)		(((JL100_HOST_IF_REGS *)pJL)->reserved2)
#define jl100_set_reserved2(pJL, data)	(((JL100_HOST_IF_REGS *)pJL)->reserved2 = (ULONG)data)
#define jl100_get_reserved3(pJL)		(((JL100_HOST_IF_REGS *)pJL)->reserved3)
#define jl100_set_reserved3(pJL, data)	(((JL100_HOST_IF_REGS *)pJL)->reserved3 = (ULONG)data)
#define jl100_get_reserved4(pJL)		(((JL100_HOST_IF_REGS *)pJL)->reserved4)
#define jl100_set_reserved4(pJL, data)	(((JL100_HOST_IF_REGS *)pJL)->reserved4 = (ULONG)data)
#define jl100_set_test(pJL, data)		(((JL100_HOST_IF_REGS *)pJL)->test = (ULONG)data)

#define jl100_read_dwdata(rdp)			*((ULONG *)rdp); rdp++
#define jl100_read_wdata(rdp)			*((USHORT *)rdp); rdp++
#define jl100_write_dwdata(wtp, rdp)	*((ULONG *)wtp) = *((ULONG *)rdp); ++wtp; ++rdp
#define jl100_write_wdata(wtp, rdp)		*((USHORT *)wtp) = *((USHORT *)rdp); ++wtp; ++rdp

#endif /* JL100_DEF_H_ */

/****************************************************************************/
/*                                                                          */
/*        JL100M_GBL.H : Common header of JL-100 access driver              */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*       Defines:                                                           */
/*          Definetion of Host Interface registers                          */
/*                                                                          */
/******** Copyright(C) 2007 Yaskawa Electric Corporation ********************/
/*                                                                          */
/*       Ver 1.00  :  2007.12.20  Initial coding  T.soeda                   */
/*                                                                          */
/****************************************************************************/
//#include "little_jl100_def.h"

/***********************************************************************/
/*   ASIC polling counter (max setting)                                */
/***********************************************************************/
#define JL100_CMD_POLLING_CNT	0x0000ffff	/* max polling count for CMD register */

/***********************************************************************/
/*   access driver version                                             */
/***********************************************************************/
#define ACCESS_DRIVER_VERSION	0x01200001		/* Access driver version : 1.20     */
												/* Support type          : C1master */

/***********************************************************************/
/*   function prototype                                                */
/***********************************************************************/
#ifdef __cplusplus
extern	"C"	{
#endif

extern void  jl100m_init_channel( CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, JL100_USER_IOMAP *usr_iomapp );
extern short jl100m_setup_asic(ULONG *hif_reg_top);
extern short jl100m_chk_asic_ready(ULONG *hif_reg_top);
extern short jl100m_set_usr_param(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_par, 
									JL100_REG_PAR *reg_par, JL100_COM_PAR *com_par);
extern short jl100m_reset_asic(CHANNEL_INFO *chbuffp);
extern short jl100m_set_regpar(CHANNEL_INFO *chbuffp, JL100_REG_PAR *reg_par);
extern short jl100m_write_compar(CHANNEL_INFO *chbuffp, JL100_COM_PAR *com_parp);
extern short jl100m_write_iomap(CHANNEL_INFO *chbuffp, JL100_USER_IOMAP *usr_iomapp);
extern short jl100m_req_set_par(CHANNEL_INFO *chbuffp);
extern short jl100m_initialize( CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, 
                          JL100_USER_PAR *usr_parp, JL100_USER_IOMAP *usr_iomapp );
extern short jl100m_req_detect_slv(CHANNEL_INFO *chbuffp);
extern short jl100m_chk_detect_slv_cmp(CHANNEL_INFO *chbuffp);
extern short jl100m_req_measure_transdly(CHANNEL_INFO *chbuffp);
extern short jl100m_chk_transdly_cmp(CHANNEL_INFO *chbuffp);
extern short jl100m_calc_dlytime(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_parp, 
                                                 JL100_USER_IOMAP *usr_iomapp);
extern short jl100m_infm_cmode(CHANNEL_INFO *chbuffp);
extern short jl100m_chk_infm_cmode_cmp(CHANNEL_INFO *chbuffp);
extern short jl100m_start_sync(CHANNEL_INFO *chbuffp);
extern short jl100m_start_async(CHANNEL_INFO *chbuffp);
extern short jl100m_set_first_data(CHANNEL_INFO *chbuffp);
extern short jl100m_read_ram(ULONG *hif_reg_top, USHORT ofst_adr, USHORT size, ULONG *rdata);
extern short jl100m_write_ram(ULONG *hif_reg_top, USHORT ofst_adr, USHORT size, ULONG wdata);
extern short jl100m_activate_comprm(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_parp,
                                                           JL100_USER_IOMAP *iomapp);
extern short jl100m_read_slvstat(CHANNEL_INFO *chbuffp, USHORT st_no);
extern USHORT jl100m_read_iomap_member(CHANNEL_INFO *chbuffp, USHORT st_no, USHORT member);
extern void jl100m_write_iomap_member(CHANNEL_INFO *chbuffp, USHORT st_no, USHORT member, USHORT data);
extern USHORT jl100m_find_max_trdly(CHANNEL_INFO *chbuffp);
extern short jl100m_chk_iomap_prm(CHANNEL_INFO *chbuffp, JL100_USER_IOMAP *usr_iomapp);
extern short jl100m_begin_cyclic_com(CHANNEL_INFO *chbuffp);
extern unsigned long jl100m_chk_intrp_factor(CHANNEL_INFO *chbuffp);
extern void  jl100m_async_rcv_enable(CHANNEL_INFO *chbuffp);
extern short jl100m_change_rbuff(CHANNEL_INFO *chbuffp);
extern short jl100m_change_cbuff(CHANNEL_INFO *chbuffp);
extern short jl100m_read_ldata(CHANNEL_INFO *chbuffp, USHORT st_no, ULONG *rbuffp);
extern short jl100m_write_ldata(CHANNEL_INFO *chbuffp, USHORT st_no, ULONG *sbuffp);
extern short jl100m_req_rcv_frame(CHANNEL_INFO *chbuffp, USHORT *st_adr, USHORT *rcv_stat, 
												USHORT *ftype, ULONG *rbuffp, USHORT *size, USHORT tout_time);
extern short jl100m_send_frame(CHANNEL_INFO *chbuffp, USHORT st_adr, USHORT ftype, ULONG *sbuffp, USHORT size);

extern void jl100m_get_rrcvstat(CHANNEL_INFO *chbuffp, ULONG *rcvstat);
extern void jl100m_get_stistat(CHANNEL_INFO *chbuffp, ULONG *stistat);
extern ULONG jl100m_read_comstat(CHANNEL_INFO *chbuffp);
extern short jl100m_get_cid(CHANNEL_INFO *chbuffp);
extern ULONG jl100m_get_accdrv_ver(void);
extern USHORT jl100m_get_rbuff_offset(CHANNEL_INFO *chbuffp, USHORT st_no);
extern USHORT jl100m_get_cbuff_offset(CHANNEL_INFO *chbuffp, USHORT st_no);
extern short jl100m_req_rcv_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT st_adr, USHORT *msg_size);
extern short jl100m_req_snd_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT st_adr, USHORT msg_size);
extern short jl100m_abort_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg);
extern short jl100m_read_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT offset, 
                                                                      USHORT size, ULONG *rdata);
extern short jl100m_write_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT offset, 
                                                                       USHORT size, ULONG *sdata);

#ifdef __cplusplus
}
#endif

/************************************************************************************************/
/*																								*/
/*		SMPL_PAR.H : Prameter setting for JL-100 sample program.(C1 master)						*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*		Ver 1.00	:	2007.12.20	Initial coding	T.soeda										*/
/*																								*/
/************************ Copyright(C) 2007 Yaskawa Electric Corporation ************************/
/*																								*/
/*		FUNCTIONS :																				*/
/*																								*/
/************************************************************************************************/
/************************************************************************/
/*  Definetions                                                         */
/************************************************************************/
/* System setting parameter */
#define DEF_MA_MAX				8				/* Maximum Number of Slaves */
#define DEF_TMCYC				50000			/* T_MCYC setting (time unit : 10nsec) */
#define DEF_MAX_RTRY			1				/* Max retry setting */
#define DEF_PROT_SEL			0				/* Protocol select (0:sync, 1:async) */
#define DEF_WDT					16384			/* WDT setting */

/* Sync. communication parameter */
#define DEF_INT_OFFSET			25000			/* INT_OFFSET setting (time unit : 10nsec) */
#define DEF_C2_DLY				49500			/* C2_DLY setting     (time unit : 10nsec) */
#define DEF_TRSP				5000			/* T_RSP  setting     (time unit : 10nsec) */
#define DEF_CD_LEN				48				/* Command data length (unit : byte) */
#define DEF_RD_LEN				48				/* Response data length (unit : byte) */

/* C1/C2 message communication parameter */
#define C1MSG_PEER_ADR			0x0021			/* Destination address of C1 message communication */
#define DEF_C1MSG_SIZE			64				/* C1 message data length (unit : byte) */
#define C2MSG_PEER_ADR			0x0002  		/* Destination address of C2 message communication */
#define DEF_C2MSG_SIZE			64				/* C2 message data length (unit : byte) */
#define DEF_PKT_SZ				64				/* Message packet size */

/* Async. communication parameter */
#define DEF_ASYNC_PEER_ADR		0x21			/* Destination address of Async. communication */
#define DEF_ASYNC_FTYPE			0x02			/* Frame type of async communication(0x02 or 0x0C) */
#define DEF_ASYNC_DATA_SIZE		64				/* Async. communication data size (unit : byte) */
#define DEF_ASYNC_RCV_TOUT_TIME 0xFFFF			/* Async. communication receive time-out setting */
												/* unit : usec */

#ifndef OK
#define	OK						0
#endif

/*****************************************************************************/
/*                                                                           */
/*     JL-100 micro code table (for C1 master)                               */
/*                                                                           */
/*****************************************************************************/
const	unsigned short	AsicUprg[] = {
0x8a01, 0x0000, 0x8401, 0x0000, 0x8501, 0x0001, 0x0001, 0x0000, 
0x0101, 0x0000, 0x0201, 0x0000, 0x0301, 0x0000, 0x0501, 0x0000, 
0x0601, 0x0000, 0x0701, 0x0000, 0x0801, 0x0000, 0x0901, 0x0000, 
0x0a01, 0x0000, 0x0b01, 0x0000, 0x0c01, 0x0000, 0x0d01, 0x0000, 
0x0e01, 0x0000, 0x0f01, 0x0000, 0x1001, 0x0000, 0x1101, 0x0000, 
0x1201, 0x0000, 0x1301, 0x0000, 0x1401, 0x0000, 0x1501, 0x0000, 
0x1601, 0x0000, 0x1701, 0x0000, 0x1801, 0x0000, 0x1901, 0x0000, 
0x1a01, 0x0000, 0x1b01, 0x0000, 0x1c01, 0x0000, 0x1d01, 0x0000, 
0x1e01, 0x0000, 0x1f01, 0x0000, 0x2001, 0x0000, 0x2101, 0x0000, 
0x2201, 0x0000, 0x2301, 0x0000, 0x2401, 0x0000, 0x2501, 0x0000, 
0x2601, 0x0000, 0x2701, 0x0000, 0x2801, 0x0000, 0x2901, 0x0000, 
0x2a01, 0x0000, 0x2b01, 0x0000, 0x2c01, 0x0000, 0x2d01, 0x0000, 
0x2e01, 0x0000, 0x2f01, 0x0000, 0x3001, 0x0000, 0x3101, 0x0000, 
0x3201, 0x0000, 0x3301, 0x0000, 0x3401, 0x0000, 0x3501, 0x0000, 
0x3601, 0x0000, 0x3701, 0x0000, 0x3801, 0x0000, 0x3901, 0x0000, 
0x3a01, 0x0000, 0x3b01, 0x0000, 0x3c01, 0x0000, 0x3d01, 0x0000, 
0x3e01, 0x0000, 0x3f01, 0x0000, 0x4001, 0x0000, 0x4101, 0x0000, 
0x4201, 0x0000, 0x4301, 0x0000, 0x4401, 0x0000, 0x0101, 0x5555, 
0x0201, 0x3fff, 0x4501, 0x0000, 0x4611, 0x0001, 0x0203, 0x0001, 
0x020e, 0x0094, 0x8501, 0x0001, 0x0201, 0x3fff, 0x4501, 0x0000, 
0x0011, 0x0046, 0x0014, 0x0001, 0x019b, 0x00aa, 0x4b01, 0x4000, 
0x001d, 0x00d4, 0x0203, 0x0001, 0x020e, 0x00a0, 0x8501, 0x0001, 
0x0104, 0x5555, 0x019a, 0x00b8, 0x0101, 0xaaaa, 0x001d, 0x0090, 
0x0104, 0xaaaa, 0x019a, 0x00c0, 0x0101, 0xffff, 0x001d, 0x0090, 
0x0104, 0xffff, 0x019a, 0x00c8, 0x0101, 0x0000, 0x001d, 0x0090, 
0x890c, 0x00ce, 0x4b06, 0x2004, 0x001d, 0x00d4, 0x8601, 0x0001, 
0x4b06, 0x2002, 0x001d, 0x00d8, 0x8501, 0x0001, 0x001d, 0x00d4, 
0x8a01, 0x0001, 0x3e01, 0x0018, 0x8501, 0x0001, 0x4a0c, 0x00dc, 
0x50bc, 0x00e6, 0x3e06, 0x0001, 0x8811, 0x003e, 0x4a01, 0x0001, 
0x4d01, 0x0001, 0x0011, 0x0050, 0x0005, 0x0003, 0x021b, 0x00f6, 
0x4b01, 0x4000, 0x8501, 0x0001, 0x001d, 0x00f2, 0x0a11, 0x006b, 
0x0a19, 0x0001, 0x0a02, 0x0018, 0x3e06, 0x0004, 0x3e05, 0xfffd, 
0x8811, 0x003e, 0x0506, 0x0020, 0x50fc, 0x010a, 0x0506, 0x0008, 
0x001d, 0x010e, 0x0505, 0xfff7, 0x001d, 0x0114, 0x50cc, 0x0114, 
0x0506, 0x0010, 0x001d, 0x0116, 0x0505, 0xffef, 0x504c, 0x011c, 
0x0506, 0x0400, 0x001d, 0x011e, 0x0505, 0xfbff, 0x001d, 0x0120, 
0x8a01, 0x0002, 0x8501, 0x0001, 0x4a2c, 0x0122, 0x003d, 0x0bc2, 
0x030e, 0x0136, 0x003d, 0x0cf8, 0x003d, 0x0e1a, 0x030e, 0x0136, 
0x4a01, 0x0004, 0x4d01, 0x0004, 0x001d, 0x025a, 0x4e01, 0x0004, 
0x4a01, 0x0004, 0x4d01, 0x0004, 0x001d, 0x0122, 0x8a01, 0x0060, 
0x4a01, 0x0040, 0x0901, 0x0000, 0x0011, 0x006b, 0x0019, 0x0002, 
0x0a11, 0x0000, 0x4d01, 0x0040, 0x3e05, 0xfffd, 0x8811, 0x003e, 
0x0011, 0x0025, 0x0018, 0x000e, 0x8605, 0x3fff, 0x8616, 0x0000, 
0x8011, 0x0024, 0x8606, 0x0002, 0x8501, 0x0001, 0x4a2c, 0x0176, 
0x003d, 0x0bc2, 0x030e, 0x0170, 0x003d, 0x0cf8, 0x003d, 0x0e1a, 
0x030e, 0x0170, 0x4d01, 0x0004, 0x4a01, 0x0004, 0x001d, 0x0150, 
0x4e01, 0x0004, 0x4a01, 0x0004, 0x001d, 0x015c, 0x493c, 0x01d6, 
0x4511, 0x0009, 0x8111, 0x0046, 0x8701, 0x0004, 0x8606, 0x0004, 
0x4502, 0x0001, 0x490c, 0x0192, 0x5111, 0x0046, 0x5211, 0x0046, 
0x5311, 0x0046, 0x5411, 0x0046, 0x8701, 0x0002, 0x5a01, 0x0061, 
0x001d, 0x01ac, 0x5511, 0x0046, 0x5611, 0x0046, 0x5711, 0x0046, 
0x0011, 0x0046, 0x5811, 0x0000, 0x0005, 0x0fff, 0x0019, 0x0002, 
0x4711, 0x0000, 0x5b8c, 0x01a8, 0x872c, 0x01a2, 0x001d, 0x01d0, 
0x451f, 0x0000, 0x5a01, 0x0021, 0x5a0c, 0x01b2, 0x872c, 0x01ac, 
0x001d, 0x01d0, 0x8605, 0xfffb, 0x4101, 0x863f, 0x023d, 0x0f66, 
0x020e, 0x01cc, 0x0001, 0x0001, 0x0908, 0x0001, 0x4611, 0x0000, 
0x490c, 0x01c6, 0x4901, 0x0001, 0x4c01, 0x0001, 0x4901, 0x0008, 
0x4c01, 0x0008, 0x001d, 0x01d6, 0x0001, 0x0002, 0x001d, 0x01bc, 
0x8605, 0xfffb, 0x0001, 0x0003, 0x001d, 0x01bc, 0x497c, 0x0256, 
0x6401, 0x0001, 0x4511, 0x000a, 0x8111, 0x0046, 0x8701, 0x0004, 
0x8606, 0x0004, 0x4502, 0x0001, 0x8501, 0x0001, 0x651c, 0x022e, 
0x8605, 0xfffb, 0x658c, 0x01f0, 0x6501, 0x0100, 0x001d, 0x023e, 
0x652c, 0x0236, 0x0211, 0x0065, 0x0205, 0x0600, 0x020e, 0x0242, 
0x653c, 0x023a, 0x656c, 0x0206, 0x4611, 0x005c, 0x4611, 0x005d, 
0x4611, 0x005e, 0x4611, 0x005f, 0x001d, 0x020e, 0x4611, 0x0060, 
0x4611, 0x0061, 0x4611, 0x0062, 0x4611, 0x0063, 0x0a08, 0x0005, 
0x0011, 0x0046, 0x0005, 0x0fff, 0x0019, 0x0002, 0x0002, 0x0001, 
0x4811, 0x0000, 0x657c, 0x021e, 0x001d, 0x021a, 0x451e, 0x0000, 
0x6501, 0x007e, 0x0001, 0x0001, 0x0a08, 0x0001, 0x4611, 0x0000, 
0x4901, 0x0080, 0x4c01, 0x0080, 0x001d, 0x015c, 0x65fc, 0x024e, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x001d, 0x023e, 0x65fc, 0x01f0, 
0x001d, 0x0230, 0x4e01, 0x0001, 0x001d, 0x0244, 0x0211, 0x0065, 
0x0205, 0x0600, 0x4e11, 0x0002, 0x6501, 0x0800, 0x6401, 0x0080, 
0x6501, 0x007e, 0x0001, 0x0002, 0x001d, 0x0224, 0x872c, 0x01e4, 
0x8605, 0xfffb, 0x0001, 0x0003, 0x001d, 0x0224, 0x4a4c, 0x015c, 
0x001d, 0x0500, 0x8a01, 0x0003, 0x0001, 0x003f, 0x0d11, 0x0032, 
0x0d02, 0x0008, 0x0d08, 0x0004, 0x4611, 0x0044, 0x0003, 0x0001, 
0x000e, 0x0260, 0x8501, 0x0001, 0x4a1c, 0x026a, 0x6401, 0x0080, 
0x6501, 0x8800, 0x6501, 0x007e, 0x0301, 0x0000, 0x8605, 0x3fff, 
0x8606, 0x8000, 0x8605, 0xfdff, 0x0111, 0x006b, 0x0119, 0x0001, 
0x0108, 0x0004, 0x0011, 0x0046, 0x8111, 0x0000, 0x3e05, 0xffef, 
0x8811, 0x003e, 0x0101, 0x0001, 0x6401, 0x0009, 0x0d11, 0x0032, 
0x0d02, 0x0008, 0x0001, 0x003f, 0x4201, 0x0002, 0x3801, 0x0000, 
0x0d08, 0x0000, 0x3311, 0x0046, 0x330f, 0x0332, 0x4111, 0x0033, 
0x4105, 0xff00, 0x410f, 0x02bc, 0x4111, 0x0033, 0x4105, 0x00ff, 
0x7711, 0x0041, 0x4111, 0x0076, 0x4118, 0x0003, 0x0211, 0x0032, 
0x0212, 0x0041, 0x0208, 0x0005, 0x4111, 0x0046, 0x0d08, 0x0005, 
0x4611, 0x0041, 0x001d, 0x0332, 0x003d, 0x118e, 0x5b8c, 0x02c2, 
0x001d, 0x02be, 0x431f, 0x0000, 0x8701, 0x0004, 0x8606, 0x0014, 
0x5a01, 0x0021, 0x5a0c, 0x02ce, 0x001d, 0x02ca, 0x4101, 0x863f, 
0x023d, 0x0f66, 0x020f, 0x02da, 0x4a01, 0x0002, 0x4d01, 0x0002, 
0x001d, 0x026a, 0x8501, 0x0001, 0x872c, 0x02da, 0x8607, 0x0014, 
0x651c, 0x036a, 0x658c, 0x02e8, 0x6501, 0x0100, 0x001d, 0x0360, 
0x652c, 0x0354, 0x6114, 0x0033, 0x019a, 0x036a, 0x6304, 0x6004, 
0x019a, 0x036a, 0x4111, 0x0065, 0x4105, 0x0600, 0x410e, 0x036e, 
0x653c, 0x035c, 0x4801, 0x0002, 0x431e, 0x0000, 0x657c, 0x0302, 
0x001d, 0x02fe, 0x4308, 0x0001, 0x4111, 0x0046, 0x4105, 0x003f, 
0x410f, 0x0310, 0x380e, 0x0360, 0x3801, 0x0001, 0x001d, 0x0314, 
0x4203, 0x0001, 0x3801, 0x0000, 0x6501, 0x007e, 0x420e, 0x0298, 
0x0d08, 0x0004, 0x0211, 0x0046, 0x020e, 0x0360, 0x4308, 0x0000, 
0x4111, 0x0046, 0x0d08, 0x0004, 0x4611, 0x0041, 0x0211, 0x0083, 
0x0219, 0x0001, 0x0d08, 0x0005, 0x4611, 0x0002, 0x6406, 0x0080, 
0x6501, 0x007e, 0x0003, 0x0001, 0x000f, 0x033a, 0x0d02, 0x0008, 
0x001d, 0x0294, 0x010f, 0x0346, 0x3e06, 0x0010, 0x3e05, 0xfff7, 
0x8811, 0x003e, 0x0101, 0x0000, 0x001d, 0x028e, 0x3e06, 0x0008, 
0x8811, 0x003e, 0x6401, 0x0000, 0x4a01, 0x0002, 0x4d01, 0x0002, 
0x030e, 0x026a, 0x001d, 0x0376, 0x65fc, 0x02e8, 0x4e01, 0x0800, 
0x6501, 0x8000, 0x001d, 0x036a, 0x4e01, 0x0001, 0x001d, 0x032e, 
0x4e01, 0x0010, 0x0301, 0x0001, 0x0201, 0x0023, 0x0d08, 0x0004, 
0x4611, 0x0002, 0x4111, 0x0065, 0x4105, 0x0600, 0x4e11, 0x0041, 
0x6406, 0x0080, 0x6501, 0x0800, 0x001d, 0x0330, 0x8a01, 0x0004, 
0x8501, 0x0001, 0x4a3c, 0x037e, 0x001d, 0x039a, 0x4a2c, 0x0392, 
0x003d, 0x0bc2, 0x030e, 0x038a, 0x003d, 0x0cf8, 0x003d, 0x0e1a, 
0x030f, 0x038c, 0x4e01, 0x0004, 0x4a01, 0x0004, 0x4d01, 0x0004, 
0x001d, 0x0378, 0x4a1c, 0x0396, 0x001d, 0x025a, 0x4a4c, 0x0378, 
0x001d, 0x0500, 0x4a01, 0x0008, 0x6401, 0x0080, 0x6501, 0x8800, 
0x6501, 0x007e, 0x3601, 0x0000, 0x0011, 0x0025, 0x0018, 0x000e, 
0x8605, 0x3fff, 0x8616, 0x0000, 0x0d11, 0x0032, 0x0d02, 0x0008, 
0x0001, 0x0001, 0x8501, 0x0001, 0x3801, 0x0000, 0x0d08, 0x0000, 
0x3311, 0x0046, 0x330f, 0x04e0, 0x4111, 0x0033, 0x4105, 0xff00, 
0x410f, 0x03e2, 0x4111, 0x0033, 0x4105, 0x00ff, 0x7711, 0x0041, 
0x4111, 0x0076, 0x4118, 0x0003, 0x0211, 0x0032, 0x0212, 0x0041, 
0x4119, 0x0003, 0x6c11, 0x0041, 0x4111, 0x006d, 0x6c11, 0x0000, 
0x6d11, 0x0041, 0x0208, 0x0005, 0x4111, 0x0046, 0x0d08, 0x0005, 
0x4611, 0x0041, 0x0d08, 0x0004, 0x3411, 0x0046, 0x3404, 0x0022, 
0x049b, 0x04e0, 0x6c11, 0x0000, 0x6d01, 0x0000, 0x0201, 0x0025, 
0x0d08, 0x0004, 0x4611, 0x0002, 0x003d, 0x115e, 0x5b8c, 0x03fa, 
0x001d, 0x03f6, 0x431f, 0x0000, 0x5a01, 0x0021, 0x5a0c, 0x0402, 
0x001d, 0x03fe, 0x4101, 0x863b, 0x023d, 0x0f66, 0x020e, 0x0378, 
0x0201, 0x0026, 0x0d08, 0x0004, 0x4611, 0x0002, 0x0111, 0x006b, 
0x0119, 0x0001, 0x0108, 0x0016, 0x3811, 0x0046, 0x380f, 0x041c, 
0x3803, 0x0001, 0x001d, 0x0416, 0x6611, 0x0033, 0x0111, 0x0031, 
0x0301, 0x0000, 0x4201, 0x0000, 0x3f1a, 0x0438, 0x250e, 0x042c, 
0x8101, 0xc350, 0x001d, 0x043e, 0x2504, 0x0001, 0x019a, 0x0434, 
0x8101, 0x1388, 0x001d, 0x043e, 0x8101, 0x01f4, 0x001d, 0x043e, 
0x0d08, 0x0001, 0x0211, 0x0046, 0x8111, 0x0002, 0x8501, 0x0001, 
0x003d, 0x1178, 0x5b8c, 0x0446, 0x001d, 0x0442, 0x431f, 0x0000, 
0x8701, 0x0004, 0x8606, 0x0014, 0x6401, 0x0001, 0x5a01, 0x0021, 
0x5a0c, 0x0454, 0x001d, 0x0450, 0x4101, 0x863b, 0x023d, 0x0f66, 
0x020e, 0x0378, 0x652c, 0x0484, 0x658c, 0x0462, 0x6501, 0x0100, 
0x001d, 0x0490, 0x8605, 0xfffb, 0x0211, 0x0065, 0x0205, 0x0600, 
0x020e, 0x049c, 0x653c, 0x0498, 0x6014, 0x0033, 0x040c, 0x049e, 
0x0211, 0x0063, 0x0204, 0x4008, 0x019a, 0x047c, 0x6401, 0x0080, 
0x6501, 0x007e, 0x001d, 0x04ae, 0x0205, 0x0fff, 0x085b, 0x049e, 
0x4e01, 0x0100, 0x001d, 0x049e, 0x65fc, 0x048c, 0x4e01, 0x0800, 
0x6501, 0x8000, 0x001d, 0x0490, 0x872c, 0x045a, 0x8701, 0x0004, 
0x8607, 0x0004, 0x0211, 0x0065, 0x0205, 0x0600, 0x001d, 0x049c, 
0x4e01, 0x0001, 0x001d, 0x049e, 0x4e11, 0x0002, 0x6401, 0x0080, 
0x6501, 0x0800, 0x0201, 0x0024, 0x0d08, 0x0004, 0x4611, 0x0002, 
0x6501, 0x007e, 0x3801, 0x0001, 0x001d, 0x04e0, 0x0104, 0x0001, 
0x049b, 0x04d2, 0x0312, 0x0083, 0x0313, 0x003f, 0x0103, 0x0001, 
0x010e, 0x0442, 0x8607, 0x0010, 0x0211, 0x0031, 0x0219, 0x0001, 
0x020f, 0x04c6, 0x0319, 0x0001, 0x001d, 0x04be, 0x0319, 0x0001, 
0x4211, 0x0003, 0x3614, 0x0003, 0x042c, 0x0424, 0x3611, 0x0003, 
0x001d, 0x0424, 0x0d08, 0x0005, 0x4611, 0x0003, 0x6c11, 0x0000, 
0x6d01, 0x0001, 0x0201, 0x0027, 0x0d08, 0x0004, 0x4611, 0x0002, 
0x6601, 0x0001, 0x0002, 0x0001, 0x0004, 0x003f, 0x040f, 0x04fc, 
0x0d02, 0x0008, 0x380f, 0x03b2, 0x0111, 0x006b, 0x0119, 0x0001, 
0x0108, 0x0017, 0x3811, 0x0046, 0x380f, 0x03b2, 0x3803, 0x0001, 
0x001d, 0x04f4, 0x001d, 0x03b2, 0x4d01, 0x0008, 0x001d, 0x0500, 
0x8a01, 0x0005, 0x8605, 0x3fff, 0x8606, 0x8000, 0x8101, 0x01f4, 
0x8501, 0x0001, 0x4a4c, 0x050e, 0x001d, 0x0526, 0x4a2c, 0x0522, 
0x003d, 0x0bc2, 0x030e, 0x051a, 0x003d, 0x0cf8, 0x003d, 0x0e1a, 
0x030f, 0x051c, 0x4e01, 0x0004, 0x4a01, 0x0004, 0x4d01, 0x0004, 
0x001d, 0x0508, 0x4a3c, 0x0508, 0x001d, 0x0376, 0x4a01, 0x0010, 
0x6401, 0x0080, 0x6501, 0x8800, 0x6501, 0x007e, 0x3301, 0xffff, 
0x0001, 0x0002, 0x003d, 0x11a8, 0x5b8c, 0x0538, 0x001d, 0x0534, 
0x431f, 0x0000, 0x5a01, 0x0021, 0x5a0c, 0x0540, 0x001d, 0x053c, 
0x4101, 0x863f, 0x023d, 0x0f66, 0x020f, 0x0550, 0x0003, 0x0001, 
0x000e, 0x054c, 0x001d, 0x0508, 0x8501, 0x0001, 0x001d, 0x0532, 
0x0201, 0x0064, 0x8501, 0x0001, 0x0203, 0x0001, 0x020e, 0x0552, 
0x0601, 0x0001, 0x0801, 0x0000, 0x0d11, 0x0032, 0x0d02, 0x0008, 
0x260f, 0x056e, 0x0211, 0x006b, 0x0219, 0x0001, 0x0208, 0x0018, 
0x3811, 0x0046, 0x380e, 0x056e, 0x3801, 0x0001, 0x6c11, 0x0006, 
0x0d08, 0x0000, 0x3311, 0x0046, 0x0311, 0x0033, 0x0305, 0xff00, 
0x030e, 0x0614, 0x6d0e, 0x058e, 0x260f, 0x0614, 0x330f, 0x0614, 
0x8701, 0x0004, 0x8606, 0x0004, 0x8501, 0x0001, 0x872c, 0x0584, 
0x8607, 0x0004, 0x8701, 0x0004, 0x001d, 0x0614, 0x003d, 0x118e, 
0x5b8c, 0x0594, 0x001d, 0x0590, 0x431f, 0x0000, 0x6401, 0x0001, 
0x5a01, 0x0021, 0x8701, 0x0004, 0x8606, 0x0004, 0x5a0c, 0x05a2, 
0x001d, 0x059e, 0x4101, 0x863f, 0x023d, 0x0f66, 0x020f, 0x05aa, 
0x001d, 0x0508, 0x652c, 0x05de, 0x260f, 0x05b0, 0x872c, 0x05ae, 
0x658c, 0x05b6, 0x6501, 0x0100, 0x001d, 0x05ea, 0x8607, 0x0004, 
0x0111, 0x0065, 0x0105, 0x0600, 0x010e, 0x05f0, 0x653c, 0x05f4, 
0x6114, 0x0033, 0x040c, 0x05f6, 0x0111, 0x0063, 0x0104, 0x6004, 
0x019b, 0x05d2, 0x0105, 0x0fff, 0x083b, 0x05f6, 0x4e01, 0x0100, 
0x001d, 0x05f6, 0x4801, 0x0002, 0x657c, 0x05d8, 0x001d, 0x05d4, 
0x431e, 0x0000, 0x6501, 0x007e, 0x001d, 0x0600, 0x65fc, 0x05e4, 
0x6501, 0x8000, 0x001d, 0x05ea, 0x872c, 0x05aa, 0x8701, 0x0004, 
0x001d, 0x05ea, 0x8607, 0x0004, 0x0111, 0x0065, 0x0105, 0x0600, 
0x4e11, 0x0001, 0x001d, 0x05f6, 0x4e01, 0x0001, 0x6401, 0x0080, 
0x6501, 0x0800, 0x6501, 0x007e, 0x0802, 0x0001, 0x001d, 0x0614, 
0x4308, 0x0000, 0x0311, 0x0046, 0x0304, 0x0030, 0x049a, 0x060c, 
0x0802, 0x0001, 0x001d, 0x0610, 0x607b, 0x0610, 0x0301, 0x0050, 
0x0d08, 0x0004, 0x4611, 0x0003, 0x0602, 0x0001, 0x0d02, 0x0008, 
0x0604, 0x0040, 0x049b, 0x056e, 0x080f, 0x0630, 0x260f, 0x062e, 
0x3803, 0x0001, 0x380f, 0x062e, 0x0801, 0x0000, 0x0601, 0x0001, 
0x0d11, 0x0032, 0x0d02, 0x0008, 0x001d, 0x056e, 0x4e01, 0x0002, 
0x4d01, 0x0010, 0x001d, 0x0634, 0x8a01, 0x0006, 0x8501, 0x0001, 
0x4a4c, 0x063c, 0x001d, 0x0500, 0x4a3c, 0x0640, 0x001d, 0x0376, 
0x4a5c, 0x069c, 0x1201, 0x0000, 0x1001, 0x0000, 0x1101, 0x0000, 
0x2101, 0x0021, 0x1511, 0x0028, 0x2a0e, 0x0650, 0x0505, 0xfffe, 
0x1c01, 0x0010, 0x1a01, 0x0000, 0x1b01, 0x0000, 0x1f11, 0x002b, 
0x0011, 0x0025, 0x0018, 0x000e, 0x8605, 0x3fff, 0x8616, 0x0000, 
0x8011, 0x0024, 0x3014, 0x0037, 0x019b, 0x066a, 0x8211, 0x0030, 
0x001d, 0x066c, 0x8201, 0xffff, 0x7911, 0x0037, 0x8701, 0x003f, 
0x7201, 0x0000, 0x4511, 0x0073, 0x5111, 0x0046, 0x5211, 0x0046, 
0x5311, 0x0046, 0x5411, 0x0046, 0x053c, 0x0688, 0x054c, 0x0684, 
0x8606, 0x3102, 0x001d, 0x0686, 0x8606, 0x1102, 0x001d, 0x068a, 
0x8606, 0x1002, 0x8501, 0x0001, 0x870c, 0x068a, 0x4a01, 0x0020, 
0x4d01, 0x0020, 0x4b06, 0x0001, 0x052c, 0x069a, 0x8411, 0x002f, 
0x8501, 0x0001, 0x001d, 0x06a0, 0x4a6c, 0x0636, 0x001d, 0x013e, 
0x8a01, 0x0007, 0x6401, 0x0080, 0x6501, 0x8900, 0x6501, 0x007e, 
0x5a01, 0x0080, 0x3208, 0x0001, 0x0011, 0x0046, 0x0003, 0x0001, 
0x8111, 0x0000, 0x7201, 0x0000, 0x4511, 0x0073, 0x5111, 0x0046, 
0x053c, 0x06ce, 0x871c, 0x06c2, 0x8701, 0x0002, 0x4e01, 0x0008, 
0x001d, 0x09e8, 0x5a01, 0x0043, 0x8606, 0x0204, 0x871c, 0x06c6, 
0x8701, 0x0003, 0x003d, 0x0f5c, 0x001d, 0x06e0, 0x003d, 0x0f5c, 
0x490c, 0x06ce, 0x8701, 0x0001, 0x5a01, 0x0061, 0x8701, 0x0002, 
0x8606, 0x0204, 0x4901, 0x0001, 0x4c01, 0x0001, 0x001d, 0x06e0, 
0x8a01, 0x0008, 0x8701, 0x000c, 0x0d11, 0x0032, 0x0d02, 0x0008, 
0x0601, 0x0001, 0x003d, 0x0ffe, 0x0c01, 0x0000, 0x0801, 0x0000, 
0x0911, 0x000a, 0x003d, 0x0f86, 0x872c, 0x06f8, 0x001d, 0x06fe, 
0x870c, 0x06f4, 0x4e01, 0x0008, 0x001d, 0x06a0, 0x8a01, 0x0009, 
0x870c, 0x0706, 0x4e01, 0x0008, 0x001d, 0x06a0, 0x7411, 0x0006, 
0x7011, 0x0006, 0x0111, 0x000d, 0x0602, 0x0001, 0x0d02, 0x0008, 
0x6401, 0x0001, 0x003d, 0x0ffe, 0x001d, 0x0716, 0x8a01, 0x000a, 
0x651c, 0x0780, 0x658c, 0x073e, 0x6501, 0x0100, 0x65fc, 0x0724, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x0802, 0x0001, 0x2714, 0x0008, 
0x049b, 0x0730, 0x0908, 0x0000, 0x4611, 0x0074, 0x0902, 0x0001, 
0x0108, 0x0003, 0x4311, 0x0046, 0x4319, 0x0002, 0x4302, 0x0001, 
0x4511, 0x0075, 0x003d, 0x0f3a, 0x001d, 0x077e, 0x0211, 0x0063, 
0x0311, 0x0002, 0x0205, 0x0fff, 0x0319, 0x000c, 0x027a, 0x074e, 
0x003d, 0x1054, 0x030f, 0x077e, 0x001d, 0x071e, 0x067a, 0x071e, 
0x003d, 0x1106, 0x030e, 0x077e, 0x0108, 0x0004, 0x0311, 0x0046, 
0x277b, 0x075e, 0x6c11, 0x0074, 0x6d01, 0x0000, 0x0108, 0x0000, 
0x3311, 0x0046, 0x0311, 0x0033, 0x0305, 0xff00, 0x030e, 0x077e, 
0x3d0f, 0x0772, 0x3a0f, 0x077e, 0x3d14, 0x0074, 0x019a, 0x077e, 
0x001d, 0x0774, 0x3d11, 0x0074, 0x4001, 0x0000, 0x0701, 0x0000, 
0x3a01, 0x0000, 0x0108, 0x0007, 0x4611, 0x0044, 0x001d, 0x07a0, 
0x65fc, 0x0784, 0x001d, 0x0720, 0x872c, 0x079a, 0x8701, 0x0004, 
0x6c11, 0x0074, 0x6d0f, 0x0798, 0x0802, 0x0001, 0x2714, 0x0008, 
0x049b, 0x0798, 0x0908, 0x0000, 0x4611, 0x0074, 0x0902, 0x0001, 
0x001d, 0x07a0, 0x870c, 0x0718, 0x4e01, 0x0008, 0x001d, 0x06a0, 
0x8a01, 0x000b, 0x7414, 0x0023, 0x049a, 0x07a8, 0x001d, 0x06fe, 
0x8605, 0xfdfb, 0x8701, 0x0004, 0x8b12, 0x0008, 0x270f, 0x07cc, 
0x080e, 0x07c4, 0x4b05, 0xbfff, 0x657c, 0x07b8, 0x001d, 0x07b4, 
0x5a01, 0x0080, 0x3d0f, 0x07be, 0x001d, 0x07dc, 0x2808, 0x0000, 
0x1711, 0x0046, 0x001d, 0x087c, 0x0b11, 0x0009, 0x0911, 0x000a, 
0x0902, 0x0001, 0x001d, 0x07ea, 0x080f, 0x07d2, 0x4b06, 0x4000, 
0x001d, 0x07d4, 0x4b05, 0xbfff, 0x657c, 0x07d8, 0x001d, 0x07d4, 
0x5a01, 0x0080, 0x3d0f, 0x07e8, 0x0611, 0x003d, 0x0011, 0x003d, 
0x0018, 0x0003, 0x0d11, 0x0032, 0x0d12, 0x0000, 0x001d, 0x09fa, 
0x001d, 0x09a4, 0x8a01, 0x000c, 0x870c, 0x07f0, 0x001d, 0x06a0, 
0x080f, 0x0814, 0x2714, 0x000c, 0x040e, 0x0816, 0x0311, 0x0030, 
0x0312, 0x003c, 0x8111, 0x003c, 0x8701, 0x0004, 0x8014, 0x0003, 
0x049b, 0x0814, 0x8606, 0x0004, 0x5a01, 0x0021, 0x6401, 0x0001, 
0x0c02, 0x0001, 0x7411, 0x0006, 0x7011, 0x0006, 0x0111, 0x000d, 
0x003d, 0x10a6, 0x001d, 0x0832, 0x5a01, 0x0080, 0x080f, 0x081c, 
0x4b06, 0x4000, 0x001d, 0x081e, 0x4b05, 0xbfff, 0x3d0f, 0x082c, 
0x0611, 0x003d, 0x0011, 0x003d, 0x0018, 0x0003, 0x0d11, 0x0032, 
0x0d12, 0x0000, 0x001d, 0x09fa, 0x2808, 0x0000, 0x1711, 0x0046, 
0x001d, 0x087c, 0x8a01, 0x000d, 0x651c, 0x086c, 0x658c, 0x0850, 
0x6501, 0x0100, 0x65fc, 0x0840, 0x4e01, 0x0800, 0x6501, 0x8000, 
0x8605, 0xfffb, 0x0108, 0x0003, 0x4311, 0x0046, 0x4319, 0x0002, 
0x4302, 0x0001, 0x4511, 0x0075, 0x003d, 0x0f3a, 0x001d, 0x07ea, 
0x0211, 0x0063, 0x0311, 0x0002, 0x0205, 0x0fff, 0x0319, 0x000c, 
0x027a, 0x083a, 0x8605, 0xfffb, 0x003d, 0x1054, 0x030e, 0x0842, 
0x0011, 0x0009, 0x0003, 0x0001, 0x0008, 0x0000, 0x4611, 0x0044, 
0x0803, 0x0001, 0x001d, 0x07ea, 0x65fc, 0x0870, 0x001d, 0x083c, 
0x872c, 0x0878, 0x8605, 0xfffb, 0x8701, 0x0004, 0x001d, 0x07ea, 
0x870c, 0x0834, 0x001d, 0x06a0, 0x8a01, 0x000e, 0x870c, 0x0882, 
0x001d, 0x06a0, 0x050c, 0x089c, 0x1204, 0x0000, 0x019b, 0x089c, 
0x0011, 0x0017, 0x0003, 0x0001, 0x8111, 0x0000, 0x0012, 0x0030, 
0x8701, 0x0004, 0x8014, 0x0000, 0x049b, 0x089c, 0x8606, 0x0004, 
0x003d, 0x11d4, 0x001d, 0x089e, 0x001d, 0x09a4, 0x8a01, 0x000f, 
0x651c, 0x08c4, 0x658c, 0x08b4, 0x6501, 0x0100, 0x65fc, 0x08ac, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x6401, 0x0080, 0x6501, 0x0800, 
0x6501, 0x007e, 0x001d, 0x08c0, 0x0011, 0x0063, 0x0111, 0x0000, 
0x0005, 0x0fff, 0x0119, 0x000c, 0x0c3a, 0x08d2, 0x003d, 0x127e, 
0x8607, 0x0004, 0x001d, 0x087c, 0x65fc, 0x08c8, 0x001d, 0x08a8, 
0x872c, 0x08ce, 0x8701, 0x0004, 0x001d, 0x08c0, 0x870c, 0x08a0, 
0x001d, 0x06a0, 0x063a, 0x08a6, 0x6104, 0x0002, 0x019a, 0x08a6, 
0x3d0e, 0x08a6, 0x0111, 0x0032, 0x0102, 0x01f8, 0x0211, 0x0000, 
0x003d, 0x1106, 0x030e, 0x08c0, 0x255a, 0x08c0, 0x3d01, 0x003f, 
0x4001, 0x0000, 0x0701, 0x0000, 0x3a01, 0x0000, 0x001d, 0x08c0, 
0x8a01, 0x0012, 0x0d08, 0x0001, 0x0011, 0x0046, 0x0012, 0x0022, 
0x0111, 0x0000, 0x0112, 0x0037, 0x0114, 0x0080, 0x040f, 0x0918, 
0x8606, 0x0004, 0x0d08, 0x0000, 0x3311, 0x0046, 0x8111, 0x0000, 
0x8701, 0x0004, 0x003d, 0x118e, 0x5b8c, 0x0910, 0x001d, 0x090c, 
0x431f, 0x0000, 0x6401, 0x0001, 0x5a01, 0x0021, 0x001d, 0x091a, 
0x001d, 0x09e8, 0x651c, 0x095a, 0x658c, 0x092e, 0x6501, 0x0100, 
0x65fc, 0x0926, 0x4e01, 0x0800, 0x6501, 0x8000, 0x6401, 0x0080, 
0x6501, 0x0800, 0x6501, 0x007e, 0x001d, 0x0954, 0x0211, 0x0063, 
0x0311, 0x0002, 0x0205, 0x0fff, 0x0319, 0x000c, 0x067a, 0x0920, 
0x0111, 0x000d, 0x003d, 0x1106, 0x030e, 0x0926, 0x0204, 0x0027, 
0x040f, 0x094e, 0x3d0e, 0x0954, 0x4001, 0x0000, 0x0701, 0x0000, 
0x3a01, 0x0000, 0x3d01, 0x003f, 0x001d, 0x0954, 0x0301, 0x0050, 
0x0108, 0x0004, 0x4611, 0x0003, 0x8605, 0xfffb, 0x8701, 0x0004, 
0x001d, 0x09e8, 0x65fc, 0x095e, 0x001d, 0x0922, 0x872c, 0x0962, 
0x001d, 0x0954, 0x870c, 0x091a, 0x001d, 0x06a0, 0x8a01, 0x0011, 
0x6401, 0x0001, 0x651c, 0x099c, 0x658c, 0x0980, 0x6501, 0x0100, 
0x65fc, 0x0976, 0x4e01, 0x0800, 0x6501, 0x8000, 0x6401, 0x0080, 
0x6501, 0x0800, 0x6501, 0x007e, 0x6401, 0x0001, 0x001d, 0x09a0, 
0x0011, 0x0063, 0x0111, 0x0000, 0x0005, 0x0fff, 0x0119, 0x000c, 
0x0c3a, 0x0990, 0x003d, 0x148c, 0x6401, 0x0001, 0x001d, 0x09a0, 
0x063a, 0x0970, 0x0111, 0x000d, 0x0211, 0x0000, 0x003d, 0x1106, 
0x030e, 0x09a0, 0x001d, 0x09e8, 0x65fc, 0x09a0, 0x001d, 0x0972, 
0x870c, 0x096a, 0x001d, 0x06a0, 0x8a01, 0x0010, 0x870c, 0x09aa, 
0x001d, 0x06a0, 0x0d11, 0x0032, 0x0d02, 0x01f8, 0x0d08, 0x0000, 
0x0011, 0x0046, 0x021a, 0x09dc, 0x0d08, 0x0004, 0x0011, 0x0046, 
0x501a, 0x09de, 0x051c, 0x09dc, 0x0d08, 0x0005, 0x0111, 0x0046, 
0x0112, 0x0030, 0x0112, 0x0039, 0x8014, 0x0001, 0x049b, 0x09e0, 
0x5501, 0x0002, 0x5601, 0x0001, 0x5701, 0x0000, 0x5801, 0x5000, 
0x5a01, 0x0021, 0x5a0c, 0x09d6, 0x001d, 0x09d2, 0x4101, 0x863f, 
0x023d, 0x0f66, 0x001d, 0x0966, 0x001d, 0x09e8, 0x001d, 0x08f0, 
0x873c, 0x09e4, 0x001d, 0x0966, 0x870c, 0x09e0, 0x001d, 0x06a0, 
0x8a01, 0x0013, 0x6401, 0x0080, 0x6501, 0x0800, 0x6501, 0x007e, 
0x870c, 0x09f4, 0x001d, 0x06a0, 0x871c, 0x09f0, 0x4e01, 0x0008, 
0x001d, 0x06a0, 0x8a01, 0x0014, 0x870c, 0x0a00, 0x001d, 0x06a0, 
0x0d08, 0x0001, 0x0011, 0x0046, 0x0111, 0x0000, 0x0119, 0x0001, 
0x0012, 0x0001, 0x0111, 0x0000, 0x0112, 0x0030, 0x8111, 0x0000, 
0x8701, 0x0004, 0x8014, 0x0001, 0x049b, 0x0a1a, 0x8606, 0x0004, 
0x001d, 0x0a28, 0x4e01, 0x0020, 0x3d01, 0x0000, 0x050c, 0x0a26, 
0x2808, 0x0000, 0x1711, 0x0046, 0x001d, 0x087c, 0x001d, 0x09a4, 
0x8a01, 0x0015, 0x0d08, 0x0004, 0x3411, 0x0046, 0x0d08, 0x0000, 
0x3311, 0x0046, 0x3404, 0x0027, 0x019b, 0x0a52, 0x3a0e, 0x0aa6, 
0x3404, 0x0050, 0x019b, 0x0a72, 0x3101, 0x0000, 0x003d, 0x115e, 
0x5b8c, 0x0a44, 0x001d, 0x0a40, 0x431f, 0x0000, 0x5a01, 0x0021, 
0x5a0c, 0x0a4c, 0x001d, 0x0a48, 0x4101, 0x863f, 0x023d, 0x0f66, 
0x001d, 0x0aa6, 0x4004, 0x0002, 0x049b, 0x0a36, 0x3a0e, 0x0a5c, 
0x003d, 0x11a8, 0x001d, 0x0a5e, 0x003d, 0x118e, 0x5b8c, 0x0a62, 
0x001d, 0x0a5e, 0x431f, 0x0000, 0x6401, 0x0001, 0x5a01, 0x0021, 
0x5a0c, 0x0a6c, 0x001d, 0x0a68, 0x4101, 0x863f, 0x023d, 0x0f66, 
0x001d, 0x0b6a, 0x0d08, 0x0007, 0x3811, 0x0046, 0x3802, 0x0001, 
0x0d08, 0x0007, 0x4611, 0x0038, 0x0211, 0x0006, 0x0212, 0x0038, 
0x6c11, 0x0002, 0x6d01, 0x0001, 0x0111, 0x0002, 0x0118, 0x0003, 
0x0211, 0x0032, 0x0212, 0x0001, 0x0d08, 0x0005, 0x0111, 0x0046, 
0x0208, 0x0005, 0x4611, 0x0001, 0x0d08, 0x0006, 0x0211, 0x0046, 
0x3814, 0x0002, 0x019a, 0x0aa4, 0x0d08, 0x0007, 0x4611, 0x0044, 
0x3d01, 0x0000, 0x3801, 0x0000, 0x001d, 0x09e8, 0x8a01, 0x0016, 
0x6611, 0x0033, 0x4211, 0x0007, 0x8501, 0x0001, 0x003d, 0x1178, 
0x5b8c, 0x0ab4, 0x001d, 0x0ab0, 0x431f, 0x0000, 0x8606, 0x0010, 
0x6401, 0x0001, 0x5a01, 0x0021, 0x5a0c, 0x0ac0, 0x001d, 0x0abc, 
0x4101, 0x863b, 0x023d, 0x0f66, 0x652c, 0x0b06, 0x658c, 0x0acc, 
0x6501, 0x0100, 0x001d, 0x0b1c, 0x0211, 0x0065, 0x0205, 0x0600, 
0x020e, 0x0b22, 0x653c, 0x0b26, 0x0211, 0x0063, 0x0204, 0x4008, 
0x019a, 0x0ae4, 0x6014, 0x0033, 0x040c, 0x0b28, 0x6401, 0x0080, 
0x6501, 0x007e, 0x001d, 0x0b34, 0x3a0f, 0x0b28, 0x0204, 0x6004, 
0x019a, 0x0afe, 0x6114, 0x0033, 0x040c, 0x0afe, 0x0111, 0x000d, 
0x003d, 0x1106, 0x030e, 0x0afa, 0x4001, 0x0000, 0x0701, 0x0000, 
0x3a01, 0x0000, 0x6601, 0x0001, 0x001d, 0x09e8, 0x6401, 0x0080, 
0x6501, 0x0800, 0x6501, 0x007e, 0x001d, 0x0afa, 0x65fc, 0x0b0e, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x001d, 0x0b1c, 0x872c, 0x0b14, 
0x8701, 0x0004, 0x001d, 0x0b1c, 0x870c, 0x0ac4, 0x6601, 0x0001, 
0x3a01, 0x0001, 0x001d, 0x06a0, 0x8607, 0x0004, 0x0211, 0x0065, 
0x0205, 0x0600, 0x4e11, 0x0002, 0x001d, 0x0b28, 0x4e01, 0x0001, 
0x6401, 0x0080, 0x6501, 0x0800, 0x6501, 0x007e, 0x6601, 0x0001, 
0x3a01, 0x0001, 0x001d, 0x09e8, 0x8605, 0xffef, 0x8605, 0xfffb, 
0x8701, 0x0004, 0x0311, 0x0083, 0x0313, 0x003f, 0x0319, 0x0001, 
0x0711, 0x0003, 0x3614, 0x0003, 0x042c, 0x0b48, 0x3611, 0x0003, 
0x0d08, 0x0005, 0x4611, 0x0003, 0x400f, 0x0b5a, 0x3a0e, 0x0b60, 
0x6c11, 0x003d, 0x6d01, 0x0001, 0x4301, 0x0027, 0x0d08, 0x0004, 
0x4611, 0x0043, 0x4002, 0x0001, 0x6601, 0x0001, 0x001d, 0x09e8, 
0x4301, 0x0000, 0x0d08, 0x0004, 0x4611, 0x0043, 0x3d01, 0x0000, 
0x001d, 0x0b5c, 0x8a01, 0x0017, 0x651c, 0x0bb4, 0x658c, 0x0b82, 
0x6501, 0x0100, 0x65fc, 0x0b78, 0x4e01, 0x0800, 0x6501, 0x8000, 
0x6401, 0x0080, 0x6501, 0x0800, 0x6501, 0x007e, 0x3a01, 0x0001, 
0x001d, 0x0bb0, 0x0211, 0x0063, 0x0311, 0x0002, 0x0205, 0x0fff, 
0x0319, 0x000c, 0x067a, 0x0b72, 0x0111, 0x000d, 0x003d, 0x1106, 
0x030e, 0x0bb0, 0x0108, 0x0004, 0x0311, 0x0046, 0x0304, 0x0027, 
0x049a, 0x0b9e, 0x3a01, 0x0001, 0x001d, 0x0bb0, 0x3d04, 0x003f, 
0x019b, 0x0bae, 0x0301, 0x0050, 0x0108, 0x0004, 0x4611, 0x0003, 
0x0d08, 0x0006, 0x0311, 0x0046, 0x030e, 0x0bb0, 0x3d01, 0x0000, 
0x8605, 0xfffb, 0x001d, 0x09e8, 0x65fc, 0x0bb8, 0x001d, 0x0b74, 
0x872c, 0x0bbe, 0x8701, 0x0004, 0x001d, 0x0b72, 0x870c, 0x0b6c, 
0x001d, 0x06a0, 0x4211, 0x006b, 0x4219, 0x0001, 0x4208, 0x0000, 
0x0011, 0x0046, 0x0005, 0x00ff, 0x0004, 0x0001, 0x049b, 0x0cf4, 
0x0004, 0x00ef, 0x040f, 0x0cf4, 0x4208, 0x0002, 0x0011, 0x0046, 
0x0005, 0x00ff, 0x0004, 0x0001, 0x049b, 0x0cf4, 0x0004, 0x00fe, 
0x040f, 0x0cf4, 0x055c, 0x0bec, 0x4208, 0x0004, 0x0011, 0x0046, 
0x0004, 0x000a, 0x049b, 0x0cf4, 0x4208, 0x0005, 0x0011, 0x0046, 
0x057c, 0x0bf6, 0x000e, 0x0cf4, 0x001d, 0x0bfe, 0x0004, 0x0001, 
0x049b, 0x0cf4, 0x0004, 0x003e, 0x040f, 0x0cf4, 0x4208, 0x0006, 
0x0011, 0x0046, 0x4208, 0x0007, 0x0111, 0x0046, 0x003a, 0x0c1c, 
0x055c, 0x0c16, 0x0004, 0x0c34, 0x040e, 0x0cf4, 0x0004, 0xc350, 
0x040f, 0x0cf4, 0x2201, 0x00c8, 0x3901, 0x012c, 0x4001, 0x0110, 
0x3701, 0x01f3, 0x001d, 0x0c46, 0x013a, 0x0c32, 0x055c, 0x0c2c, 
0x0004, 0x1388, 0x040e, 0x0cf4, 0x0004, 0x9c40, 0x040f, 0x0cf4, 
0x2201, 0x0014, 0x3901, 0x001e, 0x4001, 0x001b, 0x3701, 0x0031, 
0x001d, 0x0c46, 0x023a, 0x0cf4, 0x055c, 0x0c42, 0x0004, 0x0fa0, 
0x040e, 0x0cf4, 0x0004, 0xfa00, 0x040f, 0x0cf4, 0x2201, 0x0002, 
0x3901, 0x0003, 0x4001, 0x0003, 0x3701, 0x0004, 0x4208, 0x0008, 
0x0011, 0x0046, 0x0005, 0xfffe, 0x000e, 0x0cf4, 0x4208, 0x0009, 
0x0011, 0x0046, 0x055c, 0x0c5a, 0x0004, 0x003e, 0x040f, 0x0cf4, 
0x001d, 0x0c5c, 0x000e, 0x0cf4, 0x4208, 0x000a, 0x0011, 0x0046, 
0x0004, 0x00d0, 0x049b, 0x0cf4, 0x0004, 0x7b10, 0x040f, 0x0cf4, 
0x4208, 0x000b, 0x0011, 0x0046, 0x0111, 0x0000, 0x0105, 0x0003, 
0x010e, 0x0cf4, 0x0004, 0x3d20, 0x040f, 0x0cf4, 0x4208, 0x000c, 
0x0011, 0x0046, 0x0111, 0x0000, 0x0105, 0x0003, 0x010e, 0x0cf4, 
0x0004, 0x3d20, 0x040f, 0x0cf4, 0x4208, 0x000d, 0x0011, 0x0046, 
0x0111, 0x0000, 0x0105, 0x0003, 0x010e, 0x0cf4, 0x0004, 0x0004, 
0x049b, 0x0cf4, 0x0004, 0x01f4, 0x040f, 0x0cf4, 0x4208, 0x000e, 
0x0011, 0x0046, 0x0004, 0x4000, 0x040f, 0x0cf4, 0x057c, 0x0ca2, 
0x001d, 0x0ca4, 0x058c, 0x0caa, 0x4208, 0x000f, 0x0011, 0x0046, 
0x000e, 0x0cf4, 0x4208, 0x0010, 0x0011, 0x0046, 0x055c, 0x0cc4, 
0x0201, 0x0000, 0x0101, 0x0001, 0x4311, 0x0001, 0x4315, 0x0000, 
0x430e, 0x0cc8, 0x0118, 0x0001, 0x020b, 0x0000, 0x0204, 0x0006, 
0x049b, 0x0cb4, 0x001d, 0x0cf4, 0x000e, 0x0cf4, 0x001d, 0x0ccc, 
0x0014, 0x0001, 0x040c, 0x0cf4, 0x4208, 0x0011, 0x0011, 0x0046, 
0x0004, 0x01c0, 0x049b, 0x0cf4, 0x0004, 0x7c00, 0x040f, 0x0cf4, 
0x4208, 0x0012, 0x0011, 0x0046, 0x0004, 0x001a, 0x040f, 0x0cf4, 
0x4208, 0x0013, 0x0011, 0x0046, 0x0004, 0x0003, 0x040f, 0x0cf4, 
0x4208, 0x0018, 0x0011, 0x0046, 0x0004, 0x1fff, 0x040f, 0x0cf4, 
0x0301, 0x0000, 0x005d, 0x0000, 0x0301, 0x0001, 0x005d, 0x0000, 
0x4211, 0x006b, 0x4219, 0x0001, 0x4208, 0x0000, 0x0011, 0x0046, 
0x6611, 0x0000, 0x4208, 0x0001, 0x0011, 0x0046, 0x6711, 0x0000, 
0x4208, 0x0002, 0x0011, 0x0046, 0x6811, 0x0000, 0x4208, 0x0003, 
0x0011, 0x0046, 0x6911, 0x0000, 0x4208, 0x0005, 0x0011, 0x0046, 
0x057c, 0x0d1e, 0x2301, 0x0001, 0x001d, 0x0d20, 0x2311, 0x0000, 
0x4208, 0x0006, 0x0011, 0x0046, 0x0003, 0x0001, 0x2411, 0x0000, 
0x4208, 0x0007, 0x0011, 0x0046, 0x2511, 0x0000, 0x055c, 0x0d38, 
0x4208, 0x0008, 0x0011, 0x0046, 0x2611, 0x0000, 0x001d, 0x0d3a, 
0x2611, 0x0044, 0x4208, 0x0009, 0x0011, 0x0046, 0x2711, 0x0000, 
0x000e, 0x0d48, 0x055c, 0x0d48, 0x0505, 0xfffe, 0x001d, 0x0d4a, 
0x0506, 0x0001, 0x055c, 0x0d72, 0x4208, 0x000a, 0x0011, 0x0046, 
0x0019, 0x0001, 0x2811, 0x0000, 0x4208, 0x000b, 0x0111, 0x0046, 
0x0119, 0x0001, 0x2a11, 0x0001, 0x4208, 0x000c, 0x0211, 0x0046, 
0x0219, 0x0001, 0x2d11, 0x0002, 0x0012, 0x0001, 0x2911, 0x0000, 
0x0012, 0x0001, 0x2b11, 0x0000, 0x0012, 0x0002, 0x2c11, 0x0000, 
0x001d, 0x0dbe, 0x056c, 0x0d9a, 0x4208, 0x000a, 0x0011, 0x0046, 
0x0019, 0x0001, 0x3c11, 0x0000, 0x4208, 0x000b, 0x0111, 0x0046, 
0x0119, 0x0001, 0x3f11, 0x0001, 0x4208, 0x000c, 0x0211, 0x0046, 
0x0219, 0x0001, 0x2a11, 0x0002, 0x0012, 0x0001, 0x3d11, 0x0000, 
0x0012, 0x0001, 0x2811, 0x0000, 0x0012, 0x0002, 0x2911, 0x0000, 
0x001d, 0x0dbe, 0x4208, 0x000a, 0x0011, 0x0046, 0x0019, 0x0001, 
0x3c11, 0x0000, 0x4208, 0x000b, 0x0111, 0x0046, 0x0119, 0x0001, 
0x3f11, 0x0001, 0x4208, 0x000c, 0x0211, 0x0046, 0x0219, 0x0001, 
0x2d11, 0x0002, 0x0012, 0x0001, 0x3d11, 0x0000, 0x0012, 0x0001, 
0x2b11, 0x0000, 0x0012, 0x0002, 0x2c11, 0x0000, 0x4208, 0x000d, 
0x0011, 0x0046, 0x0019, 0x0001, 0x2e11, 0x0000, 0x4208, 0x000e, 
0x0011, 0x0046, 0x2f11, 0x0000, 0x0004, 0x4000, 0x019b, 0x0dd4, 
0x0506, 0x0004, 0x001d, 0x0dd8, 0x8401, 0x8000, 0x0505, 0xfffb, 
0x4208, 0x000f, 0x0011, 0x0046, 0x055c, 0x0df2, 0x0014, 0x0037, 
0x040e, 0x0de8, 0x0003, 0x0001, 0x3011, 0x0000, 0x001d, 0x0df0, 
0x3011, 0x0037, 0x000e, 0x0df0, 0x0505, 0xfffd, 0x001d, 0x0df2, 
0x0506, 0x0002, 0x4208, 0x0010, 0x3111, 0x0046, 0x4208, 0x0011, 
0x0011, 0x0046, 0x0019, 0x0001, 0x3211, 0x0000, 0x4208, 0x0012, 
0x0011, 0x0046, 0x4208, 0x0013, 0x0111, 0x0046, 0x0018, 0x0004, 
0x0016, 0x0001, 0x5911, 0x0000, 0x4208, 0x0014, 0x0011, 0x0046, 
0x0e11, 0x0000, 0x0e02, 0x0001, 0x4208, 0x0015, 0x3f11, 0x0046, 
0x005d, 0x0000, 0x0601, 0x0000, 0x0001, 0xffff, 0x0301, 0x0000, 
0x0311, 0x0006, 0x0302, 0x0040, 0x7611, 0x0003, 0x7711, 0x0000, 
0x0602, 0x0001, 0x0604, 0x003f, 0x040e, 0x0e20, 0x0601, 0x0001, 
0x0001, 0x0000, 0x0101, 0x0000, 0x0201, 0x0000, 0x3801, 0x0000, 
0x0211, 0x0032, 0x0001, 0x0020, 0x0101, 0x0020, 0x0112, 0x0000, 
0x0202, 0x0008, 0x0208, 0x0002, 0x3a11, 0x0046, 0x3a04, 0x0007, 
0x040e, 0x0f36, 0x0011, 0x003a, 0x3a05, 0x0003, 0x3a0e, 0x0f36, 
0x0002, 0x000c, 0x0112, 0x0000, 0x0208, 0x0003, 0x3b11, 0x0046, 
0x3b04, 0x0007, 0x040e, 0x0f36, 0x0011, 0x003b, 0x3b05, 0x0003, 
0x3b0e, 0x0f36, 0x0002, 0x000c, 0x0112, 0x0000, 0x0602, 0x0001, 
0x0614, 0x0023, 0x040e, 0x0e40, 0x0119, 0x0001, 0x0601, 0x0000, 
0x0001, 0x0000, 0x0201, 0x0000, 0x0301, 0x0000, 0x0211, 0x0032, 
0x0311, 0x0006, 0x0302, 0x0040, 0x7211, 0x0003, 0x7311, 0x0000, 
0x7211, 0x0006, 0x05ac, 0x0e88, 0x7311, 0x0000, 0x001d, 0x0e8a, 
0x7311, 0x0001, 0x060f, 0x0e98, 0x0208, 0x0002, 0x3a11, 0x0046, 
0x0311, 0x003a, 0x0302, 0x000c, 0x0319, 0x0001, 0x001d, 0x0e9c, 
0x0301, 0x0020, 0x0319, 0x0001, 0x0012, 0x0003, 0x0112, 0x0003, 
0x0208, 0x0000, 0x3311, 0x0046, 0x330f, 0x0f36, 0x7711, 0x0033, 
0x0311, 0x0076, 0x0305, 0x8000, 0x030f, 0x0f36, 0x0311, 0x0006, 
0x0302, 0x0040, 0x7611, 0x0003, 0x7711, 0x0033, 0x7611, 0x0006, 
0x0202, 0x0008, 0x0602, 0x0001, 0x0614, 0x0023, 0x040e, 0x0e78, 
0x0601, 0x0000, 0x0201, 0x0000, 0x0301, 0x0000, 0x0211, 0x0032, 
0x0311, 0x0006, 0x0302, 0x0040, 0x7411, 0x0003, 0x7511, 0x0000, 
0x7411, 0x0006, 0x05ac, 0x0ed8, 0x7511, 0x0000, 0x001d, 0x0eda, 
0x7511, 0x0001, 0x060f, 0x0ee8, 0x0208, 0x0003, 0x3b11, 0x0046, 
0x0311, 0x003b, 0x0302, 0x000c, 0x0319, 0x0001, 0x001d, 0x0eec, 
0x0301, 0x0020, 0x0319, 0x0001, 0x0012, 0x0003, 0x0112, 0x0003, 
0x0208, 0x0000, 0x3311, 0x0046, 0x0311, 0x0033, 0x0305, 0xff00, 
0x030f, 0x0f26, 0x0311, 0x0033, 0x0305, 0x00ff, 0x7711, 0x0003, 
0x0311, 0x0076, 0x4211, 0x0003, 0x4205, 0x8000, 0x420e, 0x0f36, 
0x0318, 0x0003, 0x4311, 0x0032, 0x4312, 0x0003, 0x380e, 0x0f2a, 
0x3801, 0x0001, 0x4308, 0x0006, 0x4611, 0x0038, 0x0208, 0x0006, 
0x4611, 0x0043, 0x0202, 0x0008, 0x0602, 0x0001, 0x0614, 0x0023, 
0x040e, 0x0ec8, 0x0301, 0x0000, 0x005d, 0x0000, 0x3801, 0x0000, 
0x001d, 0x0f1a, 0x4308, 0x0006, 0x0311, 0x0046, 0x0302, 0x0001, 
0x4308, 0x0006, 0x4611, 0x0003, 0x001d, 0x0f16, 0x0301, 0x0001, 
0x005d, 0x0000, 0x656c, 0x0f44, 0x4611, 0x005c, 0x4611, 0x005d, 
0x4611, 0x005e, 0x4611, 0x005f, 0x4611, 0x0060, 0x4611, 0x0061, 
0x4611, 0x0062, 0x4611, 0x0063, 0x4811, 0x0043, 0x451e, 0x0000, 
0x657c, 0x0f54, 0x001d, 0x0f50, 0x6401, 0x0080, 0x6501, 0x0800, 
0x6501, 0x007e, 0x005d, 0x0000, 0x052c, 0x0f64, 0x49cc, 0x0f64, 
0x8501, 0x0001, 0x4901, 0x1000, 0x005d, 0x0000, 0x0211, 0x005b, 
0x3511, 0x0002, 0x0215, 0x0041, 0x020e, 0x0f74, 0x0201, 0x0000, 
0x5b01, 0x0080, 0x025d, 0x0000, 0x5bfc, 0x0f7c, 0x4f01, 0x0800, 
0x5b01, 0x8000, 0x0205, 0x063f, 0x4f11, 0x0002, 0x5a01, 0x0080, 
0x5b01, 0x0880, 0x0201, 0x0001, 0x025d, 0x0000, 0x050c, 0x0fc2, 
0x2a0f, 0x0fc2, 0x496c, 0x0f90, 0x1201, 0x0004, 0x001d, 0x0fc2, 
0x1204, 0x0000, 0x019a, 0x0fc2, 0x494c, 0x0fb2, 0x1201, 0x0001, 
0x2808, 0x0005, 0x0011, 0x0046, 0x0005, 0x0fff, 0x0019, 0x0001, 
0x0e11, 0x0000, 0x1611, 0x000e, 0x1511, 0x0028, 0x1502, 0x0006, 
0x1011, 0x0044, 0x1311, 0x0044, 0x1411, 0x0044, 0x2101, 0x0021, 
0x001d, 0x0fc2, 0x495c, 0x0fc2, 0x1201, 0x0002, 0x0f11, 0x0044, 
0x1511, 0x0029, 0x1502, 0x0006, 0x1111, 0x0044, 0x1311, 0x0044, 
0x1411, 0x0044, 0x051c, 0x0ffc, 0x2d0f, 0x0ffc, 0x49ac, 0x0fcc, 
0x1c01, 0x0004, 0x001d, 0x0ffc, 0x1c04, 0x0010, 0x019a, 0x0ffc, 
0x498c, 0x0fec, 0x1c01, 0x0012, 0x2b08, 0x0005, 0x0011, 0x0046, 
0x0005, 0x0fff, 0x0019, 0x0001, 0x1811, 0x0000, 0x2011, 0x0018, 
0x1f11, 0x002b, 0x1f02, 0x0006, 0x1a11, 0x0044, 0x1d11, 0x0044, 
0x1e11, 0x0044, 0x001d, 0x0ffc, 0x499c, 0x0ffc, 0x1c01, 0x0011, 
0x1911, 0x0044, 0x1f11, 0x002c, 0x1f02, 0x0006, 0x1b11, 0x0044, 
0x1d11, 0x0044, 0x1e11, 0x0044, 0x005d, 0x0000, 0x0614, 0x0023, 
0x040f, 0x103c, 0x0301, 0x0000, 0x0d08, 0x0000, 0x3311, 0x0046, 
0x0d08, 0x0001, 0x3c11, 0x0046, 0x7211, 0x0006, 0x5a0c, 0x1012, 
0x001d, 0x100e, 0x8111, 0x003c, 0x8701, 0x0004, 0x4101, 0x863f, 
0x023d, 0x0f66, 0x4511, 0x0073, 0x5511, 0x0046, 0x5611, 0x0046, 
0x5711, 0x0046, 0x0211, 0x0046, 0x5811, 0x0002, 0x0205, 0x0fff, 
0x0219, 0x0002, 0x4711, 0x0002, 0x657c, 0x1030, 0x001d, 0x102c, 
0x451f, 0x0000, 0x030e, 0x1038, 0x5a01, 0x0005, 0x005d, 0x0000, 
0x5a05, 0xfffa, 0x005d, 0x0000, 0x0301, 0x0001, 0x080f, 0x104e, 
0x0a08, 0x0000, 0x0211, 0x0046, 0x0611, 0x0002, 0x0218, 0x0003, 
0x0d11, 0x0032, 0x0d12, 0x0002, 0x001d, 0x1004, 0x0603, 0x0001, 
0x0d03, 0x0008, 0x001d, 0x1004, 0x0108, 0x0000, 0x3311, 0x0046, 
0x3314, 0x0061, 0x019a, 0x1096, 0x0108, 0x0003, 0x3b11, 0x0046, 
0x0214, 0x003b, 0x019a, 0x1094, 0x0219, 0x0002, 0x0202, 0x0001, 
0x4811, 0x0002, 0x4511, 0x0075, 0x4611, 0x0060, 0x4611, 0x0061, 
0x4611, 0x0062, 0x4611, 0x0063, 0x652c, 0x108c, 0x4311, 0x0065, 
0x4305, 0x0600, 0x430e, 0x10a0, 0x653c, 0x1090, 0x5b8c, 0x1082, 
0x001d, 0x107e, 0x451e, 0x0000, 0x7101, 0x0001, 0x0301, 0x0000, 
0x6501, 0x007e, 0x005d, 0x0000, 0x65fc, 0x1074, 0x001d, 0x1096, 
0x4e01, 0x0001, 0x001d, 0x10a0, 0x4e01, 0x0100, 0x4311, 0x0065, 
0x4305, 0x0600, 0x65fc, 0x10a0, 0x4e01, 0x0800, 0x6501, 0x8000, 
0x4e11, 0x0043, 0x0301, 0x0001, 0x005d, 0x0000, 0x2714, 0x000c, 
0x040e, 0x10fc, 0x0914, 0x000b, 0x049b, 0x10b0, 0x0911, 0x000a, 
0x4511, 0x0009, 0x0211, 0x0009, 0x0611, 0x0046, 0x060f, 0x10bc, 
0x0911, 0x0045, 0x001d, 0x10c8, 0x4514, 0x000b, 0x049b, 0x10c2, 
0x0911, 0x000a, 0x4514, 0x0002, 0x019a, 0x10b4, 0x005d, 0x0000, 
0x0211, 0x0006, 0x0218, 0x0003, 0x0d11, 0x0032, 0x0d12, 0x0002, 
0x0d08, 0x0000, 0x3311, 0x0046, 0x0d08, 0x0001, 0x3c11, 0x0046, 
0x7211, 0x0006, 0x5a0c, 0x10de, 0x001d, 0x10da, 0x4101, 0x863f, 
0x023d, 0x0f66, 0x4511, 0x0073, 0x5511, 0x0046, 0x5611, 0x0046, 
0x5711, 0x0046, 0x0311, 0x0046, 0x5811, 0x0003, 0x0305, 0x0fff, 
0x0319, 0x0002, 0x4711, 0x0003, 0x5b8c, 0x10f8, 0x001d, 0x10f4, 
0x451f, 0x0000, 0x005d, 0x0000, 0x5a0c, 0x1100, 0x001d, 0x10fc, 
0x4101, 0x863f, 0x023d, 0x0f66, 0x005d, 0x0000, 0x652c, 0x1140, 
0x0108, 0x0000, 0x3311, 0x0046, 0x6114, 0x0033, 0x040c, 0x114a, 
0x045a, 0x1148, 0x0311, 0x006b, 0x0319, 0x0001, 0x0302, 0x0062, 
0x0219, 0x0002, 0x0202, 0x0001, 0x4811, 0x0002, 0x657c, 0x1122, 
0x001d, 0x111e, 0x031e, 0x0000, 0x4311, 0x0065, 0x4305, 0x0600, 
0x430e, 0x1152, 0x653c, 0x1150, 0x6501, 0x007e, 0x0211, 0x0061, 
0x0205, 0xff00, 0x020e, 0x113c, 0x0308, 0x0000, 0x0211, 0x0046, 
0x0108, 0x0004, 0x4611, 0x0002, 0x0301, 0x0000, 0x005d, 0x0000, 
0x65fc, 0x1106, 0x4e01, 0x0800, 0x6501, 0x8000, 0x001d, 0x114a, 
0x4e01, 0x0100, 0x4311, 0x0065, 0x4305, 0x0600, 0x001d, 0x1152, 
0x4e01, 0x0001, 0x4e11, 0x0043, 0x6401, 0x0080, 0x6501, 0x0800, 
0x6501, 0x007e, 0x0301, 0x0001, 0x001d, 0x113e, 0x4311, 0x006b, 
0x4319, 0x0001, 0x4302, 0x0058, 0x4308, 0x0000, 0x4611, 0x0031, 
0x4308, 0x0001, 0x4611, 0x0044, 0x4701, 0x0001, 0x5511, 0x0033, 
0x5601, 0x0001, 0x5701, 0x0000, 0x5801, 0x3004, 0x005d, 0x0000, 
0x4311, 0x006b, 0x4319, 0x0001, 0x4302, 0x005c, 0x4308, 0x0002, 
0x4611, 0x0042, 0x4701, 0x0002, 0x5511, 0x0033, 0x5601, 0x0001, 
0x5701, 0x0000, 0x5801, 0x4008, 0x005d, 0x0000, 0x4311, 0x006b, 
0x4319, 0x0001, 0x4302, 0x0062, 0x4308, 0x0000, 0x4611, 0x0044, 
0x4308, 0x0001, 0x4611, 0x0044, 0x4701, 0x0001, 0x5511, 0x0033, 
0x5601, 0x0001, 0x5701, 0x0000, 0x5801, 0x6004, 0x005d, 0x0000, 
0x4311, 0x006b, 0x4319, 0x0001, 0x4308, 0x000f, 0x4211, 0x0046, 
0x4302, 0x0066, 0x4308, 0x0000, 0x4611, 0x0024, 0x4308, 0x0001, 
0x4611, 0x0042, 0x4308, 0x0002, 0x4611, 0x0036, 0x4211, 0x0025, 
0x4218, 0x0008, 0x4216, 0x0026, 0x4308, 0x0003, 0x4611, 0x0042, 
0x4701, 0x0002, 0x5511, 0x0033, 0x5601, 0x0001, 0x5701, 0x0000, 
0x5801, 0x7008, 0x005d, 0x0000, 0x2808, 0x0002, 0x5511, 0x0046, 
0x2808, 0x0003, 0x5611, 0x0046, 0x0311, 0x0012, 0x017a, 0x1268, 
0x0011, 0x002a, 0x0003, 0x0006, 0x0014, 0x000e, 0x049b, 0x125c, 
0x0011, 0x002e, 0x0018, 0x0007, 0x0013, 0x002e, 0x0014, 0x000e, 
0x049a, 0x120a, 0x1201, 0x0000, 0x0001, 0x8007, 0x2808, 0x0001, 
0x4611, 0x0000, 0x055c, 0x1204, 0x2101, 0x0021, 0x4901, 0x0010, 
0x4c01, 0x0010, 0x001d, 0x1208, 0x4901, 0x0100, 0x4c01, 0x0100, 
0x005d, 0x0000, 0x0011, 0x0010, 0x0018, 0x0008, 0x0016, 0x0011, 
0x2e14, 0x000e, 0x042c, 0x1224, 0x1614, 0x002e, 0x040f, 0x1238, 
0x1301, 0x0001, 0x0006, 0x0080, 0x5711, 0x0000, 0x0011, 0x0016, 
0x0018, 0x0001, 0x001d, 0x123e, 0x2104, 0x0023, 0x019b, 0x122c, 
0x2101, 0x0022, 0x001d, 0x126c, 0x1301, 0x0001, 0x0006, 0x0080, 
0x5711, 0x0000, 0x0011, 0x000e, 0x0018, 0x0001, 0x001d, 0x123e, 
0x5711, 0x0000, 0x0011, 0x002e, 0x0018, 0x0001, 0x4311, 0x0000, 
0x4306, 0xc000, 0x5811, 0x0043, 0x0019, 0x0002, 0x4711, 0x0000, 
0x5b8c, 0x124c, 0x001d, 0x1248, 0x151f, 0x0000, 0x6401, 0x0001, 
0x5a01, 0x0021, 0x5a0c, 0x1256, 0x001d, 0x1252, 0x4101, 0x863f, 
0x023d, 0x0f66, 0x005d, 0x0000, 0x0001, 0x8003, 0x2808, 0x0001, 
0x4611, 0x0000, 0x1201, 0x0004, 0x5701, 0x9080, 0x001d, 0x1272, 
0x027b, 0x126c, 0x037a, 0x1276, 0x0011, 0x0011, 0x0006, 0x8080, 
0x5711, 0x0000, 0x5801, 0xc000, 0x001d, 0x124e, 0x047a, 0x127c, 
0x5701, 0x9080, 0x001d, 0x1272, 0x005d, 0x0000, 0x2808, 0x0002, 
0x0111, 0x0046, 0x0114, 0x0061, 0x019a, 0x1326, 0x0311, 0x0012, 
0x027a, 0x1334, 0x0111, 0x0062, 0x0211, 0x0001, 0x0205, 0x8000, 
0x020e, 0x12e8, 0x0211, 0x0001, 0x0219, 0x0008, 0x0214, 0x0011, 
0x019a, 0x1326, 0x0019, 0x0002, 0x4811, 0x0000, 0x0018, 0x0001, 
0x0311, 0x0000, 0x0211, 0x000f, 0x0212, 0x0000, 0x0011, 0x002a, 
0x0003, 0x0006, 0x0014, 0x0002, 0x049b, 0x1310, 0x0105, 0x0080, 
0x010f, 0x12bc, 0x1401, 0x0001, 0x0218, 0x0001, 0x0206, 0xc000, 
0x4511, 0x0029, 0x4502, 0x0002, 0x652c, 0x131a, 0x4311, 0x0065, 
0x4305, 0x0600, 0x430e, 0x132a, 0x653c, 0x1322, 0x151e, 0x0000, 
0x0f12, 0x0003, 0x140f, 0x12da, 0x4611, 0x0060, 0x4611, 0x0061, 
0x4611, 0x0062, 0x4611, 0x0002, 0x1201, 0x0003, 0x1102, 0x0001, 
0x001d, 0x12de, 0x1512, 0x0003, 0x1102, 0x0001, 0x657c, 0x12e2, 
0x001d, 0x12de, 0x6401, 0x0080, 0x6501, 0x007e, 0x005d, 0x0000, 
0x0104, 0x9080, 0x019a, 0x1306, 0x1101, 0x0000, 0x1001, 0x0000, 
0x0201, 0x8002, 0x2908, 0x0001, 0x4611, 0x0002, 0x1201, 0x0000, 
0x055c, 0x1300, 0x4901, 0x0020, 0x4c01, 0x0020, 0x001d, 0x1326, 
0x4901, 0x0200, 0x4c01, 0x0200, 0x001d, 0x1326, 0x0105, 0xa080, 
0x0104, 0xa080, 0x019a, 0x1326, 0x0201, 0x8006, 0x001d, 0x12f2, 
0x0001, 0x8004, 0x2908, 0x0001, 0x4611, 0x0000, 0x1201, 0x0004, 
0x001d, 0x1326, 0x65fc, 0x12bc, 0x4e01, 0x0800, 0x6501, 0x8000, 
0x001d, 0x1326, 0x4e01, 0x0001, 0x001d, 0x132a, 0x4311, 0x0065, 
0x4305, 0x0600, 0x4e11, 0x0043, 0x6401, 0x0080, 0x6501, 0x0800, 
0x1401, 0x0000, 0x001d, 0x12de, 0x017a, 0x13c0, 0x0111, 0x0062, 
0x0105, 0x8000, 0x010f, 0x1326, 0x652c, 0x13b8, 0x4311, 0x0065, 
0x4305, 0x0600, 0x430e, 0x132a, 0x653c, 0x1322, 0x6204, 0x9080, 
0x019a, 0x136a, 0x1101, 0x0000, 0x1001, 0x0000, 0x0201, 0x8001, 
0x2808, 0x0001, 0x4611, 0x0002, 0x1201, 0x0000, 0x055c, 0x1360, 
0x2101, 0x0021, 0x4901, 0x0010, 0x4c01, 0x0010, 0x001d, 0x1364, 
0x4901, 0x0100, 0x4c01, 0x0100, 0x6401, 0x0080, 0x6501, 0x007e, 
0x005d, 0x0000, 0x0011, 0x0062, 0x0005, 0x007f, 0x0111, 0x0010, 
0x0102, 0x0001, 0x0211, 0x0062, 0x0205, 0x7000, 0x020e, 0x13a6, 
0x2104, 0x0022, 0x019a, 0x1382, 0x000e, 0x12e2, 0x2101, 0x0023, 
0x001d, 0x12e2, 0x0014, 0x0001, 0x019a, 0x12e2, 0x1011, 0x0000, 
0x130f, 0x13a2, 0x0001, 0x0000, 0x1201, 0x0000, 0x2808, 0x0001, 
0x4611, 0x0000, 0x055c, 0x139c, 0x2101, 0x0021, 0x4901, 0x0010, 
0x4c01, 0x0010, 0x001d, 0x13a0, 0x4901, 0x0100, 0x4c01, 0x0100, 
0x001d, 0x12e2, 0x1613, 0x002e, 0x1512, 0x002e, 0x0204, 0x2000, 
0x019a, 0x1326, 0x130f, 0x13b4, 0x0014, 0x0001, 0x019a, 0x13b4, 
0x1011, 0x0000, 0x001d, 0x138a, 0x0001, 0x8005, 0x001d, 0x138c, 
0x65fc, 0x133c, 0x4e01, 0x0800, 0x6501, 0x8000, 0x001d, 0x1326, 
0x047a, 0x1450, 0x0211, 0x0062, 0x0205, 0xf000, 0x0204, 0xa000, 
0x019b, 0x13d0, 0x0204, 0x9000, 0x019b, 0x13d0, 0x001d, 0x1326, 
0x652c, 0x1448, 0x4311, 0x0065, 0x4305, 0x0600, 0x430e, 0x132a, 
0x653c, 0x1322, 0x1201, 0x0000, 0x1001, 0x0000, 0x1101, 0x0000, 
0x055c, 0x1414, 0x494c, 0x13f8, 0x2808, 0x0001, 0x0011, 0x0046, 
0x0004, 0x8003, 0x019b, 0x13f2, 0x0001, 0x8001, 0x2808, 0x0001, 
0x4611, 0x0000, 0x2101, 0x0021, 0x4901, 0x0010, 0x4c01, 0x0010, 
0x495c, 0x140c, 0x2908, 0x0001, 0x0011, 0x0046, 0x0004, 0x8004, 
0x019b, 0x1408, 0x0001, 0x8002, 0x2908, 0x0001, 0x4611, 0x0000, 
0x4901, 0x0020, 0x4c01, 0x0020, 0x496c, 0x1442, 0x4901, 0x0040, 
0x4c01, 0x0040, 0x001d, 0x1442, 0x498c, 0x1428, 0x2808, 0x0001, 
0x0011, 0x0046, 0x0004, 0x8003, 0x019b, 0x1424, 0x0001, 0x8001, 
0x2808, 0x0001, 0x4611, 0x0000, 0x4901, 0x0100, 0x4c01, 0x0100, 
0x499c, 0x143c, 0x2908, 0x0001, 0x0011, 0x0046, 0x0004, 0x8004, 
0x019b, 0x1438, 0x0001, 0x8002, 0x2908, 0x0001, 0x4611, 0x0000, 
0x4901, 0x0200, 0x4c01, 0x0200, 0x49ac, 0x1442, 0x4901, 0x0400, 
0x4c01, 0x0400, 0x6401, 0x0080, 0x6501, 0x007e, 0x005d, 0x0000, 
0x65fc, 0x13d0, 0x4e01, 0x0800, 0x6501, 0x8000, 0x001d, 0x1326, 
0x037a, 0x1326, 0x652c, 0x1484, 0x4311, 0x0065, 0x4305, 0x0600, 
0x430e, 0x132a, 0x653c, 0x1322, 0x0211, 0x0062, 0x0205, 0xf000, 
0x0204, 0xa000, 0x019b, 0x146e, 0x0204, 0x8000, 0x019b, 0x146e, 
0x0204, 0x9000, 0x019b, 0x12ec, 0x001d, 0x1326, 0x0001, 0x0000, 
0x2908, 0x0001, 0x4611, 0x0000, 0x1201, 0x0000, 0x055c, 0x147e, 
0x4901, 0x0020, 0x4c01, 0x0020, 0x001d, 0x12e2, 0x4901, 0x0200, 
0x4c01, 0x0200, 0x001d, 0x12e2, 0x65fc, 0x1452, 0x4e01, 0x0800, 
0x6501, 0x8000, 0x001d, 0x1326, 0x2b08, 0x0002, 0x5511, 0x0046, 
0x2b08, 0x0003, 0x5611, 0x0046, 0x5801, 0xc000, 0x0311, 0x001c, 
0x117a, 0x159a, 0x0111, 0x0062, 0x0211, 0x0001, 0x0205, 0x8000, 
0x020e, 0x1560, 0x0211, 0x0001, 0x0219, 0x0008, 0x0214, 0x001b, 
0x019a, 0x151e, 0x0019, 0x0002, 0x4811, 0x0000, 0x0018, 0x0001, 
0x0311, 0x0000, 0x0211, 0x0019, 0x0212, 0x0000, 0x0011, 0x002d, 
0x0003, 0x0006, 0x0014, 0x0002, 0x049b, 0x153e, 0x0011, 0x001b, 
0x0002, 0x0001, 0x0105, 0x0080, 0x010f, 0x14ce, 0x0006, 0xa080, 
0x5711, 0x0000, 0x1d01, 0x0001, 0x001d, 0x14d2, 0x0006, 0x8080, 
0x5711, 0x0000, 0x652c, 0x1546, 0x0111, 0x0065, 0x0105, 0x0600, 
0x010e, 0x1556, 0x653c, 0x154e, 0x1b02, 0x0001, 0x1912, 0x0003, 
0x5511, 0x0061, 0x5611, 0x0060, 0x5a01, 0x0021, 0x1f1e, 0x0000, 
0x1d0f, 0x1504, 0x0011, 0x0019, 0x0018, 0x0001, 0x0006, 0xc000, 
0x4511, 0x002c, 0x4502, 0x0002, 0x4611, 0x0060, 0x4611, 0x0061, 
0x4611, 0x0062, 0x4611, 0x0000, 0x0001, 0x0000, 0x2c08, 0x0001, 
0x4611, 0x0000, 0x1c01, 0x0010, 0x657c, 0x1508, 0x001d, 0x1504, 
0x1d0f, 0x150e, 0x4901, 0x0200, 0x4c01, 0x0200, 0x1f12, 0x0003, 
0x5a0c, 0x1514, 0x001d, 0x1510, 0x4101, 0x863f, 0x023d, 0x0f66, 
0x6401, 0x0080, 0x6501, 0x007e, 0x005d, 0x0000, 0x652c, 0x1522, 
0x001d, 0x1526, 0x65fc, 0x151e, 0x001d, 0x1548, 0x0111, 0x0065, 
0x0105, 0x0600, 0x010e, 0x1556, 0x653c, 0x154e, 0x6401, 0x0080, 
0x0011, 0x001b, 0x0006, 0x8080, 0x5511, 0x0061, 0x5611, 0x0060, 
0x5711, 0x0000, 0x5a01, 0x0021, 0x001d, 0x1510, 0x0001, 0x8004, 
0x2c08, 0x0001, 0x4611, 0x0000, 0x001d, 0x168a, 0x65fc, 0x14d2, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x001d, 0x1552, 0x4e01, 0x0001, 
0x001d, 0x1556, 0x0111, 0x0065, 0x0105, 0x0600, 0x4e11, 0x0001, 
0x1d01, 0x0000, 0x6401, 0x0080, 0x6501, 0x0800, 0x001d, 0x1518, 
0x0104, 0x9080, 0x019a, 0x151e, 0x1b01, 0x0000, 0x1a01, 0x0000, 
0x0001, 0x8002, 0x2c08, 0x0001, 0x4611, 0x0000, 0x4901, 0x0200, 
0x4c01, 0x0200, 0x1c01, 0x0010, 0x652c, 0x1578, 0x001d, 0x157c, 
0x65fc, 0x1574, 0x001d, 0x1548, 0x0111, 0x0065, 0x0105, 0x0600, 
0x010e, 0x1556, 0x653c, 0x154e, 0x6401, 0x0080, 0x0011, 0x001b, 
0x0006, 0xa080, 0x0311, 0x001c, 0x107a, 0x1590, 0x0001, 0xa080, 
0x5511, 0x0061, 0x5611, 0x0060, 0x5711, 0x0000, 0x5a01, 0x0021, 
0x001d, 0x1510, 0x127a, 0x1684, 0x0311, 0x0062, 0x0211, 0x0003, 
0x0205, 0x8000, 0x020f, 0x151e, 0x0211, 0x0003, 0x0205, 0x7000, 
0x020e, 0x165e, 0x0305, 0x007f, 0x652c, 0x1674, 0x0111, 0x0065, 
0x0105, 0x0600, 0x010e, 0x1556, 0x653c, 0x154e, 0x0011, 0x002d, 
0x0003, 0x0006, 0x0014, 0x0018, 0x049b, 0x167c, 0x0011, 0x002e, 
0x0018, 0x0007, 0x0013, 0x002e, 0x0014, 0x0018, 0x049a, 0x15d6, 
0x1c01, 0x0010, 0x0001, 0x8007, 0x2b08, 0x0001, 0x4611, 0x0000, 
0x4901, 0x0100, 0x4c01, 0x0100, 0x001d, 0x1552, 0x0011, 0x001a, 
0x0018, 0x0008, 0x0016, 0x001b, 0x2e14, 0x0018, 0x042c, 0x15f0, 
0x2014, 0x002e, 0x040f, 0x15fc, 0x4201, 0x0001, 0x0006, 0x0080, 
0x5711, 0x0000, 0x0011, 0x0020, 0x0018, 0x0001, 0x001d, 0x1604, 
0x4201, 0x0001, 0x0006, 0x0080, 0x5711, 0x0000, 0x0011, 0x0018, 
0x0018, 0x0001, 0x001d, 0x1604, 0x4201, 0x0000, 0x5711, 0x0000, 
0x0011, 0x002e, 0x0018, 0x0001, 0x4311, 0x0000, 0x4306, 0xc000, 
0x5811, 0x0043, 0x0019, 0x0002, 0x4711, 0x0000, 0x0314, 0x001a, 
0x019a, 0x1630, 0x030f, 0x162a, 0x1e0f, 0x1626, 0x1c01, 0x0010, 
0x0001, 0x0000, 0x2b08, 0x0001, 0x4611, 0x0000, 0x4901, 0x0100, 
0x4c01, 0x0100, 0x5801, 0xc000, 0x001d, 0x1584, 0x030f, 0x162a, 
0x1f12, 0x002e, 0x1a02, 0x0001, 0x0301, 0x0001, 0x001d, 0x1642, 
0x0111, 0x001a, 0x0103, 0x0001, 0x0118, 0x0008, 0x0116, 0x001b, 
0x1e0f, 0x163c, 0x0106, 0x0080, 0x5711, 0x0001, 0x4201, 0x0000, 
0x0301, 0x0000, 0x5b8c, 0x1646, 0x001d, 0x1642, 0x1f1f, 0x0000, 
0x5a01, 0x0021, 0x5a0c, 0x164e, 0x001d, 0x164a, 0x4101, 0x863f, 
0x023d, 0x0f66, 0x420f, 0x1658, 0x1e01, 0x0001, 0x001d, 0x1518, 
0x030f, 0x1518, 0x2013, 0x002e, 0x001d, 0x1518, 0x0304, 0x9080, 
0x019a, 0x151e, 0x1a01, 0x0000, 0x1b01, 0x0000, 0x0001, 0x8001, 
0x2b08, 0x0001, 0x4611, 0x0000, 0x1c01, 0x0010, 0x4901, 0x0100, 
0x4c01, 0x0100, 0x001d, 0x1574, 0x65fc, 0x15ac, 0x4e01, 0x0800, 
0x6501, 0x8000, 0x001d, 0x1552, 0x0001, 0x8003, 0x2b08, 0x0001, 
0x4611, 0x0000, 0x001d, 0x168a, 0x047a, 0x1574, 0x4901, 0x0400, 
0x4c01, 0x0400, 0x652c, 0x168e, 0x001d, 0x169a, 0x65fc, 0x168a, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x0111, 0x0065, 0x0105, 0x0600, 
0x001d, 0x16a8, 0x0111, 0x0065, 0x0105, 0x0600, 0x010e, 0x16a8, 
0x653c, 0x16a6, 0x6401, 0x0080, 0x001d, 0x16ac, 0x4e01, 0x0001, 
0x4e11, 0x0001, 0x6401, 0x0080, 0x5511, 0x0061, 0x5611, 0x0060, 
0x5701, 0x9080, 0x5a01, 0x0021, 0x1a01, 0x0000, 0x1b01, 0x0000, 
0x1c01, 0x0010, 0x498c, 0x16ce, 0x2b08, 0x0001, 0x0011, 0x0046, 
0x0004, 0x8003, 0x019b, 0x16ca, 0x0001, 0x8001, 0x2b08, 0x0001, 
0x4611, 0x0000, 0x4901, 0x0100, 0x4c01, 0x0100, 0x499c, 0x16e2, 
0x2c08, 0x0001, 0x0011, 0x0046, 0x0004, 0x8004, 0x019b, 0x16de, 
0x0001, 0x8002, 0x2c08, 0x0001, 0x4611, 0x0000, 0x4901, 0x0200, 
0x4c01, 0x0200, 0x001d, 0x1510, 0x3c08, 0x0002, 0x5511, 0x0046, 
0x3c08, 0x0003, 0x5611, 0x0046, 0x5801, 0xc000, 0x0311, 0x0026, 
0x117a, 0x17f2, 0x0111, 0x0062, 0x0211, 0x0001, 0x0205, 0x8000, 
0x020e, 0x17b8, 0x0211, 0x0001, 0x0219, 0x0008, 0x0214, 0x0025, 
0x019a, 0x1776, 0x0019, 0x0002, 0x4811, 0x0000, 0x0018, 0x0001, 
0x0311, 0x0000, 0x0211, 0x0023, 0x0212, 0x0000, 0x0011, 0x003f, 
0x0003, 0x0006, 0x0014, 0x0002, 0x049b, 0x1796, 0x0011, 0x0025, 
0x0002, 0x0001, 0x0105, 0x0080, 0x010f, 0x1726, 0x0006, 0xa080, 
0x5711, 0x0000, 0x2701, 0x0001, 0x001d, 0x172a, 0x0006, 0x8080, 
0x5711, 0x0000, 0x652c, 0x179e, 0x0111, 0x0065, 0x0105, 0x0600, 
0x010e, 0x17ae, 0x653c, 0x17a6, 0x2502, 0x0001, 0x2312, 0x0003, 
0x5511, 0x0061, 0x5611, 0x0060, 0x5a01, 0x0021, 0x391e, 0x0000, 
0x270f, 0x175c, 0x0011, 0x0023, 0x0018, 0x0001, 0x0006, 0xc000, 
0x4511, 0x003d, 0x4502, 0x0002, 0x4611, 0x0060, 0x4611, 0x0061, 
0x4611, 0x0062, 0x4611, 0x0000, 0x0001, 0x0000, 0x3d08, 0x0001, 
0x4611, 0x0000, 0x2601, 0x0010, 0x657c, 0x1760, 0x001d, 0x175c, 
0x270f, 0x1766, 0x4901, 0x0020, 0x4c01, 0x0020, 0x3912, 0x0003, 
0x5a0c, 0x176c, 0x001d, 0x1768, 0x4101, 0x863f, 0x023d, 0x0f66, 
0x6401, 0x0080, 0x6501, 0x007e, 0x005d, 0x0000, 0x652c, 0x177a, 
0x001d, 0x177e, 0x65fc, 0x1776, 0x001d, 0x17a0, 0x0111, 0x0065, 
0x0105, 0x0600, 0x010e, 0x17ae, 0x653c, 0x17a6, 0x6401, 0x0080, 
0x0011, 0x0025, 0x0006, 0x8080, 0x5511, 0x0061, 0x5611, 0x0060, 
0x5711, 0x0000, 0x5a01, 0x0021, 0x001d, 0x1768, 0x0001, 0x8004, 
0x3d08, 0x0001, 0x4611, 0x0000, 0x001d, 0x18e2, 0x65fc, 0x172a, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x001d, 0x17aa, 0x4e01, 0x0001, 
0x001d, 0x17ae, 0x0111, 0x0065, 0x0105, 0x0600, 0x4e11, 0x0001, 
0x2701, 0x0000, 0x6401, 0x0080, 0x6501, 0x0800, 0x001d, 0x1770, 
0x0104, 0x9080, 0x019a, 0x1776, 0x2501, 0x0000, 0x2401, 0x0000, 
0x0001, 0x8002, 0x3d08, 0x0001, 0x4611, 0x0000, 0x4901, 0x0020, 
0x4c01, 0x0020, 0x2601, 0x0010, 0x652c, 0x17d0, 0x001d, 0x17d4, 
0x65fc, 0x17cc, 0x001d, 0x17a0, 0x0111, 0x0065, 0x0105, 0x0600, 
0x010e, 0x17ae, 0x653c, 0x17a6, 0x6401, 0x0080, 0x0011, 0x0025, 
0x0006, 0xa080, 0x0311, 0x001c, 0x107a, 0x17e8, 0x0001, 0xa080, 
0x5511, 0x0061, 0x5611, 0x0060, 0x5711, 0x0000, 0x5a01, 0x0021, 
0x001d, 0x1768, 0x127a, 0x18dc, 0x0311, 0x0062, 0x0211, 0x0003, 
0x0205, 0x8000, 0x020f, 0x1776, 0x0211, 0x0003, 0x0205, 0x7000, 
0x020e, 0x18b6, 0x0305, 0x007f, 0x652c, 0x18cc, 0x0111, 0x0065, 
0x0105, 0x0600, 0x010e, 0x17ae, 0x653c, 0x17a6, 0x0011, 0x003f, 
0x0003, 0x0006, 0x0014, 0x0022, 0x049b, 0x18d4, 0x0011, 0x002e, 
0x0018, 0x0007, 0x0013, 0x002e, 0x0014, 0x0022, 0x049a, 0x182e, 
0x2601, 0x0010, 0x0001, 0x8007, 0x3c08, 0x0001, 0x4611, 0x0000, 
0x4901, 0x0010, 0x4c01, 0x0010, 0x001d, 0x17aa, 0x0011, 0x0024, 
0x0018, 0x0008, 0x0016, 0x0025, 0x2e14, 0x0022, 0x042c, 0x1848, 
0x3a14, 0x002e, 0x040f, 0x1854, 0x4201, 0x0001, 0x0006, 0x0080, 
0x5711, 0x0000, 0x0011, 0x003a, 0x0018, 0x0001, 0x001d, 0x185c, 
0x4201, 0x0001, 0x0006, 0x0080, 0x5711, 0x0000, 0x0011, 0x0022, 
0x0018, 0x0001, 0x001d, 0x185c, 0x4201, 0x0000, 0x5711, 0x0000, 
0x0011, 0x002e, 0x0018, 0x0001, 0x4311, 0x0000, 0x4306, 0xc000, 
0x5811, 0x0043, 0x0019, 0x0002, 0x4711, 0x0000, 0x0314, 0x0024, 
0x019a, 0x1888, 0x030f, 0x1882, 0x380f, 0x187e, 0x2601, 0x0010, 
0x0001, 0x0000, 0x3c08, 0x0001, 0x4611, 0x0000, 0x4901, 0x0010, 
0x4c01, 0x0010, 0x5801, 0xc000, 0x001d, 0x17dc, 0x030f, 0x1882, 
0x3912, 0x002e, 0x2402, 0x0001, 0x0301, 0x0001, 0x001d, 0x189a, 
0x0111, 0x0024, 0x0103, 0x0001, 0x0118, 0x0008, 0x0116, 0x0025, 
0x380f, 0x1894, 0x0106, 0x0080, 0x5711, 0x0001, 0x4201, 0x0000, 
0x0301, 0x0000, 0x5b8c, 0x189e, 0x001d, 0x189a, 0x391f, 0x0000, 
0x5a01, 0x0021, 0x5a0c, 0x18a6, 0x001d, 0x18a2, 0x4101, 0x863f, 
0x023d, 0x0f66, 0x420f, 0x18b0, 0x3801, 0x0001, 0x001d, 0x1770, 
0x030f, 0x1770, 0x3a13, 0x002e, 0x001d, 0x1770, 0x0304, 0x9080, 
0x019a, 0x1776, 0x2401, 0x0000, 0x2501, 0x0000, 0x0001, 0x8001, 
0x3c08, 0x0001, 0x4611, 0x0000, 0x2601, 0x0010, 0x4901, 0x0010, 
0x4c01, 0x0010, 0x001d, 0x17cc, 0x65fc, 0x1804, 0x4e01, 0x0800, 
0x6501, 0x8000, 0x001d, 0x17aa, 0x0001, 0x8003, 0x3c08, 0x0001, 
0x4611, 0x0000, 0x001d, 0x18e2, 0x047a, 0x17cc, 0x4901, 0x0040, 
0x4c01, 0x0040, 0x652c, 0x18e6, 0x001d, 0x18f2, 0x65fc, 0x18e2, 
0x4e01, 0x0800, 0x6501, 0x8000, 0x0111, 0x0065, 0x0105, 0x0600, 
0x001d, 0x1900, 0x0111, 0x0065, 0x0105, 0x0600, 0x010e, 0x1900, 
0x653c, 0x18fe, 0x6401, 0x0080, 0x001d, 0x1904, 0x4e01, 0x0001, 
0x4e11, 0x0001, 0x6401, 0x0080, 0x5511, 0x0061, 0x5611, 0x0060, 
0x5701, 0x9080, 0x5a01, 0x0021, 0x2401, 0x0000, 0x2501, 0x0000, 
0x2601, 0x0010, 0x494c, 0x1926, 0x3c08, 0x0001, 0x0011, 0x0046, 
0x0004, 0x8003, 0x019b, 0x1922, 0x0001, 0x8001, 0x3c08, 0x0001, 
0x4611, 0x0000, 0x4901, 0x0010, 0x4c01, 0x0010, 0x495c, 0x193a, 
0x3d08, 0x0001, 0x0011, 0x0046, 0x0004, 0x8004, 0x019b, 0x1936, 
0x0001, 0x8002, 0x3d08, 0x0001, 0x4611, 0x0000, 0x4901, 0x0020, 
0x4c01, 0x0020, 0x001d, 0x1768
};
const	unsigned short	AsicUprgSz = sizeof(AsicUprg)/2;

/************************************************************************************************/
/*																								*/
/*		JL100M_INI.C : JL-100 interface access driver											*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*		Ver 1.00	:	2007.12.20	Initial coding	T.soeda										*/
/*																								*/
/************************ Copyright(C) 2007 Yaskawa Electric Corporation ************************/
/*																								*/
/*		FUNCTIONS :																				*/
/*			jl100m_init_channel()			:	Clear Chnannel buffer and save 					*/
/*													host interface top address.					*/
/*			jl100m_setup_asic()				:	Setup ASIC.										*/
/*			jl100m_chk_asic_ready()			:	Check ASIC ready.								*/
/*			jl100m_set_usr_param()			:	Set user parameter.								*/
/*			jl100m_reset_asic()				:	Reset asic.										*/
/*			jl100m_set_regpar()				:	Set register parameter 							*/
/*													to register parameter area.					*/
/*			jl100m_write_compar()			:	Write communication parameter 					*/
/*													to JL100 SRAM area.							*/
/*			jl100m_write_iomap()			:	Write iomap parameter to JL100 SRAM area.		*/
/*			jl100m_req_set_par()			:	Request set CMD(PAR_R).							*/
/*			jl100m_initialize()				:	Excute JL100 initializing.						*/
/*			jl100m_req_detect_slv()			:	Request detect connecting slave(or C2 master).	*/
/*			jl100m_chk_detect_slv_cmp()		:	Check complete detect 							*/
/*															   connecting slave(or C2 master).	*/
/*			jl100m_req_measure_transdly()	:	Request transmit delay measurement.				*/
/*			jl100m_chk_transdly_cmp()		:	Check transmission delay mesurement cmplete.	*/
/*			jl100m_calc_dlytime()			:	Calculate T_RSP and INT_OFFSET.					*/
/*			jl100m_infm_cmode()				:	Inform C1 master setting communication mode 	*/
/*													to slave.									*/
/*			jl100m_chk_infm_cmode_cmp()		:	Check jl100m_infm_cmode complete.				*/
/*			jl100m_start_sync()				:	Start cyclic communication with sync mode.		*/
/*			jl100m_start_async()			:	Start cyclic communication with async mode.		*/
/*			jl100m_set_first_data()			:	Set first transmit data 						*/
/*													to toggle buffer A and B.					*/
/*			jl100m_set_global_frame()		:	Set global frame to JL100 SRAM area.			*/
/*			jl100m_set_link_header()		:	Set frame header data to JL100 SRAM area.		*/
/*			jl100m_read_ram()				:	Read data from RAM.								*/
/*			jl100m_write_ram()				:	Write data from RAM.							*/
/*			jl100m_activate_comprm()		:	Activate communication parameter.				*/
/*			jl100m_read_slvstat()			:	Read slave status number from IOMAP.			*/
/*			jl100m_read_iomap_member()		:	Read IOMAP member.								*/
/*			jl100m_write_iomap_member()		:	Write IOMAP member.								*/
/*			jl100m_chk_iomap_prm()			:	Check user setting IOMAP member.				*/
/*			jl100m_find_max_trdly()			:	Find max TR_DLY from IOMAP.						*/
/*			jl100m_download_asicprg()		:	Download JL-100 micro code.						*/
/*			jl100m_get_accdrv_ver()			:	Get access driver version.						*/
/*																								*/
/************************************************************************************************/

/* includes */
//#include "jl100m_gbl.h"

/* local defines */
#define TIME_500USEC			50000	/* 500usec at time unit 10nsec */
#define TIME_4MSEC				400000	/* 4msec   at time unit 10nsec */
#define TIME_64MSEC				6400000	/* 64msec  at time unit 10nsec */
#define SLV_CHK_TOUT_TIME		500000	/* Slave status check time out (time unit : 1usec) */
#define SLV_STS_CYCLIC			0x0031	/* Slave status number : Cyclic communication */

/* external */
extern const	unsigned short	AsicUprg[];
extern const	unsigned short	AsicUprgSz;

/* forward declarations */
#ifdef __cplusplus
extern	"C"	{
#endif
void  jl100m_init_channel(CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, JL100_USER_IOMAP *usr_iomapp);
short jl100m_setup_asic(ULONG *hif_reg_top);
short jl100m_chk_asic_ready(ULONG *hif_reg_top);
short jl100m_set_usr_param(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_par, JL100_REG_PAR *reg_par,
																		   JL100_COM_PAR *com_par);
short jl100m_reset_asic(CHANNEL_INFO *chbuffp);
short jl100m_set_regpar(CHANNEL_INFO *chbuffp, JL100_REG_PAR *reg_par);
short jl100m_write_compar(CHANNEL_INFO *chbuffp, JL100_COM_PAR *com_parp);
short jl100m_write_iomap(CHANNEL_INFO *chbuffp, JL100_USER_IOMAP *user_iomapp);
short jl100m_req_set_par(CHANNEL_INFO *chbuffp);
short jl100m_initialize(CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, 
                          JL100_USER_PAR *usr_parp, JL100_USER_IOMAP *usr_iomapp);
short jl100m_req_detect_slv(CHANNEL_INFO *chbuffp);
short jl100m_chk_detect_slv_cmp(CHANNEL_INFO *chbuffp);
short jl100m_req_measure_transdly(CHANNEL_INFO *chbuffp);
short jl100m_chk_transdly_cmp(CHANNEL_INFO *chbuffp);
short jl100m_calc_dlytime(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_parp, 
                                                 JL100_USER_IOMAP *usr_iomapp);
short jl100m_infm_cmode(CHANNEL_INFO *chbuffp);
short jl100m_chk_infm_cmode_cmp(CHANNEL_INFO *chbuffp);
short jl100m_start_sync(CHANNEL_INFO *chbuffp);
short jl100m_start_async(CHANNEL_INFO *chbuffp);
short jl100m_set_first_data(CHANNEL_INFO *chbuffp);
void  jl100m_set_global_frame(CHANNEL_INFO *chbuffp, ULONG adr);
void  jl100m_set_link_header(CHANNEL_INFO *chbuffp, ULONG adr);
short jl100m_read_ram(ULONG *hif_reg_top, USHORT ofst_adr, USHORT size, ULONG *rdata);
short jl100m_write_ram(ULONG *hif_reg_top, USHORT ofst_adr, USHORT size, ULONG wdata);
short jl100m_activate_comprm(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_parp,
                                                    JL100_USER_IOMAP *iomapp);
short jl100m_read_slvstat(CHANNEL_INFO *chbuffp, USHORT st_no);
unsigned short jl100m_read_iomap_member(CHANNEL_INFO *chbuffp, USHORT st_no, USHORT member);
void jl100m_write_iomap_member(CHANNEL_INFO *chbuffp, USHORT st_no, USHORT member, USHORT data);
short jl100m_chk_iomap_prm(CHANNEL_INFO *chbuffp, JL100_USER_IOMAP *usr_iomapp);
USHORT jl100m_find_max_trdly(CHANNEL_INFO *chbuffp);
unsigned short jl100m_get_rbuff_offset(CHANNEL_INFO *chbuffp, USHORT st_no);
unsigned short jl100m_get_cbuff_offset(CHANNEL_INFO *chbuffp, USHORT st_no);
short jl100m_download_asicprg(ULONG *hif_reg_top);
ULONG jl100m_get_accdrv_ver(void);
short jl100m_chk_slv_status( CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, 
                          JL100_USER_PAR *usr_parp, JL100_USER_IOMAP *usr_iomapp );

#ifdef __cplusplus
}
#endif

/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_init_channel()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Clear Chnannel buffer and save host interface top address.								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	*hif_reg_top	:	Host I/F register top address								*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void jl100m_init_channel( CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, JL100_USER_IOMAP *usr_iomapp)
{
	USHORT	*wtp;		/* for channel buffer access */
	USHORT	size, i;	/* Channel buffer size */
	
	/* Clear channel buffer */
	wtp = (USHORT *)chbuffp;
	size = sizeof(CHANNEL_INFO) / sizeof(USHORT);
	for (i = 0; i < size; i++)
	{
		*wtp = 0;
		wtp++;
	}

	/* Set top address of Host I/F register */
	chbuffp->hif_reg_top = (JL100_HOST_IF_REGS *)hif_reg_top;
	chbuffp->usr_iomap = usr_iomapp;
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_setup_asic()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Setup ASIC.																				*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Nomal end.													*/
/*		WAIT_SETUP				:	Waiting ASIC setup cmplete.									*/
/*		ERROR_VERIFY_MICRO		:	Download micro is not correctly								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_setup_asic(ULONG *hif_reg_top)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	 cid[2], ret;				/* Chip ID */
	
	/* Get Host I/F register top address */
	hirp = (JL100_HOST_IF_REGS *)hif_reg_top;
	
	/* Get Chip ID */
	*(ULONG*)(&cid) = (ULONG)jl100_get_cid(hirp);

	/* Check chip ID */
	if(*(ULONG*)(&cid) != JL100_CID)
	{
		return(WAIT_SETUP);	/* ASIC not ready */
	}
	if(cid[0] != JL100_CID_LO_ADR)
	{
		return(WAIT_SETUP);	/* ASIC not ready */
	}
	if(cid[1] != JL100_CID_HI_ADR)
	{
		return(WAIT_SETUP);	/* ASIC not ready */
	}
	
	/* Download micro code */
	ret = jl100m_download_asicprg(hif_reg_top);

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_chk_asic_ready()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Check ASIC ready.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Nomal end.													*/
/*		WAIT_ASIC_READY			:	Waiting ASIC ready.											*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_chk_asic_ready(ULONG *hif_reg_top)
{
	volatile JL100_HOST_IF_REGS *hirp;		/* Host I/F Top address */
	USHORT	 cid[2], sts;					/* Chip ID */

	/* Get Host I/F register top address */
	hirp = (volatile JL100_HOST_IF_REGS *)hif_reg_top;

	/* Get Chip ID */
	*(ULONG *)(&cid) = (ULONG)jl100_get_cid(hirp);

	/* Check chip ID */
	if(*(ULONG *)(&cid) != JL100_CID)
	{
		return(WAIT_ASIC_READY);	/* ASIC not ready */
	}
	if(cid[0] != JL100_CID_LO_ADR)
	{
		return(WAIT_ASIC_READY);	/* ASIC not ready */
	}
	if(cid[1] != JL100_CID_HI_ADR)
	{
		return(WAIT_ASIC_READY);	/* ASIC not ready */
	}
	
	/* Check STATUS.RDY */
	sts = (USHORT)jl100_get_sts(hirp);
	if((sts & JL100_STS_RDY) != 0)
	{
		return(LIB_OK);
	}
	else
	{
		return(WAIT_ASIC_READY);	/* ASIC not ready */
	}
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_set_usr_param()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Set user parameter.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		JL100_USER_PAR *usr_par	:	JL100 user parameter										*/
/*		JL100_REG_PAR *reg_par	:	JL100 register parameter									*/
/*		JL100_COM_PAR *com_par	:	JL100 communication parameter								*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_RAM_SIZE_OVER		:	Using memory size larger than RAM.							*/
/*		ERROR_INVALID_TMCYC		:	Invalid transmite cycle.									*/
/*		ERROR_INVALID_USRPAR	:	Invalid user parameter.										*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_set_usr_param(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_par, JL100_REG_PAR *reg_par,
																		   JL100_COM_PAR *com_par)
{
	USHORT buf;
	ULONG  c2_dly_work, intoffset_work;
	ULONG  *wtp, size, i;

	/* Initialize value */
	wtp = &com_par->ulong_ptr;
	size = sizeof(JL100_COM_PAR) / sizeof(ULONG);
	for (i = 0; i < size; i++)
	{
		*wtp = 0;
		wtp++;
	}
	
	wtp = &reg_par->ulong_ptr;
	size = sizeof(JL100_REG_PAR) / sizeof(ULONG);
	for (i = 0; i < size; i++)
	{
		*wtp = 0;
		wtp++;
	}

	/* Set register parameter of user setting "usr_par -> reg_par" */
	reg_par->str.mod = usr_par->mod;
	reg_par->str.imk = DEF_IMK_REG;
	reg_par->str.pars = DEF_PARS_ADR;

	/* Set user setting communication parameter "usr_par -> com_par" */
	com_par->str.ma0 = usr_par->ma0;
	com_par->str.ma_max = usr_par->ma_max;
	com_par->str.prot_sel = usr_par->prot_sel;
	com_par->str.max_rtry = usr_par->max_rtry;
	com_par->str.pkt_sz = usr_par->pkt_sz;
	com_par->str.wdt = (16384 - usr_par->wdt);	/* WDT works : (16384 - (com_par->wdt setting)) * 8us */
	com_par->str.dly_cnt = usr_par->dly_cnt;

	/* Set default setting communication parameter */
	com_par->str.ma_msk0 = DEF_MA_MSK0;
	com_par->str.ma1 = usr_par->ma0;
	com_par->str.ma_msk1 = DEF_MA_MSK1;
	com_par->str.srch_time = DEF_SRCH_TIME;
	com_par->str.ifgset = DEF_IFGSET;
	com_par->str.max_frm = DEF_MAX_FRM;
	com_par->str.t_unit = 0;
	com_par->str.t_mcyc = 0xC350;
	com_par->str.reserve1 = 2;
	com_par->str.reserve3 = DEF_DLYFRM_WAIT_CNT;		/* Wait count for Delay measurement frame */
	com_par->str.reserve4 = DEF_DLYAPP_WAIT_CNT;		/* Wait count for next Delay appointment frame */

	/* Set async request retry count */
	com_par->str.async_req_rtry = COM_START_TOUT/(ASYNC_REQ_POLL_TIME * com_par->str.ma_max);
	if(com_par->str.async_req_rtry > 0x1FFF)
	{
		com_par->str.async_req_rtry = 0x1FFF;
	}

	/* Check message size */
	buf = (USHORT)(DEF_MSG_PTR + DEF_C1MSG_SZ * 2 + DEF_C2MSG_SZ * 2);
	if((reg_par->str.pars) < buf)
	{
		return(ERROR_RAM_SIZE_OVER);
	}

	buf = DEF_IOMAP_PTR + IOMAP_SIZE * 64;
	if(DEF_SRAM_SIZE < buf)
	{
		return(ERROR_RAM_SIZE_OVER);
	}

	/* Set pointer address and message size */
	com_par->str.msg_ptr 	= DEF_MSG_PTR;
	com_par->str.iomap_ptr 	= DEF_IOMAP_PTR;
	com_par->str.c1msg_sz 	= DEF_C1MSG_SZ;
	com_par->str.c2msg_sz 	= DEF_C2MSG_SZ;

	/* Set T_MCYC, T_UNIT, C2_DLY, and IDLY */
	if(((chbuffp->chk_code & PROC_INITIAL) != 0))
	{
		/* Check communication mode */
		if(com_par->str.prot_sel == 1)	/* Async. com mode */
		{
			com_par->str.t_mcyc = 8000;
			com_par->str.t_unit = TUNIT_1USEC;
			com_par->str.reserve2 = DEF_COMPAR_RESERVE2_1US;
			com_par->str.c2_dly = 0;
			reg_par->str.idly = 1000;
			
			return(LIB_OK);
		}
		/* Set t_mcyc and t_unit, c2_dly , idly*/
		if(usr_par->t_mcyc > TIME_64MSEC)			/* t_mcyc >64msec */
		{
			return(ERROR_INVALID_TMCYC);
		}
		else if(usr_par->t_mcyc <= TIME_500USEC)	/* t_mcyc <= 500usec */
		{
			com_par->str.t_mcyc = (USHORT)usr_par->t_mcyc;
			com_par->str.t_unit = TUNIT_10NSEC;
			com_par->str.reserve2 = DEF_COMPAR_RESERVE2_10NS;
			if((usr_par->c2_dly > 0xffff) || (usr_par->intoffset > com_par->str.t_mcyc))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				com_par->str.c2_dly = com_par->str.t_mcyc - (USHORT)usr_par->c2_dly;
				reg_par->str.idly = com_par->str.t_mcyc - (USHORT)usr_par->intoffset;
			}
		}
		else if(usr_par->t_mcyc > TIME_4MSEC)		/* t_mcyc > 4msec */
		{
			com_par->str.t_mcyc = (USHORT)(usr_par->t_mcyc/100);
			com_par->str.t_unit = TUNIT_1USEC;
			com_par->str.reserve2 = DEF_COMPAR_RESERVE2_1US;
			c2_dly_work = usr_par->c2_dly/100;
			intoffset_work = usr_par->intoffset/100;
			if((c2_dly_work > 0xffff) || (intoffset_work > com_par->str.t_mcyc))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				com_par->str.c2_dly = com_par->str.t_mcyc - (USHORT)c2_dly_work;
				reg_par->str.idly = com_par->str.t_mcyc - (USHORT)intoffset_work;
			}
		}
		else										/* 500usec < t_mcyc <= 4msec */
		{
			com_par->str.t_mcyc = (USHORT)(usr_par->t_mcyc/10);
			com_par->str.t_unit = TUNIT_100NSEC;
			com_par->str.reserve2 = DEF_COMPAR_RESERVE2_100NS;
			c2_dly_work = usr_par->c2_dly/10;
			intoffset_work = usr_par->intoffset/10;
			if((c2_dly_work > 0xffff) || (intoffset_work > com_par->str.t_mcyc))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				com_par->str.c2_dly = com_par->str.t_mcyc - (USHORT)c2_dly_work;
				reg_par->str.idly = com_par->str.t_mcyc - (USHORT)intoffset_work;
			}
		}
		
		if(usr_par->c2_dly == 0)
		{
			com_par->str.c2_dly = 0;
		}
	}
	return(LIB_OK);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_reset_asic()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Reset asic.																				*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		WAIT_SETUP				:	Waiting ASIC setup cmplete.									*/
/*		ERROR_VERIFY_MICRO		:	Download micro is not correctly								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_reset_asic(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	short	ret;						/* Return code */
	
	/* Initialize value */
	ret = LIB_OK;

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Request reset asic */
	jl100_set_cmd(hirp, JL100_CMD_RST_ASC);

	while((jl100_get_cmd(hirp) & JL100_CMD_RST_ASC) != 0){ ;}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_set_regpar()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Set register parameter to register parameter area.										*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		JL100_REG_PAR *reg_par	:	JL100 register parameter									*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_TOUT_MODE_SET		:	MODE regs. set request did not completed					*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_set_regpar(CHANNEL_INFO *chbuffp, JL100_REG_PAR *reg_par)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	i;							/* Polling Counter */
	ULONG	data;						/* Register read data */
	short	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Save PARS pointer data */
	chbuffp->pars_data = (USHORT)reg_par->str.pars + DEF_SRAM_TOP_ADR;

	/* Write data to register area */
	jl100_set_imk(hirp, reg_par->str.imk);
	jl100_set_mod(hirp, reg_par->str.mod);
	jl100_set_pars(hirp, reg_par->str.pars);
	jl100_set_idly(hirp, reg_par->str.idly);

	/* Request set CMD(P_MOD) */
	jl100_set_cmd(hirp, JL100_CMD_P_MOD_R);

	/* Wait p_mod complete */
	ret = ERROR_TOUT_MODE_SET;
	for(i = 0; i < JL100_CMD_POLLING_CNT; i++)
	{
		data = jl100_get_ints(hirp);
		if((data & JL100_INTS_P_MOD_I) != 0)
		{
			ret = LIB_OK;
			/* Clear interrupt factor */
			jl100_clear_ints(hirp, JL100_INTS_P_MOD_I);
			break;
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_write_compar()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Write communication parameter to JL100 SRAM area.										*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		JL100_COM_PAR *com_par	:	JL100 communication parameter								*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_write_compar(CHANNEL_INFO *chbuffp, JL100_COM_PAR *com_parp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	*wtp, *rdp;					/* for RAM access */
	USHORT	compar_sz;					/* JL100_COM_PAR size */
	short	ret;						/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Save communication parameter to channel buffer */
	chbuffp->ma0 = com_parp->str.ma0;
	chbuffp->ma1 = com_parp->str.ma1;
	chbuffp->ma_max = com_parp->str.ma_max;
	chbuffp->t_unit = com_parp->str.t_unit;
	chbuffp->prot_sel = com_parp->str.prot_sel;
	chbuffp->max_rtry = com_parp->str.max_rtry;
	chbuffp->msg_ptr = com_parp->str.msg_ptr + DEF_SRAM_TOP_ADR;
	chbuffp->iomap_ptr = com_parp->str.iomap_ptr + DEF_SRAM_TOP_ADR;
	chbuffp->c1msg_sz = com_parp->str.c1msg_sz;
	chbuffp->c2msg_sz = com_parp->str.c2msg_sz;
	chbuffp->pkt_sz = com_parp->str.pkt_sz;

	/* Write communication parameter */
	rdp = &com_parp->ulong_ptr;
	wtp = (ULONG *)((ULONG)hirp + chbuffp->pars_data);
	compar_sz = sizeof(JL100_COM_PAR);
	while(compar_sz > 0)
	{
		jl100_write_dwdata(wtp, rdp);
		compar_sz -= DWORD_SIZE;
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_write_iomap()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Write iomap parameter to JL100 SRAM area.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp		:	Channel buffer address									*/
/*		JL100_USER_IOMAP *iomapp	:	JL100 iomap parameter(user setting)						*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK						:	Normal end												*/
/*		ERROR_IOMAP_SIZE			:	Invalid command data length or response data length.	*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_write_iomap(CHANNEL_INFO *chbuffp, JL100_USER_IOMAP *usr_iomapp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	volatile JL100_IO_MAP *iomapp;		/* IOMAP top address */
	volatile JL100_IO_MAP iomap_work;	/* Work */
	volatile ULONG	*wtp, *rdp;			/* for RAM access */
	ULONG	t_rsp_work;					/* Work */
	USHORT	usrio_sz, i;				/* JL100_USER_IOMAP size */
	short	ret;						/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get IOMAP area top address */
	iomapp = (volatile JL100_IO_MAP *)((ULONG)hirp + chbuffp->iomap_ptr);

	/* User setting IOMAP data check */
	ret = jl100m_chk_iomap_prm(chbuffp, usr_iomapp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Write iomap data to #0 - #ma_max area */
	wtp = &iomapp->ulong_ptr;
	for(i = 0; i < (chbuffp->ma_max)+1; i++)
	{
		rdp = &iomap_work.ulong_ptr;
		iomap_work.str.axis_adr = (usr_iomapp + i)->axis_adr;
		iomap_work.str.cd_len = (usr_iomapp + i)->cd_len;
		iomap_work.str.rd_len = (usr_iomapp + i)->rd_len;
		if(chbuffp->t_unit == TUNIT_100NSEC)
		{
			t_rsp_work = (usr_iomapp + i)->t_rsp / 10;
			if((t_rsp_work > 0xffff) || (t_rsp_work < 50))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				iomap_work.str.t_rsp = (USHORT)t_rsp_work;
			}
		}
		else if(chbuffp->t_unit == TUNIT_1USEC)
		{
			t_rsp_work = (usr_iomapp + i)->t_rsp / 100;
			if((t_rsp_work > 0xffff) || (t_rsp_work < 5))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				iomap_work.str.t_rsp = (USHORT)t_rsp_work;
			}
		}
		else
		{
			t_rsp_work = (usr_iomapp + i)->t_rsp;
			if((t_rsp_work > 0xffff) || (t_rsp_work < 500))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				iomap_work.str.t_rsp = (USHORT)t_rsp_work;
			}
		}

		usrio_sz = USER_IOMAP_SIZE;
		while(usrio_sz > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			usrio_sz -= DWORD_SIZE;
		}
		wtp += (sizeof(JL100_IO_MAP) - USER_IOMAP_SIZE)/sizeof(ULONG);

		/* Save CMD/RSP buffer offset */
		(usr_iomapp + i)->cmdbuff_offset = jl100m_get_cbuff_offset(chbuffp, i);
		(usr_iomapp + i)->rspbuff_offset = jl100m_get_rbuff_offset(chbuffp, i);
	}

	if((usr_iomapp + (chbuffp->ma_max + 1))->axis_adr == 0x0002)
	{
		/* Write C2 master IOMAP parameter */
		wtp = &iomapp->ulong_ptr;
		wtp += 0x00FC;
		iomap_work.str.axis_adr = C2MST_ADR;
		iomap_work.str.cd_len = 0;
		iomap_work.str.rd_len = 0;
		if(chbuffp->t_unit == TUNIT_100NSEC)
		{
			t_rsp_work = (usr_iomapp + (chbuffp->ma_max + 1))->t_rsp / 10;
			if((t_rsp_work > 0xffff) || (t_rsp_work < 50))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				iomap_work.str.t_rsp = (USHORT)t_rsp_work;
			}
		}
		else if(chbuffp->t_unit == TUNIT_1USEC)
		{
			t_rsp_work = (usr_iomapp + (chbuffp->ma_max + 1))->t_rsp / 100;
			if((t_rsp_work > 0xffff) || (t_rsp_work < 5))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				iomap_work.str.t_rsp = (USHORT)t_rsp_work;
			}
		}
		else
		{
			t_rsp_work = (usr_iomapp + (chbuffp->ma_max + 1))->t_rsp;
			if((t_rsp_work > 0xffff) || (t_rsp_work < 500))
			{
				return(ERROR_INVALID_USRPAR);
			}
			else
			{
				iomap_work.str.t_rsp = (USHORT)t_rsp_work;
			}
		}

		usrio_sz = USER_IOMAP_SIZE;
		rdp = &iomap_work.ulong_ptr;
		while(usrio_sz > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			usrio_sz -= DWORD_SIZE;
		}
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_req_set_par()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Request set CMD(PAR_R).																	*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_TOUT_USRPRM_SET	:	User param set request did not completed					*/
/*		ERROR_INVALID_USRPAR	:	Invalid user setting parameter.								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_req_set_par(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	data;						/* Register read data */
	ULONG	i;							/* Polling counter */
	short	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Request set par_r of CMD register */
	jl100_set_cmd(hirp, JL100_CMD_PAR_R);

	/* Wait par_r complete */
	ret = ERROR_TOUT_USRPRM_SET;
	for(i = 0; i < JL100_CMD_POLLING_CNT; i++)
	{
		data = jl100_get_ints(hirp);
		if((data & JL100_INTS_PAR_I) != 0)
		{
			/* Clear interrupt factor */
			jl100_clear_ints(hirp, JL100_INTS_PAR_I);

			/* Check error status */
			data = jl100_get_ests(hirp);
			if((data & JL100_ESTS_PAR_ERR) != 0)
			{
				ret = ERROR_INVALID_USRPAR;
				/* Clear error status */
				jl100_clear_ests(hirp, JL100_ESTS_PAR_ERR);
				break;
			}
			else
			{
				ret = LIB_OK;
			}
			break;
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_initialize()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Excute JL100 initializing.																*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp			:	Channel buffer address								*/
/*		ULONG *hif_reg_top				:	Host I/F register top address						*/
/*		JL100_USER_PAR *usr_parp		:	JL100 user parameter								*/
/*		JL100_USER_IOMAP *usr_iomapp	:	JL100 IOMAP parameter(user setting)					*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK							:	Normal end											*/
/*		ERROR_INVALID_HIFPTR			:	Invalid host I/F register address setting.			*/
/*		ERROR_RAM_SIZE_OVER				:	Using memory size larger than RAM.					*/
/*		ERROR_TOUT_MODE_SET				:	MODE regs. set request did not completed			*/
/*		ERROR_TOUT_USRPRM_SET			:	User param set request did not completed			*/
/*		ERROR_INVALID_USRPAR			:	Invalid user setting parameter.						*/
/*		ERROR_VERIFY_MICRO				:	Download micro is not correctly						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_initialize( CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, 
                          JL100_USER_PAR *usr_parp, JL100_USER_IOMAP *usr_iomapp )
{
	JL100_COM_PAR	com_par;		/* Communication parameter */
	JL100_REG_PAR	reg_par;		/* Register parameter */
	short	ret;					/* Return code */

	/* Check HOST I/F regs. top address */
	if((ULONG)hif_reg_top > 0xffff0000)
	{
		return(ERROR_INVALID_HIFPTR);
	}

	ret = jl100m_chk_slv_status(chbuffp, hif_reg_top, usr_parp, usr_iomapp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Clear channel buffer, and set top address of Host I/F register */
	jl100m_init_channel(chbuffp, hif_reg_top, usr_iomapp);

	/* Get Chip ID */
	chbuffp->cid = (ULONG)jl100_get_cid(chbuffp->hif_reg_top);

	/* Set user parameter & default parameter */
	ret = jl100m_set_usr_param(chbuffp, usr_parp, &reg_par, &com_par);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Set register parameter */
	ret = jl100m_set_regpar(chbuffp, &reg_par);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Write communication parameter */
	ret = jl100m_write_compar(chbuffp, &com_par);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Write IOMAP parameter */
	ret = jl100m_write_iomap(chbuffp, usr_iomapp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Request set Communication parameter and IOMAP */
	ret = jl100m_req_set_par(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Set check code of this process */
	chbuffp->chk_code = PROC_INITIAL;

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_req_detect_slv()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Request detect connecting slave(or C2 master).											*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:																*/
/*		ERROR_WRONG_SEQ			:																*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_req_detect_slv(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;		/* Host I/F top address */
	USHORT   need_proc;						/* for process sequence check */
	short    ret;							/* Return code */

	/* Check processing sequence */
	need_proc = PROC_INITIAL;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Initialize value */
	ret = LIB_OK;

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Request detect connecting slave */
	jl100_set_cmd(hirp, JL100_CMD_DTCT_R);

	/* Set check code of this process */
	chbuffp->chk_code |= PROC_REQ_DETECT_SLV;

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_chk_detect_slv_cmp()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Check detecting connect slave(or C2 master) complete.									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end.													*/
/*		WAITING_CMP_DETECT		:	Waiting complete detect slave.								*/
/*		ERROR_SLV_AXIS_NO		:	Some slave has same station address.						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_chk_detect_slv_cmp(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;		/* Host I/F top address */
	USHORT	 need_proc;						/* for process sequence check */
	ULONG    data;							/* for register read */
	USHORT   max_trdly;						/*  */
	short    ret;							/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_REQ_DETECT_SLV;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Check detect connecting slave complete */
	data = jl100_get_ints(hirp);
	if((data & JL100_INTS_DTCT_I) != 0)
	{
		/* Clear interrupt factor */
		jl100_clear_ints(hirp, JL100_INTS_DTCT_I);
		
		/* Check error status */
		data = jl100_get_ests(hirp);
		if((data & JL100_ESTS_AXIS_NO_ERR) != 0)
		{
			ret = ERROR_SLV_AXIS_NO;
			/* Clear error status */
			jl100_clear_ests(hirp, data);
		}
		else if((data & JL100_ESTS_TX_ERROR) != 0)
		{
			ret = ERROR_TX_FRM;
			/* Clear error status */
			jl100_clear_ests(hirp, data);
		}
		else
		{
			ret = LIB_OK;
		}
		
		/* Check max TR_DLY(time unit : 1usec) */
		max_trdly = jl100m_find_max_trdly(chbuffp);
		
		if(max_trdly < 500)
		{
			/* time unit : 10nsec */
			chbuffp->t_unit = TUNIT_10NSEC;
		}
		else if(max_trdly < 4000)
		{
			/* time unit : 100nsec */
			chbuffp->t_unit = TUNIT_100NSEC;
		}
		else
		{
			/* time unit : 1usec */
			chbuffp->t_unit = TUNIT_1USEC;
		}
		
		if(ret == LIB_OK)
		{
			/* Set check code of this process */
			chbuffp->chk_code |= PROC_CHK_DETECT_SLV_CMP;
			chbuffp->chk_code &= ~(PROC_REQ_DETECT_SLV);
		}
	}
	else
	{
		/* Check error status */
		data = jl100_get_ests(hirp);
		if((data & JL100_ESTS_TX_ERROR) != 0)
		{
			ret = ERROR_TX_FRM;
			/* Clear error status */
			jl100_clear_ests(hirp, data);
		}
		else
		{
			ret = WAIT_CMP_DETECT;
		}
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_req_measure_transdly()															*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Request transmit delay measurement.														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_WRONG_SEQ			:	Wrong process sequence										*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_req_measure_transdly(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	need_proc;					/* for process sequence check */
	short	ret;						/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_CHK_DETECT_SLV_CMP;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Request measure trans delay */
	jl100_set_cmd(hirp, JL100_CMD_DLY_R);

	/* Set check code of this process */
	chbuffp->chk_code |= PROC_REQ_MEASUR_TRANSDLY;

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_chk_transdly_cmp()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Check transmission delay mesurement cmplete.											*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		MEASURING_TRANSDLY		:	Measuring transmit delay time								*/
/*		ERROR_WRONG_SEQ			:	Wrong process sequence										*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_chk_transdly_cmp(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	ints;						/* for register read */
	ULONG	data;						/* for register read */
	USHORT	need_proc;					/* for process sequence check */
	short	ret;						/* Return code */

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_CHK_DETECT_SLV_CMP | PROC_REQ_MEASUR_TRANSDLY;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Check trans delay measurement complete */
	ints = jl100_get_ints(hirp);
	if((ints & JL100_INTS_DLY_I) != 0)
	{
		ret = LIB_OK;
		/* Clear interrupt factor */
		jl100_clear_ints(hirp, JL100_INTS_DLY_I);
		
		/* Check error status */
		data = jl100_get_ests(hirp);
		if((data & JL100_ESTS_TX_ERROR) != 0)
		{
			ret = ERROR_TX_FRM;
			/* Clear error status */
			jl100_clear_ests(hirp, data);
		}
	}
	else
	{
		/* Check error status */
		data = jl100_get_ests(hirp);
		if((data & JL100_ESTS_TX_ERROR) != 0)
		{
			ret = ERROR_TX_FRM;
			/* Clear error status */
			jl100_clear_ests(hirp, data);
		}
		else
		{
			ret = MEASURING_TRANSDLY;
		}
	}

	/* Set check code of this process */
	if(ret == LIB_OK)
	{
		chbuffp->chk_code |= PROC_CHK_TRANSDLY_CMP;
		chbuffp->chk_code &= ~(PROC_REQ_MEASUR_TRANSDLY);
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_calc_dlytime()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Calculate T_RSP and INT_OFFSET.															*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp		:	Channel buffer address									*/
/*		JL100_USER_PAR *usr_parp	:	JL100 user parameter									*/
/*		JL100_USER_IOMAP *iomapp	:	User IOMAP address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK						:	Normal end												*/
/*		ERROR_WRONG_SEQ				:	Wrong process sequence									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_calc_dlytime(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_parp, 
                                                 JL100_USER_IOMAP *usr_iomapp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	need_proc, i;				/* for process sequence check */
	ULONG  t_rsp_work, t_rsp_max, t_rsp_sum;
	ULONG  cd_len_work, rd_len_work;
	ULONG  stistat[2];
	short   ret;						/* Return code */

	/* Initialize value */
	t_rsp_sum = t_rsp_max = 0;
	ret = LIB_OK;

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_CHK_DETECT_SLV_CMP | PROC_CHK_TRANSDLY_CMP;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	stistat[0] = jl100_get_sti1(hirp);
	stistat[1] = jl100_get_sti2(hirp);

	/* Set #1T_RSP - #ma_maxT_RSP to user IOMAP*/
	for(i = 1; i < (chbuffp->ma_max)+1; i++)
	{
		if(((i < 32) && (((stistat[0] >> i) & 0x0001) != 0)) || ((i >= 32) && ((stistat[1] >> (i - 32)) & 0x0001) != 0))
		{
			/* Get TR_DLY from IOMAP */
			t_rsp_work = jl100m_read_iomap_member(chbuffp, i, TR_DLY);
			t_rsp_work <<= 1;

			/* Check T_UNIT */
			if(chbuffp->t_unit == TUNIT_10NSEC)
			{
				t_rsp_work = t_rsp_work + DEF_TRSP_BASE_TIME;
			}
			else if(chbuffp->t_unit == TUNIT_100NSEC)
			{
				t_rsp_work = (t_rsp_work * 10) + DEF_TRSP_BASE_TIME;
			}
			else
			{
				t_rsp_work = (t_rsp_work * 100) + DEF_TRSP_BASE_TIME;
			}
			
			/* Add data length trans time over 32byte & Save T_RSP to user setting area */
			cd_len_work = jl100m_read_iomap_member(chbuffp, i, CD_LEN);
			cd_len_work = (cd_len_work <= 32) ? 0 : (cd_len_work - 32);
			rd_len_work = jl100m_read_iomap_member(chbuffp, i, RD_LEN);
			rd_len_work = (rd_len_work <= 32) ? 0 : (rd_len_work - 32);
			t_rsp_work += ((cd_len_work + rd_len_work) << 3);
			(usr_iomapp + i)->t_rsp = t_rsp_work;
		}
		
		/* Sum t_rsp */
		t_rsp_sum += (usr_iomapp + i)->t_rsp;
		
		/* Max T_RSP */
		if(t_rsp_max < (usr_iomapp + i)->t_rsp)
		{
			t_rsp_max = (usr_iomapp + i)->t_rsp;
		}
	}
	
	/* Calculate int_offset and set to user area */
	t_rsp_sum += usr_iomapp->t_rsp;
	t_rsp_sum += ((t_rsp_max + 500) * chbuffp->max_rtry);
	if(chbuffp->t_unit == TUNIT_10NSEC)
	{
		usr_parp->intoffset = t_rsp_sum;
	}
	else
	{
		usr_parp->intoffset = t_rsp_sum + (chbuffp->ma_max * 100);
	}
	
	/* C2master */
	if(((usr_iomapp + (chbuffp->ma_max+1))->axis_adr == 0x0002) && ((stistat[1] & 0x80000000) != 0))
	{
		/* Get TR_DLY from IOMAP */
		t_rsp_work = jl100m_read_iomap_member(chbuffp, 63, TR_DLY);
		t_rsp_work <<= 1;

		/* Check T_UNIT */
		if(chbuffp->t_unit == TUNIT_10NSEC)
		{
			t_rsp_work = t_rsp_work + DEF_TRSP_BASE_TIME;
		}
		else if(chbuffp->t_unit == TUNIT_100NSEC)
		{
			t_rsp_work = (t_rsp_work * 10) + DEF_TRSP_BASE_TIME;
		}
		else
		{
			t_rsp_work = (t_rsp_work * 100) + DEF_TRSP_BASE_TIME;
		}
		
		(usr_iomapp + (chbuffp->ma_max+1))->t_rsp = t_rsp_work;
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_infm_cmode()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Inform C1 master setting communication mode to slave.									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp			:	Channel buffer address								*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK							:	Normal end											*/
/*		ERROR_WRONG_SEQ					:	Wrong process sequence								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_infm_cmode(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	need_proc;					/* for process sequence check */
	short	ret; 						/* Return code */
	
	ret = LIB_OK;

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_CHK_DETECT_SLV_CMP | PROC_CHK_TRANSDLY_CMP;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Request set CMD(SCNF_R) */
	jl100_set_cmd(hirp, JL100_CMD_SCNF_R);

	/* Set check code of this process */
	chbuffp->chk_code |= PROC_INFM_CMODE;

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_chk_infm_cmode_cmp()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Check jl100m_infm_cmode complete.														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		WAIT_SLV_RSP			:	Waiting slave response.										*/
/*		ERROR_WRONG_SEQ			:	Wrong process sequence.										*/
/*		ERROR_INFM_CMODE		:	Inform com. mode request did not completed.					*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_chk_infm_cmode_cmp(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	data;						/* Read data from register */
	USHORT	need_proc;					/* for process sequence check */
	short	ret; 						/* Return code */

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_CHK_DETECT_SLV_CMP | PROC_CHK_TRANSDLY_CMP | PROC_INFM_CMODE;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	data = jl100_get_ints(hirp);
	if((data & JL100_INTS_SCNF_I) != 0)
	{
		/* Clear interrupt factor */
		jl100_clear_ints(hirp, JL100_INTS_SCNF_I);

		/* Check error status */
		data = jl100_get_ests(hirp);

		if((data & JL100_ESTS_SCNF_ERR) != 0)
		{
			ret = ERROR_INFM_CMODE;
			/* Clear error status */
			jl100_clear_ests(hirp, data);
		}
		else if((data & JL100_ESTS_TX_ERROR) != 0)
		{
			ret = ERROR_TX_FRM;
			/* Clear error status */
			jl100_clear_ests(hirp, data);
		}
		else
		{
			ret = LIB_OK;
		}
	}
	else
	{
		/* Check error status */
		data = jl100_get_ests(hirp);
		if((data & JL100_ESTS_TX_ERROR) != 0)
		{
			jl100_clear_ests(hirp, data);
			return(ERROR_TX_FRM);
		}
		else
		{
			return(WAIT_SLV_RSP);
		}
	}

	if((ret == LIB_OK) || ((chbuffp->prot_sel == 1) && (ret == ERROR_INFM_CMODE)))
	{
		/* Set check code of this process */
		chbuffp->chk_code |= PROC_INFM_CMODE_CMP;
		chbuffp->chk_code &= ~(PROC_INFM_CMODE);
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_start_sync()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Start cyclic communication with sync mode.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_WRONG_SEQ			:	Wrong process sequence.										*/
/*		ERROR_TOUT_CHANG_CBUFF	:	Request change command buffer did not complete.				*/
/*		ERROR_TOUT_CSTART		:	Request start sync com. is not complete.					*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_start_sync(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	i;							/* Polling counter */
	ULONG	data;						/* Register read data */
	USHORT	need_proc;					/* for process sequence check */
	short	ret;						/* Return code */

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_CHK_DETECT_SLV_CMP | PROC_CHK_TRANSDLY_CMP | PROC_INFM_CMODE_CMP;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Mask interrupt factor (INT0) */
	jl100_set_imk(hirp, 0xFFFFFFFF);

	/* Set sync frame and first transmit data */
	ret = jl100m_set_first_data(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Request start sync mode communication */
	jl100_set_cmd(hirp, JL100_CMD_C_START_R);

	/* Wait sync mode communication start interrupt */
	ret = ERROR_TOUT_CSTART;
	for(i = 0; i < JL100_CMD_POLLING_CNT; i++)
	{
		data = jl100_get_ints(hirp);
		if((data & JL100_INTS_C_START_I) != 0)
		{
			ret = LIB_OK;
			/* Clear interrupt factor */
			jl100_clear_ints(hirp, JL100_INTS_C_START_I);
			break;
		}
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_start_async()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Start cyclic communication with async mode.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_WRONG_SEQ			:	Wrong process sequence.										*/
/*		ERROR_TOUT_ASTART		:	Start async com request did not completed.					*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_start_async(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	i;							/* Polling counter */
	ULONG	data;						/* Register read data */
	USHORT	need_proc;					/* for process sequence check */
	short	ret;						/* Return code */

	/* Check processing sequence */
	need_proc = PROC_INITIAL | PROC_CHK_DETECT_SLV_CMP | PROC_CHK_TRANSDLY_CMP;
	if((chbuffp->chk_code & need_proc) != need_proc)
	{
		return(ERROR_WRONG_SEQ);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Mask interrupt factor except RX_I (INT0) */
	jl100_set_imk(hirp, 0xFFFFFF7F);

	/* Request start async mode communication */
	jl100_set_cmd(hirp, JL100_CMD_A_START_R);

	/* Wait sync mode communication start interrupt */
	ret = ERROR_TOUT_ASTART;
	for(i = 0; i < JL100_CMD_POLLING_CNT; i++)
	{
		data = jl100_get_ints(hirp);
		if((data & JL100_INTS_A_START_I) != 0)
		{
			ret = LIB_OK;
			/* Clear interrupt factor */
			jl100_clear_ints(hirp, JL100_INTS_A_START_I);
			break;
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_set_first_data()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Set first transmit data to toggle buffer A and B.										*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_TOUT_CHANG_CBUFF	:	Request change command buffer did not complete.				*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_set_first_data(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	cbadr;						/* Command buffer address */
	short	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get command buffer offset address */
	cbadr = (ULONG)(chbuffp->hif_reg_top) + DEF_SRAM_TOP_ADR;
	cbadr += (USHORT)jl100_get_cbadr(hirp);

	/* Set sync frame */
	jl100m_set_global_frame(chbuffp, cbadr);
	/* Set link header */
	jl100m_set_link_header(chbuffp, cbadr);

	/* Change command buffer A to B */
	ret = jl100m_change_cbuff(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Get command buffer offset address */
	cbadr = (ULONG)(chbuffp->hif_reg_top) + DEF_SRAM_TOP_ADR;
	cbadr += (USHORT)jl100_get_cbadr(hirp);

	/* Set global address */
	jl100m_set_global_frame(chbuffp, cbadr);
	/* Set link header */
	jl100m_set_link_header(chbuffp, cbadr);

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_set_global_frame()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Set global frame to JL100 SRAM area.													*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		ULONG adr				:	Global frame start address									*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void jl100m_set_global_frame(CHANNEL_INFO *chbuffp, ULONG adr)
{
	JL100_GBL_FRAME gbl_frame;			/* Global frame struct */
	ULONG	*wtp, *rdp;					/* for RAM access */
	USHORT	size;

	/* Set global frame data */
	gbl_frame.str.da = 0xFFFF;
	gbl_frame.str.sa = 0x0001;
	gbl_frame.str.msg_ctrl = 0x0000;
	gbl_frame.str.ftyp_len = FTYPE_SYNC | jl100m_read_iomap_member(chbuffp, 0, CD_LEN);
	gbl_frame.str.time = 0x00000000;
	gbl_frame.str.idly = 0x0000;
	gbl_frame.str.reserve = 0x0000;
	gbl_frame.str.fcs = 0x00000000;

	/* Write global frame data to SRAM area */
	wtp = (ULONG *)adr;
	rdp = &gbl_frame.ulong_ptr;
	size = sizeof(JL100_GBL_FRAME);
	while(size > 0)
	{
		jl100_write_dwdata(wtp, rdp);
		size -= DWORD_SIZE;
	}
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_set_link_header()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Set frame header data to JL100 SRAM area.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		ULONG adr				:	Cyclic frame start address									*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void jl100m_set_link_header(CHANNEL_INFO *chbuffp, ULONG adr)
{
	JL100_FRAME_HEADER frm_header;		/* frame header struct  */
	ULONG	*wtp, *rdp;					/* for RAM access */
	USHORT	size;
	USHORT	i;

	/* Set first command data */
	for(i = 1; i < (chbuffp->ma_max) + 1; i++)
	{
		/* Set frame header data */
		frm_header.str.da = jl100m_read_iomap_member(chbuffp, i, AXIS_ADR);
		frm_header.str.sa = 0x0001;
		frm_header.str.msg_ctrl = 0x0000;
		frm_header.str.ftyp_len = FTYPE_CR | jl100m_read_iomap_member(chbuffp, i, CD_LEN);

		/* Calculate top address of C/R frame buffer */
		wtp = (ULONG *)(adr +  jl100m_get_cbuff_offset(chbuffp,i));

		/* Write frame header data to SRAM area */
		rdp = &frm_header.ulong_ptr;
		size = HEADER_SIZE;
		while(size > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			size -= DWORD_SIZE;
		}

		/* Set FCS data */
		wtp += jl100m_read_iomap_member(chbuffp, i, CD_LEN)>>2;
		*wtp = 0x00000000;
	}
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_read_ram()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Read data from RAM.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		ULONG	*hif_reg_top	:	Host I/F register top address								*/
/*		USHORT	ofst_adr		:	Offset address												*/
/*		USHORT	size			:	Read data size												*/
/*		ULONG	*rdata			:	Read data save buffer										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_INVALID_SIZE		:	Invalid request size.										*/
/*		ERROR_REQ_SIZE_OVER		:	Request size is over RAM area.								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_read_ram(ULONG *hif_reg_top, USHORT ofst_adr, USHORT size, ULONG *rdata)
{
	ULONG	*rdp;				/* for RAM access */
	ULONG	*sram_top_adr;		/* SRAM area top address */

	/* Check request offset and size */
	if((ofst_adr % DWORD_SIZE != 0) || (size % DWORD_SIZE != 0))
	{
		return(ERROR_INVALID_SIZE);
	}
	if((ofst_adr + size) > DEF_SRAM_SIZE)
	{
		return(ERROR_REQ_SIZE_OVER);
	}

	/* Calcurate SRAM area top address */
	sram_top_adr = (ULONG *)((ULONG)hif_reg_top + DEF_SRAM_TOP_ADR);

	/* Read data from SRAM */
	rdp = (ULONG *)((ULONG)sram_top_adr + ofst_adr);
	while(size > 0)
	{
		*rdata = jl100_read_dwdata(rdp);
		rdata++;
		size -= DWORD_SIZE;
	}
	return(LIB_OK);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_write_ram()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Write data from RAM.																	*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		ULONG	*hif_reg_top	:	Host I/F register top address								*/
/*		USHORT	ofst_adr		:	Offset address												*/
/*		USHORT	size			:	Read data size												*/
/*		ULONG	wdata			:	Write data													*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_INVALID_SIZE		:	Invalid request size.										*/
/*		ERROR_REQ_SIZE_OVER		:	Request size is over RAM area.								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_write_ram(ULONG *hif_reg_top, USHORT ofst_adr, USHORT size, ULONG wdata)
{
	ULONG	*wtp;			/* for RAM access */
	ULONG	*sram_top_adr;	/* SRAM area top address */

	/* Check request offset and size */
	if((ofst_adr % DWORD_SIZE != 0) || (size % DWORD_SIZE != 0))
	{
		return(ERROR_INVALID_SIZE);
	}
	if((ofst_adr + size) > DEF_SRAM_SIZE)
	{
		return(ERROR_REQ_SIZE_OVER);
	}

	/* Calcurate RAM area top address */
	sram_top_adr = (ULONG *)((ULONG)hif_reg_top + DEF_SRAM_TOP_ADR);

	/* Write data to RAM */
	wtp = (ULONG *)((ULONG)sram_top_adr + ofst_adr);
	while(size > 0)
	{
		*wtp = wdata;
		wtp++;
		size -= DWORD_SIZE;
	}
	return(LIB_OK);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_activate_comprm()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Activate communication parameter.														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp			:	Channel buffer address								*/
/*		JL100_USER_PAR *usr_parp		:	JL100 user parameter								*/
/*		JL100_USER_IOMAP *usr_iomapp	:	JL100 IOMAP parameter(user setting)					*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK							:	Normal end											*/
/*		ERROR_RAM_SIZE_OVER				:	Using memory size larger than RAM.					*/
/*		ERROR_INVALID_TMCYC				:	Invalid transmite cycle.							*/
/*		ERROR_TOUT_USRPRM_SET			:	User param set request did not completed.			*/
/*		ERROR_INVALID_USRPAR			:	Invalid user setting parameter.						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_activate_comprm(CHANNEL_INFO *chbuffp, JL100_USER_PAR *usr_parp,
                                                    JL100_USER_IOMAP *usr_iomapp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	JL100_COM_PAR com_par;				/* Communication parameter */
	JL100_REG_PAR reg_par;				/* Register parameter */
	short	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Set user parameter & default parameter */
	ret = jl100m_set_usr_param(chbuffp, usr_parp, &reg_par, &com_par);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Write communication parameter */
	ret = jl100m_write_compar(chbuffp, &com_par);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Write IOMAP parameter */
	ret = jl100m_write_iomap(chbuffp, usr_iomapp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Set IDLY regs */
	jl100_set_idly(hirp, reg_par.str.idly);

	/* Request set Communication parameter and IOMAP */
	ret = jl100m_req_set_par(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_read_slvstat()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Read slave status number from IOMAP.													*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT st_no			:	Station number												*/
/*																								*/
/*	Return Code :																				*/
/*		Status number 			:	Normal end													*/
/*		ERROR_INVALID_STNO		:	Request st_no is not exist									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_read_slvstat(CHANNEL_INFO *chbuffp, USHORT st_no)
{
	short ret;							/* Return code */

	/* Check st_no */
	if((st_no > (chbuffp->ma_max)) || (st_no == 0))
	{
		return(ERROR_INVALID_STNO);
	}

	/* Get status number of st_no */
	ret = jl100m_read_iomap_member(chbuffp, st_no, STS_NUM);

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_read_iomap_member()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Read IOMAP member.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	st_no			:	Station number												*/
/*		USHORT	member			:	IOMAP member to be read(Code is follow)						*/
/*																								*/
/*									Member Code	:	Substance									*/
/*									-----------------------------------------------------		*/
/*									AXIS_ADR	:	axis address								*/
/*									T_RSP		:	transmission response monitering time		*/
/*									CD_LEN		:	command length								*/
/*									RD_LEN		:	response length								*/
/*									STS_NUM		:	status number								*/
/*									TR_DLY		:	transmission delay time						*/
/*																								*/
/*	Return Code :																				*/
/*		IOMAP member																			*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
USHORT jl100m_read_iomap_member(CHANNEL_INFO *chbuffp, USHORT st_no, USHORT member)
{
	volatile JL100_HOST_IF_REGS *hirp;			/* Host I/F Top address */
	volatile JL100_IO_MAP_DWORD *iomapp;		/* IOMAP top address */
	DWORD	work;								/* Work */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get IOMAP area top address */
	iomapp = (volatile JL100_IO_MAP_DWORD *)((ULONG)hirp + chbuffp->iomap_ptr);

	switch(member)
	{
		case AXIS_ADR	:	/* Read axis address */
			work.dword = (iomapp + st_no)->dword1;
			return(work.word.lo);

		case T_RSP		:	/* Read transmit response */
			work.dword = (iomapp + st_no)->dword1;
			return(work.word.hi);

		case CD_LEN		:	/* Read command data length */
			work.dword = (iomapp + st_no)->dword2;
			return(work.word.lo);

		case RD_LEN		:	/* Read response data length */
			work.dword = (iomapp + st_no)->dword2;
			return(work.word.hi);

		case STS_NUM	:	/* Read status number */
			work.dword = (iomapp + st_no)->dword3;
			return(work.word.lo);

		case TR_DLY		:	/* Read transmit delay time */
			work.dword = (iomapp + st_no)->dword3;
			return(work.word.hi);

		default			:
			return(LIB_OK);
	}
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_write_iomap_member()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Write IOMAP member.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	st_no			:	Station number												*/
/*		USHORT	member			:	IOMAP member to be read										*/
/*																								*/
/*									Member Code	:	Substance									*/
/*									-----------------------------------------------------		*/
/*									AXIS_ADR	:	axis address								*/
/*									T_RSP		:	transmission response monitering time		*/
/*									CD_LEN		:	command length								*/
/*									RD_LEN		:	response length								*/
/*									STS_NUM		:	status number								*/
/*																								*/
/*		USHORT	data			:	Write data													*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void jl100m_write_iomap_member(CHANNEL_INFO *chbuffp, USHORT st_no, USHORT member, USHORT data)
{
	volatile JL100_HOST_IF_REGS *hirp;			/* Host I/F Top address */
	volatile JL100_IO_MAP_DWORD *iomapp;		/* IOMAP top address */
	DWORD	work;								/* Work */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get IOMAP area top address */
	iomapp = (volatile JL100_IO_MAP_DWORD *)((ULONG)hirp + chbuffp->iomap_ptr);

	switch(member)
	{
		case AXIS_ADR	:	/* Write axis address */
			work.dword = (iomapp + st_no)->dword1;
			work.word.lo = data;
			(iomapp + st_no)->dword1 = work.dword;
			break;

		case T_RSP		:	/* Write transmit response time */
			work.dword = (iomapp + st_no)->dword1;
			work.word.hi = data;
			(iomapp + st_no)->dword1 = work.dword;
			break;

		case CD_LEN		:	/* Write command data length */
			work.dword = (iomapp + st_no)->dword2;
			work.word.lo = data;
			(iomapp + st_no)->dword2 = work.dword;
			break;

		case RD_LEN		:	/* Write response data length */
			work.dword = (iomapp + st_no)->dword2;
			work.word.hi = data;
			(iomapp + st_no)->dword2 = work.dword;
			break;
			
		case STS_NUM	:	/* Write status number */
			work.dword = (iomapp + st_no)->dword3;
			work.word.lo = data;
			(iomapp + st_no)->dword3 = work.dword;
			break;

		default			:
			break;
	}
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_chk_iomap_prm()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Check user setting IOMAP parameters.													*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp			:	Channel buffer address								*/
/*		JL100_USER_IOMAP *usr_iomapp	:	JL100 iomap parameter(user setting)					*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK				:	Normal end														*/
/*		ERROR_IOMAP_SIZE	:	User setting command(or response) length is not arrowed			*/
/*		ERROR_IOMAP_TRSP	:																	*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_chk_iomap_prm(CHANNEL_INFO *chbuffp, JL100_USER_IOMAP *usr_iomapp)
{
	USHORT cd_len, rd_len, ch;			/* Work */
	ULONG  t_rsp_work;					/* Work */
	short  ret;							/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Check command data length and response data length */
	for(ch = 0; ch <= chbuffp->ma_max; ch++)
	{
		cd_len = (usr_iomapp + ch)->cd_len;
		rd_len = (usr_iomapp + ch)->rd_len;
		if(((cd_len!=8) && (cd_len!=16) && (cd_len!=32) && (cd_len!=48) && (cd_len!=64)) ||
           ((rd_len!=8) && (rd_len!=16) && (rd_len!=32) && (rd_len!=48) && (rd_len!=64)))
		{
			return(ERROR_IOMAP_SIZE);
		}
		t_rsp_work = (usr_iomapp + ch)->t_rsp;
		if((t_rsp_work > 6400000) || (t_rsp_work < 500))
		{
			return(ERROR_INVALID_USRPAR);
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_find_max_trdly()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Find max TR_DLY from IOMAP.																*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp			:	Channel buffer address								*/
/*		JL100_USER_IOMAP *usr_iomapp	:	JL100 iomap parameter(user setting)					*/
/*																								*/
/*	Return Code :																				*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
USHORT jl100m_find_max_trdly(CHANNEL_INFO *chbuffp)
{
	USHORT max_trdly, trdly_work;	/*  */
	USHORT st_no;					/*  */

	/* Initialize value */
	max_trdly = trdly_work = 0;

	/* Find max TR_DLY */
	for(st_no = 1; st_no <= chbuffp->ma_max; st_no++)
	{
		trdly_work = jl100m_read_iomap_member(chbuffp, st_no, TR_DLY);
		if(trdly_work > max_trdly)
		{
			max_trdly = trdly_work;
		}
	}
	
	return(max_trdly);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_get_rbuff_offset()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Get receive buffer offset of st_no station.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	st_no			:	Station number												*/
/*																								*/
/*	Return Code :																				*/
/*		USHORT					:	Receive buffer offset of st_no station						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
unsigned short jl100m_get_rbuff_offset(CHANNEL_INFO *chbuffp, USHORT st_no)
{
	USHORT	offset;						/* Responce buffer offset */
	USHORT	i;
	
	/* Calculate offset of st_no station buffer */
	offset = 0;
	offset += SYNC_FRAME_SIZE;			/* #0 reserve area size */
	for(i = 1; i < st_no; i++)
	{
		offset += jl100m_read_iomap_member(chbuffp, i, RD_LEN);		/* responce data length */
		offset += (HEADER_SIZE + FCS_SIZE);	/* header info length */
	}
	return(offset);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_get_cbuff_offset()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Get command buffer offset of st_no station.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	st_no			:	Station number												*/
/*																								*/
/*	Return Code :																				*/
/*		USHORT					:	Command buffer offset of st_no station						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
unsigned short jl100m_get_cbuff_offset(CHANNEL_INFO *chbuffp, USHORT st_no)
{
	USHORT	offset;						/* Command buffer offset */
	USHORT	i;

	/* Calculate offset of st_no station buffer */
	offset = 0;
	offset += SYNC_FRAME_SIZE;			/* #0 sync frame size */
	for(i = 1; i < st_no; i++)
	{
		offset += jl100m_read_iomap_member(chbuffp, i, CD_LEN);		/* command data length */
		offset += (HEADER_SIZE + FCS_SIZE);	/* header info length */
	}
	return(offset);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_download_asicprg()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Download micro program to download SRAM area.											*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		ULONG	*hif_reg_top			:	Host I/F register top address						*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK							:	Normal end											*/
/*		ERROR_VERIFY_MICRO				:	Download micro is not correctly						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_download_asicprg(ULONG *hif_reg_top)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	VULONG   *dl_micro_adr;
	ULONG    *dl_micro_code_tbl;
	LONG     dl_micro_sz;
	ULONG    i, work, micro_code;
	short    ret;
	
	/* Initialize value */
	ret = LIB_OK;
	
	/* Get Host I/F register top address */
	hirp = (JL100_HOST_IF_REGS *)hif_reg_top;
	
	/* Get download SRAM top address */
	dl_micro_adr = (VULONG *)((ULONG)hirp + DEF_DOWNLOAD_SRAM_TOP_ADR);
	
	/* Get micro code table top address & size */
	dl_micro_code_tbl = (ULONG *)AsicUprg;
	dl_micro_sz  = (AsicUprgSz/2 < 0x4000) ? AsicUprgSz/2 : (AsicUprgSz/2 - 1);
	
	/* Download micro code */
	for(i = 0; i < dl_micro_sz; i++)
	{
#ifdef BIG_ENDIAN
		jl100_swap_long_data(dl_micro_code_tbl[i], micro_code);
		dl_micro_adr[i] = micro_code;
#else
		dl_micro_adr[i] = dl_micro_code_tbl[i];
#endif /* BIG_ENDIAN */
	}
	
	/* Verify download micro code */
	for(i = 0; i < dl_micro_sz; i++)
	{
		work = dl_micro_adr[i];
#ifdef BIG_ENDIAN
		jl100_swap_long_data(dl_micro_code_tbl[i], micro_code);
#else
		micro_code = dl_micro_code_tbl[i];
#endif /* BIG_ENDIAN */
		if(work != micro_code)
		{
			return(ERROR_VERIFY_MICRO);
		}
	}
	
	/*  */
	dl_micro_adr[0x1000-1] = 0xFFFFFFFF;
	
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_get_accdrv_ver()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Get access driver version.																*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		Nothing																					*/
/*																								*/
/*	Return Code :																				*/
/*		Access driver version : High byte	Access driver version.								*/
/*								Low  byte	Supported type.										*/
/*											(00h:Slave, 01h:C1master, 02h:C2master)				*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
ULONG jl100m_get_accdrv_ver(void)
{
	ULONG version;
	
	/* Get access driver version */
	version = ACCESS_DRIVER_VERSION;
	
	return(version);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_chk_slv_status()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Check slave status.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp			:	Channel buffer address								*/
/*		ULONG *hif_reg_top				:	Host I/F register top address						*/
/*		JL100_USER_PAR *usr_parp		:	JL100 user parameter								*/
/*		JL100_USER_IOMAP *usr_iomapp	:	JL100 IOMAP parameter(user setting)					*/
/*																								*/
/*	Return Code :																				*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_chk_slv_status( CHANNEL_INFO *chbuffp, ULONG *hif_reg_top, 
                          JL100_USER_PAR *usr_parp, JL100_USER_IOMAP *usr_iomapp )
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	JL100_COM_PAR	com_par;			/* Communication parameter */
	JL100_REG_PAR	reg_par;			/* Register parameter */
	USHORT	st_no, sts_sync, sts, int_cnt, err_cnt, cnt;
	ULONG	data, err, gtim, tout_tim;
	VULONG   *dl_micro_adr;
	short	ret;						/* Return code */

	/* Clear channel buffer, and set top address of Host I/F register */
	jl100m_init_channel(chbuffp, hif_reg_top, usr_iomapp);

	/* Initialize value */
	sts_sync = int_cnt = err_cnt = 0;
	hirp = chbuffp->hif_reg_top;
	tout_tim = (ULONG)SLV_CHK_TOUT_TIME;

	/* Write register parameter */
	reg_par.str.mod = usr_parp->mod;
	reg_par.str.pars = DEF_PARS_ADR;
	reg_par.str.imk = 0;
	reg_par.str.idly = 0;

	/* Request to set register parameter */
	ret = jl100m_set_regpar(chbuffp, &reg_par);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Write user parameter & default parameter */
	com_par.str.ma0			= 0x0001;
	com_par.str.ma_msk0		= 0xFFFF;
	com_par.str.ma1			= 0x0001;
	com_par.str.ma_msk1		= 0xFFFF;
	com_par.str.srch_time	= 0x01F4;
	com_par.str.ma_max		= usr_parp->ma_max;
	com_par.str.t_mcyc		= 0x2710;
	com_par.str.t_unit		= 0x0001;
	com_par.str.prot_sel	= 0x0000;
	com_par.str.max_rtry	= 0x0000;
	com_par.str.msg_ptr		= DEF_MSG_PTR;
	com_par.str.c1msg_sz	= DEF_C1MSG_SZ;
	com_par.str.c2msg_sz	= DEF_C2MSG_SZ;
	com_par.str.pkt_sz		= usr_parp->pkt_sz;
	com_par.str.wdt			= 0x4000;
	com_par.str.c2_dly		= 0x0000;
	com_par.str.dly_cnt		= 0x0001;
	com_par.str.iomap_ptr	= DEF_IOMAP_PTR;
	com_par.str.ifgset		= 0x0000;
	com_par.str.max_frm		= 0x0002;
	com_par.str.reserve1	= 2;
	com_par.str.reserve2	= 0;
	com_par.str.reserve3	= DEF_DLYFRM_WAIT_CNT;
	com_par.str.reserve4	= DEF_DLYAPP_WAIT_CNT;
	com_par.str.async_req_rtry = 0;

	/* Write COM. parameter */
	ret = jl100m_write_compar(chbuffp, &com_par);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Write IOMAP parameter */
	ret = jl100m_write_iomap(chbuffp, usr_iomapp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Request to set communication parameter and IOMAP */
	ret = jl100m_req_set_par(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	for(cnt = 0; cnt < 2; cnt++)
	{
		/* Request to detect slave */
		jl100_set_cmd(hirp, JL100_CMD_DTCT_R);
		jl100_set_cmd(hirp, JL100_CMD_GTIM_RST);
		data = jl100_get_ints(hirp);
		err_cnt = 0;
		while((data & JL100_INTS_DTCT_I) == 0)
		{
			data = jl100_get_ints(hirp);
			err = jl100_get_ests(hirp);
			if((err & JL100_ESTS_TX_ERROR) != 0)
			{
				err_cnt++;
				jl100_clear_ests(hirp, err);
				jl100_set_cmd(hirp, JL100_CMD_DTCT_R);
				jl100_set_cmd(hirp, JL100_CMD_GTIM_RST);
			}
			gtim = jl100_get_gtim(hirp);
			if((gtim > tout_tim) || (err_cnt > 5))
			{
				return(ERROR_TOUT_MODE_SET);
			}
		}
		
		/* Clear INTS */
		if((data & JL100_INTS_DTCT_I) != 0)
		{
			err = jl100_get_ests(hirp);
			if((cnt == 1) && ((err & JL100_ESTS_AXIS_NO_ERR) != 0))
			{
				return(ERROR_SLV_AXIS_NO);
			}
			jl100_clear_ests(hirp, JL100_ESTS_AXIS_NO_ERR);
			jl100_clear_ints(hirp, JL100_INTS_DTCT_I);
		}
	}

	/* Check slave status */
	for(st_no = 1; st_no <= usr_parp->ma_max; st_no++)
	{
		sts = jl100m_read_iomap_member(chbuffp,st_no,STS_NUM);
		if(sts >= SLV_STS_CYCLIC)
		{
			sts_sync = 1;
		}
	}

	if(sts_sync == 1)
	{
		/* Set communication parameter */
		com_par.str.ma_max = 1;
		chbuffp->ma_max = 1;

		/* Write COM. parameter */
		ret = jl100m_write_compar(chbuffp, &com_par);
		if(ret != LIB_OK)
		{
			return(ret);
		}

		/* Request to set communication parameter and IOMAP */
		ret = jl100m_req_set_par(chbuffp);
		if(ret != LIB_OK)
		{
			return(ret);
		}

		/* Set IOMAP parameter */
		jl100m_write_iomap_member(chbuffp, 1, AXIS_ADR, 0xFEEF);
		jl100m_write_iomap_member(chbuffp, 1, CD_LEN, 0x0008);
		jl100m_write_iomap_member(chbuffp, 1, RD_LEN, 0x0008);

		/* Set sync. frame and cyclic frame */
		jl100m_set_first_data(chbuffp);

		/* Set IDLY and protsel */
		jl100_set_idly(hirp, 0xFFFF);

		/* Request to send TMC frame */
		jl100_set_cmd(hirp, JL100_CMD_SCNF_R);
		jl100_set_cmd(hirp, JL100_CMD_GTIM_RST);
		data = jl100_get_ints(hirp);
		err_cnt = 0;
		while((data & JL100_INTS_SCNF_I) == 0)
		{
			data = jl100_get_ints(hirp);
			err = jl100_get_ests(hirp);
			if((err & JL100_ESTS_TX_ERROR) != 0)
			{
				err_cnt++;
				jl100_clear_ests(hirp, err);
				jl100_set_cmd(hirp, JL100_CMD_SCNF_R);
				jl100_set_cmd(hirp, JL100_CMD_GTIM_RST);
			}
			gtim = jl100_get_gtim(hirp);
			if((gtim > tout_tim) || (err_cnt > 5))
			{
				return(ERROR_TOUT_MODE_SET);
			}
		}

		if((data & JL100_INTS_SCNF_I) != 0)
		{
			jl100_clear_ints(hirp, JL100_INTS_SCNF_I);
		}

		/* Request to start sync. communication */
		jl100_set_cmd(hirp, JL100_CMD_C_START_R);
		
		/* Wait 5 transmission cycle. */
		while(int_cnt <= 5)
		{
			data = jl100_get_ints(hirp);
			if((data & JL100_INTS_TIM1) != 0)
			{
				jl100_clear_ints(hirp, JL100_INTS_TIM1);
				int_cnt++;
			}
		}
	}

	/* Reset ASIC */
	jl100m_reset_asic(chbuffp);

	/* Setup ASIC */
	dl_micro_adr = (VULONG *)((ULONG)hirp + DEF_DOWNLOAD_SRAM_TOP_ADR);
	dl_micro_adr[0x1000-1] = 0xFFFFFFFF;
	
	/* Check ASIC ready */
	while((ret = jl100m_chk_asic_ready((ULONG *)hirp)) != LIB_OK)
	{
		;
	}

	return(ret);
}

/************************************************************************************************/
/*																								*/
/*		JL100M_LNK.C : JL-100 interface access driver											*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*		Ver 1.00	:	2007.12.20	Initial coding	T.soeda										*/
/*																								*/
/************************ Copyright(C) 2007 Yaskawa Electric Corporation ************************/
/*																								*/
/*		FUNCTIONS :																				*/
/*			jl100m_change_rbuff()		:	Change toggle buffer(RSP)							*/
/*			jl100m_change_cbuff()		:	Change toggle buffer(CMD).							*/
/*			jl100m_read_ldata()			:	Read cyclic data. (for sync mode)					*/
/*			jl100m_write_ldata()		:	Write cyclic data. (for sync mode)					*/
/*			jl100m_req_rcv_frame()		:	Request receive frame and 							*/
/*												read received frame data.(for async mode)		*/
/*			jl100m_send_frame()			:	Request send frame.(for async mode)					*/
/*			jl100m_get_rrcvstat()		:	Get receive status from RRCV* register.				*/
/*			jl100m_get_stistat()		:	Get  status from STI* register.						*/
/*			jl100m_read_comstat()		:	Get ESTS register.									*/
/*			jl100m_get_cid()			:	Get CID register.									*/
/*			jl100m_get_rbuff_offset()	:	Get receive buffer offset of st_no station.			*/
/*			jl100m_get_cbuff_offset()	:	Get command buffer offset of st_no station.			*/
/*			jl100m_read_frame_header()	:	Get frame header infomation.						*/
/*			jl100m_begin_cyclic_com()	:	Set WD_R(CMD), and clear interrupt factors.			*/
/*			jl100m_chk_intrp_factor()	:	Check interrupt factor.								*/
/*			jl100m_async_rcv_enable()	:	Enable receive frame.(for async mode)				*/
/*																								*/
/************************************************************************************************/

/* includes */
//#include "jl100m_gbl.h"

/* forward declarations */
#ifdef __cplusplus
extern	"C"	{
#endif
short jl100m_change_rbuff(CHANNEL_INFO *chbuffp);
short jl100m_change_cbuff(CHANNEL_INFO *chbuffp);
short jl100m_read_ldata(CHANNEL_INFO *chbuffp, USHORT st_no, ULONG *rbuffp);
short jl100m_write_ldata(CHANNEL_INFO *chbuffp, USHORT st_no, ULONG *sbuffp);
short jl100m_req_rcv_frame(CHANNEL_INFO *chbuffp, USHORT *st_adr, USHORT *rcv_stat, 
											USHORT *ftype, ULONG *rbuffp, USHORT *size, USHORT tout_time);
short jl100m_send_frame(CHANNEL_INFO *chbuffp, USHORT st_adr, USHORT ftype, ULONG *sbuffp, USHORT size);
void jl100m_get_rrcvstat(CHANNEL_INFO *chbuffp, ULONG *rcvstat);
void jl100m_get_stistat(CHANNEL_INFO *chbuffp, ULONG *stistat);
unsigned long jl100m_read_comstat(CHANNEL_INFO *chbuffp);
short jl100m_get_cid(CHANNEL_INFO *chbuffp);
short jl100m_begin_cyclic_com(CHANNEL_INFO *chbuffp);
unsigned long jl100m_chk_intrp_factor(CHANNEL_INFO *chbuffp);
void jl100m_async_rcv_enable(CHANNEL_INFO *chbuffp);

#ifdef __cplusplus
}
#endif



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_change_rbuff()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Change toggle buffer(RSP).																*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_TOUT_CHANG_RBUFF	:	Change response buffer didn't complete						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_change_rbuff(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	data;						/* Register read data */
	ULONG	i;							/* Polling counter */
	short	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Request change receive buffer */
	jl100_set_cmd(hirp, JL100_CMD_RBX_R);

	/* Wait change receive buffer complete */
	ret = ERROR_TOUT_CHANG_RBUFF;
	for(i = 0; i < JL100_CMD_POLLING_CNT; i++)
	{
		data = jl100_get_cmd(hirp);
		if((data & JL100_CMD_RBX_R) == 0)
		{
			ret = LIB_OK;
			break;
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_change_cbuff()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Change toggle buffer(CMD).																*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_TOUT_CHANG_CBUFF	:	Change command buffer didn't complete						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_change_cbuff(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	data;						/* Register read data */
	ULONG	i;							/* Polling counter */
	short	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Request change receive buffer */
	jl100_set_cmd(hirp, JL100_CMD_CBX_R);

	/* Wait change command buffer complete */
	ret = ERROR_TOUT_CHANG_CBUFF;
	for(i = 0; i < JL100_CMD_POLLING_CNT; i++)
	{
		data = jl100_get_cmd(hirp);
		if((data & JL100_CMD_CBX_R) == 0)
		{
			ret = LIB_OK;
			break;
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_read_ldata()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Read cyclic data. (for sync mode)														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	st_no			:	Station number to be read									*/
/*		ULONG	*rbuffp			:	Response data save buffer									*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_INVALID_STNO		:	Setting st_no is not exist									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_read_ldata(CHANNEL_INFO *chbuffp, USHORT st_no, ULONG *rbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	rbadr;						/* Responce buffer address */
	ULONG	*rdp, *wtp;					/* for RAM access */
	USHORT	size_buf;					/* Responce data length from IOMAP */
	short	ret;						/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Check st_no */
	if((st_no > (chbuffp->ma_max)) || (st_no == 0))
	{
		return(ERROR_INVALID_STNO);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get response data length */
	size_buf = jl100m_read_iomap_member(chbuffp, st_no, RD_LEN);

	/* Data length check */
	if((size_buf != 8) && (size_buf != 16) && (size_buf != 32) && (size_buf != 48) && (size_buf != 64))
	{
		return(ERROR_IOMAP_SIZE);
	}

	/* Get receive buffer offset address */
	rbadr = ((ULONG)hirp + DEF_SRAM_TOP_ADR);
	rbadr += (USHORT)jl100_get_rbadr(hirp);
	rbadr += (chbuffp->usr_iomap + st_no)->rspbuff_offset;
	rbadr += HEADER_SIZE;

	/* Read receive data */
	rdp = (ULONG *)rbadr;
	wtp = rbuffp;
	while(size_buf > 0)
	{
		*wtp = jl100_read_dwdata(rdp);
		wtp++;
		size_buf -= DWORD_SIZE;
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_write_ldata()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Write cyclic data. (for sync mode)														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	st_no			:	Station number to be read									*/
/*		ULONG	*sbuffp			:	Send data save buffer										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_INVALID_STNO		:	Setting st_no is not exist									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_write_ldata(CHANNEL_INFO *chbuffp, USHORT st_no, ULONG *sbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	cbadr;						/* Command buffer address */
	ULONG	*rdp, *wtp;					/* for RAM access */
	USHORT	size_buf;					/* Command data length from IOMAP */
	short	ret;						/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Check st_no */
	if((st_no > (chbuffp->ma_max)) || (st_no == 0))
	{
		return(ERROR_INVALID_STNO);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get command data length from IOMAP */
	size_buf = jl100m_read_iomap_member(chbuffp, st_no, CD_LEN);

	/* Data length check */
	if((size_buf != 8) && (size_buf != 16) && (size_buf != 32) && (size_buf != 48) && (size_buf != 64))
	{
		return(ERROR_IOMAP_SIZE);
	}

	/* Get command buffer offset address */
	cbadr = ((ULONG)hirp + DEF_SRAM_TOP_ADR);
	cbadr += (USHORT)jl100_get_cbadr(hirp);
	cbadr += (chbuffp->usr_iomap + st_no)->cmdbuff_offset;
	cbadr += HEADER_SIZE;

	/* Write command data */
	rdp = sbuffp;
	wtp = (ULONG *)cbadr;
	while(size_buf > 0)
	{
		jl100_write_dwdata(wtp, rdp);
		size_buf -= DWORD_SIZE;
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_req_rcv_frame()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Request receive frame.																	*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address.										*/
/*		USHORT *st_adr			:	Station address save buffer pointer.						*/
/*		USHORT *rcv_stat		:	Receive status save buffer pointer.							*/
/*		USHORT *ftype			:	Frame type save buffer pointer.								*/
/*		ULONG  *rbuffp			:	Receive data save buffer pointer.							*/
/*		USHORT *size			:	Receive data size save buffer pointer.						*/
/*		USHORT tout_time		:	Receive time-out time setting.								*/
/*																								*/
/*	Return Code :																				*/
/*		RCVING_FRAME			:	Waiting receive frame.										*/
/*		RECEIVED_FRAME			:	Received frame.												*/
/*		ERROR_ASYNC_FTYPE		:	Invalid ftype.												*/
/*																								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_req_rcv_frame(CHANNEL_INFO *chbuffp, USHORT *st_adr, USHORT *rcvstat, 
												USHORT *ftype, ULONG *rbuffp, USHORT *size, USHORT tout_time)
{
	volatile JL100_HOST_IF_REGS *hirp;		/* Host I/F Top address */
	JL100_FRAME_HEADER_ASYNC frm_header;	/* Frame header struct */
	ULONG	rbadr;							/* Responce buffer address */
	ULONG	*rdp, *wtp;						/* for RAM access */
	ULONG	data;							/* Register read data */
	ULONG	work;
	USHORT	size_buff;
	short	ret;							/* Return code */
	
	/* Initialize value */
	ret = RCVING_FRAME;
	
	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;
	
	/* Get CMD register */
	data = jl100_get_cmd(hirp);
	
	if((data & JL100_CMD_RX_R) != 0)
	{
		/* Waiting receive frame */
		return(RCVING_FRAME);
	}
	else
	{
		/* Not request receive frame */
		data = jl100_get_ints(hirp);
		if((data & JL100_INTS_RX_I) != 0)
		{
			/* Received frame */
			ret = RECEIVED_FRAME;
			jl100_clear_ints(hirp, JL100_INTS_RX_I);

			/* Get receive buffer offset address */
			rbadr = (ULONG)((ULONG)hirp + DEF_SRAM_TOP_ADR);
			rbadr += (chbuffp->pars_data - DEF_SRAM_TOP_ADR) >> 1;

			/* Read header data */
			rdp = (ULONG *)rbadr;
			wtp = &frm_header.ulong_ptr;
			size_buff = ASYNC_HEADER_SIZE;
			while(size_buff > 0)
			{
				*wtp = jl100_read_dwdata(rdp);
				wtp++;
				size_buff -= DWORD_SIZE;
			}
			/* Save source address */
			*st_adr = frm_header.str.sa;
			/* Save receive status */
			*rcvstat = frm_header.str.stat;
			/* Save frame type */
			*ftype = (frm_header.str.ftyp_len >> 12) & 0x000f;
			/* Save data size */
			*size = frm_header.str.ftyp_len & 0x0fff;
			
			/* Receive timeout check */
			if(*rcvstat == ASYNC_RCV_TIMOUT)
			{
				return(ret);
			}
			
			/* Check frame type */
			if((*ftype != 0x02) && (*ftype != 0x0C))
			{
				return(ERROR_ASYNC_FTYPE);
			}
			
			/* Read receive data */
			rdp = (ULONG *)(rbadr + ASYNC_HEADER_SIZE);
			wtp = rbuffp;
			size_buff = *size;
			while(size_buff > 0)
			{
				*wtp = jl100_read_dwdata(rdp);
				wtp++;
				size_buff -= DWORD_SIZE;
			}
		}
		else
		{
			/* Set response monitering time */
			/* Get receive buffer offset address */
			rbadr = (ULONG)((ULONG)hirp + DEF_SRAM_TOP_ADR);
			rbadr += (chbuffp->pars_data - DEF_SRAM_TOP_ADR) >> 1;
			work = tout_time;
			wtp = (ULONG *)rbadr;
			*wtp |= work;
			
			/* Request receive frame */
			jl100_set_cmd(hirp, JL100_CMD_RX_R);
			ret = RCVING_FRAME;
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_send_frame()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Send frame data. (for async mode)														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	st_adr			:	Station address to be read									*/
/*		USHORT	ftype			:	Frame type													*/
/*		USHORT	*sbuffp			:	Send data buffer											*/
/*		USHORT	size			:	Send data size												*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		SNDING_FRAME			:	Sending frame												*/
/*		ERROR_INVALID_SIZE		:	Invalid size												*/
/*		ERROR_INVALID_FTYPE		:	Invalid ftype												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_send_frame(CHANNEL_INFO *chbuffp, USHORT st_adr, USHORT ftype, ULONG *sbuffp, USHORT size)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	JL100_FRAME_HEADER_ASYNC frm_header;/* Frame header struct */
	ULONG	cbadr;						/* Command buffer address */
	ULONG	*rdp, *wtp;					/* for RAM access */
	ULONG	data;						/* Register read data */
	USHORT	size_buff;
	short	ret;						/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Check frame type and size */
	if((ftype != 0x02) && (ftype != 0x0c))
	{
		ret = ERROR_INVALID_FTYPE;
	}
	if((size % DWORD_SIZE) != 0)
	{
		ret = ERROR_INVALID_SIZE;
	}

	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get CMD register */
	data = jl100_get_cmd(hirp);

	/* Check transmit request */
	if((data & JL100_CMD_TX_R) != 0)
	{
		ret = SNDING_FRAME;
	}
	else
	{
		/* Not request send frame */
		data = jl100_get_ints(hirp);
		if((data & JL100_INTS_TX_I) != 0)
		{
			/* Sent frame */
			ret = LIB_OK;
			jl100_clear_ints(hirp, JL100_INTS_TX_I);
		}
		
		/* Set frame header data */
		frm_header.str.t_rsp = 0xffff;
		frm_header.str.stat = 0x0000;
		frm_header.str.da = st_adr;
		frm_header.str.sa = 0x0001;
		frm_header.str.msg_ctrl = 0x0000;
		frm_header.str.ftyp_len =  (ftype << 12) | (size & 0x0fff);

		/* Get command buffer address offset */
		cbadr = (ULONG)((ULONG)hirp + DEF_SRAM_TOP_ADR);

		/* Write frame header data to SRAM area */
		rdp = &frm_header.ulong_ptr;
		wtp = (ULONG *)cbadr;
		size_buff = ASYNC_HEADER_SIZE;
		while(size_buff > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			size_buff -= DWORD_SIZE;
		}

		/* Write send data */
		rdp = sbuffp;	/* Set send data buffer pointer */
		while(size > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			size -= DWORD_SIZE;
		}

		/* Request transmit data */
		jl100_set_cmd(hirp, JL100_CMD_TX_R);
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_get_rrcvstat()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Get receive status from RRCV* register.													*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		ULONG	*rcvstat		:	Receive status save buffer									*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void jl100m_get_rrcvstat(CHANNEL_INFO *chbuffp, ULONG *rrcvstat)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get receive status */
	rrcvstat[0] = jl100_get_rrcv1(hirp);
	rrcvstat[1] = jl100_get_rrcv2(hirp);

}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_get_stistat()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Get  status from STI* register.															*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		ULONG	*stistat		:	Connection status save buffer								*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void jl100m_get_stistat(CHANNEL_INFO *chbuffp, ULONG *stistat)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get connection status */
	stistat[0] = jl100_get_sti1(hirp);
	stistat[1] = jl100_get_sti2(hirp);

}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_read_comstat()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Get ESTS register.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		LIB_NG					:	ESTS														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
unsigned long jl100m_read_comstat(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get ESTS register */
	ret = jl100_get_ests(hirp);

	/* Clear ESTS register */
	jl100_clear_ests(hirp, ret);

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_get_cid()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Get CID register .																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*																								*/
/*	Return Code :																				*/
/*		cid						:	Chip ID														*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_get_cid(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	short	ret;						/* Return code */

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get CID register */
	ret = (USHORT)jl100_get_cid(hirp);

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_begin_cyclic_com()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Set WD_R(CMD), and clear interrupt factors.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp		:	Channel buffer address									*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK						:	Normal end												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_begin_cyclic_com(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	short   ret;						/* Return code */
	
	/* Initialize value */
	ret = LIB_OK;

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;
	
	/* Set WD */
	jl100_set_cmd(hirp, JL100_CMD_WD_R);
	
	/* Clear interrupt factor */
	jl100_clear_ints(hirp, JL100_INTS_TIM1);
	
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_chk_intrp_factor()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Check interrupt factor.																	*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp		:	Channel buffer address									*/
/*																								*/
/*	Return Code :																				*/
/*		INTS regs.																				*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
unsigned long jl100m_chk_intrp_factor(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	ints;						/* for register read */
	
	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get INTS register */
	ints = jl100_get_ints(hirp);
	
	return(ints);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_async_rcv_enable()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Enable receive frame (for async mode).													*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp		:	Channel buffer address									*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void jl100m_async_rcv_enable(CHANNEL_INFO *chbuffp)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	
	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Receive enable */
	jl100_set_cmd(hirp, JL100_CMD_RX_R);
}

/************************************************************************************************/
/*																								*/
/*		JL100M_MSG.C : JL-100 interface access driver											*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*		Ver 1.00	:	2007.12.20	Initial coding	T.soeda										*/
/*																								*/
/************************ Copyright(C) 2007 Yaskawa Electric Corporation ************************/
/*																								*/
/*		FUNCTIONS :																				*/
/*			jl100m_req_rcv_msgdata()	:	Request receive message data.						*/
/*			jl100m_req_snd_msgdata()	:	Request send message data.							*/
/*			jl100m_abort_msgdata()		:	Request abort message communication.				*/
/*			jl100m_read_msgdata()		:	Read message data.									*/
/*			jl100m_write_msgdata()		:	write message data.									*/
/*																								*/
/************************************************************************************************/

/* includes */
//#include "jl100m_gbl.h"

/* forward declarations */
#ifdef __cplusplus
extern	"C"	{
#endif
short jl100m_req_rcv_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT st_adr, USHORT *msg_size);
short jl100m_req_snd_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT st_adr, USHORT msg_size);
short jl100m_abort_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg);
short jl100m_read_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT offset, USHORT size, ULONG *rdata);
short jl100m_write_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT offset, USHORT size, ULONG *sdata);
#ifdef __cplusplus
}
#endif


/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_req_rcv_msgdata()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Request receive message data.															*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	cnmsg			:	Select C1 or C2												*/
/*		USHORT	st_adr			:	Station address												*/
/*		USHORT	*msg_size		:	Message data size											*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Complete receive message data								*/
/*		RCVING_MSG				:	In receiving message data									*/
/*		ERROR_MSG_ABORT			:	Message communication aborted								*/
/*		ERROR_MSG_OVERFLOW		:	Message data size over flow									*/
/*		ERROR_BUSY_MSG			:	Message communication rejected								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_req_rcv_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT st_adr, USHORT *msg_size)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	JL100_FRAME_HEADER_MSG frm_header;	/* Message frame header struct */
	ULONG	cmd, cmd_msk;				/* CMD register */
	ULONG	ints, ints_msk;				/* INTS register */
	ULONG	msg_adr;					/* Message receive buffer offset address */
	ULONG	*rdp, *wtp;					/* for RAM access */
	USHORT	size_buff;
	short	ret;						/* Return code */

	/* Initialize value */
	ret = LIB_OK;

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Check C1 or C2 */
	if(cnmsg == DEF_C1_MST)
	{
		cmd_msk = JL100_CMD_C1MRX_R;
		ints_msk = JL100_INTS_C1MRX_I;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr + chbuffp->c1msg_sz;
	}
	else
	{
		cmd_msk = JL100_CMD_C2MRX_R;
		ints_msk = JL100_INTS_C2MRX_I;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr + (chbuffp->c1msg_sz << 1) + chbuffp->c2msg_sz;
	}

	/* Get CMD register */
	cmd = jl100_get_cmd(hirp);
	
	if((cmd & cmd_msk) != 0)	/* In receiving message */
	{
		return(RCVING_MSG);
	}

	/* Get INTS register */
	ints = jl100_get_ints(hirp);

	if((ints & ints_msk) != 0)	/* Receive message complete */
	{
		/* Clear interrupt factor */
		jl100_clear_ints(hirp, ints_msk);

		/* Get header data */
		rdp = (ULONG *)msg_adr;
		wtp = &frm_header.ulong_ptr;
		size_buff = sizeof(JL100_FRAME_HEADER_MSG);
		while(size_buff > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			size_buff -= DWORD_SIZE;
		}

		/* Set message size */
		*msg_size = (frm_header.str.ftyp_len & 0x0fff);

		/* Check receive status */
		if(frm_header.str.stat == MSG_OVERFLOW)
		{
			ret = ERROR_MSG_OVERFLOW;
		}
		else if(frm_header.str.stat == MSG_ABORT)
		{
			ret = ERROR_MSG_ABORT;
		}
		else if(frm_header.str.stat == MSG_BUSY)
		{
			ret = ERROR_BUSY_MSG;
		}

		return(ret);
	}

	if(cnmsg == DEF_C1_MST)
	{
		/* Write station address */
		wtp  = (ULONG *)(msg_adr + 4);
		*wtp = (ULONG)st_adr << 16;
	}
	/* Request receive message data */
	jl100_set_cmd(hirp, cmd_msk);

	return(RCVING_MSG);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_req_snd_msgdata()																*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Request send message data.																*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	cnmsg			:	Select C1 or C2												*/
/*		USHORT	st_adr			:	Station address												*/
/*		USHORT	*msg_size		:	Message data size											*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Complete send message data									*/
/*		SNDING_MSG				:	In sending message data										*/
/*		ERROR_MSG_ABORT			:	Message communication aborted								*/
/*		ERROR_MSG_UNDERFLOW		:	Message data size under flow								*/
/*		ERROR_BUSY_MSG			:	Message communication rejected								*/
/*		ERROR_MSG_DIV_OVER		:	Message division over										*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_req_snd_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT st_adr, USHORT msg_size)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	JL100_FRAME_HEADER_MSG frm_header;	/* Message frame header struct */
	ULONG	cmd, cmd_msk;				/* CMD register */
	ULONG	ints, ints_msk;				/* INTS register */
	ULONG	msg_adr;					/* Message receive buffer offset address */
	ULONG	*rdp, *wtp;					/* for RAM access */
	USHORT	my_st_adr;					/* My station address */
	USHORT	st_no;						/* Station number */
	USHORT	size_buff;
	USHORT	t_rsp_work;					/* transmit monitering time */
	USHORT	pkt_size;
	short	ret;						/* Return code */

	/* Initialize value */
	ret = SNDING_MSG;

	if(msg_size > chbuffp->pkt_sz)
	{
		pkt_size = chbuffp->pkt_sz;
	}
	else
	{
		pkt_size = msg_size;
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Get messege buffer pointer */
	if(cnmsg == DEF_C1_MST)
	{
		cmd_msk = JL100_CMD_C1MTX_R;
		ints_msk = JL100_INTS_C1MTX_I;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr;
		my_st_adr = chbuffp->ma0;
	}
	else
	{
		cmd_msk = JL100_CMD_C2MTX_R;
		ints_msk = JL100_INTS_C2MTX_I;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr + (chbuffp->c1msg_sz << 1);
		my_st_adr = chbuffp->ma0;
	}

	/* Get CMD register */
	cmd = jl100_get_cmd(hirp);
	
	if((cmd & cmd_msk) != 0)	/* In receiving message */
	{
		return(SNDING_MSG);
	}

	/* Get INTS register */
	ints = jl100_get_ints(hirp);

	/* Sending messege complete */
	if((ints & ints_msk) != 0)
	{
		ret = LIB_OK;
		/* Clear interrupt factor */
		jl100_clear_ints(hirp, ints_msk);
		
		/* Get header data */
		rdp = (ULONG *)msg_adr;
		wtp = &frm_header.ulong_ptr;
		size_buff = sizeof(JL100_FRAME_HEADER_MSG);
		while(size_buff > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			size_buff -= DWORD_SIZE;
		}
		
		/* Check send status */
		if(frm_header.str.stat == MSG_SND_ABORT)
		{
			ret = ERROR_MSG_ABORT;
		}
		else if(frm_header.str.stat == MSG_UNDERFLOW)
		{
			ret = ERROR_MSG_UNDERFLOW;
		}
		else if(frm_header.str.stat == MSG_SND_BUSY)
		{
			ret = ERROR_BUSY_MSG;
		}
		else if(frm_header.str.stat == MSG_DIV_OVER)
		{
			ret = ERROR_MSG_DIV_OVER;
		}
		
		return(ret);
	}

	/* Get station number */
	for(st_no = 0; st_no <= chbuffp->ma_max; st_no++)
	{
		if(jl100m_read_iomap_member(chbuffp, st_no, AXIS_ADR) == st_adr)
		{
			break;
		}
		else if(st_adr == 0x0002)	/* C2master */
		{
			st_no = 63;
			break;
		}
	}

	/* Calculate transmit monitering time */
	t_rsp_work = (jl100m_read_iomap_member(chbuffp, st_no, TR_DLY) << 1);
	if(chbuffp->t_unit == TUNIT_10NSEC)
	{
		t_rsp_work += 2400;
		if(pkt_size > 64)
		{
			t_rsp_work += ((pkt_size - 64) << 3);
		}
	}
	else if(chbuffp->t_unit == TUNIT_100NSEC)
	{
		t_rsp_work += 240;
		if(pkt_size > 64)
		{
			t_rsp_work += (((pkt_size - 64) << 3) / 10);
		}
	}
	else
	{
		t_rsp_work += 24;
		if(pkt_size > 64)
		{
			t_rsp_work += (((pkt_size - 64) << 3) / 100);
		}
	}
	
	/* Set header data */
	frm_header.str.reserve = t_rsp_work;				/* Set transmit monitering time */
	frm_header.str.stat    = 0x0000;					/* Set transmit status(set by JL100) */
	frm_header.str.da      = st_adr;					/* Set destination address */
	frm_header.str.sa      = my_st_adr;					/* Set source address */
	frm_header.str.msg_ctrl= 0x0000;					/* Set message control(set by JL100) */
	frm_header.str.ftyp_len= (FTYPE_MSG | msg_size);	/* Set frame type and data length */

	/* Write header data */
	rdp = &frm_header.ulong_ptr;
	wtp = (ULONG *)msg_adr;
	size_buff = sizeof(JL100_FRAME_HEADER_MSG);
	while(size_buff > 0)
	{
		jl100_write_dwdata(wtp, rdp);
		size_buff -= DWORD_SIZE;
	}

	/* Request send message data */
	jl100_set_cmd(hirp, cmd_msk);

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_abort_msgdata()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Request abort send/receive message data.												*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	cnmsg			:	Select C1 or C2												*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_ABT_MSG			:	Abort message did not completed.							*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_abort_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg)
{
	volatile JL100_HOST_IF_REGS *hirp;			/* Host I/F Top address */
	ULONG	cmd_abt;							/* CMD register */
	ULONG	ints, ints_msk;						/* INTS register */
	ULONG	i;									/* Polling counter */
	short	ret;								/* Return code */

	/* Initialize value */
	ret = ERROR_ABT_MSG;

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	if(cnmsg == DEF_C1_MST)
	{
		cmd_abt = JL100_CMD_C1ABT_R;
		ints_msk = JL100_INTS_C1ABT_I;
	}
	else
	{
		cmd_abt = JL100_CMD_C2ABT_R;
		ints_msk = JL100_INTS_C2ABT_I;
	}

	/* Request abort Cn message communication */
	jl100_set_cmd(hirp, cmd_abt);

	/* Wait abort Cn message communication complete */
	for(i = 0; i < JL100_CMD_POLLING_CNT; i++)
	{
		ints = jl100_get_ints(hirp);
		if((ints & ints_msk) != 0)
		{
			ret = LIB_OK;
			/* Clear interrupt factor */
			jl100_clear_ints(hirp, ints_msk);
			break;
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_read_msgdata()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Read message data.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	cnmsg			:	Select C1 or C2												*/
/*		USHORT	offset			:	Offset address to be read									*/
/*		USHORT	size			:	Size to be read												*/
/*		ULONG	*rdata			:	Receive message save buffer									*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_INVALID_SIZE		:	Invalid size												*/
/*		ERROR_REQ_MSG_SIZE		:	Request size is over message buffer area.					*/
/*		ERROR_RCVING_MSG		:	In requesting receive message data							*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_read_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT offset, USHORT size, ULONG *rdata)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	msg_adr;					/* Message receive buffer offset address */
	ULONG	offset_adr;					/* Offset address */
	ULONG	*wtp, *rdp;					/* for RAM access */
	ULONG	cmd, cmd_msk;				/* CMD register */
	USHORT	msg_size;					/* Message size */
	short	ret;						/* Return code */

	/* Check request offset and size */
	if((offset % DWORD_SIZE != 0) || (size % DWORD_SIZE != 0))
	{
		return(ERROR_INVALID_SIZE);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Check C1 or C2 */
	if(cnmsg == DEF_C1_MST)
	{
		cmd_msk = JL100_CMD_C1MRX_R;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr + chbuffp->c1msg_sz + sizeof(JL100_FRAME_HEADER_MSG);
		msg_size = chbuffp->c1msg_sz;
	}
	else
	{
		cmd_msk = JL100_CMD_C2MRX_R;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr + (chbuffp->c1msg_sz << 1) +chbuffp->c2msg_sz
                                                                     + sizeof(JL100_FRAME_HEADER_MSG);
		msg_size = chbuffp->c2msg_sz;
	}

	/* Check message size and offset */
	if((offset + size) > msg_size)
	{
		return(ERROR_REQ_MSG_SIZE);
	}

	/* Get CMD register */
	cmd = jl100_get_cmd(hirp);
	if((cmd & cmd_msk) == 0)
	{
		/* Calculate offset of message receive buffer */
		offset_adr = msg_adr + offset;

		/* Get message data */
		rdp = (ULONG *)offset_adr;
		wtp = rdata;
		while(size > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			size -= DWORD_SIZE;
		}
		ret = LIB_OK;
	}
	else
	{
		ret = ERROR_RCVING_MSG;
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		jl100m_write_msgdata()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Write message data.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*		CHANNEL_INFO *chbuffp	:	Channel buffer address										*/
/*		USHORT	cnmsg			:	Select C1 or C2												*/
/*		USHORT	offset			:	Offset address to be write									*/
/*		USHORT	size			:	Size to be write											*/
/*		ULONG	*sdata			:	Send message data buffer									*/
/*																								*/
/*	Return Code :																				*/
/*		LIB_OK					:	Normal end													*/
/*		ERROR_INVALID_SIZE		:	Invalid size												*/
/*		ERROR_REQ_MSG_SIZE		:	Request size is over message buffer area.					*/
/*		ERROR_SNDING_MSG		:	In requesting send message data								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short jl100m_write_msgdata(CHANNEL_INFO *chbuffp, USHORT cnmsg, USHORT offset, USHORT size, ULONG *sdata)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	ULONG	msg_adr;					/* Message receive buffer offset address */
	ULONG	offset_adr;					/* Offset address */
	ULONG	*wtp, *rdp;					/* for RAM access */
	ULONG	cmd, cmd_msk;				/* CMD register */
	USHORT	msg_size;					/* Message size */
	short	ret;						/* Return code */

	/* Check request offset and size */
	if((offset % DWORD_SIZE != 0) || (size % DWORD_SIZE != 0))
	{
		return(ERROR_INVALID_SIZE);
	}

	/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	/* Check C1 or C2 */
	if(cnmsg == DEF_C1_MST)
	{
		cmd_msk = JL100_CMD_C1MTX_R;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr + sizeof(JL100_FRAME_HEADER_MSG);
		msg_size = chbuffp->c1msg_sz;
	}
	else
	{
		cmd_msk = JL100_CMD_C2MTX_R;
		msg_adr = (ULONG)hirp + chbuffp->msg_ptr + (chbuffp->c1msg_sz << 1) + sizeof(JL100_FRAME_HEADER_MSG);
		msg_size = chbuffp->c2msg_sz;
	}

	/* Check message size and offset */
	if((offset + size) > msg_size)
	{
		return(ERROR_REQ_MSG_SIZE);
	}

	/* Get CMD register */
	cmd = jl100_get_cmd(hirp);
	if((cmd & cmd_msk) == 0)
	{
		/* Calculate offset of message send buffer */
		offset_adr = msg_adr + offset;

		/* Get message data */
		rdp = sdata;
		wtp = (ULONG *)offset_adr;
		while(size > 0)
		{
			jl100_write_dwdata(wtp, rdp);
			size -= DWORD_SIZE;
		}
		ret = LIB_OK;
	}
	else
	{
		ret = ERROR_SNDING_MSG;
	}

	return(ret);
}

/************************************************************************************************/
/*																								*/
/*		JL-100 sample programs for C1 Master													*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*		This file contains following sample programs; 											*/
/*		 (1) mst_init(void)																		*/
/*					: JL-100 initialization for MECHATROLINK-III.								*/
/*		 (2) mst_exchange_sync(void)															*/
/*					: Send/recieve data processing for cyclic communication(sync. mode).		*/
/*		 (3) mst_exchange_async(void)															*/
/*					: Send/recieve data processing for cyclic communication(async. mode).		*/
/*		 (4) mst_exchange_msg(void)																*/
/*					: Send/recieve data processing for message communication.					*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*		These sample programs are made under the following conditions;							*/
/*			Number of Slaves				: 8													*/
/*			Transmission Cycle				: 500 usec											*/
/*			JL-100 register start address	: 0x0F800000										*/
/*			Sync. communication data size	: 48 [bytes]										*/
/*			Max. number of Retries			: 1													*/
/*			Message communication data size	: 64 [bytes]										*/
/*			Async. communication data size	: 64 [bytes]										*/
/*																								*/
/*																								*/
/*		Please refer to the following document for more detials.								*/
/*       "MECHATROLINK-III JL-100 Access Driver Instructions for C1 Master Station"				*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*		Ver 1.00	:	2007.12.20	Initial coding	T.soeda										*/
/*																								*/
/**************************************** Copyright(C) 2007 Yaskawa Electric Corporation ********/

/* includes */
//#include "jl100m_gbl.h"
//#include "smpl_par.h"

/* defines */
//#define HOST_IF_REGS_PTR		0x0f800000		/* JL-100 register start address */
ULONG * HOST_IF_REGS_PTR;
#define ASYNC_SND_SEQ			0				/*  */
#define ASYNC_RCV_SEQ			1				/*  */
#define MSG_SND_SEQ				0				/*  */
#define MSG_RCV_SEQ				1				/*  */

/* Error code definitions */
#define ERROR_MEASURE_TRANSDLY	(-1)			/* Some slave could not complete measure transmission delay time */
#define ERROR_ASIC_STATUS		(-2)			/* Some error occured in ASIC */
#define ERROR_SRAM_CHECK		(-3)			/* SRAM read/write check error */

/* globals */
/* User setting parameter */
CHANNEL_INFO		chbuff;						/* Channel Buffer */
JL100_USER_PAR		usr_par;					/* Communication Parameters */
JL100_USER_IOMAP	usr_io_map[DEF_MA_MAX+2];	/* IO MAP Parameters */

/* Buffer */
ULONG	lnk_sbuff[DEF_MA_MAX+1][(DEF_CD_LEN >> 2)];	/* Send Buffer */
ULONG	lnk_rbuff[DEF_MA_MAX+1][(DEF_RD_LEN >> 2)];	/* Receive Buffer */
ULONG	c1msg_sbuff[(DEF_C1MSG_SIZE >> 2)];			/* Send buffer for C1message com. */
ULONG	c1msg_rbuff[(DEF_C1MSG_SIZE >> 2)];			/* Receive buffer for C1message com. */
ULONG	c2msg_sbuff[(DEF_C2MSG_SIZE >> 2)];			/* Send buffer for C2message com. */
ULONG	c2msg_rbuff[(DEF_C2MSG_SIZE >> 2)];			/* Receive buffer for C2message com. */
ULONG	async_sbuff[(DEF_ASYNC_DATA_SIZE >> 2)];	/* Send Buffer for async com. */
ULONG	async_rbuff[(DEF_ASYNC_DATA_SIZE >> 2)];	/* Receive Buffer for async com. */

/* Work for user setting */
USHORT	c1snd_msgsz;				/* Send message data size buffer */
USHORT	c1rcv_msgsz;				/* Receive message data size buffer */
USHORT	c2snd_msgsz;				/* Send message data size buffer */
USHORT	c2rcv_msgsz;				/* Receive message data size buffer */
USHORT	async_rcv_stadr;			/* Receive frame source address of async com. buffer */
USHORT	async_rcv_ftype;			/* Receive frame type of async com. buffer */
USHORT	async_rcv_size;				/* Receive data size of async com. buffer */
USHORT	async_sw;					/* Async. communication sequence flag */
USHORT	msg_sw;						/* Message communication sequence flag */

/* Status */
USHORT	c1msg_rcv_stat;				/* C1 message receive status */
USHORT	c1msg_snd_stat;				/* C1 message send status */
USHORT	c2msg_rcv_stat;				/* C2 message receive satatus */
USHORT	c2msg_snd_stat;				/* C2 message send status */
USHORT	async_rcv_stat;				/* Async. communication receive status */

/* Forward declarations */
short mst_init(void);								/* Initialize MECHATROLINK communicaiton(Setup JL-100) */
short mst_exchange_sync(void);						/* Send/Recieve Link data in cyclic communication(sync mode) */
short mst_exchange_async(void);						/* Send/Recieve Link data with async mode */
short mst_exchange_msg(void);						/* Send/Recieve message data */
void set_usr_prm(JL100_USER_PAR* usr_par, JL100_USER_IOMAP* usr_iomapp);		
													/* Set user parameter */
short check_ram(ULONG *hif_reg_top, USHORT size, ULONG chkdata);
													/* SRAM read/write check */

/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		mst_init()																				*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Initialize MECHATROLINK communicaiton(Setup JL-100).									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short mst_init(void)
{
	CHANNEL_INFO*		chbuffp;		/* Channel Buffer */
	USHORT				st_no;			/* Counter */
	ULONG				sti[2];			/* Connection status */
	short				ret;			/* return code */

	/* Initialize value */
	ret = WAIT_SETUP;
	async_sw = ASYNC_SND_SEQ;
	msg_sw = MSG_SND_SEQ;

	/* Get the pointer of Channel Buffer */
	chbuffp = &chbuff;

	/* Setup ASIC */
	while(ret == WAIT_SETUP)
	{
		ret = jl100m_setup_asic((ULONG *)HOST_IF_REGS_PTR);
		if(ret == LIB_OK)
		{
			break;
		}
		else if(ret == ERROR_VERIFY_MICRO)
		{
			return(ret);
		}
	}

	/* Check ASIC ready */
	while((ret = jl100m_chk_asic_ready((ULONG *)HOST_IF_REGS_PTR)) != LIB_OK)
	{
		;
	}

	/* Check JL100 SRAM area */
	ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0x5a5a5a5a);
	if(ret != LIB_OK)
	{
		return(ret);
	}
	
	ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0xa5a5a5a5);
	if(ret != LIB_OK)
	{
		return(ret);
	}
	
	ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0xffffffff);
	if(ret != LIB_OK)
	{
		return(ret);
	}
	
	ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Set user parameters */
	set_usr_prm(&usr_par, usr_io_map);

	/* JL-100 Initialization */
	ret = jl100m_initialize( chbuffp, (ULONG *)HOST_IF_REGS_PTR, &usr_par, usr_io_map );
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Excute detect connecting slave */
	ret = jl100m_req_detect_slv(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}
	
	/* Check complete detect connecting slave */
	while((ret = jl100m_chk_detect_slv_cmp(chbuffp)) != LIB_OK)
	{
		if(ret == ERROR_TX_FRM)
		{
			ret = jl100m_req_detect_slv(chbuffp);
			if(ret != LIB_OK)
			{
				return(ret);
			}
		}
		else if(ret != WAIT_CMP_DETECT)
		{
			return(ret);
		}
	}

	for(st_no = 1; st_no <= chbuffp->ma_max; st_no++)
	{
		if(jl100m_read_slvstat(chbuffp, st_no) < STSNUM_WAIT_MEASURE_DLY)
		{
			/* Add the codes for your product specification */
		}
	}

	/* Activate user setting parameter */
	ret = jl100m_activate_comprm(chbuffp, &usr_par, usr_io_map);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Excute measure transmission delay time */
	ret = jl100m_req_measure_transdly(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Check complete measure transmit delay time */
	while((ret = jl100m_chk_transdly_cmp(chbuffp)) != LIB_OK)
	{
		if(ret == ERROR_TX_FRM)
		{
			ret = jl100m_req_measure_transdly(chbuffp);
			if(ret != LIB_OK)
			{
				return(ret);
			}
		}
		else if(ret != MEASURING_TRANSDLY)
		{
			return(ret);
		}
	}

	jl100m_get_stistat(chbuffp, sti);
	for(st_no = 1; st_no <= chbuffp->ma_max; st_no++)
	{
		if(st_no < 32)
		{
			if(((sti[0] >> st_no) & 0x0001) != 0)
			{
				if(jl100m_read_slvstat(chbuffp, st_no) != STSNUM_WAIT_TMCFRM)
				{
					/* Add the codes for your product specification */
				}
			}
		}
		else
		{
			if(((sti[1] >> (st_no - 32)) & 0x0001) != 0)
			{
				if(jl100m_read_slvstat(chbuffp, st_no) != STSNUM_WAIT_TMCFRM)
				{
					/* Add the codes for your product specification */
				}
			}
		}
	}

	/* Calculate response monitoring time and interrupt delay time */
	ret = jl100m_calc_dlytime(chbuffp, &usr_par, usr_io_map);
	if(ret != LIB_OK)
	{
		return(ret);
	}


	/* Activate user setting parameter */
	ret = jl100m_activate_comprm(chbuffp, &usr_par, usr_io_map);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Inform communication mode to slave and C2 master */
	ret = jl100m_infm_cmode(chbuffp);
	if(ret != LIB_OK)
	{
		return(ret);
	}

	/* Check complete inform communication mode and slave status */
	while((ret = jl100m_chk_infm_cmode_cmp(chbuffp)) != LIB_OK)
	{
		if(ret == ERROR_INFM_CMODE)
		{
			jl100m_get_stistat(chbuffp, sti);
			for(st_no = 1; st_no <= chbuffp->ma_max; st_no++)
			{
				if(st_no < 32)
				{
					if(((sti[0] >> st_no) & 0x0001) != 0)
					{
						if((chbuffp->prot_sel == 0) && (jl100m_read_slvstat(chbuffp, st_no) == STSNUM_WAIT_DLY_APPFRM))
						{
							/* Add the codes for your product specification */
						}
					}
				}
				else
				{
					if(((sti[1] >> (st_no - 32)) & 0x0001) != 0)
					{
						if((chbuffp->prot_sel == 0) && (jl100m_read_slvstat(chbuffp, st_no) == STSNUM_WAIT_DLY_APPFRM))
						{
							/* Add the codes for your product specification */
						}
					}
				}
			}
			if(chbuffp->prot_sel == 0)
			{
				/* Retry to inform communication mode to slave and C2 master */
				ret = jl100m_infm_cmode(chbuffp);
				if(ret != LIB_OK)
				{
					return(ret);
				}
			}
			else
			{
				return(ret);
			}
		}
		else if(ret == ERROR_TX_FRM)
		{
			ret = jl100m_infm_cmode(chbuffp);
			if(ret != LIB_OK)
			{
				return(ret);
			}
		}
	}

	/* Start cyclic communication */
	if(chbuffp->prot_sel == COM_MODE_SYNC)
	{
		ret = jl100m_start_sync(chbuffp);
		if(ret != LIB_OK)
		{
			return(ret);
		}
	}
	else
	{
		ret = jl100m_start_async(chbuffp);
		if(ret != LIB_OK)
		{
			return(ret);
		}
	}

	return ret;
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		mst_exchange_sync()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Send/recieve data processing.(sync communication mode)									*/
/*			-Copy received data from JL100 response buffer to lnk_rbuff,						*/
/*		 	-and copy send data from lnk_sbuff to JL100 command buffer.							*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short mst_exchange_sync(void)
{
	CHANNEL_INFO*	chbuffp;			/* Channel Buffer */
	ULONG			rrcvstat[2];		/* Receive status */
	ULONG			ests;				/* Error Status */
	USHORT			st_no;				/* Counter */
	short			ret;				/* Return code */

	/* Initialize value */
	ret = OK;

	/* Get the pointer of Channel Buffer */
	chbuffp = &chbuff;

	/* Start cyclic communication */
	jl100m_begin_cyclic_com(chbuffp);

	/* Check JL100 status */
	ests = jl100m_read_comstat(chbuffp);

	/* Toggle response buffer */
	if((ret = jl100m_change_rbuff(chbuffp)) != LIB_OK)
	{
		return(ret);
	}

	/* Toggle command buffer */
	if((ret = jl100m_change_cbuff(chbuffp)) != LIB_OK)
	{
		return(ret);
	}

	/* Get receive status */
	jl100m_get_rrcvstat(chbuffp, rrcvstat);

	/* Receive Process for all stations(slaves) */
	for(st_no = 1; st_no <= chbuffp->ma_max; st_no++)
	{
		if(st_no < 32)
		{
			if(((rrcvstat[0] >> st_no) & 0x0001) == 0)
			{
				/* Not received response data */
				if(ests != 0)
				{
					/* Add the codes for your product specification */
				}
				continue;
			}
		}
		else
		{
			if(((rrcvstat[1] >> (st_no - 32)) & 0x0001) == 0)
			{
				/* Not received response data */
				if(ests != 0)
				{
					/* Add the codes for your product specification */
				}
				continue;
			}
		}

		/* Receive [JL-100 -> buffer] */
		ret = jl100m_read_ldata(chbuffp, st_no, lnk_rbuff[st_no]);
		if(ret != LIB_OK)
		{
			return(ret);
		}
	}

	/* Add the codes for your product specification */

	/* Send Process for all stations(slaves) */
	for(st_no = 1; st_no <= chbuffp->ma_max; st_no++)
	{
		if(st_no < 32)
		{
			if(((rrcvstat[0] >> st_no) & 0x0001) == 0)
			{
				/* Not received response data */
				continue;
			}
		}
		else
		{
			if(((rrcvstat[1] >> (st_no - 32)) & 0x0001) == 0)
			{
				/* Not received response data */
				continue;
			}
		}

		/* Send [buffer -> JL-100] */
		ret = jl100m_write_ldata(chbuffp, st_no, lnk_sbuff[st_no]);
		if(ret != LIB_OK)
		{
			return(ret);
		}
	}

	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		mst_exchange_async()																	*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Send/recieve data processing.(async communication mode.)								*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short mst_exchange_async(void)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	CHANNEL_INFO*	chbuffp;			/* Channel Buffer */
	ULONG			ests;				/* Error Status */
	ULONG			ret;				/* return code */

	/* Initialize value */
	ret = OK;

	/* Set pointer of Channel Buffer */
	chbuffp = &chbuff;
	hirp = chbuffp->hif_reg_top;

	/* Request send async frame */
	if(async_sw == ASYNC_SND_SEQ)
	{
		ret = jl100m_send_frame(chbuffp, DEF_ASYNC_PEER_ADR, DEF_ASYNC_FTYPE, async_sbuff, DEF_ASYNC_DATA_SIZE);
		if(ret == LIB_OK)
		{
			async_sw = ASYNC_RCV_SEQ;
		}
		else if(ret != SNDING_FRAME)
		{
			return(ret);
		}
	}
	
	/* Request receive async frame */
	if(async_sw == ASYNC_RCV_SEQ)
	{
		ret = jl100m_req_rcv_frame(chbuffp, &async_rcv_stadr, &async_rcv_stat, &async_rcv_ftype, async_rbuff, &async_rcv_size, (USHORT)DEF_ASYNC_RCV_TOUT_TIME);
		if(ret == RECEIVED_FRAME)
		{
			async_sw = ASYNC_SND_SEQ;
			if((async_rcv_stat == ASYNC_RCV_CMP) || (async_rcv_stat == ASYNC_RCV_TIMOUT))
			{
				/* Add the codes for your product specification */
				jl100m_read_comstat(chbuffp);
			}
			else
			{
				/* Check JL100 status */
				if((ests = jl100m_read_comstat(chbuffp)) != 0)
				{
					/* Add the codes for your product specification */
					return(ERROR_ASIC_STATUS);
				}
				return(async_rcv_stat);
			}
		}
		else if(ret != RCVING_FRAME)
		{
			return(ret);
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		mst_exchange_msg()																		*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Send/recieve data processing.(message communication)									*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short mst_exchange_msg(void)
{
	volatile JL100_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	CHANNEL_INFO	*chbuffp;			/* Channel Buffer */
	USHORT			offset;				/*  */
	USHORT			ret ;				/* return code */

	/* Initialize value */
	ret = OK;

	/* Set pointer of Channel Buffer */
	chbuffp = &chbuff;
	hirp = chbuffp->hif_reg_top;

	/* Set send message data size & offset */
	offset = 0;
	
	/* Message send sequence */
	if(msg_sw == MSG_SND_SEQ)
	{
		/* Set send data */
		ret = jl100m_write_msgdata(chbuffp, DEF_C1_MST, offset, DEF_C1MSG_SIZE, c1msg_sbuff);
		if(ret != LIB_OK)
		{
			return(ret);
		}

		/* Request send message data */
		while((c1msg_snd_stat = jl100m_req_snd_msgdata(chbuffp, DEF_C1_MST, C1MSG_PEER_ADR, DEF_C1MSG_SIZE)) == SNDING_MSG){ ;};
		if((c1msg_snd_stat == ERROR_MSG_ABORT) || (c1msg_snd_stat == ERROR_BUSY_MSG))
		{
			msg_sw = MSG_SND_SEQ;
		}
		else
		{
			msg_sw = MSG_RCV_SEQ;
		}

		return(c1msg_snd_stat);
	}
	
	/* Message receive sequence */
	else if(msg_sw == MSG_RCV_SEQ)
	{
		/* Request receive message data */
		if((c1msg_rcv_stat = jl100m_req_rcv_msgdata(chbuffp, DEF_C1_MST, C1MSG_PEER_ADR, &c1rcv_msgsz)) == RCVING_MSG)
		{
			return(c1msg_rcv_stat);
		}
		if(c1msg_rcv_stat == ERROR_BUSY_MSG)
		{
			msg_sw = MSG_RCV_SEQ;
		}
		else
		{
			msg_sw = MSG_SND_SEQ;
		}

		/* Get received messaged data */
		if(c1msg_rcv_stat == LIB_OK)
		{
			ret = jl100m_read_msgdata(chbuffp, DEF_C1_MST, offset, c1rcv_msgsz, c1msg_rbuff);
			if(ret != LIB_OK)
			{
				return(ret);
			}
		}
	}
	return(ret);
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		set_usr_prm()																			*/
/*																								*/
/*	Function Abstruct:																			*/
/*		Set user parameter.																		*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
void set_usr_prm(JL100_USER_PAR	*usr_parp, JL100_USER_IOMAP* usr_iomapp)
{
	USHORT ch;

	/* set default user parameter setting */
	usr_parp->mod = JL100_MOD_TYPE_C1MST | JL100_MOD_INT_FR;
	usr_parp->ma0 = 0x0001;					/* My Address(C1 Master:0x0001) */
	usr_parp->ma_max = DEF_MA_MAX;
	usr_parp->t_mcyc = DEF_TMCYC;			/* Transmission cycle[10nsec] */
	usr_parp->prot_sel = DEF_PROT_SEL;		/* sync mode */
	usr_parp->max_rtry = DEF_MAX_RTRY;		/* Max. number of Retries per Transmission cycle */
	usr_parp->wdt = DEF_WDT;				/* Watch dog timer [8usec]; if wdt=0, WDT function disabled */
	usr_parp->c2_dly = DEF_C2_DLY;			/* C2 delay time */
	usr_parp->pkt_sz = DEF_PKT_SZ;
	usr_parp->dly_cnt = 1;					/* System parameter ("1" fix) */
	usr_parp->intoffset = DEF_INT_OFFSET;	/* Interrupt offset time [10nsec] */
	
	/* Set IOMAP parameters(C1 master) */
	usr_iomapp->axis_adr = 0x0001;			/* Station address */
	usr_iomapp->t_rsp = 1000;				/* Transmission response monitering time [10nsec] */
	usr_iomapp->cd_len = 8;					/* Commando data length */
	usr_iomapp->rd_len = 8;					/* Response data length */
	/* Set IOMAP parameters(slave) */
	for(ch = 1; ch <= usr_parp->ma_max; ch++)
	{
		(usr_iomapp+ch)->axis_adr = 0x20 + ch;	/* Station address */
		(usr_iomapp+ch)->t_rsp = DEF_TRSP;		/* Transmission response monitering time [10nsec] */
		(usr_iomapp+ch)->cd_len = DEF_CD_LEN;	/* Command data length */
		(usr_iomapp+ch)->rd_len = DEF_RD_LEN;	/* Response data length */
	}
	
	/* Set IOMAP parameters(C2 master) */
	(usr_iomapp+(usr_parp->ma_max + 1))->axis_adr = 0x0002;	/* Station address */
	(usr_iomapp+(usr_parp->ma_max + 1))->t_rsp = DEF_TRSP;	/* Transmission response monitering time [10nsec] */
	(usr_iomapp+(usr_parp->ma_max + 1))->cd_len = 0;
	(usr_iomapp+(usr_parp->ma_max + 1))->rd_len = 0;
}



/************************************************************************************************/
/*																								*/
/*	Function Name :																				*/
/*		check_ram()																				*/
/*																								*/
/*	Function Abstruct:																			*/
/*		SRAM read/write check.																	*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Parameter :																					*/
/*																								*/
/*	Return Code :																				*/
/*		Non																						*/
/*																								*/
/*==============================================================================================*/
/*																								*/
/*	Note	:																					*/
/*																								*/
/*	Log		:																					*/
/*																								*/
/************************************************************************************************/
short check_ram(ULONG *hif_reg_top, USHORT size, ULONG chkdata)
{
	ULONG	work;
	USHORT	ofst, ret;
	
	/* Initialize value */
	ofst = 0;
	ret = OK;

	ret = jl100m_write_ram((ULONG *)HOST_IF_REGS_PTR, 0, size, chkdata);
	if(ret != LIB_OK)
	{
		return(ret);
	}
	
	while(ofst < DEF_SRAM_SIZE)
	{
		ret = jl100m_read_ram((ULONG *)HOST_IF_REGS_PTR, ofst, 4, &work);
		if(ret != LIB_OK)
		{
			return(ret);
		}
		if(work != chkdata)
		{
			return(ERROR_SRAM_CHECK);
		}
		ofst = ofst + 4;
	}
	return(ret);
}

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

#define PULSE_CH_NUM		16

#define PULSE_BUFFER_SIZE	4

#define CYCLE_INC(d)	(((d)+1)&(PULSE_BUFFER_SIZE-1))
#define IS_CYCLE_BUFFER_FULL(buffer)	(CYCLE_INC((buffer).head) == ((buffer).tail))
#define IS_CYCLE_BUFFER_EMPTY(buffer)	((buffer).head == (buffer).tail)

#define DEVICE_NAME		"jl101"

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
	uint16_t	dir;
}fpga_pulse_t;

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
	unsigned int irq;

	unsigned int offset;
	unsigned int interrupt_lost;
	unsigned int pulse_queue_break;
	struct miscdevice io_miscdev;
	struct miscdevice axis_io_miscdev;
	struct miscdevice pulse_miscdev;
};

static struct rbt_info *rbt_info_p;

static inline void jl101_writew(struct rbt_info *info,
		uint16_t val, unsigned int off)
{
	__raw_writew(val, info->iobase + off);
}

static inline uint16_t jl101_readw(struct rbt_info *info,
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
static ssize_t jl101_get_freq(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	//return sprintf(buf, "%ld\n", RBT_CLK/(pprd+1)/(tprd+1));
	return sprintf(buf, "");
}

static ssize_t jl101_set_freq(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	unsigned long freq;
	int err;

	err = strict_strtol(buf, 10, &freq);
	if (err)
		return -EINVAL;

	return count;
}

static ssize_t jl101_get_address(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "0x%x\n", info->offset);
}

static ssize_t jl101_set_address(struct device *dev,
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

static ssize_t jl101_get_data(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "0x%x:0x%x\n", info->offset, jl101_readw(info, info->offset));
}

static ssize_t jl101_set_data(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	unsigned long val;
	int err;

	err = strict_strtol(buf, 0, &val);
	if (err)
		return -EINVAL;

	jl101_writew(info, val, info->offset);

	return count;
}

static ssize_t jl101_regdump(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	unsigned long i, n=0;
	for(i=0;i<info->iosize/2;i++){
		if((i&0x7)==0)
			n += sprintf(buf+n, "0x%04lx: ", i);
		n += sprintf(buf+n, "0x%04x", jl101_readw(info, i));
		if((i&0x7)==7)
			n += sprintf(buf+n, "\n");
		else
			n += sprintf(buf+n, ",");
	}

	return n;
}

static ssize_t jl101_errordump(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct rbt_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "interrupt lost: %d\npulse queue break: %d\nmax break tick: %d\n", 
		info->interrupt_lost, info->pulse_queue_break, info->max_break_time);
}

static DEVICE_ATTR(freq, S_IWUSR | S_IRUGO,jl101_get_freq, jl101_set_freq);
static DEVICE_ATTR(address, S_IWUSR | S_IRUGO, jl101_get_address, jl101_set_address);
static DEVICE_ATTR(data, S_IWUSR | S_IRUGO, jl101_get_data, jl101_set_data);
static DEVICE_ATTR(regdump, S_IWUSR | S_IRUGO, jl101_regdump, NULL);
static DEVICE_ATTR(error, S_IWUSR | S_IRUGO, jl101_errordump, NULL);

static struct attribute *jl101_attrs[] = {
	&dev_attr_freq.attr,
	&dev_attr_address.attr,
	&dev_attr_data.attr,
	&dev_attr_regdump.attr,
	&dev_attr_error.attr,
	NULL
};

static const struct attribute_group jl101_sysfs_files = {
	.attrs	= jl101_attrs,
};

static irqreturn_t jl101_irq_handler(int irq, struct rbt_info *info)
{
	unsigned long flags;
	uint16_t rbtsys;
	fpga_pulse_t *pulse;

	raw_spin_lock_irqsave(&info->lock,flags);
	pulse = GetPulseData(info);

	if(pulse){
		//write pulse into FPGA
		// TODO
		//
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

	raw_spin_unlock_irqrestore(&info->lock,flags);

	// Clear interrupt flag
	// TODO
	//jl101_writew(info, 0x1, RBT_INT_OFFSET);

	// Check interrput lost
	// TODO
	/*
	rbtsys = jl101_readw(info, RBT_SYS_OFFSET);
	if(rbtsys&(1<<3)){
		if(info->interrupt_lost<100 || (info->interrupt_lost%100)==0)
			printk("interrput lost %d\n", info->interrupt_lost);
		info->interrupt_lost++;
		rbtsys &=~(1<<3);
		jl101_writew(info, rbtsys, RBT_SYS_OFFSET);
	}
	*/
	
	return IRQ_HANDLED;
}


static inline void jl101_push_pulse(struct rbt_info *info, 
	fpga_pulse_t *pulse, int32_t *data)
{
	int i;
	uint16_t dir=0;
	int32_t d;
	for(i=0;i<info->frame_size;i++){
		d = data[i];
		if(d<0){
			d = -d;
			dir |= (1<<i);
			pulse->period[i] = info->prd_cnt/d;
		}
		else if(d>0){
			pulse->period[i] = info->prd_cnt/d;
		}
		pulse->count[i] = d;
	}
	pulse->dir = dir<<8;
}

static ssize_t jl101_pulse_write(struct file *file, const char __user *buf,
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

	// 
	jl101_push_pulse(info, pulse, (int32_t*)pulse_data);
	raw_spin_unlock_irqrestore(&info->lock,flags);
	
	return count;
}

static const struct file_operations pulse_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= noop_llseek,
	.write		= jl101_pulse_write,
};

static int __init jl101_init_pulse(struct rbt_info *info)
{
	int ret;

	if(request_irq(info->irq, (irq_handler_t)jl101_irq_handler, 
		IRQF_TRIGGER_LOW|IRQF_NO_THREAD|IRQF_DISABLED|IRQF_NOBALANCING|IRQF_NO_SOFTIRQ_CALL, DEVICE_NAME, info)<0){
		printk("RBT FPGA request irq %d failed!\n", info->irq);
		return -ENXIO;
	}

	/* Setup the miscdevice */
	info->pulse_miscdev.minor = MISC_DYNAMIC_MINOR;
	info->pulse_miscdev.name = "jl101pulse";
	info->pulse_miscdev.fops = &pulse_fops;

	ret = misc_register(&info->pulse_miscdev);
	if(ret<0){
		printk("Failed to register fpga io device\n");
		free_irq(info->irq, info);
		return ret;
	}

	return 0;
}

#define IO_NUM_MAX	256
#define FPGA_COMMON_IO_OFF	13

static ssize_t jl101_io_read(struct file *file, 
	char __user *buf, size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;

	int i;
	uint16_t tbuf[IO_NUM_MAX/2];

	if(count>(IO_NUM_MAX))
		return -EINVAL;

	// Read actual IO Data
	// TODO
	//for(i=0;i<(count/2);i++)
	//	tbuf[i] = jl101_readw(info, RBT_INPUT_OFFSET+FPGA_COMMON_IO_OFF+i);
	copy_to_user(buf, tbuf, count);

	return count;
}

static ssize_t jl101_io_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	/*
	 * The miscdevice layer puts our struct miscdevice into the
	 * filp->private_data field. We use this to find our private
	 * data and then overwrite it with our own private structure.
	 */
	struct rbt_info *info = rbt_info_p;
	
	int i;
	uint16_t tbuf[IO_NUM_MAX/2];

	if(count>(IO_NUM_MAX))
		return -EINVAL;

	copy_from_user(tbuf, buf, count);
	// Write actual IO Data
	// TODO
	//for(i=0;i<IO_NUM_16BYTE;i++)
	//	jl101_writew(info, tbuf[i], RBT_OUTPUT_OFFSET+FPGA_COMMON_IO_OFF+i);

	return count;
}

static const struct file_operations io_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= noop_llseek,
	.read		= jl101_io_read,
	.write		= jl101_io_write,
};

static ssize_t rbt_axis_io_read(struct file *file, 
	char __user *buf, size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;
	
	return count;
}

static ssize_t rbt_axis_io_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	struct rbt_info *info = rbt_info_p;
	
	return count;
}

static const struct file_operations axis_io_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= default_llseek,
	.read		= rbt_axis_io_read,
	.write		= rbt_axis_io_write,
};

static int __init jl101_init_io(struct rbt_info *info)
{
	int ret;

	/* Setup the miscdevice */
	info->io_miscdev.minor = MISC_DYNAMIC_MINOR;
	info->io_miscdev.name = "jl101io";
	info->io_miscdev.fops = &io_fops;

	info->axis_io_miscdev.minor = MISC_DYNAMIC_MINOR;
	info->axis_io_miscdev.name = "jl101axisio";
	info->axis_io_miscdev.fops = &axis_io_fops;
	
	rbt_info_p = info;
	
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

	return 0;
}

static int __init jl101_probe(struct platform_device *pdev)
{
	struct rbt_info *info;
	struct resource *res;
	uint32_t v;
	int err;
	int ret = 0, i;	/* return code */

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
	info->iosize=IO_NUM_MAX;//resource_size(res);

	err = platform_get_irq(pdev, 0);
	if(err<0)
		goto fail_no_rbt_fpga;
	info->irq = err;

	HOST_IF_REGS_PTR=(ULONG*)(info->iobase);

	// Check chip ID
	v = jl101_readw(info, 0x0D);
	v = v << 16;
	v = v | jl101_readw(info, 0x0C);
	if(v!=0x0000100A){
		err = -ENXIO;
		printk("Can't find jl101 Chip ret=0x%x!\n", v);
		goto fail_no_rbt_fpga;
	}
	printk("jl101 Chip ID=0x%08x\n", v);

	/* Check JL100 SRAM area */
	for(i=0;i<5;i++) {
		ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0x5a5a5a5a);
		if(ret != LIB_OK)
		{
			err = -ENXIO;
			printk("jl101 ram cheaking 0x5a5a5a5a faile@cycle%d, step1, error coed: %d!\n",i,ret);
			//goto fail_no_rbt_fpga;
		} else {printk("jl101 ram cheaking 0x5a5a5a5a success@cycle%d, step1\n",i);}
	
		ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0xa5a5a5a5);
		if(ret != LIB_OK)
		{
			err = -ENXIO;
			printk("jl101 ram cheaking 0xa5a5a5a5 faile@cycle%d, step2, error coed: %d!\n",i,ret);
			//goto fail_no_rbt_fpga;
		} else {printk("jl101 ram cheaking 0xa5a5a5a5 success@cycle%d, step2\n",i);}
	
		ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0xffffffff);
		if(ret != LIB_OK)
		{
			err = -ENXIO;
			printk("jl101 ram cheaking 0xffffffff faile@cycle%d, step4, error coed: %d!\n",i,ret);
			//goto fail_no_rbt_fpga;
		} else {printk("jl101 ram cheaking 0xffffffff success@cycle%d, step4\n",i);}
	
		ret = check_ram((ULONG *)HOST_IF_REGS_PTR, DEF_SRAM_SIZE, 0x00000000);
		if(ret != LIB_OK)
		{
			err = -ENXIO;
			printk("jl101 ram cheaking 0x00000000 faile@cycle%d, step5, error coed: %d!\n",i,ret);
			//goto fail_no_rbt_fpga;
		} else {printk("jl101 ram cheaking 0x00000000 success@cycle%d, step5\n",i);}
	}

	err = jl101_init_pulse(info);
	if(err<0)
		goto fail_no_rbt_fpga;

	err = jl101_init_io(info);
	if(err<0)
		goto fail_no_rbt_fpga;

	err = sysfs_create_group(&pdev->dev.kobj, &jl101_sysfs_files);
	if (err)
		goto fail_no_sysfs;

	platform_set_drvdata(pdev, info);

	dev_info(&pdev->dev, "jl101@0x%x irq(%d)\n", res->start, info->irq);

	return 0;

	sysfs_remove_group(&pdev->dev.kobj, &jl101_sysfs_files);
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

static int __exit jl101_remove(struct platform_device *pdev)
{
	struct rbt_info *info = platform_get_drvdata(pdev);
	struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	free_irq(info->irq, info);
	platform_set_drvdata(pdev, NULL);
	sysfs_remove_group(&pdev->dev.kobj, &jl101_sysfs_files);
	iounmap(info->iobase);
	release_mem_region(res->start, resource_size(res));
	kfree(info);

	return 0;
}

static struct of_device_id of_jl101_match[] = {
	{
		.compatible	= "yaskawa,jl101",
	},
	{ },
};
MODULE_DEVICE_TABLE(of, of_jl101_match);

static struct platform_driver jl101_driver = {
	.driver		= {
		.name	= DEVICE_NAME,
		.owner	= THIS_MODULE,
		.of_match_table = of_jl101_match,
	},
	.probe		= jl101_probe,
	.remove		= __exit_p(jl101_remove),
};

static int __init jl101_init(void)
{
	return platform_driver_register(&jl101_driver);
}

static void __exit jl101_exit(void)
{
	platform_driver_unregister(&jl101_driver);
}

late_initcall(jl101_init);
module_exit(jl101_exit);

MODULE_DESCRIPTION("jl101 driver");
MODULE_LICENSE("GPL");

