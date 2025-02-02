

#ifndef __LRRC_GRRINTERFACE_H__
#define __LRRC_GRRINTERFACE_H__

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

#define LRRC_GRR_MSG_HDR                (PS_MSG_ID_LRRC_TO_GRR_BASE)
#define GRR_LRRC_MSG_HDR                (PS_MSG_ID_GRR_TO_LRRC_BASE)

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
enum LRRC_GRR_MSG_TYPE_ENUM
{
    /* G -> L Cell Resel */
    ID_GRR_LRRC_CELL_RESEL_REQ                 = (GRR_LRRC_MSG_HDR + 0x00),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_RESEL_REQ_STRU */
    ID_LRRC_GRR_CELL_RESEL_CNF                 = (LRRC_GRR_MSG_HDR + 0x00),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_RESEL_CNF_STRU */
    ID_GRR_LRRC_CELL_RESEL_STOP_REQ            = (GRR_LRRC_MSG_HDR + 0x01),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_RESEL_STOP_REQ_STRU */
    ID_LRRC_GRR_CELL_RESEL_STOP_CNF            = (LRRC_GRR_MSG_HDR + 0x01),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_RESEL_STOP_CNF_STRU */

    /* G -> L Redirect */
    ID_GRR_LRRC_REDIRECTED_REQ                 = (GRR_LRRC_MSG_HDR + 0x02),     /* _H2ASN_MsgChoice GRR_LRRC_REDIRECTED_REQ_STRU */
    ID_LRRC_GRR_REDIRECTED_CNF                 = (LRRC_GRR_MSG_HDR + 0x02),     /* _H2ASN_MsgChoice LRRC_GRR_REDIRECTED_CNF_STRU */
    ID_GRR_LRRC_REDIRECTED_STOP_REQ            = (GRR_LRRC_MSG_HDR + 0x03),     /* _H2ASN_MsgChoice GRR_LRRC_REDIRECTED_STOP_REQ_STRU */
    ID_LRRC_GRR_REDIRECTED_STOP_CNF            = (LRRC_GRR_MSG_HDR + 0x03),     /* _H2ASN_MsgChoice LRRC_GRR_REDIRECTED_STOP_CNF_STRU */

    /* G -> L CCO */
    ID_GRR_LRRC_CELL_CHANGE_ORDER_REQ          = (GRR_LRRC_MSG_HDR + 0x04),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_CHANGE_ORDER_REQ_STRU */
    ID_LRRC_GRR_CELL_CHANGE_ORDER_CNF          = (LRRC_GRR_MSG_HDR + 0x04),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_CHANGE_ORDER_CNF_STRU */
    ID_GRR_LRRC_CELL_CHANGE_ORDER_STOP_REQ     = (GRR_LRRC_MSG_HDR + 0x05),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_CHANGE_ORDER_STOP_REQ_STRU */
    ID_LRRC_GRR_CELL_CHANGE_ORDER_STOP_CNF     = (LRRC_GRR_MSG_HDR + 0x05),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_CHANGE_ORDER_STOP_CNF_STRU */

    /* G-> L HO */
    ID_GRR_LRRC_HANDOVER_REQ                   = (GRR_LRRC_MSG_HDR + 0x06),     /* _H2ASN_MsgChoice GRR_LRRC_HANDOVER_REQ_STRU */
    ID_LRRC_GRR_HANDOVER_CNF                   = (LRRC_GRR_MSG_HDR + 0x06),     /* _H2ASN_MsgChoice LRRC_GRR_HANDOVER_CNF_STRU */
    ID_GRR_LRRC_HANDOVER_STOP_REQ              = (GRR_LRRC_MSG_HDR + 0x07),     /* _H2ASN_MsgChoice GRR_LRRC_HANDOVER_STOP_REQ_STRU */
    ID_LRRC_GRR_HANDOVER_STOP_CNF              = (LRRC_GRR_MSG_HDR + 0x07),     /* _H2ASN_MsgChoice LRRC_GRR_HANDOVER_STOP_CNF_STRU */

    /* G-> L 低功耗 */
    ID_GRR_LRRC_SET_DSP_POWER_REQ              = (GRR_LRRC_MSG_HDR + 0x08),     /* _H2ASN_MsgChoice GRR_LRRC_SET_DSP_POWER_REQ_STRU */
    ID_LRRC_GRR_SET_DSP_POWER_CNF              = (LRRC_GRR_MSG_HDR + 0x08),     /* _H2ASN_MsgChoice LRRC_GRR_SET_DSP_POWER_CNF_STRU */

    /* G-> L Idle Meas */
    ID_GRR_LRRC_IDLE_MEASURE_REQ               = (GRR_LRRC_MSG_HDR + 0x09),     /* _H2ASN_MsgChoice GRR_LRRC_IDLE_MEASURE_REQ_STRU */
    ID_LRRC_GRR_IDLE_MEASURE_CNF               = (LRRC_GRR_MSG_HDR + 0x09),     /* _H2ASN_MsgChoice LRRC_GRR_IDLE_MEASURE_CNF_STRU */
    ID_LRRC_GRR_IDLE_MEASURE_IND               = (LRRC_GRR_MSG_HDR + 0x0a),     /* _H2ASN_MsgChoice LRRC_GRR_IDLE_MEASURE_IND_STRU */

