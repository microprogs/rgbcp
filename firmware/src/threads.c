#include "threads.h"
#include <timer16.h>
#include <timer32.h>
#include "leds.h"
#include "buttons.h"
#include "adc.h"
#include "delay.h"
#include "switches.h"
#include "thread_buttons.h"


BTN_CONTEXT btn_ctx_0;
BTN_CONTEXT btn_ctx_1;

BTN_CONTEXT btn_ctx_2;
BTN_CONTEXT btn_ctx_3;

BTN_CONTEXT btn_ctx_4;
BTN_CONTEXT btn_ctx_5;


LED_CONTEXT led_bat_0_ctx;
LED_CONTEXT led_bat_1_ctx;
LED_CONTEXT led_bat_2_ctx;
LED_CONTEXT led_bat_3_ctx;


LED_CONTEXT led_ann_1b_ctx;
LED_CONTEXT led_ann_1g_ctx;
LED_CONTEXT led_ann_1r_ctx;

LED_CONTEXT led_ann_2b_ctx;
LED_CONTEXT led_ann_2g_ctx;
LED_CONTEXT led_ann_2r_ctx;

LED_CONTEXT led_ann_3b_ctx;
LED_CONTEXT led_ann_3g_ctx;
LED_CONTEXT led_ann_3r_ctx;












uint32_t mega_val = 0;


uint32_t bat_v = 0;


uint32_t cs_val = 0;

uint32_t sel_rgb = 0;

void next_red();

void btn_act_0(void)
{
//	mega_val++;
//	print_bat_leds(mega_val);
//	bat_v = ADCRead(0);
//	print_bat_leds(0);

	led_fsm_set_bright(&led_bat_0_ctx, led_fsm_get_bright(&led_bat_0_ctx) + 1);  // 0..brightMax

    /*if (sel_rgb == 0)
	{
		led_fsm_set_bright(&led_ann_1b_ctx, led_fsm_get_bright(&led_ann_1b_ctx) + 1);  // 0..brightMax
	}
	else if (sel_rgb == 1)
	{
		led_fsm_set_bright(&led_ann_2b_ctx, led_fsm_get_bright(&led_ann_2b_ctx) + 1);  // 0..brightMax
	}
	else if (sel_rgb == 2)
	{
		led_fsm_set_bright(&led_ann_3b_ctx, led_fsm_get_bright(&led_ann_3b_ctx) + 1);  // 0..brightMax
    }*/

    next_red();
}

void next_green();

void btn_act_1(void)
{
//	mega_val--;
//	print_bat_leds(mega_val);
//	print_bat_leds(bat_v & 0x00F);

	led_fsm_set_bright(&led_bat_1_ctx, led_fsm_get_bright(&led_bat_1_ctx) + 1);  // 0..brightMax

    /*if (sel_rgb == 0)
	{
		led_fsm_set_bright(&led_ann_1g_ctx, led_fsm_get_bright(&led_ann_1g_ctx) + 1);  // 0..brightMax
	}
	else if (sel_rgb == 1)
	{
		led_fsm_set_bright(&led_ann_2g_ctx, led_fsm_get_bright(&led_ann_2g_ctx) + 1);  // 0..brightMax
	}
	else if (sel_rgb == 2)
	{
		led_fsm_set_bright(&led_ann_3g_ctx, led_fsm_get_bright(&led_ann_3g_ctx) + 1);  // 0..brightMax
    }*/

    next_green();
}

void next_blue();

void btn_act_2(void)
{
//	mega_val <<= 1;
//	print_bat_leds(mega_val);
//	print_bat_leds((bat_v & 0x0F0) >> 4);

	led_fsm_set_bright(&led_bat_2_ctx, led_fsm_get_bright(&led_bat_2_ctx) + 1);  // 0..brightMax

    /*if (sel_rgb == 0)
	{
		led_fsm_set_bright(&led_ann_1r_ctx, led_fsm_get_bright(&led_ann_1r_ctx) + 1);  // 0..brightMax
	}
	else if (sel_rgb == 1)
	{
		led_fsm_set_bright(&led_ann_2r_ctx, led_fsm_get_bright(&led_ann_2r_ctx) + 1);  // 0..brightMax
	}
	else if (sel_rgb == 2)
	{
		led_fsm_set_bright(&led_ann_3r_ctx, led_fsm_get_bright(&led_ann_3r_ctx) + 1);  // 0..brightMax
    }*/

    next_blue();
}

