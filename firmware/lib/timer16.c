#include "LPC13xx.h"
#include "timer16.h"
#include <config.h>

/*****************************************************************************
** Function name:		delay_microseconds
**
** Descriptions:		Start the timer delay in microseconds (1/1000000 sec)
**						until elapsed
**
** parameters:			timer number, Delay value in microseconds
** 						
** Returned value:		None
** 
*****************************************************************************/
//void delay_microseconds(uint8_t timer_num, uint32_t delayIn_us)
//{
//  if (timer_num == 0)
//  {
//    /*
//    * setup timer #0 for delay
//    */
//    LPC_TMR16B0->TCR = 0x02;		/* reset timer */
//    LPC_TMR16B0->PR  = 0x00;		/* set prescaler to zero */
//    LPC_TMR16B0->MR0 = delayIn_us * ((SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV)/ 1000000);
//    LPC_TMR16B0->IR  = 0xff;		/* reset all interrrupts */
//    LPC_TMR16B0->MCR = 0x04;		/* stop timer on match */
//    LPC_TMR16B0->TCR = 0x01;		/* start timer */
//    /* wait until delay time has elapsed */
//    while (LPC_TMR16B0->TCR & 0x01);
//  }
//  else if (timer_num == 1)
//  {
//    /*
//    * setup timer #1 for delay
//    */
 //   LPC_TMR16B1->TCR = 0x02;		/* reset timer */
//    LPC_TMR16B1->PR  = 0x00;		/* set prescaler to zero */
 //   LPC_TMR16B1->MR0 = delayIn_us * ((SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV) / 1000000);
//    LPC_TMR16B1->IR  = 0xff;		/* reset all interrrupts */
//    LPC_TMR16B1->MCR = 0x04;		/* stop timer on match */
//    LPC_TMR16B1->TCR = 0x01;		/* start timer */
 //   /* wait until delay time has elapsed */
 //   while (LPC_TMR16B1->TCR & 0x01);
//  }
//  return;
//}

/******************************************************************************
** Function name:		enable_timer
**
** Descriptions:		Enable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
** 
******************************************************************************/
void enable_timer16(uint8_t timer_num)
{
  if ( timer_num == 0 )
  {
    LPC_TMR16B0->TCR = 1;
  }
  else
  {
    LPC_TMR16B1->TCR = 1;
  }
  return;
}

/******************************************************************************
** Function name:		disable_timer
**
** Descriptions:		Disable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
** 
******************************************************************************/
/*void disable_timer16(uint8_t timer_num)
{
  if ( timer_num == 0 )
  {
    LPC_TMR16B0->TCR = 0;
  }
  else
  {
    LPC_TMR16B1->TCR = 0;
  }
  return;
}*/

/******************************************************************************
** Function name:		reset_timer
**
** Descriptions:		Reset timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
** 
******************************************************************************/
/*void reset_timer16(uint8_t timer_num)
{
  uint32_t regVal;

  if ( timer_num == 0 )
  {
    regVal = LPC_TMR16B0->TCR;
    regVal |= 0x02;
    LPC_TMR16B0->TCR = regVal;
  }
  else
  {
    regVal = LPC_TMR16B1->TCR;
    regVal |= 0x02;
    LPC_TMR16B1->TCR = regVal;
  }
  return;
}*/

/******************************************************************************
** Function name:		init_timer
**
** Descriptions:		Initialize timer, set timer interval, reset timer,
**						install timer interrupt handler
**
** parameters:			timer number and timer interval
** Returned value:		None
** 
******************************************************************************/
void init_timer16(uint8_t timer_num, uint32_t TimerInterval) 
{
  if ( timer_num == 0 )
  {
    /* Some of the I/O pins need to be clearfully planned if
    you use below module because JTAG and TIMER CAP/MAT pins are muxed. */
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);
    //LPC_IOCON->PIO0_2           &= ~0x07;	/*  Timer0_16 I/O config */
    //LPC_IOCON->PIO0_2           |= 0x02;		/* Timer0_16 CAP0 */
    //LPC_IOCON->PIO0_8           &= ~0x07;	
    //LPC_IOCON->PIO0_8           |= 0x02;		/* Timer0_16 MAT0 */
    //LPC_IOCON->PIO0_9           &= ~0x07;
    //LPC_IOCON->PIO0_9           |= 0x02;		/* Timer0_16 MAT1 */
    //LPC_IOCON->JTAG_TCK_PIO0_10 &= ~0x07;
    //LPC_IOCON->JTAG_TCK_PIO0_10 |= 0x03;		/* Timer0_16 MAT2 */

    LPC_TMR16B0->MR0 = TimerInterval;
//	LPC_TMR16B0->EMR &= ~(0xFF<<4);
//	LPC_TMR16B0->EMR |= ((0x3<<4)|(0x3<<6));
    LPC_TMR16B0->MCR = 3;				/* Interrupt and Reset on MR0 */

    /* Enable the TIMER0 Interrupt */
	NVIC_SetPriority(TIMER_16_0_IRQn, 0);
    NVIC_EnableIRQ(TIMER_16_0_IRQn);
  }
  else if ( timer_num == 1 )
  {
    /* Some of the I/O pins need to be clearfully planned if
    you use below module because JTAG and TIMER CAP/MAT pins are muxed. */
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<8);
    //LPC_IOCON->PIO1_8           &= ~0x07;	/*  Timer1_16 I/O config */
    //LPC_IOCON->PIO1_8           |= 0x01;		/* Timer1_16 CAP0 */
    //LPC_IOCON->PIO1_9           &= ~0x07;	
    //LPC_IOCON->PIO1_9           |= 0x01;		/* Timer1_16 MAT0 */
    //LPC_IOCON->PIO1_10          &= ~0x07;
    //LPC_IOCON->PIO1_10          |= 0x02;		/* Timer1_16 MAT1 */	

    LPC_TMR16B1->MR0 = TimerInterval;
//	LPC_TMR16B1->EMR &= ~(0xFF<<4);
//	LPC_TMR16B1->EMR |= ((0x3<<4)|(0x3<<6));
    LPC_TMR16B1->MCR = 3;				/* Interrupt and Reset on MR1 */

    /* Enable the TIMER1 Interrupt */
	//NVIC_SetPriority(TIMER_16_1_IRQn, 0);
    NVIC_EnableIRQ(TIMER_16_1_IRQn);
  }
  return;
}

