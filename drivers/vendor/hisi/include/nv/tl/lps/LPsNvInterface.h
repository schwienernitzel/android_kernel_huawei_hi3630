

#ifndef __LPSNVINTERFACE_H__
#define __LPSNVINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include  "vos.h"
#include  "PsTypeDef.h"
#include  "LNvCommon.h"
#include  "RrcNvInterface.h"
#include  "LNasNvInterface.h"
#if (VOS_OS_VER != VOS_WIN32)
#include  "msp.h"
#endif
#pragma pack(4)

/*****************************************************************************
  2 macro
*****************************************************************************/
/* NV操作函数 */
/*
ERR_MSP_NO_INITILIZATION   3              模块初始化失败，无法执行接口操作
ERR_MSP_NO_INITILIZATION   502            参数错误
ERR_MSP_NV_NOT_SUPPORT_ID  520            该ID不存在
ERR_MSP_NV_ERROR_READ      521            读flash失败
ERR_MSP_NV_ITEM_IS_EMPTY   1100           该项数据长度为零
*/
#define LPs_NvimItem_Read( ulId, pItemData, usItemDataLen ) \
        NVM_Read( ulId, (VOS_VOID *)pItemData, usItemDataLen)

/*
ERR_MSP_NO_INITILIZATION             3              模块初始化失败，无法执行接口操作
ERR_MSP_NO_INITILIZATION             502            参数错误
ERR_MSP_NV_NOT_SUPPORT_ID            520            该ID不存在（按照要求该接口中不支持添加ID的操作）
ERR_MSP_NV_NOT_SUPPORT_LENTH         522            长度不支持
ERR_MSP_NV_ERROR_WRITE               524            写flash失败
ERR_MSP_NV_FLASH_FULL                1103           flash空间被写满
ERR_MSP_NVIM_NOT_SUPPORT_WRITE       2007           系统模式不允许修改该项
*/
#define LPs_NvimItem_Write( ulId, pItemData, usItemDataLen)\
       NVM_Write( ulId, (VOS_VOID *)pItemData, usItemDataLen)

#define LPs_FactNvim_Write(ulId, pItemData, usDataLen)\
        NVIM_WriteFactoryForce(ulId, (VOS_VOID *)pItemData, usDataLen)

/* GCF开关组,位域功能 */
#define LPS_NV_GET_TAU_CIPHERED_BIT         ( 0x00000001 )
#define LPS_NV_LOCK_BAND_FREQ_CELL_IN_TEST_MODE_FUNC_BIT     (0x00000001)

#define LPS_NV_DL_CTRL_PDU_NOTIFY_BIT          (0x00000002)

/*added by lishangfeng 20130320 begin*/
#define LPS_NV_SEARCHING_OPTIMIZE_FUN_BIT    (0x00000004)
/*added by lishangfeng 20130320 end*/

#define LPS_NV_GET_MSG4_OLDCR_BIT           ( 0x00000002 )

/* GCF是否支持24.301 Table D.1.1中建链原因设置，位域开关 */
#define LPS_NV_GET_EST_CAUSE_BIT             ( 0x00000004 )

/* 指示安全功能是否支持测试模式,位域功能 */
#define LPS_NV_GET_SUPPORT_SMC_TEST_MODE_BIT  ( 0x00000008 )

/* GCF打桩通过CDRX相关用例，实际场景为了降功耗不打开该开关，位域开关 */
#define LPS_NV_GET_CDRX_L2_TIMER_BIT         ( 0x00000010 )

/* PS功能开关组,位域功能 */
#define LPS_NV_GET_SUPPORT_BAND64_BIT       ( 0x00000001 )

/* PS功能开关组,删除SDF是否携带Qos 位域 */
/* 删除SDF时是否携带Qos信息功能开关，0为关闭，1为打开。默认为关闭 */
#define LPS_NV_GET_DEL_SDF_WITH_QOS_BIT       ( 0x00000002 )

/* 是否进行连接态收到本ue的业务寻呼后进行释放, 缺省0 表示进行释放,  4表示不进行释放 */
#define LPS_NV_GET_CONN_RCV_PAGING_TO_RELASE_BIT       ( 0x00000004 )

/* PS功能开关组,是否支持安全能力比较位域 */
#define LPS_NV_GET_SECU_CAP_MACTCH_BIT         ( 0x00000008 )

/* PS功能开关组,是否支持安全激活场景下处理明文拒绝NAS消息标识 */
#define LPS_NV_GET_NAS_PLAIN_REJ_MSG_FLAG_BIT  (0x00001000)

/* PS功能开关组,规避兰州CSFB中兴核心网BUG的NV开关标识 */
#define LPS_NV_GET_NAS_CSFB_TAU_TYPE2_FLAG_BIT  (0x00002000)

/* PS功能开关组,是否支持软件KDF算法位域 */
#define LPS_NV_GET_HARD_KDF_BIT         ( 0x00000010 )
#define LPS_NV_GET_HARD_KDF_HYBRI_BIT   ( 0x00000020 )
#define LPS_NV_GET_ULDRB_DISCARD_BIT    ( 0x00000040 )

/* 信令面时延优化开关， 0x00000080表示打开，0表示关闭 */
#define PS_NV_TIME_DELAY_SWITCH_BIT     ( 0x00000080 )

/* 信令面时延优化开关， 0x00000100表示打开，0表示关闭 */
#define PS_NV_TIME_DELAY_HOOK_SWITCH_BIT     ( 0x00000100 )

/* MBMS　开关 */
#define LPS_NV_GET_MBMS_SUPPORT_BIT         ( 0x00000200 )

/* 软银Bandwidth需求开关 */
#define LPS_NV_GET_BANDWIDTH_SUPPORT_BIT         ( 0x00000400 )

/* modify by lishangfeng freq all begin */
#define LPS_NV_GET_FREQ_IN_ALL_BANDWITH_SUPPORT_BIT ( 0x00000800 )
/* modify by lishangfeng freq all end */
/* 重建开关 */
#define LPS_NV_GET_REST_STUB_SUPPORT_BIT         ( 0x00001000 )

/* sunjitan DCM定制需求 GU到L的切换不判断被禁TA开关 */
#define LPS_NV_GET_GU2L_HO_IGNORE_FORBID_TA_BIT     ( 0x00002000 )

/* gaojishan-ETWS-Begin */
#define LPS_NV_ETWS_SUPPORT_BIT         ( 0x00004000 )
#define LPS_NV_CMAS_SUPPORT_BIT         ( 0x00008000 )
/* gaojishan-ETWS-End */
/* gaojishan-SYSCFG-SAVENV-Begin */
#define LPS_NV_GET_JP_UBand1_Record_SUPPORT_BIT         ( 0x00010000 )
/* gaojishan-SYSCFG-SAVENV-End */

/* L重建UTRA-FDD搜网开关 */
#define LPS_NV_GET_L_REEST_CELL_SRCH_UTRA_FDD_BIT         ( 0x00020000 )

/* L重建GSM搜网开关 */
#define LPS_NV_GET_L_REEST_CELL_SRCH_GSM_BIT         ( 0x00040000 )

/* 小区搜索到小区，但是无法接收或者部分接收到系统信息时,用于判断否需要bar小区 */
#define LPS_NV_GET_CELL_SRCH_CELL_BAR_BIT         ( 0x00080000 )

/* gaojishan-nccpermit */
#define LPS_NV_NCC_PERMIT_BIT         ( 0x00100000 )

/* bgs begin */
/* L背景搜功能是否支持开关 */
#define LPS_NV_GET_L_BGS_SUPPORT_BIT                 ( 0x00200000 )
/* bgs end */

#define LPS_NV_TCP_OPT_BIT            ( 0x00800000 )


/* gaojishan-reest-measGap*/
#define LPS_NV_GET_REEST_MEAS_GAP_SETUP_BIT            ( 0x00400000 )

/* gaojishan-SoftBank-定制标志:true,set Band41 range */
#define LPS_NV_SOFT_BANK_FLAG_BIT            ( 0x01000000 )

/* gaojishan-nccpermit-2 */
#define LPS_NV_NO_IDLE_NCC_PERMIT_BIT        ( 0x02000000 )

/* gaojishan-dcom-resel-cfg */
#define LPS_NV_JP_DCOM_USE_R8_BIT        ( 0x04000000 )

/* gaojishan-dcom-resel-cfg */
#define LPS_NV_JP_DCOM_CON_TO_IDLE_BIT        ( 0x08000000 )

/* gaojishan-dcom-resel-cfg */
#define LPS_NV_JP_DCOM_REL_OFFSET_BIT        ( 0x10000000 )
#define LPS_NV_JP_DCOM_REL_OFFSET_DEBUG_BIT  ( 0x20000000 )
/* gaojishan-fast-dorm-cfg */
#define LPS_NV_JP_DCOM_FAST_DORM_BIT  ( 0x40000000 )

/* add by lishangfeng for RRM 5.2.1 test begin */
#define LPS_NV_RRM_LTE_521_BIT  ( 0x80000000 )
/* add by lishangfeng for RRM 5.2.1 test end */

/* gaojishan-CMAS-Begin */
#define LPS_NV_CMAS_REPT_BEFORE_CAMP_SUCC_BIT    (0x00000008 )
/* gaojishan-CMAS-End */

/* v7r2 ca begin */
/* CA特性是否打开，1为打开，0为关闭 */
#define LPS_NV_CA_SUPPORT_BIT  ( 0x00000001 )
/* v7r2 ca end */


/* lwurc 频段限制指示开关 */
#define LPS_NV_LWURC_BAND_LIMIT_FLG_BIT            (0x00000020)

/* 启动背景搜，但是只搜索L单模，搜索完毕后回复LMM搜索结果，不再搜索 GU 模 */
#define LPS_NV_GET_L_BGS_L_SUPPORT_BIT            (0x00000040)

/* modify by lishangfeng 20131212 begin */
#define LPS_NV_SND_ETWS_IMIDIEATELY_BIT           (0x00000080)                  /* 0x80表示为立即发送；0x00表示收齐后再发送 */
/* modify by lishangfeng 20131212 end */

#define LPS_NV_L2_TLEVENT_REPORT_BIT           (0x00000100)                  /* TL L2事件上报*/
#define LPS_NV_L2_LTEPRINT_REPORT_BIT           (0x00000200)                  /* LTE L2 打印信息上报*/
#define LPS_NV_RRC_LIST_SEARCH_TWICE_BIT           (0x00000400)                  /* LTE 控制LIST搜网先验频点搜索两次开关*/
#define LPS_NV_RRC_BACKTOLTE_REDRECTFAIL_BIT        (0x00000800)
#define LPS_NV_L2_CACELLINFO_REPORT_BIT          (0x00002000)                  /*CA SCELL状态信息上报*/

#define LPS_NV_GET_INTRA_HO_IGNORE_FORBID_TA_BIT    (0x00008000)                /* 本系统切换不判断被禁TA开关 */
#define LPS_NV_GET_SSC_SUPPORT_BIT                (0x00000001)
#define LPS_NV_GET_ADRX_SUPPORT_BIT               (0x00000002)
#define LPS_NV_GET_PTMSI_TAU_ACTIVE_FLAG_SUPPORT_BIT (0x00000020)
/* niuxiufan rrc release modify begin */
#define LPS_NV_GET_NOT_TRY_FAKE_CELL_FLAG_BIT     (0x00000004)
/* niuxiufan rrc release modify end */

/*TDS DSP 自检地址*/
#define ADDR_SELF_ADJUST_PARA       (0x1300F840)


/* GCF开关组 */
#define  LPS_NV_GET_GCF_FLAG(ucIndex, ulFlag) \
         (g_aulGcfFlg[ucIndex]&(ulFlag))

/* PS功能开关组 */
#define  LPS_NV_GET_PS_FUN_FLAG(ucIndex, ulFlag) \
         (g_aulPsFunFlg[ucIndex]&(ulFlag))