    /* G-> L conn Meas */
    ID_GRR_LRRC_CONNECTED_MEASURE_REQ          = (GRR_LRRC_MSG_HDR + 0x0a),     /* _H2ASN_MsgChoice GRR_LRRC_CONNECTED_MEASURE_REQ_STRU */
    ID_LRRC_GRR_CONNECTED_MEASURE_CNF          = (LRRC_GRR_MSG_HDR + 0x0b),     /* _H2ASN_MsgChoice LRRC_GRR_CONNECTED_MEASURE_CNF_STRU */
    ID_LRRC_GRR_CONNECTED_MEASURE_IND          = (LRRC_GRR_MSG_HDR + 0x0c),     /* _H2ASN_MsgChoice LRRC_GRR_CONNECTED_MEASURE_IND_STRU */

    /* L -> G Cell Resel*/
    ID_LRRC_GRR_CELL_RESEL_REQ                 = (LRRC_GRR_MSG_HDR + 0x0d),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_RESEL_REQ_STRU */
    ID_GRR_LRRC_CELL_RESEL_CNF                 = (GRR_LRRC_MSG_HDR + 0x0b),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_RESEL_CNF_STRU */
    ID_LRRC_GRR_CELL_RESEL_STOP_REQ            = (LRRC_GRR_MSG_HDR + 0x0e),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_RESEL_STOP_REQ_STRU */
    ID_GRR_LRRC_CELL_RESEL_STOP_CNF            = (GRR_LRRC_MSG_HDR + 0x0c),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_RESEL_STOP_CNF_STRU */

    /* L-> G Redirect */
    ID_LRRC_GRR_REDIRECTED_REQ                 = (LRRC_GRR_MSG_HDR + 0x0f),     /* _H2ASN_MsgChoice LRRC_GRR_REDIRECTED_REQ_STRU */
    ID_GRR_LRRC_REDIRECTED_CNF                 = (GRR_LRRC_MSG_HDR + 0x0d),     /* _H2ASN_MsgChoice GRR_LRRC_REDIRECTED_CNF_STRU */
    ID_LRRC_GRR_REDIRECTED_STOP_REQ            = (LRRC_GRR_MSG_HDR + 0x10),     /* _H2ASN_MsgChoice LRRC_GRR_REDIRECTED_STOP_REQ_STRU */
    ID_GRR_LRRC_REDIRECTED_STOP_CNF            = (GRR_LRRC_MSG_HDR + 0x0e),     /* _H2ASN_MsgChoice GRR_LRRC_REDIRECTED_STOP_CNF_STRU */

    /* L-> G CCO */
    ID_LRRC_GRR_CELL_CHANGE_ORDER_REQ          = (LRRC_GRR_MSG_HDR + 0x11),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_CHANGE_ORDER_REQ_STRU */
    ID_GRR_LRRC_CELL_CHANGE_ORDER_CNF          = (GRR_LRRC_MSG_HDR + 0x0f),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_CHANGE_ORDER_CNF_STRU */
    ID_LRRC_GRR_CELL_CHANGE_ORDER_STOP_REQ     = (LRRC_GRR_MSG_HDR + 0x12),     /* _H2ASN_MsgChoice LRRC_GRR_CELL_CHANGE_ORDER_STOP_REQ_STRU */
    ID_GRR_LRRC_CELL_CHANGE_ORDER_STOP_CNF     = (GRR_LRRC_MSG_HDR + 0x10),     /* _H2ASN_MsgChoice GRR_LRRC_CELL_CHANGE_ORDER_STOP_CNF_STRU */

    /* L-> G HO */
    ID_LRRC_GRR_HANDOVER_REQ                   = (LRRC_GRR_MSG_HDR + 0x13),     /* _H2ASN_MsgChoice LRRC_GRR_HANDOVER_REQ_STRU */
    ID_GRR_LRRC_HANDOVER_CNF                   = (GRR_LRRC_MSG_HDR + 0x11),     /* _H2ASN_MsgChoice GRR_LRRC_HANDOVER_CNF_STRU */
    ID_LRRC_GRR_HANDOVER_STOP_REQ              = (LRRC_GRR_MSG_HDR + 0x14),     /* _H2ASN_MsgChoice LRRC_GRR_HANDOVER_STOP_REQ_STRU */
    ID_GRR_LRRC_HANDOVER_STOP_CNF              = (GRR_LRRC_MSG_HDR + 0x12),     /* _H2ASN_MsgChoice GRR_LRRC_HANDOVER_STOP_CNF_STRU */

    /* G-> L 低功耗 */
    ID_LRRC_GRR_SET_DSP_POWER_REQ              = (LRRC_GRR_MSG_HDR + 0x15),     /* _H2ASN_MsgChoice LRRC_GRR_SET_DSP_POWER_REQ_STRU */
    ID_GRR_LRRC_SET_DSP_POWER_CNF              = (GRR_LRRC_MSG_HDR + 0x13),     /* _H2ASN_MsgChoice GRR_LRRC_SET_DSP_POWER_CNF_STRU */

