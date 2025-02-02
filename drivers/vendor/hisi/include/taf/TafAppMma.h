

#ifndef __TAF_APP_MMA_H__
#define __TAF_APP_MMA_H__

#include "TafTypeDef.h"
/*#include "NasCommDef.h" */
#include "UsimPsInterface.h"

#include  "AtMnInterface.h"
#include "TafNvInterface.h"

#include "AppVcApi.h"

#ifdef  __cplusplus
#if  __cplusplus
extern "C"{
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

#define TAF_MMA_PNN_INFO_MAX_NUM                           (50)                /* AT模块要求MMA一次上报的PNN个数 */

#define TAF_MMA_PLMN_MNC_TWO_BYTES                          (2)                 /* MNC的最大长度为3位，实际长度为2位或3位，可选 */

#define TAF_MMA_COPN_PLMN_MAX_NUM                           (50)                /* AT模块要求MMA一次上报的运营商个数 */

#define TAF_MMA_NET_SCAN_MAX_FREQ_NUM                       (20)

#define TAF_MMA_REG_MAX_PLMN_NUM                            (8)
#define TAF_MMA_REG_MAX_CELL_NUM                            (8)

/*****************************************************************************
 枚举名    : TAF_MMA_PLMN_MNC_DIGIT_MASK_ENUM
 结构说明  : 运营商信息PLMN的数字格式MNC各字段的掩码
             0: DRV_AGENT_TSELRF_SET_ERROR_NO_ERROR 设置操作成功；
             1: DRV_AGENT_TSELRF_SET_ERROR_LOADDSP  设置操作失败；
*****************************************************************************/
enum TAF_MMA_PLMN_MNC_DIGIT_MASK_ENUM
{
    TAF_MMA_PLMN_MNC_DIGIT1_MASK = 0x00f,
    TAF_MMA_PLMN_MNC_DIGIT2_MASK = 0x0f0,
    TAF_MMA_PLMN_MNC_DIGIT3_MASK = 0xf00,
    TAF_MMA_PLMN_MNC_DIGIT_MASK_BUTT
};

enum TAF_MMA_PLMN_MNC_DIGIT_OFFSET_ENUM
{
    TAF_MMA_PLMN_MNC_DIGIT1_OFFSET = 0,
    TAF_MMA_PLMN_MNC_DIGIT2_OFFSET = 4,
    TAF_MMA_PLMN_MNC_DIGIT3_OFFSET = 8,
    TAF_MMA_PLMN_MNC_DIGIT_OFFSET_BUTT
};

enum TAF_MMA_PLMN_MCC_DIGIT_MASK_ENUM
{
    TAF_MMA_PLMN_MCC_DIGIT1_MASK = 0x00f,
    TAF_MMA_PLMN_MCC_DIGIT2_MASK = 0x0f0,
    TAF_MMA_PLMN_MCC_DIGIT3_MASK = 0xf00,
    TAF_MMA_PLMN_MCC_DIGIT_MASK_BUTT
};

enum TAF_MMA_PLMN_MCC_DIGIT_OFFSET_ENUM
{
    TAF_MMA_PLMN_MCC_DIGIT1_OFFSET = 0,
    TAF_MMA_PLMN_MCC_DIGIT2_OFFSET = 4,
    TAF_MMA_PLMN_MCC_DIGIT3_OFFSET = 8,
    TAF_MMA_PLMN_MCC_DIGIT_OFFSET_BUTT
};

#define NAS_MM_INFO_IE_NULL             (0x00)
#define NAS_MM_INFO_IE_LTZ              0x01        /* Local time zone */
#define NAS_MM_INFO_IE_UTLTZ            0x02        /* Universal time and local time zone */
#define NAS_MM_INFO_IE_LSA              0x04        /* LSA Identity */
#define NAS_MM_INFO_IE_DST              0x08        /* Network Daylight Saving Time */
#define NAS_MM_INFO_IE_NETWORKFULLNAME  0x10        /* Full name for network */
#define NAS_MM_INFO_IE_NETWORKSHORTNAME 0x20        /* Short name for network */

/* 新增IMSI长度定义 */
#define   NAS_MAX_IMSI_LENGTH           (9)

/* +CSQLVL 相关的宏定义 */
#define AT_CSQLVL_MAX_NUM               (3)
#define AT_CSQLVL_LEVEL_0               (0)
#define AT_CSQLVL_LEVEL_1               (20)
#define AT_CSQLVL_LEVEL_2               (40)
#define AT_CSQLVL_LEVEL_3               (60)

#define DRVAGENT_GPIOPL_MAX_LEN          (20)

#define TAF_CDROM_VERSION_LEN         128

/*硬件版本号最大长度*/
#define DRV_AGENT_MAX_HARDWARE_LEN            (31)

#define TAF_MAX_REVISION_ID_LEN     (31)

#define TAF_MAX_MODEL_ID_LEN     (31)

#define TAF_MAX_HARDWARE_LEN            (31)


#define PRODUCTION_CARD_TYPE   "WCDMA"

#define TAF_UTRANCTRL_UTRAN_MODE_FDD    (0)
#define TAF_UTRANCTRL_UTRAN_MODE_TDD    (1)

#define AT_HS_PARA_MAX_LENGTH           (9)

#define TAF_MMA_UTRA_BLER_INVALID       (99)
#define TAF_MMA_RSSI_LOWER_LIMIT        (-114)
#define TAF_MMA_UTRA_RSCP_UNVALID       (-140)

#define TAF_MMA_RPT_CFG_MAX_SIZE         (8)

/*****************************************************************************
  6 消息定义
*****************************************************************************/

/*****************************************************************************
 枚举名    : AT_MMA_MSG_TYPE_ENUM
 结构说明  : AT与MMA消息接口枚举
*****************************************************************************/
enum AT_MMA_MSG_TYPE_ENUM
{
    /* 消息名称 */                      /*消息ID*/      /* 备注 */
    /* AT发给MMA的消息 */


    /* MMA发给AT的消息 */
    AT_MMA_OM_MAINTAIN_INFO_IND         = 0x0001,
    AT_MMA_USIM_STATUS_IND              = 0x0003,
    AT_MMA_CRPN_QUERY_RSP               = 0x0005,
    AT_MMA_CMM_SET_CMD_RSP              = 0x0007,

    AT_MMA_CIPHER_INFO_QUERY_CNF        = 0x0009,
    AT_MMA_LOCATION_INFO_QUERY_CNF      = 0x000b,
    AT_MMA_SIMLOCK_STAUS_QUERY_CNF      = 0x000d,

    AT_MMA_AC_INFO_QUERY_CNF            = 0x000f,

    AT_MMA_CERSSI_INFO_QUERY_CNF        = 0x0010,

    AT_MMA_COPN_INFO_QUERY_CNF          = 0x0013,

    AT_MMA_SIM_INSERT_RSP               = 0x0015,
    AT_MMA_CPOL_INFO_QUERY_CNF          = 0x0017,

    /* 该枚举不再允许添加消息，添加消息请添加到TAF_MMA_MSG_TYPE_ENUM中 */
    AT_MMA_MSG_TYPE_BUTT                = 0x0018,
};
typedef VOS_UINT32 AT_MMA_MSG_TYPE_ENUM_UINT32;

/*****************************************************************************
 枚举名    : TAF_MMA_MSG_TYPE_ENUM
 结构说明  : MMA消息接口枚举
*****************************************************************************/
enum TAF_MMA_MSG_TYPE_ENUM
{
    ID_TAF_MMA_MSG_TYPE_BEGIN           = AT_MMA_MSG_TYPE_BUTT,
    ID_TAF_MMA_PHONE_MODE_SET_REQ       = AT_MMA_MSG_TYPE_BUTT + 1,
    ID_TAF_MMA_PHONE_MODE_SET_CNF       = AT_MMA_MSG_TYPE_BUTT + 2,
    ID_TAF_MMA_SYS_CFG_SET_REQ          = AT_MMA_MSG_TYPE_BUTT + 3,
    ID_TAF_MMA_SYS_CFG_SET_CNF          = AT_MMA_MSG_TYPE_BUTT + 4,
    ID_TAF_MMA_ACQ_BEST_NETWORK_REQ     = AT_MMA_MSG_TYPE_BUTT + 5,
    ID_TAF_MMA_ACQ_BEST_NETWORK_CNF     = AT_MMA_MSG_TYPE_BUTT + 6,
    ID_TAF_MMA_REG_REQ                  = AT_MMA_MSG_TYPE_BUTT + 7,
    ID_TAF_MMA_REG_CNF                  = AT_MMA_MSG_TYPE_BUTT + 8,
    ID_TAF_MMA_DETACH_REQ               = AT_MMA_MSG_TYPE_BUTT + 9,
    ID_TAF_MMA_DETACH_CNF               = AT_MMA_MSG_TYPE_BUTT + 10,
    ID_TAF_MMA_POWER_SAVE_REQ           = AT_MMA_MSG_TYPE_BUTT + 11,
    ID_TAF_MMA_POWER_SAVE_CNF           = AT_MMA_MSG_TYPE_BUTT + 12,
    ID_TAF_MMA_SERVICE_STATUS_IND       = AT_MMA_MSG_TYPE_BUTT + 13,
    ID_TAF_MMA_ACQ_IND                  = AT_MMA_MSG_TYPE_BUTT + 14,
    ID_TAF_MMA_SYS_INFO_IND             = AT_MMA_MSG_TYPE_BUTT + 15,
    ID_TAF_MMA_SIM_STATUS_IND           = AT_MMA_MSG_TYPE_BUTT + 16,
    ID_TAF_MMA_IMS_SRV_INFO_NOTIFY      = AT_MMA_MSG_TYPE_BUTT + 17,

    ID_TAF_MMA_IMS_SWITCH_SET_REQ       = AT_MMA_MSG_TYPE_BUTT + 19, /* _H2ASN_MsgChoice TAF_MMA_IMS_SWITCH_SET_REQ_STRU */
    ID_TAF_MMA_IMS_SWITCH_SET_CNF       = AT_MMA_MSG_TYPE_BUTT + 20, /* _H2ASN_MsgChoice TAF_MMA_IMS_SWITCH_SET_CNF_STRU */
    ID_TAF_MMA_IMS_SWITCH_QRY_REQ       = AT_MMA_MSG_TYPE_BUTT + 21, /* _H2ASN_MsgChoice TAF_MMA_IMS_SWITCH_QRY_REQ_STRU */
    ID_TAF_MMA_IMS_SWITCH_QRY_CNF       = AT_MMA_MSG_TYPE_BUTT + 22, /* _H2ASN_MsgChoice TAF_MMA_IMS_SWITCH_QRY_CNF_STRU */
    ID_TAF_MMA_VOICE_DOMAIN_SET_REQ     = AT_MMA_MSG_TYPE_BUTT + 23, /* _H2ASN_MsgChoice TAF_MMA_VOICE_DOMAIN_SET_REQ_STRU */
    ID_TAF_MMA_VOICE_DOMAIN_SET_CNF     = AT_MMA_MSG_TYPE_BUTT + 24, /* _H2ASN_MsgChoice TAF_MMA_VOICE_DOMAIN_SET_CNF_STRU */
    ID_TAF_MMA_VOICE_DOMAIN_QRY_REQ     = AT_MMA_MSG_TYPE_BUTT + 25, /* _H2ASN_MsgChoice TAF_MMA_VOICE_DOMAIN_QRY_REQ_STRU */
    ID_TAF_MMA_VOICE_DOMAIN_QRY_CNF     = AT_MMA_MSG_TYPE_BUTT + 26, /* _H2ASN_MsgChoice TAF_MMA_VOICE_DOMAIN_QRY_CNF_STRU */

    ID_TAF_MMA_MSG_TYPE_BUTT
};
typedef VOS_UINT32 TAF_MMA_MSG_TYPE_ENUM_UINT32;


enum TAF_PH_RAT_TYPE_ENUM
{
    TAF_PH_RAT_GSM,                                                             /* GSM接入技术 */
    TAF_PH_RAT_WCDMA,                                                           /* WCDMA接入技术 */
    TAF_PH_RAT_LTE,                                                             /* LTE接入技术 */
    TAF_PH_RAT_BUTT
};
typedef VOS_UINT8 TAF_PH_RAT_TYPE_ENUM_UINT8;

/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/
/* AT处理MN_CALLBACK_CMD_CNF事件时所使用的数据结构 */
typedef struct
{
    MN_CLIENT_ID_T              clientId;
    MN_OPERATION_ID_T           opId;
    TAF_UINT8                   ucRsv;
    TAF_UINT32                  ulErrorCode;
}AT_CMD_CNF_EVENT;


/*****************************************************************************
 枚举名    : AT_MMA_USIM_STATUS_IND_STRU
 结构说明  : AT与MMA AT_MMA_USIM_STATUS_IND消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                      ulMsgName;
    USIMM_CARD_TYPE_ENUM_UINT32     enCardType;                     /* 卡类型:SIM、USIM、ROM-SIM  */
    USIMM_CARD_SERVIC_ENUM_UINT32   enCardStatus;                   /* 卡状态*/
    VOS_UINT8                       aucIMSI[NAS_MAX_IMSI_LENGTH];   /* IMSI号*/
    VOS_UINT8                       ucIMSILen;                      /* IMSI长度 */
    VOS_UINT8                       ucRsv[2];
}AT_MMA_USIM_STATUS_IND_STRU;

/*****************************************************************************
 枚举名    : AT_MMA_SIMLOCK_STATUS_STRU
 结构说明  : AT与MMA AT_MMA_SIMLOCK_STATUS_STRU消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                      ulMsgName;
    AT_APPCTRL_STRU                 stAtAppCtrl;
    VOS_BOOL                        bSimlockEnableFlg;
}AT_MMA_SIMLOCK_STATUS_STRU;


enum  TAF_MMA_CELL_RESTRICTION_TYPE_ENUM
{
    TAF_MMA_CELL_RESTRICTION_TYPE_NONE                   = 0,                           /* 当前小区不限制任何业务 */
    TAF_MMA_CELL_RESTRICTION_TYPE_NORMAL_SERVICE         = 1,                           /* 当前小区限制正常业务 */
    TAF_MMA_CELL_RESTRICTION_TYPE_EMERGENCY_SERVICE      = 2,                           /* 当前小区限制紧急业务 */
    TAF_MMA_CELL_RESTRICTION_TYPE_ALL_SERVICE            = 3,                           /* 当前小区限制正常业务和紧急业务 */
    TAF_MMA_CELL_RESTRICTION_TYPE_BUTT
};
typedef VOS_UINT8   TAF_MMA_CELL_RESTRICTION_TYPE_ENUM_UINT8;


typedef struct
{
    TAF_UINT8                                   ucSrvDomain;                                    /* 服务域 0:CS,1:ps */
    TAF_MMA_CELL_RESTRICTION_TYPE_ENUM_UINT8    enCellAcType;                                   /* 小区受限类型 */
    VOS_UINT8                                   ucRestrictRegister;                             /* 是否限制注册 */
    VOS_UINT8                                   ucRestrictPagingRsp;                            /* 是否限制响应寻呼 */
}TAF_MMA_CELL_AC_INFO_STRU;


typedef struct
{
    VOS_UINT8                           aucRsv[4];
}TAF_MMA_AC_INFO_QUERY_REQ_STRU;



typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                  ulMsgName;
    VOS_UINT32                                  ulRslt;                                 /* 结果 */
    AT_APPCTRL_STRU                             stAtAppCtrl;
    TAF_MMA_CELL_AC_INFO_STRU                   stCellCsAcInfo;                         /* 当前小区CS域的接入禁止信息 */
    TAF_MMA_CELL_AC_INFO_STRU                   stCellPsAcInfo;                         /* 当前小区ps域的接入禁止信息 */
}TAF_MMA_AC_INFO_QUERY_CNF_STRU;

/*****************************************************************************
 枚举名    : MN_PH_CSQLVLEXT_BER_VALUE_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : CSQLVLEXT命令BER参数值枚举列表，目前版本不支持BER参数查询，直接返回99
*****************************************************************************/
enum MN_PH_CSQLVLEXT_BER_VALUE_ENUM
{
    MN_PH_CSQLVLEXT_BER_VALUE_99        = 99,
    MN_PH_CSQLVLEXT_BER_VALUE_BUTT
};
typedef VOS_UINT8 MN_PH_CSQLVLEXT_BER_VALUE_ENUM_UINT8;


/*****************************************************************************
 枚举名    : MN_PH_CSQLVLEXT_RSSILV_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : CSQLVLEXT命令RSSILV信号格数参数枚举列表，
*****************************************************************************/
enum MN_PH_CSQLVLEXT_RSSILV_ENUM
{
    MN_PH_CSQLVLEXT_RSSILV_0,
    MN_PH_CSQLVLEXT_RSSILV_1,
    MN_PH_CSQLVLEXT_RSSILV_2,
    MN_PH_CSQLVLEXT_RSSILV_3,
    MN_PH_CSQLVLEXT_RSSILV_4,
    MN_PH_CSQLVLEXT_RSSILV_5,
    MN_PH_CSQLVLEXT_RSSILV_BUTT
};
typedef VOS_UINT8 MN_PH_CSQLVLEXT_RSSILV_ENUM_UINT8;

/*****************************************************************************
 枚举名    : MN_PH_CSQLVLEXT_RSSILV_VALUE_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : CSQLVLEXT命令RSSILV信号格数参数枚举列表，
*****************************************************************************/
enum MN_PH_CSQLVLEXT_RSSILV_VALUE_ENUM
{
    MN_PH_CSQLVLEXT_RSSILV_VALUE_0      = 0,
    MN_PH_CSQLVLEXT_RSSILV_VALUE_20     = 20,
    MN_PH_CSQLVLEXT_RSSILV_VALUE_40     = 40,
    MN_PH_CSQLVLEXT_RSSILV_VALUE_60     = 60,
    MN_PH_CSQLVLEXT_RSSILV_VALUE_80     = 80,
    MN_PH_CSQLVLEXT_RSSILV_VALUE_99     = 99,
    MN_PH_CSQLVLEXT_RSSILV_VALUE_BUTT
};
typedef VOS_UINT8 MN_PH_CSQLVLEXT_RSSILV_VALUE_ENUM_UINT8;


enum TAF_SYS_SUBMODE_ENUM
{
    TAF_SYS_SUBMODE_NONE                = 0,                /* 无服务 */
    TAF_SYS_SUBMODE_GSM                 = 1,                /* GSM模式 */
    TAF_SYS_SUBMODE_GPRS                = 2,                /* GPRS模式 */
    TAF_SYS_SUBMODE_EDGE                = 3,                /* EDGE模式 */
    TAF_SYS_SUBMODE_WCDMA               = 4,                /* WCDMA模式 */
    TAF_SYS_SUBMODE_HSDPA               = 5,                /* HSDPA模式 */
    TAF_SYS_SUBMODE_HSUPA               = 6,                /* HSUPA模式 */
    TAF_SYS_SUBMODE_HSDPA_HSUPA         = 7,                /* HSDPA+HSUPA模式 */
    TAF_SYS_SUBMODE_TD_SCDMA            = 8,                /* TD_SCDMA模式 */
    TAF_SYS_SUBMODE_HSPA_PLUS           = 9,                /* HSPA+模式 */
    TAF_SYS_SUBMODE_LTE                 = 10,               /* LTE模式 */
    TAF_SYS_SUBMODE_DC_HSPA_PLUS        = 17,               /* DC-HSPA+模式 */
    TAF_SYS_SUBMODE_DC_MIMO             = 18,               /* MIMO-HSPA+模式 */
    TAF_SYS_SUBMODE_BUTT
};
typedef VOS_UINT8  TAF_SYS_SUBMODE_ENUM_UINT8;

