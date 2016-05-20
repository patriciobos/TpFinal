/*
 * Copyright(C) NXP Semiconductors, 2012
 * All rights reserved.
 *
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "string.h"

#include "retarget.h"

/** @ingroup BOARD_NGX_XPLORER_18304330
 * @{
 */

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/* System configuration variables used by chip driver */
const uint32_t ExtRateIn = 0;
const uint32_t OscRateIn = 12000000;

typedef struct {
	uint8_t port;
	uint8_t pin;
} io_port_t;

static const io_port_t gpioLEDBits[] = {{5,0},{5,1},{5,2},{0,14},{1,11},{1,12}};

void Board_UART_Init(LPC_USART_T *pUART)
{
	if (pUART == LPC_USART0) {
		Chip_SCU_PinMuxSet(0x6, 4, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC2));					/* P6.5 : UART0_TXD */
		Chip_SCU_PinMuxSet(0x6, 5, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC2));/* P6.4 : UART0_RXD */
	}
	else if (pUART == LPC_UART1) {
		Chip_SCU_PinMuxSet(0x1, 13, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC2));				/* P1.13 : UART1_TXD */
		Chip_SCU_PinMuxSet(0x1, 14, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC2));	/* P1.14 : UART1_RX */
	}
	else if (pUART == LPC_USART2) {
			Chip_SCU_PinMux(7, 1, MD_PDN, FUNC6);              	/* P7_1: UART2_TXD */
			Chip_SCU_PinMux(7, 2, MD_PLN|MD_EZI|MD_ZI, FUNC6); 	/* P7_2: UART2_RXD */
		}
}

/* Initialize debug output via UART for board */
void Board_Debug_Init(void)
{
#if defined(DEBUG_UART)
	Board_UART_Init(DEBUG_UART);

	Chip_UART_Init(DEBUG_UART);
	Chip_UART_SetBaud(DEBUG_UART, 115200);
	Chip_UART_ConfigData(DEBUG_UART, UART_LCR_WLEN8 | UART_LCR_SBS_1BIT | UART_LCR_PARITY_DIS);

	/* Enable UART Transmit */
	Chip_UART_TXEnable(DEBUG_UART);

	/*UART init ok message*/
	DEBUGOUT("\r\nUART initialized.........[OK]\r\n");

#endif
}

/* Sends a character on the UART */
void Board_UARTPutChar(char ch)
{
#if defined(DEBUG_UART)
	/* Wait for space in FIFO */
	while ((Chip_UART_ReadLineStatus(DEBUG_UART) & UART_LSR_THRE) == 0) {}
	Chip_UART_SendByte(DEBUG_UART, (uint8_t) ch);
#endif
}

/* Gets a character from the UART, returns EOF if no character is ready */
int Board_UARTGetChar(void)
{
#if defined(DEBUG_UART)
	if (Chip_UART_ReadLineStatus(DEBUG_UART) & UART_LSR_RDR) {
		return (int) Chip_UART_ReadByte(DEBUG_UART);
	}
#endif
	return EOF;
}

/* Outputs a string on the debug UART */
void Board_UARTPutSTR(const char *str)
{
#if defined(DEBUG_UART)
	while (*str != '\0') {
		Board_UARTPutChar(*str++);
	}
#endif
}

static void Board_LED_Init()
{
   /* LEDs EDU-CIAA-NXP */
   Chip_SCU_PinMux(2,0,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[0], LED0R */
   Chip_SCU_PinMux(2,1,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[1], LED0G */
   Chip_SCU_PinMux(2,2,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[2], LED0B */
   Chip_SCU_PinMux(2,10,MD_PUP|MD_EZI,FUNC0); /* GPIO0[14], LED1 */
   Chip_SCU_PinMux(2,11,MD_PUP|MD_EZI,FUNC0); /* GPIO1[11], LED2 */
   Chip_SCU_PinMux(2,12,MD_PUP|MD_EZI,FUNC0); /* GPIO1[12], LED3 */

   Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2),1);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<14),1);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<11)|(1<<12),1);

   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0,(1<<14));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1,(1<<11)|(1<<12));
}

