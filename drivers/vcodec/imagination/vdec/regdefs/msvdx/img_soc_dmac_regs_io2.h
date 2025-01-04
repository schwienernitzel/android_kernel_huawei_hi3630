/*!
 *****************************************************************************
 *
 * @File       img_soc_dmac_regs_io2.h
 * @Description    This file contains the IMG_SOC_DMAC_REGS_IO2_H Definitions.
 * ---------------------------------------------------------------------------
 *
 * Copyright (c) Imagination Technologies Ltd.
 * 
 * The contents of this file are subject to the MIT license as set out below.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 * 
 * Alternatively, the contents of this file may be used under the terms of the 
 * GNU General Public License Version 2 ("GPL")in which case the provisions of
 * GPL are applicable instead of those above. 
 * 
 * If you wish to allow use of your version of this file only under the terms 
 * of GPL, and not to allow others to use your version of this file under the 
 * terms of the MIT license, indicate your decision by deleting the provisions 
 * above and replace them with the notice and other provisions required by GPL 
 * as set out in the file called "GPLHEADER" included in this distribution. If 
 * you do not delete the provisions above, a recipient may use your version of 
 * this file under the terms of either the MIT license or GPL.
 * 
 * This License is also included in this distribution in the file called 
 * "MIT_COPYING".
 *
 *****************************************************************************/


#if !defined (__IMG_SOC_DMAC_REGS_IO2_H__)
#define __IMG_SOC_DMAC_REGS_IO2_H__