    /* L-> G Get Ue Capability Info */
    ID_LRRC_GRR_GETUECAPINFO_REQ               = (LRRC_GRR_MSG_HDR + 0x16),     /* _H2ASN_MsgChoice LRRC_GRR_GETUECAPINFO_REQ_STRU */
    ID_GRR_LRRC_GETUECAPINFO_CNF               = (GRR_LRRC_MSG_HDR + 0x14),     /* _H2ASN_MsgChoice GRR_LRRC_GETUECAPINFO_CNF_STRU */

    /* L -> G cell srch. L重建时搜索G小区 */
    ID_LRRC_GRR_CELL_SRCH_REQ                  = (LRRC_GRR_MSG_HDR + 0x1c),       /* _H2ASN_MsgChoice LRRC_GRR_CELL_SRCH_REQ_STRU */
    ID_GRR_LRRC_CELL_SRCH_CNF                  = (GRR_LRRC_MSG_HDR + 0x1d),       /* _H2ASN_MsgChoice GRR_LRRC_CELL_SRCH_CNF_STRU */
    ID_LRRC_GRR_CELL_SRCH_STOP_REQ             = (LRRC_GRR_MSG_HDR + 0x1d),       /* _H2ASN_MsgChoice LRRC_GRR_CELL_SRCH_STOP_REQ_STRU */
    ID_GRR_LRRC_CELL_SRCH_STOP_CNF             = (GRR_LRRC_MSG_HDR + 0x1e),       /* _H2ASN_MsgChoice GRR_LRRC_CELL_SRCH_STOP_CNF_STRU */

    /* GTL版本中，L->G从模测量等ID已经使用了
	LRRC_GRR_MSG_HDR + [ 0x17 - 0x1b]和 GRR_LRRC_MSG_HDR + [ 0x15 - 0x1c ]
    此处将这些 ID值留空 */

    /* G-> L BackGroud Search */
    ID_GRR_LRRC_BG_PLMN_SEARCH_REQ         = (GRR_LRRC_MSG_HDR + 0x1f),         /* _H2ASN_MsgChoice GRR_LRRC_BG_PLMN_SEARCH_REQ_STRU */
    ID_LRRC_GRR_BG_PLMN_SEARCH_CNF         = (LRRC_GRR_MSG_HDR + 0x1e),         /* _H2ASN_MsgChoice LRRC_GRR_BG_PLMN_SEARCH_CNF_STRU */
    ID_LRRC_GRR_BG_PLMN_SEARCH_IND         = (LRRC_GRR_MSG_HDR + 0x1f),         /* _H2ASN_MsgChoice LRRC_GRR_BG_PLMN_SEARCH_IND_STRU */
    ID_GRR_LRRC_BG_SEARCH_STOP_REQ         = (GRR_LRRC_MSG_HDR + 0x20),         /* _H2ASN_MsgChoice GRR_LRRC_BG_SEARCH_STOP_REQ_STRU */
    ID_LRRC_GRR_BG_SEARCH_STOP_CNF         = (LRRC_GRR_MSG_HDR + 0x20),         /* _H2ASN_MsgChoice LRRC_GRR_BG_SEARCH_STOP_CNF_STRU */
    ID_GRR_LRRC_BG_SEARCH_SUSPEND_REQ      = (GRR_LRRC_MSG_HDR + 0x21),         /* _H2ASN_MsgChoice GRR_LRRC_BG_SEARCH_SUSPEND_REQ_STRU */
    ID_LRRC_GRR_BG_SEARCH_SUSPEND_CNF      = (LRRC_GRR_MSG_HDR + 0x21),         /* _H2ASN_MsgChoice LRRC_GRR_BG_SEARCH_SUSPEND_CNF_STRU */
    ID_LRRC_GRR_BG_SEARCH_RESUME_CNF       = (LRRC_GRR_MSG_HDR + 0x22),         /* _H2ASN_MsgChoice LRRC_GRR_BG_SEARCH_RESUME_CNF_STRU */
    ID_GRR_LRRC_BG_SEARCH_RESUME_REQ       = (GRR_LRRC_MSG_HDR + 0x22),         /* _H2ASN_MsgChoice GRR_LRRC_BG_SEARCH_RESUME_REQ_STRU */


    ID_GRR_LRRC_FR_INFO_REQ                    = (GRR_LRRC_MSG_HDR + 0x2b),     /* _H2ASN_MsgChoice GRR_LRRC_FR_INFO_REQ_STRU */
    ID_LRRC_GRR_FR_INFO_CNF                    = (LRRC_GRR_MSG_HDR + 0x29),     /* _H2ASN_MsgChoice LRRC_GRR_FR_INFO_CNF_STRU */

    ID_LRRC_GRR_MSG_TYPE_BUTT

};
typedef VOS_UINT32  LRRC_GRR_MSG_TYPE_ENUM_UINT32;

