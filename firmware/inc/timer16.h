#ifndef __TIMER16_H 
#define __TIMER16_H

#include "types.h"

//void delay_microseconds(uint8_t timer_num, uint32_t delayIn_us);
void enable_timer16(uint8_t timer_num);
//void disable_timer16(uint8_t timer_num);
//void reset_timer16(uint8_t timer_num);
void init_timer16(uint8_t timer_num, uint32_t timerInterval);

#endif /* end __TIMER16_H */

