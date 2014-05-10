#ifndef __TIMER32_H 
#define __TIMER32_H

#include <types.h>

//void delay32Ms(uint8_t timer_num, uint32_t delayInMs);
//void TIMER32_0_IRQHandler(void);
//void TIMER32_1_IRQHandler(void);
void enable_timer32(uint8_t timer_num);
//void disable_timer32(uint8_t timer_num);
//void reset_timer32(uint8_t timer_num);
void init_timer32(uint8_t timer_num, uint32_t timerInterval);


#endif /* end __TIMER32_H */

