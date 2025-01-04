/*!
 *****************************************************************************
 *
 * @File       msvdx_test_reg_io2.h
 * @Description    This file contains the MSVDX_TEST_REG_IO2_H Definitions.
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


#if !defined (__MSVDX_TEST_REG_IO2_H__)
#define __MSVDX_TEST_REG_IO2_H__

#ifdef __cplusplus
extern "C" {
#endif


#define MSVDX_TEST_MEM_CTRL_OFFSET		(0x0000)

/* MSVDX_TEST, MEM_CTRL, MEM_LATENCY_MIN
*/
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MIN_MASK		(0x000000FF)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MIN_LSBMASK		(0x000000FF)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MIN_SHIFT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MIN_LENGTH		(8)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MIN_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MIN_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_CTRL, MEM_LATENCY_MAX
*/
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MAX_MASK		(0x0000FF00)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MAX_LSBMASK		(0x000000FF)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MAX_SHIFT		(8)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MAX_LENGTH		(8)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MAX_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_LATENCY_MAX_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_CTRL, MEM_STALL_RATIO
*/
#define MSVDX_TEST_MEM_CTRL_MEM_STALL_RATIO_MASK		(0x000F0000)
#define MSVDX_TEST_MEM_CTRL_MEM_STALL_RATIO_LSBMASK		(0x0000000F)
#define MSVDX_TEST_MEM_CTRL_MEM_STALL_RATIO_SHIFT		(16)
#define MSVDX_TEST_MEM_CTRL_MEM_STALL_RATIO_LENGTH		(4)
#define MSVDX_TEST_MEM_CTRL_MEM_STALL_RATIO_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_STALL_RATIO_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_CTRL, MEM_36BIT_MMU_MODE
*/
#define MSVDX_TEST_MEM_CTRL_MEM_36BIT_MMU_MODE_MASK		(0x01000000)
#define MSVDX_TEST_MEM_CTRL_MEM_36BIT_MMU_MODE_LSBMASK		(0x00000001)
#define MSVDX_TEST_MEM_CTRL_MEM_36BIT_MMU_MODE_SHIFT		(24)
#define MSVDX_TEST_MEM_CTRL_MEM_36BIT_MMU_MODE_LENGTH		(1)
#define MSVDX_TEST_MEM_CTRL_MEM_36BIT_MMU_MODE_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_36BIT_MMU_MODE_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_CTRL, MEM_40BIT_MMU_MODE
*/
#define MSVDX_TEST_MEM_CTRL_MEM_40BIT_MMU_MODE_MASK		(0x02000000)
#define MSVDX_TEST_MEM_CTRL_MEM_40BIT_MMU_MODE_LSBMASK		(0x00000001)
#define MSVDX_TEST_MEM_CTRL_MEM_40BIT_MMU_MODE_SHIFT		(25)
#define MSVDX_TEST_MEM_CTRL_MEM_40BIT_MMU_MODE_LENGTH		(1)
#define MSVDX_TEST_MEM_CTRL_MEM_40BIT_MMU_MODE_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_40BIT_MMU_MODE_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_CTRL, MEM_RDATA_REORDER_MODE
*/
#define MSVDX_TEST_MEM_CTRL_MEM_RDATA_REORDER_MODE_MASK		(0x10000000)
#define MSVDX_TEST_MEM_CTRL_MEM_RDATA_REORDER_MODE_LSBMASK		(0x00000001)
#define MSVDX_TEST_MEM_CTRL_MEM_RDATA_REORDER_MODE_SHIFT		(28)
#define MSVDX_TEST_MEM_CTRL_MEM_RDATA_REORDER_MODE_LENGTH		(1)
#define MSVDX_TEST_MEM_CTRL_MEM_RDATA_REORDER_MODE_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_RDATA_REORDER_MODE_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_CTRL, AXI_BID_REORDER_MODE
*/
#define MSVDX_TEST_MEM_CTRL_AXI_BID_REORDER_MODE_MASK		(0x20000000)
#define MSVDX_TEST_MEM_CTRL_AXI_BID_REORDER_MODE_LSBMASK		(0x00000001)
#define MSVDX_TEST_MEM_CTRL_AXI_BID_REORDER_MODE_SHIFT		(29)
#define MSVDX_TEST_MEM_CTRL_AXI_BID_REORDER_MODE_LENGTH		(1)
#define MSVDX_TEST_MEM_CTRL_AXI_BID_REORDER_MODE_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_AXI_BID_REORDER_MODE_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_CTRL, MEM_DATA_ENCRYPT
*/
#define MSVDX_TEST_MEM_CTRL_MEM_DATA_ENCRYPT_MASK		(0x40000000)
#define MSVDX_TEST_MEM_CTRL_MEM_DATA_ENCRYPT_LSBMASK		(0x00000001)
#define MSVDX_TEST_MEM_CTRL_MEM_DATA_ENCRYPT_SHIFT		(30)
#define MSVDX_TEST_MEM_CTRL_MEM_DATA_ENCRYPT_LENGTH		(1)
#define MSVDX_TEST_MEM_CTRL_MEM_DATA_ENCRYPT_DEFAULT		(0)
#define MSVDX_TEST_MEM_CTRL_MEM_DATA_ENCRYPT_SIGNED_FIELD	(IMG_FALSE)