#define  LPS_NV_SUPPORT_BAND64                1     /* 支持Band64频段 */
#define  LPS_NV_NOT_SUPPORT_BAND64            0     /* 不支持Band64频段 */
#define LPS_NV_CONN_RCV_PAGING_RELASE  0          /* 收到业务寻呼进行释放 */
#define LPS_NV_CONN_RCV_PAGING_NO_RELASE  LPS_NV_GET_CONN_RCV_PAGING_TO_RELASE_BIT   /* 收到业务寻呼不进行释放 */

#define LPS_NV_GET_HARD_KDF_OFF        0                        /* 不支持硬件KDF算法 */
#define LPS_NV_GET_HARD_KDF_ON         LPS_NV_GET_HARD_KDF_BIT  /* 支持硬件KDF算法 */


#define LPS_NV_GET_HARD_KDF_HYBRI_OFF        0                              /* 不使用两次混合计算的KDF算法 */
#define LPS_NV_GET_HARD_KDF_HYBRI_ON         LPS_NV_GET_HARD_KDF_HYBRI_BIT  /* 使用两次混合计算的KDF算法 */


/* PS功能开关宏定义 */
#define LPS_FUNC_SW_ON                       (1)
#define LPS_FUNC_SW_OFF                      (0)
/*add for DTS20120922*/

/*打印全局变量的最大个数*/
#define MAX_GLOBAL_PRANT_NUM   5
/*add for DTS20120922*/

/* TPS 开关组 */
#define  TPS_NV_GET_FLAG(uVlaue, ulFlag) \
         (uVlaue&(ulFlag))
#define TPS_NV_OP_HL1_SCHEDULE_IND_FLITER_BIT            ( 0x00000001 )
#define TPS_NV_OP_T_RRC_trafficMeasPeriod_FLITER_BIT            ( 0x00000002 )
#define TPS_NV_Print_FLITER_BIT            ( 0x00000004 )
/*CELLUPDATE MODEFIED BEGIN*/
#define TPS_NV_OP_Cellupdate_stub_BIT            ( 0x00000001 )
/*CELLUPDATE MODEFIED END*/
/* Cell-Reselection optimazation in CELL-FACH when Srx/SNR are lower than the thresholds*/
#define TPS_NV_CELL_RESEL_FOR_CELLFACH_GET_BIT      ( 0x00002000 )
#define TPS_NV_SMC_STUB_BIT                 ( 0x00000400 )

#define TPS_NV_CS_TL_MEAS_EVA_CLOSE_BIT                 ( 0x00000800 )

#define TPS_NV_OP_NEWKEY_GET_BIT            ( 0x00000008 )

#define TPS_NV_OP_TCP_ACK_DIS_GET_BIT       ( 0x00000010 )


/*DETECT CELL MODIFIY BEGIN*/
#define TPS_NV_OP_DETECT_CELL_GET_BIT       (0x00000020)
/*DETECT CELL MODIFIY END*/

#define TPS_NV_OP_MEASCONTROL_GET_BIT       (0x00000040)

#define TPS_NV_OP_RlcUmDataInd_GET_BIT       (0x00000080)


#define TPS_NV_OP_Debug_Info_BIT            ( 0x00000002 )

#define TPS_NV_OP_Debug_State_BIT            ( 0x00000004 )


#define TPS_NV_GCF_CS_LOOP_BIT            ( 0x00000001 )

#define TPS_NV_GCF_DRXEXTRA_CONTROL_BIT            ( 0x00000002 )

/*准FR特性begin*/
#define TPS_NV_OP_GSM_FR_BIT           ( 0x00000004 )
/*准FR特性end*/
/*TG 重选优化begin*/
#define TPS_NV_GCF_SIRAT_BIT           ( 0x00000008 )
#define TPS_NV_GCF_QRXLEVMIN_BIT        (0x00000010)
#define TPS_NV_GCF_S_UNSATISFIED_BIT    (0x00000020)
#define TPS_NV_T2G_IRAT_REPORT_BIT      (0x00000040)
/*TG 重选优化end*/

#define TPS_NV_GCF_RRM_STUB_BIT         (0x00000080)
/* niuxiufan taiwan modify begin */
#define LRRC_IRAT_REDIR_NOT_BANDSCAN_BIT (0x00000008)
/* niuxiufan taiwan modify end */

/* LTE PS Transfer begin */
#define LRRC_MTC_THRESHOLD_MIN_VALUE      (0)
#define LRRC_MTC_THRESHOLD_MAX_VALUE      (31 * 2 * 8)
/* LTE PS Transfer end */

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/
/*开关枚举*/
enum RRC_NV_SWITCH_ENUM
{
    RRC_SWITCH_OFF = 0,
    RRC_SWITCH_ON  = 1
};

typedef VOS_UINT32   RRC_NV_SWITCH_ENUM_UINT32;

/* sib定时器选择开关枚举*/
enum RRC_NV_TIMER_CHOICE_ENUM
{
    RRC_TIMER_CHOICE_DEFAULT = 0,           /* 默认选择 */
    RRC_TIMER_CHOICE_DT  = 1,               /* 德电需求选择 */
    RRC_TIMER_CHOICE_BUTT
};
typedef VOS_UINT32   RRC_NV_TIMER_CHOICE_ENUM_UINT32;

enum RRC_PHY_LTE_RF_HW_ENUM
{
    RRC_PHY_LTE_RF_HW_BAND7_38_40         = 0,  /* Band7/38/40多频带扣板*/
    RRC_PHY_LTE_RF_HW_BAND20,                   /* Band20单频带扣板*/
    RRC_PHY_LTE_RF_HW_USB_STICK_VB,             /* USB STICK的vb硬件单板 */
    RRC_PHY_LTE_RF_HW_SOFTBANK_BAND64,          /* 软银使用的Band64扣板 */
    RRC_PHY_LTE_RF_HW_USB_STICK_VC,             /* USB STICK的vC硬件单板 */
    RRC_PHY_LTE_RF_HW_USB_STICK_VD,             /* USB STICK的vD硬件单板 */
    RRC_PHY_LTE_RF_HW_USB_STICK_VE,             /* USB STICK的vE硬件单板 */
    RRC_PHY_LTE_RF_HW_USB_STICK_VF,             /* USB STICK的vF硬件单板 */
    RRC_PHY_LTE_RF_HW_USB_STICK_VG,             /* USB STICK的vG硬件单板 */
    RRC_PHY_LTE_RF_HW_USB_STICK_VH,             /* USB STICK的vH硬件单板 */
    RRC_PHY_LTE_RF_HW_BUTT
};
typedef VOS_UINT8 RRC_PHY_LTE_RF_HW_ENUM_UINT8;
/*NV项枚举*/
/* gaojishan-PLMN_EXACTLY_COMPARE_FLG */
#ifdef PS_ITT_PC_TEST2
#define en_NV_Item_PLMN_EXACTLY_COMPARE_FLG   (9106)
#endif
/*****************************************************************************
 枚举名    : PS_NV_INDEX_ENUM
 枚举说明  : 用于索引不同band下的相同的NV项
*****************************************************************************/
enum PS_NV_INDEX_ENUM
{
    NV_IDX_AGC_PARA                     = 0 ,

    NV_IDX_MODEM_LOSS,
    NV_IDX_TEMP_SENSOR,
    NV_IDX_RX_CAL_FREQ_LIST,
    NV_IDX_RX_NOBLK_AGC_FREQ_COMP_ANT1,
    NV_IDX_RX_NOBLK_AGC_FREQ_COMP_ANT2,
    NV_IDX_RX_BLK_AGC_FREQ_COMP_ANT1,
    NV_IDX_RX_BLK_AGC_FREQ_COMP_ANT2,
    NV_IDX_RX_TEMP_COMP,
    NV_IDX_RX_IP2_CAL_FREQ_LIST,
    NV_IDX_RX_IP2_CAL_THRESHOLD,
    /*NV_IDX_RX_IP2_CAL,*/
    NV_IDX_TX_APC_GAIN_THRESHOLD,
    /*NV_IDX_APC_ATT_TABLE_STRU,*/
    NV_IDX_TX_CAL_FREQ_LIST,
    NV_IDX_TX_PA_POWER,
    NV_IDX_TX_CAL_HIGHGAIN_POWER,
    NV_IDX_TX_CAL_MIDGAIN_POWER,
    NV_IDX_TX_CAL_LOWGAIN_POWER,
    NV_IDX_TX_APC_HIGHGAIN_FREQ_COMP,
    NV_IDX_TX_APC_MIDGAIN_FREQ_COMP,
    NV_IDX_TX_APC_LOWGAIN_FREQ_COMP,
    NV_IDX_TX_APC_TEMP_COMP,
    NV_IDX_TX_APT_PARA,
    NV_IDX_TX_APT_PDM_HIGH_TBL,
    NV_IDX_TX_APT_PDM_MID_TBL,
    NV_IDX_TX_APT_PDM_LOW_TBL,
    NV_IDX_TX_APT_PDM_MC_COMP_HIGH_TBL,
    NV_IDX_TX_APT_PDM_MC_COMP_MID_TBL,
    NV_IDX_TX_APT_PDM_MC_COMP_LOW_TBL,
    /* add by lishangfneg mpr begin */
    NV_IDX_TX_MPR,
    /* add by lishangfneg mpr end */
    NV_IDX_ANT_SAR,
    /*add by chenhongqiang begin*/
    NV_IDX_LTE_TX_ATTEN,
    /*add by chenhongqiang end*/

    NV_IDX_TX_AMPR,

    NV_IDX_LTE_TX_DIVERSITY_LOSS_COMP,

    EN_NV_ID_LTE_TX_AMPR_NS05,
    EN_NV_ID_LTE_TX_AMPR_NS09,
    /*add for V9R1_6361 Begin*/
    NV_IDX_IIP2_CAL_TABLE,
    NV_IDX_RF_DCOC_CAL_ANT1,
    NV_IDX_RF_DCOC_CAL_ANT2,
    NV_IDX_TX_APC_GAIN,
    NV_IDX_RF_TXIQ_CAL,
    NV_IDX_TX_RF_BB_ATT,
    NV_IDX_TX_RF_BIAS,
    NV_IDX_PA_POWER_DIFFERENCE,
    NV_IDX_TX_RF_FREQ_COMP_STRU,
    NV_IDX_TX_PA_TEMP_COMP,
    NV_IDX_TX_ATTEN_TABLE,
    NV_IDX_POWERDET_VOLTAGE,
    /*add for V9R1_6361 End*/
    NV_IDX_TX_ET_BAND_PARA,
    NV_IDX_ET_LUT_TBL_LOWCH,
    NV_IDX_ET_LUT_TBL_MIDCH,
    NV_IDX_ET_LUT_TBL_HIGHCH,
    NV_IDX_ET_GAIN_COMP,
    NV_IDX_TX_ET_FINEDLY_PARA,
    NV_IDX_TX_ET_VOFFSET_GAIN,
    NV_IDX_TX_ET_EVDELY,
    NV_IDX_RF_CA_RCCODE_STRU,
    NV_IDX_LTE_TX_UL_ONE_RB_MPR,

    NV_IDX_LTE_TX_PD_PARA,
    NV_IDX_LTE_TX_PD_AUTO_CAL,
    NV_IDX_LTE_TX_PD_PWR_TABLE,
    NV_IDX_LTE_TX_PD_VOLT_TABLE,
    NV_IDX_LTE_TX_PD_TEMPCMP_TABLE,

    NV_IDX_RX_NOBLK_AGC_SCC_FREQ_COMP_ANT1,
    NV_IDX_RX_NOBLK_AGC_SCC_FREQ_COMP_ANT2,
    NV_IDX_RX_BLK_AGC_SCC_FREQ_COMP_ANT1,
    NV_IDX_RX_BLK_AGC_SCC_FREQ_COMP_ANT2,
    NV_IDX_DPDT_ANT_SAR,
    EN_IDX_NV_ID_FTM_CAND_CELL_LIST,

    PS_NV_IDX_BUTT
};
typedef VOS_UINT32 PS_NV_INDEX_ENUM_UINT32;

