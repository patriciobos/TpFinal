/*
 * C-API.h
 *
 *  Created on: 12/11/2015
 *      Author: Juan Manuel Cruz
 *
 *  Modified on: 03/19/2016
 *  	By: Patricio Bos
 */

#ifndef C_API_H_
#define C_API_H_

#define lpc4337			1
#define mk60fx512vlq15	2

#define EDU_CIAA_NXP	1
#define CIAA_NXP		2

#define BOARD EDU_CIAA_NXP

#define CPU lpc4337

#ifndef CPU
#error CPU shall be defined
#endif


#include "stdint.h"

#if (lpc4337 == CPU)

#include "chip.h"
#include "cmsis_43xx.h"

/** \brief Reset ISR
 **
 ** ResetISR is defined in cr_startup_lpc43xx.c
 **/

extern void ResetISR(void);

/** \brief Stack Top address
 **
 ** External declaration for the pointer to the stack top from the Linker Script
 **
 ** \remark only a declaration is needed, there is no definition, the address
 **         is set in the linker script:
 **         externals/base/cortexM4/lpc43xx/linker/ciaa_lpc4337.ld.
 **/

extern void _vStackTop(void);

void RIT_IRQHandler(void);


#elif (mk60fx512vlq15 == CPU)

/* Reset_Handler is defined in startup_MK60F15.S_CPP */
void Reset_Handler( void );

extern uint32_t __StackTop;

#else
#error CPU definition mismatch

#endif



#endif /* C-API_H_ */
