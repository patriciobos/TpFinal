//CAPI
#include "lpc_176X_PeriphNames.h"
#include "lpc_176X_PinNames.h"
#include "GPIO.h"
#include "UART.h"
UART Consola;

/* Standard includes. */
#include <string.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* lwIP includes. */
#include "lwip/tcpip.h"

#include "AHBRAM.h"

static void Heartbeat 			(void* pvParameters); //Destello un led
extern void lwIPAppsInit		( void *pvArguments );	/* Defined in lwIPApps.c. */
static void prvSetupHardware	( void );

/*-----------------------------------------------------------*/

int main( void )
{
	prvSetupHardware();

	xTaskCreate	( Heartbeat, (signed char *)"Heartbeat", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
	tcpip_init	( lwIPAppsInit, NULL ); // This call creates the TCP/IP thread.

	vTaskStartScheduler();

	for( ;; );
}

static void prvSetupHardware( void )
{
	UARTInit(&Consola, UART_3, 115200, 8, 'n', 1);
	UARTputs(&Consola, "Uart OK", UART_PUTS_INTERRUPCIONES);

	/* The examples assume that all priority bits are assigned as preemption priority bits. */
	NVIC_SetPriorityGrouping( 0UL );

	/* Force some large data structures into AHB RAM to keep the calculated flash+RAM code size down. */
	prvManuallyPlaceLargeDataInAHBRAM();
}

//-----------------------------------------------------------------------------

#if 1 //Hooks
void vApplicationMallocFailedHook( void )
{
	taskDISABLE_INTERRUPTS();
	for( ;; );
}

void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	taskDISABLE_INTERRUPTS();
	for( ;; );
}

//NO se usan en esta aplicacion
void vApplicationIdleHook( void )
{

}

void vApplicationTickHook( void )
{

}
#endif

static void Heartbeat (void* pvParameters)
{
	GPIO Rojo, Verde, Azul;
	GPIO_Init(&Rojo, 	SALIDA, ALTO, EABASE_RGB_ROJO);
	GPIO_Init(&Verde, 	SALIDA, ALTO, EABASE_RGB_VERDE);
	GPIO_Init(&Azul, 	SALIDA, ALTO, EABASE_RGB_AZUL);

	while(1)
	{
		isActivo(&Rojo) ? Pasivar(&Rojo) : Activar (&Rojo);
		vTaskDelay(500 / portTICK_RATE_MS);
	}
}
