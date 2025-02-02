

#ifndef __LRRCWRRCINTERFACE_H__
#define __LRRCWRRCINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include  "vos.h"
#include  "LPSCommon.h"
#include  "LRrcGuRrcCommInterface.h"


/*****************************************************************************
  #pragma pack(*)    设置字节对齐方式
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 Macro
*****************************************************************************/

#define LRRC_WRRC_MSG_HDR                (PS_MSG_ID_LRRC_TO_WRRC_BASE)
#define WRRC_LRRC_MSG_HDR                (PS_MSG_ID_WRRC_TO_LRRC_BASE)

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 枚举名    :
 协议表格  :
 ASN.1描述 :
 枚举说明  :
*****************************************************************************/
enum LRRC_WRRC_MSG_TYPE_ENUM
{
    /* W -> L Cell Resel */
    ID_WRRC_LRRC_CELL_RESEL_REQ             = (WRRC_LRRC_MSG_HDR + 0x00),       /* _H2ASN_MsgChoice WRRC_LRRC_CELL_RESEL_REQ_STRU */        /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_CELL_RESEL_CNF             = (LRRC_WRRC_MSG_HDR + 0x00),       /* _H2ASN_MsgChoice LRRC_WRRC_CELL_RESEL_CNF_STRU */        /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_CELL_RESEL_STOP_REQ        = (WRRC_LRRC_MSG_HDR + 0x01),       /* _H2ASN_MsgChoice WRRC_LRRC_CELL_RESEL_STOP_REQ_STRU */   /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_CELL_RESEL_STOP_CNF        = (LRRC_WRRC_MSG_HDR + 0x01),       /* _H2ASN_MsgChoice LRRC_WRRC_CELL_RESEL_STOP_CNF_STRU */   /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* W -> L Redirect */
    ID_WRRC_LRRC_REDIRECTED_REQ             = (WRRC_LRRC_MSG_HDR + 0x02),       /* _H2ASN_MsgChoice WRRC_LRRC_REDIRECTED_REQ_STRU */        /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_REDIRECTED_CNF             = (LRRC_WRRC_MSG_HDR + 0x02),       /* _H2ASN_MsgChoice LRRC_WRRC_REDIRECTED_CNF_STRU */        /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_REDIRECTED_STOP_REQ        = (WRRC_LRRC_MSG_HDR + 0x03),       /* _H2ASN_MsgChoice WRRC_LRRC_REDIRECTED_STOP_REQ_STRU */   /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_REDIRECTED_STOP_CNF        = (LRRC_WRRC_MSG_HDR + 0x03),       /* _H2ASN_MsgChoice LRRC_WRRC_REDIRECTED_STOP_CNF_STRU */   /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* W -> L HO */
    ID_WRRC_LRRC_HANDOVER_REQ               = (WRRC_LRRC_MSG_HDR + 0x04),       /* _H2ASN_MsgChoice WRRC_LRRC_HANDOVER_REQ_STRU */          /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_HANDOVER_CNF               = (LRRC_WRRC_MSG_HDR + 0x04),       /* _H2ASN_MsgChoice LRRC_WRRC_HANDOVER_CNF_STRU */          /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_HANDOVER_STOP_REQ          = (WRRC_LRRC_MSG_HDR + 0x05),       /* _H2ASN_MsgChoice WRRC_LRRC_HANDOVER_STOP_REQ_STRU */     /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_HANDOVER_STOP_CNF          = (LRRC_WRRC_MSG_HDR + 0x05),       /* _H2ASN_MsgChoice LRRC_WRRC_HANDOVER_STOP_CNF_STRU */     /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* W -> L 低功耗 */
    ID_WRRC_LRRC_SET_DSP_POWER_REQ          = (WRRC_LRRC_MSG_HDR + 0x06),       /* _H2ASN_MsgChoice WRRC_LRRC_SET_DSP_POWER_REQ_STRU */     /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_SET_DSP_POWER_CNF          = (LRRC_WRRC_MSG_HDR + 0x06),       /* _H2ASN_MsgChoice LRRC_WRRC_SET_DSP_POWER_CNF_STRU */     /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* W -> L Get Ue Capability Info */
    ID_WRRC_LRRC_GETUECAPINFO_REQ           = (WRRC_LRRC_MSG_HDR + 0x07),       /* _H2ASN_MsgChoice WRRC_LRRC_GETUECAPINFO_REQ_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_GETUECAPINFO_CNF           = (LRRC_WRRC_MSG_HDR + 0x07),       /* _H2ASN_MsgChoice LRRC_WRRC_GETUECAPINFO_CNF_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* W -> L PLMN SEARCH */
    ID_WRRC_LRRC_PLMN_SEARCH_REQ            = (WRRC_LRRC_MSG_HDR + 0x08),       /* _H2ASN_MsgChoice WRRC_LRRC_PLMN_SEARCH_REQ_STRU */       /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_PLMN_SEARCH_CNF            = (LRRC_WRRC_MSG_HDR + 0x08),       /* _H2ASN_MsgChoice LRRC_WRRC_PLMN_SEARCH_CNF_STRU */       /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_PLMN_SEARCH_STOP_REQ       = (WRRC_LRRC_MSG_HDR + 0x09),       /* _H2ASN_MsgChoice WRRC_LRRC_PLMN_SEARCH_STOP_REQ_STRU */  /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_PLMN_SEARCH_STOP_CNF       = (LRRC_WRRC_MSG_HDR + 0x09),       /* _H2ASN_MsgChoice LRRC_WRRC_PLMN_SEARCH_STOP_CNF_STRU */  /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* W -> L Idle Meas */
    ID_WRRC_LRRC_IDLE_MEASURE_REQ           = (WRRC_LRRC_MSG_HDR + 0x0a),       /* _H2ASN_MsgChoice WRRC_LRRC_IDLE_MEASURE_REQ_STRU */      /* SendPid:WUEPS_PID_WCOM; RcvPid:PS_PID_ERMM */
    ID_LRRC_WRRC_IDLE_MEASURE_CNF           = (LRRC_WRRC_MSG_HDR + 0x0a),       /* _H2ASN_MsgChoice LRRC_WRRC_IDLE_MEASURE_CNF_STRU */      /* SendPid:PS_PID_ERMM; RcvPid:WUEPS_PID_WCOM */
    ID_LRRC_WRRC_IDLE_MEASURE_IND           = (LRRC_WRRC_MSG_HDR + 0x0b),       /* _H2ASN_MsgChoice LRRC_WRRC_IDLE_MEASURE_IND_STRU */      /* SendPid:PS_PID_ERMM; RcvPid:WUEPS_PID_WCOM */

    /* W -> L Conn Meas */
    ID_WRRC_LRRC_CONNECTED_MEASURE_REQ      = (WRRC_LRRC_MSG_HDR + 0x0b),       /* _H2ASN_MsgChoice WRRC_LRRC_CONNECTED_MEASURE_REQ_STRU */ /* SendPid:WUEPS_PID_WCOM; RcvPid:PS_PID_ERMM */
    ID_LRRC_WRRC_CONNECTED_MEASURE_CNF      = (LRRC_WRRC_MSG_HDR + 0x0c),       /* _H2ASN_MsgChoice LRRC_WRRC_CONNECTED_MEASURE_CNF_STRU */ /* SendPid:PS_PID_ERMM; RcvPid:WUEPS_PID_WCOM */
    ID_LRRC_WRRC_CONNECTED_MEASURE_IND      = (LRRC_WRRC_MSG_HDR + 0x0d),       /* _H2ASN_MsgChoice LRRC_WRRC_CONNECTED_MEASURE_IND_STRU */ /* SendPid:PS_PID_ERMM; RcvPid:WUEPS_PID_WCOM */

