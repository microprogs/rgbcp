#include <boardinit.h>
#include <armv7m.h>
#include <ioconfig.h>
#include <sysctrl.h>
#include <leds.h>
#include <switches.h>
#include <buttons.h>
#include <delay.h>
#include <usbdrvrom.h>


static void config_pins(void)
{
	// DBG LEDS
	// PIO3_1 - LED_DBG_R
	iocfg_pio3_1_set_func_gpio();
	iocfg_pio3_1_set_resistor_pull_up();
	iocfg_pio3_1_set_hysteresis_disable();
	// PIO3_2 - LED_DBG_G
	iocfg_pio3_2_set_func_gpio();
	iocfg_pio3_2_set_resistor_pull_up();
	iocfg_pio3_2_set_hysteresis_disable();
	// PIO3_3 - LED_DBG_B
	iocfg_pio3_3_set_func_gpio();
	iocfg_pio3_3_set_resistor_pull_up();
	iocfg_pio3_3_set_hysteresis_disable();

	// BAT LEDS
	// PIO0_10 - LED_BAT_0
	iocfg_pio0_10_set_func_gpio();
	iocfg_pio0_10_set_resistor_pull_up();
	iocfg_pio0_10_set_hysteresis_disable();
	// PIO1_9 - LED_BAT_1
	iocfg_pio1_9_set_func_gpio();
	iocfg_pio1_9_set_resistor_pull_up();
	iocfg_pio1_9_set_hysteresis_disable();
	// PIO1_10 - LED_BAT_2
	iocfg_pio1_10_set_func_gpio();
	iocfg_pio1_10_set_resistor_pull_up();
	iocfg_pio1_10_set_hysteresis_disable();
	// PIO1_11 - LED_BAT_3
	iocfg_pio1_11_set_func_gpio();
	iocfg_pio1_11_set_resistor_pull_up();
	iocfg_pio1_11_set_hysteresis_disable();

	// MAIN LEDS CHIP SELECT
	// PIO2_0 - LED_ANN_CS_0
	iocfg_pio2_0_set_func_gpio();
	iocfg_pio2_0_set_resistor_pull_up();
	iocfg_pio2_0_set_hysteresis_disable();
	// PIO2_1 - LED_ANN_CS_1
	iocfg_pio2_1_set_func_gpio();
	iocfg_pio2_1_set_resistor_pull_up();
	iocfg_pio2_1_set_hysteresis_disable();
	// PIO2_2 - LED_ANN_CS_2
	iocfg_pio2_2_set_func_gpio();
	iocfg_pio2_2_set_resistor_pull_up();
	iocfg_pio2_2_set_hysteresis_disable();
	// PIO2_3 - LED_ANN_CS_3
	iocfg_pio2_3_set_func_gpio();
	iocfg_pio2_3_set_resistor_pull_up();
	iocfg_pio2_3_set_hysteresis_disable();
	// PIO2_4 - LED_ANN_CS_4
	iocfg_pio2_4_set_func_gpio();
	iocfg_pio2_4_set_resistor_pull_up();
	iocfg_pio2_4_set_hysteresis_disable();
	// PIO2_5 - LED_ANN_CS_5
	iocfg_pio2_5_set_func_gpio();
	iocfg_pio2_5_set_resistor_pull_up();
	iocfg_pio2_5_set_hysteresis_disable();
	// PIO2_6 - LED_ANN_CS_6
	iocfg_pio2_6_set_func_gpio();
	iocfg_pio2_6_set_resistor_pull_up();
	iocfg_pio2_6_set_hysteresis_disable();
	// PIO2_7 - LED_ANN_CS_7
	iocfg_pio2_7_set_func_gpio();
	iocfg_pio2_7_set_resistor_pull_up();
	iocfg_pio2_7_set_hysteresis_disable();
	// PIO2_8 - LED_ANN_CS_8
	iocfg_pio2_8_set_func_gpio();
	iocfg_pio2_8_set_resistor_pull_up();
	iocfg_pio2_8_set_hysteresis_disable();
	// PIO2_9 - LED_ANN_CS_9
	iocfg_pio2_9_set_func_gpio();
	iocfg_pio2_9_set_resistor_pull_up();
	iocfg_pio2_9_set_hysteresis_disable();

	// MAIN LEDS
	// PIO1_0 - LED_ANN_1B
	iocfg_pio1_0_set_func_gpio();
	iocfg_pio1_0_set_resistor_pull_up();
	iocfg_pio1_0_set_hysteresis_disable();
	// PIO1_1 - LED_ANN_1G
	iocfg_pio1_1_set_func_gpio();
	iocfg_pio1_1_set_resistor_pull_up();
	iocfg_pio1_1_set_hysteresis_disable();
	// PIO1_2 - LED_ANN_1R
	iocfg_pio1_2_set_func_gpio();
	iocfg_pio1_2_set_resistor_pull_up();
	iocfg_pio1_2_set_hysteresis_disable();
	// PIO1_3 - LED_ANN_2B
	iocfg_pio1_3_set_func_gpio();
	iocfg_pio1_3_set_resistor_pull_up();
	iocfg_pio1_3_set_hysteresis_disable();
	// PIO1_4 - LED_ANN_2G
	iocfg_pio1_4_set_func_gpio();
	iocfg_pio1_4_set_resistor_pull_up();
	iocfg_pio1_4_set_hysteresis_disable();
	// PIO1_5 - LED_ANN_2R
	iocfg_pio1_5_set_func_gpio();
	iocfg_pio1_5_set_resistor_pull_up();
	iocfg_pio1_5_set_hysteresis_disable();
	// PIO1_6 - LED_ANN_3B
	iocfg_pio1_6_set_func_gpio();
	iocfg_pio1_6_set_resistor_pull_up();
	iocfg_pio1_6_set_hysteresis_disable();
	// PIO1_7 - LED_ANN_3G
	iocfg_pio1_7_set_func_gpio();
	iocfg_pio1_7_set_resistor_pull_up();
	iocfg_pio1_7_set_hysteresis_disable();
	// PIO1_8 - LED_ANN_3R
	iocfg_pio1_8_set_func_gpio();
	iocfg_pio1_8_set_resistor_pull_up();
	iocfg_pio1_8_set_hysteresis_disable();

	// SWITCHES
	// PIO3_0 - DBG_FLAG
	iocfg_pio3_0_set_func_gpio();
	iocfg_pio3_0_set_resistor_pull_up();
	iocfg_pio3_0_set_hysteresis_disable();

	// BUTTONS
	// PIO2_10 - BTN_0
	iocfg_pio2_10_set_func_gpio();
	iocfg_pio2_10_set_resistor_pull_up();
	iocfg_pio2_10_set_hysteresis_disable();
	// PIO0_5 - BTN_1
	iocfg_pio0_5_set_func_gpio();
	// PIO2_11 - BTN_2
	iocfg_pio2_11_set_func_gpio();
	iocfg_pio2_11_set_resistor_pull_up();
	iocfg_pio2_11_set_hysteresis_disable();
	// PIO0_7 - BTN_3
	iocfg_pio0_7_set_func_gpio();
	iocfg_pio0_7_set_resistor_pull_up();
	iocfg_pio0_7_set_hysteresis_disable();
	// PIO0_8 - BTN_4
	iocfg_pio0_8_set_func_gpio();
	iocfg_pio0_8_set_resistor_pull_up();
	iocfg_pio0_8_set_hysteresis_disable();
	// PIO0_9 - BTN_5
	iocfg_pio0_9_set_func_gpio();
	iocfg_pio0_9_set_resistor_pull_up();
	iocfg_pio0_9_set_hysteresis_disable();

	// ADC BAT
	// PIO0_11 - AD0
	iocfg_pio0_11_set_func_ad0();
	iocfg_pio0_11_set_resistor_none();
	iocfg_pio0_11_set_hysteresis_disable();

	// USB
	// PIO0_3 - USB_VBUS
	iocfg_pio0_3_set_func_usb_vbus();
	iocfg_pio0_3_set_resistor_pull_up();
	iocfg_pio0_3_set_hysteresis_disable();
}