/*****************************************************************************
  5 STRUCT
*****************************************************************************/
/*****************************************************************************
 结构名    : GRR_LRRC_CELL_RESEL_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR发给LRRC指示小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usArfcn;
    VOS_UINT16                                              usCellId;
    /* 空口不存在该数据时，填写默认值0 */
    LRRC_GURRC_MEAS_BAND_WIDTH_ENUM_UINT16                  enMeasBand;

    /* 重选成功后惩罚定时器，在usPunishTimerValue内UE不能从L自主重选到G小区，
       单位:毫秒，目前默认为5000毫秒 */
    VOS_UINT16                                              usPunishTimerValue;

    /* G指示驻留到LTE 小区的类型，如果G支持CS语音则只能重选到SUITABLE小区 */
    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;
    VOS_UINT8                                               aucReserved[2];

    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stLrrcGurrcDPriInfo;
}GRR_LRRC_CELL_RESEL_REQ_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_CELL_RESEL_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示小区搜索结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_CELL_RESEL_RESULT_ENUM_UINT32                enRslt;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_NOT_EPLMNS时，stPlmnIdInfo 有效，
     该数据为此小区的PLMN IDs */
    LRRC_GURRC_PLMN_ID_INFO_LIST_STRU                       stPlmnIdInfo;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_SIB_RCV_FAIL,
       LRRC_GURRC_CELL_RESEL_CELL_BARRED, LRRC_GURRC_CELL_RESEL_ACCESS时，
       ulTimerVaule有效,单位 :毫秒*/
    VOS_UINT32                                              ulTimerValue;
}LRRC_GRR_CELL_RESEL_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_CELL_RESEL_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GRR指示LRRC停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_CELL_RESEL_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_CELL_RESEL_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR已停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_CELL_RESEL_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_REDIRECTED_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GSM系统中重定位信息
*****************************************************************************/
typedef struct
{

    VOS_UINT16                                              usArfcn;
    VOS_UINT8                                               aucReserved[3];
    VOS_UINT8                                               ucTargetCellPresent;
    VOS_UINT16                                              usCellId;

    /* 空口不存在该数据时，填写默认值0 */
    LRRC_GURRC_MEAS_BAND_WIDTH_ENUM_UINT16                  enMeasBand;

    /* LTE 系统中的黑名单信息 */
    VOS_UINT16                                              usBlackListCellNum;
    VOS_UINT16                                              ausBlackListCellId[LRRC_GURRC_BLACK_LIST_CELL_MAX_NUM];
}GRR_LRRC_REDIRECTED_INFO_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_REDIRECTED_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR发给LRRC指示启动重定向
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                                              ulRedirInfoNum;
    GRR_LRRC_REDIRECTED_INFO_STRU                           astGrrRedirInfo[LRRC_GURRC_LTE_ARFCN_MAX_NUM];

    /* CMCC-BEGIN */
    LRRC_GURRC_REDIR_TYPE_ENUM_UINT8                        enRedirType;
    VOS_UINT8                                               aucReserved[3];
    /* CMCC-END */

    /* 在REDIR INFO 指示搜索的时间 单位:毫秒,目前固定10000ms，
    在此时间内,LRRC只能在指示的频点内进行搜索，超时后，可以任意点上搜索 */
    VOS_UINT16                                              usSearchTimer;
    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;

    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stLrrcGurrcDPriInfo;
}GRR_LRRC_REDIRECTED_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_REDIRECTED_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示重定向结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_REDIRECTED_RESULT_ENUM_UINT32                enRslt;
}LRRC_GRR_REDIRECTED_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_REDIRECTED_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GRR指示LRRC停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_REDIRECTED_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_REDIRECTED_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR已停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_REDIRECTED_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_CELL_CHANGE_ORDER_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GRR指示LRRC启动CCO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usArfcn;
    VOS_UINT16                                              usCellId;

    /* 空口不存在该数据时，填写默认值0 */
    LRRC_GURRC_MEAS_BAND_WIDTH_ENUM_UINT16                  enMeasBand;
    VOS_UINT8                                               aucReserved[1];

    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stLrrcGurrcDPriInfo;
}GRR_LRRC_CELL_CHANGE_ORDER_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_CELL_CHANGE_ORDER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR完成CCO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_CCO_RESULT_ENUM_UINT32                       enRslt;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_NOT_EPLMNS时，stPlmnIdInfo 有效，
     该数据为此小区的PLMN IDs */
    LRRC_GURRC_PLMN_ID_INFO_LIST_STRU                       stPlmnIdInfo;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_SIB_RCV_FAIL,
       LRRC_GURRC_CELL_RESEL_CELL_BARRED, LRRC_GURRC_CELL_RESEL_ACCESS时，
       ulTimerVaule有效,单位 :毫秒*/
    VOS_UINT32                                              ulTimerValue;
}LRRC_GRR_CELL_CHANGE_ORDER_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_CELL_CHANGE_ORDER_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GRR指示LRRC停止CCO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_CELL_CHANGE_ORDER_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_CELL_CHANGE_ORDER_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR已停止CCO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_CELL_CHANGE_ORDER_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_HANDOVER_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR发给LRRC指示启动切换流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/

    /* 该数据为编码后的 RRC CONN RECFG 消息 */
    VOS_UINT32                                              ulHoDataLen;
    VOS_UINT8                                               aucHoData[4];
}GRR_LRRC_HANDOVER_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_HANDOVER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示切换流程结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_HANDOVER_RESULT_ENUM_UINT32                  enRslt;
}LRRC_GRR_HANDOVER_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_HANDOVER_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :GRR指示LRRC停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_HANDOVER_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_HANDOVER_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR已停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_HANDOVER_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_SET_DSP_POWER_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  GRR指示LRRC对DSP省电模式操作
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_CMD_ENUM_UINT32                enSetLDspPowerCmd;
}GRR_LRRC_SET_DSP_POWER_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_SET_DSP_POWER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR对EDSP操作省电流程结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_RESULT_ENUM_UINT32             enRslt;
}LRRC_GRR_SET_DSP_POWER_CNF_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_IDLE_MEASURE_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR发给LRRC指示启动IDLE测量
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpid;
    LRRC_GURRC_MEAS_CMD_ENUM_UINT16                         enMeasCmd;
    GURRC_LRRC_EUTRAN_INFO_LIST_STRU                        stIdleEutranArfcnInfoList;
}GRR_LRRC_IDLE_MEASURE_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_IDLE_MEASURE_CNF_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : LRRC发给GRR指示IDLE测量启动结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpid;
    VOS_UINT8                                               aucReserved[2];

    LRRC_GURRC_MEAS_RESULT_ENUM_UINT32                      enRslt;
}LRRC_GRR_IDLE_MEASURE_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_IDLE_MEASURE_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示IDLE 测量结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpid;
    VOS_UINT8                                               aucReserved[2];

    LRRC_GURRC_MEAS_EUTRAN_RESULT_STRU                      stIdleMeasResult;
}LRRC_GRR_IDLE_MEASURE_IND_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_CONNECTED_MEASURE_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR发给LRRC指示启动CONNECTED测量
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpid;
    LRRC_GURRC_MEAS_CMD_ENUM_UINT16                         enMeasCmd;
    GURRC_LRRC_EUTRAN_INFO_LIST_STRU                        stConnEutranArfcnInfoList;
}GRR_LRRC_CONNECTED_MEASURE_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_CONNECTED_MEASURE_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示CONNECTED测量启动结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpid;
    VOS_UINT8                                               aucReserved[2];

    LRRC_GURRC_MEAS_RESULT_ENUM_UINT32                      enRslt;
}LRRC_GRR_CONNECTED_MEASURE_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_CONNECTED_MEASURE_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示CONNECTED 测量结果
*****************************************************************************/
typedef struct
{
   VOS_MSG_HEADER                                                               /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpid;
    VOS_UINT8                                               aucReserved[2];

    LRRC_GURRC_MEAS_EUTRAN_RESULT_STRU                      stConnMeasResult;
}LRRC_GRR_CONNECTED_MEASURE_IND_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_CELL_RESEL_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GERAN_CELL_INFO_STRU                         stGeranCellInfo;
    /* G小区测量电平值,负数形式。如果无法获取，填为约定的无效值。*/
    VOS_INT16                                               sGeranCellRxlev;
    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;

    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stLrrcGurrcDPriInfo;
}LRRC_GRR_CELL_RESEL_REQ_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_CELL_RESEL_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR发给LRRC指示小区搜索结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_CELL_RESEL_RESULT_ENUM_UINT32                enRslt;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_NOT_EPLMNS时，stPlmnIdInfo 有效
        该数据为此小区的PLMN ID  */
    LRRC_GURRC_PLMN_ID_INFO_LIST_STRU                       stPlmnIdInfo;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_SIB_RCV_FAIL,
       LRRC_GURRC_CELL_RESEL_CELL_BARRED, LRRC_GURRC_CELL_RESEL_ACCESS时，
       ulTimerVaule有效,单位 :毫秒*/
    VOS_UINT32                                              ulTimerValue;
}GRR_LRRC_CELL_RESEL_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_CELL_RESEL_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示GRR停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_CELL_RESEL_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_CELL_RESEL_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GRR指示LRRC已停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_CELL_RESEL_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_SYSINFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LTE系统中携带的重定向、CCO或切换信息中的系统消息
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                              ulSysInfoLen;
    VOS_UINT8                                               aucSysInfoData[LRRC_GURRC_GERAN_SYS_MAX_LEN];
}LRRC_GRR_SYSINFO_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_REDIRECTED_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LTE系统中携带的重定向信息中的系统消息
                  协议6.2.2
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                              bitulBsicInfoPresent : 1;
    VOS_UINT32                                              bitulSysInfoPresent  : 1;
    VOS_UINT32                                              bitSpare             : 30;

    VOS_UINT16                                              usArfCn;
    LRRC_GRR_BANDINDICATOR_ENUM_UINT16                      enBandInd;
    LRRC_GRR_BSIC_INFO_STRU                                 stBsic;

    VOS_UINT32                                              ulSysInfoNum;
    LRRC_GRR_SYSINFO_STRU                                   astRedirSysInfo[LRRC_GURRC_GERAN_SYS_MAX_NUM];
}LRRC_GRR_REDIRECTED_INFO_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_REDIRECTED_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LTE 系统中携带的重定向信列表
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                              ulArfcnNum;
    LRRC_GRR_REDIRECTED_INFO_STRU                           astLrrcGrrRedirInfo[LRRC_GURRC_GERAN_ARFCN_MAX_NUM];
}LRRC_GRR_REDIRECTED_INFO_LIST_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_REDIRECTED_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示重定向流程启动
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/

    LRRC_GRR_REDIRECTED_INFO_LIST_STRU                      stRedirGeranInfo;

    /* CMCC-BEGIN */
    LRRC_GURRC_REDIR_SAVED_EUTRA_INFO_STRU                  stRedirEutraInfo;
    /* CMCC-END */

    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;
    VOS_UINT8                                               aucReserved[2];


    /* 专有优先级信息, 0: 表示不存在，1 表示存在*/
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enDPriInfoPresent;
    LRRC_GURRC_DEDICATED_PRI_INFO_STRU                      stLrrcGurrcDPriInfo;
}LRRC_GRR_REDIRECTED_REQ_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_REDIRECTED_CNF_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : GRR发给LRRC指示重定向结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_REDIRECTED_RESULT_ENUM_UINT32                enRslt;
}GRR_LRRC_REDIRECTED_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_REDIRECTED_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示GRR停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_REDIRECTED_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_REDIRECTED_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GRR指示LRRC已停止重定向流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_REDIRECTED_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_CELL_CHANGE_ORDER_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示重定向流程启动
                  LTE CCO 到GSM，是从连接态到IDLE，专有态信息无效
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GRR_SAVE_GERAN_CELL_INFO_STRU                      stGeranSaveCellInfo;

    /* CMCC-BEGIN */
    LRRC_GURRC_REDIR_SAVED_EUTRA_INFO_STRU                  stRedirEutraInfo;
    /* CMCC-END */

    /* CSFB 标志,1:表示是CSFB, 0: 表示不是CSFB */
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enCsfbInd;

    /* enNCOPresent = 1: 表示存在NCO, 0: 表示不存在NCO */
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enNCOPresent;
    VOS_UINT8                                               ucNetworkControlOrder;

    /* enSysInfoChoice = 1: 表示携带系统消息, 0: 表示不携带 */
    LRRC_GRR_SYS_TYPE_ENUM_UINT8                            enSysInfoChoice;

    VOS_UINT32                                              ulSysInfoNum;
    LRRC_GRR_SYSINFO_STRU                                   astCcoSysInfo[LRRC_GURRC_GERAN_SYS_MAX_NUM];
}LRRC_GRR_CELL_CHANGE_ORDER_REQ_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_CELL_CHANGE_ORDER_CNF_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : GRR发给LRRC指示重定向结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_CCO_RESULT_ENUM_UINT32                       enRslt;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_NOT_EPLMNS时，stPlmnIdInfo 有效，
     该数据为此小区的PLMN IDs */
    LRRC_GURRC_PLMN_ID_INFO_LIST_STRU                       stPlmnIdInfo;

    /* 当usResult 原因值为LRRC_GURRC_CELL_RESEL_SIB_RCV_FAIL,
       LRRC_GURRC_CELL_RESEL_CELL_BARRED, LRRC_GURRC_CELL_RESEL_ACCESS时，
       ulTimerVaule有效,单位 :毫秒*/
    VOS_UINT32                                              ulTimerValue;
}GRR_LRRC_CELL_CHANGE_ORDER_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_CELL_CHANGE_ORDER_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示GRR停止CCO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_CELL_CHANGE_ORDER_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_CELL_CHANGE_ORDER_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GRR指示LRRC已停止CCO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_CELL_CHANGE_ORDER_STOP_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_HANDOVER_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示HO流程启动, 协议6.2.2
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/

    /* v7r2 lld begin */
    /*#ifdef V7R2*/
    /* Add by zhuochao for SRVCC 20131025 begin */
    /* 目标GSM小区频段指示 */
    LRRC_GRR_BANDINDICATOR_ENUM_UINT16                      enBandInd;

    /* 同步切换时携带的L侧TA，单位为1TS，取值有效范围[0~20512]TS */
    VOS_UINT16                                              usTaValue;
    /* Add by zhuochao for SRVCC 20131025 end */
    /*#endif*/
    /* v7r2 lld end */

    /* CSFB 标志,1:表示是CSFB, 0: 表示不是CSFB */
    LRRC_GURRC_VALID_FLAG_ENUM_UINT8                        enCsfbInd;

    /* ucSysInfoChoice =0, 表示不携带系统消息 */
    LRRC_GRR_SYS_TYPE_ENUM_UINT8                            enSysInfoChoice;

    VOS_UINT16                                              usSysInfoNum;
    LRRC_GRR_SYSINFO_STRU                                   astHoSysInfo[LRRC_GURRC_GERAN_SYS_MAX_NUM];

    /* 连接态下测量CELL 信息 */
    LRRC_GRR_SAVE_GERAN_CELL_INFO_LIST_STRU                 stGeranCellInfoList;

    VOS_UINT8                                               aucPlmnId[3];
    VOS_UINT8                                               aucReserved[1];

    LRRC_GURRC_REDIR_SAVED_EUTRA_INFO_STRU                  stRedirEutraInfo;

    /* begin：add for chr */
    VOS_UINT32                                              ulHoBeginTimeStampHigh;
    VOS_UINT32                                              ulHoBeginTimeStampLow;
    /* end：add for chr */

    VOS_UINT32                                              ulHoDatalen;

    /* 编码后PS HANDOVER COMMAND 或者HANDOVER COMMAND 数据 */
    VOS_UINT8                                               aucHoData[4];
}LRRC_GRR_HANDOVER_REQ_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_HANDOVER_CNF_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  : GRR发给LRRC指示HO结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_HANDOVER_RESULT_ENUM_UINT32                  enRslt;
}GRR_LRRC_HANDOVER_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_HANDOVER_STOP_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :LRRC指示GRR停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_HANDOVER_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_HANDOVER_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GRR指示LRRC已停止HO流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_HANDOVER_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_SET_DSP_POWER_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示GRR对DSP省电模式操作
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_CMD_ENUM_UINT32                enSetLDspPowerCmd;
}LRRC_GRR_SET_DSP_POWER_REQ_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_SET_DSP_POWER_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GRR指示LRRC对EDSP操作完成
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_SET_DSP_POWER_RESULT_ENUM_UINT32             enRslt;
}GRR_LRRC_SET_DSP_POWER_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_GETUECAPINFO_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  LRRC指示GRR 提供UE能力信息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucPlmnId[3];
    VOS_UINT8                                               aucReserved[1];
}LRRC_GRR_GETUECAPINFO_REQ_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_GETUECAPINFO_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GRR指示LRRC对UE能力获取完成,GERAN UE CAP填写原则见下

