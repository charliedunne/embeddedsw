/******************************************************************************
*
* Copyright (C) 2018 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PRTNICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xpmcfw_iomodule.h
*
* This is the file which contains common code for the PMCFW.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date        Changes
* ----- ---- -------- -------------------------------------------------------
* 1.00  kc   03/27/2018 Initial release
*
* </pre>
*
* @note
*
******************************************************************************/

#ifndef XPMCFW_IOMODULE_H
#define XPMCFW_IOMODULE_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xpmcfw_default.h"
#include "xpmcfw_main.h"
#include "xiomodule.h"

/************************** Constant Definitions *****************************/
#define IOMODULE_DEVICE_ID XPAR_IOMODULE_0_DEVICE_ID
#define XPMCFW_PIT1_RESET_VALUE		(0xFFFFFFFDU)
#define XPMCFW_PIT2_RESET_VALUE		(0xFFFFFFFEU)
#define MB_IOMODULE_GPO1_PIT1_PRESCALE_SRC_MASK	(0x2U)
#define XPMCFW_PIT1		(0U)
#define XPMCFW_PIT2		(1U)
#define XPMCFW_SMAP_INTR	(0x0U)
#define XPMCFW_GPI_INTR		(0x1U)


/*
 * PPU1_IOMODULE_BASEADDR
 */
#define PPU1_IOMODULE_BASEADDR			((u32)0xF0280000U)

/*
 * PPU1_IOMODULE_IRQ_STATUS
 */
#define PPP1_IOMODULE_IRQ_STATUS						( ( PPU1_IOMODULE_BASEADDR ) + ((u32)0x00000030U) )

#define PPU1_IOMODULE_IRQ_STATUS_WAKEUP_REQ_SHIFT		31
#define PPU1_IOMODULE_IRQ_STATUS_WAKEUP_REQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_WAKEUP_REQ_MASK		((u32)0x80000000U)

#define PPU1_IOMODULE_IRQ_STATUS_ISO_REQ_SHIFT			30
#define PPU1_IOMODULE_IRQ_STATUS_ISO_REQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_STATUS_ISO_REQ_MASK			((u32)0x40000000U)

#define PPU1_IOMODULE_IRQ_STATUS_SRST_REQ_SHIFT			29
#define PPU1_IOMODULE_IRQ_STATUS_SRST_REQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_STATUS_SRST_REQ_MASK			((u32)0x20000000U)

#define PPU1_IOMODULE_IRQ_STATUS_PWR_UP_REQ_SHIFT		28
#define PPU1_IOMODULE_IRQ_STATUS_PWR_UP_REQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_PWR_UP_REQ_MASK		((u32)0x10000000U)

#define PPU1_IOMODULE_IRQ_STATUS_PWR_DWN_REQ_SHIFT		27
#define PPU1_IOMODULE_IRQ_STATUS_PWR_DWN_REQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_PWR_DWN_REQ_MASK		((u32)0x08000000U)

#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ0_SHIFT		26
#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ0_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ0_MASK			((u32)0x04000000U)

#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ1_SHIFT		25
#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ1_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ1_MASK			((u32)0x02000000U)

#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ2_SHIFT		24
#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ2_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_SSIT_IRQ2_MASK			((u32)0x01000000U)

#define PPU1_IOMODULE_IRQ_STATUS_PL_IRQ_SHIFT			23
#define PPU1_IOMODULE_IRQ_STATUS_PL_IRQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_STATUS_PL_IRQ_MASK			((u32)0x00800000U)

#define PPU1_IOMODULE_IRQ_STATUS_PMC_GPI_SHIFT			22
#define PPU1_IOMODULE_IRQ_STATUS_PMC_GPI_WIDTH			1
#define PPU1_IOMODULE_IRQ_STATUS_PMC_GPI_MASK			((u32)0x00400000U)

