#include <boardinit.h>
#include <armv7m.h>
#include <ioconfig.h>
#include <sysctrl.h>
#include <leds.h>
#include <switches.h>
#include <delay.h>
#include <usbdrvrom.h>
#include <si4705.h>


static void config_pins(void)
{
	// PIO2_0 - DFS
//	iocfg_pio2_0_set_func_gpio();
//	iocfg_pio2_0_set_resistor_pull_up();
//	iocfg_pio2_0_set_hysteresis_disable();

	// PIO2_1 - FRST
//	iocfg_pio2_1_set_func_gpio();
//	iocfg_pio2_1_set_resistor_pull_up();
//	iocfg_pio2_1_set_hysteresis_disable();

	// PIO0_3 - USB_VBUS
	iocfg_pio0_3_set_func_usb_vbus();
	iocfg_pio0_3_set_resistor_pull_up();
	iocfg_pio0_3_set_hysteresis_disable();

	// PIO0_4 - SCL
//	iocfg_pio0_4_set_func_scl_i2c_standard_or_fast();

	// PIO0_5 - SDA
//	iocfg_pio0_5_set_func_sda_i2c_standard_or_fast();

	// PIO3_0 - RED LED
//	iocfg_pio3_0_set_func_gpio();
//	iocfg_pio3_0_set_resistor_pull_up();
//	iocfg_pio3_0_set_hysteresis_disable();

	// PIO3_1 - GREEN LED
//	iocfg_pio3_1_set_func_gpio();
//	iocfg_pio3_1_set_resistor_pull_up();
//	iocfg_pio3_1_set_hysteresis_disable();

	// PIO3_2 - DBG FLAG
//	iocfg_pio3_2_set_func_gpio();
//	iocfg_pio3_2_set_resistor_pull_up();
//	iocfg_pio3_2_set_hysteresis_disable();

	// PIO1_5 - DOUT
//	iocfg_pio1_5_set_func_gpio();
//	iocfg_pio1_5_set_resistor_pull_up();
//	iocfg_pio1_5_set_hysteresis_disable();

	// PIO1_6 - RCLK
//	iocfg_pio1_6_set_func_gpio();
		//void iocfg_pio1_6_set_func_ct32b0_mat0(void);
//	iocfg_pio1_6_set_resistor_pull_up();
//	iocfg_pio1_6_set_hysteresis_disable();

	// PIO1_7 - DCLK
//	iocfg_pio1_7_set_func_gpio();
		//void iocfg_pio1_7_set_func_ct32b0_mat1(void);
//	iocfg_pio1_7_set_resistor_pull_up();
//	iocfg_pio1_7_set_hysteresis_disable();
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
	runcfg_adc_power_off();
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
	//sysahbclk_i2c_enable_clock();
	sysahbclk_gpio_enable_clock();
	sysahbclk_ct16b0_enable_clock();
	sysahbclk_ct16b1_enable_clock();
	sysahbclk_ct32b0_enable_clock();
	sysahbclk_ct32b1_enable_clock();
	sysahbclk_ssp_disable_clock();
	sysahbclk_uart_disable_clock();
	sysahbclk_adc_disable_clock();
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

	usbdrvrom_init_connect();
	
	//si4705_init();
}

