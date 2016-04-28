/*
 * AHBRAM.h
 *
 *  Created on: 22/11/2013
 *      Author: Alejandro
 */

#ifndef AHBRAM_H_
#define AHBRAM_H_

void prvManuallyPlaceLargeDataInAHBRAM		( void );
void *pvApplicationGetEMACTxBufferAddress	( void );
void *pvApplicationGetEMACRxBufferAddress	( void );

#endif /* AHBRAM_H_ */
