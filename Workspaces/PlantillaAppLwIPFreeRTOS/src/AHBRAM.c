/*
 * AHBRAM.c
 *
 *  Created on: 22/11/2013
 *      Author: Alejandro
 */

#include "FreeRTOS.h"
#include "lpc17xx_emac.h"	//Mira los buffers del emac
#include "string.h"			//Usa memset

/* The emac buffers are manually placed at the start of the AHB RAM.  These
variables store the calculated addresses, which are then made available
through the pvApplicationGetEMACTxBufferAddress() and
pvApplicationGetEMACRxBufferAddress() access functions. */
static uint32_t ulEMACTxBufferStart = 0UL, ulEMACRxBufferStart = 0UL;

uint8_t *pucFreeRTOSHeap = NULL;

void prvManuallyPlaceLargeDataInAHBRAM( void )
{
	uint32_t ulAddressCalc;
	extern uint32_t __top_RamAHB32[];
	const uint32_t ulBaseAddress = 0x2007c000UL;

	/* Start at the bottom of the second bank of RAM.  Need to use a linker
	variable here! */
	ulAddressCalc = ulBaseAddress;
	ulEMACTxBufferStart = ulAddressCalc;

	/* Move up far enough to hold all the Tx buffers. */
	ulAddressCalc += sizeof( xEMACTxBuffer_t );

	/* Align and store the calculated address. */
	ulAddressCalc += 0x0fUL;
	ulAddressCalc &= ~0x0fUL;
	ulEMACRxBufferStart = ulAddressCalc;

	/* Move up far enough to hold all the Rx buffers. */
	ulAddressCalc += sizeof( xEMACRxBuffer_t );

	/* Align and assign the calculated address to the FreeRTOS heap. */
	ulAddressCalc += 0x0fUL;
	ulAddressCalc &= ~0x0fUL;
	pucFreeRTOSHeap = ( uint8_t * ) ulAddressCalc;

	/* Sanity check that the variables placed in AHB RAM actually fit in AHB
	RAM before zeroing down the memory. */
	configASSERT( ( ulAddressCalc + configTOTAL_HEAP_SIZE ) < ( uint32_t ) __top_RamAHB32 );
	memset( ( void * ) ulBaseAddress, 0x00, ( ulAddressCalc + configTOTAL_HEAP_SIZE ) - ulBaseAddress );

	/* Remove compiler warnings when configASSERT() is not defined. */
	( void ) __top_RamAHB32;
}

void *pvApplicationGetEMACTxBufferAddress( void )
{
	return ( void * ) ulEMACTxBufferStart;
}

void *pvApplicationGetEMACRxBufferAddress( void )
{
	return ( void * ) ulEMACRxBufferStart;
}