/*ucSysModeEx取值如下：*/
enum MN_PH_SYS_MODE_EX_ENUM
{
    MN_PH_SYS_MODE_EX_NONE_RAT  ,                                               /*无服务*/
    MN_PH_SYS_MODE_EX_GSM_RAT   ,                                               /*GSM模式*/
    MN_PH_SYS_MODE_EX_CDMA_RAT  ,                                               /*CDMA模式*/
    MN_PH_SYS_MODE_EX_WCDMA_RAT ,                                               /*WCDMA模式*/
    MN_PH_SYS_MODE_EX_TDCDMA_RAT,                                               /*TD-SCDMA模式*/
    MN_PH_SYS_MODE_EX_WIMAX_RAT ,                                               /*Wimax模式*/
    MN_PH_SYS_MODE_EX_LTE_RAT   ,                                               /*LTE模式*/
    MN_PH_SYS_MODE_EX_BUTT_RAT
};
typedef VOS_UINT8  MN_PH_SYS_MODE_EX_ENUM_U8;

/*ucSubSysModeEx取值如下：*/
enum MN_PH_SUB_SYS_MODE_EX_ENUM
{
    MN_PH_SUB_SYS_MODE_EX_NONE_RAT              ,                               /*无服务*/
    MN_PH_SUB_SYS_MODE_EX_GSM_RAT               ,                               /*GSM模式*/
    MN_PH_SUB_SYS_MODE_EX_GPRS_RAT              ,                               /*GPRS模式*/
    MN_PH_SUB_SYS_MODE_EX_EDGE_RAT              ,                               /*EDGE模式*/

    MN_PH_SUB_SYS_MODE_EX_IS95A_RAT     = 21    ,                               /*IS95A模式*/
    MN_PH_SUB_SYS_MODE_EX_IS95B_RAT             ,                               /*IS95B模式*/
    MN_PH_SUB_SYS_MODE_EX_CDMA20001X_RAT        ,                               /*CDMA20001X模式*/
    MN_PH_SUB_SYS_MODE_EX_EVDOREL0_RAT          ,                               /*EVDORel0模式*/
    MN_PH_SUB_SYS_MODE_EX_EVDORELA_RAT          ,                               /*EVDORelA模式*/
    MN_PH_SUB_SYS_MODE_EX_EVDORELB_RAT          ,                               /*EVDORelB模式*/
    MN_PH_SUB_SYS_MODE_EX_HYBIRD_CDMA20001X_RAT ,                               /*HYBIRD CDMA20001X模式*/
    MN_PH_SUB_SYS_MODE_EX_HYBIRD_EVDOREL0_RAT   ,                               /*HYBIRD EVDORel0模式*/
    MN_PH_SUB_SYS_MODE_EX_HYBIRD_EVDORELA_RAT   ,                               /*HYBIRD EVDORelA模式*/
    MN_PH_SUB_SYS_MODE_EX_HYBIRD_EVDORELB_RAT   ,                               /*HYBIRD EVDORelA模式*/

    MN_PH_SUB_SYS_MODE_EX_WCDMA_RAT     = 41    ,                               /*WCDMA模式*/
    MN_PH_SUB_SYS_MODE_EX_HSDPA_RAT     = 42    ,                               /*HSDPA模式*/
    MN_PH_SUB_SYS_MODE_EX_HSUPA_RAT     = 43    ,                               /*HSUPA模式*/
    MN_PH_SUB_SYS_MODE_EX_HSPA_RAT      = 44    ,                               /*HSPA模式*/
    MN_PH_SUB_SYS_MODE_EX_HSPA_PLUS_RAT = 45    ,                               /*HSPA+模式*/
    MN_PH_SUB_SYS_MODE_EX_DCHSPA_PLUS_RAT = 46  ,                               /*DCHSPA+模式*/

    MN_PH_SUB_SYS_MODE_EX_TDCDMA_RAT    = 61    ,                               /*TD-SCDMA模式*/

    MN_PH_SUB_SYS_MODE_EX_TD_HSDPA_RAT                      = 62,               /*HSDPA模式*/
    MN_PH_SUB_SYS_MODE_EX_TD_HSUPA_RAT                      = 63,               /*HSUPA模式*/
    MN_PH_SUB_SYS_MODE_EX_TD_HSPA_RAT                       = 64,               /*HSPA模式*/
    MN_PH_SUB_SYS_MODE_EX_TD_HSPA_PLUS_RAT                  = 65,               /*HSPA+模式*/

    MN_PH_SUB_SYS_MODE_EX_LTE_RAT       = 101   ,                               /*LTE模式*/
    MN_PH_SUB_SYS_MODE_EX_BUTT_RAT
};
typedef VOS_UINT8  MN_PH_SUB_SYS_MODE_EX_ENUM_U8;

/*****************************************************************************
 枚举名    : TAF_PH_ACCESS_TECH_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : 驻留网络的接入技术枚举，用于CREG/CGREG的ACT参数
*****************************************************************************/
enum TAF_PH_ACCESS_TECH_ENUM
{
    TAF_PH_ACCESS_TECH_GSM              = 0,                /* GSM */
    TAF_PH_ACCESS_TECH_GSM_COMPACT      = 1,                /* GSM Compact,不支持 */
    TAF_PH_ACCESS_TECH_UTRAN            = 2,                /* UTRAN */
    TAF_PH_ACCESS_TECH_EGPRS            = 3,                /* EGPRS */
    TAF_PH_ACCESS_TECH_HSDPA            = 4,                /* HSDPA */
    TAF_PH_ACCESS_TECH_HSUPA            = 5,                /* HSUPA */
    TAF_PH_ACCESS_TECH_HSDPA_HSUPA      = 6,                /* HSDPA+HSUPA */
    TAF_PH_ACCESS_TECH_E_UTRAN          = 7,                /* E-UTRAN*/
    TAF_PH_ACCESS_TECH_BUTT
};
typedef VOS_UINT8  TAF_PH_ACCESS_TECH_ENUM_UINT8;


/*****************************************************************************
 枚举名    : TAF_SIM_INSERT_STATE_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : 指示当前SIM卡的状态:插入或移除
*****************************************************************************/
enum TAF_SIM_INSERT_STATE_ENUM
{
    TAF_SIM_INSERT_STATE_REMOVE              = 0,                /* 移除 */
    TAF_SIM_INSERT_STATE_INSERT              = 1,                /* 插入 */
    TAF_SIM_INSERT_STATE_BUTT

};
typedef VOS_UINT32  TAF_SIM_INSERT_STATE_ENUM_UINT32;



enum TAF_MMA_PLMN_LIST_ABORT_PROC_ENUM
{
    TAF_MMA_PLMN_LIST_ABORT_PROCESSING_TIMEOUT                   = 0,           /* 正在处理定时器超时打断列表搜 */
    TAF_MMA_PLMN_LIST_ABORT_PROCESSING_USER_ABORT                = 1,           /* 正在处理用户打断列表搜 */
    TAF_MMA_PLMN_LIST_ABORT_BUTT
};
typedef VOS_UINT8  TAF_MMA_PLMN_LIST_ABORT_PROC_ENUM_UINT8;



enum TAF_MMA_ACQ_REASON_ENUM
{
    TAF_MMA_ACQ_REASON_POWER_UP         = 0,    /* 开机获取网络 */
    TAF_MMA_ACQ_REASON_OOS              = 1,    /* 出服务区获取网络 */
    TAF_MMA_ACQ_REASON_HIGH_PRIO        = 2,    /* 获取更高优先级网络 */
    TAF_MMA_ACQ_REASON_BUTT
};
typedef VOS_UINT8  TAF_MMA_ACQ_REASON_ENUM_UINT8;
enum TAF_MMA_EPS_ATTACH_REASON_ENUM
{
    TAF_MMA_ATTACH_REASON_INITIAL          = 0,    /* 非C->L重选时都填写该原因 */
    TAF_MMA_ATTACH_REASON_HANDOVER         = 1,    /* C->L重选时填写该原因 */
    TAF_MMA_ATTACH_REASON_BUTT
};
typedef VOS_UINT8 TAF_MMA_EPS_ATTACH_REASON_ENUM_UINT8;


enum TAF_MMA_PLMN_PRIORITY_CLASS_ENUM
{
    TAF_MMA_PLMN_PRIORITY_HOME               = 0,/* home or ehome plmn */
    TAF_MMA_PLMN_PRIORITY_PREF               = 1,/* UPLMN or OPLMN */
    TAF_MMA_PLMN_PRIORITY_ANY                = 2,/* Acceptable PLMN */
    TAF_MMA_PLMN_PRIORITY_BUTT
};
typedef VOS_UINT8 TAF_MMA_PLMN_PRIORITY_CLASS_ENUM_UINT8;
enum TAF_MMA_APP_OPER_RESULT_ENUM
{
    TAF_MMA_APP_OPER_RESULT_SUCCESS               = 0,/* 操作成功 */
    TAF_MMA_APP_OPER_RESULT_FAILURE               = 1,/*  操作失败 */
    TAF_MMA_APP_OPER_RESULT_ACQUIRED_FAIL         = 2,/* ACQ失败 */
    TAF_MMA_APP_OPER_RESULT_REJECT                = 3,/* 不允许进行该操作 */
    TAF_MMA_APP_OPER_RESULT_BUTT
};
typedef VOS_UINT32 TAF_MMA_APP_OPER_RESULT_ENUM_UINT32;


enum TAF_MMA_DETACH_CAUSE_ENUM
{
    TAF_MMA_DETACH_CAUSE_NORMAL               = 0,/* 正常Detach */
    TAF_MMA_DETACH_CAUSE_3GPP2_ATTACHED       = 1,/* 在3GPP2上附着成功 */
    TAF_MMA_DETACH_CAUSE_BUTT
};
typedef VOS_UINT8 TAF_MMA_DETACH_CAUSE_ENUM_UINT8;



enum TAF_MMA_VOICE_DOMAIN_ENUM
{
    TAF_MMA_VOICE_DOMAIN_CS_ONLY            = 0,    /* CS voice only */
    TAF_MMA_VOICE_DOMAIN_IMS_PS_ONLY        = 1,    /* IMS PS voice only */
    TAF_MMA_VOICE_DOMAIN_CS_PREFERRED       = 2,    /* CS vocie preferred, IMS PS voice as secondary */
    TAF_MMA_VOICE_DOMAIN_IMS_PS_PREFERRED   = 3,    /* IMS PS voice preferred, CS vocie as secondary */

    TAF_MMA_VOICE_DOMAIN_BUTT
};
typedef VOS_UINT8 TAF_MMA_VOICE_DOMAIN_ENUM_UINT32;


enum TAF_MMA_IMS_SWITCH_SET_ENUM
{
    TAF_MMA_IMS_SWITCH_SET_POWER_OFF            = 0,
    TAF_MMA_IMS_SWITCH_SET_POWER_ON             = 1,
    TAF_MMA_IMS_SWITCH_STATE_BUTT
};
typedef VOS_UINT8 TAF_MMA_IMS_SWITCH_SET_ENUM_UINT8;



#define  TAF_INVALID_TAB_INDEX          0
/*TAF各模块ID*/
#ifndef SUBMOD_NULL
#define  SUBMOD_NULL                    0
#endif
#define  TAF_CCA                        1
#define  TAF_APS                        2
#define  TAF_SMA                        3
#define  TAF_SSA                        4
#define  TAF_MMA                        5
#define  TAF_ALL_SUBMODULE              0xFF    /*所有子模块*/
#define  TAF_TAFM                       0



/* IMEI有效数据长度: IMEI信息由IMEI(TAC8位,SNR6位)和校验位两部分组成*/
#define TAF_IMEI_DATA_LENGTH            (15)

typedef struct
{
    TAF_UINT32    Mcc;
    TAF_UINT32    Mnc;
}TAF_PLMN_ID_STRU;
typedef struct
{
    TAF_PLMN_ID_STRU    stHplmn;
    VOS_UINT8           ucHplmnMncLen;
    VOS_UINT8           aucReserved[3];
}TAF_HPLMN_WITH_MNC_LEN_STRU;


#define TAF_PH_RELEASEDATE_LEN            10
typedef struct
{

    TAF_UINT8     aucReleaseDate[TAF_PH_RELEASEDATE_LEN+1];         /*发布日期*/
}TAF_PH_RELEASE_DATE_STRU;

#define TAF_PH_RELEASETIME_LEN             8
typedef struct
{

    TAF_UINT8     aucReleaseTime[TAF_PH_RELEASETIME_LEN+1];         /*发布时间*/
}TAF_PH_RELEASE_TIME_STRU;


#define TAF_PH_CAPLITYCLASS1               1
#define TAF_PH_CAPLITYCLASS2               4
#define TAF_PH_CAPLITYCLASS3              16
#define TAF_PH_COMPLETECAPILITYLIST_LEN   16
#define TAF_PH_CAPILITYLIST_TYPE           3
typedef struct
{
/*完整的功能列表*/
    TAF_UINT8       aucCompleteCapilityList[TAF_PH_CAPILITYLIST_TYPE][TAF_PH_COMPLETECAPILITYLIST_LEN];
}TAF_PH_COMPCAPLIST_STRU;

/*用于HS命令枚举*/
typedef enum
{
    TAF_PH_ONLINE,
    TAF_PH_OFFLINE,
    TAF_PH_MT_STA_BUTT
}TAF_PH_MT_STA_ENUM;


enum MN_MMA_CPAM_RAT_TYPE
{
    MN_MMA_CPAM_RAT_TYPE_WCDMA,          /* WCDMA单模**/
    MN_MMA_CPAM_RAT_TYPE_WCDMA_GSM,      /* WCDMA/GSM双模 */
    MN_MMA_CPAM_RAT_TYPE_GSM,            /* GSM单模 */
    MN_MMA_CPAM_RAT_TYPE_NOCHANGE,       /* 不改变*/
    MN_MMA_CPAM_RAT_TYPE_BUTT
};
typedef VOS_UINT8 MN_MMA_CPAM_RAT_TYPE_ENUM_UINT8;

#define  TAF_PHONE_ACCESS_MODE_LEN        (2)

/*Taf_USIM_RAT*/
typedef TAF_UINT16 TAF_MMC_USIM_RAT;
#define TAF_MMC_USIM_UTRN_RAT             0x8000
#define TAF_MMC_USIM_GSM_RAT              0x0080
#define TAF_MMC_USIM_UTRN_GSM_RAT         0x8080
#define TAF_MMC_USIM_GSM_COMPACT_RAT      0x0040
#define TAF_MMC_USIM_NO_RAT               0x0000
#define TAF_MMC_USIM_E_UTRN_RAT            0x4000
#define MMC_MS_LTE                          2

typedef TAF_UINT8 TAF_PHONE_SERVICE_STATUS;

typedef TAF_UINT8 TAF_PHONE_CHANGED_SERVICE_STATUS;                      /* 服务状态变化主动上报(^SRVST) */
#define TAF_REPORT_SRVSTA_NO_SERVICE                   0                        /* 无服务状态       */
#define TAF_REPORT_SRVSTA_LIMITED_SERVICE              1                        /* 限制服务状态     */
#define TAF_REPORT_SRVSTA_NORMAL_SERVICE               2                        /* 正常工作状态     */
#define TAF_REPORT_SRVSTA_REGIONAL_LIMITED_SERVICE     3                        /* 有限制的区域服务 */
#define TAF_REPORT_SRVSTA_DEEP_SLEEP                   4                        /* 省电和深睡眠状态 */

/* typedef TAF_UINT16 TAF_PHONE_ERROR; */

typedef struct
{
    TAF_PHONE_SERVICE_STATUS            CsSrvSta; /*CS服务状态*/
    TAF_PHONE_SERVICE_STATUS            PsSrvSta; /*PS服务状态*/
    VOS_UINT8                           aucReserved[2];
}TAF_PH_SRV_STA_STRU;

typedef TAF_UINT8 TAF_PH_PLMN_PRIO;
#define TAF_PLMN_PRIO_AUTO    0         /*自动选择网络*/
#define TAF_PLMN_GSM_PRIO     1         /*优选2G网络*/
#define TAF_PLMN_WCDMA_PRIO   2         /*优选3G网络*/
#define TAF_PLMN_PRIO_NOCHANGE  3

#define TAF_PLMN_PRIO_DIST_BTWN_CPAM_SYSCFG  1 /*CPAM与SYSCFG的接入优先级设置的差距 1 */

typedef TAF_UINT8 TAF_PH_MS_CLASS_TYPE;
#define TAF_PH_MS_CLASS_CC        0     /*只支持CS域手机对应于MMC的D_MMC_MODE_CC*/
#define TAF_PH_MS_CLASS_CG        1     /*只支持PS域手机对应于MMC的D_MMC_MODE_CG*/
#define TAF_PH_MS_CLASS_A         2

#define TAF_PH_MS_CLASS_ANY       3     /* 相当于只支持CS域 */

#define TAF_PH_MS_CLASS_NULL      5
#define TAF_PH_MS_CLASS_B         6     /*对应于GSM下B类手机*/

typedef TAF_UINT8 TAF_PH_SERVICE_DOMAIN;
#define  TAF_PH_SERVICE_CS       0       /*仅CS业务使能 */
#define  TAF_PH_SERVICE_PS       1       /*仅PS业务使能 */
#define  TAF_PH_SERVICE_CS_PS    2       /*PS、CS业务都使能 */
#define  TAF_PH_SERVICE_ANY      3       /* 等效于 PS_CS */
#define  TAF_PH_SERVICE_NOCHANGE 4       /*不改变服务域 */
#define  TAF_PH_SERVICE_NULL     5       /*PS、CS业务都没有使能*/


typedef TAF_UINT8 TAF_PH_IMSI_LOCK_STATUS;
#define TAF_PH_IMSI_LOCK_ENABLED             1
#define TAF_PH_IMSI_LOCK_DISABLED            0

/* 获取端口信息*/
#define TAF_MAX_PORT_INFO_LEN     100
typedef struct
{
    TAF_UINT8 aucPortInfo[TAF_MAX_PORT_INFO_LEN + 1];
    TAF_UINT8 aucRsv[3];
}TAF_PH_PORT_INFO_STRU;


/*****************************************************************************
 结构名    : TAF_PH_CREATION_TIME_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 系统编译时间
*****************************************************************************/
#define TAF_MAX_CREATION_TIME_LEN       31
typedef struct
{
    TAF_UINT8 aucCreationTime[TAF_MAX_CREATION_TIME_LEN + 1];
}TAF_PH_CREATION_TIME_STRU;

#define TAF_CFG_VERSION                 (1004)

/*+CGMR - 获取模块软件版本号*/
typedef struct
{
    TAF_UINT8 aucRevisionId[TAF_MAX_REVISION_ID_LEN + 1];
}TAF_PH_REVISION_ID_STRU;

/*****************************************************************************
 结构名    : TAF_PH_HW_VER_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 硬件名称
*****************************************************************************/
typedef struct
{
    TAF_UINT8 aucHwVer[TAF_MAX_HARDWARE_LEN+1];
}TAF_PH_HW_VER_STRU;

/*+CGMM - 获取模块标识*/
typedef struct
{
    TAF_UINT8 aucModelId[TAF_MAX_MODEL_ID_LEN + 1];
}TAF_PH_MODEL_ID_STRU;

/*****************************************************************************
 结构名    : TAF_PH_CDROM_VER_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 后台软件版本号
*****************************************************************************/


typedef struct
{
    TAF_UINT8 aucIsoInfo[TAF_CDROM_VERSION_LEN];
}TAF_PH_CDROM_VER_STRU;

/*+CGSN - 获取IMEI*/
typedef TAF_UINT8 TAF_PH_IMEI_TYPE;
#define TAF_PH_IMEI_LEN     16
#define TAF_PH_IMEIV_Mode   1
#define TAF_PH_IMEI_Mode    0

typedef struct
{
    TAF_PH_IMEI_TYPE                    ImeiMode;
    TAF_UINT8                           aucImei[TAF_PH_IMEI_LEN + 1];
    VOS_UINT8                           aucReserved[2];
}TAF_PH_IMEI_STRU;


 /*+CIMI - 获取IMSI*/
#define TAF_PH_IMSI_LEN     15
typedef struct
{
    TAF_UINT8  aucImsi[TAF_PH_IMSI_LEN + 1];
}TAF_PH_IMSI_STRU;