static void config_system(void)
{
	// memory remap
	remap_vectors_to_flash();

	// power enable
	runcfg_irc_out_power_on();
	runcfg_irc_power_on();
	runcfg_flash_power_on();
	runcfg_bod_power_off();
	runcfg_adc_power_on();
	runcfg_sysosc_power_off();
	runcfg_wdtosc_power_off();
	runcfg_syspll_power_off();
	runcfg_usbpll_power_off();
	runcfg_usbphy_power_on();

	// clock enable
	sysahbclk_set_divider(1);
	sysahbclk_ahb2apb_bridge_enable_clock();
	sysahbclk_rom_enable_clock();
	sysahbclk_ram_enable_clock();
	sysahbclk_flashreg_enable_clock();
	sysahbclk_flasharray_enable_clock();
	sysahbclk_gpio_enable_clock();
	sysahbclk_ct16b0_enable_clock();
	sysahbclk_ct16b1_enable_clock();
	sysahbclk_ct32b0_enable_clock();
	sysahbclk_ct32b1_enable_clock();
	sysahbclk_ssp_disable_clock();
	sysahbclk_uart_disable_clock();
	sysahbclk_adc_enable_clock();
	sysahbclk_usbreg_enable_clock();
	sysahbclk_wdt_disable_clock();
	sysahbclk_iocon_enable_clock();

	// sysosc enable
	sysosc_enable_1MHz_20MHz();
	runcfg_sysosc_power_on();
	delay_ticks(500);

	// syspll enable
	syspll_set_clock_source_sysosc();
	delay_ticks(500);

	syspll_set_dividers_12MHz_to_72Mhz();

	runcfg_syspll_power_on();
	while (!syspll_is_locked())
		no_operation();

	// mainclk enable
	mainclk_set_clock_source_syspll_out();

	// usbpll enable
	usbpll_set_clock_source_sysosc();
	delay_ticks(500);

	usbpll_set_dividers_12MHz_to_48Mhz();

	runcfg_usbpll_power_on();
	while (!usbpll_is_locked())
		no_operation();

	// usbclk enable
	usbclk_set_divider(1);
	delay_ticks(500);
	usbclk_set_clock_source_usbpll_out();
}

void board_init(void)
{
	config_system();
	config_pins();

	init_leds();
	init_switches();
	init_buttons();

	usbdrvrom_init_connect();
}