#ifdef __cplusplus
extern "C" {
#endif


#define DMAC_DMAC_SETUP_OFFSET		(0x0000)
#define DMAC_DMAC_SETUP_STRIDE		(32)
#define DMAC_DMAC_SETUP_NO_ENTRIES		(6)

/* DMAC, DMAC_SETUP, START_ADDRESS
*/
#define DMAC_DMAC_SETUP_START_ADDRESS_MASK		(0xFFFFFFFF)
#define DMAC_DMAC_SETUP_START_ADDRESS_LSBMASK		(0xFFFFFFFF)
#define DMAC_DMAC_SETUP_START_ADDRESS_SHIFT		(0)
#define DMAC_DMAC_SETUP_START_ADDRESS_LENGTH		(32)
#define DMAC_DMAC_SETUP_START_ADDRESS_DEFAULT		(0)
#define DMAC_DMAC_SETUP_START_ADDRESS_SIGNED_FIELD	(IMG_FALSE)

#define DMAC_DMAC_COUNT_OFFSET		(0x0004)
#define DMAC_DMAC_COUNT_STRIDE		(32)
#define DMAC_DMAC_COUNT_NO_ENTRIES		(6)

/* DMAC, DMAC_COUNT, LIST_IEN
*/
#define DMAC_DMAC_COUNT_LIST_IEN_MASK		(0x80000000)
#define DMAC_DMAC_COUNT_LIST_IEN_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_LIST_IEN_SHIFT		(31)
#define DMAC_DMAC_COUNT_LIST_IEN_LENGTH		(1)
#define DMAC_DMAC_COUNT_LIST_IEN_DEFAULT		(0)
#define DMAC_DMAC_COUNT_LIST_IEN_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, BSWAP
*/
#define DMAC_DMAC_COUNT_BSWAP_MASK		(0x40000000)
#define DMAC_DMAC_COUNT_BSWAP_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_BSWAP_SHIFT		(30)
#define DMAC_DMAC_COUNT_BSWAP_LENGTH		(1)
#define DMAC_DMAC_COUNT_BSWAP_DEFAULT		(0)
#define DMAC_DMAC_COUNT_BSWAP_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, TRANSFER_IEN
*/
#define DMAC_DMAC_COUNT_TRANSFER_IEN_MASK		(0x20000000)
#define DMAC_DMAC_COUNT_TRANSFER_IEN_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_TRANSFER_IEN_SHIFT		(29)
#define DMAC_DMAC_COUNT_TRANSFER_IEN_LENGTH		(1)
#define DMAC_DMAC_COUNT_TRANSFER_IEN_DEFAULT		(0)
#define DMAC_DMAC_COUNT_TRANSFER_IEN_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, PW
*/
#define DMAC_DMAC_COUNT_PW_MASK		(0x18000000)
#define DMAC_DMAC_COUNT_PW_LSBMASK		(0x00000003)
#define DMAC_DMAC_COUNT_PW_SHIFT		(27)
#define DMAC_DMAC_COUNT_PW_LENGTH		(2)
#define DMAC_DMAC_COUNT_PW_DEFAULT		(0)
#define DMAC_DMAC_COUNT_PW_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, DIR
*/
#define DMAC_DMAC_COUNT_DIR_MASK		(0x04000000)
#define DMAC_DMAC_COUNT_DIR_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_DIR_SHIFT		(26)
#define DMAC_DMAC_COUNT_DIR_LENGTH		(1)
#define DMAC_DMAC_COUNT_DIR_DEFAULT		(0)
#define DMAC_DMAC_COUNT_DIR_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, PI
*/
#define DMAC_DMAC_COUNT_PI_MASK		(0x03000000)
#define DMAC_DMAC_COUNT_PI_LSBMASK		(0x00000003)
#define DMAC_DMAC_COUNT_PI_SHIFT		(24)
#define DMAC_DMAC_COUNT_PI_LENGTH		(2)
#define DMAC_DMAC_COUNT_PI_DEFAULT		(0)
#define DMAC_DMAC_COUNT_PI_SIGNED_FIELD	(IMG_FALSE)

enum DMAC_DMAC_COUNT_PI_ENUM {
	DMAC_PI_1 = 0x2,
	DMAC_PI_2 = 0x1,
	DMAC_PI_4 = 0x0,
};

/* DMAC, DMAC_COUNT, LIST_FIN_CTL
*/
#define DMAC_DMAC_COUNT_LIST_FIN_CTL_MASK		(0x00400000)
#define DMAC_DMAC_COUNT_LIST_FIN_CTL_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_LIST_FIN_CTL_SHIFT		(22)
#define DMAC_DMAC_COUNT_LIST_FIN_CTL_LENGTH		(1)
#define DMAC_DMAC_COUNT_LIST_FIN_CTL_DEFAULT		(0)
#define DMAC_DMAC_COUNT_LIST_FIN_CTL_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, DREQ
*/
#define DMAC_DMAC_COUNT_DREQ_MASK		(0x00100000)
#define DMAC_DMAC_COUNT_DREQ_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_DREQ_SHIFT		(20)
#define DMAC_DMAC_COUNT_DREQ_LENGTH		(1)
#define DMAC_DMAC_COUNT_DREQ_DEFAULT		(0)
#define DMAC_DMAC_COUNT_DREQ_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, SRST
*/
#define DMAC_DMAC_COUNT_SRST_MASK		(0x00080000)
#define DMAC_DMAC_COUNT_SRST_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_SRST_SHIFT		(19)
#define DMAC_DMAC_COUNT_SRST_LENGTH		(1)
#define DMAC_DMAC_COUNT_SRST_DEFAULT		(0)
#define DMAC_DMAC_COUNT_SRST_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, LIST_EN
*/
#define DMAC_DMAC_COUNT_LIST_EN_MASK		(0x00040000)
#define DMAC_DMAC_COUNT_LIST_EN_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_LIST_EN_SHIFT		(18)
#define DMAC_DMAC_COUNT_LIST_EN_LENGTH		(1)
#define DMAC_DMAC_COUNT_LIST_EN_DEFAULT		(0)
#define DMAC_DMAC_COUNT_LIST_EN_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, ENABLE_2D_MODE
*/
#define DMAC_DMAC_COUNT_ENABLE_2D_MODE_MASK		(0x00020000)
#define DMAC_DMAC_COUNT_ENABLE_2D_MODE_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_ENABLE_2D_MODE_SHIFT		(17)
#define DMAC_DMAC_COUNT_ENABLE_2D_MODE_LENGTH		(1)
#define DMAC_DMAC_COUNT_ENABLE_2D_MODE_DEFAULT		(0)
#define DMAC_DMAC_COUNT_ENABLE_2D_MODE_SIGNED_FIELD	(IMG_FALSE)

enum DMAC_DMAC_COUNT_ENABLE_2D_MODE_ENUM {
	DMAC_ENABLE_2D_MODE_ENABLED = 0x1,
	DMAC_ENABLE_2D_MODE_DISABLED = 0x0,
};

/* DMAC, DMAC_COUNT, EN
*/
#define DMAC_DMAC_COUNT_EN_MASK		(0x00010000)
#define DMAC_DMAC_COUNT_EN_LSBMASK		(0x00000001)
#define DMAC_DMAC_COUNT_EN_SHIFT		(16)
#define DMAC_DMAC_COUNT_EN_LENGTH		(1)
#define DMAC_DMAC_COUNT_EN_DEFAULT		(0)
#define DMAC_DMAC_COUNT_EN_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_COUNT, CNT
*/
#define DMAC_DMAC_COUNT_CNT_MASK		(0x0000FFFF)
#define DMAC_DMAC_COUNT_CNT_LSBMASK		(0x0000FFFF)
#define DMAC_DMAC_COUNT_CNT_SHIFT		(0)
#define DMAC_DMAC_COUNT_CNT_LENGTH		(16)
#define DMAC_DMAC_COUNT_CNT_DEFAULT		(0)
#define DMAC_DMAC_COUNT_CNT_SIGNED_FIELD	(IMG_FALSE)

#define DMAC_DMAC_PERIPH_OFFSET		(0x0008)
#define DMAC_DMAC_PERIPH_STRIDE		(32)
#define DMAC_DMAC_PERIPH_NO_ENTRIES		(6)

/* DMAC, DMAC_PERIPH, ACC_DEL
*/
#define DMAC_DMAC_PERIPH_ACC_DEL_MASK		(0xE0000000)
#define DMAC_DMAC_PERIPH_ACC_DEL_LSBMASK		(0x00000007)
#define DMAC_DMAC_PERIPH_ACC_DEL_SHIFT		(29)
#define DMAC_DMAC_PERIPH_ACC_DEL_LENGTH		(3)
#define DMAC_DMAC_PERIPH_ACC_DEL_DEFAULT		(0)
#define DMAC_DMAC_PERIPH_ACC_DEL_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_PERIPH, INCR
*/
#define DMAC_DMAC_PERIPH_INCR_MASK		(0x08000000)
#define DMAC_DMAC_PERIPH_INCR_LSBMASK		(0x00000001)
#define DMAC_DMAC_PERIPH_INCR_SHIFT		(27)
#define DMAC_DMAC_PERIPH_INCR_LENGTH		(1)
#define DMAC_DMAC_PERIPH_INCR_DEFAULT		(0)
#define DMAC_DMAC_PERIPH_INCR_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_PERIPH, BURST
*/
#define DMAC_DMAC_PERIPH_BURST_MASK		(0x07000000)
#define DMAC_DMAC_PERIPH_BURST_LSBMASK		(0x00000007)
#define DMAC_DMAC_PERIPH_BURST_SHIFT		(24)
#define DMAC_DMAC_PERIPH_BURST_LENGTH		(3)
#define DMAC_DMAC_PERIPH_BURST_DEFAULT		(0)
#define DMAC_DMAC_PERIPH_BURST_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_PERIPH, EXT_BURST
*/
#define DMAC_DMAC_PERIPH_EXT_BURST_MASK		(0x000F0000)
#define DMAC_DMAC_PERIPH_EXT_BURST_LSBMASK		(0x0000000F)
#define DMAC_DMAC_PERIPH_EXT_BURST_SHIFT		(16)
#define DMAC_DMAC_PERIPH_EXT_BURST_LENGTH		(4)
#define DMAC_DMAC_PERIPH_EXT_BURST_DEFAULT		(0)
#define DMAC_DMAC_PERIPH_EXT_BURST_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_PERIPH, EXT_SA
*/
#define DMAC_DMAC_PERIPH_EXT_SA_MASK		(0x0000000F)
#define DMAC_DMAC_PERIPH_EXT_SA_LSBMASK		(0x0000000F)
#define DMAC_DMAC_PERIPH_EXT_SA_SHIFT		(0)
#define DMAC_DMAC_PERIPH_EXT_SA_LENGTH		(4)
#define DMAC_DMAC_PERIPH_EXT_SA_DEFAULT		(0)
#define DMAC_DMAC_PERIPH_EXT_SA_SIGNED_FIELD	(IMG_FALSE)

#define DMAC_DMAC_IRQ_STAT_OFFSET		(0x000C)
#define DMAC_DMAC_IRQ_STAT_STRIDE		(32)
#define DMAC_DMAC_IRQ_STAT_NO_ENTRIES		(6)

/* DMAC, DMAC_IRQ_STAT, LIST_FIN
*/
#define DMAC_DMAC_IRQ_STAT_LIST_FIN_MASK		(0x00200000)
#define DMAC_DMAC_IRQ_STAT_LIST_FIN_LSBMASK		(0x00000001)
#define DMAC_DMAC_IRQ_STAT_LIST_FIN_SHIFT		(21)
#define DMAC_DMAC_IRQ_STAT_LIST_FIN_LENGTH		(1)
#define DMAC_DMAC_IRQ_STAT_LIST_FIN_DEFAULT		(0)
#define DMAC_DMAC_IRQ_STAT_LIST_FIN_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_IRQ_STAT, LIST_INT
*/
#define DMAC_DMAC_IRQ_STAT_LIST_INT_MASK		(0x00100000)
#define DMAC_DMAC_IRQ_STAT_LIST_INT_LSBMASK		(0x00000001)
#define DMAC_DMAC_IRQ_STAT_LIST_INT_SHIFT		(20)
#define DMAC_DMAC_IRQ_STAT_LIST_INT_LENGTH		(1)
#define DMAC_DMAC_IRQ_STAT_LIST_INT_DEFAULT		(0)
#define DMAC_DMAC_IRQ_STAT_LIST_INT_SIGNED_FIELD	(IMG_FALSE)

enum DMAC_DMAC_IRQ_STAT_LIST_INT_ENUM {
	DMAC_LIST_INT_ENABLE = 0x1,
	DMAC_LIST_INT_DISABLE = 0x0,
};

/* DMAC, DMAC_IRQ_STAT, TRANSFER_FIN
*/
#define DMAC_DMAC_IRQ_STAT_TRANSFER_FIN_MASK		(0x00020000)
#define DMAC_DMAC_IRQ_STAT_TRANSFER_FIN_LSBMASK		(0x00000001)
#define DMAC_DMAC_IRQ_STAT_TRANSFER_FIN_SHIFT		(17)
#define DMAC_DMAC_IRQ_STAT_TRANSFER_FIN_LENGTH		(1)
#define DMAC_DMAC_IRQ_STAT_TRANSFER_FIN_DEFAULT		(0)
#define DMAC_DMAC_IRQ_STAT_TRANSFER_FIN_SIGNED_FIELD	(IMG_FALSE)

#define DMAC_DMAC_2D_MODE_OFFSET		(0x0010)
#define DMAC_DMAC_2D_MODE_STRIDE		(32)
#define DMAC_DMAC_2D_MODE_NO_ENTRIES		(6)

/* DMAC, DMAC_2D_MODE, REP_COUNT
*/
#define DMAC_DMAC_2D_MODE_REP_COUNT_MASK		(0x7FF00000)
#define DMAC_DMAC_2D_MODE_REP_COUNT_LSBMASK		(0x000007FF)
#define DMAC_DMAC_2D_MODE_REP_COUNT_SHIFT		(20)
#define DMAC_DMAC_2D_MODE_REP_COUNT_LENGTH		(11)
#define DMAC_DMAC_2D_MODE_REP_COUNT_DEFAULT		(0)
#define DMAC_DMAC_2D_MODE_REP_COUNT_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_2D_MODE, LINE_ADDR_OFFSET
*/
#define DMAC_DMAC_2D_MODE_LINE_ADDR_OFFSET_MASK		(0x000FFC00)
#define DMAC_DMAC_2D_MODE_LINE_ADDR_OFFSET_LSBMASK		(0x000003FF)
#define DMAC_DMAC_2D_MODE_LINE_ADDR_OFFSET_SHIFT		(10)
#define DMAC_DMAC_2D_MODE_LINE_ADDR_OFFSET_LENGTH		(10)
#define DMAC_DMAC_2D_MODE_LINE_ADDR_OFFSET_DEFAULT		(0)
#define DMAC_DMAC_2D_MODE_LINE_ADDR_OFFSET_SIGNED_FIELD	(IMG_FALSE)

/* DMAC, DMAC_2D_MODE, ROW_LENGTH
*/
#define DMAC_DMAC_2D_MODE_ROW_LENGTH_MASK		(0x000003FF)
#define DMAC_DMAC_2D_MODE_ROW_LENGTH_LSBMASK		(0x000003FF)
#define DMAC_DMAC_2D_MODE_ROW_LENGTH_SHIFT		(0)
#define DMAC_DMAC_2D_MODE_ROW_LENGTH_LENGTH		(10)
#define DMAC_DMAC_2D_MODE_ROW_LENGTH_DEFAULT		(0)
#define DMAC_DMAC_2D_MODE_ROW_LENGTH_SIGNED_FIELD	(IMG_FALSE)

#define DMAC_DMAC_PERIPHERAL_ADDR_OFFSET		(0x0014)
#define DMAC_DMAC_PERIPHERAL_ADDR_STRIDE		(32)
#define DMAC_DMAC_PERIPHERAL_ADDR_NO_ENTRIES		(6)

/* DMAC, DMAC_PERIPHERAL_ADDR, ADDR
*/
#define DMAC_DMAC_PERIPHERAL_ADDR_ADDR_MASK		(0x007FFFFF)
#define DMAC_DMAC_PERIPHERAL_ADDR_ADDR_LSBMASK		(0x007FFFFF)
#define DMAC_DMAC_PERIPHERAL_ADDR_ADDR_SHIFT		(0)
#define DMAC_DMAC_PERIPHERAL_ADDR_ADDR_LENGTH		(23)
#define DMAC_DMAC_PERIPHERAL_ADDR_ADDR_DEFAULT		(0)
#define DMAC_DMAC_PERIPHERAL_ADDR_ADDR_SIGNED_FIELD	(IMG_FALSE)

#define DMAC_DMAC_PER_HOLD_OFFSET		(0x0018)
#define DMAC_DMAC_PER_HOLD_STRIDE		(32)
#define DMAC_DMAC_PER_HOLD_NO_ENTRIES		(6)

/* DMAC, DMAC_PER_HOLD, PER_HOLD
*/
#define DMAC_DMAC_PER_HOLD_PER_HOLD_MASK		(0x0000001F)
#define DMAC_DMAC_PER_HOLD_PER_HOLD_LSBMASK		(0x0000001F)
#define DMAC_DMAC_PER_HOLD_PER_HOLD_SHIFT		(0)
#define DMAC_DMAC_PER_HOLD_PER_HOLD_LENGTH		(5)
#define DMAC_DMAC_PER_HOLD_PER_HOLD_DEFAULT		(7)
#define DMAC_DMAC_PER_HOLD_PER_HOLD_SIGNED_FIELD	(IMG_FALSE)

#define DMAC_DMAC_SOFT_RESET_OFFSET		(0x00C0)



#ifdef __cplusplus
}
#endif

#endif /* __IMG_SOC_DMAC_REGS_IO2_H__ */