/*
 * leds.h
 *
 *  Created on: 12/11/2015
 *      Author: Juan Manuel Cruz
 *
 *  Modified on: 03/06/2016
 *  	Author: Patricio Bos
 */

#ifndef LEDS_H_
#define LEDS_H_


#include "C_API.h"

typedef struct {
	uint8_t port;
	uint8_t pin;
	uint8_t gpio;
	uint8_t bit;
	uint16_t mode;
} led_io_port_t;

#if (BOARD == EDU_CIAA_NXP)
/*	LED1 => P2_10 en GPIO 0[14]	*
 *	LED2 => P2_11 en GPIO 1[11]	*
 *	LED3 => P2_12 en GPIO 1[12]	*/

// LEDs
#define LED1	0
#define LED2	1
#define LED3	2


#define led_t	uint8_t
static const led_t led[] = {LED1, LED2, LED3};



static const led_io_port_t gpioLEDPins[] = {
	{ 2, 10,  0, 14, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC0)},
	{ 2, 11,  1, 11, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC0)},
	{ 2, 12,  1, 12, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC0)}};


#elif (BOARD == CIAA_NXP)

//	RELAYs
/*		LED0 => P4_4 on GPIO 2[4]	*
 *		LED1 => P4_5 on GPIO 2[5]	*
 *		LED2 => P4_6 on GPIO 2[6]	*
 *		LED3 => P2_1 on GPIO 5[1]	*/


//	MOSFETs
/* 		LED5 => P4_8  on GPIO5[12] */
/* 		LED4 => P4_9  on GPIO5[13] */
/* 		LED7 => P4_10 on GPIO5[14] */
/* 		LED6 => P1_5  on GPIO1[8] */



// LEDs
#define LED0	0
#define LED1	1
#define LED2	2
#define LED3	3
#define LED4	4
#define LED5	5
#define LED6	6
#define LED7	7

#define led_t	uint8_t
static const led_t led[] = {LED0, LED1, LED2, LED3};
//static const led_t led[] = {LED4, LED5, LED6, LED7};


static const led_io_port_t gpioLEDPins[] = {
//	{ 4,  4,  2,  4, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC0)},
//	{ 4,  5,  2,  5, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC0)},
//	{ 4,  6,  2,  6, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC0)},
//	{ 2,  1,  5,  1, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC4)},
	{ 4,  9,  5, 13, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC4)},
	{ 4,  8,  5, 12, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC4)},
	{ 1,  5,  1,  8, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC0)},
	{ 4, 10,  5, 14, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC4)}};


#endif


void initLeds (void);
void initLed (const led_t ledNumber);
void setLed (const led_t ledNumber);
void clearLed (const led_t ledNumber);
void toggleLed (const led_t ledNumber);


#endif /* LEDS_H_ */