void Board_Ciaa_Gpios()
{
	/* Inputs */
	   Chip_SCU_PinMux(4,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO2[0]  */
	   Chip_SCU_PinMux(4,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO2[1]  */
	   Chip_SCU_PinMux(4,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO2[2]  */
	   Chip_SCU_PinMux(4,3,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO2[3]  */
	   Chip_SCU_PinMux(7,3,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO3[11] */
	   Chip_SCU_PinMux(7,4,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO3[12] */
	   Chip_SCU_PinMux(7,5,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO3[13] */
	   Chip_SCU_PinMux(7,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO3[14] */
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 2, 0xF, 0);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 3, 0xF<<11, 0);

	   /* MOSFETs */
	   Chip_SCU_PinMux(4,8,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[12] */
	   Chip_SCU_PinMux(4,9,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[13] */
	   Chip_SCU_PinMux(4,10,MD_PUP|MD_EZI,FUNC4); /* GPIO5[14] */
	   Chip_SCU_PinMux(1,5,MD_PUP|MD_EZI,FUNC0);  /* GPIO1[8]  */
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<12)|(1<<13)|(1<<14),1);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<8),1);
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<12)|(1<<13)|(1<<14));
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1,(1<<8));

	   /* Relays */
	   Chip_SCU_PinMux(4,4,MD_PUP|MD_EZI,FUNC0); /* GPIO2[4] */
	   Chip_SCU_PinMux(4,5,MD_PUP|MD_EZI,FUNC0); /* GPIO2[5] */
	   Chip_SCU_PinMux(4,6,MD_PUP|MD_EZI,FUNC0); /* GPIO2[6] */
	   Chip_SCU_PinMux(2,1,MD_PUP|MD_EZI,FUNC4); /* GPIO5[1] */
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 2,(1<<4)|(1<<5)|(1<<6),1);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<1),1);
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 2,(1<<4)|(1<<5)|(1<<6));
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<1));

	   DEBUGOUT("Board GPIOs initialized..[OK]\r\n");
//	   Board_UARTPutSTR("Board GPIOs initialized..[OK]\r\n");
//
//	   // Ugly delay for clearing timing issues
//	   	uint32_t i;
//	   	for(i=0;i<0xFFF;i++);

}

void Board_LED_Set(uint8_t LEDNumber, bool On)
{
	if (LEDNumber < (sizeof(gpioLEDBits) / sizeof(io_port_t)))
		Chip_GPIO_SetPinState(LPC_GPIO_PORT, gpioLEDBits[LEDNumber].port, gpioLEDBits[LEDNumber].pin, On);
}

bool Board_LED_Test(uint8_t LEDNumber)
{
	if (LEDNumber < (sizeof(gpioLEDBits) / sizeof(io_port_t)))
		return (bool) Chip_GPIO_GetPinState(LPC_GPIO_PORT, gpioLEDBits[LEDNumber].port, gpioLEDBits[LEDNumber].pin);

	return false;
}

void Board_LED_Toggle(uint8_t LEDNumber)
{
	Board_LED_Set(LEDNumber, !Board_LED_Test(LEDNumber));
}

void Board_Buttons_Init(void)
{
	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[4], SW1 */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO_PORT, BUTTONS_BUTTON1_GPIO_PORT_NUM, BUTTONS_BUTTON1_GPIO_BIT_NUM);	// input
}

uint32_t Buttons_GetStatus(void)
{
	uint8_t ret = NO_BUTTON_PRESSED;
	if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, BUTTONS_BUTTON1_GPIO_PORT_NUM, BUTTONS_BUTTON1_GPIO_BIT_NUM) == 0) {
		ret |= BUTTONS_BUTTON1;
	}
	return ret;
}

void Board_Joystick_Init(void)
{}