    /* W -> L RelAll */
    ID_WRRC_LRRC_RELALL_REQ                 = (WRRC_LRRC_MSG_HDR + 0x0c),       /* _H2ASN_MsgChoice WRRC_LRRC_RELALL_REQ_STRU */            /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_RELALL_CNF                 = (LRRC_WRRC_MSG_HDR + 0x0e),       /* _H2ASN_MsgChoice LRRC_WRRC_RELALL_CNF_STRU */            /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* L -> W Cell Resel*/
    ID_LRRC_WRRC_CELL_RESEL_REQ             = (LRRC_WRRC_MSG_HDR + 0x0f),       /* _H2ASN_MsgChoice LRRC_WRRC_CELL_RESEL_REQ_STRU */        /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_CELL_RESEL_CNF             = (WRRC_LRRC_MSG_HDR + 0x0d),       /* _H2ASN_MsgChoice WRRC_LRRC_CELL_RESEL_CNF_STRU */        /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_CELL_RESEL_STOP_REQ        = (LRRC_WRRC_MSG_HDR + 0x10),       /* _H2ASN_MsgChoice LRRC_WRRC_CELL_RESEL_STOP_REQ_STRU */   /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_CELL_RESEL_STOP_CNF        = (WRRC_LRRC_MSG_HDR + 0x0e),       /* _H2ASN_MsgChoice WRRC_LRRC_CELL_RESEL_STOP_CNF_STRU */   /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L-> W Redirect */
    ID_LRRC_WRRC_REDIRECTED_REQ             = (LRRC_WRRC_MSG_HDR + 0x11),       /* _H2ASN_MsgChoice LRRC_WRRC_REDIRECTED_REQ_STRU */        /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_REDIRECTED_CNF             = (WRRC_LRRC_MSG_HDR + 0x0f),       /* _H2ASN_MsgChoice WRRC_LRRC_REDIRECTED_CNF_STRU */        /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_REDIRECTED_STOP_REQ        = (LRRC_WRRC_MSG_HDR + 0x12),       /* _H2ASN_MsgChoice LRRC_WRRC_REDIRECTED_STOP_REQ_STRU */   /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_REDIRECTED_STOP_CNF        = (WRRC_LRRC_MSG_HDR + 0x10),       /* _H2ASN_MsgChoice WRRC_LRRC_REDIRECTED_STOP_CNF_STRU */   /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L-> W HO */
    ID_LRRC_WRRC_HANDOVER_REQ               = (LRRC_WRRC_MSG_HDR + 0x13),       /* _H2ASN_MsgChoice LRRC_WRRC_HANDOVER_REQ_STRU */          /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_HANDOVER_CNF               = (WRRC_LRRC_MSG_HDR + 0x11),       /* _H2ASN_MsgChoice WRRC_LRRC_HANDOVER_CNF_STRU */          /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_HANDOVER_STOP_REQ          = (LRRC_WRRC_MSG_HDR + 0x14),       /* _H2ASN_MsgChoice LRRC_WRRC_HANDOVER_STOP_REQ_STRU */     /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_HANDOVER_STOP_CNF          = (WRRC_LRRC_MSG_HDR + 0x12),       /* _H2ASN_MsgChoice WRRC_LRRC_HANDOVER_STOP_CNF_STRU */     /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L -> W 低功耗 */
    ID_LRRC_WRRC_SET_DSP_POWER_REQ          = (LRRC_WRRC_MSG_HDR + 0x15),       /* _H2ASN_MsgChoice LRRC_WRRC_SET_DSP_POWER_REQ_STRU */     /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_SET_DSP_POWER_CNF          = (WRRC_LRRC_MSG_HDR + 0x13),       /* _H2ASN_MsgChoice WRRC_LRRC_SET_DSP_POWER_CNF_STRU */     /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L-> W Get Ue Capability Info */
    ID_LRRC_WRRC_GETUECAPINFO_REQ           = (LRRC_WRRC_MSG_HDR + 0x16),       /* _H2ASN_MsgChoice LRRC_WRRC_GETUECAPINFO_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_GETUECAPINFO_CNF           = (WRRC_LRRC_MSG_HDR + 0x14),       /* _H2ASN_MsgChoice WRRC_LRRC_GETUECAPINFO_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L -> GU Idle Meas */
    ID_LRRC_GURRC_IDLE_MEASURE_REQ          = (LRRC_WRRC_MSG_HDR + 0x17),       /* _H2ASN_MsgChoice LRRC_GURRC_IDLE_MEASURE_REQ_STRU */     /* SendPid:PS_PID_ERMM; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_IDLE_MEASURE_CNF          = (WRRC_LRRC_MSG_HDR + 0x15),       /* _H2ASN_MsgChoice GURRC_LRRC_IDLE_MEASURE_CNF_STRU */     /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERMM */
    ID_GURRC_LRRC_IDLE_MEASURE_IND          = (WRRC_LRRC_MSG_HDR + 0x16),       /* _H2ASN_MsgChoice GURRC_LRRC_IDLE_MEASURE_IND_STRU */     /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERMM */

    /* L -> GU Conn Meas */
    ID_LRRC_GURRC_CONNECTED_MEASURE_REQ     = (LRRC_WRRC_MSG_HDR + 0x18),       /* _H2ASN_MsgChoice LRRC_GURRC_CONNECTED_MEASURE_REQ_STRU */    /* SendPid:PS_PID_ERMM; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_CONNECTED_MEASURE_CNF     = (WRRC_LRRC_MSG_HDR + 0x17),       /* _H2ASN_MsgChoice GURRC_LRRC_CONNECTED_MEASURE_CNF_STRU */    /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERMM */
    ID_GURRC_LRRC_CONNECTED_MEASURE_IND     = (WRRC_LRRC_MSG_HDR + 0x18),       /* _H2ASN_MsgChoice GURRC_LRRC_CONNECTED_MEASURE_IND_STRU */    /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERMM */

    /* L -> GU  Gsm Cell Bsic Verify  */
    ID_LRRC_GURRC_BSIC_VERIFIED_REQ         = (LRRC_WRRC_MSG_HDR + 0x19),       /* _H2ASN_MsgChoice LRRC_GURRC_BSIC_VERIFIED_REQ_STRU */        /* SendPid:PS_PID_ERMM; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_BSIC_VERIFIED_CNF         = (WRRC_LRRC_MSG_HDR + 0x19),       /* _H2ASN_MsgChoice GURRC_LRRC_BSIC_VERIFIED_CNF_STRU */        /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERMM */
    ID_GURRC_LRRC_BSIC_VERIFIED_IND         = (WRRC_LRRC_MSG_HDR + 0x1a),       /* _H2ASN_MsgChoice GURRC_LRRC_BSIC_VERIFIED_IND_STRU */        /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERMM */

