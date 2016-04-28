/*
===============================================================================
 Name        : C_API_FUNCTIONAL_TEST.c
 Author      : $
 Version     :
 Copyright   : $(copyright)
 Description : main definitions for functional test the C_API
===============================================================================
*/


#include <cr_section_macros.h>

/*==================[inclusions]=============================================*/
#include "chip.h"

#include "../../C_API/inc/board.h"
#include "../../C_API/inc/C_API.h"       /* <= own header */
/*==================[macros and definitions]=================================*/
#define TEST_RGBs			 0		/*	Test RGB0G, RGB0R, RGB0B						*/
#define TEST_LEDs			 1		/*	Test LED1, LED2, LED3							*/
#define TEST_PWMs			 2		/*	Test PWM on LED1, LED2, LED3, GPIO2 & GPIO8		*/
#define TEST_UARTs			 3		/*	Test UART3 Tx => Rx with PWM on LED1			*/
#define TEST_GPIOsA			 4		/*	Test A - GPIO0, GPIO1, GPIO2, GPIO3, GPIO4,		*/
							 	 	/*		     GPIO5, GPIO6, GPIO7, GPIO8				*/
#define TEST_GPIOsB			 5		/*	Test B - GPIO0, GPIO1, GPIO2, GPIO3, GPIO4,		*/
							 	 	/*	         GPIO5, GPIO6, GPIO7, GPIO8				*/
#define TEST_IRQs			 6		/*	Test TECLA1, TECLA2, TECLA3, TECLA4	on IRQs		*/
							 	 	/*	      GPIO1,  GPIO3,  GPIO5,  GPIO7 on IRQs		*/
#define TEST_ADCs			 7		/*	Test ADCX on LEDs & RGBs						*/
#define TEST_DACsA		 	 8		/*	Test DAC => triangular wave						*/
#define TEST_DACsB			 9		/*	Test DAC => sine wave							*/
#define	TEST_RITs			10		/*	Test RIT on LED1								*/

#define	TEST_CIAA_NXP_LEDs	11		/*	Test CIAA_NXP on LED0 LED1 LED2 LED3			*/
#define TEST_CIAA_NXP_ADCs	12		/*	Test CIAA_NXP ADCX on LEDs 								*/

#define TEST	TEST_RGBs			/*	Type the mane of Test to do here 				*/

/*==================[internal data declaration]==============================*/
#if (TEST == TEST_IRQs)

static void	interrupcionTecla1 (void);
static void	interrupcionTecla2 (void);
static void	interrupcionTecla3 (void);
static void	interrupcionTecla4 (void);
static void	interrupcionGpio1 (void);
static void	interrupcionGpio3 (void);
static void	interrupcionGpio5 (void);
static void	interrupcionGpio7 (void);

#endif

#if (TEST == TEST_RITs)

static void	interrupcionRit (void);

#endif
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
 /** \brief Main function
  *
  * This is the main entry point of the software.
  *
  * \returns 0
  *
  * \remarks This function never returns. Return value is only to avoid compiler
  *          warnings or errors.
  */

#if (TEST == TEST_RGBs)
	/*	Test RGB0G, RGB0R, RGB0B					*/
int main (void)
{
	/* perform the needed initialization here */
 	uint8_t 	idx;
 	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 250;									/*	delay = 250mS			*/

 	while (1) {

	 	for (idx = 0; idx < (sizeof (rgb) / sizeof (rgb_t)); ++idx) {
	 	 	initRgb (rgb[idx]);

	 	 	setRgb (rgb[idx]);
	 	 	delay_ms (delay);

	 	 	clearRgb (rgb[idx]);
	 	 	delay_ms (delay);

	 	 	toggleRgb (rgb[idx]);
	 	 	delay_ms (delay);

	 	 	toggleRgb (rgb[idx]);
	 	 	delay_ms (delay);
	 	}
 	}

	return 0;
}
#endif


 #if (TEST == TEST_LEDs)
	/*	Test LED1, LED2, LED3						*/
int main (void)
{
	/* perform the needed initialization here */
 	uint8_t 	idx;
 	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 250;									/*	delay = 250mS			*/

 	while (1) {

	 	for (idx = 0; idx < (sizeof (led) / sizeof (led_t)); ++idx) {
	 	 	initLed (led[idx]);

	 	 	setLed (led[idx]);
	 	 	delay_ms (delay);

	 	 	clearLed (led[idx]);
	 	 	delay_ms (delay);

	 	 	toggleLed (led[idx]);
	 	 	delay_ms (delay);

	 	 	toggleLed (led[idx]);
	 	 	delay_ms (delay);
	 	}
 	}

	return 0;
}