#define PPU1_IOMODULE_IRQ_STATUS_CFRAME_SEU_SHIFT		20
#define PPU1_IOMODULE_IRQ_STATUS_CFRAME_SEU_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_CFRAME_SWU_MASK		((u32)0x00100000U)

#define PPU1_IOMODULE_IRQ_STATUS_ERR_IRQ_SHIFT			18
#define PPU1_IOMODULE_IRQ_STATUS_ERR_IRQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_STATUS_ERR_IRQ_MASK			((u32)0x00040000U)

#define PPU1_IOMODULE_IRQ_STATUS_PPU1_MB_RAM_SHIFT		17
#define PPU1_IOMODULE_IRQ_STATUS_PPU1_MB_RAM_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_PPU1_MB_RAM_MASK		((u32)0x00020000U)

#define PPU1_IOMODULE_IRQ_STATUS_PMC_GIC_IRQ_SHIFT		16
#define PPU1_IOMODULE_IRQ_STATUS_PMC_GIC_IRQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_STATUS_PMC_GIC_IRQ_MASK		((u32)0x00010000U)

#define PPU1_IOMODULE_IRQ_STATUS_PIT4_SHIFT				6
#define PPU1_IOMODULE_IRQ_STATUS_PIT4_WIDTH				1
#define PPU1_IOMODULE_IRQ_STATUS_PIT4_MASK				((u32)0x00000040U)

#define PPU1_IOMODULE_IRQ_STATUS_PIT3_SHIFT				5
#define PPU1_IOMODULE_IRQ_STATUS_PIT3_WIDTH				1
#define PPU1_IOMODULE_IRQ_STATUS_PIT3_MASK				((u32)0x00000020U)

#define PPU1_IOMODULE_IRQ_STATUS_PIT2_SHIFT				4
#define PPU1_IOMODULE_IRQ_STATUS_PIT2_WIDTH				1
#define PPU1_IOMODULE_IRQ_STATUS_PIT2_MASK				((u32)0x00000010U)

#define PPU1_IOMODULE_IRQ_STATUS_PIT1_SHIFT				3
#define PPU1_IOMODULE_IRQ_STATUS_PIT1_WIDTH				1
#define PPU1_IOMODULE_IRQ_STATUS_PIT1_MASK				((u32)0x00000008U)

/*
 * PPU1_IOMODULE_IRQ_PENDING
 */
#define PPU1_IOMODULE_IRQ_PENDING						( ( PPU1_IOMODULE_BASEADDR ) + ((u32)0x00000034U) )

#define PPU1_IOMODULE_IRQ_PENDING_WAKEUP_REQ_SHIFT		31
#define PPU1_IOMODULE_IRQ_PENDING_WAKEUP_REQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_WAKEUP_REQ_MASK		((u32)0x80000000U)

#define PPU1_IOMODULE_IRQ_PENDING_ISO_REQ_SHIFT			30
#define PPU1_IOMODULE_IRQ_PENDING_ISO_REQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_ISO_REQ_MASK			((u32)0x40000000U)

#define PPU1_IOMODULE_IRQ_PENDING_SRST_REQ_SHIFT		29
#define PPU1_IOMODULE_IRQ_PENDING_SRST_REQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_SRST_REQ_MASK			((u32)0x20000000U)

#define PPU1_IOMODULE_IRQ_PENDING_PWR_UP_REQ_SHIFT		28
#define PPU1_IOMODULE_IRQ_PENDING_PWR_UP_REQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_PWR_UP_REQ_MASK		((u32)0x10000000U)

#define PPU1_IOMODULE_IRQ_PENDING_PWR_DWN_REQ_SHIFT		27
#define PPU1_IOMODULE_IRQ_PENDING_PWR_DWN_REQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_PWR_DWN_REQ_MASK		((u32)0x08000000U)

#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ0_SHIFT		26
#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ0_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ0_MASK		((u32)0x04000000U)