    /* L -> W DSP 加载 */
    ID_LRRC_WRRC_LOAD_DSP_REQ               = (LRRC_WRRC_MSG_HDR + 0x1a),       /* _H2ASN_MsgChoice LRRC_WRRC_LOAD_DSP_REQ_STRU */          /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_LOAD_DSP_CNF               = (WRRC_LRRC_MSG_HDR + 0x1b),       /* _H2ASN_MsgChoice WRRC_LRRC_LOAD_DSP_CNF_STRU */          /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L -> GU RelAll */
    ID_LRRC_GURRC_RELALL_REQ                = (LRRC_WRRC_MSG_HDR + 0x1b),       /* _H2ASN_MsgChoice LRRC_GURRC_RELALL_REQ_STRU */           /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_RELALL_CNF                = (WRRC_LRRC_MSG_HDR + 0x1c),       /* _H2ASN_MsgChoice GURRC_LRRC_RELALL_CNF_STRU */           /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L -> W cell srch. L重建时搜索UTRA小区 */
    ID_LRRC_WRRC_CELL_SRCH_REQ              = (LRRC_WRRC_MSG_HDR + 0x1c),       /* _H2ASN_MsgChoice LRRC_WRRC_CELL_SRCH_REQ_STRU */        /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_CELL_SRCH_CNF              = (WRRC_LRRC_MSG_HDR + 0x1d),       /* _H2ASN_MsgChoice WRRC_LRRC_CELL_SRCH_CNF_STRU */        /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_WRRC_CELL_SRCH_STOP_REQ         = (LRRC_WRRC_MSG_HDR + 0x1d),       /* _H2ASN_MsgChoice LRRC_WRRC_CELL_SRCH_STOP_REQ_STRU */   /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_CELL_SRCH_STOP_CNF         = (WRRC_LRRC_MSG_HDR + 0x1e),       /* _H2ASN_MsgChoice WRRC_LRRC_CELL_SRCH_STOP_CNF_STRU */   /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L -> GU BackGroud Search */
    ID_LRRC_GURRC_BG_PLMN_SEARCH_REQ        = (LRRC_WRRC_MSG_HDR + 0x1e),       /* _H2ASN_MsgChoice LRRC_GURRC_BG_PLMN_SEARCH_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_BG_PLMN_SEARCH_CNF        = (WRRC_LRRC_MSG_HDR + 0x1f),       /* _H2ASN_MsgChoice GURRC_LRRC_BG_PLMN_SEARCH_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_GURRC_LRRC_BG_PLMN_SEARCH_IND        = (WRRC_LRRC_MSG_HDR + 0x20),       /* _H2ASN_MsgChoice GURRC_LRRC_BG_PLMN_SEARCH_IND_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_GURRC_BG_SEARCH_STOP_REQ        = (LRRC_WRRC_MSG_HDR + 0x1f),       /* _H2ASN_MsgChoice LRRC_GURRC_BG_SEARCH_STOP_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_BG_SEARCH_STOP_CNF        = (WRRC_LRRC_MSG_HDR + 0x21),       /* _H2ASN_MsgChoice GURRC_LRRC_BG_SEARCH_STOP_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_GURRC_BG_SEARCH_SUSPEND_REQ     = (LRRC_WRRC_MSG_HDR + 0x20),       /* _H2ASN_MsgChoice LRRC_GURRC_BG_SEARCH_SUSPEND_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_BG_SEARCH_SUSPEND_CNF     = (WRRC_LRRC_MSG_HDR + 0x22),       /* _H2ASN_MsgChoice GURRC_LRRC_BG_SEARCH_SUSPEND_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_LRRC_GURRC_BG_SEARCH_RESUME_REQ      = (LRRC_WRRC_MSG_HDR + 0x21),       /* _H2ASN_MsgChoice LRRC_GURRC_BG_SEARCH_RESUME_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_GURRC_LRRC_BG_SEARCH_RESUME_CNF      = (WRRC_LRRC_MSG_HDR + 0x23),       /* _H2ASN_MsgChoice GURRC_LRRC_BG_SEARCH_RESUME_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* W-> L BackGroud Search */
    ID_WRRC_LRRC_BG_PLMN_SEARCH_REQ         = (WRRC_LRRC_MSG_HDR + 0x24),       /* _H2ASN_MsgChoice WRRC_LRRC_BG_PLMN_SEARCH_REQ_STRU */
    ID_LRRC_WRRC_BG_PLMN_SEARCH_CNF         = (LRRC_WRRC_MSG_HDR + 0x22),       /* _H2ASN_MsgChoice LRRC_WRRC_BG_PLMN_SEARCH_CNF_STRU */
    ID_LRRC_WRRC_BG_PLMN_SEARCH_IND         = (LRRC_WRRC_MSG_HDR + 0x23),       /* _H2ASN_MsgChoice LRRC_WRRC_BG_PLMN_SEARCH_IND_STRU */
    ID_WRRC_LRRC_BG_SEARCH_STOP_REQ         = (WRRC_LRRC_MSG_HDR + 0x25),       /* _H2ASN_MsgChoice WRRC_LRRC_BG_SEARCH_STOP_REQ_STRU */
    ID_LRRC_WRRC_BG_SEARCH_STOP_CNF         = (LRRC_WRRC_MSG_HDR + 0x24),       /* _H2ASN_MsgChoice LRRC_WRRC_BG_SEARCH_STOP_CNF_STRU */
    ID_WRRC_LRRC_BG_SEARCH_SUSPEND_REQ      = (WRRC_LRRC_MSG_HDR + 0x26),       /* _H2ASN_MsgChoice WRRC_LRRC_BG_SEARCH_SUSPEND_REQ_STRU */
    ID_LRRC_WRRC_BG_SEARCH_SUSPEND_CNF      = (LRRC_WRRC_MSG_HDR + 0x25),       /* _H2ASN_MsgChoice LRRC_WRRC_BG_SEARCH_SUSPEND_CNF_STRU */
    ID_WRRC_LRRC_BG_SEARCH_RESUME_REQ       = (WRRC_LRRC_MSG_HDR + 0x27),       /* _H2ASN_MsgChoice WRRC_LRRC_BG_SEARCH_RESUME_REQ_STRU */
    ID_LRRC_WRRC_BG_SEARCH_RESUME_CNF       = (LRRC_WRRC_MSG_HDR + 0x26),       /* _H2ASN_MsgChoice LRRC_WRRC_BG_SEARCH_RESUME_CNF_STRU */

    /* L -> W ANR */
    ID_LRRC_WRRC_GET_W_CGI_REQ              = (LRRC_WRRC_MSG_HDR + 0x27),       /* _H2ASN_MsgChoice LRRC_WRRC_GET_W_CGI_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_GET_W_CGI_CNF              = (WRRC_LRRC_MSG_HDR + 0x28),       /* _H2ASN_MsgChoice WRRC_LRRC_GET_W_CGI_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_WRRC_LRRC_GET_W_CGI_IND              = (WRRC_LRRC_MSG_HDR + 0x29),       /* _H2ASN_MsgChoice WRRC_LRRC_GET_W_CGI_IND_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L -> G ANR */
    ID_LRRC_WRRC_GET_G_CGI_REQ              = (LRRC_WRRC_MSG_HDR + 0x28),       /* _H2ASN_MsgChoice LRRC_WRRC_GET_G_CGI_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */
    ID_WRRC_LRRC_GET_G_CGI_CNF              = (WRRC_LRRC_MSG_HDR + 0x30),       /* _H2ASN_MsgChoice WRRC_LRRC_GET_G_CGI_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */
    ID_WRRC_LRRC_GET_G_CGI_IND              = (WRRC_LRRC_MSG_HDR + 0x31),       /* _H2ASN_MsgChoice WRRC_LRRC_GET_G_CGI_IND_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* L -> GU ANR STOP */
    ID_LRRC_GURRC_GET_CGI_STOP_REQ          = (LRRC_WRRC_MSG_HDR + 0x29),       /* _H2ASN_MsgChoice LRRC_GURRC_GET_CGI_STOP_REQ_STRU */      /* SendPid:PS_PID_ERRC; RcvPid:WUEPS_PID_WRR */

    /* L 驻留的网络通知 WAS */
    ID_LRRC_WRRC_CAMP_PLMN_INFO_NTF        = (LRRC_WRRC_MSG_HDR + 0x30),       /* _H2ASN_MsgChoice LRRC_WRRC_CAMP_PLMN_INFO_NTF_STRU */

    /* L 丢网通知 WAS */
    ID_LRRC_WRRC_AREA_LOST_NTF             = (LRRC_WRRC_MSG_HDR + 0x31),       /* _H2ASN_MsgChoice LRRC_WRRC_AREA_LOST_NTF_STRU */

    ID_GURRC_LRRC_GET_CGI_STOP_CNF          = (WRRC_LRRC_MSG_HDR + 0x32),       /* _H2ASN_MsgChoice GURRC_LRRC_GET_CGI_STOP_CNF_STRU */      /* SendPid:WUEPS_PID_WRR; RcvPid:PS_PID_ERRC */

