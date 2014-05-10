#include "LPC13xx.h"
#include "timer16.h"

#include <config.h>
#include <gpio.h>
#include <leds.h>
#include <buttons.h>
#include "threads.h"


//volatile uint32_t timer16_0_counter = 0;
//volatile uint32_t timer16_1_counter = 0;



/******************************************************************************
** Function name:		TIMER_0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**						executes each 10ms @ 60 MHz CPU Clock
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void timer16_0_irqhandler(void)
{
	LPC_TMR16B0->IR = 1;			/* clear interrupt flag */
	//timer16_0_counter++;

	tick_thread_16_0();

	return;
}

/******************************************************************************
** Function name:		TIMER_1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**						executes each 10ms @ 60 MHz CPU Clock
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void timer16_1_irqhandler(void)
{
	LPC_TMR16B1->IR = 1;			/* clear interrupt flag */
	//timer16_1_counter++;

	tick_thread_16_1();

	return;
}

