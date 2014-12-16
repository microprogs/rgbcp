#ifndef THREAD_LEDS_H
#define THREAD_LEDS_H


#include "types.h"


void thread_leds_init();
void thread_leds_tick();
void thread_leds_set_bat_level(uint32_t bat_val);


#endif