/*+CREG - 设置网络注册状态上报格式*/
#define TAF_PH_LAC_LENGTH       4
#define TAF_PH_CI_LENGTH        4
#define TAF_PH_RAC_LENGTH       2


/*注册状态*/
typedef TAF_UINT8 TAF_PH_REG_STATE_TYPE;
#define TAF_PH_REG_NOT_REGISTERED_NOT_SEARCH   0 /*没有注册，MS现在并没有在搜寻要注册的新的运营商*/
#define TAF_PH_REG_REGISTERED_HOME_NETWORK     1 /*注册了本地网络*/
#define TAF_PH_REG_NOT_REGISTERED_SEARCHING    2 /*没有注册，但MS正在搜寻要注册的新的运营商*/
#define TAF_PH_REG_REGISTERED_DENIED           3 /*注册被拒绝*/
#define TAF_PH_REG_UNKNOWN                     4 /*未知原因*/
#define TAF_PH_REG_REGISTERED_ROAM             5 /*注册了漫游网络*/

/*新增ATTACH、DETACH类型*/
typedef TAF_UINT8  TAF_PH_ATTACH_TYPE;
typedef TAF_UINT8  TAF_PH_DETACH_TYPE;
#define TAF_PH_ATTACH_DETACH_NULL           0
#define TAF_PH_PS_OPERATE                   1  /*发起PS操作*/
#define TAF_PH_CS_OPERATE                   2  /*发起CS操作*/
#define TAF_PH_PS_CS_OPERATE                3  /*发起PS与CS操作*/

typedef TAF_UINT8  TAF_PH_CS_STATUS;
typedef TAF_UINT8  TAF_PH_PS_STATUS;
#define TAF_PH_ATTACHED                       1
#define TAF_PH_DETACHED                       0
#define TAF_MMC_NORMAL_SERVICE                0

#define TAF_MMC_LIMITED_SERVICE                 (1)                             /* 限制服务 */
#define TAF_MMC_LIMITED_SERVICE_REGION          (2)                             /* 有限制区域服务 */
#define TAF_MMC_NO_IMSI                         (3)                             /* 无imsi */
#define TAF_MMC_NO_SERVICE                      (4)                             /* 无服务 */



/*操作模式设置命令+CFUN  */
typedef TAF_UINT8 TAF_PH_MODE;
#define TAF_PH_MODE_MINI                0   /* minimum functionality*/
#define TAF_PH_MODE_FULL                1   /* full functionality */
#define TAF_PH_MODE_TXOFF               2   /* disable phone transmit RF circuits only */
#define TAF_PH_MODE_RXOFF               3   /* disable phone receive RF circuits only */
#define TAF_PH_MODE_RFOFF               4   /* disable phone both transmit and receive RF circuits */
#define TAF_PH_MODE_FT                  5   /* factory-test functionality */
#define TAF_PH_MODE_RESET               6   /* reset */
#define TAF_PH_MODE_VDFMINI             7   /* mini mode required by VDF*/
#define TAF_PH_MODE_POWEROFF            8   /* 关机下电模式 */
#define TAF_PH_MODE_LOWPOWER            9
#define TAF_PH_MODE_NUM_MAX             10

typedef TAF_UINT8   TAF_PH_RESET_FLG;
#define TAF_PH_OP_MODE_UNRESET       0
#define TAF_PH_OP_MODE_RESET         1

typedef TAF_UINT8   TAF_PH_CMD_TYPE;
#define TAF_PH_CMD_SET                  0   /* set cmd */
#define TAF_PH_CMD_QUERY                1   /* query cmd */

typedef struct
{
     TAF_PH_CMD_TYPE                    CmdType; /* 命令类型 */
     TAF_PH_MODE                        PrePhMode;
     TAF_PH_MODE                        PhMode;  /* 模式 */
     TAF_PH_RESET_FLG                   PhReset; /* 是否需要重启 */
}TAF_PH_OP_MODE_STRU;
typedef struct
{
     TAF_PH_CMD_TYPE                    CmdType; /* 命令类型 */
     TAF_PH_MODE                        PhMode;  /* 模式 */
     VOS_UINT8                          aucReserved[2];
}TAF_PH_OP_MODE_CNF_STRU;
typedef struct
{
    VOS_INT16                       sRscpValue;  /* 小区信号质量用于3g下^cerssi上报使用*/
    VOS_INT16                       sEcioValue;  /* 小区信噪比用于3g下^cerssi上报使用*/
} TAF_MMA_W_CELL_SIGN_INFO_STRU;


typedef struct
{
    VOS_INT16                       sRssiValue;   /* 小区信号质量用于2g下^cerssi上报使用,2g没有rscp的概念用的是rssi */
    VOS_UINT8                       aucReserve1[2];
} TAF_MMA_G_CELL_SIGN_INFO_STRU;



/*RSSI查询功能命令+CSQ*/
/*
  0       等于0或小于 -113 dBm
  1                -111 dBm
  2...30           -109...  -53 dBm
  31     等于或大于 -51 dBm
  99     未知或不可测。
*/
#define TAF_PH_RSSIUNKNOW        99
#define TAF_PH_RSSIZERO          0

typedef struct
{
    TAF_UINT8        ucRssiValue;       /*已转换为等级表示的信号强度*/
    TAF_UINT8        ucChannalQual;     /*误码率,只有在有业务的时候才有,若无
                                          效填99*/
    VOS_UINT8       aucReserved1[2];

    union
    {
        TAF_MMA_W_CELL_SIGN_INFO_STRU   stWCellSignInfo;
        TAF_MMA_G_CELL_SIGN_INFO_STRU   stGCellSignInfo;
    }u;


}TAF_PH_RSSI_VALUE_STRU;

#define TAF_PH_RSSI_MAX_NUM         8

typedef struct
{
    TAF_UINT8                           ucRssiNum;                    /*上报信号强度小区的个数*/

    TAF_PH_RAT_TYPE_ENUM_UINT8          enRatType;                    /* 接入模式0:G;1:W */
    VOS_UINT8                           ucCurrentUtranMode;
    VOS_UINT8                           aucReserv1;

    VOS_UINT16                          usCellDlFreq;                           /*小区频点(下行)*/
    VOS_UINT16                          usCellUlFreq;                           /*当前频点(上行)*/
    VOS_INT16                           sUeRfPower;                             /*发射功率*/
    VOS_UINT8                           aucReserved[2];

    TAF_PH_RSSI_VALUE_STRU              aRssi[TAF_PH_RSSI_MAX_NUM];   /*每个小区的信号强度与误码率*/
}TAF_PH_RSSI_STRU;

typedef struct
{
    TAF_INT32                           lRscpValue;
    TAF_INT32                           lEcioValue;
    TAF_UINT8                           ucRssiValue;       /*已转换为等级表示的信号强度*/
    TAF_UINT8                           ucAnlevelValue;
    TAF_UINT8                           ucChannalQual;     /*误码率,只有在有业务的时候才有,若无效填99*/
    VOS_UINT8                           aucReserved[1];
}TAF_PH_ANLEVEL_VALUE_STRU;

#define TAF_PH_ANLEVEL_MAX_NUM         8

typedef struct
{
    TAF_UINT8                           ucAnlevelNum;                    /*上报信号强度小区的个数*/
    VOS_UINT8                           aucReserved[3];
    TAF_PH_ANLEVEL_VALUE_STRU           aAnlevel[TAF_PH_ANLEVEL_MAX_NUM];   /*每个小区的信号强度与误码率*/
}TAF_PH_ANLEVEL_STRU;

#define TAF_UE_RFPOWER_INVALID      0x1fff
#define TAF_FREQ_INVALID            0xffff
typedef struct
{
    TAF_UINT32                          CellId;
    TAF_INT16                           CellRSCP;
    VOS_UINT8                           aucReserved[2];
} TAF_PH_CELL_RSCP_ST;

typedef struct
{
    TAF_UINT16                          CellNum;
    VOS_UINT8                           aucReserved1[2];
    TAF_PH_CELL_RSCP_ST                 CellRscp[TAF_PH_RSSI_MAX_NUM];
    TAF_UINT16                          CellDlFreq;       /*小区频点(下行)*/
    VOS_UINT8                           aucReserved2[2];
} TAF_PH_CELL_RSSI_STRU;

typedef struct
{
    TAF_UINT16              CellUlFreq;       /*当前频点(上行)*/
    TAF_INT16               UeRfPower;        /*发射功率*/
} TAF_PH_UE_RFPOWER_FREQ_STRU;

/*当前电池电量+CBC*/
 /*
 状态类型：
 0 电池正在供电
 1 与电池连接，但是电池未供电
 2 没有与电池连接
 3 电源故障, 通话禁止
*/
#define TAF_PH_BATTERYCHARGING             0
#define TAF_PH_BATTERYNOSUPPLY             1
#define TAF_PH_NOBATTERYFIXED              2
#define TAF_PH_POWERSOURCEERROR            3
typedef TAF_UINT8 TAF_PH_BATTERYPOWER_STA;

/*
0电源不足或没有与电池连接
1...100 目前剩余电量，百分比
*/
typedef TAF_UINT8 TAF_PH_BATTERY_REMAINS;
typedef struct
{
   TAF_PH_BATTERYPOWER_STA              BatteryPowerStatus;
   TAF_PH_BATTERY_REMAINS               BatteryRemains;
   VOS_UINT8                            aucReserved[2];
}TAF_PH_BATTERYPOWER_STRU;


typedef TAF_UINT8 TAF_ME_PERSONALISATION_CMD_TYPE;
#define TAF_ME_PERSONALISATION_SET             0x01   /*移动设备私有特性设置*/
#define TAF_ME_PERSONALISATION_VERIFY          0x02   /*移动设备私有密码校验*/
#define TAF_ME_PERSONALISATION_PWD_CHANGE      0x03   /*更换移动设备私有密码*/
#define TAF_ME_PERSONALISATION_ACTIVE          0x04   /*激活移动设备私有功能*/
#define TAF_ME_PERSONALISATION_DEACTIVE        0x05   /*去激活移动设备私有功能*/
#define TAF_ME_PERSONALISATION_RETRIEVE        0x06   /*获取当前移动设备私有特性列表*/
#define TAF_ME_PERSONALISATION_QUERY           0x07   /*查询当前移动设备私有特性状态*/

/*当前只支持对锁卡的操作*/
typedef TAF_UINT8 TAF_ME_PERSONALISATION_TYPE;
#define TAF_SIM_PERSONALISATION                 0x01   /*锁卡*/
#define TAF_NETWORK_PERSONALISATION             0x02   /*锁网络*/
#define TAF_NETWORK_SUBSET_PERSONALISATION      0x03   /*锁网络子集*/
#define TAF_SERVICE_PROVIDE_PERSONALISATION     0x04   /*锁业务供应商*/
#define TAF_CORPORATE_PERSONALISATION           0x05   /*锁公司**/
#define TAF_OPERATOR_PERSONALISATION            0x06   /*自定义:锁网络,按照终端需求实现 */

/*定义当前锁卡状态*/
typedef TAF_UINT8 TAF_ME_PERSONALISATION_STATUS_FLAG;
#define TAF_ME_PERSONALISATION_ACTIVE_STATUS       0
#define TAF_ME_PERSONALISATION_DEACTIVE_STATUS     1

/*自定义:定义当前锁运营商激活状态 */
#define TAF_OPERATOR_LOCK_STATUS_NOT_UNLOCK        TAF_ME_PERSONALISATION_ACTIVE_STATUS
#define TAF_OPERATOR_LOCK_STATUS_UNLOCKED          TAF_ME_PERSONALISATION_DEACTIVE_STATUS

/* 上报的锁运营商状态*/
typedef enum
{
    TAF_OPERATOR_LOCK_NEED_UNLOCK_CODE             = 1,/* 需要输入解锁码 */
    TAF_OPERATOR_LOCK_NONEED_UNLOCK_CODE           = 2,/* 不需要输入解锁码 */
    TAF_OPERATOR_LOCK_LOCKED                       = 3,/* 处于锁定状态 */
    TAF_OPERATOR_LOCK_BUTT
}TAF_OPERATOR_LOCK_STATUS_ENUM;
typedef TAF_UINT32 TAF_OPERATOR_LOCK_STATUS_ENUM_U32;

#define TAF_OPERATOR_UNLOCK_TIMES_MAX                   10  /* 运营商锁解锁次数最大值 */
#define TAF_OPERATOR_UNLOCK_TIMES_MIN                   0   /* 运营商锁解锁次数最小值 */
#define TAF_PH_ME_LOCK_OPER_LEN_MAX                     15  /* 运营商锁提供服务运营商名最大长度 */
#define TAF_PH_ME_LOCK_OPER_LEN_MIN                     5   /* 运营商锁提供服务运营商名最小长度 */

typedef struct
{
    TAF_UINT32                          RemainTimes;
    TAF_OPERATOR_LOCK_STATUS_ENUM_U32   OperatorLockStatus;
    TAF_UINT8                           OperatorLen;
    TAF_UINT8                           Operator[TAF_PH_ME_LOCK_OPER_LEN_MAX];
}TAF_OPERATOR_LOCK_INFO_STRU;

#define TAF_MAX_IMSI_LEN                        15
typedef struct
{
    TAF_UINT8   DataLen;
    TAF_UINT8   aucSimPersonalisationStr[TAF_MAX_IMSI_LEN];       /* 设定锁卡的内容   */
}TAF_SIM_PERSIONALISATION_STR_STRU;

typedef union
{
    /*锁卡字串,CmdType为TAF_ME_PERSONALISATION_RETRIEVE，MePersonalType为TAF_SIM_PERSONALISATION时有效*/
    TAF_SIM_PERSIONALISATION_STR_STRU  SimPersionalisationStr;
}TAF_ME_PERSONALISATION_SET_UN;

typedef union
{
    /*锁卡字串,CmdType为TAF_ME_PERSONALISATION_RETRIEVE，MePersonalType为TAF_SIM_PERSONALISATION时有效*/
    TAF_SIM_PERSIONALISATION_STR_STRU  SimPersionalisationStr;

    /*运营商锁信息,CmdType为TAF_ME_PERSONALISATION_QUERY，MePersonalType为TAF_OPERATOR_PERSONALISATION时有效*/
    TAF_OPERATOR_LOCK_INFO_STRU        OperatorLockInfo;
}TAF_ME_PERSONALISATION_REPORT_CONTENT_UN;

#define TAF_PH_ME_PERSONALISATION_PWD_LEN_MAX   8
typedef struct
{
    TAF_ME_PERSONALISATION_CMD_TYPE     CmdType;
    TAF_ME_PERSONALISATION_TYPE         MePersonalType;
    TAF_UINT8                           aucOldPwd[TAF_PH_ME_PERSONALISATION_PWD_LEN_MAX +1];
    TAF_UINT8                           aucNewPwd[TAF_PH_ME_PERSONALISATION_PWD_LEN_MAX +1];
    TAF_ME_PERSONALISATION_SET_UN       unMePersonalisationSet;
}TAF_ME_PERSONALISATION_DATA_STRU;

typedef TAF_UINT8   TAF_OP_ME_PERSONALISATION_RESULT;
#define TAF_PH_ME_PERSONALISATION_OK                    0
#define TAF_PH_ME_PERSONALISATION_IMST_STR_NOT_EXIST    1
#define TAF_PH_ME_PERSONALISATION_ERROR                 2
#define TAF_PH_ME_PERSONALISATION_WRONG_PARA            3
#define TAF_PH_ME_PERSONALISATION_WRONG_PWD             4
#define TAF_PH_ME_PERSONALISATION_LOCK_PHONE_TO_SIM     5
#define TAF_PH_ME_PERSONALISATION_NO_SIM                6
#define TAF_PH_ME_PERSONALISATION_OP_NOT_ALLOW          7

#define TAF_PH_CARDLOCK_DEFAULT_MAXTIME    10

typedef struct
{
    TAF_OP_ME_PERSONALISATION_RESULT                    OpRslt;                 /*移动设备私有操作结果*/
    TAF_ME_PERSONALISATION_CMD_TYPE                     CmdType;                /*移动设备私有操作命令类型*/
    TAF_ME_PERSONALISATION_STATUS_FLAG                  ActiveStatus;           /*移动设备私有操作激活状态 */
    TAF_ME_PERSONALISATION_TYPE                         MePersonalisatonType;   /*移动设备私有类型*/
    TAF_ME_PERSONALISATION_REPORT_CONTENT_UN            unReportContent;        /*移动设备私有操作上报参数*/
}TAF_PH_ME_PERSONLISATION_CNF_STRU;


typedef struct
{
    TAF_UINT8                           ucLen;
    TAF_UINT8                           ucSW1;
    TAF_UINT8                           ucSW2;
    VOS_UINT8                           aucReserved[1];
    TAF_UINT8                           aucContent[USIMM_T0_APDU_MAX_LEN];
} TAF_PH_RESTRICTED_ACCESS_CNF_STRU;
/*PIN码管理与类型+CPIN,+CPWD,+CLCK*/
/*
底层API提供的函数调用的数据结构
TAF_UINT8 ucCmdType, TAF_UINT8 ucPINType, TAF_UINT8 *pucOldPIN, TAF_UINT8 *pucNewPIN
*/

#define TAF_PH_PINCODELENMAX     8
#define TAF_PH_PINCODELENMIN     4
#define TAF_PH_UNLOCKCODELEN     16

#define TAF_SIM_PIN              0      /*PIN1*/
#define TAF_SIM_PUK              1      /*PUK1*/
#define TAF_SIM_PIN2             6      /*PIN2*/
#define TAF_SIM_PUK2             7      /*PUK2*/
#define TAF_PHSIM_PIN            8      /*PH-SIM PIN*/
#define TAF_PHNET_PIN            9      /*PH-NET PIN*/
#define TAF_PHNET_PUK            10     /*PH-NET PUK*/
#define TAF_PHNETSUB_PIN         11     /*PH-NETSUB PIN*/
#define TAF_PHNETSUB_PUK         12     /*PH-NETSUB PUK*/
#define TAF_PHSP_PIN             13     /*PH-SP PIN*/
#define TAF_PHSP_PUK             14     /*PH-SP PUK*/
#define TAF_SIM_NON              255    /*不确定操作PIN的类型时填入此值*/
typedef TAF_UINT8 TAF_PH_PIN_TYPE;


typedef TAF_UINT8 TAF_PH_PIN_CMD_TYPE;
#define TAF_PIN_VERIFY          0x20   /*校验PIN码*/
#define TAF_PIN_CHANGE          0x24   /*更换PIN码的密码*/
#define TAF_PIN_DISABLE         0x26   /*禁止使用PIN码*/
#define TAF_PIN_ENABLE          0x28   /*使用PIN码*/
#define TAF_PIN_UNBLOCK         0x2c   /*解除阻止PIN码*/

/*新增PIN码查询功能*/
#define TAF_PIN_QUERY           0x30   /*查询PIN码状态*/
#define TAF_PIN_RemainTime      0x31
#define TAF_PIN2_QUERY          0x32   /*查询PIN2码状态*/
#define TAF_PIN_CMD_NULL        0x00

typedef struct
{
    TAF_PH_PIN_CMD_TYPE               CmdType;
    TAF_PH_PIN_TYPE                   PinType;
    TAF_UINT8                         aucOldPin[TAF_PH_PINCODELENMAX +1];
    TAF_UINT8                         aucNewPin[TAF_PH_PINCODELENMAX +1];
}TAF_PH_PIN_DATA_STRU;


/*当为查询时,PIN返回的结果所需要的结构体*/
typedef TAF_UINT8 TAF_PH_USIMM_NEED_TYPE;

#define TAF_PH_USIMM_NONEED     0   /*不需要验证*/
#define TAF_PH_USIMM_NEED       1   /*需要验证*/
#define TAF_PH_USIMM_PUK        2   /* need verifer puk */
#define TAF_PH_USIMM_ADM        3   /* puk block */