For GERAN CS: the octet string contains the concatenated string of the Mobile Station Classmark 2
and Mobile Station Classmark 3. The first 5 octets correspond to Mobile Station Classmark 2
and the following octets correspond to Mobile Station Classmark 3. The Mobile Station Classmark 2
is formatted as 'TLV' and is coded in the same way as the Mobile Station Classmark 2 information
element in TS 24.008 [49]. The first octet is the Mobile station classmark 2 IEI and its value shall
be set to 33H. The second octet is the Length of mobile station classmark 2 and its value shall be
set to 3. The octet 3 contains the first octet of the value part of the Mobile Station Classmark 2
information element, the octet 4 contains the second octet of the value part of the Mobile Station
Classmark 2 information element and so on. For each of these octets, the first/ leftmost/ most significant
bit of the octet contains b8 of the corresponding octet of the Mobile Station Classmark 2. The Mobile
Station Classmark 3 is formatted as 'V' and is coded in the same way as the value part in the Mobile
station classmark 3 information element in TS 24.008 [49]. The sixth octet of this octet string contains
octet 1 of the value part of Mobile station classmark 3, the seventh of octet of this octet string contains
octet 2 of the value part of Mobile station classmark 3 and so on. Note.


For GERAN PS: the encoding of UE capabilities is formatted as 'V' and is coded in the same way as the
value part in the MS Radio Access Capability information element in TS 24.008 [49].
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_GET_UECAP_RESULT_ENUM_UINT16                 enRslt;
    VOS_UINT8                                               aucReserved[2];
    VOS_UINT16                                              usGeranCsDataLen;
    VOS_UINT16                                              usGeranPsDataLen;
    VOS_UINT8                                               aucGeranCsInfoData[LRRC_GRR_UE_CAP_GEREN_CS_MAX_LEN];
    VOS_UINT8                                               aucGeranPsInfoData[LRRC_GRR_UE_CAP_GEREN_PS_MAX_LEN];
}GRR_LRRC_GETUECAPINFO_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_CELL_SRCH_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC发给GRR指示小区搜索, 携带G小区信息
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[1];
    LRRC_GURRC_CELL_CAMPEDON_TYPE_ENUM_UINT8                enCellCampedType;
    VOS_UINT16                                              usArfcnNum;
    LRRC_GURRC_GERAN_CELL_STRU                              astGeranCellInfo[LRRC_GURRC_GERAN_ARFCN_MAX_NUM];
}LRRC_GRR_CELL_SRCH_REQ_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_CELL_SRCH_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR发给LRRC指示小区搜索结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/

    /* 找到指定驻留模式的G小区时使用LRRC_GURRC_CELL_RESEL_SUCC，
       没有找到指定驻留模式的G小区时使用LRRC_GURRC_CELL_RESEL_UNSPECIFIC */
    LRRC_GURRC_CELL_RESEL_RESULT_ENUM_UINT32                enRslt;

    /* 满足指定驻留模式驻留条件的G小区信息, BSIC信息由G提供。 如果enRslt为成功，
       L不管BSIC信息是否有效，在重选请求中直接使用 */
    LRRC_GURRC_GERAN_CELL_INFO_STRU                         stGeranCellInfo;

    /* G小区测量电平值,负数形式。如果无法获取，填为约定的无效值。*/
    VOS_INT16                                               sGeranCellRxlev;
    VOS_UINT8                                               aucReserved[2];

    /* stSuitablePlmnId和stPlmnIdList信息只在驻留模式为suitable时有意义，
       在驻留模式为any cell时暂时可以不填 */

    /* enRslt = LRRC_GURRC_CELL_RESEL_SUCC ，填写G CELL中携带的PLMN*/
    LRRC_GURRC_PLMN_ID_INFO_STRU                            stSuitablePlmnId;

    /* enRslt = LRRC_GURRC_CELL_RESEL_UNSPECIFIC ，携带在此过程中搜索到
       的所有的PLMN 信息，以高低质量排序传递给LRRC，具体准则同正常的
       PLMN LIST 搜索 */
    LRRC_GURRC_PLMN_ID_LIST_STRU                            stPlmnIdList;
}GRR_LRRC_CELL_SRCH_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_CELL_SRCH_STOP_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示GRR停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_CELL_SRCH_STOP_REQ_STRU;

