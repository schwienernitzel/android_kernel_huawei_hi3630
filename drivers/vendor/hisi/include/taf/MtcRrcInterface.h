

#ifndef __MTCRRCINTERFACE_H__
#define __MTCRRCINTERFACE_H__

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)


/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define  MTC_RRC_TDS_ARFCN_MAX_NUM                          (9)                 /* TDS频点列表最大个数，用于GAS根据邻区结构给MTC上报频点信息 */
#define  MTC_RRC_LTE_ARFCN_MAX_NUM                          (8)                 /* LTE频点列表最大个数，用于GAS根据邻区结构给MTC上报频点信息 */
#define  MTC_RRC_GSM_MAX_USING_ARFCN_NUM                    (7)                 /* GSM频点列表最大个数 */
#define  MTC_RRC_GSM_MA_ARFCN_MAX_NUM                       (64)                /* GSM跳频频点列表最大个数 */
#define  MTC_RRC_WCDMA_MAX_USING_ARFCN_NUM                  (4)                 /* WCDMA频点列表最大个数 */

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum MTC_RRC_MSG_ID_ENUM
{
    /* 消息名称 */                             /* 消息ID */                     /* 备注 */
    /* MTC --> RRC */
    ID_MTC_RRC_INTRUSION_ACTION_SET_REQ     = 0x0001,                           /* _H2ASN_MsgChoice MTC_RRC_INTRUSION_ACTION_SET_REQ_STRU */
    ID_MTC_RRC_INTRUSION_BAND_SET_REQ       = 0x0003,                           /* _H2ASN_MsgChoice MTC_RRC_INTRUSION_BAND_SET_REQ_STRU */
    ID_MTC_RRC_NOTCH_CHANNEL_IND            = 0x0005,                           /* _H2ASN_MsgChoice MTC_RRC_NOTCH_CHANNEL_IND_STRU */
    ID_MTC_RRC_BAND_CFG_IND                 = 0x0007,                           /* _H2ASN_MsgChoice MTC_RRC_BAND_CFG_IND_STRU */
    ID_MTC_RRC_TDS_LTE_RF_CONTROL_IND       = 0x0009,                           /* _H2ASN_MsgChoice MTC_RRC_TDS_LTE_RF_CONTROL_IND_STRU */

    ID_MTC_RRC_GSM_CELL_INFO_IND            = 0x000B,                           /* _H2ASN_MsgChoice MTC_RRC_GSM_CELL_INFO_IND_STRU */

    /* RRC --> MTC */
    ID_RRC_MTC_INTRUSION_ACTION_SET_CNF     = 0x0002,                           /* _H2ASN_MsgChoice RRC_MTC_RESULT_CNF_STRU */
    ID_RRC_MTC_INTRUSION_BAND_SET_CNF       = 0x0004,                           /* _H2ASN_MsgChoice RRC_MTC_RESULT_CNF_STRU */
    ID_RRC_MTC_INTRUSION_BAND_INFO_IND      = 0x0006,                           /* _H2ASN_MsgChoice RRC_MTC_INTRUSION_BAND_INFO_IND_STRU */
    ID_RRC_MTC_AREA_LOST_IND                = 0x0008,                           /* _H2ASN_MsgChoice RRC_MTC_AREA_LOST_IND_STRU */
    ID_RRC_MTC_NCELL_INFO_IND               = 0x000A,                           /* _H2ASN_MsgChoice RRC_MTC_NCELL_INFO_IND_STRU */
    ID_RRC_MTC_AREA_AVALIABLE_IND           = 0x000C,                           /* _H2ASN_MsgChoice RRC_MTC_AREA_AVALIABLE_IND_STRU */
    ID_MTC_RRC_RSE_CFG_IND                  = 0x000D,                           /* _H2ASN_MsgChoice MTC_RRC_RSE_CFG_IND_STRU */
    ID_RRC_MTC_USING_FREQ_IND               = 0x000E,                           /* _H2ASN_MsgChoice RRC_MTC_USING_FREQ_IND_STRU */

    ID_RRC_MTC_GSM_CELL_INFO_IND            = 0x0010,                           /* _H2ASN_MsgChoice RRC_MTC_GSM_CELL_INFO_IND_STRU */

    ID_MTC_RRC_MSG_ID_ENUM_BUTT
};
typedef VOS_UINT32  MTC_RRC_MSG_ID_ENUM_UINT32;


enum MTC_RRC_RESULT_ENUM
{
    MTC_RRC_RESULT_NO_ERROR             = 0x0000,                               /* 消息处理正常 */
    MTC_RRC_RESULT_ERROR,