/*****************************************************************************
 枚举名    : PS_BAND_ENUM
 枚举说明  : 用于索引不同band的NV列表
*****************************************************************************/
enum PS_BAND_ENUM
{
    PS_BAND_7,
    PS_BAND_38,
    PS_BAND_20,
    PS_BAND_40,
    PS_BAND_41,
    PS_BAND_3,
    PS_BAND_1,
    PS_BAND_5,
    PS_BAND_8,
    PS_BAND_39,

    PS_BAND_19,
    PS_BAND_21,

    PS_BAND_2,
    PS_BAND_4,
    PS_BAND_6,
    PS_BAND_9,
    PS_BAND_10,
    PS_BAND_11,
    PS_BAND_12,
    PS_BAND_13,
    PS_BAND_14,
    PS_BAND_17,

    PS_BAND_18,
    PS_BAND_22,
    PS_BAND_23,
    PS_BAND_24,
    PS_BAND_25,
    PS_BAND_33,
    PS_BAND_34,
    PS_BAND_35,
    PS_BAND_36,
    PS_BAND_37,

    PS_BAND_42,
    PS_BAND_43,
	PS_BAND_28,
    /* 非标频段begin */
    //PS_BAND_101,
    PS_BAND_128,
    PS_BAND_103,
    PS_BAND_104,
    PS_BAND_105,
    PS_BAND_106,
    PS_BAND_107,
    PS_BAND_108,
    PS_BAND_109,
    PS_BAND_110,
    PS_BAND_111,
    PS_BAND_112,
    PS_BAND_113,
    PS_BAND_114,
    PS_BAND_115,
    PS_BAND_116,
    /* 非标频段end */

    PS_BAND_BUTT
};
typedef VOS_UINT8 PS_BAND_ENUM_UINT8;

/*****************************************************************************
 枚举名    : LRRC_DPDT_SWITCH_PARA_ENUM
 枚举说明  : DPDT功能开关
*****************************************************************************/
enum LRRC_DPDT_SWITCH_PARA_ENUM
{
    LRRC_DPDT_SWITCH_OFF    = 0,
    LRRC_DPDT_SWITCH_ON
};
typedef VOS_UINT32 LRRC_DPDT_SWITCH_PARA_ENUM_UINT32;

/*****************************************************************************
 结构名    : LPS_NV_FLOW_CONTROL
 协议表格  :
 ASN.1描述 :
 结构说明  : 协议栈流控结构体
*****************************************************************************/
typedef struct
{
    /* 流控总开关 */
    VOS_UINT32                          ulFlowCtrlFlag;
    /*ulFcInitFlag流控初始化选择 0-由RRC动态选择，1-代表由NV项进行控制*/
    VOS_UINT32                          ulFcInitFlag;
    VOS_UINT32                          ulFcPdcpTarget;
    VOS_UINT32                          ulTargetIPMax;
    VOS_UINT32                          ulSendSduMax;
    VOS_UINT32                          ulDlSduMax;
    VOS_UINT32                          ulULIpMax;
    VOS_UINT32                          ulMeasGap;
    VOS_UINT32                          ulSduGap;
}LPS_NV_FLOW_CONTROL;

/*add for DTS20120922*/
/*****************************************************************************
 结构名    : LPS_NV_GLOBAL_PRINT
 协议表格  :
 ASN.1描述 :
 结构说明  : 协议栈打印全局变量结构体
*****************************************************************************/
typedef struct
{
    /* 打印总开关 0:关闭打印全局变量，1: 打印一个，2:打印两个，依次 3 4 5 */
    VOS_UINT32                          ulGlobalPrintFlag;
    VOS_UINT32                          aulPara[MAX_GLOBAL_PRANT_NUM];
}LPS_NV_GLOBAL_PRINT_STRU;
/*add for DTS20120922*/

/*****************************************************************************
 结构名    : LPS_NV_MEAS_THRESHOLD_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8 ucSynsSwitch;     /*是否启动测量值掉底发起重建流程 */
    VOS_UINT8 ucRsrpLowCount;   /* PHY上报的测量值小于sRsrpHoldThreshold达到两次。发起重建流程 */
    VOS_INT16 sRsrpHoldThreshold;  /* PHY上报的测量值小于某值 ucRsrpLowCount++*/
}LPS_NV_MEAS_THRESHOLD_STRU;


