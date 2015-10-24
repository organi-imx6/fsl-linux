/*
 *  Yaskawa JL098 driver
 */

/****************************************************************************/
/*                  JL-098 sample programs for C1 Master                    */
/*                                                                          */
/*    This file contains sample programs of                                 */
/*      (1) mst_init(void) : JL-098 initialization for MECHATROLINK-II,     */
/*      (2) mst_exchange(void) : Send/recieve data processing.              */
/*                                                                          */
/*    These sample programs are made under the following conditions;        */
/*                   Number of Slaves : 7                                   */
/*                 Transmission Cycle : 1 msec                              */
/*                Communication Cycle : 1 msec                              */
/*      JL-098 register start address : 0xDE000000                          */
/*                        packet size : 32 [bytes]                          */
/*             Max. number of Retries : 1                                   */
/*            Time slot for C2 Master : 1(use)                              */
/*                                                                          */
/*    Please refer to the following document for more detials.              */
/*       "MECHATROLINK-II JL-098 Access Driver Instructions                 */
/*                                            for Master Station"           */
/*                                                                          */
/*    == IMPORTANT ==                                                       */
/*      The interface registers of the JL-098                               */
/*      handle unsigned short data in the sample programs.                  */
/*      When using an implementation in which unsigned short data is not    */
/*      16 bits, it will be necessary to change the part of the source code */
/*      that accesses the interface registers.                              */
/*                                                                          */
/*                                          Yaskawa Electric Corporation    */
/*                                                                          */
/****************************************************************************/


/* includes */
//#include "jl098gbl.h"
/*file*********** MELNK_DRV : ***********************************************/
/*                                                                          */
/*                                                                          */
/*        JL098GBR.H : Common header of JL-098 access driver                */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*       [Defines]                                                          */
/*          Definetion of Host Interface registers                          */
/*                                                                          */
/*                                                                          */
/******** Copyright(C) 2007 Yaskawa Electric Corporation ********************/
/*                                                                          */
/*      Ver 1.00    2007.02.28   Initial coding    T.Soeda                  */
/*                                                                          */
/****************************************************************************/

//#include "jl098def.h"
/*file*********** MELNK_DRV : ***********************************************/
/*                                                                          */
/*                                                                          */
/*        JL098DEF.H : Common header of JL-098 access driver                */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*       [Defines]                                                          */
/*          Definetion of Host Interface registers                          */
/*                                                                          */
/*                                                                          */
/******** Copyright(C) 2007 Yaskawa Electric Corporation ********************/
/*                                                                          */
/*      Ver 1.00    2007.02.28   Initial coding    T.Soeda                  */
/*                                                                          */
/****************************************************************************/
#ifndef		YENETDEF_H_
#define		YENETDEF_H_

/***********************************************************************/
/*   Type macro                                                        */
/***********************************************************************/
#ifndef         SHORT
typedef		short          SHORT;
#endif       /* SHORT */
#ifndef         USHORT
typedef		unsigned short USHORT;
#endif       /* USHORT */
#ifndef         LONG
typedef		long           LONG;
#endif       /* LONG */
#ifndef         ULONG
typedef		unsigned long  ULONG;
#endif       /* ULONG */
#ifndef         VOID
typedef		void           VOID;
#endif       /* VOID */
#ifndef         INT
typedef		int            INT;
#endif       /* int */
#ifndef         UINT
typedef		unsigned int   UINT;
#endif       /* UINT */
#ifndef         UCHAR
typedef		unsigned char   UCHAR;
#endif       /* UCHAR */

#ifndef		NULL
#define 	NULL	((void *)0)
#endif       /* NULL */

#ifndef		TRUE
#define		TRUE	1
#endif		/* TRUE */
#ifndef		FALSE
#define		FALSE	0
#endif		/* FALSE */

/************************************************************************/
/*      HOST I/F register bit pattern definition                        */
/************************************************************************/

/* CMD regs */
#define	YN_CMD_C1MTX_R		0x0001
#define YN_CMD_C2MTX_R		0x0002
#define YN_CMD_PAR_R		0x0004
#define YN_CMD_C1MRX_R		0x0008
#define YN_CMD_C2MRX_R		0x0010
#define YN_CMD_WD_R			0x0020
#define YN_CMD_LTX_RA		0x0040
#define YN_CMD_LTX_RB		0x0080
#define YN_CMD_ENA_CER		0x0100
#define YN_CMD_P_RSTRQ		0x0400
#define YN_CMD_C1ABT_R		0x0800
#define YN_CMD_C2ABT_R		0x1000
#define YN_CMD_RST_CER		0x8000

/* STS regs */
#define YN_STS_LTX_UA		0x0040
#define YN_STS_LTX_UB		0x0080
#define YN_STS_RDY			0x2000
#define YN_STS_ERRL			0x4000
#define YN_STS_ERR			0x8000

/* intS, IMK regs */
#define YN_INTS_C1MTX_I		0x0001
#define YN_INTS_C2MTX_I		0x0002
#define YN_INTS_PAR_I		0x0004
#define YN_INTS_C1MRX_I		0x0008
#define YN_INTS_C2MRX_I		0x0010
#define YN_INTS_TXEN_I		0x0020
#define YN_INTS_TXST_I		0x0040
#define YN_INTS_P_RSTAK		0x0400
#define	YN_INTS_TIM1		0x1000
#define YN_INTS_TIM1D		0x2000
#define YN_INTS_SFR			0x8000

/* ESTS regs */
#define YN_ESTS_CRC_ERR		0x0001
#define YN_ESTS_ABT_ERR		0x0002
#define YN_ESTS_PAR_ERR		0x0004
#define YN_ESTS_TMCYCOVR	0x0008
#define YN_ESTS_ALG_ERR		0x0010
#define YN_ESTS_SPT_ERR		0x0020
#define YN_ESTS_TGLCOVR		0x0200
#define YN_ESTS_TGL_ERR		0x0400
#define YN_ESTS_TUR_ERR		0x0800
#define YN_ESTS_RFO_ERR		0x1000
#define YN_ESTS_FE_RSM		0x2000
#define YN_ESTS_EWDTOVR		0x4000
#define YN_ESTS_WDTOVR		0x8000

#define YN_ESTS_APPL_ERR	(YN_ESTS_TGL_ERR | YN_ESTS_TMCYCOVR | YN_ESTS_PAR_ERR)
#define YN_ESTS_SYS_ERR		(YN_ESTS_WDTOVR | YN_ESTS_EWDTOVR | YN_ESTS_RFO_ERR | YN_ESTS_TUR_ERR)

/* MOD regs */
#define	YN_MOD_PROCEL_1NS	0x0000
#define	YN_MOD_PROCEL_2NS	0x0001

#define YN_MOD_SPEED_2M		0x0018
#define YN_MOD_SPEED_4M		0x0010
#define YN_MOD_SPEED_10M	0x0008
#define YN_MOD_SPEED_20M	0x0000

#define YN_MOD_CODE_MAN		0x00c0
#define YN_MOD_CODE_NRZI	0x0040
#define YN_MOD_CODE_MNRZ	0x0080 /* add for JL-098 */

#define	YN_MOD_BMOD_STATIC	0x0000
#define	YN_MOD_BMOD_ALT		0x0100
#define	YN_MOD_BMOD_RALT	0x0300

#define	YN_MOD_MTYP_C1		0x0000
#define	YN_MOD_MTYP_C2		0x0400

#define	YN_MOD_INTLV_PLS	0x0800
#define	YN_MOD_INTLV_LVL	0x0000

#define	YN_MOD_ESYNCS		0x1000
#define	YN_MOD_LBTST		0x2000
#define	YN_MOD_TYPE_MASTER	0x4000
#define	YN_MOD_TYPE_SLAVE	0x0000
#define	YN_MOD_INT_FRS		0x8000
#define	YN_MOD_MASK			0x0300	/* BMOD mask */

/* TMBC,RMBC */
#define YN_MBC_WD		0x0002

/* default parameters */
#define	DEF_IMK_REG			0		/* IMK register */
#define	DEF_RAM_SIZE		4096	/* RAM word size for JL-098 (8Kbyte)*/

/* 1NS */
#define	DEF_1NS_MA			0		/* My address */
#define	DEF_1NS_MA_MAX		14		/* Max. number of slaves */
#define	DEF_1NS_T_MCYC		2000	/* Tmcyc */
#define	DEF_1NS_T_CYC		130		/* Tcyc */
#define	DEF_1NS_BYTE		17		/* Length of Cyclick trans. data */
#define	DEF_1NS_DEV			0		/* Devision */
#define	DEF_1NS_PREL		1		/* Length of Preamble */
#define	DEF_1NS_INT1_DLY	8		/* PV of short1 delay timer */
#define	DEF_1NS_RAM_SPD		0		/* External RAM speed  */
#define	DEF_1NS_ROM_SPD		0		/* External ROM speed  */
#define	DEF_1NS_LBSS_REG	0x300	/* LBSS register */
#define	DEF_1NS_RMBD_REG	0x780	/* RMBD register */
/* 2NS */
#define	DEF_2NS_MA			1		/* My address */
#define	DEF_2NS_MA_MAX		14		/* Max. number of slaves */
#define	DEF_2NS_T_MCYC		4000	/* Tmcyc */
/* add for JL-098 */
#define	DEF_2NS_T_CYC_10M_32	360		/* Tcyc (90us) */
#define	DEF_2NS_T_CYC_10M_17	240		/* Tcyc (60us) */
/* for JL-098 */
#define	DEF_2NS_T_CYC		360		/* Tcyc */
#define	DEF_2NS_BYTE		30		/* Length of Cyclick trans. data */
#define	DEF_2NS_DEV			0		/* Devision */
#define	DEF_2NS_PREL		1		/* Length of Preamble */
#define	DEF_2NS_INT1_DLY	32		/* PV of short1 delay timer x 4 */
#define	DEF_2NS_RAM_SPD		0		/* External RAM speed  */
#define	DEF_2NS_ROM_SPD		0		/* External ROM speed  */
#define	DEF_2NS_LBSS		0x300	 /* Pointer to alt. buff. B (LBSS) */
#define	DEF_2NS_MAX_RTRY	1		/* Max. num. of retry */
#define	DEF_2NS_C2M_CH		1		/* C2-Master flag */
#define	DEF_2NS_MSG_PTR		0x632	/* Pointer to messege buffer */
#define	DEF_2NS_C1MSG_SZ	128		/* C1-message size */
#define	DEF_2NS_C2MSG_SZ	128		/* C2-message size */
#define	DEF_2NS_WDT			15		/* PV of Watch dog timer */
#define	DEF_2NS_C2DLY		180		/* C2-Master send delay */

/* Error Code */
#ifndef OK
#define	OK				0
#endif

#define	ERROR_INIT_CHANNEL			(-1)
#define	ERROR_INVALID_PROTOCOL		(-2)		/* yns_set_regs() */
#define	ERROR_INVALID_BMODE			(-3)		/* yns_set_regs() */
#define	ERROR_INVALID_PARAMETER		(-4)		/* yns_set_param() */

#define	ERROR_NOT_READY				(-5)		/* yns_reset() */
#define	ERROR_POLL_TIMEOUT_REG		(-6)		/* yns_sequent_init() */
#define	ERROR_POLL_TIMEOUT_PAR		(-7)		/* yns_sequent_init() */
#define	ERROR_POLL_TIMEOUT_ENA		(-8)		/* yns_sequent_init() */
#define ERROR_RAM_SIZE_OVER			(-9)

#define ERROR_STS_ERR				(-10)
#define ERROR_RAM_CHECK				(-11)
#define ERROR_SLOTCH_OVER			(-12)

#define	ERROR_INVALID_ST_NO			(-20)
#define	ERROR_ALT_BUFFER			(-21)
#define ERROR_TOGGLE_BUFFER			(-22)
#define	ERROR_REQ_SIZE				(-23)
#define	ERROR_RECV_DATA				(-24)		/* yns_read_ldata() */
#define ERROR_SYNC_NO_RECV			(-25)
#define ERROR_NO_SYNC				(-26)
#define ERROR_JL098_SYSTEM			(-27)
#define ERROR_JL098_APPL			(-28)