typedef TAF_UINT8 TAF_PH_USIMM_ENABLE_FLG;
#define TAF_PH_USIMM_ENABLE     1   /*已经使能*/
#define TAF_PH_USIMM_UNENABLE   0   /*未使能*/

/*查询USIM状态API返回情况*/
/*查询或操作PIN结果*/
typedef TAF_UINT8   TAF_OP_PIN_RESULT;
#define TAF_PH_OP_PIN_OK    0
#define TAF_PH_PIN_ERROR                    1
#define TAF_PH_QUERY_USIMM_WRONG_PARA       2
#define TAF_PH_QUERY_USIMM_NOAPP            3
#define TAF_PH_QUERY_USIMM_NOINITIAL        4
#define TAF_PH_QUERY_USIMM_ALLOCMEM_FAILED  5
#define TAF_PH_QUERY_USIMM_SENDMSG_FAILED   6
#define TAF_PH_OP_PIN_NEED_PIN1             7
#define TAF_PH_OP_PIN_NEED_PUK1             8
#define TAF_PH_OP_PIN_NEED_PIN2             9
#define TAF_PH_OP_PIN_NEED_PUK2             10
#define TAF_PH_OP_PIN_INCORRECT_PASSWORD    11
#define TAF_PH_OP_PIN_OPERATION_NOT_ALLOW   12
#define TAF_PH_OP_PIN_SIM_FAIL              13


typedef struct
{
    TAF_PH_USIMM_NEED_TYPE              UsimmNeedType;
    TAF_PH_USIMM_ENABLE_FLG             UsimmEnableFlg;
    VOS_UINT8                           aucReserved[2];
}TAF_PH_PIN_QUERY_CNF_STRU;

typedef struct
{
    TAF_UINT8                   ucResult;
}TAF_PH_PIN_OPERATION_CNF_STRU;

typedef struct
{
    TAF_UINT8 ucPin1RemainTime;    /* PIN1码剩余次数 */
    TAF_UINT8 ucPin2RemainTime;    /* PIN2码剩余次数 */
    TAF_UINT8 ucPuk1RemainTime;    /* PUK1码剩余次数 */
    TAF_UINT8 ucPuk2RemainTime;    /* PUK2码剩余次数 */
}TAF_PH_PIN_REMAIN;
/*当参数未初始化是，为255*/
#define MMA_PIN_REMAINS_UNINIT             255

typedef struct
{
    TAF_OP_PIN_RESULT               OpPinResult;  /*PIN动作的结果*/
    TAF_PH_PIN_CMD_TYPE             CmdType;      /*对PIN的动作类型*/
    TAF_PH_PIN_TYPE                 PinType;      /*查询或操作PIN类型*/
    TAF_UINT8                       ucRemain;     /*对PIN操作剩余次数*/
    TAF_PH_PIN_QUERY_CNF_STRU       QueryResult;  /*查询PIN返回结果*/
    TAF_PH_PIN_REMAIN               RemainTime;   /*所有PIN码的剩余次数*/
}TAF_PH_PIN_CNF_STRU;

typedef struct
{
    TAF_OP_PIN_RESULT                   OpPinResult;  /*PIN动作的结果*/
    TAF_PH_PIN_CMD_TYPE                 CmdType;      /*对PIN的动作类型*/
    TAF_PH_PIN_TYPE                     PinType;              /*查询或操作PIN类型*/
    TAF_UINT8                           ucPIN1Remain;     /*对PIN操作剩余次数*/
    TAF_UINT8                           ucPUK1Remain;
    TAF_UINT8                           ucPIN2Remain;
    TAF_UINT8                           ucPUK2Remain;
    VOS_UINT8                           aucReserved2[1];
    TAF_PH_PIN_QUERY_CNF_STRU           QueryResult;  /*查询PIN返回结果*/
}TAF_PH_PIN_TIMECNF_STRU;


typedef TAF_UINT32   TAF_FPLMN_OPERATE_TYPE;
#define TAF_PH_FPLMN_QUREY      0
#define TAF_PH_FPLMN_DEL_ALL    1
#define TAF_PH_FPLMN_DEL_ONE    2
#define TAF_PH_FPLMN_ADD_ONE    3

typedef struct
{
    TAF_FPLMN_OPERATE_TYPE  ulCmdType;
    TAF_PLMN_ID_STRU        stPlmn;
}TAF_PH_FPLMN_OPERATE_STRU;

/*
USIM状态结构体
AT暂时未从MMA获取USIM状态，
但MMA本身也需要USIM状态
*/
/*
0：     USIM卡状态无效
1:      USIM卡状态有效
2：     USIM在CS下无效
3：     USIM在PS下无效
4：     USIM在PS+CS下均无效
255：   USIM卡不存在
*/
typedef TAF_UINT8 TAF_USIM_STATUS;
#define TAF_PH_USIM_STATUS_UNAVAIL         0
#define TAF_PH_USIM_STATUS_AVAIL           1


#define TAF_PH_USIM_STATUS_CS_UNVAIL      2
#define TAF_PH_USIM_STATUS_PS_UNVAIL      3
#define TAF_PH_USIM_STATUS_CSPS_UNVAIL    4

#define TAF_PH_USIM_ROMSIM                240
#define TAF_PH_USIM_NON                   255
typedef struct
{
    VOS_UINT8                           aucImsi[NAS_MAX_IMSI_LENGTH];
    VOS_UINT8                           aucReserve[3];
}TAF_USIM_STATUS_ST;


/*获取运营商信息，由华三AT命令（＋COPS）*/
typedef TAF_UINT8 TAF_PH_NETWORKNAME_FORMAT;
#define TAF_PH_NETWORKNAME_LONG          0
#define TAF_PH_NETWORKNAME_SHORT         1
#define TAF_PH_NETWORKNAME_NUMBER        2
#define TAF_PH_NETWORKNAME_ALL           4
/*
当前注册网络状态标识
  0:未知的
  1:可用的
  2:当前注册
  3:禁止
*/
typedef TAF_UINT8 TAF_PH_NETWORK_STATUS_FLAG;
#define TAF_PH_NETWORK_STATUS_UNKNOW       0
#define TAF_PH_NETWORK_STATUS_AVAILIBLE    1
#define TAF_PH_NETWORK_STATUS_CURRENT      2
#define TAF_PH_NETWORK_STATUS_FORBIDDEN    3


typedef TAF_UINT8 TAF_PH_RA_MODE;           /*接入模式*/
#define TAF_PH_RA_GSM                      0
#define TAF_PH_RA_WCDMA                    1
#define TAF_PH_RA_LTE                      2
#define TAF_PH_RA_MODE_DEFAULT             3
#define TAF_NAMELENGTH_MAX                 32

/* STK功能 Access Technology Change Event 相关宏定义 */
#define TAF_STK_ACC_TECH_GSM               0
#define TAF_STK_ACC_TECH_TIA_EIA_553       1
#define TAF_STK_ACC_TECH_TIA_EIA_136       2
#define TAF_STK_ACC_TECH_UTRAN             3
#define TAF_STK_ACC_TECH_TETRA             4
#define TAF_STK_ACC_TECH_TIA_EIA_95        5
#define TAF_STK_ACC_TECH_TIA_EIA_IS_2000   6

/* NV项是否激活指示 */
#define NV_ITEM_DEACTIVE           0
#define NV_ITEM_ACTIVE             1



/*获取完整的PLMN列表并上报*/
#define TAF_PH_OPER_NAME_LONG                   40
#define TAF_PH_OPER_NAME_SHORT                  36
#define TAF_PH_PLMN_LIST_MAX                    32
/*#define TAF_PH_OPER_NAME_PLMN_ID_LENGTH         8*/
#define TAF_PH_STORED_OPER_NAME_NUM_IN_NVIM     3
typedef struct
{
    TAF_PLMN_ID_STRU            PlmnId;
    TAF_CHAR                    aucOperatorNameShort[TAF_PH_OPER_NAME_SHORT ];
    TAF_CHAR                    aucOperatorNameLong[TAF_PH_OPER_NAME_LONG ];
}TAF_PH_OPERATOR_NAME_STRU;


typedef TAF_UINT8    TAF_PH_GET_OPERATOR_INFO_OP;
#define TAF_PH_OPER_NAME_PLMN2ALPHANUMERICNAME         0
#define TAF_PH_OPER_NAME_SHORTNAME2OTHERS              1
#define TAF_PH_OPER_NAME_LONGNAME2OTERS                2
#define TAF_PH_OPER_NAME_ERROROP                       3

typedef struct
{
    TAF_PH_OPERATOR_NAME_STRU           OperName;
    TAF_PH_GET_OPERATOR_INFO_OP         ListOp;
    VOS_UINT8                           aucReserved[3];
}TAF_PH_OPERATOR_NAME_FORMAT_OP_STRU;

typedef TAF_UINT8 TAF_PH_PLMN_SEL_MODE;               /*PLMN selection mode     */
#define TAF_PH_PLMN_SEL_MODE_AUTO                   0   /*automatic selection mode*/
#define TAF_PH_PLMN_SEL_MODE_MANUAL                 1   /*manual selection mode   */
#define TAF_PH_PLMN_SEL_MODE_BUTT                   (0xFF)


typedef struct
{
    TAF_PH_OPERATOR_NAME_STRU       Name;
    TAF_PH_NETWORKNAME_FORMAT       NameFormat;  /*网络运营商名字格式*/
    TAF_PH_RA_MODE                  RaMode;      /*无线接入模式,3G/2G*/
    TAF_PH_PLMN_SEL_MODE            PlmnSelMode; /*PLMN selection mode*/
    VOS_UINT8                       aucReserved[1];
}TAF_PH_NETWORKNAME_STRU;

typedef struct
{
    TAF_PH_NETWORK_STATUS_FLAG   Status;
    VOS_UINT8                    aucReserved1[3];
    TAF_PLMN_ID_STRU             Plmn;
    TAF_PH_RA_MODE               RaMode;
    VOS_UINT8                    aucReserved2[3];
}TAF_PLMN_INFO_STRU;

/*上报当前小区所有PLMN列表与状态*/
typedef struct
{
    TAF_UINT8                    ucOperatorNums;
    VOS_UINT8                    aucReserved2[3];
    TAF_PH_OPERATOR_NAME_STRU    aOperatorInfo[TAF_PH_PLMN_LIST_MAX];
}TAF_PH_OPERATORS_INFO_LIST_STRU;

/*获取band值，从MS的RACIEZ中获得*/

typedef struct
{
    TAF_UINT32 ulBandLow; /*低32位*/
    TAF_UINT32 ulBandHigh;/*高32位*/
} TAF_USER_SET_PREF_BAND64;

typedef TAF_UINT32 TAF_PH_PREF_BAND;

#define TAF_PH_BAND_GSM_DCS_1800                             0x00000080
#define TAF_PH_BAND_GSM_EGSM_900                             0x00000100
#define TAF_PH_BAND_GSM_PGSM_900                             0x00000200
#define TAF_PH_BAND_WCDMA_VII_2600                           0x00010000
#define TAF_PH_BAND_WCDMA_VIII_900                           0x00020000
#define TAF_PH_BAND_WCDMA_IX_1700                            0x00040000
#define TAF_PH_BAND_GSM_850                                  0x00080000
#define TAF_PH_BAND_GSM_RGSM_900                             0x00100000
#define TAF_PH_BAND_GSM_PCS_1900                             0x00200000
#define TAF_PH_BAND_WCDMA_I_IMT_2100                         0x00400000
#define TAF_PH_BAND_WCDMA_II_PCS_1900                        0x00800000
#define TAF_PH_BAND_WCDMA_III_1800                           0x01000000
#define TAF_PH_BAND_WCDMA_IV_1700                            0x02000000
#define TAF_PH_BAND_WCDMA_V_850                              0x04000000
#define TAF_PH_BAND_WCDMA_VI_800                             0x08000000
#define TAF_PH_BAND_WCDMA_XI_1500                            0x20000000
/* 增加对BAND19的支持 */
#define TAF_PH_BAND_WCDMA_XIX_850                            0x10000000
#define TAF_PH_BAND_ANY                                      0x3FFFFFFF
#define TAF_PH_BAND_NO_CHANGE                                0x40000000

#define MN_MMA_LTE_HIGH_BAND_ANY        (0x7FFFFFFF)
#define MN_MMA_LTE_LOW_BAND_ANY         (0xFFFFFFFF)
#define MN_MMA_LTE_EUTRAN_BAND1         (0x1)
#define MN_MMA_LTE_EUTRAN_BAND7         (0x40)
#define MN_MMA_LTE_EUTRAN_BAND13        (0x1000)
#define MN_MMA_LTE_EUTRAN_BAND17        (0x10000)
#define MN_MMA_LTE_EUTRAN_BAND40        (0x80)

#define MN_MMA_LTE_LOW_BAND_ALL         (MN_MMA_LTE_EUTRAN_BAND1 | MN_MMA_LTE_EUTRAN_BAND7 \
                                         | MN_MMA_LTE_EUTRAN_BAND13 | MN_MMA_LTE_EUTRAN_BAND17)

#define MN_MMA_LTE_HIGH_BAND_ALL        (MN_MMA_LTE_EUTRAN_BAND40)


/* 增加BAND6,BAND19的支持 */
#define TAF_PH_BAND_WCDMA_BAND_ALL           ( TAF_PH_BAND_WCDMA_I_IMT_2100 \
                                              | TAF_PH_BAND_WCDMA_II_PCS_1900 | TAF_PH_BAND_WCDMA_IV_1700 \
                                              | TAF_PH_BAND_WCDMA_V_850 | TAF_PH_BAND_WCDMA_VI_800 \
                                              | TAF_PH_BAND_WCDMA_VIII_900 | TAF_PH_BAND_WCDMA_XI_1500 \
                                              | TAF_PH_BAND_WCDMA_XIX_850)
#define TAF_PH_BAND_GSM_BAND_ALL             ( TAF_PH_BAND_GSM_DCS_1800  | TAF_PH_BAND_GSM_EGSM_900  \
                                               |TAF_PH_BAND_GSM_PGSM_900 | TAF_PH_BAND_GSM_850       \
                                               | TAF_PH_BAND_GSM_PCS_1900 )

#define TAF_PH_BAND_ALL                       (TAF_PH_BAND_WCDMA_BAND_ALL | TAF_PH_BAND_GSM_BAND_ALL)



/*用于返回SYSCFG=?的频段分组1的范围*/

#define TAF_PH_BAND_GSM_900   ( TAF_PH_BAND_GSM_EGSM_900 | TAF_PH_BAND_GSM_PGSM_900 )

/* 增加对BAND19的支持 */
#define TAF_PH_BAND_GROUP1_FOR_SYSCFG    ( TAF_PH_BAND_WCDMA_I_IMT_2100 | TAF_PH_BAND_WCDMA_VIII_900 \
                                          | TAF_PH_BAND_WCDMA_IX_1700 | TAF_PH_BAND_WCDMA_VI_800     \
                                          | TAF_PH_BAND_GSM_DCS_1800 | TAF_PH_BAND_GSM_EGSM_900      \
                                          | TAF_PH_BAND_GSM_PGSM_900 | TAF_PH_BAND_WCDMA_XI_1500     \
                                          | TAF_PH_BAND_WCDMA_XIX_850 )
/*用于返回SYSCFG=?的频段分组2的范围*/
#define TAF_PH_BAND_GROUP2_FOR_SYSCFG    ( TAF_PH_BAND_WCDMA_II_PCS_1900  \
                                          | TAF_PH_BAND_WCDMA_IV_1700 | TAF_PH_BAND_WCDMA_V_850 \
                                          | TAF_PH_BAND_GSM_PCS_1900 | TAF_PH_BAND_GSM_850 )

/* 需要做64位和32位转换的频段 */
#define TAF_PH_BAND_NEED_CHANGE_TO_64BIT    ( TAF_PH_BAND_WCDMA_VIII_900 | TAF_PH_BAND_WCDMA_IX_1700 | TAF_PH_BAND_WCDMA_XI_1500 | TAF_PH_BAND_WCDMA_XIX_850)

typedef struct
{
     TAF_PH_PREF_BAND                             BandMask;             /*频带设置*/
     TAF_CHAR*                                    BandStr;              /*频带字符串*/
}TAF_PH_BAND_NAME_STRU;

#define TAF_DEVICE_AT_MAX_W_BAND_NUM   9  /*当前用户可设置的W频段范围号*/

/*漫游支持选项0，1不使用，只使用未变化即2，*/
typedef TAF_UINT8 TAF_PH_ROAM_MODE;
#define TAF_PH_ROAM_NATIONAL_ON_INTERNATIONAL_ON        0
#define TAF_PH_ROAM_NATIONAL_ON_INTERNATIONAL_OFF       1
#define TAF_PH_ROAM_NATIONAL_OFF_INTERNATIONAL_ON       2
#define TAF_PH_ROAM_NATIONAL_OFF_INTERNATIONAL_OFF      3
#define TAF_PH_ROAM_UNCHANGE          4


enum MN_MMA_ROAM_MODE_ENUM
{
    MN_MMA_ROAM_NATIONAL_ON_INTERNATIONAL_ON,                                   /* 开启国内国际漫游 */
    MN_MMA_ROAM_NATIONAL_ON_INTERNATIONAL_OFF,                                  /* 开启国内漫游，关闭国际漫游 */
    MN_MMA_ROAM_NATIONAL_OFF_INTERNATIONAL_ON,                                  /* 关闭国内漫游，开启国际漫游 */
    MN_MMA_ROAM_NATIONAL_OFF_INTERNATIONAL_OFF,                                 /* 关闭国内国际漫游 */
    MN_MMA_ROAM_UNCHANGE,                                                       /* 漫游能力未改变 */
    MN_MMA_ROAM_BUTT
};
typedef VOS_UINT8 MN_MMA_ROAM_MODE_ENUM_UINT8;

/*漫游状态*/
typedef TAF_UINT8 TAF_PH_ROAM_STA;
#define TAF_PH_ROAMING               0
#define TAF_PH_NO_ROAM               1
#define TAF_PH_ROAM_UNKNOW           2

#if(FEATURE_ON == FEATURE_LTE)

#define TAF_PH_DOMESTIC_5776        1
#define TAF_PH_FOREIGN_5776         2
#define TAF_PH_ROAM_UNKNOW_5776     0
typedef struct
{
    TAF_PH_RA_MODE                  RaMode;                                     /*无线接入模式,3G/2G*/
    TAF_PH_ROAM_STA                 RoamMode;                                   /*ROAM mode*/
}TAF_PH_CELLROAM_STRU;

#endif



/*------------    域状态标志宏     ------------*/
/*域状态标志宏需增加*/
/*
  0：    无服务
  1：    仅CS服务
  2：    仅PS服务
  3：    PS+CS服务
  4：    CS、PS均未注册，并处于搜索状态
*/
typedef TAF_UINT8 TAF_PH_DOMAIN_FLAG;

typedef struct
{
     TAF_PH_PREF_BAND                   PhBand;              /*频带设置*/
     TAF_PH_DOMAIN_FLAG                 DomainFlag;           /*域状态标志*/
     TAF_PH_ROAM_MODE                   RoamMode;             /*漫游选项*/
     /*只读,不可写,获取当前漫游状态*/
     TAF_PH_ROAM_STA                    RoamSta;
     VOS_UINT8                          aucReserved[1];
}TAF_PH_SYSTEM_MODE_STRU;

/*从USIM的spn文件中获取的信息结构体*/
typedef TAF_UINT8 TAF_PH_SPN_TYPE;
#define TAF_PH_GSM_SPN          0
#define TAF_PH_USIM_SPN         1
#define TAF_PH_SPN_TYPE_UNKNOW  2

typedef TAF_UINT8 TAF_PH_SPN_DISP_MODE;

typedef TAF_UINT8 TAF_PH_SPN_CODING;
#define TAF_PH_GSM_7BIT_DEFAULT       0
#define TAF_PH_RAW_MODE               1
#define TAF_PH_SPN_CODING_UNKNOW      255


