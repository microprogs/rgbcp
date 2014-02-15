#include <leds.h>
#include <gpio.h>

void init_leds(void)
{
//	gpio_set_dir_out(LED_RED_PORT, LED_RED_BIT);
//	gpio_set_data_bit_zero(LED_RED_PORT, LED_RED_BIT);

//	gpio_set_dir_out(LED_GREEN_PORT, LED_GREEN_BIT);
//	gpio_set_data_bit_zero(LED_GREEN_PORT, LED_GREEN_BIT);
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