    /* W -> L 获取自主FR LTE频点*/
    ID_WRRC_LRRC_FR_INFO_REQ               = (WRRC_LRRC_MSG_HDR + 0x33),        /* _H2ASN_MsgChoice WRRC_LRRC_FR_INFO_REQ_STRU */
    ID_LRRC_WRRC_FR_INFO_CNF               = (LRRC_WRRC_MSG_HDR + 0x32),        /* _H2ASN_MsgChoice LRRC_WRRC_FR_INFO_CNF_STRU */

    ID_LRRC_WRRC_MSG_TYPE_BUTT
};

typedef VOS_UINT32 LRRC_WRRC_MSG_TYPE_ENUM_UINT32;


/*****************************************************************************
  5 STRUCT
*****************************************************************************/
/*****************************************************************************
 结构名    : WRRC_LRRC_CELL_RESEL_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usArfcn;
    VOS_UINT16                                              usCellId;
    LRRC_GURRC_MEAS_BAND_WIDTH_ENUM_UINT16                  enMeasBand;

    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;

    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stDPriInfo;
}WRRC_LRRC_CELL_RESEL_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_CELL_RESEL_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示小区搜索结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_CELL_RESEL_RESULT_ENUM_UINT32                enRslt;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_NOT_EPLMNS时，stPlmnIdInfo 有效*/
    LRRC_GURRC_PLMN_ID_INFO_LIST_STRU                       stPlmnIdInfoList;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_SIB_RCV_FAIL,
       LRRC_GURRC_CELL_RESEL_CELL_BARRED, LRRC_GURRC_CELL_RESEL_ACCESS时，
       ulTimerVaule有效,单位 :毫秒*/
    VOS_UINT32                                              ulTimerValue;
}LRRC_WRRC_CELL_RESEL_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_CELL_RESEL_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :WRRC指示LRRC停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_CELL_RESEL_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_CELL_RESEL_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC已停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_CELL_RESEL_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_ARFCN_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRRC重定向、连接态搜网信息
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usArfcn;
    VOS_UINT16                                              usBlackListNum;
    VOS_UINT16                                              ausBlackListCellId[LRRC_GURRC_BLACK_LIST_CELL_MAX_NUM];
}WRRC_LRRC_ARFCN_INFO_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_REDIRECTED_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示重定向流程启动
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/

    VOS_UINT8                                               aucReserve1[2];

    /* W->L重定向信息 */
    VOS_UINT16                                              usArfcnNum;
    WRRC_LRRC_ARFCN_INFO_STRU                               astRedirInfo[LRRC_GURRC_LTE_ARFCN_MAX_NUM];


    /* 惩罚时间指的是RRC CON REJ 中携带定时器剩余时长单位:毫秒 */
    VOS_UINT16                                              usPunishTimerValue;

    /* 在REDIR INFO 指示搜索的时间 单位:毫秒,目前固定10000ms，
       在此时间内搜索指定小区后，直接进行其他的小区搜索，不需要等到此定时器超时后再搜索其他SUITABELE小区
    ***************************************************************************/
    VOS_UINT16                                              usSearchTimer;

    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;   /* 固定为SUITABLE */

    /* CMCC-BEGIN */
    LRRC_GURRC_REDIR_TYPE_ENUM_UINT8                        enRedirType;
    VOS_UINT8                                               aucReserved2[1];
    /* CMCC-END */

    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stDPriInfo;
}WRRC_LRRC_REDIRECTED_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_REDIRECTED_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示重定向结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_REDIRECTED_RESULT_ENUM_UINT32                enRslt;
}LRRC_WRRC_REDIRECTED_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_REDIRECTED_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :WRRC指示LRRC停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_REDIRECTED_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_REDIRECTED_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC已停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_REDIRECTED_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_HANDOVER_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :WRRC指示LRRC启动HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/

    /* W通知L当前网络国家码 */
    VOS_UINT8                                               aucMcc[3];
    VOS_UINT8                                               aucReserved[1];

    VOS_UINT32                                              ulHoDataLen;
    /* 该数据为编码后的RRC CONN RECFG */
    VOS_UINT8                                               aucHoData[4];
}WRRC_LRRC_HANDOVER_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_HANDOVER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  LRRC发给WRRC指示切换流程结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_HANDOVER_RESULT_ENUM_UINT32                  enRslt;
}LRRC_WRRC_HANDOVER_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_HANDOVER_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :WRRC指示LRRC停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_HANDOVER_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_HANDOVER_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC已停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_HANDOVER_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_SET_DSP_POWER_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  WRRC指示LRRC对DSP省电模式操作
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_CMD_ENUM_UINT32                enSetLDspPowerCmd;
}WRRC_LRRC_SET_DSP_POWER_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_SET_DSP_POWER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC对EDSP操作完成
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_RESULT_ENUM_UINT32             enRslt;
}LRRC_WRRC_SET_DSP_POWER_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_GETUECAPINFO_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  WRRC指示LRRC对提供UE能力信息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    /* gaojishan-SYSCFG-SAVENV-Begin */
    VOS_UINT8                                               aucMcc[3];
    VOS_UINT8                                               aucReserved[1];
    /* gaojishan-SYSCFG-SAVENV-End */
}WRRC_LRRC_GETUECAPINFO_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_GETUECAPINFO_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC对UE能力获取完成
 For EUTRA: the encoding of UE capabilities is defined in IE UE-EUTRA-Capability.
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GET_UECAP_RESULT_ENUM_UINT16                 enRslt;
    VOS_UINT16                                              usDataLen;
    VOS_UINT8                                               aucEutranCapInfoData[LRRC_WRRC_UE_CAP_EUTRAN_MAX_LEN];
}LRRC_WRRC_GETUECAPINFO_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_HANDOVER_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :WRRC指示LRRC启动PLMN SEARCH流程
                 仅仅针对UTRAN UE在连接态下出服务区搜网流程，
                 LRRC需要在搜索过程中判断该小区是否满足SUITABLE准则，
                 与正常的指定的PLMN搜索过程一样，但是不驻留
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[2];
    VOS_UINT16                                              usArfcnNum;
    WRRC_LRRC_ARFCN_INFO_STRU                               astArfcnInfo[LRRC_GURRC_LTE_ARFCN_MAX_NUM];
}WRRC_LRRC_PLMN_SEARCH_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_PLMN_SEARCH_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  LRRC发给WRRC PLMN SEARCH 结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_WRRC_PLMN_SEARCH_RESULT_ENUM_UINT16                enPLmnSearchRslt;
    VOS_UINT8                                               aucReserved[2];

    /* usPLmnSearchResult =  LRRC_WRRC_PLMN_SEARCH_SUCC ，填写原则如下
       LTE CELL中携带的PLMN LIST中，有RPLMN则填写RPLMN，否则选择其中
       一个PLMN 信息*/
    LRRC_GURRC_PLMN_ID_INFO_STRU                            stSuitablePlmnId;

    /* usPLmnSearchResult =  LRRC_WRRC_PLMN_SEARCH_FAIL ，携带再次过程中搜索到
           所有的PLMN 信息，以高低质量排序传递给WRRC，具体准则同正常的
          PLMN LIST 搜索*/
    LRRC_GURRC_PLMN_ID_LIST_STRU                            stPlmnIdList;
}LRRC_WRRC_PLMN_SEARCH_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_PLMN_SEARCH_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :WRRC指示LRRC停止PLMN SEARCH流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_PLMN_SEARCH_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_PLMN_SEARCH_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC已停止PLMN SEARCH 流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_PLMN_SEARCH_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_IDLE_MEASURE_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示启动IDLE测量
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    LRRC_GURRC_MEAS_CMD_ENUM_UINT16                         enMeasCmd;
    GURRC_LRRC_EUTRAN_INFO_LIST_STRU                        stIdleEutranArfcnInfoList;
}WRRC_LRRC_IDLE_MEASURE_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_IDLE_MEASURE_CNF_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : LRRC发给WRRC指示IDLE测量启动结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_MEAS_RESULT_ENUM_UINT32                      enRslt;
}LRRC_WRRC_IDLE_MEASURE_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_IDLE_MEASURE_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示IDLE测量结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_MEAS_EUTRAN_RESULT_STRU                      stIdleMeasRslt;
}LRRC_WRRC_IDLE_MEASURE_IND_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_CONNECTED_MEASURE_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示启动CONNECTED测量
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;

    LRRC_GURRC_MEAS_CMD_ENUM_UINT16                         enMeasCmd;
    LRRC_WRRC_STATE_TYPE_ENUM_UINT16                        enWRrcStateType;
    VOS_UINT8                                               aucReserved[2];
    GURRC_LRRC_EUTRAN_INFO_LIST_STRU                        stConnEutranArfcnInfoList;
}WRRC_LRRC_CONNECTED_MEASURE_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_CONNECTED_MEASURE_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示CONNECTED测量启动结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_MEAS_RESULT_ENUM_UINT32                      enRslt;
}LRRC_WRRC_CONNECTED_MEASURE_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_CONNECTED_MEASURE_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示CONNECTED 测量结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_MEAS_EUTRAN_RESULT_STRU                      stConnMeasRslt;
}LRRC_WRRC_CONNECTED_MEASURE_IND_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_RELALL_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  WRRC指示LRRC执行RelAll操作
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_RELALL_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_RELALL_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC执行RelAll操作完成
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_RELALL_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_CELL_RESEL_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : LRRC发给WRRC指示小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usArfcn;
    VOS_UINT16                                              usPrimaryCode;

    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;
    PS_BOOL_ENUM_UINT8                                      enLteReestInd;
    VOS_UINT8                                               aucReserved[1];

    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stDPriInfo;
}LRRC_WRRC_CELL_RESEL_REQ_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_CELL_RESEL_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示小区搜索结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_CELL_RESEL_RESULT_ENUM_UINT32                enRslt;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_NOT_EPLMNS时，
    stPlmnIdInfo 有效,该数据为小区的PLMN IDs 信息*/
    LRRC_GURRC_PLMN_ID_INFO_LIST_STRU                       stPlmnIdInfoList;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_SIB_RCV_FAIL,
       LRRC_GURRC_CELL_RESEL_CELL_BARRED, LRRC_GURRC_CELL_RESEL_ACCESS时，
       ulTimerVaule有效,单位 :毫秒*/
    VOS_UINT32                                              ulTimerValue;
}WRRC_LRRC_CELL_RESEL_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_CELL_RESEL_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示WRRC停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_CELL_RESEL_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_CELL_RESEL_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC已停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_CELL_RESEL_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GURRC_REDIR_CELL_INFO_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : 重定向中携带的小区信息
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usPrimaryCode;
    VOS_UINT16                                              usSysInfoLen;
    VOS_UINT8                                               aucData[LRRC_WRRC_UTRAN_BCCH_CONTAINER_MAX_BYTE_LEN];
}LRRC_GURRC_REDIR_CELL_INFO_STRU;