#define	ERROR_STS_MSG				(-30)
#define	ERROR_RCV_ABORT_MSG			(-31)
#define	ERROR_HNDSHAKE_MSG			(-32)
#define	ERROR_SNDBUF_UNDERFLOW		(-33)
#define	ERROR_RCVBUF_OVERFLOW		(-34)
#define	ERROR_NOT_ENOUGH_MSGAREA	(-35)
#define	ERROR_RECV_BUSY				(-36)

#define YENET_INIT_CHBUF			0x1020	/*  */
#define YENET_INIT_DONE				0x2040	/*  */

#define YN_C1_MASTER				0	/* C1 master */
#define YN_C2_MASTER				1	/* C21 master */

#define YN_CTRL_CDRW				0x03	/* CDRW code */
#define YN_CTRL_MDS					0x04	/* MDS code */
#define YN_CTRL_CDRW_ACK			0x01	/* ACK code */
#define YN_CTRL_MDS_ACK				0x90	/* MDS ACK code */

#define YN_CTRL_ERRCODE				0x00FF	/* Receve Error code */

/***********************************************************************/
/*	Structure of HOST I/F registers                                    */
/***********************************************************************/
typedef struct _YENET_HOST_IF_REGS {
	volatile USHORT cmd;	/* Command to CERF */
	volatile USHORT sts;	/* Status */
	volatile USHORT ints;	/* Interrupt Status */
	volatile USHORT imk;	/* Interrupt Mask, same as ints register */
	volatile USHORT ests;	/* Error Status */
	volatile USHORT mod;	/* Mode */
	volatile USHORT lbs;	/* Link Buffer Select */
	volatile USHORT lbp;	/* Link Buffer Access Pointer */
	volatile USHORT lbd;	/* Link Buffer Data Port */
	volatile USHORT ubp;	/* Universal Buffer Access Pointer */
	volatile USHORT ubd;	/* Universal Buffer Data Port */
	volatile USHORT tmbc;	/* Transmit Message Buffer Control */
	volatile USHORT tmbd;	/* Transmit Message Buffer Data Port */
	volatile USHORT rmbc;	/* Receive Message Buffer Control */
	volatile USHORT rmbd;	/* Receive Message Buffer Data Port */
	volatile USHORT mctr;	/* Message Conter */
	volatile USHORT cid;	/* Chip ID <add for JL-098> */
	volatile USHORT mset;	/* Mode Set <add for JL-098> */
} YENET_HOST_IF_REGS;


/***********************************************************************/
/*    Communication Parameter                                          */
/***********************************************************************/
typedef struct _YENET_COM_PAR {
	USHORT ma;				/* My Address */
	USHORT ma_max;			/* Max. Number of Slaves */
	USHORT t_mcyc;			/* Tmcyc */
	USHORT t_cyc;			/* Tcyc */
	USHORT byte;			/* Transimit Data Size (Bytes) */
	USHORT dev;				/* Devision */
	USHORT prel;			/* Preamble Length */
	USHORT int1_dly;		/* int1 Delay */
	USHORT ram_spd;			/* External RAM Speed */
	USHORT rom_spd;			/* External ROM Speed */
	USHORT lbss;			/* Alt buf.B start Adrress*/
	USHORT max_rtry;		/* Max Number of Retry */
	USHORT c2m_ch;			/* Time slot */
	USHORT msg_ptr;			/* Message buf. pointer */
	USHORT c1msg_sz;		/* C1 message size */
	USHORT c2msg_sz;		/* C2 message size */
	USHORT wdt;				/* Watch dog setting */
	USHORT c2dly;			/* Transfer message delay for C2 */
} YENET_COM_PAR;


typedef struct _YENET_USER_PAR {
	USHORT mod;				/* MOD register */
	USHORT ma;				/* My Address */
	USHORT ma_max;			/* Max. Number of Slaves */
	USHORT t_mcyc;			/* Tmcyc */
	USHORT t_cyc;			/* Tcyc */
	USHORT byte;			/* Transimit Data Size (Bytes) */
	USHORT dev;				/* Devision */
	USHORT max_rtry;		/* Max Number of Retry */
	USHORT c2m_ch;			/* Time slot */
	USHORT wdt;				/* Watch dog setting */
} YENET_USER_PAR;


/***********************************************************************/
/*    Register Parameter                                               */
/***********************************************************************/
typedef struct _YENET_REG_PAR {
	USHORT mod;				/* MOD register */
	USHORT imk;				/* IMK register */
	USHORT rmbd;			/* RMBD register */
	USHORT mctr;			/* MCTR register */
} YENET_REG_PAR;

typedef struct _CHANNEL_INFO {
	YENET_HOST_IF_REGS *hif_reg_top;	/* Host I/F register top save area */
	USHORT ma_max;						/* Max. nods save area */
	USHORT ma;							/* My address save area */
	USHORT link_sz;						/* Buffer size */
	USHORT buff_mod;					/* Burffer mode (FIX or ALT or MIX) */
	USHORT alt_buff;					/* Current buffer (A or B) */
	USHORT ubp_data;					/* UBP backup data */
	USHORT link_sadr[2];				/* Link buffer offset address */
	USHORT link_radr[2];				/* Link buffer offset address */
	USHORT pars_data;					/* Communication Param. address */
	USHORT c1msg_sz;					/* C1 message buffer size */
	USHORT c2msg_sz;					/* C2 message buffer size */
	USHORT c1msg_adr;					/* C1 message buffer address */
	USHORT c2msg_adr;					/* C2 message buffer address */
	USHORT msgpkt_sz;					/* Packet size of message */
	USHORT check_code;
	USHORT net_clk;						/* Network time */
} CHANNEL_INFO;


#endif /* _YENETDEF_H */

/***********************************************************************/
/*   function prototype                                                */
/***********************************************************************/
#ifndef	YENET_LOCAL_DEFINES_
#ifdef __cplusplus
extern	"C"	{
#endif



#ifdef __cplusplus
}
#endif
#endif 	/* _YENET_LOCAL_DEFINES */

#define ynb_get_cmd(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->cmd)
#define ynb_set_cmd(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->cmd = (USHORT)data)
#define ynb_get_sts(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->sts)
#define ynb_get_ints(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->ints)
#define ynb_clear_ints(pJL, data) (((YENET_HOST_IF_REGS * volatile)pJL)->ints = (USHORT)data)
#define ynb_set_imk(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->imk = (USHORT)data)
#define ynb_get_ests(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->ests)
#define ynb_clear_ests(pJL, data) (((YENET_HOST_IF_REGS * volatile)pJL)->ests =(USHORT)data)
#define ynb_get_mod(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->mod)
#define ynb_set_mod(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->mod = (USHORT)data)
#define ynb_get_lbs(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->lbs)
#define ynb_set_lbs(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->lbs = (USHORT)data)
#define ynb_get_lbp(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->lbp)
#define ynb_set_lbp(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->lbp = (USHORT)data)
#define ynb_get_lbd(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->lbd)
#define ynb_set_lbd(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->lbd = (USHORT)data)
#define ynb_get_ubp(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->ubp)
#define ynb_set_ubp(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->ubp = (USHORT)data)
#define ynb_get_ubd(pJL)          (((YENET_HOST_IF_REGS * volatile)pJL)->ubd)
#define ynb_set_ubd(pJL, data)    (((YENET_HOST_IF_REGS * volatile)pJL)->ubd = (USHORT)data)
#define ynb_get_tmbc(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->tmbc)
#define ynb_set_tmbc(pJL, data)   (((YENET_HOST_IF_REGS * volatile)pJL)->tmbc = (USHORT)data)
#define ynb_get_tmbd(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->tmbd)
#define ynb_set_tmbd(pJL, data)   (((YENET_HOST_IF_REGS * volatile)pJL)->tmbd = (USHORT)data)
#define ynb_get_rmbc(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->rmbc)
#define ynb_set_rmbc(pJL, data)   (((YENET_HOST_IF_REGS * volatile)pJL)->rmbc = (USHORT)data)
#define ynb_get_rmbd(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->rmbd)
#define ynb_set_pars(pJL, data)   (((YENET_HOST_IF_REGS * volatile)pJL)->rmbd =(USHORT)data)
#define ynb_get_mctr(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->mctr)
#define ynb_get_mset(pJL)         (((YENET_HOST_IF_REGS * volatile)pJL)->mset)	/* <add for JL-098> */
#define ynb_set_mset(pJL, data)   (((YENET_HOST_IF_REGS * volatile)pJL)->mset = (USHORT)data)	/* <add for JL-098> */
#define ynb_set_lbss(pJL, data)   (((YENET_HOST_IF_REGS * volatile)pJL)->mctr = (USHORT)data)


/*file*********** MELNK_DRV : ***********************************************/
/*                                                                          */
/*                                                                          */
/*                JL098INI.C : JL-098 interface access driver               */
/*                                                                          */
/*                                                                          */
/******** Copyright(C) 2002 Yaskawa Electric Corporation ********************/
/*                                                                          */
/*      Ver 1.00    2007.02.28   Initial coding    T.Soeda                  */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*       [Functions]                                                        */
/*       Service functions                                                  */
/*       yns_init_channel()          Initialize Channel Buffer              */
/*       yns_reset()                 Reset JL-098                           */
/*       yns_set_regs()              Initialize Host I/F Registers          */
/*       yns_set_param()             Set Communication Parameter            */
/*       yns_enable()                Enable JL-098                          */
/*       yns_sequent_init()          Execute JL-098                         */
/*                                                  initializing sequense   */
/*       yns_check_ram()             memory check                           */
/*                                                                          */
/*                                                                          */
/******** Copyright(C) 2007 Yaskawa Electric Corporation ********************/

#ifndef YENET_LOCAL_DEFINES_
#define YENET_LOCAL_DEFINES_
#endif /* _YENET_LOCAL_DEFINES */

/* includes */
//#include "jl098gbl.h"

/* local defines */
#define	YN_MOD_INVALID	0x0200	/* BMOD invalid code */
#define YN_PROSEL_CHECK	0x0006	/* Protocol check */

#define	YENET_POLLING_READY	0x0ffff	/* Polling counter for yenet_reset */
#define	YENET_POLLING_COUNT	0x0ffff	/* Polling counter for service func. */

#define	YN_GBL_CODE		0x0800	/* Global code for C1 master */
#define	YN_MGBL_CODE	0x0300	/* Global code for C1 master */
#define	YN_SGBL_CODE	0x0100	/* Global code for slave */

/* add for JL-098 */
#define	YN_MOD_CODE_MSK		(YN_MOD_CODE_MAN | YN_MOD_CODE_NRZI | YN_MOD_CODE_MNRZ)