void next_line();

void btn_act_3(void)
{
//	mega_val >>= 1;
//	print_bat_leds(mega_val);
//	print_bat_leds((bat_v & 0xF00) >> 8);

	led_fsm_set_bright(&led_bat_3_ctx, led_fsm_get_bright(&led_bat_3_ctx) + 1);  // 0..brightMax

    next_line();
}

void next_row();

void btn_act_4(void)
{
/*
	int f = mega_val & 0x8;
	mega_val <<= 1;
	if (f)
		mega_val |= 1;
	mega_val &= 0xF;
	print_bat_leds(mega_val);
*/
	mega_val /= 2;

	sel_rgb++;
	if (sel_rgb > 2)
		sel_rgb = 0;

    next_row();
}

void next_global_bright();

void btn_act_5(void)
{
/*
	int f = mega_val & 0x1;
	mega_val >>= 1;
	if (f)
		mega_val |= 0x8;
	mega_val &= 0xF;
	print_bat_leds(mega_val);
*/
	mega_val *= 2;

	cs_val++;
	if (cs_val > 9)
		cs_val = 0;

    next_global_bright();
}






void init_threads(void)
{
/////////////////////////////////////////////

#define N1_TIME 100
#define N2_TIME 50

	btn_fsm_init(&btn_ctx_0, btn_0_is_set, btn_act_0, N1_TIME, N2_TIME);
	btn_fsm_init(&btn_ctx_1, btn_1_is_set, btn_act_1, N1_TIME, N2_TIME);

	btn_fsm_init(&btn_ctx_2, btn_2_is_set, btn_act_2, N1_TIME, N2_TIME);
	btn_fsm_init(&btn_ctx_3, btn_3_is_set, btn_act_3, N1_TIME, N2_TIME);

	btn_fsm_init(&btn_ctx_4, btn_4_is_set, btn_act_4, N1_TIME, N2_TIME);
	btn_fsm_init(&btn_ctx_5, btn_5_is_set, btn_act_5, N1_TIME, N2_TIME);


	led_ann_cs_all_off();


	// LED FSM INIT
	led_fsm_init(&led_bat_0_ctx, 100, led_bat_0_power_off, led_bat_0_power_on);
	led_fsm_init(&led_bat_1_ctx, 100, led_bat_1_power_off, led_bat_1_power_on);
	led_fsm_init(&led_bat_2_ctx, 100, led_bat_2_power_off, led_bat_2_power_on);
	led_fsm_init(&led_bat_3_ctx, 100, led_bat_3_power_off, led_bat_3_power_on);


	led_fsm_set_bright(&led_bat_0_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_bat_1_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_bat_2_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_bat_3_ctx, 0);  // 0..brightMax



	//


/*    led_fsm_init(&led_ann_1b_ctx, LED_MAX_VAL, led_ann_1b_off, led_ann_1b_on);
    led_fsm_init(&led_ann_1g_ctx, LED_MAX_VAL, led_ann_1g_off, led_ann_1g_on);
    led_fsm_init(&led_ann_1r_ctx, LED_MAX_VAL, led_ann_1r_off, led_ann_1r_on);

    led_fsm_init(&led_ann_2b_ctx, LED_MAX_VAL, led_ann_2b_off, led_ann_2b_on);
    led_fsm_init(&led_ann_2g_ctx, LED_MAX_VAL, led_ann_2g_off, led_ann_2g_on);
    led_fsm_init(&led_ann_2r_ctx, LED_MAX_VAL, led_ann_2r_off, led_ann_2r_on);

    led_fsm_init(&led_ann_3b_ctx, LED_MAX_VAL, led_ann_3b_off, led_ann_3b_on);
    led_fsm_init(&led_ann_3g_ctx, LED_MAX_VAL, led_ann_3g_off, led_ann_3g_on);
    led_fsm_init(&led_ann_3r_ctx, LED_MAX_VAL, led_ann_3r_off, led_ann_3r_on);


	led_fsm_set_bright(&led_ann_1b_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_ann_1g_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_ann_1r_ctx, 0);  // 0..brightMax
	
	led_fsm_set_bright(&led_ann_2b_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_ann_2g_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_ann_2r_ctx, 0);  // 0..brightMax

	led_fsm_set_bright(&led_ann_3b_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_ann_3g_ctx, 0);  // 0..brightMax
	led_fsm_set_bright(&led_ann_3r_ctx, 0);  // 0..brightMax
*/

///////////////////////////////////////////
    ADCInit(4500000);

///////////////////////////////////////////

		uint32_t bat_val = ADCRead(0);

		bat_val = bat_val / 100;

		led_dbg_red_power_on();

		uint32_t bv;
		for (bv = 0; bv < bat_val; ++bv)
		{
			led_dbg_blue_power_on();
			delay_ticks(1000000);
			led_dbg_blue_power_off();
			delay_ticks(1000000);
		}
///////////////////////////////////////////


        init_timer16(0, 48000); // 1 ms
        enable_timer16(0);

        init_timer16(1, 48000); // 1 ms
        enable_timer16(1);

        //init_timer32(0, 480*2); // 10 us
        //enable_timer32(0);



    ///////////////////////////////////////////



}