/* 2655 begin */
 /*****************************************************************************
 结构名    : LPS_NV_LONG_BIT_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 协议栈的和协议功能相关的开关的结构体
*****************************************************************************/
typedef struct
{
    VOS_UINT32  bitFlag01                   :1;
    VOS_UINT32  bitFlag02                   :1;
    VOS_UINT32  bitFlag03                   :1;
    VOS_UINT32  bitFlag04                   :1;
    VOS_UINT32  bitFlag05                   :1;
    VOS_UINT32  bitFlag06                   :1;
    VOS_UINT32  bitFlag07                   :1;
    VOS_UINT32  bitFlag08                   :1;
    VOS_UINT32  bitFlag09                   :1;
    VOS_UINT32  bitFlag10                   :1;
    VOS_UINT32  bitFlag11                   :1;
    VOS_UINT32  bitFlag12                   :1;
    VOS_UINT32  bitFlag13                   :1;
    VOS_UINT32  bitFlag14                   :1;
    VOS_UINT32  bitFlag15                   :1;
    VOS_UINT32  bitFlag16                   :1;
    VOS_UINT32  bitFlag17                   :1;
    VOS_UINT32  bitFlag18                   :1;
    VOS_UINT32  bitFlag19                   :1;
    VOS_UINT32  bitFlag20                   :1;
    VOS_UINT32  bitFlag21                   :1;
    VOS_UINT32  bitFlag22                   :1;
    VOS_UINT32  bitFlag23                   :1;
    VOS_UINT32  bitFlag24                   :1;
    VOS_UINT32  bitFlag25                   :1;
    VOS_UINT32  bitFlag26                   :1;
    VOS_UINT32  bitFlag27                   :1;
    VOS_UINT32  bitFlag28                   :1;
    VOS_UINT32  bitFlag29                   :1;
    VOS_UINT32  bitFlag30                   :1;
    VOS_UINT32  bitFlag31                   :1;
    VOS_UINT32  bitFlag32                   :1;
}LPS_NV_LONG_BIT_STRU;
/*****************************************************************************
 结构名    : LPS_NV_TL_L2_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : L2功能相关的开关的结构体
*****************************************************************************/
typedef struct
{
    /* 配置RLC 上行组包个数限制 ，NV默认为45*/
    VOS_UINT32                          ulRlcUlSduLimit;

    LPS_NV_LONG_BIT_STRU                stL2Flag;

    /************************stL2Flag各个BIT含义***************************
     bitFlag01: 设置抓取L2 MAC PDU中的参数 g_ulIfForwardToPc, 默认为关
     bitFlag02: 设置抓取L2 MAC PDU中的参数 g_ulCapPusch, 默认为关
     bitFlag03: 设置抓取L2 MAC PDU中的参数 g_ulCapPdsch, 默认为关
     bitFlag04: 设置抓取L2 MAC PDU中的参数 g_ulCapPdcp, 默认为关
     bitFlag05: 设置抓取L2 MAC PDU中的参数 g_ulTcpDebugFlg, 默认为关
     bitFlag06: 设置抓取L2 MAC PDU中的参数 g_ulTcpDlFlg, 默认为关
     bitFlag07: 设置抓取L2 MAC PDU中的参数 g_g_ulTcpUlFlg, 默认为关
     bitFlag08: 设置抓取L2 MAC PDU中的参数 g_ulTcpCtrlPduFlg, 默认为关
     bitFlag09:
     bitFlag10:
     bitFlag11:
     bitFlag12:
     bitFlag13:
     bitFlag14:
     bitFlag15:
     bitFlag16:
     bitFlag17:
     bitFlag18:
     bitFlag19:
     bitFlag20:
     bitFlag21:
     bitFlag22:
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:
    ****************************************************************************/

    LPS_NV_LONG_BIT_STRU                stL2Flag1;

    /*预留*/
    /*数组中的第一个元素为规避罗德仪器不响应IPV6前缀问题，使用NV控制的全局变量，IPV6前缀默认UE只发1次*/
    VOS_UINT32                          ulRev[32];

}LPS_NV_TL_L2_PARA_STRU;
/*****************************************************************************
 结构名    : LPS_SWITCH_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 协议栈的和协议功能相关的开关的结构体
*****************************************************************************/
typedef struct
{
    /* 配置TA Timer超时SRS和PUCCH释放开关 0:关闭，1:打开，默认关闭 */
    VOS_UINT32                          ulCloseTaTimer;

    /* 配置SR触发方开关 0:关闭  1:打开，默认关闭 */
    VOS_UINT32                          ulSrTrigFlag;

    /* 配置SR触发随机接入开关 0:关闭，1:打开，默认关闭 */
    VOS_UINT32                          ulCloseSrRandFlag;

    /*同失步开关，0为关闭，1为打开。默认为关闭，设置为打开*/
    /*VOS_UINT32                          ulSyncCtrlFlag;*/

    /*连接态测量开关，0为关闭，1为打开。默认为关闭，设置为打开*/
    VOS_UINT32                          ulConnMeasFlg;

    /*设置测量IND消息频率，参数表示上报间隔: 取值方法要大于等于1*/
    VOS_UINT32                          ulMeasReportMaxNum;

    /*0:关闭抓包功能 1:打开抓包功能 默认是打开*/
    VOS_UINT32                          ulIfForwardToPc;

    /*打开安全加密开关，仅仅需要时设置该标志*/
    VOS_UINT32                          ulSmcControl;

    /*规避eNB的TDD的接入问题*/
    /*VOS_UINT32                          ulMsg4OnlyPadding;*/

    /*判断是否BAR小区开关*/
    VOS_UINT32                          ulCloseBarCell;

    /*DRX功能开关 0:关闭  1:打开*/
    VOS_UINT32                          ulDrxControlFlag;

   /*外场测试桩代码开关 0:关闭  1:打开.默认为关闭*/
    VOS_UINT32                          ulFieldTestSwitch;

    /* PCO功能开关，0为关闭，1为打开。默认为打开 */
    VOS_UINT32                          ulPcoFlag;

    /*流控结构*/
    LPS_NV_FLOW_CONTROL                  stPsNvFlowCtl;

    /************************stPsGcfFlag01各个BIT含义***************************
     bitFlag01:表示GCF测试场景TAU消息是否加密，平台缺省值为1。
               0: 加密；1:不加密
     bitFlag02:表示GCF测试场景msg4解析开关，平台缺省值为1。
               0: 表示按协议实现; 1:表示按规避方案实现
     bitFlag03:表示GCF测试场景是否支持24.301 Table D.1.1中建链原因设置，平台缺省值为1。
               0: 支持; 1:不支持
     bitFlag04:表示GCF测试场景指示安全功能是否支持测试模式，测试模式支持空完整性算法，平台缺省值为1。
               0: 支持; 1:不支持
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsGcfFlag01;

    /************************stPsGcfFlag02各个BIT含义***************************
     stPsGcfFlag01各个BIT含义:
     bitFlag01:
     bitFlag02:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsGcfFlag02;

    /************************stPsFunFlag01各个BIT含义***************************
     bitFlag01: Band64是否支持，缺省值:0; 0:不支持;1:支持
     bitFlag02: 删除SDF时是否携带Qos信息,缺省值:0; 0:携带;1:不携带
     bitFlag03: 是否进行连接态收到本ue的业务寻呼后进行释放,缺省值:0; 0:释放;1:不释放
     bitFlag04: 校验安全功能开关,缺省值:0; 0:打开;1:关闭
     bitFlag05:
     bitFlag06:
     bitFlag07: 拨号功能合入之前，装备测试时上行DRB数据在PDCP入口丢掉,0为关闭，1为打开。默认为关闭
     bitFlag08: Print时延优化开关，缺省值:0; 0:关;1:开;但是RRM测试时时自动生效的
     bitFlag09: 层间消息时延优化开关，缺省值:0; 0:关;1:开;
     bitFlag10: MBMS的支持开关，缺省值:0; 0:关;1:开;
     bitFlag11: SBM定制需求开关，特定band支持特定的带宽.缺省值:0; 0:关;1:开;
     bitFlag12: 检查整个小区的带宽是都在协议频段内，缺省值:1; 0:关;1:开;
     bitFlag13: 测试部需求,模拟切换失败用例，缺省值:1; 0:关;1:开;
     bitFlag14: DCM定制需求 GU到L的切换NAS不判断被禁TA;缺省值:0; 0:关;1:开;
     bitFlag15: 是否支持ETWS功能;缺省值:1; 0:关;1:开;
     bitFlag16: 是否支持CMAS功能;缺省值:1; 0:关;1:开;
     bitFlag17:
     bitFlag18: L重建时是否搜索UTRAN;缺省值:1; 0:关;1:开;
     bitFlag19: L重建时是否搜索GSM;缺省值:1; 0:关;1:开;
     bitFlag20: 部分接收到系统信息时,如果小区RSRP门限小于设定值，用于判断否需要bar小区，;缺省值:0; 0:关;1:开;
     bitFlag21: NCC从左向右还是从右向左，目前按照协议实现，缺省值:0; 0表示按照协议，1表示不按照协议
     bitFlag22: 是否支持背景搜索,缺省值:0;1:关，0:开；
     bitFlag23: 重建时需要根据GAP是否有配置重新配置一下物理层，缺省值:1; 1:开，0:关
     bitFlag24:
     bitFlag25:
     bitFlag26: IDLE下重选前不判断NCC，缺省值:0; 0表示需要判断；1表示不判断。
     bitFlag27: V7R1日本DCOM需求，缺省值:0; 0:关;1:开;
     bitFlag28: V7R1日本DCOM需求，缺省值:0; 0:关;1:开;
     bitFlag29: V7R1日本DCOM需求，缺省值:0; 0:关;1:开;
     bitFlag30: V7R1日本DCOM需求，缺省值:0; 0:关;1:开;
     bitFlag31: V7R1日本DCOM需求，缺省值:0; 0:关;1:开;
     bitFlag32: RRM测试时，缺省关闭打印是否生效，缺省值:0; 1:不生效；0:生效。
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsFunFlag01;

    /************************stPsFunFlag02各个BIT含义***************************
     bitFlag01: CA特性开关:缺省值:0; 0:开;1:关:;
     bitFlag02:
     bitFlag03:
     bitFlag04: CMAS在驻留之前还是驻留之后上报，缺省值:0;0: 驻留之后上报; 1:驻留前后都可以上报
     bitFlag05:
     bitFlag06:
     bitFlag07: 背景搜，只搜L单模.不搜GU模开关.缺省值:0; 0:关;1:开;
     bitFlag08: ETWS发生时机; 1:立即发送，0:收齐后再发送
     bitFlag09: TL L2关键事件上报-缺省值:0;0:关;1:开
     bitFlag10: LTE L2 数传信息上报-缺省值:0;0:关;1:开
     bitFlag11: LIST搜网先验频点是否搜索2次。0:关;1:开
     bitFlag12: 网络指定模式重定向结束后是否继续发起其他模式的重定向流程; 0:发起网络指定模式的重定向之后继续发起其他模式的重定向;1:只发起网络指定模式的重定向
     bitFlag13:
     bitFlag14: LTE CA小区状态信息上报-缺省值:0;0:关;1:开
     bitFlag15:
     bitFlag16: LTE模内切换NAS忽略被禁TA,缺省值:0; 0:关; 1:开
     bitFlag17:
     bitFlag18:
     bitFlag19:
     bitFlag20:
     bitFlag21:
     bitFlag22:
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsFunFlag02;


    LPS_NV_LONG_BIT_STRU                 stPsFunFlag03;

   /************************stPsFunFlag04各个BIT含义***************************
     bitFlag01:
     bitFlag02: 无卡开机或开机读卡失败，是否删除了NV中的安全上下文,缺省值:1; 0:删除; 1:不删除
     bitFlag03:
     bitFlag04:
     bitFlag05:
     bitFlag06:
     bitFlag07:
     bitFlag08:
     bitFlag09:
     bitFlag10:
     bitFlag11:
     bitFlag12:
     bitFlag13:
     bitFlag14:
     bitFlag15:
     bitFlag16:
     bitFlag17:
     bitFlag18:
     bitFlag19:
     bitFlag20:
     bitFlag21:
     bitFlag22:
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsFunFlag04;

    LPS_NV_GLOBAL_PRINT_STRU             stPsNvGlobalPrint;
}LPS_SWITCH_PARA_STRU;

/*****************************************************************************
 结构名    : TPS_SWITCH_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 协议栈的和协议功能相关的开关的结构体
*****************************************************************************/
typedef struct
{
    /************************stTpsLayFliterFlag01各个BIT含义********************
     bitFlag01:层间消息OP_HL1_SCHEDULE_IND过滤开关。平台缺省值为0
               0:过滤 1:不过滤
     bitFlag02:层间消息OP_T_RRC_trafficMeasPeriod过滤开关。平台缺省值为0
               0:过滤 1:不过滤
     bitFlag03:部分动态打印关闭，一般是数组、循环等次要信息关闭。平台缺省值为0
               0:关闭打印 1:不关闭打印
     bitFlag04:
     bitFlag05:
     bitFlag06:
     bitFlag07:
     bitFlag08:
     bitFlag09:
     bitFlag10:
     bitFlag11:
     bitFlag12:
     bitFlag13:
     bitFlag14:
     bitFlag15:
     bitFlag16:
     bitFlag17:
     bitFlag18:
     bitFlag19:
     bitFlag20:
     bitFlag21:
     bitFlag22:
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:

    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stTpsLayFliterFlag01;

    /************************stTpsLayFliterFlag01各个BIT含义********************
     bitFlag01:
     bitFlag02:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stTpsLayFliterFlag02;

    /************************stTPsGCFFlag01各个BIT含义**************************
     bitFlag01: GCF是否打开cs loop 功能。
                平台缺省值为0
                0:关闭CsLoop功能  1:打开功能
                此功能已经自动识别，无需打开。

     bitFlag02: TDS快速搜网功能,非标功能。功能打开时TRRC不满足S准则，直接发起搜网流程。
                平台缺省值为0
                0:功能关闭 1:功能打开

     bitFlag03: 准FR特性开关
                平台缺省值为1
                0:功能关闭 1:功能打开

     bitFlag04: TG互操作，sOfIratsearch门限优化，已不使用。
                平台缺省值为0
                0:关闭功能  1:打开功能

     bitFlag05: TG互操作，QrxLev门限优化，已不使用。
                平台缺省值为0
                0:关闭功能  1:打开功能

     bitFlag06: 当T的S值小于0时，如果GSM有S值大于0的小区则直接重选，已不使用。
                平台缺省值为0
                0:关闭功能  1:打开功能

     bitFlag07: 重选优化,非标功能。如果是能量在这个范围内，把能量降6db，保证重选到tds时，t能量足够强
                平台缺省值为0
                0:关闭功能  1:打开功能

     bitFlag08: RRM桩函数，只有当此功能打开，RRM测试才能通过。
                平台缺省值为0
                0:功能关闭 1:功能打开

     bitFlag09:
     bitFlag10:
     bitFlag11:
     bitFlag12:
     bitFlag13:
     bitFlag14:
     bitFlag15:
     bitFlag16:
     bitFlag17:
     bitFlag18:
     bitFlag19:
     bitFlag20:
     bitFlag21:
     bitFlag22:
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stTPsGCFFlag01;

    /************************stTPsGCFFlag02各个BIT含义**************************
     bitFlag01:
     bitFlag02:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stTPsGCFFlag02;

    /************************stTPsFunFlag01各个BIT含义**************************
     bitFlag01: CellUpdate流程优化，在T313超时，如果只有PS域时不发起CellUpdate直接,进入IDL状态
                平台缺省值为1。
                0:功能打开 1:功能关闭

     bitFlag02: debug信息处理，对相关状态下的小区信息、状态等数据进行保存，
                平台缺省值为0.
                0:功能打开 1:功能关闭

     bitFlag03: debug信息上报功能，将Debug信息以层间形式上报。
                平台缺省值为0。
                0:功能打开 1:功能关闭

     bitFlag04: SMC使用同步函数接口的参数
                平台缺省值为0
                0:功能关闭 1:功能打开

     bitFlag05: TCP ACK丢弃功能。
                平台缺省值为0
                0:功能关闭 1:功能打开

     bitFlag06: DetectCell功能。
                平台缺省值为0
                0:功能关闭 1:功能打开

     bitFlag07: 规避网络的无效MeasCtrl，在特定网络环境下使用
                平台缺省值为0
                0:功能关闭 1:功能打开

     bitFlag08: CCCH消息上报，屏蔽掉不属于UE的空口
                平台缺省值为1
                0:功能关闭 1:功能打开

     bitFlag09:
     bitFlag10:
     bitFlag11:
     bitFlag12:
     bitFlag13:
     bitFlag14:
     bitFlag14:CS FACH重选优化开关，开启时如果服务小区能量低于门限值则重选，高于门限不重选
              平台缺省值为1
              0:功能关闭 1:功能打开
     bitFlag15:
     bitFlag16:
     bitFlag17:
     bitFlag18:
     bitFlag19:
     bitFlag20:
     bitFlag21:
     bitFlag22:
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:

    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stTPsFunFlag01;

    /************************stTPsFunFlag02各个BIT含义**************************
     bitFlag01:
     bitFlag02:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stTPsFunFlag02;
}TPS_SWITCH_PARA_STRU;

/*****************************************************************************
 结构名    : TDS_CERSSI_REPORT_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 协议栈的和协议功能相关的开关的结构体
*****************************************************************************/
typedef struct
{
    VOS_UINT32                           ulThreshold;
    VOS_UINT32                           ulInterval;
    VOS_UINT8                            aucRsv[4];
}TDS_CERSSI_REPORT_PARA_STRU;
/*****************************************************************************
 结构名    : LPS_LTE_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 协议栈的和LTE相关的配置
*****************************************************************************/
typedef struct
{
    /* LTE天线个数 */
    VOS_UINT32                          ulPsCfgDspAntCnt;

    /*VOS_UINT32                          ulPsCfgDspRatMod;*/
    /*频带号，取值范围从1至40，分别对应36.101的band取值,默认为20*/
    VOS_UINT8                          ucEutraBand;

    VOS_UINT8                          aucRsv[3];

    /* 上下行子帧配比，默认为1 */
    VOS_UINT32                          ulCfgSubFrameAssign;

    /* 特殊子帧配置，默认为7 */
    VOS_UINT32                          ulSubFramePattern;
}LPS_LTE_CONFIG_STRU;

/*****************************************************************************
 结构名    : LRRC_NV_CAND_CELL_LIST_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 候补小区NV结构
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFreqCount;                            /* 有效的频率数目 */
    VOS_UINT8                           aucReserved1[2];
    RRC_NV_CSEL_CAND_FREQ_STRU          ausCandFreqs[RRC_NV_EACH_BAND_FREQ_COUNT];/* 先验频率列表 */
}LRRC_NV_CAND_CELL_LIST_STRU;

/*****************************************************************************
 结构名    : LRRC_NV_SUPPORT_BAND_LIST_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : UE支持频段NV结构
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usBandCount;                            /* 有效的频带数目 */
    VOS_UINT8                           aucReserved1[2];
    RRC_NV_CSEL_FREQ_BAND_INFO_STRU     astCandBands[RRC_NV_EACH_BAND_BANDS_COUNT];
}LRRC_NV_SUPPORT_BAND_LIST_STRU;