#define TAF_PH_SPN_NAME_MAXLEN        16
/*用于与AT命令获取SPN文件对应*/
typedef struct
{
          TAF_PH_SPN_TYPE                   SpnType;
          TAF_PH_SPN_DISP_MODE              DispRplmnMode;
          TAF_PH_SPN_CODING                 SpnCoding;
          TAF_UINT8                         aucSpnName[TAF_PH_SPN_NAME_MAXLEN + 1];
}TAF_PH_USIM_SPN_STRU;

/*USIM中SPN文件内容*/
typedef struct
{
    TAF_UINT8         ucDispRplmnMode;
    TAF_UINT8         aucSpnName[TAF_PH_SPN_NAME_MAXLEN];
}TAF_PH_USIM_SPN_CNF_STRU;

/* 上报到应用层的SPN信息 */
typedef struct
{
    TAF_PH_SPN_DISP_MODE                DispRplmnMode;
    TAF_PH_ROAM_STA                     PhRoam;
    TAF_UINT8                           aucSpnName[TAF_PH_SPN_NAME_MAXLEN];
    VOS_UINT8                           aucReserved[2];
}TAF_PH_SPN_INFO_STRU;

#define FULL_NAME_IEI       0x43
#define SHORT_NAME_IEI      0x45
#define PLMN_ADDITIONAL_INFO_IEI      0x80

typedef struct
{
    VOS_BOOL                            bCPHSOperNameValid;
    VOS_UINT8                           aucCPHSOperNameStr[TAF_PH_OPER_NAME_LONG + 1];
    VOS_UINT8                           aucReserved[3];
}TAF_PH_SIM_CPHS_OPER_NAME_STRU;


typedef struct
{
    TAF_UINT8       PNN[80];
}TAF_PH_USIM_PNN_RECORD;

typedef TAF_UINT8 TAF_PH_ICC_TYPE;
#define TAF_PH_ICC_UNKNOW   0
#define TAF_PH_ICC_SIM      1
#define TAF_PH_ICC_USIM     2

typedef struct
{
    TAF_UINT32              CardType;
    TAF_UINT32              TotalRecordNum;
    TAF_UINT32              RecordLen;
    VOS_UINT16              usPnnCurrIndex; /* 查询PNN的起始位置 */
    TAF_PH_ICC_TYPE         Icctype;
    VOS_UINT8               aucReserve[1];
    TAF_PH_USIM_PNN_RECORD  PNNRecord[1];
}TAF_PH_USIM_PNN_CNF_STRU;

typedef struct
{
    TAF_UINT16              PlmnLen;
    TAF_UINT8               PLMN[6];
    TAF_UINT16              LACLow;
    TAF_UINT16              LACHigh;
    TAF_UINT16              PNNIndex;
    VOS_UINT8               aucReserved[2];
}TAF_PH_USIM_OPL_RECORD;

typedef struct
{
    TAF_UINT32              CardType;
    TAF_UINT32              TotalRecordNum;
    TAF_UINT32              RecordLen;
    TAF_PH_USIM_OPL_RECORD  OPLRecord[1];
}TAF_PH_USIM_OPL_CNF_STRU;

typedef struct
{
    TAF_PH_USIM_PNN_CNF_STRU *pstPnnCnf;
    TAF_PH_USIM_OPL_CNF_STRU *pstOplCnf;
}TAF_PH_USIM_CPNN_CNF_STRU;


/*小区信息*/
#define TAFMMA_CELL_MAX_NUM    8
typedef struct
{
    TAF_UINT8                           ucCellNum;
    VOS_UINT8                           aucReserved[3];
    TAF_UINT32                          aulCellId[TAFMMA_CELL_MAX_NUM];
}TAF_CELL_INFO_STRU;

typedef struct
{
    TAF_UINT32                          OP_CsRegState      : 1;
    TAF_UINT32                          OP_PsRegState      : 1;
    TAF_UINT32                          OP_ucAct           : 1;
    TAF_UINT32                          OP_Lac             : 1;
    TAF_UINT32                          OP_CellId          : 1;
    TAF_UINT32                          OP_Rac             : 1;
    TAF_UINT32                          OP_Plmn            : 1;
    TAF_UINT32                          OP_Spare           : 25;

    TAF_PH_REG_STATE_TYPE               RegState;               /*MM注册状态*/
    TAF_PH_REG_STATE_TYPE               ucPsRegState;           /*PS注册状态*/
    TAF_PH_ACCESS_TECH_ENUM_UINT8       ucAct;                  /*当前驻留网络的接入技术*/
    TAF_UINT8                           ucRac;                  /*RAC*/
    TAF_UINT16                          usLac;                  /*位置码信息*/
    VOS_UINT8                           aucReserved[2];
    TAF_CELL_INFO_STRU                  CellId;                 /*小区ID*/
    TAF_PLMN_ID_STRU                    Plmn;                   /*提供PLMN信息，当前未有需求*/
}TAF_PH_REG_STATE_STRU;

/*该信息包都是由NVIM中提取*/
typedef struct
{
    TAF_PH_IMEI_STRU                ImeisV;                 /*IMEISV*/
    TAF_PH_FMR_ID_STRU              FmrId;                  /*手机制造厂商信息*/
    TAF_PH_PRODUCT_NAME_STRU        ProductName;            /*产品名称*/
    TAF_PH_MODEL_ID_STRU            ModelId;                /*手机硬件版本信息*/
    TAF_PH_REVISION_ID_STRU         SoftVersion;            /*手机软件版本号*/
    TAF_PH_RELEASE_DATE_STRU        ReleaseDate;            /*发行日期*/
    TAF_PH_RELEASE_TIME_STRU        ReleaseTime;            /*发行时间*/
    TAF_PH_COMPCAPLIST_STRU         CompleteCapitiyList;    /*完整功能列表*/
    TAF_PH_COMPCAPLIST_STRU         GsmCompleteCapitiyList; /*完整功能列表*/
}TAF_PH_MEINFO_STRU;

#define TAF_PH_SYSCFG_GROUP_BAND_LEN                256

typedef struct
{
    TAF_CHAR  strSysCfgBandGroup[TAF_PH_SYSCFG_GROUP_BAND_LEN];

}TAF_PH_SYSCFG_BAND_STR;


typedef struct
{
    TAF_PH_PRODUCT_NAME_STRU        ProductName;            /*数据卡类型*/
    TAF_PH_FMR_ID_STRU              FmrId;                  /*手机制造厂商信息*/
    TAF_PH_PORT_INFO_STRU           PortId;                 /*数据卡端口分配信息*/
}TAF_PH_PORT_STRU;


typedef struct
{
    TAF_PH_MT_STA_ENUM                enPhStat;             /*针对^HS命令，初始化后就被置为在线*/
    TAF_PH_PLMN_PRIO                  PlmnPrio;             /*注册优先级*/
    MN_MMA_CPAM_RAT_TYPE_ENUM_UINT8   enAccessMode;           /*设置的接入模式*/
    VOS_UINT8                         aucReserved[2];
    TAF_PH_SRV_STA_STRU               PhSrvSta;           /*当前手机服务状态*/
    TAF_PH_RSSI_STRU                  RssiValue;          /*信号强度和信道质量*/
    TAF_PH_OP_MODE_STRU               PhOpMode;           /*手机当前工作状态*/
    TAF_PH_REG_STATE_STRU             PhRegSta;           /*手机当前注册状态*/
    TAF_PH_SYSTEM_MODE_STRU           PhSystemMode;       /*手机系统模式（频率，漫游设置，漫游状态等）*/
    TAF_PH_BATTERYPOWER_STRU          PhBatteryStatus;    /*手机电源状态*/
}TAF_PH_MS_STAT_STRU;

/*该信息包的内容与USIM相关，当USIM不存在时都要置为无效值*/
typedef struct
{
    TAF_USIM_STATUS_ST                UsimStatus;                               /*USIM状态*/
    TAF_PH_USIM_SPN_STRU              UsimSpnInfo;                              /*USIM中SPN文件内容*/
    TAF_PH_USIM_SPN_STRU              SimSpnInfo;
    TAF_PH_SIM_CPHS_OPER_NAME_STRU    stSimCPHSOperName;
}TAF_USIM_INFO_STRU;

typedef struct
{
    TAF_PH_MEINFO_STRU           MeInfo;          /*终端信息*/
    TAF_PH_MS_STAT_STRU          MsStatus;        /*手机当前运行状态*/
    TAF_USIM_INFO_STRU           UsimInfo;        /*USIM相关信息*/
}TAF_AT_DATA_STRU;

/*Taf_PhoneNetworkOperate*/
typedef TAF_UINT8 TAF_AVAIL_PLMN_LIST_TYPE;
#define TAF_PLMN_LIST        0       /*启动可用PLMN搜索*/
#define TAF_PLMN_LIST_ABORT  1       /*中止可用PLMN搜索*/


typedef TAF_UINT8 TAF_PLMN_RESEL_MODE_TYPE;
#define TAF_PLMN_RESELETION_AUTO        0     /*PLMN重选：自动*/
#define TAF_PLMN_RESELETION_MANUAL      1     /*PLMN重选：手工*/

typedef struct
{
    TAF_PH_NETWORK_STATUS_FLAG          PlmnStatus;
    TAF_PH_RA_MODE                      RaMode;      /*无线接入模式,3G/2G*/
    VOS_UINT8                           aucReserved[2];
}TAF_PLMN_STATUS_STRU;

typedef TAF_UINT8 AT_COPS_FORMAT_TYPE;
#define AT_COPS_LONG_ALPH_TYPE            0
#define AT_COPS_SHORT_ALPH_TYPE           1
#define AT_COPS_NUMERIC_TYPE              2
typedef struct
{
    AT_COPS_FORMAT_TYPE         ucFormatType;
    TAF_PH_RA_MODE              ucAccessMode;
    VOS_UINT16                  usOperNameLen;
    VOS_CHAR                    ucOperName[TAF_PH_OPER_NAME_LONG];
}TAF_PLMN_USER_SEL_STRU;


typedef struct
{
    VOS_UINT8           ucDomain;
    TAF_PH_CS_STATUS    ucCsState;
    TAF_PH_PS_STATUS    ucPsState;
    VOS_UINT8           aucReserved[1];
}TAF_DOMAIN_ATTACH_STATE_STRU;


/*由于一个PLMN NAME包含长短名等有100字节左右，而核间通信缓冲最大为4K，所以只能存放36个左右PLMN NAME*/
#define MAX_PLMN_NAME_LIST   37
typedef struct
{
    TAF_UINT32                          ulPlmnNum;
    VOS_BOOL                            bPlmnSelFlg;
    TAF_PH_OPERATOR_NAME_STRU           astPlmnName[MAX_PLMN_NAME_LIST];
    TAF_MMC_USIM_RAT                    ausPlmnRat[MAX_PLMN_NAME_LIST];
    VOS_UINT8                           aucReserved[2];
}TAF_PLMN_NAME_LIST_STRU;


#define TAF_MAX_PLMN_NUM       37
typedef struct
{
    TAF_UINT8                           ucPlmnNum;
    VOS_UINT8                           aucReserved[3];
    TAF_PLMN_ID_STRU                    Plmn[TAF_MAX_PLMN_NUM];
    TAF_PLMN_STATUS_STRU                PlmnInfo[TAF_MAX_PLMN_NUM];
}TAF_PLMN_LIST_STRU;

/*   取MMC_MAX_OPLMN_NUM  NAS_MMC_MAX_UPLMN_NUM MMC_MAX_SELPLMN_NUM
     MMC_MAX_HPLMN_WITH_ACT_NUM                           中的最大值 */
#define TAF_USER_MAX_PLMN_NUM        256
typedef struct
{
    TAF_UINT16           usPlmnNum;
    TAF_UINT8            aucReserved[2];
    TAF_PLMN_ID_STRU     Plmn[TAF_USER_MAX_PLMN_NUM];
    TAF_MMC_USIM_RAT     PlmnRat[TAF_USER_MAX_PLMN_NUM];
}TAF_USER_PLMN_LIST_STRU;

typedef struct
{
    TAF_UINT8                           ucIndex;
    VOS_UINT8                           aucReserved1[3];
    TAF_PLMN_ID_STRU                    Plmn;
    MN_MMA_CPAM_RAT_TYPE_ENUM_UINT8     PlmnRat;
    VOS_UINT8                           aucReserved2[3];
}TAF_USER_PLMN_INFO_STRU;



typedef struct
{
    TAF_UINT8                           ucLen;
    VOS_UINT8                           aucReserved[3];
    TAF_UINT8                           aucCommand[USIMM_T0_APDU_MAX_LEN];
}TAF_PH_USIM_COMMAND_STRU;


/* ucActionType的取值 */
#define TAF_START_EVENT_INFO_FOREVER    0   /* 指示主动上报启动 */
#define TAF_START_EVENT_INFO_ONCE       1   /* 指示上报结果一次 */
#define TAF_START_EVENT_INFO_STOP       2   /* 指示停止上报 */

/* ucMsgType的取值 */
#define TAF_EVENT_INFO_CELL_SIGN        1   /* 表示获取小区信号强度 */
#define TAF_EVENT_INFO_CELL_ID          2   /* 表示获取小区ID */
#define TAF_EVENT_INFO_CELL_BLER        4   /* 表示获取信道误码率 */

/* 启动事件主动上报信息的结构体 */
typedef struct
{
    TAF_UINT8              ucActionType;
    TAF_UINT8              ucRrcMsgType;

    VOS_UINT8              ucSignThreshold;    /* 1:rssi变化超过1db主动上报^cerssi; 2:rssi变化超过2db主动上报
                                        3:rssi变化超过3db主动上报；4:rssi变化超过4db主动上报；5:rssi变化超过5db主动上报;*/
    VOS_UINT8              ucMinRptTimerInterval;   /*上报的间隔时间(1-20)S*/
}TAF_START_INFO_IND_STRU;


/*参数查询结果上报回调函数*/
typedef struct
{
    MN_MMA_CPAM_RAT_TYPE_ENUM_UINT8     AccessMode;
    TAF_PH_PLMN_PRIO                    PlmnPrio;
}TAF_ACCESS_MODE_QUERY_PARA_STRU;

typedef struct
{
    TAF_UINT16    usHighFreq;
    TAF_UINT16    usLowFreq;
}TAF_PH_FREQ_INFO_STRU;

/*频点信息结构体*/
typedef struct
{
    TAF_UINT32              ulGsmFreq;
    TAF_PH_FREQ_INFO_STRU   WcdmaFrq;
}TAF_PH_FRQ_STRU;

#define TAF_PH_ICC_ID_MAX 10
typedef struct
{
    TAF_UINT8 ucLen;
    TAF_UINT8 aucIccId[TAF_PH_ICC_ID_MAX + 1];
}TAF_PH_ICC_ID_STRU;

/*    ucSrvStatus取值如下： */
#define  TAF_PH_INFO_NO_SERV            0/*无服务*/
#define  TAF_PH_INFO_LIMT_SERV          1/*有限制服务*/
#define  TAF_PH_INFO_NOMRL_SERV         2/*服务有效*/
#define  TAF_PH_INFO_LIMT_REGON_SERV    3/*有限制的区域服务*/
#define  TAF_PH_INFO_DEEP_SLEEP         4/*省电和深睡状态*/
/*    ucSrvDomain取值如下：*/
#define  TAF_PH_INFO_NO_DOMAIN          0/*无服务*/
#define  TAF_PH_INFO_ONLY_CS            1/*仅CS服务*/
#define  TAF_PH_INFO_ONLY_PS            2/*仅PS服务*/
#define  TAF_PH_INFO_DUAL_DOMAIN        3/*PS+CS服务*/
#define  TAF_PH_INFO_SEARCH_DOMAIN      4/*CS、PS均未注册，并处于搜索状态  */
/*    ucRoamStatus取值如下：*/
#define  TAF_PH_INFO_NONE_ROMAING       0/*非漫游状态*/
#define  TAF_PH_INFO_ROMAING            1/*漫游状态*/
#define  TAF_PH_INFO_ROAM_UNKNOW        2/*未知状态*/

typedef TAF_UINT8 TAF_PH_INFO_RAT_TYPE;
/*ucSysMode取值如下：*/
#define  TAF_PH_INFO_NONE_RAT           0/*无服务*/
#define  TAF_PH_INFO_GSM_RAT            3/*GSM/GPRS模式*/
#define  TAF_PH_INFO_WCDMA_RAT          5/*WCDMA模式*/
#define  TAF_PH_INFO_LTE_RAT            7/*LTE模式*/

#define  TAF_PH_INFO_TD_SCDMA_RAT       15/*TD-SCDMA模式*/


/*    ucSimStatus取值如下 */
#define  TAF_PH_INFO_USIM_PIN_INVAILD   0/*USIM卡状态无效或者PIN码没有校验或解锁*/
#define  TAF_PH_INFO_USIM_VAILD         1/*USIM卡状态有效*/
#define  TAF_PH_INFO_USIM_CS_INVAILD    2/*USIM在CS下无效*/
#define  TAF_PH_INFO_USIM_PS_INVAILD    3/*USIM在PS下无效*/
#define  TAF_PH_INFO_USIM_INVAILD       4/*USIM在PS+CS下均无效*/
#define  TAF_PH_INFO_USIM_ABSENT        255/*USIM卡不存在*/

typedef struct
{
    TAF_UINT8                 ucSrvStatus;        /*服务状态，仅支持取值0,1,2*/
    TAF_UINT8                 ucSrvDomain;        /*服务域*/
    TAF_UINT8                 ucRoamStatus;       /*漫游状态，仅区别PLMN ID不同漫游*/
    TAF_UINT8                 ucSysMode;          /*系统模式*/
    TAF_UINT8                 ucSimStatus;        /*SIM卡状态*/
    TAF_UINT8                 ucSysSubMode;       /*系统子模式*/
    TAF_UINT8                 ucSimLockStatus;    /*SIM卡的LOCK状态*/
}TAF_PH_SYSINFO_STRU;

typedef struct
{
    TAF_UINT8            RatType;
    TAF_UINT8            GsmBand;
    TAF_UINT16           IndFreq;
}TAF_IND_FREQ_STRU;

#define TAF_MAX_USIM_RSP_LEN    255
typedef struct
{
    TAF_UINT8  ucLen;
    TAF_UINT8  aucResponse[TAF_MAX_USIM_RSP_LEN];
}TAF_PH_USIM_RESPONSE_STRU;

/* 系统配置数据结构 */
typedef struct
{
    TAF_PH_CMD_TYPE                     CmdType;
    MN_MMA_CPAM_RAT_TYPE_ENUM_UINT8     AccessMode;
    TAF_PH_PLMN_PRIO                    PlmnPrio;
    TAF_PH_ROAM_MODE                    Roam;
    TAF_PH_PREF_BAND                    Band;
    TAF_PH_SERVICE_DOMAIN               SrvDomain;
    VOS_UINT8                           aucReserved[3];
    TAF_USER_SET_PREF_BAND64            stOrigUserSetBand;
}TAF_PH_SYS_CFG_STRU;


typedef TAF_UINT8 TAF_PH_PIN_STATUS;
#define TAF_PH_PIN_ENABLE   0
#define TAF_PH_PIN_DISABLE  1

typedef TAF_UINT8 TAF_PH_PIN_VERIFY_STATUS;
#define TAF_PH_PIN_NEED     0
#define TAF_PH_PIN_NONEED   1
#define TAF_PH_PIN_PUK      2
typedef TAF_UINT8 TAF_PH_ME_LOCK_STATUS;
#define TAF_PH_ME_SIM_UNLOCK    0
#define TAF_PH_ME_SIM_LOCK      1
#define TAF_PH_ME_NO_SIM        2

typedef struct
{
    TAF_PH_ICC_TYPE           MmaIccType;
    TAF_PH_PIN_STATUS         MmaIccPinStatus;
    TAF_PH_PIN_VERIFY_STATUS  MmaIccPinVerifyStatus;
    TAF_UINT8                 ucRemainTimes;
}TAF_PH_UICC_TYPE;