//extern int32_t brightness_level;

static int cnt_0 = 0;
static int f_0 = 0;


void tick_thread_16_0(void)
{
	++cnt_0;
	if (cnt_0 >= 1000000)
	{
		cnt_0 = 0;
		if (f_0 == 1)
			f_0 = 0;
		else
			f_0 = 1;

		//if (f_0)
		//	led_bat_0_power_on();
		//else
		//	led_bat_0_power_off();
	}

	//if (btn_1_is_set())
	//	brightness_level++;

	//if (btn_0_is_set())
	//	brightness_level--;

	//if (brightness_level <= 0)
	//	brightness_level = 0;

	btn_fsm_step(&btn_ctx_0);
	btn_fsm_step(&btn_ctx_1);

	btn_fsm_step(&btn_ctx_2);
	btn_fsm_step(&btn_ctx_3);

	btn_fsm_step(&btn_ctx_4);
	btn_fsm_step(&btn_ctx_5);
}

/*
static uint32_t convert_bat_adc_to_leds_0_15(uint32_t bat_val)
{
#define BAT_VAL_LOW	336
#define BAT_VAL_HIGH	644
#define BAT_VAL_STEP	((BAT_VAL_HIGH - BAT_VAL_LOW) / 4)
	if (bat_val >= BAT_VAL_HIGH)
		bat_val = BAT_VAL_HIGH;
	if (bat_val <= BAT_VAL_LOW)
		bat_val = BAT_VAL_LOW;

	// bat_val = 336..644
	bat_val -= BAT_VAL_LOW;

	// bat_val = 0..308
	uint32_t res = 0;

	if (bat_val >= 1*BAT_VAL_STEP)
		res |= 0x1;

	if (bat_val >= 2*BAT_VAL_STEP)
		res |= 0x2;

	if (bat_val >= 3*BAT_VAL_STEP)
		res |= 0x4;

	if (bat_val >= 4*BAT_VAL_STEP)
		res |= 0x8;

	return res;
}
*/






static int cnt_1 = 0;
//static int f_1 = 0;
void tick_thread_16_1(void)
{
/*	++cnt_1;
	if (cnt_1 >= 200)
	{
		cnt_1 = 0;
		if (f_1 == 1)
			f_1 = 0;
		else
			f_1 = 1;

		if (f_1)
			led_dbg_red_power_on();
		else
			led_dbg_red_power_off();

		uint32_t bat_val = ADCRead(0);

	void print_bat_leds(uint32_t val);  // val=0-15	
	}
*/

	++cnt_1;
	if (cnt_1 >= mega_val)
	{
		cnt_1 = 0;

//		led_fsm_step(&led_bat_0_ctx);
//		led_fsm_step(&led_bat_1_ctx);
//		led_fsm_step(&led_bat_2_ctx);
//		led_fsm_step(&led_bat_3_ctx);	
	}
}

static int cnt32_0 = 0;
static int f32_0 = 0;

int next_cs = 0;
int next_cnt = 0;

