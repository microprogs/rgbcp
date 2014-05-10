#include "LPC13xx.h"
#include "timer32.h"
#include "leds.h"
#include "threads.h"

//volatile uint32_t timer32_0_counter = 0;
//volatile uint32_t timer32_1_counter = 0;



/******************************************************************************
** Function name:		TIMER32_0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**						executes each 10ms @ 60 MHz CPU Clock
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void timer32_0_irqhandler(void)
{
  LPC_TMR32B0->IR = 1;			/* clear interrupt flag */
  //timer32_0_counter++;

  tick_thread_32_0();

  return;
}

/******************************************************************************
** Function name:		TIMER32_1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**						executes each 10ms @ 60 MHz CPU Clock
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
// USED BY ROM USB HID DRV
/*void timer32_1_irqhandler(void)
{
  LPC_TMR32B1->IR = 1;			// clear interrupt flag
  //timer32_1_counter++;
  return;
}*/