#define MSVDX_TEST_MEM_STALL_CFG_OFFSET		(0x0004)

/* MSVDX_TEST, MEM_STALL_CFG, SEED_BURST_MEM
*/
#define MSVDX_TEST_MEM_STALL_CFG_SEED_BURST_MEM_MASK		(0x000007FF)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_BURST_MEM_LSBMASK		(0x000007FF)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_BURST_MEM_SHIFT		(0)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_BURST_MEM_LENGTH		(11)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_BURST_MEM_DEFAULT		(0)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_BURST_MEM_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_STALL_CFG, SEED_GAP_MEM
*/
#define MSVDX_TEST_MEM_STALL_CFG_SEED_GAP_MEM_MASK		(0x003FF800)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_GAP_MEM_LSBMASK		(0x000007FF)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_GAP_MEM_SHIFT		(11)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_GAP_MEM_LENGTH		(11)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_GAP_MEM_DEFAULT		(0)
#define MSVDX_TEST_MEM_STALL_CFG_SEED_GAP_MEM_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_STALL_CFG, MAX_BURST_MEM
*/
#define MSVDX_TEST_MEM_STALL_CFG_MAX_BURST_MEM_MASK		(0x03C00000)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_BURST_MEM_LSBMASK		(0x0000000F)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_BURST_MEM_SHIFT		(22)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_BURST_MEM_LENGTH		(4)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_BURST_MEM_DEFAULT		(0)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_BURST_MEM_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_STALL_CFG, MAX_GAP_MEM
*/
#define MSVDX_TEST_MEM_STALL_CFG_MAX_GAP_MEM_MASK		(0x3C000000)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_GAP_MEM_LSBMASK		(0x0000000F)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_GAP_MEM_SHIFT		(26)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_GAP_MEM_LENGTH		(4)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_GAP_MEM_DEFAULT		(0)
#define MSVDX_TEST_MEM_STALL_CFG_MAX_GAP_MEM_SIGNED_FIELD	(IMG_FALSE)

#define MSVDX_TEST_TEST_CLK_CFG_OFFSET		(0x0008)