#endif


#if (TEST == TEST_PWMs)
int main (void)
{
 	/*	Test PWM on LED1, LED2, LED3, GPIO2 & GPIO8; T = 10uS						*/
	/*	Place ORC passive probes on GPIO2 & GPIO8 pins of EDU-CIAA-NXP P2 connector	*/

	/* perform the needed initialization here */
 	uint8_t 	idx, duty;
 	uint32_t	period, delay;

 	/* add your code here */
 	initBoard ();

 	period = 1;											/*	period = 1uS to 1000000uS	*/
 	delay = 50;											/*	delay = 50mS				*/

 	while (1) {
		for (idx = 0; idx < (sizeof (pwm) / sizeof (pwm_t)); ++idx) {
			configPWM (period, pwm[idx]);				/*	PWM T = 1uS	*/
			startPWM ();								/*	Start PWM	*/
			for ( duty = 0; duty < 255; duty +=5 ) {	/*	PWM duty = 0 -> 255, duty += 5 & delay = 50mS	*/
				setPWM (duty, pwm[idx]);
				delay_ms (delay);
			}

			for ( duty = 255; duty > 0; duty -=5 ) {	/*	PWM duty = 255 -> 0, duty -= 5 & delay = 50mS	*/
				setPWM (duty, pwm[idx]);
				delay_ms (delay);
			}
			stopPWM();									/*	Stop PWM	*/
		}
	}

 	return 0;
}

#endif


#if (TEST == TEST_UARTs)
	/*	Test UART3 Tx => Rx with PWM on LED1									*/
	/*	Place jumper between 232_TX & 232_RX pins of EDU-CIAA-NXP P1 connector	*/
int main (void)
{
 	/* perform the needed initialization here */
	uint8_t		idx, duty, data;
	uint32_t	period, delay;

 	/* add your code here */
 	initBoard ();

 	idx = 0;										/*	PWM on LED1					*/
 	period = 10;									/*	period = 1uS to 1000000uS	*/
 	delay = 50;										/*	delay = 50mS				*/

 	configPWM (period, pwm[idx]);					/*	PWM T = period on ledPWM	*/
 	configUart (9600);								/*	UART baudrate = 9600		*/

	while (1) {
		startPWM();									/*	Start PWM					*/

		for (data = 0; data < 255; data += 5) {
			setUartTx (data);						/*	Tx = data					*/
			delay_ms (delay);
			duty = getUartData ();					/*	duty = Rx					*/
			setPWM (duty, pwm[idx]);
		}
		for (data = 255; data > 0; data -= 5) {
			setUartTx (data);						/*	Tx = data					*/
			delay_ms (delay);
			duty = getUartData ();					/*	duty = Rx					*/
			setPWM (duty,pwm[idx]);
		}

		stopPWM();									/*	Stop PWM					*/
	}

	return 0;
}

#endif


#if (TEST == TEST_GPIOsA)
	/*	Test GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7, GPIO8	*/
	/*	all GPIO�s => OUTPUT							*/
	/*	Place ORC passive probes on GPIOX pins of EDU-CIAA-NXP P2 connector	*/

int main (void)
{
 	/* perform the needed initialization here */
	uint8_t		idx;
 	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 10;											/*	delay = 10mS				*/
	for (idx = 0; idx < (sizeof (gpio) / sizeof (gpio_t)); ++idx)
			initGpio (gpio[idx], OUTPUT);				/*	Init all GPIO�s => OUTPUT	*/

	while (1) {

		for (idx = 0; idx < (sizeof (gpio) / sizeof (gpio_t)); ++idx) {
			toggleGpio(gpio[idx]);
			delay_ms (delay);
		}
	}

	return 0;
}

#endif


#if (TEST == TEST_GPIOsB)
	/*	Test GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7, GPIO8		*/
	/*	Place ORC passive probes on  GPIO8 pin  of EDU-CIAA-NXP P2 connector	*/
	/*	Place jumper between GPIO0 & GPIO2 pins of EDU-CIAA-NXP P2 connector	*/
	/*	Place jumper between GPIO1 & GPIO3 pins of EDU-CIAA-NXP P2 connector	*/
	/*	Place jumper between GPIO4 & GPIO6 pins of EDU-CIAA-NXP P2 connector	*/
	/*	Place jumper between GPIO5 & GPIO7 pins of EDU-CIAA-NXP P2 connector	*/