/* forward declarations */
#ifdef __cplusplus
extern	"C"	{
#endif
void yns_init_channel( CHANNEL_INFO *chbuffp, USHORT *hif_reg_top );
int yns_reset( CHANNEL_INFO *chbuffp );
int yns_set_regs( CHANNEL_INFO *chbuffp, YENET_REG_PAR *regp );
int yns_set_param( CHANNEL_INFO *chbuffp, YENET_COM_PAR *par );
int yns_enable( CHANNEL_INFO *chbuffp );
void yns_set_transmit_data( CHANNEL_INFO *chbuffp,
				YENET_REG_PAR *reg_par, YENET_COM_PAR *com_par, UCHAR *adrp);
void yns_set_lnk_header( CHANNEL_INFO *chbuffp, 
						UINT st_no, USHORT bmod, USHORT ctrl);
int yns_sequent_init( CHANNEL_INFO *chbuffp, USHORT *hif_reg_top,
					 YENET_USER_PAR *usr_par, UCHAR *adrsp );
int yn_set_user_prm( YENET_USER_PAR *par, 
				YENET_REG_PAR *reg_par, YENET_COM_PAR *com_par );
int yns_check_ram( USHORT *top_adr, 
						UINT ofst_adr, UINT size, USHORT chk_data);
int yns_reset_prm( CHANNEL_INFO *chbuffp, USHORT t_mcyc );
#ifdef __cplusplus
}
#endif


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_init_channel()                Initialiize Channel buffer        */
/*                                                                          */
/*Function :                                                                */
/*      Clear Chnannel buffer and save host interface top address           */
/*                                                                          */
/*Reference :                                                               */
/*      set_user_prm                                                        */
/*                                                                          */
/*Return code :                                                             */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :   Channel buffer address                    */
/*      USHORT *hif_reg_top   :   Host I/F register top address             */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
void yns_init_channel( CHANNEL_INFO *chbuffp, USHORT *hif_reg_top )
{
	USHORT	*p;
	USHORT	i, size;

/* Clear channel buffer */
	p = (USHORT *)chbuffp;
	size = sizeof(CHANNEL_INFO) / sizeof(USHORT);
	for (i = 0; i < size; i++)
	{
		*p++ = 0;
	}

/* Set top address of Host interface registers */
	chbuffp->hif_reg_top = (YENET_HOST_IF_REGS *)hif_reg_top;

/* Set check code */
	chbuffp->check_code = YENET_INIT_CHBUF;

}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_reset()                       Reset JL-098                      */
/*                                                                          */
/*Function :                                                                */
/*      Reset JL-098 and wait JL-098 ready                                  */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                            Normal End                          */
/*      ERROR_INIT_CHANNEL :            Invalid channel buffer specified    */
/*      ERROR_NOT_READY :               CERF Not Ready (STS(RDY) is zero.)  */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :	        Channel buffer address              */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_reset( CHANNEL_INFO *chbuffp )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT sts;							/* STS reg. */
	USHORT i;							/* Polling Conter */
	int ret;							/* Return code */

/* Check Channel Buffer */
	if (chbuffp->check_code != YENET_INIT_CHBUF)
	{
		return ERROR_INIT_CHANNEL;
	}

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Reset CERF */
	ynb_set_cmd( hirp, YN_CMD_RST_CER );

/* Wait CERF Ready */
	ret = ERROR_NOT_READY;
	for (i = 0; i < YENET_POLLING_READY; i++)
	{
		sts = ynb_get_sts( hirp );
		if ((sts & YN_STS_RDY) != 0)
		{
			ret = OK;
			break;			/* Exit */
		}
	}

	return ret;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yn_set_user_prm()              Set user parameter                   */
/*                                                                          */
/*Function :                                                                */
/*      Set specified parameter to host interface register and              */
/*      communication parameter register.                                   */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                            Normal End                          */
/*      ERROR_INVALID_PROTOCOL :        Unsupported protocol                */
/*      ERROR_INVALID_BMODE :           Unsupported buffer mode             */
/*      ERROR_RAM_SIZE_OVER :           using memory size larger than RAM   */
/*                                                                          */
/*Parameter :                                                               */
/*      YENET_USER_PAR *usr_par :       Communicaiotn parameter             */
/*      YENET_REG_PAR *reg_par :        Register parameter                  */
/*      YENET_COM_PAR *com_par :        Communicaiotn parameter             */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yn_set_user_prm( YENET_USER_PAR *par, 
				YENET_REG_PAR *reg_par, YENET_COM_PAR *com_par )
{
	USHORT	calc;

/* Check parameter */
	if(par->mod & YN_PROSEL_CHECK)
		return ERROR_INVALID_PROTOCOL;	/* protocol error */

	if((par->mod & YN_MOD_MASK) == YN_MOD_INVALID)
		return ERROR_INVALID_BMODE;	/* buffer mode error */

/* Set 1NS, 2NS Common parameter */
	reg_par->mod = 
		(par->mod & ~(YN_MOD_LBTST | YN_MOD_MTYP_C2 | YN_MOD_CODE_MSK)) | YN_MOD_CODE_MAN;

	reg_par->imk = DEF_IMK_REG;			/* IMK register */

	com_par->ma = par->ma;				/* My Address */
	com_par->ma_max = par->ma_max;		/* Max. Number of Slaves */
	com_par->t_mcyc = par->t_mcyc;		/* Tmcyc */
	com_par->t_cyc = par->t_cyc;		/* Tcyc */
	com_par->byte = par->byte;			/* Transimit Data Size (Bytes) */
	com_par->dev = par->dev;			/* Devision */
	com_par->prel = DEF_2NS_PREL;		/* Preamble Length */
	com_par->int1_dly = DEF_2NS_INT1_DLY;/* int1 Delay */
	com_par->ram_spd = DEF_2NS_RAM_SPD;	/* External RAM Speed */
	com_par->rom_spd = DEF_2NS_ROM_SPD;	/* External ROM Speed */

/* Set 1NS, 2NS parameter */
	if((par->mod & YN_MOD_PROCEL_2NS) != 0)	/* 2 : N */
	{
		reg_par->mctr = 						/* MCTR reg. */
				(com_par->byte/sizeof(USHORT)+1)*(par->ma_max+1)*2;
		reg_par->rmbd = ((reg_par->mod & YN_MOD_MASK) == 0) ? 
					reg_par->mctr + 1 : reg_par->mctr * 2;	/* RMBD reg. */
		com_par->lbss = reg_par->mctr;			/* Alt buf.B start Adrress*/
		com_par->max_rtry = par->max_rtry;		/* Max Number of Retry */
		com_par->c2m_ch = par->c2m_ch;			/* Time slot */
		com_par->msg_ptr = reg_par->rmbd + 32;	/* Message buf. pointer */

	/* calc total size */
		calc = com_par->msg_ptr + 
				DEF_2NS_C1MSG_SZ*2 + DEF_2NS_C1MSG_SZ*2;

		if(calc > DEF_RAM_SIZE)
			return ERROR_RAM_SIZE_OVER;			/* RAM size over */

		if((reg_par->mod & YN_MOD_TYPE_MASTER) != 0)	/* Master */
		{
			calc = 44 + com_par->t_cyc *
				(com_par->max_rtry + com_par->ma_max + com_par->c2m_ch + 1);

			if(calc > com_par->t_mcyc)
				return ERROR_SLOTCH_OVER;			/* SLOT CH over */
		}

		com_par->c1msg_sz = DEF_2NS_C1MSG_SZ;	/* C1 message size */
		com_par->c2msg_sz = DEF_2NS_C2MSG_SZ;	/* C2 message size */
		com_par->wdt = par->wdt;				/* Watch dog setting */
		com_par->c2dly = DEF_2NS_C2DLY;			/* Transfer C2-msg delay */
	}
	else	/* 1 : N */
	{
		reg_par->mctr = DEF_1NS_LBSS_REG;	/* Alt buf.B start Adrress*/
		reg_par->rmbd = DEF_1NS_RMBD_REG;	/* RMBD register */
		com_par->lbss = reg_par->mctr;
		com_par->max_rtry = 0;		/* Max Number of Retry */
		com_par->c2m_ch = 0;		/* Time slot */
		com_par->msg_ptr = 0;		/* Message buf. pointer */
		com_par->c1msg_sz = 0;		/* C1 message size */
		com_par->c2msg_sz = 0;		/* C2 message size */
		com_par->wdt = 0;			/* Watch dog setting */
		com_par->c2dly = 0;			/* Transfer message delay for C2 */
	}

	return OK;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_set_regs()                  Initialize Host I/F Registers       */
/*                                                                          */
/*Function :                                                                */
/*      Set specified data to host interface register and set request of    */
/*      resetting pointer.                                                  */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                            Normal End                          */
/*      ERROR_INIT_CHANNEL :            Invalid channel buffer specified    */
/*      ERROR_INVALID_PROTOCOL :        Unsupported protocol                */
/*      ERROR_INVALID_BMODE :           Unsupported buffer mode             */
/*      ERROR_POLL_TIMEOUT_REG :        P_RSTAK Request did not completed   */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*      YENET_REG_PAR *par :            Register parameter                  */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_set_regs( CHANNEL_INFO *chbuffp, YENET_REG_PAR *regp )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT data;						/* Register data */
	int ret;							/* Return code */
	USHORT i;							/* Polling Conter */

/* Check Channel Buffer */
	if (chbuffp->check_code != YENET_INIT_CHBUF)
	{
		return ERROR_INIT_CHANNEL;
	}

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	if(regp->mod & YN_PROSEL_CHECK)
	{
		return ERROR_INVALID_PROTOCOL;
	}
	if((regp->mod & YN_MOD_MASK) == YN_MOD_INVALID)
	{
		return ERROR_INVALID_BMODE;
	}

/* Save Buffer mode and rmbd */
	chbuffp->buff_mod = regp->mod & YN_MOD_MASK;
	chbuffp->pars_data = regp->rmbd;

/* Set Register */
	ynb_set_imk( hirp, regp->imk );	/* Interrupt Mask */
	ynb_set_mod( hirp, regp->mod );	/* Mod Register */
	ynb_set_pars( hirp, regp->rmbd );	/* Comm. Par. address */
	ynb_set_lbss( hirp, regp->mctr );

/* Write  Pointer Reset Request */
	ynb_set_cmd( hirp, YN_CMD_P_RSTRQ );

/* Wait Request End */
	ret = ERROR_POLL_TIMEOUT_REG;
	for (i = 0; i < YENET_POLLING_COUNT; i++)
	{
		data = ynb_get_ints( hirp );
		if ((data & YN_INTS_P_RSTAK) != 0)
		{
		/* Clear Interrupt Status */
			ynb_clear_ints( hirp, YN_INTS_P_RSTAK );
			ret = OK;
			break;				/* Exit */
		}
	}

	return ret;
}


/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_set_param()                 Set communication parameter         */
/*                                                                          */
/*Function :                                                                */
/*      Write communication parameter to common memory and set request of   */
/*      setting parameter.                                                  */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                              Normal End                        */
/*      ERROR_INIT_CHANNEL :              Invalid channel buffer specified  */
/*      ERROR_POLL_TIMEOUT_PAR :          PAR_I Request did not completed   */
/*      ERROR_INVALID_PARAMETER :         Invalid parameter                 */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*      YENET_COM_PAR *par :              Communicaiotn parameter           */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<1> fix calculation of ubp reg. data                      */
/*                                                                          */
/****************************************************************************/
int yns_set_param( CHANNEL_INFO *chbuffp, YENET_COM_PAR *par )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT data = 0;					/* Register data */
	USHORT *pp;							/* Com. Param Pointer */
	USHORT i;							/* Polling Conter */
	UINT par_sz;						/* Parameter size */
	int ret;							/* Return code */

/* Check Channel Buffer */
	if (chbuffp->check_code != YENET_INIT_CHBUF)
	{
		return ERROR_INIT_CHANNEL;
	}

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Save data to channel buffer */
	chbuffp->ma = par->ma;		/* My address */
	chbuffp->ma_max = par->ma_max;	/* Max. number of stations */
	chbuffp->link_sz = (par->byte >> 1)+1;	/* Buffer size */
	chbuffp->link_radr[0] = (par->lbss >> 1);
	chbuffp->link_radr[1] = par->lbss + (par->lbss >> 1);
	chbuffp->link_sadr[0] = 0;
	chbuffp->link_sadr[1] = par->lbss;
	chbuffp->c1msg_sz = par->c1msg_sz;
	chbuffp->c1msg_adr = par->msg_ptr;
	chbuffp->c2msg_sz = par->c2msg_sz;
	chbuffp->c2msg_adr = par->msg_ptr + par->c1msg_sz*2;
	chbuffp->msgpkt_sz = ((par->byte-1) >> 1);
	par_sz = sizeof(YENET_COM_PAR) >> 1; /* Set parameter size */