/*****************************************************************************
 结构名    : RRC_NV_EACH_BAND_IND_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 每个Band下的候补信息
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucBandInd;                              /* 频段指示 */
    PS_BOOL_ENUM_UINT8                  enFirstSearchFlg;                       /* 频点或频段搜索阶段，优先搜索这个频段 */
    VOS_UINT8                           aucReserved1[2];
    LRRC_NV_CAND_CELL_LIST_STRU         stCandCellInfo;                         /* Band内候补小区信息 */
    LRRC_NV_SUPPORT_BAND_LIST_STRU      stCandBandsInfo;                        /* Band内候补频段信息 */
}LRRC_NV_EACH_BAND_CAND_INFO_STRU;


/*****************************************************************************
 结构名    : LRRC_NV_CALIBRATION_BAND_LIST_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : UE需要校准的band信息
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucReserved[2];
    VOS_UINT16                          usCnt;
    VOS_UINT8                           aucEutraBand[RRC_MAX_NUM_OF_BANDS];
}LRRC_NV_CALIBRATION_BAND_LIST_STRU;

/*****************************************************************************
 结构名    : LRRC_UE_CAP_MEAS_EUTRA_BAND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : UE EUTRA能力中MEAS->Band参数
*****************************************************************************/
typedef struct
{
    RRC_INTER_FREQ_EUTRA_BAND_INFO_STRU stInterFreqEutraBandInfo;
    RRC_INTER_RAT_BAND_INFO_STRU        stInterRatBandInfo;
}LRRC_UE_CAP_MEAS_EUTRA_BAND_STRU;

/*****************************************************************************
 结构名    : RRC_UE_EUTRA_CAP_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : UE EUTRA能力信息
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitFeatureGroupIndsPresent    : 1;
    VOS_UINT32                          bitUeCapV920IesPresent        : 1;
    VOS_UINT32                          bitSpare                      : 30;
    VOS_UINT8                           aucReserved[2];
    /* 用来设置UE接入层版本，1：支持，0：不支持，从低到高位分别用来指示Rel8,Rel9,.... */
    VOS_UINT8                           ucAsRelBitmap;
    RRC_UE_CATEGORY_ENUM_UINT8          enUeCatg;
    RRC_UE_CAP_PDCP_PARA_STRU           stPdcpPara;
    RRC_UE_CAP_PHY_PARA_STRU            stPhyPara;
    RRC_UE_CAP_RF_PARA_STRU             stRfPara;
    RRC_UE_CAP_MEAS_PARA_STRU           stMeasPara;
    RRC_UE_CAP_FEATURE_GROUP_IND_STRU   stFeatrueGroupInds;
    RRC_UE_CAP_INTER_RAT_PARA_STRU      stInterRatPara;
    RRC_UE_EUTRA_CAP_V920_IES_STRU      stUeCapV920Ies;
} LRRC_NV_UE_EUTRA_CAP_STRU;

/*****************************************************************************
 结构名    : LRRC_NV_RRC_CTRL_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : RRC控制开关结构
             重选3db控制开关,BAR小区后最大搜索次数,SIB接收定时器选择开关
*****************************************************************************/
typedef struct
{
    RRC_NV_SWITCH_ENUM_UINT32            en3dbCtlFlg;           /* 默认值为关闭 0 */
    VOS_UINT32                           ulMaxSeachCntOfBarFrq;
    RRC_NV_TIMER_CHOICE_ENUM_UINT32      enSibTimerChoiceFlg;   /* 默认为0 */
    VOS_UINT32                           ulReserved;            /* 预留1位 */
}LRRC_NV_RRC_CTRL_STRU;

/*****************************************************************************
 结构名    : LRRC_NV_LOCK_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :NV项锁信息数据结构
*****************************************************************************/
typedef struct
{
    RRC_NV_LOCK_INFO_ENUM_UINT32         enLockInd;
    VOS_UINT8                            ucBandInd;                      /* 频段指示 */
    VOS_UINT8                            ucForbidReselAndHO;             /* 锁频过程中是否允许切换和重选 */
    VOS_UINT8                            aucReserved1[2];
    VOS_UINT16                           usCellId;                       /* 小区ID */
    VOS_UINT16                           usFreqPoint;                    /* 频点信息 */
    RRC_NV_CSEL_FREQ_BAND_INFO_STRU      stLockedBand;                   /* 锁定Band信息 */
} LRRC_NV_LOCK_INFO_STRU;

/* modify by lishangfeng begin */

/*****************************************************************************
 结构名    : LRRC_NV_CSQ_RPT_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 能量上报的周期和门限
*****************************************************************************/
typedef struct
{
    VOS_UINT32                       ulRssiReportLen;
    VOS_UINT32                       ulDetaRssi;
    VOS_UINT16                       usMs;
    VOS_UINT8                        aucRes[2];
} LRRC_NV_CSQ_RPT_INFO_STRU;

/* modify by lishangfeng end */

/* wangrui 20120817 begin */
/*****************************************************************************
 结构名    : LRRC_NV_LWCLASH_RANGE_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 冲突范围的上限和下限
*****************************************************************************/
typedef struct
{
    VOS_UINT16                        usFreqBegin;        /*范围下限频点 单位:100Khz*/
    VOS_UINT16                        usFreqEnd;          /*范围上限频点 单位:100Khz*/
} LRRC_NV_LWCLASH_RANGE_INFO_STRU;
/*****************************************************************************
 结构名    : LRRC_NV_LWCLASH_RANGE_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 冲突范围的上限和下限
*****************************************************************************/
typedef struct
{
    VOS_UINT16                        ulnum;                /*范围下限频点 单位:100Khz*/
    LRRC_NV_LWCLASH_RANGE_INFO_STRU   stBandRng[RRC_NV_LWCLASH_RANGE_COUNT]; /*范围上限频点 单位:100Khz*/
} LRRC_NV_LWCLASH_RANGE_STRU;

/* wangrui 20120817 end */
/*****************************************************************************
 结构名    : LRRC_NV_UE_RFRD_TYPE_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :NV项射频类型结构
*****************************************************************************/
typedef struct
{
    RRC_NV_UE_RFRD_TYPE_ENUM_UINT8       enUeRfrdType;              /* 射频类型 */
    VOS_UINT8                            aucReserved[3];

} LRRC_NV_UE_RFRD_TYPE_STRU;

/*****************************************************************************
 结构名    : LRRC_NV_RF_HW_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :9361RF配置
*****************************************************************************/
typedef struct
{
    RRC_PHY_LTE_RF_HW_ENUM_UINT8       enLteRfHw;
    VOS_UINT8                          aucRsv[3];
} LRRC_NV_RF_HW_STRU;

/*****************************************************************************
 结构名    : LTE_COMPENSATE_SWITCH_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 补偿开关, 从NV读出配置DSP
*****************************************************************************/
typedef struct
{
    VOS_UINT16 usFreqCmpnstSwitch;      /*0：关掉频率补偿 1:打开频率补偿*/
    VOS_UINT16 usTempCmpnstSwitch;      /*0：关掉温度补偿  1:打开温度补偿*/
    VOS_UINT16 usTxPwrCmpnstSwitch;     /*0：关掉发射功率补偿 1:打开发射补偿 。当前此开关预留*/
    VOS_UINT16 usReserved;
}LTE_COMPENSATE_SWITCH_STRU;

/*****************************************************************************
 结构名    : LUPLINK_POWER_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 功控配置, 从NV读出配置DSP
*****************************************************************************/
typedef struct
{
    VOS_UINT16 usPuschPwrCtrlSwitch;
    VOS_UINT16 usPuschClosedLoopSwitch;
    VOS_UINT16 usPucchPwrCtrlSwitch;
    VOS_UINT16 usPucchClosedLoopSwitch;
    VOS_UINT16 usSrsPwrCtrlSwitch;
    VOS_UINT16 usPrachPwrCtrlSwitch;

    VOS_INT16  sPuschTxPower;
    VOS_INT16  sPucchTxPower;
    VOS_INT16  sSrsTxPower;
    VOS_INT16  sPrachTxPower;
}LUPLINK_POWER_CONFIG_STRU;

/* LTE PS Transfer begin */
/* MTC AREA LOST Begins */
#if(FEATURE_MULTI_MODEM == FEATURE_ON)
typedef struct
{
    PS_BOOL_ENUM_UINT8      enValidFlag;  /*门限是否有效  */
    VOS_UINT8               ucLrrcMTCLostThreshold; 	/* LTE的PS迁移门限,0~31 */
    VOS_UINT8               ucLrrcMTCAvailableDValue;    /* LTE的PS回迁门限与迁移门限差值,0~(31-ucLrrcMTCLostThresh) */
    VOS_UINT8               ucMTCLostTimerLen;    /* LTE->CDMA的PS迁移过程的定时器长度,取值单位:s */
    VOS_INT16               sRsv; /*保留*/
    VOS_UINT16              usMTCAvailableTimerLen; /* CDMA->LTE的PS迁移过程的定时器长度,取值单位:s */
}LTE_MTC_AREA_LOST_THRESHOLD_STRU;
#endif
/* MTC AREA LOST End */
/* LTE PS Transfer end */


/* gaojishan-PLMN_EXACTLY_COMPARE_FLG */
#ifdef PS_ITT_PC_TEST2
typedef struct
{
    VOS_UINT8   ucPlmnExactlyCompareFlag;
    VOS_UINT8   aucRsv[3];
}NVIM_PLMN_EXACTLY_COMPARE_FLAG_STRU;
#endif
/* TCXo */
#if (VOS_OS_VER == VOS_WIN32)
/*****************************************************************************
 结构名    : LTE_TCXO_DYNAMIC_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : TCXO动态信息
*****************************************************************************/
typedef struct
{
    VOS_UINT16 usVctcxoThdHigh;             /* 动态TCXO高门限 */
    VOS_UINT16 usVctcxoDynamic;             /* 动态TCXO值, UE上电时由HPA读取NV并配置DSP,
                                               UE上电开机进入连接态后从DSP获取有效值写入NV */
    VOS_UINT16 usVctcxoFlag;                /* 动态TCXO取值是否有效标识, DSP可不用,
                                               0: 有效；其余无效，无效时usDynamicTcxo值无意义 */
    VOS_UINT16 usVctcxoFuncSwitch;          /* 动态TCXO功能是否使用开关, DSP可不用,
                                               修改后, 需要下电再上电才会生效
                                               0: 关闭, 关闭时usVctcxoDynamic取值usVctcxoInit
                                               1: 打开 */
}LTE_TCXO_DYNAMIC_CONFIG_STRU;
#endif
#if 0
/*****************************************************************************
 结构名    : LRRC_NV_UE_AD9361_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :NV项射频9361信息结构
*****************************************************************************/
typedef struct
{
    /*Common NV List*/
    VOS_UINT16 usVctcxoInit;                /*Vco初值*/
    VOS_UINT16 usRsvd;
    VOS_UINT16 usAntModemLoss[16];          /*Modem与整机天线间线损*/
    VOS_UINT16 usTempSensorTable[20];       /*PA热敏电阻检测到的平台温度转变成电压，再用HKADC采样后的数值*/
    /*Rx NV List*/
    VOS_UINT16 usRxCalibrFreqList[16];      /*Rx频率校准表*/
    VOS_UINT32 ulRxAgcTableAnt1[128];       /*对应的是ad9361的agc tabel*/
    VOS_UINT32 ulRxAgcTableAnt2[128];
    VOS_UINT8  ucRxAagcGainIdxTblAnt1[128]; /*aagc逻辑的增益索引表*/
    VOS_UINT8  ucRxAagcGainIdxTblAnt2[128]; /*aagc逻辑的增益索引表*/
    VOS_UINT16 usRxAgcTableAnt1Err[128];      /*对应lna的四个档位*/
    VOS_UINT16 usRxAgcTableAnt2Err[128];
    VOS_UINT16 usLnaGain0FreqComp[2][16];   /*Lna在档位0时对应的不同天线和频点下的补偿值*/
    VOS_UINT16 usLnaGain1FreqComp[2][16];   /*Lna在档位1时对应的不同天线和频点下的补偿值*/
    VOS_UINT16 usLnaGain2FreqComp[2][16];   /*Lna在档位2时对应的不同天线和频点下的补偿值*/
    VOS_UINT16 usLnaGain3FreqComp[2][16];   /*Lna在档位3时对应的不同天线和频点下的补偿值*/
    VOS_INT16 sLnaGain0TmpComp[20];        /*Lna在档位0时对应的不同温度时的的补偿值*/
    VOS_INT16 sLnaGain1TmpComp[20];        /*Lna在档位1时对应的不同温度时的的补偿值*/
    VOS_INT16 sLnaGain2TmpComp[20];        /*Lna在档位2时对应的不同温度时的的补偿值*/
    VOS_INT16 sLnaGain3TmpComp[20];        /*Lna在档位3时对应的不同温度时的的补偿值*/
    /*Tx NV List*/
    VOS_UINT16 usTxCalibrFreqList[16];      /*Tx频率校准表*/
    VOS_UINT16 usTxApcHighGainTable[32];    /*apc高增益表*/
    VOS_UINT16 usTxApcLowGainTable[60];     /*apc低增益表*/
    VOS_UINT16 usTxApcHighThrd;             /*apc高增益到低增益门限*/
    VOS_UINT16 usTxApcLowThrd;              /*apc低增益到高增益门限*/
    VOS_UINT16 ausTxApcHighPwr[4];         /* 高增益功率点 */
    VOS_UINT16 ausTxApcLowPwr[4];          /* 低增益功率点 */
    VOS_UINT16 usTxApcFreqCompHighGain[4][16]; /*pa频率补偿，0.25db精度*/
    VOS_UINT16 usTxApcFreqCompLowGain[4][16];
    VOS_INT16 sTxApcTempCompHighGain[20];  /*用于补偿不同温度下的PA高增益误差*/
    VOS_INT16 sTxApcTempCompLowGain[20];   /*用于补偿不同温度下的PA低增益误差*/
    VOS_UINT16 usTxPowerDetVoltage[16];     /*PA功率检测模块输出的电压与实际发送功率的关系*/
    LTE_COMPENSATE_SWITCH_STRU   stCmpnstSwitch;
    LUPLINK_POWER_CONFIG_STRU stUlPwrCfg;
    /*Timer NV List*/
    VOS_UINT16 ulAdcOpenTime;
    VOS_UINT16 usRficT1;
    VOS_UINT16 usRficT2;
    VOS_UINT16 usRficT3;
    VOS_UINT16 usRficT4;
    VOS_UINT16 usRficT5;
    VOS_UINT16 usRficT6;
    VOS_UINT16 usRficT7;
    VOS_UINT16 usRficT8;
    VOS_UINT16 usRficT9;
    VOS_UINT16 usRficT10;
    VOS_UINT16 usPaOpenTime;
    VOS_UINT32 ulAagcLNATH[7];
    VOS_UINT32 ulAagcLNAOffAddr[4];
    VOS_UINT16 usDbmToGainTbl_normal[120];
    VOS_UINT16 usDbmToGainTbl_AcsBlk[128];
    LTE_TCXO_DYNAMIC_CONFIG_STRU stTcxoDynamicCfg;
}LRRC_NV_UE_AD9361_INFO_STRU;