/*****************************************************************************
 结构名    : LRRC_GURRC_REDIR_CELL_INFO_LIST_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : 重定向中携带的小区信息列表
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                              ulCellNum;
    LRRC_GURRC_REDIR_CELL_INFO_STRU                         astCellInfo[LRRC_WRRC_REDIR_CELL_MAX_MUN];
}LRRC_GURRC_REDIR_CELL_INFO_LIST_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_REDIRECTED_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : LRRC发给WRRC指示重定向流程启动
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usArfcn;
    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;

    VOS_UINT8                                               aucReserved[3];

    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enRedirCellInfoPresent; /* 重定向小区信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;      /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_REDIR_CELL_INFO_LIST_STRU                    stRedirCellInfoList;    /* 小区信息 */
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stDPriInfo;             /* 专用优先级信息 */

    /* CMCC-BEGIN */
    LRRC_GURRC_REDIR_SAVED_EUTRA_INFO_STRU                  stRedirEutraInfo;
    /* CMCC-END */
}LRRC_WRRC_REDIRECTED_REQ_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_REDIRECTED_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示重定向结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_REDIRECTED_RESULT_ENUM_UINT32                enRslt;
}WRRC_LRRC_REDIRECTED_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_REDIRECTED_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示WRRC停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_REDIRECTED_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_REDIRECTED_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC已停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_REDIRECTED_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :  LRRC_WRRC_HANDOVER_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示WRRC启动HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/

    /* CMCC-BEGIN */
    LRRC_GURRC_REDIR_SAVED_EUTRA_INFO_STRU                  stRedirEutraInfo;
    /* CMCC-END */

    /* CSFB 标志,1:表示是CSFB, 0: 表示不是CSFB */
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enCsfbInd;

    /* L通知W当前驻留的国家码 */
    VOS_UINT8                                               aucMcc[3];

    /* begin：add for chr */
    VOS_UINT32                                              ulHoBeginTimeStampHigh;
    VOS_UINT32                                              ulHoBeginTimeStampLow;
    /* end：add for chr */

    VOS_UINT8                                               aucReserved[2];

    VOS_UINT16                                              usHoDatalen;
    VOS_UINT8                                               aucHoData[4];       /*  编码后的HANDOVER TO UTRAN COMMAND 数据*/
}LRRC_WRRC_HANDOVER_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_HANDOVER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  WRRC发给LRRC指示切换流程结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_HANDOVER_RESULT_ENUM_UINT32                  enRslt;
}WRRC_LRRC_HANDOVER_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_HANDOVER_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示WRRC停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_HANDOVER_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_HANDOVER_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC已停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_HANDOVER_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_SET_DSP_POWER_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示WRRC对DSP省电模式操作
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_CMD_ENUM_UINT32                enSetLDspPowerCmd;
}LRRC_WRRC_SET_DSP_POWER_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_SET_DSP_POWER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC对EDSP操作完成
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_RESULT_ENUM_UINT32             enRslt;
}WRRC_LRRC_SET_DSP_POWER_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_GETUECAPINFO_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示WRRC对提供UE能力信息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    /* gaojishan-SYSCFG-SAVENV-Begin */
    VOS_UINT8                                               aucMcc[3];
    VOS_UINT8                                               aucReserved[1];
    /* gaojishan-SYSCFG-SAVENV-End */
}LRRC_WRRC_GETUECAPINFO_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_GETUECAPINFO_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC对UE能力获取完成
 For UTRA: the octet string contains the INTER RAT HANDOVER INFO message defined in TS 25.331 [19].
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GET_UECAP_RESULT_ENUM_UINT16                 enRslt;
    VOS_UINT16                                              usDataLen;
    VOS_UINT8                                               aucUtranCapInfoData[LRRC_WRRC_UE_CAP_UTRAN_MAX_LEN];
}WRRC_LRRC_GETUECAPINFO_CNF_STRU;

/*****************************************************************************
 结构名     :LRRC_GURRC_GERAN_CELL_INFO_LIST_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GERAN异系统信息列表
*****************************************************************************/
typedef struct
{
   VOS_UINT16                                               usArfcnNum;

   /****************************************************************************
   频点信息中高优先级频点个数，IDLE态下有效，连接态该字段为保留，
   如果usArfcnNum =  usHighPriNum，表示仅仅只有高优先级频点，
   astGeranCellInfo存放顺序为:高优先级信息 -> 中优先级信息 -> 低优先级信息
   数组下标为GSM小区的CELL ID
   ****************************************************************************/
   VOS_UINT16                                               usHighPrioNum;
   VOS_UINT16                                               usMgsmNum;          /* GSM分组组数，连接态有效，IDLE态该字段保留 */
   VOS_UINT8                                                aucReserved[2];
   LRRC_GURRC_GERAN_CELL_STRU                               astGeranCellInfo[LRRC_GURRC_GERAN_ARFCN_MAX_NUM];
}LRRC_GURRC_GERAN_CELL_INFO_LIST_STRU;