/* Write Parameter */
	pp = (USHORT*)par;
	ynb_set_ubp( hirp, chbuffp->pars_data);	/* Set RMBD start address */
	for(i = 0 ; i < par_sz ; i++)
	{
		ynb_set_ubd( hirp, *pp);
        pp++;
	}

/* Write  Com. Par. Request */
	ynb_set_cmd( hirp, YN_CMD_PAR_R );

/* Wait Request End */
	ret = ERROR_POLL_TIMEOUT_PAR;
	for (i = 0; i < YENET_POLLING_COUNT; i++)
	{
		data = ynb_get_ints( hirp );
		if ((data & YN_INTS_PAR_I) != 0)
		{
		/* Clear Interrupt Status */
			ynb_clear_ints( hirp, YN_INTS_PAR_I );

		/* Check Error Status */
			data = ynb_get_ests( hirp );
			if ((data & YN_ESTS_PAR_ERR) != 0)
			{
			/* Clear Error Status */
				ynb_clear_ests( hirp, YN_ESTS_PAR_ERR );
				ret = ERROR_INVALID_PARAMETER;
			}
			else
			{
				ret = OK;
			}
			break;
		}
	}

	return ret;
}


/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_enable()                    Enable JL-098                       */
/*                                                                          */
/*Function :                                                                */
/*      Enable JL-098 to transmit data                                      */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                              Normal End                        */
/*      ERROR_INIT_CHANNEL :              Invalid channel buffer specified  */
/*      ERROR_POLL_TIMEOUT_ENA :          Request did not completed         */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_enable( CHANNEL_INFO *chbuffp )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT data;						/* Register data */
	int ret;							/* Return code */
	USHORT i;							/* Polling Conter */

/* Check Channel Buffer */
	if (chbuffp->check_code != YENET_INIT_CHBUF)
	{
		return ERROR_INIT_CHANNEL;
	}

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Write  Enable Request */
	ynb_set_cmd( hirp, YN_CMD_ENA_CER );

/* Wait Request End */
	ret = ERROR_POLL_TIMEOUT_ENA;
	for (i = 0; i < YENET_POLLING_COUNT; i++)
	{
		data = ynb_get_cmd( hirp );
		if ((data & YN_CMD_ENA_CER) == 0)
		{
			ret = OK;
			break;
		}
	}

	return ret;
}


/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*     yns_set_transmit_data()             Set 1st transmit data            */
/*                                                                          */
/*Function :                                                                */
/*      Enable JL-098 to transmit data                                      */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*      YENET_REG_PAR *reg_par :        Register parameter                  */
/*      YENET_COM_PAR *com_par :        Communicaiotn parameter             */
/*      UCHAR        *adrp    :         Station address                     */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
void yns_set_transmit_data( CHANNEL_INFO *chbuffp,
				YENET_REG_PAR *reg_par, YENET_COM_PAR *com_par, UCHAR *adrp)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT data = 0;	/* Register data */
	int i;				/* general */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

	if((reg_par->mod & YN_MOD_TYPE_MASTER) != 0)	/* Master */
	{
		for(i = 1; i <= chbuffp->ma_max; i++)
		{
			data = YN_MGBL_CODE | adrp[i];
		/* Set link header to Alt Buffer A */
			yns_set_lnk_header(chbuffp, i, 0, data);
		/* Set link header to Alt Buffer B */
			if(chbuffp->buff_mod == YN_MOD_BMOD_ALT)
			{
				yns_set_lnk_header(chbuffp, i, 1, data);
			}
		}
	/* Set global data to Alt Buffer A */
		data = ((reg_par->mod & YN_MOD_PROCEL_2NS) != 0)
				? (YN_GBL_CODE | adrp[0])	/* 2 : N */
				: adrp[0];					/* 1 : N */

		ynb_set_ubp(hirp, 0);
		ynb_set_ubd(hirp, data);
		ynb_set_ubd(hirp, com_par->t_mcyc);
		ynb_set_ubd(hirp, com_par->t_cyc);
		ynb_set_ubd(hirp, com_par->c2m_ch);

	/* Set global data to Alt Buffer B */
		if(chbuffp->buff_mod == YN_MOD_BMOD_ALT)
		{
			ynb_set_ubp(hirp, com_par->lbss);
			ynb_set_ubd(hirp, data);
			ynb_set_ubd(hirp, com_par->t_mcyc);
			ynb_set_ubd(hirp, com_par->t_cyc);
			ynb_set_ubd(hirp, com_par->c2m_ch);
		}
	}
	else	/* Slave */
	{
		data = YN_SGBL_CODE | chbuffp->ma;
	/* Set link header to Alt Buffer A */
		yns_set_lnk_header(chbuffp, 0, 0, data);
	/* Set link header to Alt Buffer B */
		if(chbuffp->buff_mod == YN_MOD_BMOD_ALT)
		{
			yns_set_lnk_header(chbuffp, 0, 1, data);
		}
	}
}


/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_set_lnk_header()             Set link header code               */
/*                                                                          */
/*Function :                                                                */
/*      Set link header code                                                */
/*                                                                          */
/*Return code :                                                             */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*      UINT         st_no    :           Statin number                     */
/*      USHORT       bmod     :           ALT Buf.  A or B                  */
/*                                        (bmod=0: A  bmod!=0: B)           */
/*      USHORT       ctrl     :           link header (St.Adrs+CTRL)        */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<1> fix calculation of ubp reg. data                      */
/*                                                                          */
/****************************************************************************/
void yns_set_lnk_header( CHANNEL_INFO *chbuffp, 
						UINT st_no, USHORT bmod, USHORT ctrl)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT ubp_data;					/* Register data */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Get receive buffer offset */
	ubp_data = 0;
	if (bmod != 0)
	{
		ubp_data += chbuffp->link_sadr[1];
	}

/* Add offset of station number */
	ubp_data += (USHORT)(chbuffp->link_sz * st_no);

/* Set offset address to UBP.reg */
	ynb_set_ubp( hirp, ubp_data );

/* Write UBD data */
	ynb_set_ubd( hirp, ctrl );

}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_sequent_init()                Initialize Host I/F Registers	    */
/*                                                                          */
/*Function :                                                                */
/*      Execute initializing sequense of JL-098.                            */
/*      Initializing sequense is following.                                 */
/*                                                                          */
/*      1. Reset JL-098 (yns_reset).                                        */
/*      2. Set specified data to host interface register (yns_set_regs).    */
/*      3. Set Communication parameter (yns_set_param).                     */
/*      4. Enable CERF (yns_enable).                                        */
/*      5. Set 1st Transmit data.                                           */
/*      6. Request Link data Transfer.                                      */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                              Normal End                        */
/*      ERROR_INIT_CHANNEL :              Invalid channel buffer specified  */
/*      ERROR_POLL_TIMEOUT :              Request did not completed         */
/*      ERROR_NOT_READY :                 CERF Not Ready (STS(RDY) is zero.)*/
/*      ERROR_INVALID_PROTOCOL :          Unsupported protocol              */
/*      ERROR_INVALID_BMODE :             Unsupported buffer mode           */
/*      ERROR_POLL_TIMEOUT_REG :          P_RSTAK Request did not completed */
/*      ERROR_POLL_TIMEOUT_PAR :          PAR_I Request did not completed   */
/*      ERROR_POLL_TIMEOUT_ENA :          Request did not completed         */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*      USHORT *hif_reg_top   :           Host I/F register top address     */
/*      YENET_USER_PAR *usr_par :         Communicaiotn parameter           */
/*      UCHAR *adrsp          :           Station address                   */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_sequent_init( CHANNEL_INFO *chbuffp, USHORT *hif_reg_top,
					 YENET_USER_PAR *usr_par, UCHAR *adrsp )
{
	YENET_COM_PAR par;	/* Communication parameter */
	YENET_REG_PAR reg;	/* Register parameter */
	int ret = OK;		/* Return code */

/* Initialize channel buffer */
	yns_init_channel(chbuffp,(USHORT*)hif_reg_top);

/* Set default parameter */
	if((ret = yn_set_user_prm( usr_par, &reg, &par )) != OK)
	{
		return ret;
	}

/* Reset CERF */
	if ((ret = yns_reset(chbuffp)) != OK)
	{
	/* Error end */
		return ret;
	}

/* Set Registers */
	if ((ret = yns_set_regs(chbuffp, &reg)) != OK)
	{
	/* Error end */
		return ret;
	}

/* Set Communication Parameter */
	if ((ret = yns_set_param(chbuffp, &par)) != OK)
	{
	/* Error end */
		return ret;
	}

/* Enable CERF */
	if ((ret = yns_enable(chbuffp)) != OK)
	{
	/* Error end */
		return ret;
	}

/* Set 1st Transmit data */
	yns_set_transmit_data(chbuffp, &reg, &par, adrsp);

/* Request Transmit flag */
	ynb_set_cmd(chbuffp->hif_reg_top, YN_CMD_LTX_RA);

	return ret;
}

/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_check_ram()                   RAM Check                         */
/*                                                                          */
/*Function :                                                                */
/*                                                                          */
/*Return code :                                                             */
/*      ERROR_RAM_CHECK       :           RAM Check error                   */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*      UINT         ofst_adr :           Ofset address of memory area      */
/*      UINT         size     :           memory check size                 */
/*      USHORT       chk_data :           check data(write data)            */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_check_ram( USHORT *hif_reg_top, 
						UINT ofst_adr, UINT size, USHORT chk_data)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	UINT chk_size;						/* Check Data Area size */
	USHORT rd_data;						/* Read data */
	int ret, i;							/* return code */

/* Get Host I/F register top address */
	hirp = (volatile YENET_HOST_IF_REGS*)hif_reg_top;

/* Reset CERF */
	ynb_set_cmd( hirp, YN_CMD_RST_CER );

/* Wait CERF Ready */
	ret = ERROR_NOT_READY;
	for (i = 0; i < YENET_POLLING_READY; i++)
	{
		rd_data = ynb_get_sts( hirp );
		if ((rd_data & YN_STS_RDY) != 0)
		{
			ret = OK;
			break;			/* Exit */
		}
	}
	if(ret != OK)	return ret;	/* Can't reset jl-098 */

/* Write UBD data */
	chk_size = size;
	ynb_set_ubp( hirp, ofst_adr );
	while(chk_size > 0)
	{
		ynb_set_ubd( hirp, chk_data );
		chk_size--;
	}

/* Read UBD data, and verify writed data */
	chk_size = size;
	ynb_set_ubp( hirp, ofst_adr );
	while(chk_size > 0)
	{
		rd_data = ynb_get_ubd( hirp );
		if(rd_data != chk_data)
			return ERROR_RAM_CHECK;
		chk_size--;
	}

	return OK;
}

int yns_check_ram_fakerandom( USHORT *hif_reg_top, 
						UINT ofst_adr, UINT size, USHORT chk_data)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	UINT chk_size;						/* Check Data Area size */
	USHORT rd_data;						/* Read data */
	int ret, i;							/* return code */

/* Get Host I/F register top address */
	hirp = (volatile YENET_HOST_IF_REGS*)hif_reg_top;

/* Reset CERF */
	ynb_set_cmd( hirp, YN_CMD_RST_CER );

/* Wait CERF Ready */
	ret = ERROR_NOT_READY;
	for (i = 0; i < YENET_POLLING_READY; i++)
	{
		rd_data = ynb_get_sts( hirp );
		if ((rd_data & YN_STS_RDY) != 0)
		{
			ret = OK;
			break;			/* Exit */
		}
	}
	if(ret != OK)	return ret;	/* Can't reset jl-098 */

/* Write UBD data */
	chk_size = size;
	ynb_set_ubp( hirp, ofst_adr );
	while(chk_size > 0)
	{
		ynb_set_ubd( hirp, chk_size );
		chk_size--;
	}

/* Read UBD data, and verify writed data */
	chk_size = size;
	ynb_set_ubp( hirp, ofst_adr );
	while(chk_size > 0)
	{
		rd_data = ynb_get_ubd( hirp );
		if(rd_data != chk_size)
			return ERROR_RAM_CHECK;
		chk_size--;
	}

	return OK;
}

