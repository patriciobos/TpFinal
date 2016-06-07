/*
 * board.c
 *
 *  Created on: 12/11/2015
 *      Author: Juan Manuel Cruz
 */


#include "../../C_API/inc/board.h"

#include "stdint.h"


void initBoard (void)
{
	// Setup Clock at 1/4
	Chip_SetupCoreClock(CLKIN_IRC, MAX_CLOCK_FREQ/4, true);

	// Setup SysTick Timer to interrupt at 1 msec intervals
	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock/(1000));

#if (BOARD == EDU_CIAA_NXP)

	initLeds ();
	initRgbs ();
	initTeclas ();
	initGpios ();
	initUarts (LPC_UARTX);
	initAdcs ();
	initDac ();

#elif (BOARD == CIAA_NXP)


	initLeds ();
//	initRgbs ();
//	initTeclas ();
	initGpios ();
//	initUarts (LPC_UARTX);
	initAdcs ();
//	initDac ();

#endif

}
