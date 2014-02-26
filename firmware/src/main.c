#include <armv7m.h>
#include <debug.h>
#include <gpio.h>
#include <timer16.h>
#include <boardinit.h>
#include <leds.h>
#include <switches.h>
#include <buttons.h>
#include <gpio.h>
#include <ioconfig.h>
#include <sysctrl.h>
#include <delay.h>
#include <debug.h>
#include <string.h>
#include "adc.h"


int main() 
{
	// Init Board
	board_init();



///////////////////////////////////////
		ADCInit(4500000);
		uint32_t bat_val = ADCRead(0);

		bat_val = bat_val / 100;

		uint32_t bv;
		for (bv = 0; bv < bat_val; ++bv)
		{
			led_dbg_blue_power_on();
			delay_ticks(10000000);
			led_dbg_blue_power_off();
			delay_ticks(10000000);
		}


//////////////////////////////////////////////
	int delay_cnt = 10000;
	while (1)
	{
		// LED ....
		if (switch_dbg_is_set())
			led_dbg_red_power_on();
		else
			led_dbg_red_power_off();

///////////////////////////////////////////////

		if (btn_0_is_set())
			led_bat_3_power_on();
		else
			led_bat_3_power_off();

		if (btn_1_is_set())
			led_bat_2_power_on();
		else
			led_bat_2_power_off();

		if (btn_2_is_set())
			led_bat_1_power_on();
		else
			led_bat_1_power_off();

		if (btn_3_is_set())
			led_bat_0_power_on();
		else
			led_bat_0_power_off();



		if (btn_4_is_set())
			delay_cnt += 1000;

		if (btn_5_is_set())
			delay_cnt -= 1000;

		if (delay_cnt < 1000)
			delay_cnt = 1000;



///////////////////////////////////////////////




		led_ann_cs_all_off();
		int k;
		for (k = 0; k <= 9; ++k)
		{
			led_ann_1r_off();
			led_ann_1g_off();
			led_ann_1b_off();
			led_ann_2r_off();
			led_ann_2g_off();
			led_ann_2b_off();
			led_ann_3r_off();
			led_ann_3g_off();
			led_ann_3b_off();

			led_ann_cs_one_on(k);
			//delay_ticks(1000000);

			//led_ann_1r_off();
			//delay_ticks(10000000);
			led_ann_1r_on();
			delay_ticks(delay_cnt);
			//led_ann_1r_off();
			//delay_ticks(10000000);

			//led_ann_1g_off();
			//delay_ticks(10000000);
			led_ann_1g_on();
			delay_ticks(delay_cnt);
			//led_ann_1g_off();
			//delay_ticks(10000000);

			//led_ann_1b_off();
			//delay_ticks(10000000);
			led_ann_1b_on();
			delay_ticks(delay_cnt);
			//led_ann_1b_off();
			//delay_ticks(10000000);

			//led_ann_2r_off();
			//delay_ticks(10000000);
			led_ann_2r_on();
			delay_ticks(delay_cnt);
			//led_ann_2r_off();
			//delay_ticks(10000000);

			//led_ann_2g_off();
			//delay_ticks(10000000);
			led_ann_2g_on();
			delay_ticks(delay_cnt);
			//led_ann_2g_off();
			//delay_ticks(10000000);

			//led_ann_2b_off();
			//delay_ticks(10000000);
			led_ann_2b_on();
			delay_ticks(delay_cnt);
			//led_ann_2b_off();
			//delay_ticks(10000000);

			//led_ann_3r_off();
			//delay_ticks(10000000);
			led_ann_3r_on();
			delay_ticks(delay_cnt);
			//led_ann_3r_off();
			//delay_ticks(10000000);

			//led_ann_3g_off();
			//delay_ticks(10000000);
			led_ann_3g_on();
			delay_ticks(delay_cnt);
			//led_ann_3g_off();
			//delay_ticks(10000000);

			//led_ann_3b_off();
			//delay_ticks(10000000);
			led_ann_3b_on();
			delay_ticks(delay_cnt);
			//led_ann_3b_off();
			//delay_ticks(10000000);

			//delay_ticks(1000000);
		}
		led_ann_cs_all_off();

	}


	// Process Deffered Procedure Calls
	while (1)  // Forever
	{
		extern void DPCDispatch(void);
		DPCDispatch();
	}

	// This never return
	return 0;
} 