/*****************************************************************************
 结构名    : GRR_LRRC_CELL_SRCH_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR指示LRRC已停止小区搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_CELL_SRCH_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :   GRR_LRRC_BG_PLMN_SEARCH_REQ_STRU
 协议表格  :
 ASN.1描述   :
 结构说明  :  GRR指示LRRC执行背景搜索
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32               enMsgId;                        /*_H2ASN_Skip*/

    LRRC_GURRC_PLMN_ID_INFO_STRU                stPlmnId;

    LRRC_GURRC_SEARCH_TYPE_ENUM_UINT8           enSearchType;                   /* 是做背景搜还是PLMN LIST搜 */

    VOS_UINT8                                   aucRsv1[3];
}GRR_LRRC_BG_PLMN_SEARCH_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_BG_PLMN_SEARCH_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   GRR指示LRRC执行背景搜索的确认
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                          enMsgId;             /*_H2ASN_Skip*/
    LRRC_GURRC_BG_SEARCH_RESULT_ENUM_UINT16                enRslt;
    VOS_UINT8                                              aucRsv1[2];
}LRRC_GRR_BG_PLMN_SEARCH_CNF_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_BG_PLMN_SEARCH_IND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR执行背景搜索的结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;             /*_H2ASN_Skip*/
    LRRC_GURRC_BG_SEARCH_RESULT_ENUM_UINT16                 enRslt;
    LRRC_GURRC_SEARCH_TYPE_ENUM_UINT8                       enSearchType;        /* 是做背景搜还是PLMN LIST搜 */
    VOS_UINT8                                               aucRsv1[1];

    LRRC_GURRC_PLMN_ID_LIST_STRU                            stPlmnIdList;
}LRRC_GRR_BG_PLMN_SEARCH_IND_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_BG_SEARCH_STOP_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR指示LRRC停止背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                          enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                              aucReserved[4];
}GRR_LRRC_BG_SEARCH_STOP_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_BG_SEARCH_STOP_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR已停止背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                          enMsgId;             /*_H2ASN_Skip*/
    VOS_UINT8                                              aucReserved[4];
}LRRC_GRR_BG_SEARCH_STOP_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_BG_SEARCH_SUSPEND_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR指示LRRC挂起背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}GRR_LRRC_BG_SEARCH_SUSPEND_REQ_STRU;