#endif
/*****************************************************************************
 结构名    : LTE_GATE_CLOCK_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :时钟门控
*****************************************************************************/
typedef struct
{
    VOS_UINT16 usGateClockEnableFlag;       /* 0:invalid, 1:Valid, 默认 0 */
    VOS_UINT16 usRsvd;
} LTE_GATE_CLOCK_CONFIG_STRU;

/*****************************************************************************
 结构名    : FC_LTE_CPU_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 定义LTE CPU流控配置结构
*****************************************************************************/
typedef struct
{
    VOS_UINT16          usFirstDelay;           /* 延迟进入流控状态，连续几个周期高于阈值才进行流控 */
    VOS_UINT16          usUlDownRate;           /* 上行降速步长百分比 */
    VOS_UINT16          usUlUpRate;             /* 上行升速步长百分比 */
    VOS_UINT16          usUlMinThr;             /* 上行降速下限 kbps */
    VOS_UINT16          usHqDownRate;           /* HARQ降速步长百分比 */
    VOS_UINT16          usHqUpRate;             /* HARQ升速步长百分比 */
    VOS_UINT16          usHqMaxDiscardRate;     /* HARQ丢包上限 */
    VOS_UINT16          usDowngradeThres;       /* 降速阈值，CPU占用率高于该值时，开始降速 */
    VOS_UINT16          usUpgradeThres;         /* 升速阈值，CPU占用率低于该值时，开始升速 */
	VOS_UINT16          usResv;
} FC_LTE_CPU_CONFIG_STRU;

/*****************************************************************************
 结构名    : FC_LTE_TEMPERATURE_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 定义LTE 温控配置结构
*****************************************************************************/
#define FC_UL_THROUGHPUT_THRES_CNT_NV          (12)
typedef struct
{
    VOS_UINT8           ucInitialPos;           /* 降速开始位置0~11, 默认4 */
    VOS_UINT8           ucZeroSupport;          /* 是否支持速率降到0,0表示不支持，默认0 */
    VOS_UINT8           ucResv[2];              /* 保留位 */
    VOS_UINT32          ulTemperSteps[FC_UL_THROUGHPUT_THRES_CNT_NV];      /* 温控速率档位kbps，初值[50000, 40000, 30000, 25000, 20000, 15000, 10000, 5000, 2000, 0, 0, 0] */
    VOS_UINT32          ulMinBsrThr;            /* BSR能够控制的最小速率kbps，默认120 */
} FC_LTE_TEMPERATURE_CONFIG_STRU;

/*****************************************************************************
 结构名    : FLOWCTRL_LTE_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 定义LTE流控配置结构
*****************************************************************************/
typedef struct
{
    FC_LTE_TEMPERATURE_CONFIG_STRU stFcTemperatureConfig;
    FC_LTE_CPU_CONFIG_STRU  stFcCpuConfig;
} FLOWCTRL_LTE_CONFIG_STRU;


/* gaojishan-SYSCFG-SAVENV-Begin */
#define NV_ITEM_EUTRA_MAX_SUPPORT_BANDS_NUM         (64)
#define NV_MAX_FDD_FREQ_BANDS_NUM                 (32)

/*
NVIM_UE_SUPPORT_FREQ_BAND_STRU结构说明:
usWcdmaBand和usGsmBand用Bit位表示用户设置的频段，bit1代表频段I,bit2代表频段II,
依次类推,比特位为1,表示支持该频段.下表是比特位和频段对应关系:
-------------------------------------------------------------------------------
        bit8       bit7      bit6     bit5    bit4     bit3      bit2     bit1
-------------------------------------------------------------------------------
WCDMA   900(VIII)  2600(VII) 800(VI)  850(V)  1700(IV) 1800(III) 1900(II) 2100(I) oct1
        spare      spare     spare    spare   spare    spare     spare   J1700(IX)oct2
-------------------------------------------------------------------------------
GSM频段 1900(VIII) 1800(VII) E900(VI) R900(V) P900(IV) 850(III)  480(II)  450(I)  oct3
        spare      spare     spare    spare   spare    spare     spare    700(IX) oct4
-------------------------------------------------------------------------------
aucUeSupportWcdmaBand和aucUeSupportGsmBand用数组表示UE支持的频段,并以存储顺序的
先后表示频段优先顺序,用0xff表示无效.

例如:
oct1-oct4分别是：0x03,0x00,0x7B,0x00
   则代表用户设置频段为：W：WCDMA-I-2100, WCDMA-II-1900
                         G：850(III),P900(IV),R900(V),E900(VI),1800(VII)
oct5-oct16分别是:2,5,1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
   则代表UE支持W频段I,II,V,优先顺序是:II,V,I.
oct17-oct28分别是:4,5,8,7,6,3,0xff,0xff,0xff,0xff,0xff,0xff
   则代表UE支持G频段III,IV,V,VI,VII,VIII,优先顺序是:IV,V,VIII,VII,VI,III.
*/
typedef struct
{
    VOS_UINT32                  ulWcdmaBand;
    VOS_UINT16                  usGsmBand;
    VOS_UINT8                   aucReserve[2];
    VOS_UINT8                   aucUeSupportWcdmaBand[NV_MAX_FDD_FREQ_BANDS_NUM];
    VOS_UINT8                   aucUeSupportGsmBand[NV_MAX_FDD_FREQ_BANDS_NUM];
}NV_UE_SUPPORT_FREQ_BAND_STRU;

/*****************************************************************************
 结构名    : NV_UE_EUTRA_FREQ_BAND_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LTE支持的一个频段的频点信息结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucBandNo;                               /* band号，值为(1-64) */
    VOS_UINT8                           ucDuplexModeFlg;                        /* 双工模式指示，1为半双工，0为全双工，默认为0 */
    VOS_UINT8                           aucReserve[2];
}NV_UE_EUTRA_FREQ_BAND_INFO_STRU;
/*******************************************************************************
 结构名    : NV_UE_EUTRA_SUPPORT_FREQ_BAND_LIST_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : LTE支持的能力结构,由LTE,WAS GAS共同读取，包括FDD,TDD,以及LTE支持的频段信息

LTE每个BAND的起始频点号
1  0     – 599
2  600   -  1199
3  1200  – 1949
4  1950  – 2399
5  2400  – 2649
6  2650  – 2749
7  2750  – 3449
83 450   – 3799
93 800   – 4149
10 4150  – 4749
11 4750  – 4949
12 5010  -  5179
13 5180  – 5279
14 5280  – 5379
...
17 5730  – 5849
18 5850  – 5999
19 6000  – 6149
20 6150  – 6449
21 6450  – 6599
...
33 36000 – 36199
34 36200 – 36349
35 36350 – 36949
36 36950 – 37549
37 37550 – 37749
38 37750 – 38249
39 38250 -  38649
40 38650 -  39649
64 25450 -  25749
*******************************************************************************/
typedef struct
{
    VOS_UINT16                              usBandCnt;                          /* LTE band个数  默认值4 */
    VOS_UINT8                               aucReserved1[2];                    /* 保留字节，以备用 */

    /* LTE支持的band个数，最大为64 ，默认支持7，20，38 40，即
        stCandBands[0].ucBandNo  =  7
        astCandBands[1].ucBandNo = 20
        astCandBands[2].ucBandNo = 38
        astCandBands[3].ucBandNo = 40  */
    NV_UE_EUTRA_FREQ_BAND_INFO_STRU       astCandBands[NV_ITEM_EUTRA_MAX_SUPPORT_BANDS_NUM];
}NV_UE_EUTRA_SUPPORT_FREQ_BAND_LIST_STRU;

/*****************************************************************************
 结构名    : NV_GUL_SUPPORT_FREQ_BAND_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 记录SYSCFG配置GUL的有效的band结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucValidFlag;
    VOS_UINT8                                       aucReserved1[3];
    NV_UE_SUPPORT_FREQ_BAND_STRU                  stGuCfgBand;
    NV_UE_EUTRA_SUPPORT_FREQ_BAND_LIST_STRU       stLteCfgBand;
}NV_GUL_SUPPORT_FREQ_BAND_STRU;
/* gaojishan-SYSCFG-SAVENV-End */
/* gaojishan-nv-bands-cfg-begin */
#define NV_ITEM_EUTRA_MAX_BANDXX_CAND_BANDS_NUM    (12)
#define NV_ITEM_EUTRA_MAX_CUSTOM_BAND_WIDTH_NUM    (6)
#define NV_LTE_NV_MAX_SUPPORT_BAND                 (43)
#define NV_BAND_IND_64                             (64)
enum RRC_NV_D2DA_BANDXX_FUNC_FLAG_ENUM
{
    RRC_BANDXX_FUNC_INVALIED = 0,
    RRC_BANDXX_FUNC_JAPAN_CUSTOMER,
    RRC_BANDXX_FUNC_CUSTOMIZE_BAND_RANG
};
typedef VOS_UINT16 RRC_NV_D2DA_BANDXX_FUNC_FLAG_ENUM_UINT16;