typedef enum
{
    MN_PH_PREF_PLMN_UPLMN,
    MN_PH_PREF_PLMN_OPLMN,
    MN_PH_PREF_PLMN_HPLMN
}MN_PH_PREF_PLMN_ID_ENUM;
typedef VOS_UINT8 MN_PH_PREF_PLMN_TYPE_ENUM_U8;

typedef enum
{
    MN_PH_PrefPLMN_QUREY,
    MN_PH_PrefPLMN_DEL_ONE,
    MN_PH_PrefPLMN_ADD_ONE,
    MN_PH_PrefPLMN_MODIFY_ONE
} MN_PH_PrefPLMN_OPERATE_TYPE;
typedef VOS_UINT8 MN_PH_PrefPLMN_OPERATE_TYPE_U8;

typedef struct
{
    MN_PH_PREF_PLMN_TYPE_ENUM_U8        enPrefPLMNType;
    MN_PH_PrefPLMN_OPERATE_TYPE_U8      enPrefPlmnOperType;
    TAF_MMC_USIM_RAT                    usRat;                                  /* USIM格式的 接入技术 */
    VOS_UINT32                          ulIndex;
    TAF_PLMN_ID_STRU                    stPlmn;
} TAF_PH_PREF_PLMN_OPERATE_STRU;
typedef struct
{
    MN_PH_PREF_PLMN_TYPE_ENUM_U8        enPrefPlmnType;                     /* 选中的优先级网络列表类型*/
    VOS_UINT8                           ucAtParaIndex;                      /* 参数个数 */
    VOS_UINT16                          usIndexLen;                         /* 索引参数的长度*/
    VOS_UINT16                          usFormatLen;                        /* 网络名类型的长度*/
    VOS_UINT16                          usOperNameLen;                      /* 运营商名字的长度*/
    VOS_UINT16                          usGsmRatLen;                        /* GSM接入技术的长度*/
    VOS_UINT16                          usGsmCompactRatLen;                 /* GSM COMPACT接入技术的长度*/
    VOS_UINT16                          usUtrnLen;                          /* UTRN接入技术的长度 */
    VOS_UINT16                          usReserve;                          /* 保留字段*/
    VOS_UINT32                          usIndex;                            /* 索引值*/
    VOS_UINT32                          usFormat;                           /* 网络类型值*/
    VOS_CHAR                            ucOperName[TAF_PH_OPER_NAME_LONG];  /* 运营商名*/
    VOS_UINT32                          usGsmRat;                           /* GSM接入技术值*/
    VOS_UINT32                          usGsmCompactRat;                    /* GSM COMPACK接入技术值*/
    VOS_UINT32                          usUtrn;                             /* UTRN接入技术值*/
    VOS_UINT16                          usEutrnLen;                         /* E-UTRN接入技术的长度 */
    VOS_UINT8                           aucReserved[2];
    VOS_UINT32                          usEutrn;                            /* E-UTRN接入技术值*/
} TAF_PH_SET_PREFPLMN_STRU;
typedef struct
{
    VOS_UINT8   aucPara0[TAF_PH_UNLOCKCODELEN];         /* 用来放置解析出的参数字符串 */
    VOS_UINT16  usPara0Len;                             /* 用来标识参数字符串长度 */
    VOS_UINT8   aucPara1[TAF_PH_PINCODELENMAX];         /* 用来放置解析出的参数字符串 */
    VOS_UINT16  usPara1Len;                             /* 用来标识参数字符串长度 */
}MN_PH_SET_CPIN_REQ_STRU;

typedef enum
{
    TAF_PH_PNN_FILE,
    TAF_PH_OPL_FILE,
    TAF_PH_MAX_FILE
}TAF_PH_USIM_FILE_ENUM;
typedef VOS_UINT16 TAF_PH_USIM_FILE_ENUM_U16;

#define TAF_PH_INVALID_USIM_REC             0xFFFFFFFFU
typedef struct
{
    VOS_UINT16                          usPnnCurrIndex; /* 查询PNN的起始位置 */
    VOS_UINT16                          usPnnNum;       /* 查询PNN的个数，由于A核和C核通讯，消息大小有限制，因此一次最多查询10条记录 */
}TAF_MMA_PNN_INFO_QUERY_REQ_INDEX_STRU;

typedef struct
{
    TAF_PH_ICC_TYPE                     Icctype;
    VOS_UINT8                           ucReserved;
    TAF_PH_USIM_FILE_ENUM_U16           enEfId;
    TAF_UINT32                          ulRecNum;
    TAF_MMA_PNN_INFO_QUERY_REQ_INDEX_STRU stPnnQryIndex;
}TAF_PH_QRY_USIM_INFO_STRU;

typedef struct
{
    TAF_PH_ICC_TYPE                     Icctype;
    VOS_UINT8                           aucReserved[3];
    VOS_BOOL                            bFileExist;
    TAF_UINT32                          ulTotalRecNum;
    TAF_UINT32                          ulRecordLen;
}TAF_PH_USIM_INFO_STRU;

typedef struct
{
    TAF_PH_USIM_INFO_STRU               stUsimInfo;
    TAF_PH_USIM_INFO_STRU               stSimInfo;
}TAF_PH_QRY_USIM_RANGE_INFO_STRU;

typedef TAF_UINT8 TAF_PH_ICC_STATUS;
#define TAF_PH_ICC_INVALID      0
#define TAF_PH_ICC_VALID        1
#define TAF_PH_ICC_CSINVALID    2
#define TAF_PH_ICC_PSINVALID    3
#define TAF_PH_ICC_CSPSINVALID  4
#define TAF_PH_ICC_NOTEXIT      255

/*PHONE事件类型*/
typedef TAF_UINT8 TAF_PHONE_EVENT;
#define TAF_PH_EVT_ERR                      0   /*事件通用错误*/
#define TAF_PH_EVT_PLMN_LIST_ABORT_CNF      1   /*获取可用PLMN列表终止确认信息*/
#define TAF_PH_EVT_PLMN_LIST_IND            2   /*PLMN列表主动上报指示*/
#define TAF_PH_EVT_OPER_MODE_CNF            3  /* 功能模式 */
#define TAF_PH_EVT_SYS_CFG_CNF              4  /* 系统配置 */
#define TAF_PH_EVT_PLMN_LIST_CNF            5   /*APP发起获取PLMN列表确认事件*/
#define TAF_PH_EVT_PLMN_LIST_REJ            6   /*拒绝发起获取PLMN列表操作*/
#define TAF_PH_EVT_PLMN_SEL_CNF             7   /*APP指定PLMN选择确认信息*/
#define TAF_PH_EVT_PLMN_RESEL_CNF           8   /*APP发起的PLMN重选确认信息*/
#define TAF_PH_EVT_SERVICE_STATUS_IND       9   /*主动上报下层的服务状态*/
#define TAF_PH_EVT_ATTACH_CNF               10  /*同时附着两个域时返回的确认事件*/
#define TAF_PH_EVT_PS_ATTACH_CNF            11  /*附着PS域返回的确认信息*/
#define TAF_PH_EVT_CS_ATTACH_CNF            12  /*附着CS域返回的确认信息*/
#define TAF_PH_EVT_DETACH_CNF               13  /*同时去附着两个域返回的确认信息*/
#define TAF_PH_EVT_PS_DETACH_CNF            14  /*去附着PS域返回的确认信息*/
#define TAF_PH_EVT_CS_DETACH_CNF            15  /*去附着PS域返回的确认信息*/
#define TAF_PH_EVT_RSSI_CHANGE_IND          16  /*信号强度变化指示*/
#define TAF_PH_EVT_POWER_STA_IND            17  /*电源状态指示*/
#define TAF_PH_EVT_OP_PIN_CNF               18  /*操作PIN码返回结果*/
#define TAF_PH_EVT_SYSTEM_INFO_IND          19  /*系统信息指示*/
#define TAF_PH_EVT_SETUP_SYSTEM_INFO_RSP    20  /*启动系统信息上报标志*/
#define TAF_PH_EVT_USIM_RESPONSE            21  /*获取到的USIM*/
#define TAF_PH_EVT_USIM_INFO_IND            22  /*卡状态信息指示*/
#define TAF_PH_EVT_OP_PINREMAIN_CNF         23
#define TAF_PH_EVT_ME_PERSONALISATION_CNF   24  /*移动设备私有操作返回结果*/
#define TAF_PH_EVT_RESTRICTED_ACCESS_CNF    25  /*受限制的SIM卡访问数据返回*/
#define TAF_PH_EVT_OPER_MODE_IND            26  /* 功能模式变化主动上报 */
#define TAF_PH_EVT_MM_INFO_IND              27  /* MM INFO信息上报 */
#define TAF_PH_EVT_MODE_CHANGE_IND          28  /* ^MODE信息上报 */
#define MN_PH_EVT_SIMLOCKED_IND             29  /* SIMLOCK上报 */
#define MN_PH_EVT_ROAMING_IND               30  /* ROAMING上报 */
#define TAF_PH_EVT_GET_CURRENT_ATTACH_STATUS_CNF  31 /*获取当前注册状态回复消息*/
#define TAF_PH_EVT_MT_POWER_DOWN_CNF        32  /*MT下电命令回复消息*/
#define TAF_PH_EVT_SET_PREF_PLMN_CNF        33  /*设置优先级网络列表文件回复消息*/
#define TAF_PH_EVT_SET_PREF_PLMN_TYPE_CNF   34  /*设置优先级网络列表文件回复消息*/
#define TAF_PH_EVT_TEST_PREF_PLMN_CNF       35  /*测试优先级网络列表回复消息*/
#define TAF_PH_EVT_TEST_SYSCFG_CNF          36  /*测试syscfg回复消息*/

/* MMA给AT上报事件，用于显示+PACSP1或者+PACSP0*/
#define TAF_PH_EVT_NSM_STATUS_IND           (37)

#define TAF_PH_EVT_PLMN_CHANGE_IND          (38)  /* ^PLMN信息上报 */

#define TAF_MMA_EVT_AC_INFO_CHANGE_IND       (39) /* 小区禁止接入技术信息上报 */

#define TAF_MMA_EVT_REG_REJ_INFO_IND       (40) /* 网络拒绝原因值上报 */

#define TAF_MMA_EVT_PLMN_SELECTION_INFO_IND       (41) /* 搜网结果上报 */

#define TAF_MMA_EVT_USER_CFG_OPLMN_QRY_CNF          (42) /* 查询本地PLMN列表结果上报 */
#define TAF_MMA_EVT_USER_CFG_OPLMN_SET_CNF          (43) /* 设置本地PLMN列表结果上报 */

#define TAF_MMA_EVT_NET_SCAN_CNF                            (44)

#define TAF_MMA_EVT_PS_INIT_RESULT_IND        (45)  /* 协议栈初始化结果指示消息 */

#define TAF_PH_MAX_GUL_RAT_NUM                              (3)                 /*AT^syscfgex中acqorder代表的接入技术个数 */
#define TAF_PH_MAX_GU_RAT_NUM                               (2)                 /*AT^syscfgex中acqorder代表的接入技术个数 */
#define TAF_PH_MAX_LU_RAT_NUM                               (2)                 /*AT^syscfgex中acqorder代表的接入技术个数 */



typedef struct
{
    VOS_UINT8                           ucRatOrderNum;                          /* syscfgex中设置的acqoder中的指示个数 */
    TAF_PH_RAT_TYPE_ENUM_UINT8          aenRatOrder[TAF_PH_MAX_GUL_RAT_NUM];    /* at^syscfgex中设置的acqoder的顺序 */
}TAF_PH_RAT_ORDER_STRU;



enum TAF_MMA_USER_SET_PRIO_RAT_ENUM
{
    TAF_MMA_USER_SET_PRIO_AUTO,
    TAF_MMA_USER_SET_PRIO_GSM_PREFER,
    TAF_MMA_USER_SET_PRIO_WCDMA_PREFER,
    TAF_MMA_USER_SET_PRIO_NOCHANGE,
    TAF_MMA_USER_SET_PRIO_BUTT
};
typedef VOS_UINT8 TAF_MMA_USER_SET_PRIO_RAT_ENUM_U8;



enum TAF_PH_USER_SET_RAT_TYPE_ENUM
{
    TAF_PH_USER_SET_RAT_WCDMA,
    TAF_PH_USER_SET_RAT_WCDMA_GSM,
    TAF_PH_USER_SET_RAT_GSM,
    TAF_PH_USER_SET_RAT_BUTT
};
typedef VOS_UINT8 TAF_PH_USER_SET_RAT_TYPE_ENUM_U8;





typedef struct
{
    TAF_PH_ROAM_MODE                           ucRoam;                          /* 漫游能力，0：开启国内国际漫游；1：开启国内漫游，关闭国际漫游；2：关闭国内漫游，开启国际漫游；3：关闭国内国际漫游 */
    TAF_PH_SERVICE_DOMAIN                      ucSrvDomain;                     /* 服务域，0：CS ONLY; 1:PS ONLY; 2:CS_PS; 3:any等同于CS ONLY；4：不改变服务域；*/
    TAF_MMA_USER_SET_PRIO_RAT_ENUM_U8          enUserPrio;
    VOS_UINT8                                  aucReserve[1];
    TAF_PH_RAT_ORDER_STRU                      stRatOrder;                      /* 记录接入模式个数和优先级 */
    TAF_USER_SET_PREF_BAND64                   stGuBand;                        /* 记录GU频段 */
    TAF_USER_SET_PREF_BAND64                   stLBand;                         /* 记录L频段 */
}TAF_MMA_SYS_CFG_PARA_STRU;



#define TAF_MAX_GROUP_CFG_OPLMN_NUM                  (50)            /* 单组允许配置的OPLMN的最大个数 */
#define TAF_MAX_USER_CFG_OPLMN_GROUP_INDEX           (5)             /* 允许设置的最大组Index,支持设置(0-5)共6组 */
#define TAF_MAX_USER_CFG_OPLMN_VERSION_LEN           (8)             /* 用户配置的OPLMN版本号最大长度 */
#define TAF_MAX_GROUP_CFG_OPLMN_DATA_LEN             (250)           /* 单组允许配置OPLMN的最大字节数，采用SIM卡文件格式以5个字节表示1个带接入技术的OPLMN*/
#define TAF_MAX_USER_CFG_OPLMN_DATA_LEN              (1280)          /* 用户允许配置的总的OPLMN最大字节数，采用SIM卡文件格式以5个字节表示1个带接入技术的OPLMN*/
#define TAF_SIM_PLMN_WITH_RAT_LEN                    (5)             /* SIM卡带接入技术PLMN字节数*/
#define TAF_AT_PLMN_WITH_RAT_LEN                     (10)            /* AT命令下发的带接入技术PLMN字节数*/
#define TAF_AT_EOPLMN_PARA_NUM                       (4)             /* ^EOPLMN设置命令参数的个数 */

typedef struct
{
    TAF_UINT8                           aucVersion[TAF_MAX_USER_CFG_OPLMN_VERSION_LEN];    /* OPLMN List版本号 */
    TAF_UINT8                           ucIndex;                                /* 当前设置的组Index */
    TAF_UINT8                           ucOPlmnCount;                           /* 单组实际设置OPLMN的个数 */
    TAF_UINT8                           aucOPlmnWithRat[TAF_MAX_GROUP_CFG_OPLMN_DATA_LEN];  /* OPLMN的PDU数据，和EFOplmn文件一致 */
}TAF_MMA_SET_EOPLMN_LIST_STRU;


typedef struct
{
    TAF_PHONE_EVENT                     PhoneEvent;
    MN_OPERATION_ID_T                   OpId;
    MN_CLIENT_ID_T                      ClientId;

    VOS_UINT32                          ulResult;
}TAF_PHONE_EVENT_EOPLMN_SET_CNF_STRU;


typedef struct
{
    TAF_PHONE_EVENT                     PhoneEvent;
    MN_OPERATION_ID_T                   OpId;
    MN_CLIENT_ID_T                      ClientId;

    VOS_UINT32                          ulResult;
    VOS_UINT8                           aucVersion[TAF_MAX_USER_CFG_OPLMN_VERSION_LEN];       /* OPLMN List版本号 */
    TAF_UINT16                          usOPlmnNum;                                           /* OPLMN个数 */
    TAF_UINT8                           aucReserved[2];
    TAF_UINT8                           aucOPlmnList[TAF_MAX_USER_CFG_OPLMN_DATA_LEN];        /* OPLMN的PDU数据，和EFOplmn文件一致 */
}TAF_PHONE_EVENT_EOPLMN_QRY_CNF_STRU;
typedef struct
{
    VOS_UINT16                          usCellNum;                              /* 需要扫描出超过门限的小区个数 */
    VOS_INT16                           sCellPow;                               /* 小区门限值 */
    TAF_PH_RAT_TYPE_ENUM_UINT8          ucRat;                                  /* 需要扫描的接入模式 */
    VOS_UINT8                           aucReserve[3];
    TAF_USER_SET_PREF_BAND64            stBand;                                 /* 记录频段*/
}TAF_MMA_NET_SCAN_REQ_STRU;


typedef struct
{
    VOS_UINT16                          usArfcn;                                /* 频点 */
    VOS_UINT16                          usC1;                                   /* 用于GSM小区重选的C1值(暂不支持) */
    VOS_UINT16                          usC2;                                   /* 用于GSM小区重选的C2值(暂不支持) */
    VOS_UINT16                          usLac;                                  /* 位置区码 */
    VOS_UINT32                          ulMcc;                                  /* PLMN国家码 */
    VOS_UINT32                          ulMnc;                                  /* PLMN网络码 */
    VOS_UINT16                          usBsic;                                 /* GSM小区基站码 */
    VOS_INT16                           sRxlev;                                 /* 接收到的信号强度 */
    VOS_INT16                           sRssi;                                  /* GSM是BCCH信道的RSSI，WCDMA是RSCP */
    VOS_UINT8                           aucReserve[2];
    VOS_UINT32                          ulCellId;                               /* 小区ID */
    TAF_USER_SET_PREF_BAND64            stBand;                               /* 具体取值同接口RRMM_SYS_CFG_REQ_STRU中频段参数 */
}TAF_MMA_NET_SCAN_INFO_STRU;

/*****************************************************************************
 枚举名    : TAF_MMA_NET_SCAN_RESULT_ENUM
 结构说明  : TAF_MMA_NET_SCAN_CNF_STRU消息中的enResult;
*****************************************************************************/
enum TAF_MMA_NET_SCAN_RESULT_ENUM
{
    TAF_MMA_NET_SCAN_RESULT_SUCCESS     = 0,
    TAF_MMA_NET_SCAN_RESULT_FAILURE     = 1,
    TAF_MMA_NET_SCAN_RESULT_BUTT
};
typedef VOS_UINT8  TAF_MMA_NET_SCAN_RESULT_ENUM_UINT8;


enum TAF_MMA_NET_SCAN_CAUSE_ENUM
{
    TAF_MMA_NET_SCAN_CAUSE_SIGNAL_EXIST        = 0,                /* 存在信令连接 */
    TAF_MMA_NET_SCAN_CAUSE_STATE_NOT_ALLOWED   = 1,                /* 当前未驻留 */
    TAF_MMA_NET_SCAN_CAUSE_FREQ_LOCK           = 2,                /* 当前锁频状态 */
    TAF_MMA_NET_SCAN_CAUSE_PARA_ERROR          = 3,                /* 参数错误，包含接入技术不支持，频段不支持，频点个数错误，门限错误 */
    TAF_MMA_NET_SCAN_CAUSE_CONFLICT            = 4,                /* 错误原因值冲突 */
    TAF_MMA_NET_SCAN_CAUSE_SERVICE_EXIST       = 5,
    TAF_MMA_NET_SCAN_CAUSE_NOT_CAMPED          = 6,
    TAF_MMA_NET_SCAN_CAUSE_TIMER_EXPIRED       = 7,
    TAF_MMA_NET_SCAN_CAUSE_RAT_TYPE_ERROR      = 8,
    TAF_MMA_NET_SCAN_CAUSE_MMA_STATE_DISABLE   = 9,