    MTC_RRC_RESULT_BUTT
};
typedef VOS_UINT32  MTC_RRC_RESULT_ENUM_UINT32;

/*****************************************************************************
 枚举名     :RRC_MTC_GSM_BANDINDICATOR_ENUM
 协议表格  :
 ASN.1描述   :
 枚举说明 : 2G小区频带指示
*****************************************************************************/
enum RRC_MTC_GSM_BANDINDICATOR_ENUM
{
    RRC_MTC_GSM_BANDINDICATOR_DCS1800                          = 0,
    RRC_MTC_GSM_BANDINDICATOR_PCS1900                             ,

    RRC_MTC_GSM_BANDINDICATOR_BUTT
};
typedef VOS_UINT16    RRC_MTC_GSM_BANDINDICATOR_ENUM_UINT16;


enum RRC_MTC_GSM_CELL_STATE_ENUM
{
    RRC_MTC_GSM_CELL_STATE_IDLE         = 0,                                    /* 空闲态 */
    RRC_MTC_GSM_CELL_STATE_CONNECT         ,                                    /* 专用态 */

    RRC_MTC_GSM_CELL_STATE_BUTT
};
typedef VOS_UINT32 RRC_MTC_GSM_CELL_STATE_ENUM_UINT32;


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

typedef struct
{
    VOS_UINT32                          aulBandInfo[2];                         /* 频段信息，每个Bit表示一个Band */
}RRC_MTC_MS_BAND_INFO_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enActionFlag;                           /* 打开或者关闭干扰功能 */
    VOS_UINT8                           aucRsv[3];
}MTC_RRC_INTRUSION_ACTION_SET_REQ_STRU;


typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    RRC_MTC_MS_BAND_INFO_STRU           stForbiddenBandInfo;                    /* 需要禁止的频段信息, Band对应的Bit位为0代表不禁止, 1代表禁止 */
}MTC_RRC_INTRUSION_BAND_SET_REQ_STRU;


typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTC_RRC_RESULT_ENUM_UINT32          enResult;
}RRC_MTC_RESULT_CNF_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    RRC_MTC_MS_BAND_INFO_STRU           stCurBandInfo;                          /* 当前检测到的频段信息(过滤掉不支持的频段), Band对应的Bit位为0代表不存在, 1代表存在 */
    RRC_MTC_MS_BAND_INFO_STRU           stSerCellBandInfo;                      /* 当前驻留到的频段信息(过滤掉不支持的频段), Band对应的Bit位为0代表不存在, 1代表存在 */
}RRC_MTC_INTRUSION_BAND_INFO_IND_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enIdleStateFlag;                        /* PS_TURE 表示Idle态丢网*/
    VOS_UINT8                           aucRsv[3];                              /*保留位*/
}RRC_MTC_AREA_LOST_IND_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enStartFlag;                            /* PS_TURE:启动NOTCH通道，PS_FALSE:不启动NOTCH通道 */
    VOS_UINT8                           aucRsv[3];                              /*保留位*/
}MTC_RRC_NOTCH_CHANNEL_IND_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enNarrowDcsFlag;                        /* PS_TURE:启动窄带DCS，PS_FALSE:不启动窄带DCS */
    VOS_UINT8                           aucRsv[3];                              /*保留位*/
}MTC_RRC_BAND_CFG_IND_STRU;
typedef struct
{
    VOS_UINT8                           ucTdsArfcnNum;                              /* TDS频点个数，0表示TDS频点不存在 */
    VOS_UINT8                           aucRsv[1];                                  /* 保留位*/
    VOS_UINT16                          ausTdsArfcnList[MTC_RRC_TDS_ARFCN_MAX_NUM]; /* 频点列表 */
}RRC_MTC_TDS_NCELL_INFO_STRU;
typedef struct
{
    VOS_UINT8                           ucLteArfcnNum;                              /* LTE频点个数，0表示LTE频点不存在 */
    VOS_UINT8                           aucRsv[3];                                  /* 保留位*/
    VOS_UINT16                          ausLteArfcnList[MTC_RRC_LTE_ARFCN_MAX_NUM]; /* 频点列表 */
}RRC_MTC_LTE_NCELL_INFO_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                      /*_H2ASN_Skip*/

    RRC_MTC_TDS_NCELL_INFO_STRU         stTdsNCellInfo;                   /* TDS频点列表信息 */

    RRC_MTC_LTE_NCELL_INFO_STRU         stLteNCellInfo;                   /* LTE频点列表信息 */
}RRC_MTC_NCELL_INFO_IND_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                      /*_H2ASN_Skip*/
}RRC_MTC_AREA_AVALIABLE_IND_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enUplinkCloseFlag;                      /* PS_TRUE:关闭上行发射，PS_FALSE:不关闭上行发射 */
    VOS_UINT8                           aucRsv[3];                              /* 保留位 */
}MTC_RRC_TDS_LTE_RF_CONTROL_IND_STRU;
typedef struct
{
    VOS_UINT16                              usGsmArfcn;     /* 绝对频点号 */
    RRC_MTC_GSM_BANDINDICATOR_ENUM_UINT16   enBandInd;      /* Band指示, 指示当前频点是 1800 系统 或 1900 系统 */
}RRC_MTC_GSM_FREQ_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucGsmArfcnNum;                                      /* GSM频点个数，0表示GSM频点不存在 */
    VOS_UINT8                           ucGsmMaArfcnNum;                                    /* 业务频点个数, 如当前不是G主模,则为0 */
    VOS_UINT8                           aucRsv[2];
    RRC_MTC_GSM_FREQ_INFO_STRU          astGsmArfcnList[MTC_RRC_GSM_MAX_USING_ARFCN_NUM];   /* 服务小区及邻区频点列表, 服务小区频点在第一位 */
    RRC_MTC_GSM_FREQ_INFO_STRU          astGsmMaArfcnList[MTC_RRC_GSM_MA_ARFCN_MAX_NUM];    /* 业务频点信息，此信息只在G主模下有效 */
}RRC_MTC_GSM_FREQ_INFO_LIST_STRU;