/*****************************************************************************
 结构名    : LRRC_NV_CUSTOM_BAND_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : band定制信息
*****************************************************************************/
typedef struct
{
    VOS_UINT8                         ucBandWidth;/* 0-5分别对应:1.4m、3m、5m、10m、15m、20m */
    VOS_UINT8                         aucReserved1[3];
    RRC_NV_CSEL_FREQ_BAND_INFO_STRU   stCandBands;
}LRRC_NV_CUSTOM_BAND_INFO_STRU;

/*****************************************************************************
 结构名    : LRRC_NV_BANDXX_CAND_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : band定制信息列表
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucBandInds;
    VOS_UINT8                                       ucCustomBandInfoNum;
    VOS_UINT8                                       aucReserved1[2];
    LRRC_NV_CUSTOM_BAND_INFO_STRU                   astCustomBandInfoList[NV_ITEM_EUTRA_MAX_CUSTOM_BAND_WIDTH_NUM];
}LRRC_NV_BANDXX_CAND_INFO_STRU;

/*****************************************************************************
 结构名    : NV_ID_BANDXX_CAND_INFO_GROUP_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 特殊band定制结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucValidFlag;
    VOS_UINT8                                       ucCandBandNum;
    VOS_UINT8                                       aucReserved1[2];
    LRRC_NV_BANDXX_CAND_INFO_STRU                   astCandBandInfoList[NV_ITEM_EUTRA_MAX_BANDXX_CAND_BANDS_NUM];
}NV_ID_BANDXX_CAND_INFO_GROUP_STRU;
/* gaojishan-nv-bands-cfg-end */

typedef struct
{
    VOS_UINT16                                      usMinRsrpThreshold;
    VOS_UINT16                                      usRsv;
}LRRC_NV_CSEL_GET_SIB_THRESHOLD_STRU;
typedef struct
{
    PS_BOOL_ENUM_UINT8    ucOffSetEnableFlg; /* offset NV使能标记*/
    PS_BOOL_ENUM_UINT8    enR8BasedCellReselFlg;  /* 是否是基于R8的重选准则*/
    VOS_UINT8              aucReservel[2];         /* 保留位*/
    VOS_UINT16             usWRscpThresh;        /* W服务小区的RSCP门限，大于此门限才能使用offset，取绝对值*/
    VOS_UINT16             usWEcnoThresh;        /* W服务小区的ECNO门限，大于此门限才能使用offset，取绝对值*/
    VOS_UINT16             usEutranCellRsrpOffset;  /* EUTRAN小区的RSRP OFFSET*/
    VOS_UINT16             usEutranCellRsrqOffset;  /* EUTRAN小区的RSRQ OFFSET*/
    VOS_UINT16             usLteServRsrpOffSet;
    VOS_UINT16             usLteServRsrqOffSet;
    VOS_UINT16             usUtranRscpOffSet;
    VOS_UINT16             usUtranEcnoOffSet;
}NV_ID_APP_LRRC_RESEL_OFFSET_CFG_STRU;

/* gaojishan-fast-dorm-cfg-3 */
#define LRRC_NV_CTRL_PARA_U8_MAX_LEN                   (16)
#define LRRC_NV_CTRL_PARA_U16_MAX_LEN                  (8)
#define LRRC_NV_CTRL_PARA_U32_MAX_LEN                  (8)

/* gaojishan-fast-dorm-cfg-3 */
#define LRRC_CTRL_PARA_FAST_DORM_DELAY_BIT             (16)
#define LRRC_GET_CTRL_PARA_U8_INDEX( usIndex )         ( (usIndex))
#define LRRC_GET_CTRL_PARA_U16_INDEX( usIndex )        ( (usIndex)-LRRC_NV_CTRL_PARA_U8_MAX_LEN)
#define LRRC_GET_CTRL_PARA_U32_INDEX( usIndex )        ( (usIndex)-LRRC_NV_CTRL_PARA_U8_MAX_LEN - LRRC_NV_CTRL_PARA_U16_MAX_LEN )
#define LRRC_CTRL_PARA_IS_BIT_PRESENT( ulBitMap, ulBit )         ( (ulBitMap)&( 1<< (ulBit) ) )

typedef struct
{
    VOS_UINT32          bitValidMap ; /*BitMap(high--->low) U32,U16,U8,U8 */
    VOS_UINT8           astucCtrlPara[LRRC_NV_CTRL_PARA_U8_MAX_LEN];
    VOS_UINT16          astusCtrlPara[LRRC_NV_CTRL_PARA_U16_MAX_LEN];
    VOS_UINT32          astulCtrlPara[LRRC_NV_CTRL_PARA_U32_MAX_LEN];
}NV_ID_CTRL_PARA_STRU;

/* CMCC-BEGIN */
/*****************************************************************************
 结构名    : LTE_IRAT_REDIR_SWITCH_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 异系统重定向，CMCC G2L重定向4s需求控制开关和G2L自主重定向2s需求控制开关
            沙特 W2L重定向自主重定向2s需求控制开关数据结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucG2LRedirFlag;                 /* G2L重定向4s需求控制开关 */
    VOS_UINT8                                   ucG2LAutoRedirFlag;             /* G2L自主重定向2s需求控制开关 */
    VOS_UINT8                                   ucW2LAutoRedirFlag;             /* W2L自主重定向2s需求控制开关 */
    VOS_UINT8                                   aucReservd1[5];
    VOS_UINT16                                  usG2LRedirTimeLen;              /* G2L重定向时长，默认值为4s，单位为ms */
    VOS_UINT16                                  usG2LAutoRedirTimeLen;          /* G2L自主重定向时长，默认值为2s，单位为ms */
    VOS_UINT16                                  usW2LAutoRedirTimeLen;          /* W2L自主重定向时长，默认值为2s，单位为ms */
    VOS_UINT8                                   aucReservd2[6];
}LTE_IRAT_REDIR_SWITCH_STRU;
/* CMCC-END */
/*****************************************************************************
 结构名    : FC_LTE_TEMPERATURE_LIMIT_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 定义LTE 温控配置结构
*****************************************************************************/
#define FC_UL_THROUGHPUT_MIN_COUNT_NV          (0x03)
typedef struct
{
    VOS_UINT32          ulZeroSupported;
    VOS_UINT32          ulMinThroughput[FC_UL_THROUGHPUT_MIN_COUNT_NV];
} FC_LTE_TEMPERATURE_LIMIT_CONFIG_STRU;

/*****************************************************************************
 结构名    : LTE_APT_TOTAL_SWITCH
 协议表格  :
 ASN.1描述 :
 结构说明  : LTE NV总开关
*****************************************************************************/
typedef struct
{
    VOS_UINT32          ulLteAptTotalSwitch;
    VOS_UINT32          ulRsv;
}LTE_APT_COMMONCTRL_STRU;

#define     LTE_MTC_ABAN_BAND_NUM_MAX   (8)
#define     LTE_MTC_ABAN_PLMN_NUM_MAX   (8)
#define     LTE_MTC_SPAC_BAND_NUM_MAX   (8)

typedef struct
{
    VOS_UINT32                          ulMcc;              /* MCC,3 bytes      */
    VOS_UINT32                          ulMnc;              /* MNC,2 or 3 bytes */
} LRRC_PLMN_ID_STRU;

/* 扫频排除 band NV信息 */
typedef struct
{
    LRRC_PLMN_ID_STRU                 stPlmnID;
    VOS_UINT32                       ulBandNum;                                    /* 配置的Band个数 */
    VOS_UINT8                        ucBand[LTE_MTC_ABAN_BAND_NUM_MAX];            /* 记录不需要扫频的Band */
} LTE_MTC_PLMN_ABAN_BAND_LIST;

/*Delete FDD Band */
typedef struct
{
    VOS_UINT8                     ucSwitchFlag;                                   /* 功能总控开关,0 close; 1 open */
    VOS_UINT8                     ucReserved;
    VOS_UINT16                    usMcc;                                          /* 默认填写 460  */
}LTE_CUSTOM_MCC_INFO_STRU;

extern  LTE_CUSTOM_MCC_INFO_STRU g_stLRrcDelFddBand;
/*Delete FDD Band */

typedef struct
{
    VOS_UINT32                        ulPlmnNum;
    LTE_MTC_PLMN_ABAN_BAND_LIST       astAbandPlmnList[LTE_MTC_ABAN_PLMN_NUM_MAX]; /* Plmn和BandList */
} LTE_MTC_ABANDON_EUTRA_BAND_SCAN_STRU;


/* 扫频特殊band 设置信息 */
typedef struct
{
     VOS_UINT8                      ucBand;                                        /* 指示Band信息 */
     VOS_UINT8                      aucRsv[3];                                     /*保留位*/
     VOS_UINT16                     usFreqBegin;
     VOS_UINT16                     usFreqEnd;
}LTE_MTC_SPAC_BAND_CONFIG_LIST;

typedef struct
{
     VOS_UINT32                     ulBandNum;
     VOS_UINT32                     ulSpacBandSwitch;                               /* 0 close; 1 open*/
     LTE_MTC_SPAC_BAND_CONFIG_LIST  astSpacBandList[LTE_MTC_SPAC_BAND_NUM_MAX];     /* 记录需要扫频特殊配置的Band */
} LTE_MTC_SPAC_BAND_SCAN_CONFIG_STRU;
extern LTE_MTC_ABANDON_EUTRA_BAND_SCAN_STRU g_stAbandEutraBandInfo;
extern LTE_MTC_SPAC_BAND_SCAN_CONFIG_STRU   g_stSpacBandInfo;

/* MTC NOTCH add begin  */
typedef struct
{
     VOS_UINT16                     usSwitchFlag;                                   /* 功能总控开关 */
     VOS_UINT8                      aucRcve[2];                                     /* 保留位 */
} LTE_MTC_NOTCH_FEATURE_STRU;

/* MTC NOTCH add end  */
/*****************************************************************************
 结构名    : LTE_RRC_THRESHOLD_STRU
 协议表格  :
 ASN.1描述 :
        ulCdrxPeriod:使用Balong基线值
        lGeranBasiclag: 使用Balong基线值
        lGeranBasiStartThres:使用Balong基线值
        ulCdrxFilterSwitch:使用Balong基线值
        ulAbandinFristItraMeasFlg:丢弃第一次异系统测量结果，0:不丢弃。1:丢弃。Balong基线默认值:0.
        ulTdsT315Len:  T315定时器长度，单位秒。Balong基线默认值为0，产线需要自行设置，建议值 5.
        ulHrpdIdleMeasIndInterTime:hrpd上报空闲态测量Ind的时间间隔，单位毫秒.Balong基线默认值:200.
        ulHrpdConnMeasIndInterTime:hrpd上报连接态测量Ind的时间间隔，单位毫秒.Balong基线默认值:200.
        ultimerLrrcWaitCdmaCnfLen:等待hrpd重选、重定向结果IND定时器时长,单位毫秒.Balong基线默认值:30000.
        ulTReselectUtran: 自定义3G重选定时器长度.单位:秒。Balong基线默认值为0，产线需要自行设置，建议值 60.
        ulTReselectGsm: 自定义2G重选定时器长度.单位:秒。Balong基线默认值为0，产线需要自行设置，建议值 50.
 结构说明  : LTE RRC 阈值
*****************************************************************************/
/* begin:Abandon Frist Itra Meas Result */
typedef struct
{
    VOS_UINT32          ulCdrxPeriod;
    VOS_INT32           lGeranBasiclag;
    VOS_INT32           lGeranBasiStartThres;
    VOS_UINT32          ulCdrxFilterSwitch;
    VOS_UINT32          ulAbandinFristItraMeasFlg;
    VOS_UINT32          ulTdsT315Len;
    VOS_UINT32          ulHrpdIdleMeasIndInterTime;
    VOS_UINT32          ulHrpdConnMeasIndInterTime;
    VOS_UINT32          ultimerLrrcWaitCdmaCnfLen;
    VOS_UINT32          ulTReselectUtran;
    VOS_UINT32          ulTReselectGsm;
    /* mod for FreqSearchEnhance begin */
    VOS_UINT32          ulFreqSearchEnhanceFlag;
    VOS_UINT32          ulFreqSearchEnhanceSrchCnt;
    VOS_UINT32          ulFreqSearchEnhanceSrchThres;
    /* mod for FreqSearchEnhance end */
    VOS_UINT32          aulRsv1;
    VOS_UINT32          aulRsv2;
    VOS_UINT32          aulRsv3;
    VOS_UINT32          aulRsv4;
    VOS_INT32           lDelfaultqQualMin;/*SIB1中不含qQualMin时，使用一个默认值判断是否起同频测量*/
    VOS_UINT32          aulRsv5;
    VOS_UINT32          aulRsv6;
    VOS_UINT32          aulRsv7;
    VOS_UINT32          aulRsv8;
    VOS_UINT32          aulRsv9;
    VOS_UINT32          aulRsv10;
    VOS_UINT32          aulRsv11;
    VOS_UINT32          aulRsv12;
    VOS_UINT32          aulRsv13;
    VOS_UINT32          aulRsv14;
    VOS_UINT32          aulRsv15;
    VOS_UINT32          aulRsv16;
    VOS_UINT32          aulRsv17;
}LTE_RRC_THRESHOLD_STRU;
extern VOS_UINT32   g_ulAbandinFristItraMeasFlg;
/* end:Abandon Frist Itra Meas Result */