/* MSVDX_TEST, TEST_CLK_CFG, RANDOM_CLK_ENABLE
*/
#define MSVDX_TEST_TEST_CLK_CFG_RANDOM_CLK_ENABLE_MASK		(0x00000200)
#define MSVDX_TEST_TEST_CLK_CFG_RANDOM_CLK_ENABLE_LSBMASK		(0x00000001)
#define MSVDX_TEST_TEST_CLK_CFG_RANDOM_CLK_ENABLE_SHIFT		(9)
#define MSVDX_TEST_TEST_CLK_CFG_RANDOM_CLK_ENABLE_LENGTH		(1)
#define MSVDX_TEST_TEST_CLK_CFG_RANDOM_CLK_ENABLE_DEFAULT		(0)
#define MSVDX_TEST_TEST_CLK_CFG_RANDOM_CLK_ENABLE_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, TEST_CLK_CFG, FORCE_CLK_ENABLE
*/
#define MSVDX_TEST_TEST_CLK_CFG_FORCE_CLK_ENABLE_MASK		(0x00000100)
#define MSVDX_TEST_TEST_CLK_CFG_FORCE_CLK_ENABLE_LSBMASK		(0x00000001)
#define MSVDX_TEST_TEST_CLK_CFG_FORCE_CLK_ENABLE_SHIFT		(8)
#define MSVDX_TEST_TEST_CLK_CFG_FORCE_CLK_ENABLE_LENGTH		(1)
#define MSVDX_TEST_TEST_CLK_CFG_FORCE_CLK_ENABLE_DEFAULT		(0)
#define MSVDX_TEST_TEST_CLK_CFG_FORCE_CLK_ENABLE_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, TEST_CLK_CFG, MTX_CLK_RATIO
*/
#define MSVDX_TEST_TEST_CLK_CFG_MTX_CLK_RATIO_MASK		(0x00000003)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_CLK_RATIO_LSBMASK		(0x00000003)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_CLK_RATIO_SHIFT		(0)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_CLK_RATIO_LENGTH		(2)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_CLK_RATIO_DEFAULT		(0)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_CLK_RATIO_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, TEST_CLK_CFG, MTX_FORCE_CLK_GATE_OFF
*/
#define MSVDX_TEST_TEST_CLK_CFG_MTX_FORCE_CLK_GATE_OFF_MASK		(0x00000004)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_FORCE_CLK_GATE_OFF_LSBMASK		(0x00000001)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_FORCE_CLK_GATE_OFF_SHIFT		(2)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_FORCE_CLK_GATE_OFF_LENGTH		(1)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_FORCE_CLK_GATE_OFF_DEFAULT		(0)
#define MSVDX_TEST_TEST_CLK_CFG_MTX_FORCE_CLK_GATE_OFF_SIGNED_FIELD	(IMG_FALSE)

#define MSVDX_TEST_MEM_PRIORITY_OFFSET		(0x000C)

/* MSVDX_TEST, MEM_PRIORITY, MEM_REQ_PRIORITY_STATUS
*/
#define MSVDX_TEST_MEM_PRIORITY_MEM_REQ_PRIORITY_STATUS_MASK		(0x00000002)
#define MSVDX_TEST_MEM_PRIORITY_MEM_REQ_PRIORITY_STATUS_LSBMASK		(0x00000001)
#define MSVDX_TEST_MEM_PRIORITY_MEM_REQ_PRIORITY_STATUS_SHIFT		(1)
#define MSVDX_TEST_MEM_PRIORITY_MEM_REQ_PRIORITY_STATUS_LENGTH		(1)
#define MSVDX_TEST_MEM_PRIORITY_MEM_REQ_PRIORITY_STATUS_DEFAULT		(0)
#define MSVDX_TEST_MEM_PRIORITY_MEM_REQ_PRIORITY_STATUS_SIGNED_FIELD	(IMG_FALSE)

/* MSVDX_TEST, MEM_PRIORITY, MEM_CMD_PRIORITY_STATUS
*/
#define MSVDX_TEST_MEM_PRIORITY_MEM_CMD_PRIORITY_STATUS_MASK		(0x00000004)
#define MSVDX_TEST_MEM_PRIORITY_MEM_CMD_PRIORITY_STATUS_LSBMASK		(0x00000001)
#define MSVDX_TEST_MEM_PRIORITY_MEM_CMD_PRIORITY_STATUS_SHIFT		(2)
#define MSVDX_TEST_MEM_PRIORITY_MEM_CMD_PRIORITY_STATUS_LENGTH		(1)
#define MSVDX_TEST_MEM_PRIORITY_MEM_CMD_PRIORITY_STATUS_DEFAULT		(0)
#define MSVDX_TEST_MEM_PRIORITY_MEM_CMD_PRIORITY_STATUS_SIGNED_FIELD	(IMG_FALSE)



#ifdef __cplusplus
}
#endif

#endif /* __MSVDX_TEST_REG_IO2_H__ */