#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ1_SHIFT		25
#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ1_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ1_MASK		((u32)0x02000000U)

#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ2_SHIFT		24
#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ2_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_SSIT_IRQ2_MASK		((u32)0x01000000U)

#define PPU1_IOMODULE_IRQ_PENDING_PL_IRQ_SHIFT			23
#define PPU1_IOMODULE_IRQ_PENDING_PL_IRQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_PL_IRQ_MASK			((u32)0x00800000U)

#define PPU1_IOMODULE_IRQ_PENDING_PMC_GPI_SHIFT			22
#define PPU1_IOMODULE_IRQ_PENDING_PMC_GPI_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_PMC_GPI_MASK			((u32)0x00400000U)

#define PPU1_IOMODULE_IRQ_PENDING_CFRAME_SEU_SHIFT		20
#define PPU1_IOMODULE_IRQ_PENDING_CFRAME_SEU_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_CFRAME_SWU_MASK		((u32)0x00100000U)

#define PPU1_IOMODULE_IRQ_PENDING_ERR_IRQ_SHIFT			18
#define PPU1_IOMODULE_IRQ_PENDING_ERR_IRQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_ERR_IRQ_MASK			((u32)0x00040000U)

#define PPU1_IOMODULE_IRQ_PENDING_PPU1_MB_RAM_SHIFT		17
#define PPU1_IOMODULE_IRQ_PENDING_PPU1_MB_RAM_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_PPU1_MB_RAM_MASK		((u32)0x00020000U)

#define PPU1_IOMODULE_IRQ_PENDING_PMC_GIC_IRQ_SHIFT		16
#define PPU1_IOMODULE_IRQ_PENDING_PMC_GIC_IRQ_WIDTH		1
#define PPU1_IOMODULE_IRQ_PENDING_PMC_GIC_IRQ_MASK		((u32)0x00010000U)

#define PPU1_IOMODULE_IRQ_PENDING_PIT4_SHIFT			6
#define PPU1_IOMODULE_IRQ_PENDING_PIT4_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_PIT4_MASK				((u32)0x00000040U)

#define PPU1_IOMODULE_IRQ_PENDING_PIT3_SHIFT			5
#define PPU1_IOMODULE_IRQ_PENDING_PIT3_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_PIT3_MASK				((u32)0x00000020U)

#define PPU1_IOMODULE_IRQ_PENDING_PIT2_SHIFT			4
#define PPU1_IOMODULE_IRQ_PENDING_PIT2_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_PIT2_MASK				((u32)0x00000010U)

#define PPU1_IOMODULE_IRQ_PENDING_PIT1_SHIFT			3
#define PPU1_IOMODULE_IRQ_PENDING_PIT1_WIDTH			1
#define PPU1_IOMODULE_IRQ_PENDING_PIT1_MASK				((u32)0x00000008U)

/*
 * PPU1_IOMODULE_IRQ_ACK
 */
#define PPU1_IOMODULE_IRQ_ACK							( ( PPU1_IOMODULE_BASEADDR ) + ((u32)0x0000003CU) )

#define PPU1_IOMODULE_IRQ_ACK_WAKEUP_REQ_SHIFT			31
#define PPU1_IOMODULE_IRQ_ACK_WAKEUP_REQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_WAKEUP_REQ_MASK			((u32)0x80000000U)

#define PPU1_IOMODULE_IRQ_ACK_ISO_REQ_SHIFT				30
#define PPU1_IOMODULE_IRQ_ACK_ISO_REQ_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_ISO_REQ_MASK				((u32)0x40000000U)

#define PPU1_IOMODULE_IRQ_ACK_SRST_REQ_SHIFT			29
#define PPU1_IOMODULE_IRQ_ACK_SRST_REQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_SRST_REQ_MASK				((u32)0x20000000U)

#define PPU1_IOMODULE_IRQ_ACK_PWR_UP_REQ_SHIFT			28
#define PPU1_IOMODULE_IRQ_ACK_PWR_UP_REQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_PWR_UP_REQ_MASK			((u32)0x10000000U)

