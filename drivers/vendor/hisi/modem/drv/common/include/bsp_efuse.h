/*************************************************************************
*   ��Ȩ����(C) 1987-2020, ���ڻ�Ϊ�������޹�˾.
*
*   �� �� �� :  bsp_efuse.h
*
*   ��    �� :  liuwenhui
*
*   ��    �� :  bsp_efuse ��ͷ�ļ�
*
*   �޸ļ�¼ :  2013��12��23��  v1.00  liuwenhui  ����
*
*************************************************************************/

#ifndef __BSP_EFUSE_H__
#define __BSP_EFUSE_H__

#include "osl_types.h"

#define EFUSE_OK               (0)
#define EFUSE_ERROR            (-1)

#define EFUSE_GROUP_SIZE        (4)
#define EFUSE_MAX_ALLOW_SIZE    (16)

#define  efuse_print_error(fmt, ...)    (bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_EFUSE, "[efuse]: <%s> <%d> "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__))
#define  efuse_print_info(fmt, ...)     (bsp_trace(BSP_LOG_LEVEL_ERROR,  BSP_MODU_EFUSE, "[efuse]: "fmt, ##__VA_ARGS__))


typedef enum
{
    EFUSE_READ,
    EFUSE_WRITE    

}EFUSE_OPT;

typedef struct
{
    EFUSE_OPT opt;
    u32 start;
    u32 len;
    int ret;
    u32 buf[EFUSE_MAX_ALLOW_SIZE];
}EFUSE_DATA_STRU;
#ifdef CONFIG_EFUSE
/*****************************************************************************
* �� �� ��  : bsp_efuse_read
*
* ��������  : �����ȡEFUSE�е�����
*
* �������  : group  ��ʼgroup
*                   num  ���鳤��(word��,������16)
* �������  : pBuf ��EFUSE�е�����
*
* �� �� ֵ  : 
*
* ����˵��  : 
*
*****************************************************************************/
int bsp_efuse_read(u32* pBuf, const u32 group, const u32 num);

/*****************************************************************************
* �� �� ��  : bsp_efuse_write
*
* ��������  : ��дEfsue
*
* �������  : pBuf:����д��EFUSEֵ
*                 group,Efuse��ַƫ��
*                 len,��д����
* �������  :
*
* �� �� ֵ  :
*
* ����˵��  :
*
*****************************************************************************/
int bsp_efuse_write( u32 *pBuf, const u32 group, const u32 len);
#else
static inline int bsp_efuse_read(u32* pBuf, const u32 group, const u32 num)
{
    return 0;
}

 static inline int bsp_efuse_write( u32 *pBuf, const u32 group, const u32 len)
{
    return 0;
}

#endif
/*****************************************************************************
* �� �� ��  : bsp_efuse_show
*
* ��������  : ��ʾefsue������Ϣ
*
* �������  : 
* 
* �������  :
*
* �� �� ֵ  :
*
* ����˵��  :
*
*****************************************************************************/
void bsp_efuse_show(void);

#endif