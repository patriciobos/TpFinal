/*
 * rits.c
 *
 *  Created on: 12/11/2015
 *      Author: Juan Manuel Cruz
 */


#include "../../C_API/inc/rits.h"


typedef struct {
	uint16_t time;
	void (*hook) (void);
} rit_config_t;

void RIT_IRQHandler_Hook (void);

void Chip_RIT_SetTimerInterval_(LPC_RITIMER_T *pRITimer, uint32_t time_interval);

static volatile rit_config_t ritConfig = {1000, RIT_IRQHandler_Hook};


void configRit (uint16_t timeInterval_us, void (*isr)(void))
{
	ritConfig.time = timeInterval_us;
	ritConfig.hook = isr;

	/* Initialize RITimer */
	Chip_RIT_Init(LPC_RITIMER);

	/* Configure RIT for a 1s interrupt tick rate */
	Chip_RIT_SetTimerInterval_(LPC_RITIMER, ritConfig.time);

	NVIC_EnableIRQ(RITIMER_IRQn);
}


//__attribute__ ((section(".after_vectors")))
void RIT_IRQHandler (void)
{
	/* Clearn interrupt */
	Chip_RIT_ClearInt (LPC_RITIMER);

	/* Toggle LED */
	ritConfig.hook ();
}


void RIT_IRQHandler_Hook (void)
{

}

/* Set timer interval value */
void Chip_RIT_SetTimerInterval_(LPC_RITIMER_T *pRITimer, uint32_t time_interval)
{
	uint32_t cmp_value;

	/* Determine aapproximate compare value based on clock rate and passed interval */
	cmp_value = ((Chip_Clock_GetRate(CLK_MX_RITIMER) / 1000) * time_interval )/ 1000;

	/* Set timer compare value */
	Chip_RIT_SetCOMPVAL(pRITimer, cmp_value);

	/* Set timer enable clear bit to clear timer to 0 whenever
	   counter value equals the contents of RICOMPVAL */
	Chip_RIT_EnableCTRL(pRITimer, RIT_CTRL_ENCLR);
}