uint8_t Joystick_GetStatus(void)
{
	return NO_BUTTON_PRESSED;
}

/* Returns the MAC address assigned to this board */
void Board_ENET_GetMacADDR(uint8_t *mcaddr)
{
	uint8_t boardmac[] = {0x00, 0x60, 0x37, 0x12, 0x34, 0x56};

	memcpy(mcaddr, boardmac, 6);
}

/* Set up and initialize all required blocks and functions related to the
   board hardware */
void Board_Init(void)
{

	/* Sets up DEBUG UART */
	Board_Debug_Init();

	/* Initializes GPIO */
//	Chip_GPIO_Init(LPC_GPIO_PORT);

	Board_Ciaa_Gpios();

	/* Initialize LEDs */
//	Board_LED_Init();

#if defined(USE_RMII)
	Chip_ENET_RMIIEnable(LPC_ETHERNET);
#else
	Chip_ENET_MIIEnable(LPC_ETHERNET);
#endif
}

void Board_I2C_Init(I2C_ID_T id)
{
	if (id == I2C1) {
		/* Configure pin function for I2C1*/
		Chip_SCU_PinMuxSet(0x2, 3, (SCU_MODE_ZIF_DIS | SCU_MODE_INBUFF_EN | SCU_MODE_FUNC1));		/* P2.3 : I2C1_SDA */
		Chip_SCU_PinMuxSet(0x2, 4, (SCU_MODE_ZIF_DIS | SCU_MODE_INBUFF_EN | SCU_MODE_FUNC1));		/* P2.4 : I2C1_SCL */
	}
	else {
		Chip_SCU_I2C0PinConfig(I2C0_STANDARD_FAST_MODE);
	}
}

void Board_SDMMC_Init(void)
{
	Chip_SCU_PinMuxSet(0x1, 9, (SCU_PINIO_FAST | SCU_MODE_FUNC7));	/* P1.9 connected to SDIO_D0 */
	Chip_SCU_PinMuxSet(0x1, 10, (SCU_PINIO_FAST | SCU_MODE_FUNC7));	/* P1.10 connected to SDIO_D1 */
	Chip_SCU_PinMuxSet(0x1, 11, (SCU_PINIO_FAST | SCU_MODE_FUNC7));	/* P1.11 connected to SDIO_D2 */
	Chip_SCU_PinMuxSet(0x1, 12, (SCU_PINIO_FAST | SCU_MODE_FUNC7));	/* P1.12 connected to SDIO_D3 */

	Chip_SCU_ClockPinMuxSet(2, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_FUNC4));	/* CLK2 connected to SDIO_CLK */
	Chip_SCU_PinMuxSet(0x1, 6, (SCU_PINIO_FAST | SCU_MODE_FUNC7));	/* P1.6 connected to SDIO_CMD */
}

void Board_SSP_Init(LPC_SSP_T *pSSP)
{
	if (pSSP == LPC_SSP1) {
		/* Set up clock and power for SSP1 module */
		/* Configure SSP1 pins*/
		/* SCLK comes out pin CLK0 */
		Chip_SCU_ClockPinMuxSet(0, (SCU_PINIO_FAST | SCU_MODE_FUNC6));		/* CLK0 connected to CLK	SCU_MODE_FUNC6=SSP1 CLK1  */
		Chip_SCU_PinMuxSet(0x1, 5, (SCU_PINIO_FAST | SCU_MODE_FUNC5));			/* P1.5 connected to nCS	SCU_MODE_FUNC5=SSP1 SSEL1 */
		Chip_SCU_PinMuxSet(0x1, 3, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC5));/* P1.3 connected to SO		SCU_MODE_FUNC5=SSP1 MISO1 */
		Chip_SCU_PinMuxSet(0x1, 4, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC5));/* P1.4 connected to nSI	SCU_MODE_FUNC5=SSP1 MOSI1 */
	}
	else {
		return;
	}
}

/**
 * @}
 */