typedef struct
{
    VOS_UINT8                           ucWcdmaArfcnNum;                                        /* W频点个数，0表示WCDMA频点不存在 */
    VOS_UINT8                           aucRsv[3];                                              /* 保留位*/
    VOS_UINT16                          ausWcdmaArfcnList[MTC_RRC_WCDMA_MAX_USING_ARFCN_NUM];   /* 频点列表 */
}RRC_MTC_WCDMA_FREQ_INFO_LIST_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                       /*_H2ASN_Skip*/

    RRC_MTC_GSM_FREQ_INFO_LIST_STRU     stGsmFreqInfo;                     /* GSM频点列表信息 */

    RRC_MTC_WCDMA_FREQ_INFO_LIST_STRU   stWcdmaFreqInfo;                   /* WCDMA频点列表信息 */

    RRC_MTC_TDS_NCELL_INFO_STRU         stTdsFreqInfo;                     /* TDS频点列表信息 */

    RRC_MTC_LTE_NCELL_INFO_STRU         stLteFreqInfo;                     /* LTE频点列表信息 */

    PS_BOOL_ENUM_UINT8                  enCsExistFlag;                     /* PS_FALSE 表示不存在CS连接 */
    PS_BOOL_ENUM_UINT8                  enPsExistFlag;                     /* PS_FALSE 表示不存在PS连接 */
    VOS_UINT8                           aucRsv[2];
}RRC_MTC_USING_FREQ_IND_STRU;
typedef struct
{
    VOS_UINT16                              usArfcn;                            /* GSM绝对频点信息 */
    RRC_MTC_GSM_BANDINDICATOR_ENUM_UINT16   enBandInd;                          /* 1800,1900频段指示 */
    RRC_MTC_GSM_CELL_STATE_ENUM_UINT32      enCellState;                        /* 当前小区状态，空闲态或者专用态 */
    VOS_UINT8                               ucNcc;                              /* BSIC信息中网络色码 */
    VOS_UINT8                               ucBcc;                              /* BSIC信息中基站色码 */
    VOS_INT16                               sRssi;                              /* sRssi 取值范围[-110 * 8,-48 * 8],单位:dbm,精度1/8 */
}RRC_MTC_GSM_CELL_INFO_STRU;



typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/

    RRC_MTC_GSM_CELL_INFO_STRU          stGsmCellInfo;                          /* GSM小区信息 */
}RRC_MTC_GSM_CELL_INFO_IND_STRU;


typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/

    RRC_MTC_GSM_CELL_INFO_STRU          stGsmCellInfo;                          /* GSM小区信息 */
}MTC_RRC_GSM_CELL_INFO_IND_STRU;


typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enRseOnFlag;                            /* PS_TURE:RSE ON，PS_FALSE:RSE OFF */
    VOS_UINT8                           aucRsv[3];                              /*保留位*/
}MTC_RRC_RSE_CFG_IND_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/

/*****************************************************************************
  10 函数声明
*****************************************************************************/


/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    MTC_RRC_MSG_ID_ENUM_UINT32          enMsgId;                                /*_H2ASN_MsgChoice_Export MTC_RRC_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MTC_RRC_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}MTC_RRC_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MTC_RRC_MSG_DATA                    stMsgData;
}MtcRrcInterface_MSG;

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