extern VOS_UINT8    g_ucTReselectUtran;
extern VOS_UINT8    g_ucTReselectGsm;

#define         MAX_IRAT_TDS_UE_CAPABILITY_LENGHT           (100)
typedef struct
{
     VOS_UINT16                     usSwitchFlag;                                   /* 功能总控开关: 默认打开使用NV配置的ue能力码流，特殊情况下使用自己代码里的*/
     VOS_UINT16                     usLength;                                       /* UE能力码流长度 */
     VOS_UINT8                      aucCapInfo[MAX_IRAT_TDS_UE_CAPABILITY_LENGHT];                                /* UE能力码流 */
} LTE_IRAT_TDS_UE_CAPABILITY_STRU;
/*****************************************************************************
 结构名    : LTE_RRC_EXTBANDINFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : Band28全频段特性新增NV
             ucflag:1表示扩展BAND功能打开；0表示关闭
             ucBandnum:表示有几个BAND需要用到扩展BAND号
             aucRsv[]:预留
             aucBandInd[]:需要扩展BAND号的BAND列表
*****************************************************************************/
typedef struct
{
    VOS_UINT8          ucflag;
    VOS_UINT8          ucBandnum;
    VOS_UINT8          aucRsv[2];
    VOS_UINT8          aucBandInd[8];
}LTE_RRC_EXTBANDINFO_STRU;

/*****************************************************************************
 结构名    : LRRC_NV_EXT_BAND_LIST_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 在不同带宽下的分段频段NV结构
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usBandInd;      /* 基本的BAND 号*/
    VOS_UINT16                          usScellBandInd;      /* Scell的BAND 号*/

	/* Band内候补带宽频段信息 */
    LRRC_NV_SUPPORT_BAND_LIST_STRU      astBandInfoWithBandWidth[6];/*RRC_BAND_WIDTH_BUTT*/
}LRRC_NV_EXT_BAND_LIST_STRU;

/*****************************************************************************
 结构名    : LTE_RRC_EXTBANDINFO_WITH_BANDWIDTH_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : UE支持的频段在不同带宽下的分段频段NV结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8          ucActive;
    VOS_UINT8          ucScellEnable;
    VOS_UINT16         usBandCount;
    LRRC_NV_EXT_BAND_LIST_STRU          stCandBandsInfo[8]; /*支持最多8个频定制分频*/
}LTE_RRC_EXTBANDINFO_WITH_BANDWIDTH_STRU;

/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/
extern PS_BAND_ENUM_UINT8 g_enBandInd;
extern VOS_UINT8 g_ucBandInd;
extern  VOS_UINT32  g_enBandHI6360NvId[PS_BAND_BUTT][PS_NV_IDX_BUTT];
#if 0
extern VOS_UINT32  g_enBandNvId[PS_BAND_BUTT][PS_NV_IDX_BUTT];
#endif
#if (VOS_OS_VER != VOS_WIN32)
/*关闭TA Timer的开关，0:开关关闭，即TA Timer生效 1:开关打开，即TA Timer不生效*/
extern VOS_UINT32  g_ulCloseTaTimer;

/*关闭SR触发随机接入的开关，0:开关关闭，即SR触发随机接入生效 1:开关打开，即SR触发随机接入不生效*/
extern VOS_UINT32  g_ulCloseSrRandFlag;

/*关闭SR触发机制开关，0:开关关闭，即SR不以规整BSR触发为前提 1:开关打开，即SR以规整BSR触发为前提*/
extern VOS_UINT32  g_ulSrTrigFlag;

/*设置是否将板间消息转发一份至PC以解析分析*/
extern VOS_UINT32  g_ulIfForwardToPc;

/* 加密的开关:0-打开加密，1-关闭加密*/
extern VOS_UINT32  g_ulSmcControl;

/* DCM定制需求，GU到L的切换不考虑被禁TA的开关 */
extern VOS_UINT32  g_ulHoIgnoreForbidTaFlag;
/* 定制需求，模内切换不考虑被禁TA的开关 1:打开 0:关闭 默认关闭 */
extern VOS_UINT32    g_ulIntraHoIgnoreForbidTaFlag;

/*外场测试桩代码开关 0:关闭  1:打开.默认为关闭*/
extern VOS_UINT32 g_ulFieldTestSwitch;

/*规避eNB的TDD的接入问题*/

/*判断是否BAR小区*/
extern VOS_UINT32 g_ulCloseBarCell;

/* DRX Control Flag  0: Close 1: Open */
extern VOS_UINT32 g_ulDrxControlFlag;

/* 上下行子帧配比，默认为1 */
extern VOS_UINT32 g_ulCfgSubFrameAssign;

/* 特殊子帧配置，默认为7 */
extern VOS_UINT32 g_ulSubFramePattern;

/* 天线个数 */
extern VOS_UINT32 g_ulPsCfgDspAntCnt;

#if 0
extern VOS_UINT32 g_ulPsCfgDspRatMod;
#endif

/* PCO功能开关，0为关闭，1为打开。默认为打开 */
extern VOS_UINT32 g_ulPcoFlag;

/* 删除SDF时是否携带Qos信息功能开关，0为关闭，1为打开。默认为关闭 */
extern VOS_UINT32 g_ulDelSdfWithQosFlag;

/* UE安全能力校验开关，0为打开，8为关闭。默认为打开 */
extern VOS_UINT32 g_ulUeSecuCapMatch;

/* TAU消息加密开关，0为加密，1为不加密。默认为不加密 */
extern VOS_UINT32 g_ulTauCipheredFlag;

/*流控算法开关*/
extern VOS_UINT32  g_ulFlowCtrlFlag;

/*流控调整CPU剩余目标值*/
extern VOS_UINT32  g_ulFcPdcpTarget;

/*漏桶算法的最大值*/
extern VOS_UINT32   g_ulTargetIPMax;
extern VOS_UINT32   g_ulSendSduMax;

/*定义漏桶算法阈值*/
extern VOS_UINT32  g_ulDlSduMax;
extern VOS_UINT32  g_ulULIpMax;

/*漏桶算法的测量周期，单位ms*/
extern VOS_UINT32  g_ulMeasGap;
extern VOS_UINT32  g_ulSduGap;
/*流控初始化选择*/
extern VOS_UINT32  g_ulFcInitFlag ;

/*用于对Msg4 6种头格式的CR修改前的解析处理，1表示可以解析所有相关的Msg4头，
表示只能解析最新协议规定的6种格式，默认是0*/
extern VOS_UINT32  g_ulMsg4ForOldCrFlag;

/* GCF是否支持24.301 Table D.1.1中建链原因设置 0x00000004,支持，0不支持 */
extern VOS_UINT32 g_ulGcfEstCauseFlag;

/* SMC功能是否支持测试模式，缺省支持，取值为0x00000008 */
extern VOS_UINT32  g_ulSmcFuncTestMode;

/* GCF打桩通过CDRX相关用例，实际场景为了降功耗不打开该开关，位域开关,0表示默认不打开对应外场测试
1表示打开对应GCF测试，默认值是0
extern VOS_UINT32  g_ulGcfConnDrxStubFlag;*/

#endif
/* 产品选择开关 */
extern VOS_UINT32  g_ulPsSupportBand64Flg;
extern VOS_UINT32  g_ulPsPagingConnRelFlg;
extern VOS_UINT32  g_ulPsUlDrbDiscardFlag;
extern VOS_UINT32  g_ulMbmsSupportSwitch;
extern VOS_UINT32  g_ulPsBandwidthSupportFlg;
/* modify by lishangfeng freq all begin */
extern VOS_UINT32  g_ulPsFreqInAllBandWidthFlg;

extern VOS_UINT32  g_ulHoFailFlag;
extern VOS_UINT16  g_usHoFailT304;
/* gaojishan-SYSCFG-SAVENV-Begin */
extern VOS_UINT32  gulJpUBand1Switch;

/*Begin: for sbm delete wcdma band9  */
extern VOS_UINT8       gucJpUband1MncCnt;
extern VOS_UINT8       gaucJpUband1Mnc[3];
extern VOS_UINT8       gaucJpUband1Mcc[3];
extern VOS_UINT8       gaucJpUband2Mcc[3];
/*End: for sbm delete wcdma band9  */
/* gaojishan-SYSCFG-SAVENV-End */
extern VOS_UINT32  g_ulLReestIratCellSrchFlg;
/* gaojishan-nccpermit */
extern VOS_UINT32 g_ulNccPermitFlag;
extern VOS_UINT32  g_ulLBgsSupportFlg;
/* gaojishan-reest-measGap*/
extern VOS_UINT32  g_ulLBgsLSupportFlg;

extern VOS_UINT32 g_ulLTEReestMeasGapSetupFlag;
extern VOS_UINT32 g_ulLTEConnToIdleFlag;


/* gaojishan-PLMN_EXACTLY_COMPARE_FLG */
extern VOS_UINT32 g_ulPlmnExactCmpFlg;
/* gaojishan-SoftBank-定制标志:true,set Band41 range */
extern VOS_UINT32 gulSoftBankFlag ;
/* gaojishan-nccpermit-2 */
extern VOS_UINT32 g_ulNoIdleNccPermitFlag;

/* gaojishan-dcom-resel-cfg */
extern VOS_UINT32 g_ulLteJpDcomUseR8Flag;
extern VOS_UINT32 g_ulLteJpDccomRelOffSetFlag;
extern VOS_UINT32 g_ulLteUtranEvaFlag;
/* gaojishan-fast-dorm-cfg */
extern VOS_UINT32 g_ulLteJpFastdormFlag;
/* gaojishan-fast-dorm-cfg-3 */
extern VOS_UINT32 g_usLteJpFastdormDelayValue;

extern VOS_UINT32 g_ulDlCtrlPduNotifyFlag;

/* gaojishan-CMAS-Begin */
/* >0: cmas report after rrc auth(after camp in fact); 0:cmas report even when cell searching*/
extern VOS_UINT32                              gul_CmasRptBeforeAuthSwitch;
/* gaojishan-CMAS-End */

extern VOS_UINT32 g_ulSscSupportFlag;
extern VOS_UINT32 g_ulAdrxSupportFlag;
/* niuxiufan taiwan modify begin */
extern VOS_UINT32 g_ulRedirNotBandScanFlg;
/* niuxiufan taiwan modify end */
/* niuxiufan rrc release modify begin */
extern VOS_UINT32 g_ulNotTryFakeCellFlg;
/* niuxiufan rrc release modify end */
/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/


/*****************************************************************************
  9 OTHERS
*****************************************************************************/










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

#endif /* end of PsNvInterface.h */