/*****************************************************************************
 结构名     :LRRC_GURRC_UTRAN_CELL_INFO_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :UTRAN异系统信息
*****************************************************************************/
typedef struct
{
   LRRC_GURRC_VALID_FLAG_ENUM_UINT8                         enDetectedCellMeasInd; /* 是否需要测量Detected小区 */
   VOS_UINT8                                                aucReserved[3];

   VOS_UINT16                                               usArfcn;

   /* 当usCellIdNum = 0时，表示仅仅有频点信息而无扰码信息 */
   VOS_UINT16                                               usCellIdNum;
   VOS_UINT16                                               ausUtranCellIdInfo[LRRC_GURRC_MAX_UTRAN_CELL_PER_FREQ_NUM];
}LRRC_GURRC_UTRAN_CELL_INFO_STRU;

/*****************************************************************************
 结构名     :LRRC_GURRC_UTRAN_CELL_INFO_LIST_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :UTRAN异系统信息列表
*****************************************************************************/
typedef struct
{
   VOS_UINT16                                               usArfcnNum;

   /****************************************************************************
   频点信息中高优先级频点个数，则为IDLE态下有效, 连接态下该字段为保留，
   如果usArfcnNum =  usHighPriNum，表示仅仅只有高优先级频点，
   astUtranCellInfo存放顺序为:高优先级信息 -> 中优先级信息 -> 低优先级信息
   ****************************************************************************/
   VOS_UINT16                                               usHighPrioNum;
   /* begin: for modify TDD max Meas Num  */
   LRRC_GURRC_UTRAN_CELL_INFO_STRU                          astUtranCellInfo[LRRC_TRRC_PHY_MAX_SUPPORT_CARRIER_NUM];
   /* end: for modify TDD max Meas Num  */
}LRRC_GURRC_UTRAN_CELL_INFO_LIST_STRU;

/*****************************************************************************
 结构名     :LRRC_GURRC_IRAT_INFO_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GERAN\UTRAN异系统信息
*****************************************************************************/
typedef struct
{
    LRRC_GURRC_GERAN_CELL_INFO_LIST_STRU                    stGeranCellInfoList;
    LRRC_GURRC_UTRAN_CELL_INFO_LIST_STRU                    stUtranCellInfoList;
}LRRC_GURRC_IRAT_INFO_STRU;

/*****************************************************************************
 结构名    : LRRC_GURRC_IDLE_MEASURE_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GURRC指示启动IDLE测量
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    LRRC_GURRC_MEAS_CMD_ENUM_UINT16                         enMeasCmd;
    LRRC_GURRC_IRAT_INFO_STRU                               stIdleInterRatInfo;
}LRRC_GURRC_IDLE_MEASURE_REQ_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_IDLE_MEASURE_CNF_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : GURRC发给LRRC指示IDLE测量启动结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_MEAS_RESULT_ENUM_UINT32                      enRslt;
}GURRC_LRRC_IDLE_MEASURE_CNF_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_GERAN_CELL_MEAS_RESULT_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : GERAN CELL 测量结果
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usArfcn;
    LRRC_GRR_BANDINDICATOR_ENUM_UINT16                      enBandInd;          /* 保持L->W时测量请求消息中的频段指示一致 */

    /* sRssi 取值范围[-110 * 8,-48 * 8],单位:dbm,精度1/8 */
    VOS_INT16                                               sRssi;
    VOS_UINT8                                               aucReserved[2];
}GURRC_LRRC_GERAN_CELL_MEAS_RESULT_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_GERAN_MEAS_RESULT_IND_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : GERAN CELL 测量结果列表
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usArfcnNum;
    VOS_UINT8                                               aucReserved[2];

    GURRC_LRRC_GERAN_CELL_MEAS_RESULT_STRU                  astGeranCellResult[LRRC_GURRC_GERAN_ARFCN_MAX_NUM];
}GURRC_LRRC_GERAN_MEAS_RESULT_IND_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_UTRAN_CELL_MEAS_RESULT_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : GERAN CELL 测量结果
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usPrimaryCode;
    VOS_UINT8                                               aucReserved[2];
    VOS_INT16                                               sRscp;              /* 精度1/8 */
    VOS_INT16                                               sEcN0;              /* 精度1/8 */
}GURRC_LRRC_UTRAN_CELL_MEAS_RESULT_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_UTRAN_SIGNLE_FREQ_MEAS_RESULT_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : UTRAN 单个频点 测量结果
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usArfcn;
    VOS_INT16                                               sRssi;              /* 精度1/8 */
    VOS_UINT8                                               aucReserved[2];
    VOS_UINT16                                              usCellNum;
    GURRC_LRRC_UTRAN_CELL_MEAS_RESULT_STRU                  astUtranCellInfo[LRRC_GURRC_MAX_UTRAN_CELL_PER_FREQ_NUM];
}GURRC_LRRC_UTRAN_SIGNLE_FREQ_MEAS_RESULT_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_UTRAN_MEAS_RESULT_IND_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : UTRAN CELL 测量结果列表
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usArfcnNum;
    VOS_UINT8                                               aucReserved[2];
    /* begin: for modify TDD max Meas Num  */
    GURRC_LRRC_UTRAN_SIGNLE_FREQ_MEAS_RESULT_STRU           astUtranResult[LRRC_TRRC_PHY_MAX_SUPPORT_CARRIER_NUM];
    /* end: for modify TDD max Meas Num  */
}GURRC_LRRC_UTRAN_MEAS_RESULT_IND_STRU;

