

#ifndef __AT_CSIMAGENT_H__
#define __AT_CSIMAGENT_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*******************************************************************************
  3 枚举定义
*******************************************************************************/
/*****************************************************************************
 枚举名    :AT_CSIMA_MSGID_ENUM
 结构说明  :AT和CSIMA内部消息ID枚举
*****************************************************************************/
enum AT_CSIMA_MSGID_ENUM
{
    AT_CSIMA_RESET_IND_MSG              = 0,    /* AT通知CSIMA复位状态 */

    AT_CSIMA_MSGID_BUTT
};
typedef VOS_UINT16     AT_CSIMA_MSGID_ENUM_UINT32;

/*****************************************************************************
 枚举名    : CBP_MODEM_RESET_STATUS_ENUM
 结构说明  : CBP Modem 复位状态枚举
*****************************************************************************/
enum CBP_MODEM_RESET_STATUS_ENUM
{
    CBP_MODEM_RESET_BEGIN            = 0x00,    /* CBP Modem开始复位 */
    CBP_MODEM_RESET_SUCC             = 0x01,    /* CBP Modem复位成功结束 */
    CBP_MODEM_RESET_FAIL             = 0x02,    /* CBP Modem复位失败 */
    CBP_MODEM_RESET_BUTT
};
typedef VOS_UINT32     CBP_MODEM_RESET_STATUS_ENUM_UINT32;

/*****************************************************************************
 结构名    :AT_CSIMA_RESET_STATUS_IND_MSG_STRU
 结构说明  :AT通知CSIMA VIA Modem复位状态消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                               ulMsgId;                     /* 消息ID */
    CBP_MODEM_RESET_STATUS_ENUM_UINT32       enVIAModemStatus;            /* 当前复位Modem状态: 0：开始复位 1：复位成功结束2：复位失败 */

}AT_CSIMA_RESET_STATUS_IND_MSG_STRU;



/*****************************************************************************
  4 函数声明
*****************************************************************************/




/*****************************************************************************
  5 全局变量声明
*****************************************************************************/


/*****************************************************************************
  6 OTHERS定义
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

#endif /* end of AtCsimagent.h*/