    TAF_MMA_NET_SCAN_CAUSE_BUTT
};
typedef VOS_UINT8 TAF_MMA_NET_SCAN_CAUSE_ENUM_UINT8;
typedef struct
{
    /*该部分必须放在最前面，AT模块根据取该部分来判断消息类型*/
    TAF_PHONE_EVENT                     PhoneEvent;
    MN_OPERATION_ID_T                   ucOpId;
    MN_CLIENT_ID_T                      usClientId;

    TAF_MMA_NET_SCAN_RESULT_ENUM_UINT8  enResult;
    TAF_MMA_NET_SCAN_CAUSE_ENUM_UINT8   enCause;
    VOS_UINT8                           ucFreqNum;                                      /* 上报的频点个数 */
    VOS_UINT8                           aucReserve[1];
    TAF_MMA_NET_SCAN_INFO_STRU          astNetScanInfo[TAF_MMA_NET_SCAN_MAX_FREQ_NUM];
}TAF_MMA_NET_SCAN_CNF_STRU;


typedef struct
{
    /*该部分必须放在最前面，AT模块根据取该部分来判断消息类型*/
    TAF_PHONE_EVENT                     PhoneEvent;
    MN_OPERATION_ID_T                   OpId;
    MN_CLIENT_ID_T                      ClientId;

    TAF_PLMN_ID_STRU                    stPlmnId;
    TAF_UINT32                          ulRejCause;
    TAF_PH_RAT_TYPE_ENUM_UINT8          enRat;
    TAF_PH_SERVICE_DOMAIN               ucSrvDomain;

    VOS_UINT8                           ucRejType;
    TAF_UINT8                           ucReserved;

}TAF_PH_REG_REJ_INFO_STRU;
enum TAF_PH_PLMN_SELECTION_RESULT_ENUM
{
    TAF_PH_PLMN_SELECTION_RESULT_NORMAL_SERVICE    = 0,                        /* 正常服务 */
    TAF_PH_PLMN_SELECTION_RESULT_LIMITED_SERVICE   = 1,                        /* 限制服务 */
    TAF_PH_PLMN_SELECTION_RESULT_NO_SERVICE        = 2,                        /* 无服务 */
    TAF_PH_PLMN_SELECTION_RESULT_INTERRUPT         = 3,                        /* 搜网被中断 */
    TAF_PH_PLMN_SELECTION_RESULT_BUTT
};
typedef VOS_UINT32 TAF_PH_PLMN_SELECTION_RESULT_ENUM_UINT32;


enum TAF_PH_PLMN_SELECTION_START_END_FLAG_ENUM
{
    TAF_PH_PLMN_SELECTION_START      = 0,                        /* 搜网开始 */
    TAF_PH_PLMN_SELECTION_END        = 1,                        /* 搜网结束 */
    TAF_PH_PLMN_SELECTION_INTERRUPT  = 2,                        /* 搜网被打断 */
    TAF_PH_PLMN_SELECTION_BUTT
};
typedef VOS_UINT32 TAF_PH_PLMN_SELECTION_START_END_FLAG_ENUM_UINT32;
typedef struct
{
    /*该部分必须放在最前面，AT模块根据取该部分来判断消息类型*/
    TAF_PHONE_EVENT                     PhoneEvent;
    MN_OPERATION_ID_T                   OpId;
    MN_CLIENT_ID_T                      ClientId;

    TAF_PH_PLMN_SELECTION_RESULT_ENUM_UINT32           ulPlmnSelectRlst;
    TAF_PH_PLMN_SELECTION_START_END_FLAG_ENUM_UINT32   ulPlmnSelectFlag; /* 标示搜网开始或搜网结束 */
}TAF_PH_PLMN_SELECTION_INFO_STRU;


typedef struct
{
    TAF_PHONE_EVENT             PhoneEvent;
    MN_OPERATION_ID_T           OpId;
    MN_CLIENT_ID_T              ClientId;

    TAF_UINT32                  ulPlmnNum;
    TAF_PH_OPERATOR_NAME_STRU   astPlmnName[MAX_PLMN_NAME_LIST];
    TAF_PLMN_STATUS_STRU        astPlmnInfo[MAX_PLMN_NAME_LIST];
}TAF_PHONE_EVENT_PLMN_LIST_STRU;

typedef struct
{
    /*该部分必须放在最前面，AT模块根据取该部分来判断消息类型*/
    TAF_PHONE_EVENT                    PhoneEvent;
    MN_OPERATION_ID_T                  OpId;
    MN_CLIENT_ID_T                     ClientId;

    TAF_UINT32                         OP_RegPlmn         : 1;
    TAF_UINT32                         OP_CsServiceStatus : 1;
    TAF_UINT32                         OP_PsServiceStatus : 1;
    TAF_UINT32                         OP_PlmnList        : 1;

    TAF_UINT32                         OP_PlmnReselMode   : 1;
    TAF_UINT32                         OP_PhoneError      : 1;
    TAF_UINT32                         OP_CurRegSta       : 1;
    TAF_UINT32                         OP_Rssi            : 1;

    TAF_UINT32                         OP_BatteryPower    : 1;
    TAF_UINT32                         OP_Pin             : 1;
    TAF_UINT32                         OP_UsimAccessData  : 1;
    TAF_UINT32                         OP_PinRemain       : 1;

    TAF_UINT32                         OP_MeLockStatus     : 1;
    TAF_UINT32                         OP_MePersonalisation: 1;
    TAF_UINT32                         OP_OperMode         : 1;
    TAF_UINT32                         OP_SpnInfo          : 1;

    TAF_UINT32                         OP_Mode              : 1;
    TAF_UINT32                         OP_Srvst             : 1;
    TAF_UINT32                         OP_UsimRestrictAccess: 1;
    TAF_UINT32                         OP_UsimPNN           : 1;

    TAF_UINT32                         OP_SysCfg            : 1;
    TAF_UINT32                         OP_UsimOPL           : 1;
    TAF_UINT32                         OP_MmInfo            : 1;
    TAF_UINT32                         OP_PrefPlmnList      : 1;

    TAF_UINT32                         OP_DomainAttachState : 1;
    TAF_UINT32                         OP_SysCfgBandGroup   : 1;


    TAF_UINT32                         OP_PlmnMode          : 1;

    TAF_UINT32                         OP_CurPlmn           : 1;

    TAF_UINT32                         Op_CellAcInfo        : 1;
    TAF_UINT32                         OP_Spare             : 2;
    TAF_UINT32                         OP_PsInitRslt        : 1;

    TAF_ERROR_CODE_ENUM_UINT32         PhoneError;

    TAF_PH_OP_MODE_CNF_STRU            OperMode;


    TAF_MMA_SYS_CFG_PARA_STRU          stSysCfg;


    TAF_PLMN_ID_STRU                   RegPlmn;
    TAF_PH_INFO_RAT_TYPE               RatType;
    TAF_PHONE_SERVICE_STATUS           CsServiceStatus;
    TAF_PHONE_SERVICE_STATUS           PsServiceStatus;
    TAF_PHONE_CHANGED_SERVICE_STATUS   ServiceStatus;
    TAF_PLMN_LIST_STRU                 PlmnList;
    TAF_PLMN_RESEL_MODE_TYPE           PlmnReselMode;
    VOS_UINT8                          aucReserved1[3];
    TAF_PH_REG_STATE_STRU              CurRegSta;
    TAF_PH_RSSI_STRU                   RssiValue;
    TAF_PH_BATTERYPOWER_STRU           BatteryStatus;
    TAF_PH_PIN_CNF_STRU                PinCnf;
    TAF_PH_USIM_RESPONSE_STRU          UsimAccessData;
    TAF_USIM_STATUS                    SimStatus;
    TAF_PH_ME_LOCK_STATUS              MeLockStatus;
    VOS_UINT8                          aucReserved2[2];
    TAF_PH_PIN_TIMECNF_STRU            PinRemainCnf;
    TAF_PH_ME_PERSONLISATION_CNF_STRU  MePersonalisation;
    TAF_PH_SPN_INFO_STRU               PhSpnInfo;
    TAF_PH_RESTRICTED_ACCESS_CNF_STRU  RestrictedAccess;
    NAS_MM_INFO_IND_STRU               stMmInfo;
    TAF_MMA_CELL_AC_INFO_STRU          stCellAcInfo;
    VOS_UINT32                         ulPrefPlmnNum;
    TAF_DOMAIN_ATTACH_STATE_STRU       stDomainAttachState;

    MN_PH_PREF_PLMN_TYPE_ENUM_U8       ucPrefPlmnType;
    TAF_SYS_SUBMODE_ENUM_UINT8         ucSysSubMode;            /* 系统子模式 */
    VOS_UINT8                          ucRoamStatus;            /* 上报给应用的漫游状态 */
    VOS_UINT8                          ucPlmnMode;

    TAF_CHAR                           strSysCfgBandGroup[TAF_PH_SYSCFG_GROUP_BAND_LEN];

    TAF_PLMN_ID_STRU                   stCurPlmn;                   /* 当前驻留的PLMN信息 */



    VOS_UINT8                          aucCurcRptCfg[TAF_MMA_RPT_CFG_MAX_SIZE];         /* CURC设置的主动上报标识 */
    VOS_UINT8                          aucUnsolicitedRptCfg[TAF_MMA_RPT_CFG_MAX_SIZE];  /* 单个命令设置的主动上报标识 */

    VOS_UINT32                          ulPsInitRslt;                                  /* 协议栈初始化结果 */
}TAF_PHONE_EVENT_INFO_STRU;

#define TAF_SIM_LOCK_MCC_LEN            (3)

/*****************************************************************************
 结构名    : TAF_CUSTOM_CARDLOCK_STATUS_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : en_NV_Item_CardlockStatus NV项对应的结构,
             用于保存SIM LOCK的状态以及剩余解锁次数
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulStatus;            /*是否激活，0不激活，1激活 */
    TAF_OPERATOR_LOCK_STATUS_ENUM_U32   enCardlockStatus;    /**/
    VOS_UINT32                          ulRemainUnlockTimes; /*解锁剩余次数*/
}TAF_CUSTOM_CARDLOCK_STATUS_STRU;


#define EVT_NAS_MMA_NV_CONTEXT   0xaacc          /* PC回放工程NV文件导出消息 */

/*****************************************************************************
 Structure      : NAS_MMA_NV_CONTEXT_ST
 Description    : PC回放工程，NV文件结构
 Message origin :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                             auNvFileName[40];                     /* 文件名最大40个字符*/
    VOS_UINT32                            ulNvFileLen;                          /* 文件长度*/
    VOS_UINT32                            ulPacketLen;                          /* 当前数据报内读取的文件的数据长度*/
    VOS_UINT8                             auNvFileData[4];                      /* 文件内容*/
 }NAS_MMA_NV_CONTEXT_ST;

/*****************************************************************************
 Structure      : NAS_MMA_NV_MSG_ST
 Description    : PC回放工程，NV文件回放消息
 Message origin :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT16                           usMsgID;
    VOS_UINT16                           usReserved;                            /* 在PACK(1)到PACK(4)调整中定义的保留字节 */
    NAS_MMA_NV_CONTEXT_ST                stNVCtxt;                                  /*NV文件*/
}NAS_MMA_NV_MSG_ST;

/*****************************************************************************
结构名     : MN_PH_CSQLVLEXT_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : CSQLVLEX查询操作的结果上报结构
             包括CSQLVLEX查询获取到的信号格数和比特误码率百分比，当前版本不支持BER查询，填99
*******************************************************************************/
typedef struct
{
    MN_PH_CSQLVLEXT_RSSILV_VALUE_ENUM_UINT8   enRssilv;                         /* CSQLVLEX查询获取到的信号格数 */
    MN_PH_CSQLVLEXT_BER_VALUE_ENUM_UINT8      enBer;                            /* 比特误码率百分比，暂时不支持BER查询，填99*/
}MN_PH_CSQLVLEXT_PARA_STRU;

/*****************************************************************************
 结构名    : MN_PH_CSQLVL_PARA_STRU
 结构说明  : CSQLVL查询操作的结果上报结构
             包括RSCP 等级和RSCP 的绝对值
*******************************************************************************/
typedef struct
{
    VOS_UINT16                          usRscp;                                 /* RSCP 等级 */
    VOS_UINT16                          usLevel;                                /* RSCP 的绝对值 */
}MN_PH_CSQLVL_PARA_STRU;


enum AT_CPAM_RAT_PRIO_ENUM
{
    MN_MMA_CPAM_RAT_PRIO_GSM            = 0,                                    /* 接入优先级参数为GSM优先  */
    MN_MMA_CPAM_RAT_PRIO_WCDMA          = 1,                                    /* 接入优先级参数为WCDMA优先 */
    MN_MMA_CPAM_RAT_PRIO_NO_CHANGE      = 2,                                    /* 接入优先级为不改变 */
    MN_MMA_CPAM_RAT_BUTT
};
typedef VOS_UINT8 MN_MMA_CPAM_RAT_PRIO_ENUM_UINT8;
typedef struct
{
    VOS_INT16                           sCpichRscp;
    VOS_INT16                           sCpichEcNo;
    VOS_UINT8                           ucRssi;
    VOS_UINT8                           aucReserve[3];
    VOS_UINT32                          ulCellId;
}MN_MMA_ANQUERY_PARA_STRU;

/*****************************************************************************
结构名    : MN_MMA_CSNR_PARA_STRU
结构说明  : AT+CSNR查询操作的结果上报结构
*******************************************************************************/
typedef struct
{
    VOS_INT16                           sCpichRscp;
    VOS_INT16                           sCpichEcNo;
}MN_MMA_CSNR_PARA_STRU;


typedef struct
{
    VOS_UINT8                           ucPlmnType;
    VOS_UINT8                           aucReserve[1];
    VOS_UINT16                          usPlmnNameLen;
    VOS_UINT8                           aucPlmnName[TAF_PH_OPER_NAME_LONG];
}MN_MMA_CRPN_QRY_REQ_STRU;

#define TAF_PH_CRPN_PLMN_MAX_NUM            (16)            /* AT^CRPN命令最大PLMN个数 */

typedef struct
{
    VOS_UINT8                           ucTotalNum;
    VOS_UINT8                           ucMaxMncLen;
    VOS_UINT8                           aucReserved[2];
    MN_MMA_CRPN_QRY_REQ_STRU            stMnMmaCrpnQry;
    TAF_PH_OPERATOR_NAME_STRU           stOperNameList[TAF_PH_CRPN_PLMN_MAX_NUM];
}MN_MMA_CRPN_QRY_CNF_STRU;


typedef struct
{
    VOS_UINT8                           aucRsv[4];
}MN_MMA_CIPHER_QRY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    AT_APPCTRL_STRU                     stAtAppCtrl;
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucCipherInfo;
    VOS_UINT8                           aucRsv[3];
}MN_MMA_CIPHER_QRY_CNF_STRU;


typedef struct
{
    VOS_UINT8                           aucRsv[4];
}MN_MMA_LOCATION_INFO_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    AT_APPCTRL_STRU                     stAtAppCtrl;
    VOS_UINT32                          ulResult;
    VOS_UINT32                          ulMcc;
    VOS_UINT32                          ulMnc;
    VOS_UINT16                          usLac;
    VOS_UINT8                           ucRac;
    VOS_UINT8                           ucRsv;
    VOS_UINT32                          ulCellid;
}MN_MMA_LOCATION_INFO_CNF_STRU;



typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    AT_APPCTRL_STRU                     stAtAppCtrl;
    VOS_UINT32                          ulResult;
    MN_MMA_CRPN_QRY_CNF_STRU            stMnMmaCrpnQryCnf;
}MN_MMA_CRPN_QRY_CNF_MSG_STRU;



typedef struct
{
    TAF_PH_USIM_SPN_STRU                stSimSpnInfo;
    TAF_PH_USIM_SPN_STRU                stUsimSpnInfo;
}MN_MMA_SPN_PARA_STRU;

/* MM测试命令定义，在此基础上扩展 */
typedef enum
{
    MM_TEST_AT_CMD_MM_STATE             = 0,    /* MM子层状态 */
    MM_TEST_AT_CMD_GMM_STATE            = 1,    /* GMM子层状态 */
    MM_TEST_AT_CMD_GPRS_STATE           = 2,    /* GPRS移动性管理状态 */
    MM_TEST_AT_CMD_MM_REG_STATE         = 3,    /* MM注册状态 */
    MM_TEST_AT_CMD_GMM_REG_STATE        = 4,    /* GMM注册状态 */
    MM_TEST_AT_CMD_PLMN_SEARCH_MODE     = 5,    /* 设定搜网模式, 只更新NV项 */
    MM_TEST_AT_CMD_SET_RAT_MODE         = 6,    /* 设定接入模式, 只更新NV项 */

    MM_TEST_AT_CMD_SET_ADDITIONAL_UPDATE_RESULT_IE = 7,    /* 设定ADDITIONAL_UPDATE_RESULT_IE */
    MM_TEST_AT_CMD_SET_LTE_UE_USAGE_SETTING        = 8,    /* 设定LTE_UE_USAGE_SETTING */

    MM_TEST_AT_CMD_SET_GMM_DEALY_SUSPENDRSP        = 9,    /* 设定gmm延迟回复挂起结果给MMC */

    MM_TEST_AT_CMD_SET_CSFB_HIGH_PRIO_FLG         = 10,

    MM_TEST_AT_CMD_CLEAR_USER_PLMN_                   = 11,

    MM_TEST_AT_CMD_BUTT,
}MM_TEST_AT_CMD_ENUM;
typedef VOS_UINT8 MM_TEST_AT_CMD_ENUM_U8;
enum TAF_MMA_CARD_STATUS_ENUM
{
    TAF_MMA_CARD_STATUS_AVAILABLE      = 0,
    TAF_MMA_CARD_STATUS_NOT_AVAILABLE  = 1,
    TAF_MMA_CARD_STATUS_BUTT
};
typedef VOS_UINT8 TAF_MMA_CARD_STATUS_ENUM_UINT8;


enum TAF_MMA_USIMM_CARD_TYPE_ENUM
{
    TAF_MMA_USIMM_CARD_SIM           = 0,
    TAF_MMA_USIMM_CARD_USIM          = 1,
    TAF_MMA_USIMM_CARD_ROM_SIM       = 2,
    TAF_MMA_USIMM_CARD_ISIM          = 3,             /*ISIM卡*/
    TAF_MMA_USIMM_CARD_NOCARD        = 255,
    TAF_MMA_USIMM_CARD_TYPE_BUTT
};
typedef VOS_UINT32      TAF_MMA_USIMM_CARD_TYPE_ENUM_UINT32;
typedef struct
{
    MM_TEST_AT_CMD_ENUM_U8              ucCmd;
    TAF_UINT8                           ucParaNum;
    TAF_UINT16                          usReserve;
    TAF_UINT32                          aulPara[10];
}MM_TEST_AT_CMD_STRU;


typedef struct
{
    VOS_UINT32                          ulRsltNum;
    VOS_UINT32                          aulRslt[20];
}MM_TEST_AT_RSLT_STRU;



typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    AT_APPCTRL_STRU                     stAtAppCtrl;
    VOS_UINT32                          ulResult;
    MM_TEST_AT_RSLT_STRU                stAtCmdRslt;        /* AT命令执行返回 */
}MN_MM_TEST_CMD_RSP_MSG_STRU;
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;

    VOS_UINT8                           ucOmConnectFlg;                         /* UE与PC工具的连接标志, VOS_TRUE: 已连接; VOS_FALSE: 未连接 */
    VOS_UINT8                           ucOmPcRecurEnableFlg;                   /* OM配置的发送NAS PC回放消息的使能标志 */

    VOS_UINT8                           aucRsv2[2];                             /* 保留   */
}ATMMA_OM_MAINTAIN_INFO_IND_STRU;
typedef struct
{
    VOS_UINT8                           ucLongNameLen;
    VOS_UINT8                           aucLongName[TAF_PH_OPER_NAME_LONG];
    VOS_UINT8                           ucShortNameLen;
    VOS_UINT8                           aucShortName[TAF_PH_OPER_NAME_SHORT];
    VOS_UINT8                           aucReserved[2];                             /* 保留   */
}TAF_MMA_MM_INFO_PLMN_NAME_STRU;
typedef struct
{
    VOS_UINT32                          ulCsSrvExistFlg;                        /* CS业务是否存在标志 */
    VOS_UINT32                          ulPsSrvExistFlg;                        /* PS业务是否存在标志 */
}TAF_USER_SRV_STATE_STRU;