/*****************************************************************************
 结构名    :    LRRC_GRR_BG_SEARCH_SUSPEND_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR已挂起背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT8                                               aucReserved[4];
}LRRC_GRR_BG_SEARCH_SUSPEND_CNF_STRU;

/*****************************************************************************
 结构名    :    GRR_LRRC_BG_SEARCH_RESUME_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRR指示LRRC恢复背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                          enMsgId;             /*_H2ASN_Skip*/
    VOS_UINT8                                              aucReserved[4];
}GRR_LRRC_BG_SEARCH_RESUME_REQ_STRU;

/*****************************************************************************
 结构名    :   LRRC_GRR_BG_SEARCH_RESUME_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :   LRRC指示GRR已恢复背景搜索流程
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                          enMsgId;             /*_H2ASN_Skip*/
    VOS_UINT8                                              aucReserved[4];

}LRRC_GRR_BG_SEARCH_RESUME_CNF_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_MSG_DATA
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC_GRR_MSG_DATA数据结构，用于生成ASN文件
*****************************************************************************/
typedef struct
{
    LRRC_GRR_MSG_TYPE_ENUM_UINT32                           enMsgID;            /*_H2ASN_MsgChoice_Export LRRC_GRR_MSG_TYPE_ENUM_UINT32 */
    VOS_UINT8                                               aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          LRRC_GRR_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}LRRC_GRR_MSG_DATA;

/*_H2ASN_Length UINT32*/

/*****************************************************************************
 结构名    : LRRCGRRInterface_MSG
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRCGRRInterface_MSG数据结构,用于生成ASN文件
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    LRRC_GRR_MSG_DATA                                       stMsgData;
}LRrcGrrInterface_MSG;

/*****************************************************************************
 结构名    : GRR_LRRC_FR_INFO_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : GRRC指示LRRC获取LTE自主FR频点
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                               /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32            enMsgId;            /*_H2ASN_Skip*/
}GRR_LRRC_FR_INFO_REQ_STRU;

/*****************************************************************************
 结构名    : LRRC_GRR_FR_INFO_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LRRC指示GRRC获取LTE自主FR频点的结果
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                               /*_H2ASN_Skip*/
    LRRC_GRR_MSG_TYPE_ENUM_UINT32            enMsgId;            /*_H2ASN_Skip*/
    LRRC_GURRC_REDIR_SAVED_EUTRA_INFO_STRU    stRedirEutraInfo;
}LRRC_GRR_FR_INFO_CNF_STRU;

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

#endif /* end of LRRC_GRRInterface.h */
