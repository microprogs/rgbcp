#include <leds.h>
#include <gpio.h>

void init_leds(void)
{
//	gpio_set_dir_out(LED_RED_PORT, LED_RED_BIT);
//	gpio_set_data_bit_zero(LED_RED_PORT, LED_RED_BIT);

//	gpio_set_dir_out(LED_GREEN_PORT, LED_GREEN_BIT);
//	gpio_set_data_bit_zero(LED_GREEN_PORT, LED_GREEN_BIT);
	led_dbg_red_power_off();
	led_dbg_green_power_off();
	led_dbg_blue_power_off();

	led_bat_0_power_off();
	led_bat_1_power_off();
	led_bat_2_power_off();
	led_bat_3_power_off();


	gpio_set_dir_out(2, 0);
	gpio_set_data_bit_zero(2, 0);

	gpio_set_dir_out(2, 1);
	gpio_set_data_bit_zero(2, 1);

	gpio_set_dir_out(2, 2);
	gpio_set_data_bit_zero(2, 2);

	gpio_set_dir_out(2, 3);
	gpio_set_data_bit_zero(2, 3);

	gpio_set_dir_out(2, 4);
	gpio_set_data_bit_zero(2, 4);

	gpio_set_dir_out(2, 5);
	gpio_set_data_bit_zero(2, 5);

	gpio_set_dir_out(2, 6);
	gpio_set_data_bit_zero(2, 6);

	gpio_set_dir_out(2, 7);
	gpio_set_data_bit_zero(2, 7);

	gpio_set_dir_out(2, 8);
	gpio_set_data_bit_zero(2, 8);

	gpio_set_dir_out(2, 9);
	gpio_set_data_bit_zero(2, 9);



	// PIO1_0 - LED_ANN_1B
	led_ann_1b_off();
	// PIO1_1 - LED_ANN_1G
	led_ann_1g_off();
	// PIO1_2 - LED_ANN_1R
	led_ann_1r_off();

	// PIO1_3 - LED_ANN_2B
	led_ann_2b_off();
	// PIO1_4 - LED_ANN_2G
	led_ann_2g_off();
	// PIO1_5 - LED_ANN_2R
	led_ann_2r_off();

	// PIO1_6 - LED_ANN_3B
	led_ann_3b_off();
	// PIO1_7 - LED_ANN_3G
	led_ann_3g_off();
	// PIO1_8 - LED_ANN_3R
	led_ann_3r_off();
}

void led_dbg_red_power_off(void)
{
	gpio_set_dir_in(3, 1);
}

void led_dbg_red_power_on(void)
{
	gpio_set_dir_out(3, 1);
	gpio_set_data_bit_zero(3, 1);
}

void led_dbg_green_power_off(void)
{
	gpio_set_dir_in(3, 2);
}

void led_dbg_green_power_on(void)
{
	gpio_set_dir_out(3, 2);
	gpio_set_data_bit_zero(3, 2);
}

void led_dbg_blue_power_off(void)
{
	gpio_set_dir_in(3, 3);
}

void led_dbg_blue_power_on(void)
{
	gpio_set_dir_out(3, 3);
	gpio_set_data_bit_zero(3, 3);
}



void led_bat_0_power_off(void)
{
	gpio_set_dir_in(0, 10);
}

void led_bat_0_power_on(void)
{
	gpio_set_dir_out(0, 10);
	gpio_set_data_bit_zero(0, 10);
}


void led_bat_1_power_off(void)
{
	gpio_set_dir_in(1, 9);
}

void led_bat_1_power_on(void)
{
	gpio_set_dir_out(1, 9);
	gpio_set_data_bit_zero(1, 9);
}


void led_bat_2_power_off(void)
{
	gpio_set_dir_in(1, 10);
}

void led_bat_2_power_on(void)
{
	gpio_set_dir_out(1, 10);
	gpio_set_data_bit_zero(1, 10);
}


void led_bat_3_power_off(void)
{
	gpio_set_dir_in(1, 11);
}

void led_bat_3_power_on(void)
{
	gpio_set_dir_out(1, 11);
	gpio_set_data_bit_zero(1, 11);
}



