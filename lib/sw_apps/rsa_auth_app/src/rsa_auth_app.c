/******************************************************************************
*
* (c) Copyright 2014 Xilinx, Inc. All rights reserved.
*
* This file contains confidential and proprietary information of Xilinx, Inc.
* and is protected under U.S. and international copyright and other
* intellectual property laws.
*
* DISCLAIMER
* This disclaimer is not a license and does not grant any rights to the
* materials distributed herewith. Except as otherwise provided in a valid
* license issued to you by Xilinx, and to the maximum extent permitted by
* applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL
* FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS,
* IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE;
* and (2) Xilinx shall not be liable (whether in contract or tort, including
* negligence, or under any other theory of liability) for any loss or damage
* of any kind or nature related to, arising under or in connection with these
* materials, including for any direct, or any indirect, special, incidental,
* or consequential loss or damage (including loss of data, profits, goodwill,
* or any type of loss or damage suffered as a result of any action brought by
* a third party) even if such damage or loss was reasonably foreseeable or
* Xilinx had been advised of the possibility of the same.
*
* CRITICAL APPLICATIONS
* Xilinx products are not designed or intended to be fail-safe, or for use in
* any application requiring fail-safe performance, such as life-support or
* safety devices or systems, Class III medical devices, nuclear facilities,
* applications related to the deployment of airbags, or any other applications
* that could lead to death, personal injury, or severe property or
* environmental damage (individually and collectively, "Critical
* Applications"). Customer assumes the sole risk and liability of any use of
* Xilinx products in Critical Applications, subject only to applicable laws
* and regulations governing limitations on product liability.
*
* THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE
* AT ALL TIMES.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file rsa_auth_app.c
* 	This file contains the implementation of the SW app used to
* 	validate any user application. It makes use of librsa to do the same.
*
* @note
*
* None.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who Date     Changes
* ----- --- -------- -----------------------------------------------
* 1.0   hk  27/01/14 First release
*
*</pre>
*
******************************************************************************/

/***************************** Include Files *********************************/

#include "rsa_auth_app.h"
#include "xil_cache.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/

u32 AuthenticatePartition(u8 *Buffer, u32 Size, u8 *CertStart);
void SetPpk(u8 *CertStart);
u32 RecreatePaddingAndCheck(u8 *signature, u8 *hash);

/************************** Variable Definitions *****************************/

static u8 *PpkModular;
static u8 *PpkModularEx;
static u32 PpkExp;


/*****************************************************************************/
/**
*
* Main function to call the AuthenticaApp function.
*
* @param	None
*
* @return	XST_SUCCESS if successful, otherwise XST_FAILURE.
*
* @note		None
*
******************************************************************************/
int main(void)
{
	int Status;

	Xil_DCacheFlush();

	xil_printf("RSA authentication of application started \n\r");

	Status = AuthenticateApp();
	if (Status != XST_SUCCESS) {
		xil_printf("RSA authentication of SW application failed\n\r");
		return XST_FAILURE;
	}

	xil_printf("Successfully authenticated SW application \n\r");
	return XST_SUCCESS;

}

/*****************************************************************************/
/**
*
* This function authenticates the SW application given by the user
*
* @param	None
*
* @return	XST_SUCCESS if successful, otherwise XST_FAILURE.
*
* @note		None
*
******************************************************************************/
int AuthenticateApp(void)
{
	int Status;

	/*
	 * Set the Ppk
	 */
	SetPpk((u8 *)CERTIFICATE_START_ADDR);

	/*
	 * Authenticate partition containing the application.
	 */
	Status = AuthenticatePartition((u8 *)APPLICATION_START_ADDR,
			PARTITION_SIZE, (u8 *)CERTIFICATE_START_ADDR);
	if (Status != XST_SUCCESS) {
		return Status;
	}

	return XST_SUCCESS;
}

/*****************************************************************************/
/**
*
* This function is used to set ppk pointer to ppk in OCM
*
* @param	None
*
* @return
*
* @note		None
*
******************************************************************************/

void SetPpk(u8 *CertStart)
{
	u8 *PpkPtr;

	/*
	 * Set PpkPtr to PPK start address provided by user
	 */
	PpkPtr = (u8 *)(CertStart);

	/*
	 * Increment the pointer by authentication Header size
	 */
	PpkPtr += RSA_HEADER_SIZE;

	/*
	 * Increment the pointer by Magic word size
	 */
	PpkPtr += RSA_MAGIC_WORD_SIZE;

	/*
	 * Set pointer to PPK
	 */
	PpkModular = (u8 *)PpkPtr;
	PpkPtr += RSA_PPK_MODULAR_SIZE;
	PpkModularEx = (u8 *)PpkPtr;
	PpkPtr += RSA_PPK_MODULAR_EXT_SIZE;
	PpkExp = *((u32 *)PpkPtr);

	return;
}