int main (void)
{
 	/* perform the needed initialization here */
	uint8_t		idx;
 	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 1;											/*	delay = 1mS				*/
	initGpio (gpio[0], OUTPUT);							/*	Init GPIO�s => OUTPUT 		*/
	initGpio (gpio[1], OUTPUT);
	initGpio (gpio[4], OUTPUT);
	initGpio (gpio[5], OUTPUT);
	initGpio (gpio[8], OUTPUT);

	while (1) {

		toggleGpio(gpio[0]);

		if (readGpio(gpio[2]))
			toggleGpio(gpio[1]);

		if (readGpio(gpio[3]))
			toggleGpio(gpio[4]);

		if (readGpio(gpio[6]))
			toggleGpio(gpio[5]);

		if (readGpio(gpio[7]))
			toggleGpio(gpio[8]);

		delay_ms (delay);
	}

	return 0;
}

#endif


#if (TEST == TEST_IRQs)
 	/*	Test TECLA1, TECLA2, TECLA3, TECLA4	on IRQs	*/
	/*	Test  GPIO1,  GPIO3,  GPIO5,  GPIO7 on IRQs	*/

int main (void)
{
 	/* perform the needed initialization here */

 	/* add your code here */
 	initBoard ();

 	configIrq (irq[0],  irqPin[0], interrupcionTecla1, 50);		/*	IRQ0 on TECLA1, debounce = 50mS*/
	configIrq (irq[1],  irqPin[1], interrupcionTecla2, 50);		/*	IRQ1 on TECLA2, debounce = 50mS	*/
	configIrq (irq[2],  irqPin[2], interrupcionTecla3, 50);		/*	IRQ2 on TECLA3, debounce = 50mS	*/
	configIrq (irq[3],  irqPin[3], interrupcionTecla4, 50);		/*	IRQ3 on TECLA4, debounce = 50mS	*/
	configIrq (irq[4],  irqPin[5],  interrupcionGpio1, 50);		/*	IRQ4 on  GPIO1, debounce = 50mS	*/
	configIrq (irq[5],  irqPin[7],  interrupcionGpio3, 50);		/*	IRQ4 on  GPIO3, debounce = 50mS	*/
	configIrq (irq[6],  irqPin[9],  interrupcionGpio5, 50);		/*	IRQ4 on  GPIO5, debounce = 50mS	*/
	configIrq (irq[7], irqPin[11],  interrupcionGpio7, 50);		/*	IRQ4 on  GPIO7, debounce = 50mS	*/

	while (1)
		__WFI();										/*	Wait for Interrupt	*/

	return 0;
}


void interrupcionTecla1 (void)
{
	toggleRgb (rgb[0]);
}


void interrupcionTecla2 (void)
{
	toggleRgb (rgb[1]);
}


void interrupcionTecla3 (void)
{
	toggleRgb (rgb[2]);
}


void interrupcionTecla4 (void)
{
	toggleRgb (rgb[0]);
	toggleRgb (rgb[1]);
	toggleRgb (rgb[2]);
}


void interrupcionGpio1 (void)
{
	toggleRgb (rgb[0]);
}


void interrupcionGpio3 (void)
{
	toggleRgb (rgb[1]);
}


void interrupcionGpio5 (void)
{
	toggleRgb (rgb[2]);
}


void interrupcionGpio7 (void)
{
	toggleRgb (rgb[0]);
	toggleRgb (rgb[1]);
	toggleRgb (rgb[2]);
}

#endif


#if (TEST == TEST_ADCs)
	/*	Test ADCX on LEDs & RGBs					*/

int main (void)
{
 	/* perform the needed initialization here */
	uint8_t		idx;
	uint16_t 	value;
 	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 50;											/*	delay = 5mS				*/

	while (1)
	{
		value = readAdc (adc[3]);

	 	for (idx = 0; idx < (sizeof (led) / sizeof (led_t)); ++idx) {
	 	 	clearLed (led[idx]);
	 	}

	 	for (idx = 0; idx < (sizeof (rgb) / sizeof (rgb_t)); ++idx) {
	 	 	clearRgb (rgb[idx]);
	 	}

	 	if (value > (5 * 1023/6))
	 		setRgb (rgb[0]);							/*	Over of (5/6) 3.3V		*/
	 	else
	 		if (value > (4 * 1023/6))
	 			setRgb (rgb[1]);						/*	Over of (4/6) 3.3V		*/
	 		else
	 			if (value > (3 * 1023/6))
	 				setRgb (rgb[2]);					/*	Over of (3/6) 3.3V		*/
	 			else
	 				if (value > (2 * 1023/6))
	 					setLed (led[0]);				/*	Over of (2/6) 3.3V		*/
	 				else
	 					if (value > (1 * 1023/6))
	 						setLed (led[1]);			/*	Over of (1/6) 3.3V		*/
	 					else
	 						setLed (led[2]);			/*	Under of (1/6) * 3.3V	*/

	 	delay_ms (delay);
	}

	return 0;
}