/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_reset_param()               Reset communication parameter       */
/*                                                                          */
/*Function :                                                                */
/*      Write communication parameter to common memory and set request of   */
/*      setting parameter.                                                  */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*      t_mcyc                :           Transmission cycle time           */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*    Slave station can only use this function                              */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_reset_prm( CHANNEL_INFO *chbuffp, USHORT t_mcyc )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	data;			/* Register data */
	USHORT	ubp_back;
	int		ret = OK;		/* request not ready */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;
	ubp_back = ynb_get_ubp( hirp );

/* Write Parameter */
	ynb_set_ubp( hirp, chbuffp->pars_data+2);	/* Set t_mcyc address */
	ynb_set_ubd( hirp, t_mcyc);

/* Write  Com. Par. Request */
	ynb_set_cmd( hirp, YN_CMD_PAR_R );
	ynb_set_ubp( hirp, ubp_back );	/* Set old UBP */

/* Wait Request End */
	data = ynb_get_ints( hirp );
	if ((data & YN_INTS_PAR_I) != 0)
	{
	/* Clear Interrupt Status */
		ynb_clear_ints( hirp, YN_INTS_PAR_I );

	/* Check Error Status */
		data = ynb_get_ests( hirp );
		if ((data & YN_ESTS_PAR_ERR) != 0)
		{
		/* Clear Error Status */
			ynb_clear_ests( hirp, YN_ESTS_PAR_ERR );
			ret = ERROR_INVALID_PARAMETER;
		}
		else
		{
			ret = OK;
		}
	}

	return ret;
}

/*file*********** MELNK_DRV : ***********************************************/
/*                                                                          */
/*                                                                          */
/*                JL098LNK.C : JL-098 interface access driver               */
/*                                                                          */
/*                                                                          */
/******** Copyright(C) 2007 Yaskawa Electric Corporation ********************/
/*                                                                          */
/*      Ver 1.00    2007.02.28   Initial coding    T.Soeda                  */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*       [Functions]                                                        */
/*      yns_read_ldata()              Read link data                        */
/*      yns_write_ldata()             Write link data                       */
/*      yns_read_ldata2()             Read link data with a packet header   */
/*      yns_write_ldata2()            Write link data with a packet header  */
/*      yns_begin_link_acc()	      Begin link read/write access          */
/*      yns_end_link_acc()	          Finish link read/write access         */
/*      yns_link_exchange()           Read and Write cyclic trans. data     */
/*      yns_read_comstat()            Read communication status             */
/*      yns_set_netclk()              Set network clock                     */
/*      yns_get_netclk()              Get network clock                     */
/*                                                                          */
/*                                                                          */
/******** Copyright(C) 2007 Yaskawa Electric Corporation ********************/

#ifndef YENET_LOCAL_DEFINES_
#define YENET_LOCAL_DEFINES_
#endif /*_YENET_LOCAL_DEFINES */

/* includes */
//#include "jl098gbl.h"

/* loacal defines */
#define	POLL_TIMES20	20			/* Polling timer 20count */
#define CLR_CTRL_CODE	YN_CTRL_ERRCODE		/* Default CTRL code */
#define ESTS_MASK		0xDE0C


/* forward declarations */
#ifdef __cplusplus
extern	"C"	{
#endif
int yns_link_exchange( CHANNEL_INFO *chbuffp, USHORT *rbuffp,
						 USHORT *sbuffp, UINT size, USHORT *ests);
int yns_read_ldata( CHANNEL_INFO *chbuffp, 
					UINT st_no, USHORT *rbuffp, UINT size );
int yns_write_ldata( CHANNEL_INFO *chbuffp, 
					UINT st_no, USHORT *sbuffp, UINT size );
int yns_read_ldata2( CHANNEL_INFO *chbuffp, 
					UINT st_no, USHORT *sts, USHORT *rbuffp, UINT size );
int yns_write_ldata2( CHANNEL_INFO *chbuffp,
					UINT st_no, USHORT sts, USHORT *sbuffp, UINT size );
int yns_begin_link_acc(CHANNEL_INFO *);
int yns_end_link_acc(CHANNEL_INFO *);
USHORT yns_read_comstat( CHANNEL_INFO *pchannel);
USHORT yns_set_netclk( CHANNEL_INFO *chbuffp, UINT cycle );
USHORT yns_get_netclk( CHANNEL_INFO *chbuffp );
int yns_get_gblstat( CHANNEL_INFO *chbuffp, USHORT *t_mcyc);

#ifdef __cplusplus
}
#endif


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_link_exchange()              Read and Write cyclic trans. data */
/*                                                                          */
/*Function :                                                                */
/*      Read cyclic trans. data in 1NS/2NS.                                 */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                              Normal End                        */
/*      n < 0 :                           error code                        */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*      USHORT *rbuffp :                  Read Buffer                       */
/*      USHORT *sbuffp :                  Write Buffer                      */
/*      UINT size    :                    Buffer size                       */
/*      USHORT *status :                  Receive error status              */
/*                                                                          */
/*Note :                                                                    */
/*     C1 master only use this function.                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_link_exchange( CHANNEL_INFO *chbuffp, USHORT *rbuffp,
						 USHORT *sbuffp, UINT size, USHORT *ests)
{
	int		ch;			/* Station number */
	int		ret, rc;	/* return code */
	USHORT	*bufp;		/* buffer pointer */

/* Begin link access */
	if((ret = yns_begin_link_acc(chbuffp)) != OK)
	{
		yns_end_link_acc(chbuffp);
		return ret;
	}

/* Read/Write cyclic data */
	for(ch = 1; ch <= chbuffp->ma_max; ch++)
	{
	/* Write cyclic trans. data */
		bufp = sbuffp + size*(ch-1);
		if((rc = yns_write_ldata(chbuffp, ch, bufp, size)) < 0)
		{
			ret = rc;
		}

	/* Read cyclic trans. data */
		bufp = rbuffp + size*(ch-1);
		if((rc = yns_read_ldata(chbuffp, ch, bufp, size)) < 0)
		{
			ret = rc;
		}
	}

/* End link access */
	rc = yns_end_link_acc(chbuffp);

/* Check error status */
	if((*ests = yns_read_comstat(chbuffp)) != 0)
	{
		ret = ERROR_STS_ERR;
	}

	if(ret != OK) return ret;

	return rc;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_read_ldata()               Read cyclic trans. data or link data*/
/*                                                                          */
/*Function :                                                                */
/*      Read cyclic trans. data in 1NS/2NS.                                 */
/*                                                                          */
/*Return code :                                                             */
/*      short :                           n > 0 : size of read data (word)  */
/*                                        n = 0 : no data to be read        */
/*                                        n < 0 : error code                */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :           Channel buffer address            */
/*      UINT st_no :                      Station number to be read         */
/*      USHORT *rbuffp :                  Buffer                            */
/*      UINT size :                       Buffer size                       */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<3> fix calculation of ubp reg. data                      */
/*            1.30<4> delete the station number check                       */
/*                                                                          */
/****************************************************************************/
int yns_read_ldata( CHANNEL_INFO *chbuffp, 
					UINT st_no, USHORT *rbuffp, UINT size)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	int		ret;			/* Return code */
	USHORT	ubp_data;		/* Offset address */
	USHORT	sts;			/* Status check code */
	USHORT	*prd;			/* read buffer pointer */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Check Station number */
	if (chbuffp->ma_max < st_no)
	{
		return ERROR_INVALID_ST_NO;
	}

/* Read data */
	if(size > (UINT)(chbuffp->link_sz - 1))
		size = chbuffp->link_sz - 1;
	ret = size;

/* Get receive buffer offset */
	ubp_data = chbuffp->link_radr[chbuffp->alt_buff];

/* Add offset of station number */
	ubp_data += (USHORT)(chbuffp->link_sz * st_no);

/* Set offset address to UBP.reg */
	ynb_set_ubp( hirp, ubp_data );

/* Save receive status */
	sts = ynb_get_ubd( hirp );

/* Check receive status, when data is from slave. */
	if (sts == CLR_CTRL_CODE)
	{
		return ERROR_RECV_DATA;	/* Receive error */
	}

	prd = rbuffp;			/* set buffer pointer */
/* Read from UBD */
	while ( (size--) > 0 )
	{
		*prd = ynb_get_ubd( hirp );
    	++prd;
	}

	ynb_set_ubp( hirp, ubp_data );
	ynb_set_ubd( hirp, CLR_CTRL_CODE );	/* Set CTRL code */

	return ret;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_write_ldata()             Write cyclic trans. data or link data*/
/*                                                                          */
/*Function :                                                                */
/*      Write cyclic trans. data in 1NS/2NS.                                */
/*                                                                          */
/*Return code :                                                             */
/*      short :                         n >= 0 : size of written data (word)*/
/*                                      n < 0 : error code                  */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*      UINT st_no :                    Station number                      */
/*      USHORT *sbuffp :                Buffer                              */
/*      UINT size :                     Buffer size                         */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<3> fix calculation of ubp reg. data                      */
/*            1.30<4> delete the station number check                       */
/*                                                                          */
/****************************************************************************/
int yns_write_ldata( CHANNEL_INFO *chbuffp, 
					UINT st_no, USHORT *sbuffp, UINT size )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT 	ubp_data;		/* Offset address */
	USHORT	*pwt;			/* write buffer pointer */
	int 	ret;			/* Return code */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Check Station number */
	if (chbuffp->ma_max < st_no)
	{
		return ERROR_INVALID_ST_NO;
	}

/* Read data */
	if(size > (UINT)(chbuffp->link_sz -1))
		size = chbuffp->link_sz -1;
	ret = size;

/* Get receive buffer offset */
	ubp_data = 0;
	if (chbuffp->buff_mod == YN_MOD_BMOD_ALT)
	{
		ubp_data = chbuffp->link_sadr[chbuffp->alt_buff];
	}

/* Add offset of station number */
	ubp_data += (USHORT)(chbuffp->link_sz * st_no);

/* Set offset address to UBP.reg */
	ynb_set_ubp( hirp, ubp_data + 1);

/* Write UBD data */
	pwt = sbuffp;
	while((size--) > 0)
	{
		ynb_set_ubd( hirp, *pwt );
        pwt++;
	}

	return ret;
}

/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_read_ldata2()              Read cyclic trans. data or link data*/
/*                                                                          */
/*Function :                                                                */
/*      Read cyclic trans. data in 1NS/2NS.                                 */
/*                                                                          */
/*Return code :                                                             */
/*      int :                           n > 0 : size of read data (word)    */
/*                                      n = 0 : no data to be read          */
/*                                      n < 0 : error code                  */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*      UINT st_no :                    Station number to be read           */
/*      USHORT *rctrl :                 Received St. Address and CTRL code  */
/*      USHORT *rbuffp :                Pointer of Receive buffer           */
/*      UINT size :                     Buffer size                         */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<3> fix calculation of ubp reg. data                      */
/*            1.30<4> delete the station number check                       */
/*                                                                          */
/****************************************************************************/
int yns_read_ldata2( CHANNEL_INFO *chbuffp, UINT st_no, 
					USHORT *rctrl, USHORT *rbuffp, UINT size)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	int		ret;			/* Return code */
	USHORT	ubp_data;		/* Offset address */
	USHORT	*prd;			/* read buffer pointer */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Check Station number */
	if (chbuffp->ma_max < st_no)
	{
		return ERROR_INVALID_ST_NO;
	}

/* Read data */
	if(size > (UINT)(chbuffp->link_sz - 1))
	{
		size = chbuffp->link_sz - 1;
	}
	ret = size;

/* Get receive buffer offset */
	ubp_data = chbuffp->link_radr[chbuffp->alt_buff];

/* Add offset of station number */
	ubp_data += (USHORT)(chbuffp->link_sz * st_no);

/* Set offset address to UBP.reg */
	ynb_set_ubp( hirp, ubp_data );