/*****************************************************************************
 结构名     :GURRC_LRRC_IRAT_MEAS_RESULT_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GERAN\UTRAN异系统测量结果信息
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_MEAS_IRAT_TYPE_ENUM_UINT16                   enChoice;

    union
    {
        GURRC_LRRC_GERAN_MEAS_RESULT_IND_STRU               stGeranMeasResult;
        GURRC_LRRC_UTRAN_MEAS_RESULT_IND_STRU               stUtranMeasResult;
    }u;
}GURRC_LRRC_IRAT_MEAS_RESULT_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_IDLE_MEASURE_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示IDLE测量结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    GURRC_LRRC_IRAT_MEAS_RESULT_STRU                        stIdleIRatMeasResult;
}GURRC_LRRC_IDLE_MEASURE_IND_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_CONNECTED_MEASURE_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示启动CONNECTED测量
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    LRRC_GURRC_MEAS_CMD_ENUM_UINT16                         enMeasCmd;
    LRRC_GURRC_IRAT_INFO_STRU                               stConnInterRatInfo;
}LRRC_GURRC_CONNECTED_MEASURE_REQ_STRU;

/*****************************************************************************
 结构名    : GURRC_LRRC_CONNECTED_MEASURE_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示CONNECTED测量启动结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_MEAS_RESULT_ENUM_UINT32                      enRslt;
}GURRC_LRRC_CONNECTED_MEASURE_CNF_STRU;

/*****************************************************************************
 结构名    : GRRLRRC_CONNECTED_MEASURE_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示CONNECTED 测量结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
    GURRC_LRRC_IRAT_MEAS_RESULT_STRU                        stConnIRatMeasResult;
}GURRC_LRRC_CONNECTED_MEASURE_IND_STRU;

/*****************************************************************************
 结构名    :    LRRC_GURRC_BSIC_VERIFIED_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC启动BSIC流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT16                                              usGeranInfoNum;
    LRRC_GURRC_VERIFY_TIME_INDEX_ENUM_UINT16                enVerifyTimeIndex;
    VOS_UINT8                                               aucReserved[2];
    LRRC_GURRC_GERAN_CELL_STRU                              astGeranInfo[LRRC_GURRC_GERAN_CELL_FOR_BSIC_MAX_NUM];
}LRRC_GURRC_BSIC_VERIFIED_REQ_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_BSIC_VERIFIED_CNF_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  WRRC指示LRRC返回BSIC启动结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[2];
}GURRC_LRRC_BSIC_VERIFIED_CNF_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_BSIC_VERIFIED_RESULT_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC，BSIC验证结果
*****************************************************************************/
typedef struct
{
    LRRC_GURRC_GERAN_CELL_INFO_STRU                         stGeranCellInfo;
    VOS_UINT32                                              usTimeAlignment;
    VOS_INT32                                               lFNOffset;
}GURRC_LRRC_BSIC_VERIFIED_RESULT_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_BSIC_VERIFIED_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC，BSIC验证结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT16                                              usArfcnNum;
    GURRC_LRRC_BSIC_VERIFIED_RESULT_STRU                    astGeranBsicVerifedResult[LRRC_GURRC_GERAN_CELL_FOR_BSIC_MAX_NUM];
}GURRC_LRRC_BSIC_VERIFIED_IND_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_LOAD_DSP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示WRRC加载DSP操作
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_LOAD_DSP_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_LOAD_DSP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC加载DSP操作完成
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_LOAD_DSP_RESULT_ENUM_UINT32                  enRslt;
}WRRC_LRRC_LOAD_DSP_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GURRC_RELALL_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示WRRC执行RelAll操作
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_RELALL_REASON_ENUM_UINT8                     enRelReason;
    VOS_UINT8                                               aucReserved[3];
}LRRC_GURRC_RELALL_REQ_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_RELALL_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC执行RelAll操作完成
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GURRC_LRRC_RELALL_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_CELL_SRCH_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给WRRC指示小区搜索，携带小区列表
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[1];
    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;
    VOS_UINT16                                              usArfcnNum;
    LRRC_GURRC_UTRAN_CELL_INFO_STRU                         astUtranCellInfo[LRRC_GURRC_UTRAN_PHY_MAX_SUPPORT_CARRIER_NUM];
}LRRC_WRRC_CELL_SRCH_REQ_STRU;

/*****************************************************************************
 结构名    : WRRC_LRRC_CELL_SRCH_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC发给LRRC指示小区搜索结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/

    /* 找到指定驻留模式的UTRA小区时使用LRRC_GURRC_CELL_RESEL_SUCC，
       没有找到指定驻留模式的UTRA小区时使用LRRC_GURRC_CELL_RESEL_UNSPECIFIC */
    LRRC_GURRC_CELL_RESEL_RESULT_ENUM_UINT32                enRslt;

    /* 满足指定驻留模式驻留条件的UTRA小区信息 */
    VOS_UINT16                                              usArfcn;
    VOS_UINT16                                              usPrimaryCode;

    /* stSuitablePlmnId和stPlmnIdList信息只在驻留模式为suitable时有意义，
       在驻留模式为any cell时暂时可以不填 */

    /* enRslt = LRRC_GURRC_CELL_RESEL_SUCC ，填写原则如下
       UTRA CELL中携带的PLMN LIST中，有RPLMN则填写RPLMN，否则选择其中
       一个PLMN 信息*/
    LRRC_GURRC_PLMN_ID_INFO_STRU                            stSuitablePlmnId;

    /* enRslt = LRRC_GURRC_CELL_RESEL_UNSPECIFIC ，携带在此过程中搜索到
       的所有的PLMN 信息，以高低质量排序传递给LRRC，具体准则同正常的
       PLMN LIST 搜索 */
    LRRC_GURRC_PLMN_ID_LIST_STRU                            stPlmnIdList;
}WRRC_LRRC_CELL_SRCH_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_CELL_SRCH_STOP_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示WRRC停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_CELL_SRCH_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_CELL_SRCH_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC已停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_CELL_SRCH_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :   LRRC_GURRC_BG_PLMN_SEARCH_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示GU RRC执行背景搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32              enMsgId;                        /*_H2ASN_Skip*/
    LRRC_GURRC_PLMN_ID_INFO_STRU                stPlmnId;
    LRRC_GURRC_SEARCH_RAT_ENUM_UINT8            enSearchRat;                    /* 指示搜W还是搜G */
    LRRC_GURRC_SEARCH_TYPE_ENUM_UINT8           enSearchType;                   /* LRRC通知GU是做背景搜还是PLMN LIST搜 */

    VOS_UINT16                                  usForbLaNum;                    /* 禁止注册区的个数 */
    LRRC_GURRC_FORB_LA_STRU                     astForbLaList[LRRC_GURRC_MAX_FORBLA_NUM];
                                                                                /* 禁止注册区列表 */
}LRRC_GURRC_BG_PLMN_SEARCH_REQ_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_BG_SEARCH_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GURRC指示LRRC执行背景搜索配置的确认
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_BG_SEARCH_RESULT_ENUM_UINT16                 enRslt;
    VOS_UINT8                                               aucReserved[2];
}GURRC_LRRC_BG_PLMN_SEARCH_CNF_STRU;


/*****************************************************************************
 结构名    :    GURRC_LRRC_BG_PLMN_SEARCH_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GURRC指示LRRC执行背景搜索的结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_BG_SEARCH_RESULT_ENUM_UINT16                 enRslt;
    LRRC_GURRC_SEARCH_RAT_ENUM_UINT8                        enSearchRat;        /* 指示搜W还是搜G */
    LRRC_GURRC_SEARCH_TYPE_ENUM_UINT8                       enSearchType;       /* LRRC通知GU是做背景搜还是PLMN LIST搜 */

    LRRC_GURRC_PLMN_ID_LIST_STRU                            stPlmnIdList;
}GURRC_LRRC_BG_PLMN_SEARCH_IND_STRU;

/*****************************************************************************
 结构名    :    LRRC_GURRC_BG_SEARCH_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示GURRC停止背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GURRC_BG_SEARCH_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_BG_SEARCH_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GURRC指示LRRC已停止背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GURRC_LRRC_BG_SEARCH_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GURRC_BG_SEARCH_SUSPEND_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示GURRC挂起背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GURRC_BG_SEARCH_SUSPEND_REQ_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_BG_SEARCH_SUSPEND_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GURRC指示LRRC已挂起背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GURRC_LRRC_BG_SEARCH_SUSPEND_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GURRC_BG_SEARCH_RESUME_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示GURRC恢复背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GURRC_BG_SEARCH_RESUME_REQ_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_BG_SEARCH_RESUME_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GURRC指示LRRC已恢复背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GURRC_LRRC_BG_SEARCH_RESUME_CNF_STRU;

/*****************************************************************************
 结构名    :   WRRC_LRRC_BG_PLMN_SEARCH_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  WRRC指示LRRC执行背景搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32              enMsgId;                        /*_H2ASN_Skip*/

    LRRC_GURRC_PLMN_ID_INFO_STRU                stPlmnId;

    LRRC_GURRC_SEARCH_TYPE_ENUM_UINT8           enSearchType;                   /* 是做背景搜还是PLMN LIST搜 */

    VOS_UINT8                                   aucRsv1[3];
}WRRC_LRRC_BG_PLMN_SEARCH_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_BG_PLMN_SEARCH_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC执行背景搜索的确认
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_BG_SEARCH_RESULT_ENUM_UINT16                 enRslt;
    VOS_UINT8                                               aucRsv1[2];
}LRRC_WRRC_BG_PLMN_SEARCH_CNF_STRU;