#endif


#if (TEST == TEST_DACsA)
	/*	Test DAC => triangular wave											*/
	/*	Place ORC passive probes on DAC pin of EDU-CIAA-NXP P1 connector	*/


int main (void)
{
 	/* perform the needed initialization here */
	uint16_t 	value;
	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 1;													/*	delay = 1mS				*/

	while (1) {
	 	for (value = 0; value < DAC_VALUE_SIZE; value += 5) {	/*	value = 0 -> 0x400, value += 5 & delay = 1mS	*/
	 		setLed (led[2]);

	 		setDacValue (value);

	 		clearLed (led[2]);

	 		delay_ms (delay);
	 	}
	}

	return 0;
}

#endif


#if (TEST == TEST_DACsB)
	/*	Test DAC => sine wave												*/
	/*	Place ORC passive probes on DAC pin of EDU-CIAA-NXP P1 connector	*/

#define	sineWave_t	uint16_t
const sineWave_t sineWave [] = {
	128, 153, 178, 200, 220, 236, 247, 254,
	255, 251, 242, 228, 211, 189, 166, 140,
	115,  89,  66,  44,  27,  13,   4,   0,
	  1,   8,  19,  35,  55,  77, 102, 127};

int main (void)
{
 	/* perform the needed initialization here */
	uint8_t		idx;
	uint16_t 	value;
	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 1;													/*	delay = 1mS				*/

	while (1) {
	 	for (idx = 0; idx < (sizeof (sineWave) / sizeof (sineWave_t)); ++idx) {
	 		value = 4 * sineWave[idx];
	 		setDacValue (value);								/*	value => 4 * tabla[idx], ++idx & delay = 1mS	*/
	 		delay_ms (delay);
	 	}
	}

	return 0;
}

#endif


#if (TEST == TEST_RITs)
	/*	Test RIT on LED1							*/

void interrupcionRit (void)
{
	toggleLed (led[1]);
}


int main (void)
{

	/* add your code here */
 	initBoard ();

 	configRit (400, interrupcionRit);							/*	RIT	->	250mS	& interrupcionRit	*/

	/* LED is toggled in interrupt handler */
	while (1);
}



#endif

#if (TEST == TEST_CIAA_NXP_LEDs)
	/*	Test LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7					*/
int main (void)
{
	/* perform the needed initialization here */
 	uint8_t 	idx;
 	uint32_t	delay;

 	/* add your code here */
 	initBoard();

 	delay = 200;									/*	delay = 200mS			*/

 	 	while (1) {

	 	for (idx = 0; idx < (sizeof (led) / sizeof (led_t)); ++idx) {
//	 	 	initLed (led[idx]);

	 	 	setLed (led[idx]);
	 	 	delay_ms (delay);

	 	 	clearLed (led[idx]);
	 	 	delay_ms (delay);

	 	 	toggleLed (led[idx]);
	 	 	delay_ms (delay);

	 	 	toggleLed (led[idx]);
	 	 	delay_ms (delay);
	 	}
 	}

	return 0;
}

#endif

#if (TEST == TEST_CIAA_NXP_ADCs)
	/*	Test ADCX on LEDs 0 to 3					*/

int main (void)
{
 	/* perform the needed initialization here */
	uint8_t		idx;
	uint16_t 	value;
 	uint32_t	delay;

 	/* add your code here */
 	initBoard ();

 	delay = 5;											/*	delay = 5mS				*/

	while (1)
	{
		value = readAdc (adc[3]);

	 	for (idx = 0; idx < (sizeof (led) / sizeof (led_t)); ++idx) {
	 	 	setLed (led[idx]);
	 	}
//
//	 	for (idx = 0; idx < (sizeof (rgb) / sizeof (rgb_t)); ++idx) {
//	 	 	clearRgb (rgb[idx]);
//	 	}

		if (value > (3 * 1023/4))
			clearLed (led[0]);				/*	Over of (3/4) * 3.3V		*/
		else
			if (value > (2 * 1023/4))
				clearLed (led[1]);			/*	Over of (2/4) * 3.3V		*/
			else
				if (value > (1 * 1023/4))
					clearLed (led[2]);		/*	Over of (1/4) * 3.3V		*/
				else
					clearLed (led[3]);		/*	Under of (1/4) * 3.3V	*/

	 	delay_ms (delay);
	}

	return 0;
}

#endif