/* Save receive status */
	*rctrl = ynb_get_ubd( hirp );

/* Check receive status, when data is from slave. */
	if (*rctrl == CLR_CTRL_CODE)
	{
		return ERROR_RECV_DATA;	/* Receive error */
	}

	prd = rbuffp;			/* set buffer pointer */
/* Read from UBD */
	while ( (size--) > 0 )
	{
		*prd = ynb_get_ubd( hirp );
    	++prd;
	}

	ynb_set_ubp( hirp, ubp_data );
	ynb_set_ubd( hirp, CLR_CTRL_CODE );	/* Set CTRL code */

	return ret;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_write_ldata2()            Write cyclic trans. data or link data*/
/*                                                                          */
/*Function :                                                                */
/*      Write cyclic trans. data in 1NS/2NS.                                */
/*                                                                          */
/*Return code :                                                             */
/*      short :                         n >= 0 : size of written data (word)*/
/*                                      n < 0 : error code                  */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*      UINT st_no :                    Station number to be write          */
/*      USHORT sctrl :                  St. Address and CTRL code           */
/*      USHORT *sbuffp :                Pointer of Send Buffer              */
/*      UINT size :                     Buffer size                         */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<3> fix calculation of ubp reg. data                      */
/*            1.30<4> delete the station number check                       */
/*                                                                          */
/****************************************************************************/
int yns_write_ldata2( CHANNEL_INFO *chbuffp, 
					UINT st_no, USHORT sctrl, USHORT *sbuffp, UINT size )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT 	ubp_data;		/* Offset address */
	USHORT	*pwt;			/* write buffer pointer */
	int 	ret;			/* Return code */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Check Station number */
	if (chbuffp->ma_max < st_no)
	{
		return ERROR_INVALID_ST_NO;
	}

/* Check data size */
	if(size > (UINT)(chbuffp->link_sz -1))
	{
		size = chbuffp->link_sz -1;
	}
	ret = size;

/* Get receive buffer offset */
	ubp_data = 0;
	if (chbuffp->buff_mod == YN_MOD_BMOD_ALT)
	{
		ubp_data = chbuffp->link_sadr[chbuffp->alt_buff];
	}

/* Add offset of station number */
	ubp_data += (USHORT)(chbuffp->link_sz * st_no);

/* Set offset address to UBP.reg */
	ynb_set_ubp( hirp, ubp_data);

/* Set ST# and CTRL code */
	ynb_set_ubd( hirp, sctrl );

/* Write UBD data */
	pwt = sbuffp;
	while((size--) > 0)
	{
		ynb_set_ubd( hirp, *pwt );
        pwt++;
	}

	return ret;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_begin_link_acc()      Begin link read/write access              */
/*                                                                          */
/*Function :                                                                */
/*      Begin link read/write access                                        */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                          Normal End                            */
/*      ERROR_ALT_BUFFER :            Toggle buffer error                   */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *pchannel :      Channel buffer address                */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_begin_link_acc( CHANNEL_INFO *pchannel )
{
	UINT	i;
	USHORT	sts;
	USHORT	ints;
	int		ret = OK;

/* Reset Watch Dog Timer */
	ynb_set_cmd(pchannel->hif_reg_top, YN_CMD_WD_R);
	pchannel->ubp_data = ynb_get_ubp( pchannel->hif_reg_top );

/* Check buffer mode */
	if( pchannel->buff_mod == YN_MOD_BMOD_STATIC )
	{
		pchannel->alt_buff = 0;
		return ret;
	}

/* Communication cycle start interupt	*/
/* Check start complete					*/
	for(i = 0 ; i < POLL_TIMES20 ; i++)
	{
		ints = ynb_get_ints( pchannel->hif_reg_top );
		if((ints & YN_INTS_TXST_I) != 0)
		{
			break;
		}
	}

	if(i == POLL_TIMES20)
	{
	/* Start not complete		*/
		ret = ERROR_ALT_BUFFER;
	}
	else
	{
	/* Get alt. buffer	*/
		sts = ynb_get_sts( pchannel->hif_reg_top );
		pchannel->alt_buff = ((sts & YN_STS_LTX_UA) ? 1 : 0);
	}

	return ret;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_end_link_acc()        Finish link read/write access             */
/*                                                                          */
/*Function :                                                                */
/*      Finish link read/write access                                       */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                              Normal End                        */
/*      ERROR_TOGGLE_BUFFER :             Toggle buffer error               */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *pchannel :       Channel buffer address               */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*                                                                          */
/****************************************************************************/
int yns_end_link_acc( CHANNEL_INFO *pchannel )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT		regs;
	USHORT		sts;
	int			ret = OK;

	hirp = pchannel->hif_reg_top;

	ynb_set_ubp( hirp, pchannel->ubp_data );	/* Set old UBP */
	ynb_clear_ints( hirp, YN_INTS_TXST_I );	/* Clear TXST_I */

/* Check buffer mode	*/
	if( pchannel->buff_mod != YN_MOD_BMOD_STATIC )
	{
	/* Request change alt. buffer	*/
		sts = ynb_get_sts( hirp );
		regs = ((sts & YN_STS_LTX_UA) ? YN_CMD_LTX_RB : YN_CMD_LTX_RA);
		ynb_set_cmd( hirp, regs );
	}
	else
	{
	/* Request send (for static buffer mode)	*/
		ynb_set_cmd( hirp, YN_CMD_LTX_RA );
	}

	return(ret);
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*      yns_read_comstat()        Read Jl-098 STS regs.                     */
/*                                                                          */
/*Function :                                                                */
/*      This function read STS register. If error is detected, set          */
/*     ESTS reg. value to err parameter.                                    */
/*                                                                          */
/*Reference :                                                               */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                              Normal End                        */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *pchannel :     Channel buffer address                 */
/*                                                                          */
/*Reused module :                                                           */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<2> fix return code of yns_read_comstat()                 */
/*                                                                          */
/****************************************************************************/
USHORT yns_read_comstat( CHANNEL_INFO *pchannel)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT			ret = 0;

	hirp = pchannel->hif_reg_top;

/* Check STS regs. */
	ret = ynb_get_ests( hirp );
	ynb_clear_ests( hirp, ret);

	return (ESTS_MASK & ret);
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_set_netclk()               Write network time to global data   */
/*                                                                          */
/*Function :                                                                */
/*      Write network time to global data.                                  */
/*                                                                          */
/*Return code :                                                             */
/*      USHORT :                        network time [trans. cycle]         */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*      UINT cycle :                    access time                         */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<3> fix calculation of ubp reg. data                      */
/*                                                                          */
/****************************************************************************/
USHORT yns_set_netclk( CHANNEL_INFO *chbuffp, UINT cycle )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	ubp_data;		/* Offset address */
	USHORT	clk;			/* network time */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Get receive buffer offset */
	ubp_data = 0;
	if (chbuffp->buff_mod  == YN_MOD_BMOD_ALT)
	{
		ubp_data = chbuffp->link_sadr[chbuffp->alt_buff];
	}

/* Set offset address to UBP.reg */
	ynb_set_ubp( hirp, ubp_data + 4 );

/* Write UBD data */
	clk = chbuffp->net_clk + cycle;
	ynb_set_ubd( hirp, clk );

	chbuffp->net_clk = clk;
	return clk;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_get_netclk()               Read network time to global data    */
/*                                                                          */
/*Function :                                                                */
/*      Read network time to global data.                                   */
/*                                                                          */
/*Return code :                                                             */
/*      USHORT :                        network time [trans. cycle]         */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*                                                                          */
/*Note :                                                                    */
/*                                                                          */
/*Log :                                                                     */
/*            1.30<3> fix calculation of ubp reg. data                      */
/*                                                                          */
/****************************************************************************/
USHORT yns_get_netclk( CHANNEL_INFO *chbuffp )
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	ubp_data;		/* Offset address */

/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Get receive buffer offset */
	ubp_data = chbuffp->link_radr[chbuffp->alt_buff];

/* Set offset address to UBP.reg */
	ynb_set_ubp( hirp, ubp_data + 4 );

/* Read UBD data */
	chbuffp->net_clk = ynb_get_ubd( hirp );

	return chbuffp->net_clk;
}


/*func*/
/****************************************************************************/
/*                                                                          */
/*Name :                                                                    */
/*       yns_get_gblstat()                Get the status of global frame    */
/*                                                                          */
/*Function :                                                                */
/*      Get the status of global frame.                                     */
/*                                                                          */
/*Return code :                                                             */
/*      OK :                              Normal End                        */
/*                                                                          */
/*Parameter :                                                               */
/*      CHANNEL_INFO *chbuffp :         Channel buffer address              */
/*      t_mcyc                :         transmission cycle time             */
/*                                                                          */
/*Note :                                                                    */
/*      Slave station only                                                  */
/*Log :                                                                     */
/*            1.30<1> add a new function : yns_get_gblstat()                */
/*                                                                          */
/****************************************************************************/
int yns_get_gblstat( CHANNEL_INFO *chbuffp, USHORT *t_mcyc)
{
	volatile YENET_HOST_IF_REGS *hirp;	/* Host I/F Top address */
	USHORT	ubp_data;		/* Offset address */
	int		rc;
	USHORT	sts;

	*t_mcyc = 0;
/* Get Host I/F register top address */
	hirp = chbuffp->hif_reg_top;

/* Get receive buffer offset */
	ubp_data = chbuffp->link_radr[chbuffp->alt_buff];

/* Read Global status */
	sts = ynb_get_ints( hirp );

/* Check Global status */
	if((sts & YN_INTS_SFR) != 0)
	{
		ynb_set_ubp( hirp, ubp_data );
		sts = ynb_get_ubd( hirp );
		if(sts == CLR_CTRL_CODE)	/* invalid inturrput */
		{
			rc = ERROR_NO_SYNC;
		}
		else	/* ok */
		{
			*t_mcyc = ynb_get_ubd( hirp );
			rc = OK;
		}
	}
	else	/* not receive */
	{
		rc = ERROR_SYNC_NO_RECV;
	}

	ynb_clear_ints( hirp, YN_INTS_SFR );	/* clear status */
	ynb_set_ubp( hirp, ubp_data );
	ynb_set_ubp( hirp, CLR_CTRL_CODE );	/* clear status */

	return sts;
}

/* defines */
#define LINK_SIZE			8			/* Link data size [in words] 16 means 32 bytes */
#define SLV_ST_MAX			8			/* Maximum Number of Slaves */
#define COM_TIME			1			/* Communication Cycle[multiple of Transmission Cycle] */
//#define HOST_IF_REGS_ADDR	0xDE000000	/* JL-098 register start address */
USHORT* HOST_IF_REGS_ADDR;

/* globals */
CHANNEL_INFO	chbuff;								/* Channel Buffer */
USHORT			lnk_sbuff[SLV_ST_MAX][LINK_SIZE];	/* Send Buffer */
USHORT			lnk_rbuff[SLV_ST_MAX][LINK_SIZE];	/* Receive Buffer */
USHORT			lnk_sctrl[SLV_ST_MAX];				/* Send Link Header  */
USHORT			lnk_rctrl[SLV_ST_MAX];				/* Receive Link Header */
UINT			err_axis;							/* Staion # which error occured */

/* forward declarations */
static int mst_init(void);						/* Initialize MECHATROLINK communicaiton(Setup JL-098) */
/* Send/Recieve Link data in cyclic communication */
static int mst_exchange(USHORT	sbuff[][LINK_SIZE], USHORT rbuff[][LINK_SIZE]);
static void Set_st_addr(UCHAR* pst);			/* Set Station addresses */