void tick_thread_32_0(void)
{

	++cnt32_0;
	if (cnt32_0 >= mega_val)
	{
		cnt32_0 = 0;
		if (f32_0 == 1)
			f32_0 = 0;
		else
			f32_0 = 1;

		//if (f32_0)
		//	led_bat_2_power_on();
		//else
		//	led_bat_2_power_off();

		led_fsm_step(&led_bat_0_ctx);
		led_fsm_step(&led_bat_1_ctx);
		led_fsm_step(&led_bat_2_ctx);
		led_fsm_step(&led_bat_3_ctx);	
	}

///////////////////////////////////////

/*    next_cnt++;
    if (next_cnt >= 1*LED_MAX_VAL)
    {
        next_cnt = 0;

        next_cs++;
        if (next_cs > 9)
            next_cs = 0;
    }


    led_ann_cs_one_on(next_cs);

	led_fsm_step(&led_ann_1b_ctx);
	led_fsm_step(&led_ann_1g_ctx);
	led_fsm_step(&led_ann_1r_ctx);

	led_fsm_step(&led_ann_2b_ctx);
	led_fsm_step(&led_ann_2g_ctx);
	led_fsm_step(&led_ann_2r_ctx);

	led_fsm_step(&led_ann_3b_ctx);
	led_fsm_step(&led_ann_3g_ctx);
	led_fsm_step(&led_ann_3r_ctx);
    */
}


static uint32_t s_line = 0;
static uint32_t s_row = 0;

void next_line()
{
    s_line++;
    if (s_line > 9)
        s_line = 0;
}

void next_row()
{
    s_row++;
    if (s_row > 2)
        s_row = 0;
}

void next_red()
{
    uint8_t s_red = led_matrix_fsm_get_red(s_line, s_row);
    uint8_t s_green = led_matrix_fsm_get_green(s_line, s_row);
    uint8_t s_blue = led_matrix_fsm_get_blue(s_line, s_row);

    s_red++;

    led_matrix_fsm_set_rgb_bright(s_line, s_row, s_red, s_green, s_blue);
}

void next_green()
{
    uint8_t s_red = led_matrix_fsm_get_red(s_line, s_row);
    uint8_t s_green = led_matrix_fsm_get_green(s_line, s_row);
    uint8_t s_blue = led_matrix_fsm_get_blue(s_line, s_row);

    s_green++;

    led_matrix_fsm_set_rgb_bright(s_line, s_row, s_red, s_green, s_blue);
}

void next_blue()
{
    uint8_t s_red = led_matrix_fsm_get_red(s_line, s_row);
    uint8_t s_green = led_matrix_fsm_get_green(s_line, s_row);
    uint8_t s_blue = led_matrix_fsm_get_blue(s_line, s_row);

    s_blue++;

    led_matrix_fsm_set_rgb_bright(s_line, s_row, s_red, s_green, s_blue);
}






void next_global_bright()
{
    uint32_t b = led_matrix_fsm_get_global_bright() + 1;
    if (b > 5)
        b = 1;
    led_matrix_fsm_set_global_bright(b); //1..5
}


void loop_main_thread(void)
{
#define LED_GLOBAL_BRIGHT_MAX 5
#define LED_BRIGHT_MAX 7


    led_matrix_fsm_init(LED_BRIGHT_MAX, LED_GLOBAL_BRIGHT_MAX);

    while(1)
    {
        led_matrix_fsm_step();
    }


    while(1)
    {
        tick_thread_32_0();
    }

	while (1)
	{
			led_dbg_green_power_on();
			delay_ticks(1000000);
			led_dbg_green_power_off();
			delay_ticks(1000000);
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

		//if (btn_0_is_set())
		//	led_bat_3_power_on();
		//else
		//	led_bat_3_power_off();

		//if (btn_1_is_set())
		//	led_bat_2_power_on();
		//else
		//	led_bat_2_power_off();

		//if (btn_2_is_set())
		//	led_bat_1_power_on();
		//else
		//	led_bat_1_power_off();

		//if (btn_3_is_set())
		//	led_bat_0_power_on();
		//else
		//	led_bat_0_power_off();



		//if (btn_4_is_set())
		//	delay_cnt += 1000;

		//if (btn_5_is_set())
		//	delay_cnt -= 1000;

		//if (delay_cnt < 1000)
		//	delay_cnt = 1000;

		//delay_cnt = 10000 + 1000 * brightness_level;



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




	while (1)
	{
			led_dbg_green_power_on();
			delay_ticks(1000000);
			led_dbg_green_power_off();
			delay_ticks(1000000);
	}

	// Process Deffered Procedure Calls
	while (1)  // Forever
	{
		extern void DPCDispatch(void);
		DPCDispatch();
	}

}

