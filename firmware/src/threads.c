#include "threads.h"
#include <timer16.h>
#include <timer32.h>
#include "leds.h"
#include "buttons.h"
#include "adc.h"
#include "delay.h"
#include "switches.h"
#include "thread_buttons.h"
#include "thread_leds.h"
#include "thread_movie.h"



void init_threads(void)
{
    // Init threads
    thread_buttons_init();
    thread_leds_init();
    thread_movie_init();

    // Run threads
    init_timer16(0, 48000); // 1 ms
    enable_timer16(0);

    init_timer16(1, 48000); // 1 ms
    enable_timer16(1);

    init_timer32(0, 480*2); // 10 us
    enable_timer32(0);
}




void tick_thread_16_0(void)
{
    thread_buttons_tick();
}

void tick_thread_16_1(void)
{
    thread_movie_tick();
}

void tick_thread_32_0(void)
{
    thread_leds_tick();
}

void loop_main_thread(void)
{
    ADCInit(4500000);

    while (1)
    {
        uint32_t bat_val = ADCRead(0);

        thread_leds_set_bat_level(bat_val);

        delay_ticks(10000000);
    }

// Process Deffered Procedure Calls
//	while (1)  // Forever
//	{
//		extern void DPCDispatch(void);
//		DPCDispatch();
//	}
}