/*****************************************************************************/
/**
*
* This function authenticates the partition signature
*
* @param	Partition header pointer
*
* @return
*		- XST_SUCCESS if Authentication passed
*		- XST_FAILURE if Authentication failed
*
* @note		None
*
******************************************************************************/
u32 AuthenticatePartition(u8 *Buffer, u32 Size, u8 *CertStart)
{
	u8 DecryptSignature[256];
	u8 HashSignature[32];
	u8 *SpkModular;
	u8 *SpkModularEx;
	u32 SpkExp;
	u8 *SignaturePtr;
	u32 Status;

	/*
	 * Point to Authentication Certificate
	 */
	SignaturePtr = (u8 *)(CertStart);

	/*
	 * Increment the pointer by authentication Header size
	 */
	SignaturePtr += RSA_HEADER_SIZE;

	/*
	 * Increment the pointer by Magic word size
	 */
	SignaturePtr += RSA_MAGIC_WORD_SIZE;

	/*
	 * Increment the pointer beyond the PPK
	 */
	SignaturePtr += RSA_PPK_MODULAR_SIZE;
	SignaturePtr += RSA_PPK_MODULAR_EXT_SIZE;
	SignaturePtr += RSA_PPK_EXPO_SIZE;

	/*
	 * Calculate Hash Signature
	 */
	sha_256((u8 *)SignaturePtr, (RSA_SPK_MODULAR_EXT_SIZE +
				RSA_SPK_EXPO_SIZE + RSA_SPK_MODULAR_SIZE),
				HashSignature);

   	/*
   	 * Extract SPK signature
   	 */
	SpkModular = (u8 *)SignaturePtr;
	SignaturePtr += RSA_SPK_MODULAR_SIZE;
	SpkModularEx = (u8 *)SignaturePtr;
	SignaturePtr += RSA_SPK_MODULAR_EXT_SIZE;
	SpkExp = *((u32 *)SignaturePtr);
	SignaturePtr += RSA_SPK_EXPO_SIZE;

	/*
	 * Decrypt SPK Signature
	 */
	rsa2048_pubexp((RSA_NUMBER)DecryptSignature,
			(RSA_NUMBER)SignaturePtr,
			(u32)PpkExp,
			(RSA_NUMBER)PpkModular,
			(RSA_NUMBER)PpkModularEx);

	Status = RecreatePaddingAndCheck(DecryptSignature, HashSignature);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	SignaturePtr += RSA_SPK_SIGNATURE_SIZE;

	/*
	 * Decrypt Partition Signature
	 */
	rsa2048_pubexp((RSA_NUMBER)DecryptSignature,
			(RSA_NUMBER)SignaturePtr,
			(u32)SpkExp,
			(RSA_NUMBER)SpkModular,
			(RSA_NUMBER)SpkModularEx);

	/*
	 * Partition Authentication
	 * Calculate Hash Signature
	 */
	sha_256((u8 *)Buffer, (Size - RSA_PARTITION_SIGNATURE_SIZE),
			HashSignature);

	Status = RecreatePaddingAndCheck(DecryptSignature, HashSignature);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

/*****************************************************************************/
/**
*
* This function recreates and checks the signature.
*
* @param	Partition signature
* @param	Partition hash value which includes boot header, partition data
* @return
*		- XST_SUCCESS if check passed
*		- XST_FAILURE if check failed
*
* @note		None
*
******************************************************************************/
u32 RecreatePaddingAndCheck(u8 *signature, u8 *hash)
{
	u8 T_padding[] = {0x30, 0x31, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86, 0x48,
		0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x04, 0x20 };
    u8 * pad_ptr = signature + 256;
    u32 pad = 256 - 3 - 19 - 32;
    u32 ii;

    /*
    * Re-Create PKCS#1v1.5 Padding
    * MSB  ----------------------------------------------------LSB
    * 0x0 || 0x1 || 0xFF(for 202 bytes) || 0x0 || T_padding || SHA256 Hash
    */
    if (*--pad_ptr != 0x00 || *--pad_ptr != 0x01) {
    	return XST_FAILURE;
    }

    for (ii = 0; ii < pad; ii++) {
    	if (*--pad_ptr != 0xFF) {
        	return XST_FAILURE;
        }
    }

    if (*--pad_ptr != 0x00) {
       	return XST_FAILURE;
    }

    for (ii = 0; ii < sizeof(T_padding); ii++) {
    	if (*--pad_ptr != T_padding[ii]) {
        	return XST_FAILURE;
        }
    }

    for (ii = 0; ii < 32; ii++) {
       	if (*--pad_ptr != hash[ii])
       		return XST_FAILURE;
    }

	return XST_SUCCESS;
}