void led_ann_cs_all_off(void)
{
	gpio_set_data_bit_zero(2, 0);
	gpio_set_data_bit_zero(2, 1);
	gpio_set_data_bit_zero(2, 2);
	gpio_set_data_bit_zero(2, 3);
	gpio_set_data_bit_zero(2, 4);
	gpio_set_data_bit_zero(2, 5);
	gpio_set_data_bit_zero(2, 6);
	gpio_set_data_bit_zero(2, 7);
	gpio_set_data_bit_zero(2, 8);
	gpio_set_data_bit_zero(2, 9);
}

void led_ann_cs_one_on(uint32_t num)
{
	led_ann_cs_all_off();
	if ((num >= 0) && (num <= 9))
		gpio_set_data_bit_one(2, num);
}



// PIO1_0 - LED_ANN_1B
void led_ann_1g_off(void)
{
	gpio_set_dir_in(1, 0);
}

void led_ann_1g_on(void)
{
	gpio_set_dir_out(1, 0);
	gpio_set_data_bit_zero(1, 0);
}

// PIO1_1 - LED_ANN_1G
void led_ann_1b_off(void)
{
	gpio_set_dir_in(1, 1);
}

void led_ann_1b_on(void)
{
	gpio_set_dir_out(1, 1);
	gpio_set_data_bit_zero(1, 1);
}

// PIO1_2 - LED_ANN_1R
void led_ann_1r_off(void)
{
	gpio_set_dir_in(1, 2);
}

void led_ann_1r_on(void)
{
	gpio_set_dir_out(1, 2);
	gpio_set_data_bit_zero(1, 2);
}

// PIO1_3 - LED_ANN_2B
void led_ann_2g_off(void)
{
	gpio_set_dir_in(1, 3);
}

void led_ann_2g_on(void)
{
	gpio_set_dir_out(1, 3);
	gpio_set_data_bit_zero(1, 3);
}

// PIO1_4 - LED_ANN_2G
void led_ann_2b_off(void)
{
	gpio_set_dir_in(1, 4);
}

void led_ann_2b_on(void)
{
	gpio_set_dir_out(1, 4);
	gpio_set_data_bit_zero(1, 4);
}

// PIO1_5 - LED_ANN_2R
void led_ann_2r_off(void)
{
	gpio_set_dir_in(1, 5);
}

void led_ann_2r_on(void)
{
	gpio_set_dir_out(1, 5);
	gpio_set_data_bit_zero(1, 5);
}

// PIO1_6 - LED_ANN_3B
void led_ann_3g_off(void)
{
	gpio_set_dir_in(1, 6);
}

void led_ann_3g_on(void)
{
	gpio_set_dir_out(1, 6);
	gpio_set_data_bit_zero(1, 6);
}

// PIO1_7 - LED_ANN_3G
void led_ann_3b_off(void)
{
	gpio_set_dir_in(1, 7);
}

void led_ann_3b_on(void)
{
	gpio_set_dir_out(1, 7);
	gpio_set_data_bit_zero(1, 7);
}

// PIO1_8 - LED_ANN_3R
void led_ann_3r_off(void)
{
	gpio_set_dir_in(1, 8);
}

void led_ann_3r_on(void)
{
	gpio_set_dir_out(1, 8);
	gpio_set_data_bit_zero(1, 8);
}




/*
void led_red_power(uint32_t val)
{
	if (val)
		led_red_power_on();
	else
		led_red_power_off();
}

void led_red_power_off(void)
{
	gpio_set_data_bit_zero(LED_RED_PORT, LED_RED_BIT);
}

void led_red_power_on(void)
{
	gpio_set_data_bit_one(LED_RED_PORT, LED_RED_BIT);
}

void led_green_power(uint32_t val)
{
	if (val)
		led_green_power_on();
	else
		led_green_power_off();
}

void led_green_power_off(void)
{
	gpio_set_data_bit_zero(LED_GREEN_PORT, LED_GREEN_BIT);
}

void led_green_power_on(void)
{
	gpio_set_data_bit_one(LED_GREEN_PORT, LED_GREEN_BIT);
}
*/