#define PPU1_IOMODULE_IRQ_ACK_PWR_DWN_REQ_SHIFT			27
#define PPU1_IOMODULE_IRQ_ACK_PWR_DWN_REQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_PWR_DWN_REQ_MASK			((u32)0x08000000U)

#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ0_SHIFT			26
#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ0_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ0_MASK			((u32)0x04000000U)

#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ1_SHIFT			25
#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ1_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ1_MASK			((u32)0x02000000U)

#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ2_SHIFT			24
#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ2_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_SSIT_IRQ2_MASK			((u32)0x01000000U)

#define PPU1_IOMODULE_IRQ_ACK_PL_IRQ_SHIFT				23
#define PPU1_IOMODULE_IRQ_ACK_PL_IRQ_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_PL_IRQ_MASK				((u32)0x00800000U)

#define PPU1_IOMODULE_IRQ_ACK_PMC_GPI_SHIFT				22
#define PPU1_IOMODULE_IRQ_ACK_PMC_GPI_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_PMC_GPI_MASK				((u32)0x00400000U)

#define PPU1_IOMODULE_IRQ_ACK_CFRAME_SEU_SHIFT			20
#define PPU1_IOMODULE_IRQ_ACK_CFRAME_SEU_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_CFRAME_SWU_MASK			((u32)0x00100000U)

#define PPU1_IOMODULE_IRQ_ACK_ERR_IRQ_SHIFT				18
#define PPU1_IOMODULE_IRQ_ACK_ERR_IRQ_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_ERR_IRQ_MASK				((u32)0x00040000U)

#define PPU1_IOMODULE_IRQ_ACK_PPU1_MB_RAM_SHIFT			17
#define PPU1_IOMODULE_IRQ_ACK_PPU1_MB_RAM_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_PPU1_MB_RAM_MASK			((u32)0x00020000U)

#define PPU1_IOMODULE_IRQ_ACK_PMC_GIC_IRQ_SHIFT			16
#define PPU1_IOMODULE_IRQ_ACK_PMC_GIC_IRQ_WIDTH			1
#define PPU1_IOMODULE_IRQ_ACK_PMC_GIC_IRQ_MASK			((u32)0x00010000U)

#define PPU1_IOMODULE_IRQ_ACK_PIT4_SHIFT				6
#define PPU1_IOMODULE_IRQ_ACK_PIT4_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_PIT4_MASK					((u32)0x00000040U)

#define PPU1_IOMODULE_IRQ_ACK_PIT3_SHIFT				5
#define PPU1_IOMODULE_IRQ_ACK_PIT3_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_PIT3_MASK					((u32)0x00000020U)

#define PPU1_IOMODULE_IRQ_ACK_PIT2_SHIFT				4
#define PPU1_IOMODULE_IRQ_ACK_PIT2_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_PIT2_MASK					((u32)0x00000010U)

#define PPU1_IOMODULE_IRQ_ACK_PIT1_SHIFT				3
#define PPU1_IOMODULE_IRQ_ACK_PIT1_WIDTH				1
#define PPU1_IOMODULE_IRQ_ACK_PIT1_MASK					((u32)0x00000008U)

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/
#define XPMCFW_GICP_INTERRUPT	(0x10U)
#define XPMCFW_ERR_INTERRUPT	(0x12U)
#define XPMCFW_GPI_INTERRUPT	(0x16U)
/************************** Function Prototypes ******************************/
XStatus XPmcFw_InitIOModule();
void XPmcFw_IntrHandler(void *CallbackRef);
u64 XPmcFw_GetTimerValue(void );
XStatus XPmcFw_SetUpInterruptSystem();
void XPmcFw_MeasurePerfTime(u64 tCur);

#ifdef __cplusplus
}
#endif

#endif  /* XPMCFW_DMA_H */
