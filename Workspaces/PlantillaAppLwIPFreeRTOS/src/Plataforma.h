/*
 * MCU.h
 *
 *  Created on: 23/08/2012
 *      Author: alejandro
 */

#ifndef MCU_H_
#define MCU_H_

//Definicion del micro a usar--------------------------------------------------

#if __TARGET_PORT == LIB_MCU_LPC134x

#include "LPC13xx.h"				//CMSIS
#include "lpc_134X_PinNames.h"		//Lib_MCU_LPC134x
#include "lpc_134X_PeriphNames.h"	//Lib_MCU_LPC134x
#define UART_CONSOLA UART_0

#elif __TARGET_PORT == LIB_MCU_LPC176x

#include "LPC17xx.h"				//CMSIS
#include "lpc_176X_PinNames.h"		//Lib_MCU_LPC176x
#include "lpc_176X_PeriphNames.h"	//Lib_MCU_LPC176x
#define UART_CONSOLA UART_3

#endif

//Definicion del board a usar--------------------------------------------------

//#define RUBEN_BOARD		0
#define EA_BASEBOARD	1

//#define BOARD RUBEN_BOARD
#define BOARD EA_BASEBOARD

#if BOARD == RUBEN_BOARD
#define APAGAR_RGB
#define USAR_LCD_TEXTO
#define USAR_BUS_LEDS
#define USAR_ECO_CONSOLA
#define USAR_SEGUIDOR_BOTON
//#define USAR_TARJETA_SD

#elif BOARD == EA_BASEBOARD
//#define USAR_BUS_LEDS
#define USAR_ECO_CONSOLA
#define USAR_SEGUIDOR_BOTON
//#define USAR_TARJETA_SD
#endif

//Definicion del RTOS a usar --------------------------------------------------

#if __USE_FREERTOS == FreeRTOSv7p0p1
#include "FreeRTOS.h"
#include "task.h"
#endif

#endif /* MCU_H_ */