/*****************************************************************************
 结构名    :    LRRC_WRRC_BG_PLMN_SEARCH_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC执行背景搜索的结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_BG_SEARCH_RESULT_ENUM_UINT16                 enRslt;
    LRRC_GURRC_SEARCH_TYPE_ENUM_UINT8                       enSearchType;       /* 是做背景搜还是PLMN LIST搜 */
    VOS_UINT8                                               aucRsv1[1];

    LRRC_GURRC_PLMN_ID_LIST_STRU                            stPlmnIdList;
}LRRC_WRRC_BG_PLMN_SEARCH_IND_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_BG_SEARCH_STOP_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC指示LRRC停止背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_BG_SEARCH_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_BG_SEARCH_REL_STOP_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC已停止背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                         enMsgId;             /*_H2ASN_Skip*/
    VOS_UINT8                                              aucReserved[4];
}LRRC_WRRC_BG_SEARCH_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_BG_SEARCH_SUSPEND_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC指示LRRC挂起背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}WRRC_LRRC_BG_SEARCH_SUSPEND_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_BG_SEARCH_SUSPEND_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC已挂起背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_BG_SEARCH_SUSPEND_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_BG_SEARCH_RESUME_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC指示LRRC恢复背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                         enMsgId;             /*_H2ASN_Skip*/
    VOS_UINT8                                              aucReserved[4];
}WRRC_LRRC_BG_SEARCH_RESUME_REQ_STRU;

/*****************************************************************************
 结构名    :   LRRC_WRRC_BG_SEARCH_RESUME_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示WRRC已恢复背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                         enMsgId;             /*_H2ASN_Skip*/
    VOS_UINT8                                              aucReserved[4];
}LRRC_WRRC_BG_SEARCH_RESUME_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_GET_W_CGI_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示WRRC获取对应小区的CGI信息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usArfcn;
    VOS_UINT16                                              usPrimaryCode;
    VOS_UINT8                                               aucReserved[4];
}LRRC_WRRC_GET_W_CGI_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_CGI_INFO_MEAS_RESULT_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  UTRAN CGI信息
*****************************************************************************/
typedef struct
{
    VOS_INT16                                               sRscp;              /* 精度1/8 */
    VOS_INT16                                               sEcN0;              /* 精度1/8 */
    LRRC_GURRC_CELL_GLOBAL_ID_STRU                          stCellGlobalId;
    VOS_UINT16                                              usPlmnCnt;
    VOS_UINT8                                               aucReserved1[2];
    LRRC_GURRC_PLMN_ID_INFO_STRU                            astPlmnIdList[LRRC_WRRC_MAX_NUM_OF_PLMN_ID_LIST_2];

    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enLacPresent;
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enRacPresent;
    VOS_UINT16                                              usLocAreaCode;
    VOS_UINT8                                               ucRoutingAreaCode;
    VOS_UINT8                                               aucReserved[3];
}LRRC_WRRC_CGI_INFO_MEAS_RESULT_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_GET_W_CGI_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC对应小区CGI信息获取配置结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GET_CGI_RESULT_ENUM_UINT32                   enRslt;
}WRRC_LRRC_GET_W_CGI_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_GET_W_CGI_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC对应小区CGI信息获取结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GET_CGI_RESULT_ENUM_UINT32                   enRslt;

    LRRC_WRRC_CGI_INFO_MEAS_RESULT_STRU                     stCgiInfo;
}WRRC_LRRC_GET_W_CGI_IND_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_GET_G_CGI_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示WRRC获取对应GSM小区的CGI信息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GERAN_CELL_INFO_STRU                         stGeranCellInfo;
}LRRC_WRRC_GET_G_CGI_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_CELL_GLOBAL_ID_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  GERAN CELL GLOBAL ID信息
*****************************************************************************/
typedef struct
{
    LRRC_GURRC_PLMN_ID_INFO_STRU                            stPlmnId;
    VOS_UINT16                                              usLocAreaCode;
    VOS_UINT16                                              usCellId;
}LRRC_WRRC_G_CELL_GLOBAL_ID_STRU;

/*****************************************************************************
 结构名    :    LRRC_WRRC_G_CGI_INFO_MEAS_RESULT_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  GERAN CGI信息
*****************************************************************************/
typedef struct
{
    LRRC_WRRC_G_CELL_GLOBAL_ID_STRU                         stGsmCellGlobalId;
    VOS_INT16                                               sRssi;/* RSSI测量值 ,取值范围[-110*8,-20*8], 单位:dBm，精度 1/8 */
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enRacPresent;
    VOS_UINT8                                               ucRoutingAreaCode;
}LRRC_WRRC_G_CGI_INFO_MEAS_RESULT_STRU;

/*****************************************************************************
 结构名    :  WRRC_LRRC_GET_G_CGI_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  WRRC指示LRRC对应GSM小区CGI信息获取配置结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GET_CGI_RESULT_ENUM_UINT32                   enRslt;
}WRRC_LRRC_GET_G_CGI_CNF_STRU;

/*****************************************************************************
 结构名    :    WRRC_LRRC_GET_G_CGI_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   WRRC指示LRRC对应GSM小区CGI信息获取结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GET_CGI_RESULT_ENUM_UINT32                   enRslt;

    LRRC_WRRC_G_CGI_INFO_MEAS_RESULT_STRU                   stGsmCgiInfo;
}WRRC_LRRC_GET_G_CGI_IND_STRU;

/*****************************************************************************
 结构名    :    LRRC_GURRC_GET_CGI_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示GURRC停止ANR流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GURRC_GET_CGI_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    GURRC_LRRC_GET_CGI_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GURRC指示LRRC已停止ANR流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GURRC_LRRC_GET_CGI_STOP_CNF_STRU;


/*****************************************************************************
 结构名    : LRRC_WRRC_MSG_DATA
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC_WRRC_MSG_DATA数据结构，用于生成ASN文件
*****************************************************************************/
typedef struct
{
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_MsgChoice_Export LRRC_WRRC_MSG_TYPE_ENUM_UINT32 */
    VOS_UINT8                                               aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          LRRC_WRRC_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}LRRC_WRRC_MSG_DATA;

/*_H2ASN_Length UINT32*/

/*****************************************************************************
 结构名    : LRRCWRRCInterface_MSG
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRCWRRCInterface_MSG数据结构,用于生成ASN文件
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    LRRC_WRRC_MSG_DATA                                      stMsgData;
}LRrcWRrcInterface_MSG;

/*****************************************************************************
 结构名    : LRRC_WRRC_CAMP_PLMN_INFO_NFT_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示WRRC当前驻留的网络号
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32        enMsgId;                /*_H2ASN_Skip*/
    LRRC_GURRC_PLMN_ID_INFO_STRU          stPlmnIdInfo;
}LRRC_WRRC_CAMP_PLMN_INFO_NTF_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_AREA_LOST_NFT_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示WRRC当前LRRC丢网
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                           /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32        enMsgId;           /*_H2ASN_Skip*/
    VOS_UINT8                             aucResrved[4];
}LRRC_WRRC_AREA_LOST_NTF_STRU;


/*****************************************************************************
 结构名    : WRRC_LRRC_FR_INFO_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : WRRC指示LRRC获取LTE自主FR频点
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                               /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32            enMsgId;           /*_H2ASN_Skip*/
}WRRC_LRRC_FR_INFO_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_WRRC_FR_INFO_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示WRRC获取LTE自主FR频点的结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                               /*_H2ASN_Skip*/
    LRRC_WRRC_MSG_TYPE_ENUM_UINT32            enMsgId;           /*_H2ASN_Skip*/
    LRRC_GURRC_REDIR_SAVED_EUTRA_INFO_STRU    stRedirEutraInfo;
}LRRC_WRRC_FR_INFO_CNF_STRU;

/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/


/*****************************************************************************
  9 OTHERS
*****************************************************************************/





#if (VOS_OS_VER != VOS_WIN32)
 #pragma pack()
#else
 #pragma pack(pop)
#endif

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif /* end of LRRC_WRRCInterface.h */

