#include <buttons.h>
#include <gpio.h>

void init_buttons(void)
{
	// PIO2_10 - BTN_0
	gpio_set_dir_in(2, 10);

	// PIO0_5 - BTN_1
	gpio_set_dir_in(0, 5);

	// PIO2_11 - BTN_2
	gpio_set_dir_in(2, 11);

	// PIO0_7 - BTN_3
	gpio_set_dir_in(0, 7);

	// PIO0_8 - BTN_4
	gpio_set_dir_in(0, 8);

	// PIO0_9 - BTN_5
	gpio_set_dir_in(0, 9);
}

// PIO2_10 - BTN_0
uint32_t btn_0_is_set(void)
{
	// PIO2_10 - BTN_0
	return gpio_get_data_bit(2, 10) ? 0 : 1;	
}

// PIO0_5 - BTN_1
uint32_t btn_1_is_set(void)
{
// PIO0_5 - BTN_1
	return gpio_get_data_bit(0, 5) ? 0 : 1;
}

// PIO2_11 - BTN_2
uint32_t btn_2_is_set(void)
{
// PIO2_11 - BTN_2
	return gpio_get_data_bit(2, 11) ? 0 : 1;
}

// PIO0_7 - BTN_3
uint32_t btn_3_is_set(void)
{
// PIO0_7 - BTN_3
	return gpio_get_data_bit(0, 7) ? 0 : 1;
}

// PIO0_8 - BTN_4
uint32_t btn_4_is_set(void)
{
// PIO0_8 - BTN_4
	return gpio_get_data_bit(0, 8) ? 0 : 1;
}

// PIO0_9 - BTN_5
uint32_t btn_5_is_set(void)
{
// PIO0_9 - BTN_5
	return gpio_get_data_bit(0, 9) ? 0 : 1;
}