/****************************************************************************/
/*                                                                          */
/* Name :                                                                   */
/*        Sample of JL-098 Initialization procedure                         */
/* Function:                                                                */
/*       Initializing JL-098                                                */
/* Conditions:                                                              */
/*                  Protocol : MECHATROLINK-II(2:N Communication)           */
/*               Buffer mode : Fixed buffer mode                            */
/*                     Speed : 10Mbps                                       */
/*        Transmission cycle : 1ms                                          */
/*               Packet Size : 32[byte]                                     */
/*       C2 Master Time slot : Use time slot for C2 master                  */
/*                                                                          */
/* Return Code :                                                            */
/*      OK :                            Normal End                          */
/*      ERROR_INIT_CHANNEL :            Invalid channel buffer specified    */
/*      ERROR_POLL_TIMEOUT :            Request did not completed           */
/*      ERROR_NOT_READY :               JL-098 Not Ready (STS(RDY) is zero.)*/
/*      ERROR_INVALID_PROTOCOL :        Unsupported protocol                */
/*      ERROR_INVALID_BMODE :           Unsupported buffer mode             */
/*      ERROR_POLL_TIMEOUT_REG :        P_RSTAK Request did not completed   */
/*      ERROR_POLL_TIMEOUT_PAR :        PAR_I Request did not completed     */
/*      ERROR_POLL_TIMEOUT_ENA :        Request did not completed           */
/****************************************************************************/
static int mst_init(void)
{
	CHANNEL_INFO*	chbufp;		/* Channel Buffer */
	YENET_USER_PAR	usr_par;	/* Communication Parameters */
	UCHAR			st_addr[SLV_ST_MAX+1];	/* Slave Addresses */
	int				ret = 0;	/* return code */

	chbufp = &chbuff;	/* Get the pointer of Channel Buffer */

/* Check JL-098 RAM */
/* Read/Write check 4096 words from address 0 */
#if 0
	if((ret = yns_check_ram((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0x5aa5)) != OK)
		return ret;
	if((ret = yns_check_ram((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0xa55a)) != OK)
		return ret;
	if((ret = yns_check_ram((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0x0000)) != OK)
		return ret;
#endif
/*
Cycle[ms]  Data size
          17byte 32byte
0.25		2	1
0.5			7	4
1.0			15	9
1.5			23	15
2.0			30	21
2.5			30	26
3.0			30	30
3.5			30	30
4.0			30	30
4.5			30	30
5.0			30	30
5.5			30	30
6.0			30	30
6.5			30	30
7.0			30	30
7.5			30	30
8.0			30	30
*/
/* Setup parameters of JL-098 */
	usr_par.mod = YN_MOD_PROCEL_2NS | YN_MOD_SPEED_10M | YN_MOD_BMOD_ALT
				| YN_MOD_TYPE_MASTER | YN_MOD_INT_FRS;

	usr_par.ma = 0x01;			/* My Address(C1 Master) */
	usr_par.ma_max = SLV_ST_MAX;/* Maximum Number of Slaves */
	usr_par.t_mcyc = 4000;		/* Transmission cycle[0.25us] */
	usr_par.t_cyc = 240;		/* Time slot[0.25us] */
	usr_par.byte = 17;			/* Packet size */
	usr_par.dev = 0;			/* INT1 dividing ratio(for INT2 output) */
	usr_par.max_rtry = 1;		/* Max. number of Retries per Transmission cycle */
	usr_par.c2m_ch = 0;			/* Time slot for C2 Master(0:not use, 1:use) */
	usr_par.wdt = 15;			/* Watch dog timer [10ms]; if wdt=0, WDT function disabled */

/* Setup Station addresses */
	Set_st_addr(st_addr);

/* JL-098 Initialization */
	ret = yns_sequent_init(chbufp, (USHORT*)HOST_IF_REGS_ADDR, &usr_par, st_addr);

	return ret;
}


/****************************************************************************/
/*                                                                          */
/* Name :                                                                   */
/*       Sample of send/recieve data procedure                              */
/*                                                                          */
/* Function :                                                               */
/*      Setting data in the lnk_sbuff to JL-098, and saving received data   */
/*      to the lnk_rbuff.                                                   */
/*                                                                          */
/* Return Code:                                                             */
/*      OK :                          Normal End                            */
/*      ERROR_ALT_BUFFER :            Time out of Toggle buffer             */
/*      ERROR_INVALID_ST_NO :         Invalid Channel No.                   */
/*      ERROR_RECV_DATA:              Receive error                         */
/*      ERROR_JL098_APPL:             JL-098 status error(user)             */
/*      ERROR_JL098_SYSTEM:           JL-098 status error(system)           */
/****************************************************************************/
static int mst_exchange(USHORT	sbuff[][LINK_SIZE], USHORT rbuff[][LINK_SIZE])
{
	CHANNEL_INFO*	chbufp;		/* Channel Buffer */
	USHORT			ests;		/* Error Status */
	int				ch;			/* Channel No. */
	int				ret = OK, rc;/* return code */

	chbufp = &chbuff;	/* Set pointer of Channel Buffer */

/* Start cyclic communication */
	if((ret = yns_begin_link_acc(chbufp)) != OK)
	{
	/* Error detection */
		yns_set_netclk(chbufp, COM_TIME);	/* Update Network time-stamp (for C2-Master) */
		yns_end_link_acc(chbufp);			/* Terminate cyclic communication */
		return ret;
	}

/* JL-098 status error(ESTS) check */
	if((ests = yns_read_comstat(chbufp)) != 0)
	{
		if(ests & YN_ESTS_SYS_ERR)
		{	/* JL-098 System error!! */
			yns_end_link_acc(chbufp);
			return ERROR_JL098_SYSTEM;	/* Stop cyclic communication */
		}
		else
		{	/* JL-098 Application(user) error!! */
			yns_end_link_acc(chbufp);
			return ERROR_JL098_APPL;	/* Stop cyclic communication */
		}
	}

/* Send/Receive Process for all stations(slaves) */
	for(ch = 0; ch < chbufp->ma_max; ch++)
	{
	/* Send [buffer->JL-098] */
/*		yns_write_ldata(chbufp, ch+1, lnk_sbuff[ch], LINK_SIZE); */
		yns_write_ldata2(chbufp, ch+1, lnk_sctrl[ch], sbuff[ch], LINK_SIZE); /* Send data with CTRL code */

	/* Receive [JL-098->buffer] */
/*		if((rc = yns_read_ldata(chbufp, 
				ch+1, lnk_rbuff[ch], LINK_SIZE)) < 0) */
		if((rc = yns_read_ldata2(chbufp, 
				ch+1, &lnk_rctrl[ch], rbuff[ch], LINK_SIZE)) < 0) /* Receive data with CTRL code */
		{
		/* Error detection */
			err_axis |= (0x1 << ch);	/* set station number which occurred receive error */
			ret = rc;
		}
	}

/* Finish link read/write access */
	yns_set_netclk(chbufp, COM_TIME);	/* Update Network Time-stamp (for C2-Master) */
	yns_end_link_acc(chbufp);

	return ret;
}


/****************************************************************************/
/*                                                                          */
/* Name :                                                                   */
/* Set station address                                                      */
/*                                                                          */
/* Function :                                                               */
/*      Convert station number to station address                           */
/* Conditions:                                                              */
/*      Setting all servodrive addresses or 41H - 41H + SLV_ST_MAX          */
/*                                                                          */
/****************************************************************************/
static void Set_st_addr(UCHAR* pst)
{
	int	ch;

	pst[0] = 0xFF;	/* Global address(for Sync frame) */
	for(ch = 1; ch <= SLV_ST_MAX; ch++)
	{
		pst[ch] = 0x40 + ch;	/* Station address(for Servo drive) */
		lnk_sctrl[ch-1] = (YN_CTRL_CDRW << 8) | pst[ch];	/* Set Link Header */
	}
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

#define JL098_BUFFER_SIZE	4

#define CYCLE_INC(d)	(((d)+1)&(JL098_BUFFER_SIZE-1))
#define IS_CYCLE_BUFFER_FULL(buffer)	(CYCLE_INC((buffer).head) == ((buffer).tail))
#define IS_CYCLE_BUFFER_EMPTY(buffer)	((buffer).head == (buffer).tail)

#define DEVICE_NAME		"jl098"

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

typedef union {
	uint16_t data[LINK_SIZE];
	struct{
		uint8_t cmd;
		uint8_t alarm;
		uint16_t status;
		uint8_t pad[11];
		uint8_t wdt;
	};
}jl098_chdata_t;

typedef jl098_chdata_t jl098_data_t[SLV_ST_MAX];

typedef struct jl098_cyclebuf{
	jl098_data_t data[JL098_BUFFER_SIZE];
	int head;
	int tail;
	wait_queue_head_t wq;
}jl098_cyclebuf_t;

struct jl098_info {
	struct device *dev;
	uint16_t __iomem *iobase;
	unsigned long iosize;
	raw_spinlock_t lock;

	jl098_cyclebuf_t sbuff;/* Send Buffer */
	jl098_cyclebuf_t rbuff;/* Recv Buffer */
	int pulse_running;
	unsigned int break_time;
	unsigned int max_break_time;
	unsigned int irq;

	unsigned int offset;
	unsigned int interrupt_lost;
	unsigned int pulse_queue_break;
	struct miscdevice miscdev;
	uint8_t alarm_code[SLV_ST_MAX];
	uint16_t status_code[SLV_ST_MAX];
};

static struct jl098_info *rbt_info_p;

static inline void jl098_writew(struct jl098_info *info,
		uint16_t val, unsigned int off)
{
	__raw_writew(val, info->iobase + off);
}

static inline uint16_t jl098_readw(struct jl098_info *info,
		unsigned int off)
{
	return __raw_readw(info->iobase + off);
}

static inline jl098_data_t* AllocFreeBuffer(jl098_cyclebuf_t *buff)
{
	jl098_data_t* pdata;

	if(IS_CYCLE_BUFFER_FULL(*buff)){
		return NULL;
	}

	pdata = &buff->data[buff->head];

	return pdata;
}

static inline void PushBuffer(jl098_cyclebuf_t *buff)
{
	buff->head = CYCLE_INC(buff->head);
}

static inline jl098_data_t* GetFreeBuffer(jl098_cyclebuf_t *buff)
{
	jl098_data_t* pdata = AllocFreeBuffer(buff);

	if(pdata==NULL){
		return NULL;
	}

	PushBuffer(buff);
	return pdata;
}

static inline jl098_data_t* GetBufferData(jl098_cyclebuf_t *buff)
{
	jl098_data_t* pdata;

	if(IS_CYCLE_BUFFER_EMPTY(*buff)){
		return NULL;
	}

	pdata = &buff->data[buff->tail];
	buff->tail = CYCLE_INC(buff->tail);

	return pdata;
}

/*
 * /sys/devices/platform/rbt_fpga.N
 */
static ssize_t jl098_get_status(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct jl098_info *info = platform_get_drvdata(pdev);
	int i,n=0;

	for(i=0;i<SLV_ST_MAX;i++){
		n += sprintf(buf+n, "%d status:0x%x, last alarm: 0x%x\n", 
			i, info->status_code[i], info->alarm_code[i]);
	}
	return n;
}

static ssize_t jl098_get_address(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct jl098_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "0x%x\n", info->offset);
}

static ssize_t jl098_set_address(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct jl098_info *info = platform_get_drvdata(pdev);

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

static ssize_t jl098_get_data(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct jl098_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "0x%x:0x%x\n", info->offset, jl098_readw(info, info->offset));
}

static ssize_t jl098_set_data(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct jl098_info *info = platform_get_drvdata(pdev);

	unsigned long val;
	int err;

	err = strict_strtol(buf, 0, &val);
	if (err)
		return -EINVAL;

	jl098_writew(info, val, info->offset);

	return count;
}

static ssize_t jl098_regdump(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct jl098_info *info = platform_get_drvdata(pdev);

	unsigned long i, n=0;
	for(i=0;i<info->iosize/2;i++){
		if((i&0x7)==0)
			n += sprintf(buf+n, "0x%04lx: ", i);
		n += sprintf(buf+n, "0x%04x", jl098_readw(info, i));
		if((i&0x7)==7)
			n += sprintf(buf+n, "\n");
		else
			n += sprintf(buf+n, ",");
	}

	return n;
}

static ssize_t jl098_errordump(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct jl098_info *info = platform_get_drvdata(pdev);

	return sprintf(buf, "interrupt lost: %d\npulse queue break: %d\nmax break tick: %d\n", 
		info->interrupt_lost, info->pulse_queue_break, info->max_break_time);
}

static DEVICE_ATTR(status, S_IWUSR | S_IRUGO,jl098_get_status, NULL);
static DEVICE_ATTR(address, S_IWUSR | S_IRUGO, jl098_get_address, jl098_set_address);
static DEVICE_ATTR(data, S_IWUSR | S_IRUGO, jl098_get_data, jl098_set_data);
static DEVICE_ATTR(regdump, S_IWUSR | S_IRUGO, jl098_regdump, NULL);
static DEVICE_ATTR(error, S_IWUSR | S_IRUGO, jl098_errordump, NULL);

static struct attribute *jl098_attrs[] = {
	&dev_attr_status.attr,
	&dev_attr_address.attr,
	&dev_attr_data.attr,
	&dev_attr_regdump.attr,
	&dev_attr_error.attr,
	NULL
};

static const struct attribute_group jl098_sysfs_files = {
	.attrs	= jl098_attrs,
};

static irqreturn_t jl098_irq_handler(int irq, struct jl098_info *info)
{
	unsigned long flags;
	jl098_data_t *sdata, *rdata;
	jl098_chdata_t *ps, *pr;
	uint8_t alarm;
	int i, nNop, rfull=0;
	static uint8_t rsn[SLV_ST_MAX], mn;

	static jl098_data_t sdata_nop, rdata_buff;

	raw_spin_lock_irqsave(&info->lock,flags);
	sdata = GetBufferData(&info->sbuff);
	if(sdata==NULL)
		sdata = &sdata_nop;
	else if(info->pulse_running){
		info->break_time++;
		if(info->break_time > info->max_break_time)
			info->max_break_time = info->break_time;
	}

	rdata = AllocFreeBuffer(&info->rbuff);
	if(rdata==NULL){
		rdata = &rdata_buff;
		rfull = 1;
	}

	//update wdt
	ps=(jl098_chdata_t *)sdata;
	for(i=0;i<SLV_ST_MAX;i++){
		ps[i].wdt = rsn[i]|mn;
	}
	mn=(mn+1)&0xf;
	
	mst_exchange((uint16_t (*)[LINK_SIZE])sdata, (uint16_t (*)[LINK_SIZE])rdata);
	wake_up_interruptible(&info->sbuff.wq);

	pr=(jl098_chdata_t *)rdata;
	nNop=0;

	for(i=0;i<SLV_ST_MAX;i++){
		rsn[i] = pr[i].wdt&0xf0;
		if(pr[i].cmd==0){//nop response
			nNop++;
		}
		info->status_code[i] = pr[i].data[1];
		alarm = pr[i].data[0]>>8;
		if(alarm!=0)
			info->alarm_code[i] = alarm;
	}

	if(nNop!=i && !rfull){
		PushBuffer(&info->rbuff);
		wake_up_interruptible(&info->rbuff.wq);
	}

	if(info->break_time){
		dev_info(info->dev, "pulse queue %d break %d tick\n", ++info->pulse_queue_break, info->break_time);
		info->break_time = 0;
	}

	raw_spin_unlock_irqrestore(&info->lock,flags);

	return IRQ_HANDLED;
}

static ssize_t jl098_data_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	struct jl098_info *info = rbt_info_p;
	jl098_data_t *data;
	int ret;
	unsigned long flags;

	if(count>sizeof(jl098_data_t)){
		dev_err(info->dev, "%s: frame size can't big than %d error\n", 
			__FUNCTION__, sizeof(jl098_data_t));
		return -EINVAL;
	}

	ret = wait_event_interruptible(info->sbuff.wq, !IS_CYCLE_BUFFER_FULL(info->sbuff));
	if(ret<0)
		return ret;

	raw_spin_lock_irqsave(&info->lock,flags);

	data = GetFreeBuffer(&info->sbuff);
	if(data==NULL){
		raw_spin_unlock_irqrestore(&info->lock,flags);
		dev_err(info->dev, "wait out but buffer full\n");
		return count;
	}

//	info->pulse_running=1;

	copy_from_user(data, buf, count);
	raw_spin_unlock_irqrestore(&info->lock,flags);
	
	return count;
}

static ssize_t jl098_data_read(struct file *file, 
	char __user *buf, size_t count, loff_t *ppos)
{
	struct jl098_info *info = rbt_info_p;
	jl098_data_t *data;
	int ret;
	unsigned long flags;

	if(count>sizeof(jl098_data_t)){
		dev_err(info->dev, "%s: frame size can't big than %d error\n", 
			__FUNCTION__, sizeof(jl098_data_t));
		return -EINVAL;
	}

	if(file->f_flags & O_NONBLOCK){
		if(IS_CYCLE_BUFFER_EMPTY(info->rbuff))
			return -EBUSY;
	}
	else{
		ret = wait_event_interruptible(info->rbuff.wq, !IS_CYCLE_BUFFER_EMPTY(info->rbuff));
		if(ret<0)
			return ret;
	}

	raw_spin_lock_irqsave(&info->lock,flags);

	data = GetBufferData(&info->rbuff);
	if(data==NULL){
		raw_spin_unlock_irqrestore(&info->lock,flags);
		if(!(file->f_flags & O_NONBLOCK))
			dev_err(info->dev, "wait but buffer empty\n");
		return -EBUSY;
	}

	copy_to_user(buf, data, count);
	raw_spin_unlock_irqrestore(&info->lock,flags);
	
	return count;
}

static const struct file_operations jl098_data_fops = {
	.owner		= THIS_MODULE,
	.llseek 	= noop_llseek,
	.write		= jl098_data_write,
	.read		= jl098_data_read,
};

static int __init jl098_init_dev(struct jl098_info *info)
{
	int ret;

	if(request_irq(info->irq, (irq_handler_t)jl098_irq_handler, 
			IRQF_TRIGGER_FALLING|IRQF_NO_THREAD|IRQF_DISABLED|IRQF_NOBALANCING|IRQF_NO_SOFTIRQ_CALL, DEVICE_NAME, info)<0){
		printk("jl098 request irq %d failed!\n", info->irq);
		return -ENXIO;
	}

	/* Setup the miscdevice */
	info->miscdev.minor = MISC_DYNAMIC_MINOR;
	info->miscdev.name = "jl098";
	info->miscdev.fops = &jl098_data_fops;

	ret = misc_register(&info->miscdev);
	if(ret<0){
		printk("Failed to register fpga io device\n");
		free_irq(info->irq, info);
		return ret;
	}

	ret = mst_init();
	if(ret!=OK){
		dev_err(info->dev, "init failed %d\n", ret);
		return ret;
	}

	rbt_info_p = info;

	return 0;
}

static int __exit jl098_remove_dev(struct jl098_info *info)
{
	int ret;

	free_irq(info->irq, info);

	ret = misc_deregister(&info->miscdev);
	if(ret<0){
		dev_err(info->dev, "Failed to deregister fpga pulse device\n");
		return ret;
	}

	return 0;
}

static int __init jl098_probe(struct platform_device *pdev)
{
	struct jl098_info *info;
	struct resource *res;
	uint16_t v;
	int err;
	int ret = 0, i;	/* return code */

	info = kzalloc(sizeof(struct jl098_info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	raw_spin_lock_init(&info->lock);
	init_waitqueue_head(&info->sbuff.wq);
	init_waitqueue_head(&info->rbuff.wq);
	info->dev=&pdev->dev;

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
	info->iosize = 256;//resource_size(res);

	err = platform_get_irq(pdev, 0);
	if(err<0)
		goto fail_no_rbt_fpga;
	info->irq = err;

	HOST_IF_REGS_ADDR=(USHORT*)(info->iobase);

	// Check chip ID
	v = jl098_readw(info, 0x10);
	if((v&0xFFF0)!=0x0880){
		err = -ENXIO;
		printk("Can't find jl098 Chip ret=0x%x!\n", v);
		goto fail_no_rbt_fpga;
	}
	printk("jl098 Chip ID=0x%04x\n", v);

	/* Check JL-098 RAM */
	/* Read/Write check 4096 words from address 0 */
	for(i=0;i<5;i++) {
		if((ret = yns_check_ram((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0x5aa5)) != OK){
			err = -ENXIO;
			printk("jl098 ram cheaking 0x5aa5 faile@cycle%d, step1, error coed: %d!\n",i,ret);
			goto fail_no_rbt_fpga;
		} else {printk("jl098 ram cheaking 0x5aa5 success@cycle%d, step1\n",i);}

		if((ret = yns_check_ram((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0xa55a)) != OK){
			err = -ENXIO;
			printk("jl098 ram cheaking 0xa55a faile@cycle%d, step2, error coed: %d!\n",i,ret);
			goto fail_no_rbt_fpga;
		} else {printk("jl098 ram cheaking 0xa55a success@cycle%d, step2\n",i);}

		if((ret = yns_check_ram_fakerandom((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0x1234)) != OK){
			err = -ENXIO;
			printk("jl098 ram cheaking fakerandom faile@cycle%d, step3, error coed: %d!\n",i,ret);
			goto fail_no_rbt_fpga;
		} else {printk("jl098 ram cheaking fakerandom success@cycle%d, step3\n",i);}


		if((ret = yns_check_ram((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0xFFFF)) != OK){
			err = -ENXIO;
			printk("jl098 ram cheaking 0x0000 faile@cycle%d, step4, error coed: %d!\n",i,ret);
			goto fail_no_rbt_fpga;
		} else {printk("jl098 ram cheaking 0x0000 success@cycle%d, step4\n",i);}

		if((ret = yns_check_ram((USHORT*)HOST_IF_REGS_ADDR, 0, DEF_RAM_SIZE, 0x0000)) != OK){
			err = -ENXIO;
			printk("jl098 ram cheaking 0x0000 faile@cycle%d, step5, error coed: %d!\n",i,ret);
			goto fail_no_rbt_fpga;
		} else {printk("jl098 ram cheaking 0x0000 success@cycle%d, step5\n",i);}

	}

	err = jl098_init_dev(info);
	if(err<0)
		goto fail_no_rbt_fpga;

	err = sysfs_create_group(&pdev->dev.kobj, &jl098_sysfs_files);
	if (err)
		goto fail_no_sysfs;

	platform_set_drvdata(pdev, info);

	dev_info(&pdev->dev, "jl098@0x%x irq(%d)\n", res->start, info->irq);

	return 0;

	sysfs_remove_group(&pdev->dev.kobj, &jl098_sysfs_files);
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

static int __exit jl098_remove(struct platform_device *pdev)
{
	struct jl098_info *info = platform_get_drvdata(pdev);
	struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	jl098_remove_dev(info);

	platform_set_drvdata(pdev, NULL);
	sysfs_remove_group(&pdev->dev.kobj, &jl098_sysfs_files);
	iounmap(info->iobase);
	release_mem_region(res->start, resource_size(res));
	kfree(info);

	return 0;
}

static struct of_device_id of_jl098_match[] = {
	{
		.compatible	= "yaskawa,jl098",
	},
	{ },
};
MODULE_DEVICE_TABLE(of, of_jl098_match);

static struct platform_driver jl098_driver = {
	.driver		= {
		.name	= DEVICE_NAME,
		.owner	= THIS_MODULE,
		.of_match_table = of_jl098_match,
	},
	.probe		= jl098_probe,
	.remove		= __exit_p(jl098_remove),
};

static int __init jl098_init(void)
{
	return platform_driver_register(&jl098_driver);
}

static void __exit jl098_exit(void)
{
	platform_driver_unregister(&jl098_driver);
}

late_initcall(jl098_init);
module_exit(jl098_exit);

MODULE_DESCRIPTION("jl098 driver");
MODULE_LICENSE("GPL");