typedef struct
{
    VOS_UINT8                           aucRsv[4];
}TAF_MMA_CERSSI_INFO_QUERY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                  ulMsgName;
    AT_APPCTRL_STRU                             stAtAppCtrl;
    TAF_PH_RSSI_STRU                            stCerssi;                       /* 当前小区信号质量信息 */
    VOS_UINT8                                   ucRslt;                         /* 结果 */
    VOS_UINT8                                   aucReserved[3];
}TAF_MMA_CERSSI_INFO_QUERY_CNF_STRU;





typedef struct
{
    VOS_UINT16                          usFromIndex; /* 查询运营商名称的起始位置 */
    VOS_UINT16                          usPlmnNum;   /* 查询运营商名称的个数，由于A核和C核通讯，消息大小有限制，因此一次最多查询50条记录 */
}TAF_MMA_COPN_INFO_QUERY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    AT_APPCTRL_STRU                     stAtAppCtrl;
    VOS_UINT16                          usPlmnNum;
    VOS_UINT16                          usFromIndex;
    VOS_UINT8                           aucContent[4];
}TAF_MMA_COPN_INFO_QUERY_CNF_STRU;


typedef struct
{
    MN_PH_PREF_PLMN_TYPE_ENUM_U8        enPrefPLMNType;                         /* 查询运营商名称的类型 */
    VOS_UINT8                           aucReserved1[3];
    VOS_UINT32                          ulFromIndex;                            /* 查询运营商名称的起始位置 */
    VOS_UINT32                          ulPlmnNum;                              /* 查询运营商名称的个数，由于A核和C核通讯，消息大小有限制，因此一次最多查询50条记录 */
    VOS_UINT32                          ulValidPlmnNum;                         /* 有效输出的运营商名称个数 */
}TAF_MMA_CPOL_INFO_QUERY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    AT_APPCTRL_STRU                     stAtAppCtrl;
    VOS_UINT32                          ulFromIndex;
    VOS_UINT32                          ulValidPlmnNum;                         /* 有效输出的运营商名称个数 */
    TAF_PLMN_NAME_LIST_STRU             stPlmnName;
}TAF_MMA_CPOL_INFO_QUERY_CNF_STRU;
typedef struct
{
    TAF_SIM_INSERT_STATE_ENUM_UINT32    enSimInsertState;   /* 查询运营商名称的个数，由于A核和C核通讯，消息大小有限制，因此一次最多查询50条记录 */
}TAF_MMA_SIM_INSERT_IND_STRU;
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    AT_APPCTRL_STRU                     stAtAppCtrl;
    VOS_UINT32                          ulResult;
}TAF_MMA_SIM_INSERT_RSP_STRU;


typedef struct
{
    VOS_UINT32                          ulModuleId;         /* 填入PID */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpId;
    VOS_UINT8                           aucReserved[1];
}TAF_MMA_CTRL_STRU;
typedef struct
{
    TAF_PH_MODE                        PhMode;  /* 模式 */
    TAF_PH_RESET_FLG                   PhReset; /* 是否需要重启 */
    VOS_UINT8                          aucReserve[2];
}TAF_MMA_PHONE_MODE_PARA_STRU;


typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_PHONE_MODE_PARA_STRU        stPhoneModePara;
}TAF_MMA_PHONE_MODE_SET_REQ_STRU;



typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_SYS_CFG_PARA_STRU           stSysCfgPara;
}TAF_MMA_SYS_CFG_REQ_STRU;


typedef struct
{
    TAF_MMA_ACQ_REASON_ENUM_UINT8    enAcqReason;
    VOS_UINT8                        aucReserve[3];
}TAF_MMA_ACQ_PARA_STRU;


typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_ACQ_PARA_STRU               stAcqPara;
}TAF_MMA_ACQ_REQ_STRU;


typedef struct
{
    VOS_UINT16                          usArfcn;
    VOS_UINT8                           ucPlmnNum;
    VOS_UINT8                           ucCellNum;
    TAF_PLMN_ID_STRU                    astPlmnId[TAF_MMA_REG_MAX_PLMN_NUM];
    VOS_UINT16                          ausCellId[TAF_MMA_REG_MAX_CELL_NUM];
}TAF_MMA_REG_CELL_INFO_STRU;


typedef struct
{
    VOS_UINT32                                    bitOpPrioClass       : 1;
    VOS_UINT32                                    bitOpEpsAttachReason : 1;
    VOS_UINT32                                    bitOpCellInfo        : 1;
    VOS_UINT32                                    bitSpare             : 29;
    TAF_MMA_PLMN_PRIORITY_CLASS_ENUM_UINT8        enPrioClass;
    TAF_MMA_EPS_ATTACH_REASON_ENUM_UINT8          enEpsAttachReason;
    TAF_PH_SERVICE_DOMAIN                         ucAttachDomain;               /* 服务域，0：CS ONLY; 1:PS ONLY; 2:CS_PS; 3:any等同于CS ONLY；4：不改变服务域；*/
    VOS_UINT8                                     aucReserve[1];
    TAF_MMA_REG_CELL_INFO_STRU                    stCellInfo;
}TAF_MMA_REG_PARA_STRU;
typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_REG_PARA_STRU               stRegPara;
}TAF_MMA_REG_REQ_STRU;


typedef struct
{
    VOS_UINT8                           aucReserve[4];
}TAF_MMA_POWER_SAVE_PARA_STRU;


typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_POWER_SAVE_PARA_STRU        stPowerSavePara;
}TAF_MMA_POWER_SAVE_REQ_STRU;


typedef struct
{
    TAF_MMA_DETACH_CAUSE_ENUM_UINT8     enDetachCause;
    TAF_PH_SERVICE_DOMAIN               ucDetachDomain;                         /* 服务域，0：CS ONLY; 1:PS ONLY; 2:CS_PS; 3:any等同于CS ONLY；4：不改变服务域；*/
    VOS_UINT8                           aucReserve[2];
}TAF_MMA_DETACH_PARA_STRU;
typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_DETACH_PARA_STRU            stDetachPara;
}TAF_MMA_DETACH_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_IMS_SWITCH_SET_ENUM_UINT8   enImsSwitch;
    VOS_UINT8                           aucReserved[3];
}TAF_MMA_IMS_SWITCH_SET_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    VOS_UINT8                           aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32 enResult;
    TAF_ERROR_CODE_ENUM_UINT32          enErrorCause;
}TAF_MMA_IMS_SWITCH_SET_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
}TAF_MMA_IMS_SWITCH_QRY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    TAF_MMA_IMS_SWITCH_SET_ENUM_UINT8   enImsSwitch;
}TAF_MMA_IMS_SWITCH_QRY_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
    TAF_MMA_VOICE_DOMAIN_ENUM_UINT32    enVoiceDomain;
}TAF_MMA_VOICE_DOMAIN_SET_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    VOS_UINT8                           aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32 enResult;
    TAF_ERROR_CODE_ENUM_UINT32          enErrorCause;
}TAF_MMA_VOICE_DOMAIN_SET_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    TAF_MMA_MSG_TYPE_ENUM_UINT32        ulMsgName;
    TAF_MMA_CTRL_STRU                   stCtrl;
}TAF_MMA_VOICE_DOMAIN_QRY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    TAF_MMA_VOICE_DOMAIN_ENUM_UINT32    enVoiceDomain;
}TAF_MMA_VOICE_DOMAIN_QRY_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    TAF_PH_MODE                         ucPhMode;  /* 模式 */
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32 enRslt;
    TAF_ERROR_CODE_ENUM_UINT32          enErrorCause;
}TAF_MMA_PHONE_MODE_SET_CNF_STRU;
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    VOS_UINT8                           aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32 enRslt;
    TAF_ERROR_CODE_ENUM_UINT32          enErrorCause;
}TAF_MMA_SYS_CFG_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                   ulMsgName;
    VOS_UINT16                                   usClientId;
    VOS_UINT8                                    ucOpid;
    VOS_UINT8                                    aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32          enRslt;
    TAF_PLMN_ID_STRU                             stPlmnId;
    VOS_UINT16                                   usArfcn;
    TAF_MMA_PLMN_PRIORITY_CLASS_ENUM_UINT8       enPrioClass;
    VOS_UINT8                                    aucReserve2[1];
}TAF_MMA_ACQ_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                   ulMsgName;
    VOS_UINT16                                   usClientId;
    VOS_UINT8                                    ucOpid;
    VOS_UINT8                                    aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32          enRslt;
    TAF_PLMN_ID_STRU                             stPlmnId;
    VOS_UINT16                                   usArfcn;
    TAF_MMA_PLMN_PRIORITY_CLASS_ENUM_UINT8       enPrioClass;
    VOS_UINT8                                    aucReserve2[1];
}TAF_MMA_REG_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    VOS_UINT8                           aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32 enRslt;
}TAF_MMA_POWER_SAVE_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                    ulMsgName;
    VOS_UINT16                                    usClientId;
    VOS_UINT8                                     ucOpid;
    VOS_UINT8                                     aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32           enRslt;
    TAF_PLMN_ID_STRU                              stPlmnId;
    VOS_UINT16                                    usArfcn;
    TAF_MMA_PLMN_PRIORITY_CLASS_ENUM_UINT8        enPrioClass;
    VOS_UINT8                                     aucReserve2[1];
}TAF_MMA_ACQ_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    VOS_UINT8                           aucReserve[1];
    TAF_MMA_APP_OPER_RESULT_ENUM_UINT32 enRslt;
    TAF_ERROR_CODE_ENUM_UINT32          enErrorCause;
}TAF_MMA_DETACH_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucOpid;
    VOS_UINT8                           aucReserve[1];
    TAF_PHONE_SERVICE_STATUS            CsSrvSta; /*CS服务状态*/
    TAF_PHONE_SERVICE_STATUS            PsSrvSta; /*PS服务状态*/
    VOS_UINT8                           ucCsSimValid; /* CS卡是否有效，VOS_TRUE:有效，VOS_FALSE:无效 */
    VOS_UINT8                           ucPsSimValid; /* PS卡是否有效，VOS_TRUE:有效，VOS_FALSE:无效 */
}TAF_MMA_SERVICE_STATUS_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                    ulMsgName;
    VOS_UINT16                                    usClientId;
    VOS_UINT8                                     ucOpid;
    VOS_UINT8                                     aucReserve[1];
    TAF_PLMN_ID_STRU                              stPlmnId;
    VOS_UINT16                                    usArfcn;
    TAF_MMA_PLMN_PRIORITY_CLASS_ENUM_UINT8        enPrioClass;
    VOS_UINT8                                     aucReserve2[1];
}TAF_MMA_SYS_INFO_IND_STRU;




typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                    ulMsgName;
    VOS_UINT16                                    usClientId;
    VOS_UINT8                                     ucOpid;
    TAF_MMA_CARD_STATUS_ENUM_UINT8                enCardStatus;                   /* 卡状态*/
    TAF_MMA_USIMM_CARD_TYPE_ENUM_UINT32           enCardType;                     /* 卡类型:SIM、USIM、ROM-SIM  */
}TAF_MMA_SIM_STATUS_IND_STRU;




typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT8                           ucImsCallFlg;
    VOS_UINT8                           aucReserve[3];
}TAF_MMA_IMS_SRV_INFO_NOTIFY_STRU;

TAF_UINT32 Taf_DefPhClassType(MN_CLIENT_ID_T        ClientId,
                                      MN_OPERATION_ID_T     OpId,
                                      TAF_PH_MS_CLASS_TYPE  MsClass);

TAF_UINT32 Taf_PhoneAttach(MN_CLIENT_ID_T        ClientId,
                                  MN_OPERATION_ID_T    OpId,
                                  TAF_PH_ATTACH_TYPE   AttachType);
TAF_UINT32 Taf_PhonePinHandle(MN_CLIENT_ID_T      ClientId,
                                      MN_OPERATION_ID_T   OpId,
                                      TAF_PH_PIN_DATA_STRU *pPinData);
TAF_UINT32 Taf_PhonePlmnList(MN_CLIENT_ID_T               ClientId,
                                     MN_OPERATION_ID_T            OpId,
                                     TAF_AVAIL_PLMN_LIST_TYPE      ListType);
TAF_UINT32 Taf_PhonePlmnResel(MN_CLIENT_ID_T                ClientId,
                                       MN_OPERATION_ID_T             OpId,
                                       TAF_PLMN_RESEL_MODE_TYPE      ReselType);
TAF_UINT32 Taf_PhoneStartInfoInd(MN_CLIENT_ID_T             ClientId,
                                        MN_OPERATION_ID_T          OpId,
                                        TAF_START_INFO_IND_STRU    StartInfoInd);
TAF_UINT32 TAF_DefQuickStart(MN_CLIENT_ID_T         ClientId,
                                    MN_OPERATION_ID_T       OpId,
                                    TAF_UINT32              ulSetValue);
TAF_UINT32 Taf_DefPhAutoAttach(MN_CLIENT_ID_T       ClientId,
                                       MN_OPERATION_ID_T    OpId,
                                       TAF_UINT32           ulSetValue);
TAF_UINT32 Taf_FplmnHandle(MN_CLIENT_ID_T            ClientId,
                                  MN_OPERATION_ID_T         OpId,
                                  TAF_PH_FPLMN_OPERATE_STRU stFplmnOperate);

VOS_UINT32 Taf_SysCfgHandle(MN_CLIENT_ID_T        ClientId,MN_OPERATION_ID_T  OpId,
                         TAF_MMA_SYS_CFG_PARA_STRU    stSysCfg);

VOS_UINT32 Taf_NetScanHandle(
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId,
    TAF_MMA_NET_SCAN_REQ_STRU          *pstNetScan
);

VOS_UINT32 Taf_AbortNetScan (
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId
);

TAF_UINT32 TAF_DefLoadDefault(MN_CLIENT_ID_T ClientId, MN_OPERATION_ID_T   OpId);
VOS_BOOL Taf_IsWBandSupported(VOS_UINT16 usBandNo);

TAF_UINT32  Taf_DefGetSPN(TAF_UINT8 ucSpnType, TAF_PH_USIM_SPN_STRU   *pstAtSPNRslt);

VOS_VOID  Taf_GetSyscfgBandGroupStr(TAF_PH_SYSCFG_BAND_STR* pstSysCfgBandStr);


VOS_VOID  MN_MMA_GetSyscfgExLteBandGroupStr(
    TAF_PH_SYSCFG_BAND_STR             *pstSysCfgBandStr
);


TAF_UINT32  Taf_QueryCSNR(TAF_INT16 *psCpichRscp,TAF_INT16 *psCpichEcNo);

TAF_UINT32  Taf_DefGetCardMode(TAF_UINT8 *pucCardMode);

TAF_UINT32 Taf_UsimRestrictedAccessCommand(
                                MN_CLIENT_ID_T               ClientId,
                                MN_OPERATION_ID_T            OpId,
                                TAF_SIM_RESTRIC_ACCESS_STRU *pPara);

TAF_UINT32 Taf_PhoneGetNetworkNameForListPlmn( TAF_PH_OPERATOR_NAME_FORMAT_OP_STRU *pstOperName );
TAF_UINT32 Taf_PhoneGetOperNameInfo( TAF_PH_OPERATOR_NAME_FORMAT_OP_STRU *pstOperName );
TAF_UINT32 Taf_MePersonalisationHandle(
                            MN_CLIENT_ID_T                    ClientId,
                            MN_OPERATION_ID_T                 OpId,
                            TAF_ME_PERSONALISATION_DATA_STRU *pMePersonalData);

TAF_UINT32 Taf_DefPhMode(MN_CLIENT_ID_T          ClientId,
                                MN_OPERATION_ID_T       OpId,
                                TAF_PH_OP_MODE_STRU     PhModeSet);
VOS_VOID   Taf_GetProductionID(VOS_CHAR *pcDest);


TAF_UINT32  TAF_SetPrefPlmnType(
    MN_PH_PREF_PLMN_TYPE_ENUM_U8        enPrefPlmnType
);


TAF_UINT32 TAF_QryUsimInfo(
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId,
    TAF_PH_QRY_USIM_INFO_STRU           *pstInfo
);

TAF_BOOL TAF_IsNormalSrvStatus(VOS_VOID);

TAF_UINT32 TAF_QryCpnnInfo(
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId,
    TAF_PH_ICC_TYPE                     IccType
);

VOS_UINT32 MN_PH_RptCostTime( VOS_VOID  );


VOS_UINT8 APP_MN_PH_AppQryPhMode (VOS_VOID);

VOS_UINT8 MN_MMA_GetServiceDomain(VOS_VOID);

TAF_UINT32  Taf_DefMmTestPara(TAF_VOID *pInput,TAF_VOID *pRslt);


VOS_UINT32 TAF_PhonePlmnUserSel(
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId,
    TAF_PLMN_USER_SEL_STRU             *pstPlmnUserSel
);


VOS_UINT32  MN_FillAndSndAppReqMsg(
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId,
    VOS_UINT16                          usMsgType,
    VOS_VOID                            *pPara,
    VOS_UINT32                          ulParaLen,
    VOS_UINT32                          ulReceiverPid
);

TAF_UINT32 Taf_GetCurrentAttachStatus(TAF_PH_CS_STATUS    *pCsResult,
                                                TAF_PH_PS_STATUS    *pPsResult );


TAF_UINT32 Taf_ParaQuery(
    MN_CLIENT_ID_T              ClientId,
    MN_OPERATION_ID_T           OpId,
    TAF_PARA_TYPE               ParaType,
    TAF_VOID                   *pPara
);

TAF_UINT32 Taf_PrefPlmnHandle (
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId,
    TAF_PH_PREF_PLMN_OPERATE_STRU       *pstPrefPlmnOperate
);


VOS_UINT32 TAF_AbortPlmnListReq(
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId
);





VOS_UINT32 Taf_SetEOPlmnHandle(
    MN_CLIENT_ID_T                      ClientId,
    MN_OPERATION_ID_T                   OpId,
    TAF_MMA_SET_EOPLMN_LIST_STRU       *pstEOPlmnCfg
);

VOS_UINT32 TAF_MMA_PhoneModeSetReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_PHONE_MODE_PARA_STRU       *pstPhoneModePara
);

VOS_UINT32 TAF_MMA_SetSysCfgReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_SYS_CFG_PARA_STRU          *pstSysCfgPara
);

VOS_UINT32 TAF_MMA_AcqBestNetworkReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_ACQ_PARA_STRU              *pstAcqPara
);

VOS_UINT32 TAF_MMA_RegReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_REG_PARA_STRU              *pstRegPara
);

VOS_UINT32 TAF_MMA_PowerSaveReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_POWER_SAVE_PARA_STRU       *pstPowerSavePara
);

VOS_UINT32 TAF_MMA_DetachReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_DETACH_PARA_STRU           *pstDetachPara
);


/* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, Begin */
#if (FEATURE_ON == FEATURE_IMS)
VOS_UINT32 TAF_MMA_SetImsSwitchReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_IMS_SWITCH_SET_ENUM_UINT8   enImsSwitch
);

VOS_UINT32 TAF_MMA_QryImsSwitchReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

VOS_UINT32 TAF_MMA_SetVoiceDomainReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_MMA_VOICE_DOMAIN_ENUM_UINT32    enVoiceDomain
);

VOS_UINT32 TAF_MMA_QryVoiceDomainReq(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);
#endif
/* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, End */

#if ((TAF_OS_VER == TAF_WIN32) || (TAF_OS_VER == TAF_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of TafAppMma.h */
