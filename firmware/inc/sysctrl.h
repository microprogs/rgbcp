#ifndef SYSCTRL_H
#define SYSCTRL_H

#include <types.h>

void remap_vectors_to_boot_rom(void);
void remap_vectors_to_sram(void);
void remap_vectors_to_flash(void);

void ssp_reset_enabled(void);
void ssp_reset_disabled(void);
void i2c_reset_enabled(void);
void i2c_reset_disabled(void);

void syspll_set_first_divider_1(void);
void syspll_set_first_divider_2(void);
void syspll_set_first_divider_3(void);
void syspll_set_first_divider_4(void);
void syspll_set_first_divider_5(void);
void syspll_set_first_divider_6(void);
void syspll_set_first_divider_7(void);
void syspll_set_first_divider_8(void);
void syspll_set_first_divider_9(void);
void syspll_set_first_divider_10(void);
void syspll_set_first_divider_11(void);
void syspll_set_first_divider_12(void);
void syspll_set_first_divider_13(void);
void syspll_set_first_divider_14(void);
void syspll_set_first_divider_15(void);
void syspll_set_first_divider_16(void);
void syspll_set_first_divider_17(void);
void syspll_set_first_divider_18(void);
void syspll_set_first_divider_19(void);
void syspll_set_first_divider_20(void);
void syspll_set_first_divider_21(void);
void syspll_set_first_divider_22(void);
void syspll_set_first_divider_23(void);
void syspll_set_first_divider_24(void);
void syspll_set_first_divider_25(void);
void syspll_set_first_divider_26(void);
void syspll_set_first_divider_27(void);
void syspll_set_first_divider_28(void);
void syspll_set_first_divider_29(void);
void syspll_set_first_divider_30(void);
void syspll_set_first_divider_31(void);
void syspll_set_first_divider_32(void);
void syspll_set_second_diviver_2(void);
void syspll_set_second_diviver_4(void);
void syspll_set_second_diviver_8(void);
void syspll_set_second_diviver_16(void);

void syspll_set_dividers_12MHz_to_12Mhz(void);
void syspll_set_dividers_12MHz_to_24Mhz(void);
void syspll_set_dividers_12MHz_to_36Mhz(void);
void syspll_set_dividers_12MHz_to_48Mhz(void);
void syspll_set_dividers_12MHz_to_72Mhz(void);


uint32_t syspll_is_locked(void);


void usbpll_set_first_divider_1(void);
void usbpll_set_first_divider_2(void);
void usbpll_set_first_divider_3(void);
void usbpll_set_first_divider_4(void);
void usbpll_set_first_divider_5(void);
void usbpll_set_first_divider_6(void);
void usbpll_set_first_divider_7(void);
void usbpll_set_first_divider_8(void);
void usbpll_set_first_divider_9(void);
void usbpll_set_first_divider_10(void);
void usbpll_set_first_divider_11(void);
void usbpll_set_first_divider_12(void);
void usbpll_set_first_divider_13(void);
void usbpll_set_first_divider_14(void);
void usbpll_set_first_divider_15(void);
void usbpll_set_first_divider_16(void);
void usbpll_set_first_divider_17(void);
void usbpll_set_first_divider_18(void);
void usbpll_set_first_divider_19(void);
void usbpll_set_first_divider_20(void);
void usbpll_set_first_divider_21(void);
void usbpll_set_first_divider_22(void);
void usbpll_set_first_divider_23(void);
void usbpll_set_first_divider_24(void);
void usbpll_set_first_divider_25(void);
void usbpll_set_first_divider_26(void);
void usbpll_set_first_divider_27(void);
void usbpll_set_first_divider_28(void);
void usbpll_set_first_divider_29(void);
void usbpll_set_first_divider_30(void);
void usbpll_set_first_divider_31(void);
void usbpll_set_first_divider_32(void);
void usbpll_set_second_diviver_2(void);
void usbpll_set_second_diviver_4(void);
void usbpll_set_second_diviver_8(void);
void usbpll_set_second_diviver_16(void);

void usbpll_set_dividers_12MHz_to_48Mhz(void);

uint32_t usbpll_is_locked(void);


void sysosc_disable(void);
void sysosc_enable_1MHz_20MHz(void);
void sysosc_enable_15MHz_25MHz(void);

void syspll_set_clock_source_irc(void);
void syspll_set_clock_source_sysosc(void);

void usbpll_set_clock_source_irc(void);
void usbpll_set_clock_source_sysosc(void);

void mainclk_set_clock_source_irc(void);
void mainclk_set_clock_source_syspll_in(void);
void mainclk_set_clock_source_wdtosc(void);
void mainclk_set_clock_source_syspll_out(void);

void sysahbclk_disable(void);
void sysahbclk_set_divider(uint32_t d);

void sysahbclk_ahb2apb_bridge_enable_clock(void);
void sysahbclk_rom_disable_clock(void);
void sysahbclk_rom_enable_clock(void);
void sysahbclk_ram_disable_clock(void);
void sysahbclk_ram_enable_clock(void);
void sysahbclk_flashreg_disable_clock(void);
void sysahbclk_flashreg_enable_clock(void);
void sysahbclk_flasharray_disable_clock(void);
void sysahbclk_flasharray_enable_clock(void);
void sysahbclk_i2c_disable_clock(void);
void sysahbclk_i2c_enable_clock(void);
void sysahbclk_gpio_disable_clock(void);
void sysahbclk_gpio_enable_clock(void);
void sysahbclk_ct16b0_disable_clock(void);
void sysahbclk_ct16b0_enable_clock(void);
void sysahbclk_ct16b1_disable_clock(void);
void sysahbclk_ct16b1_enable_clock(void);
void sysahbclk_ct32b0_disable_clock(void);
void sysahbclk_ct32b0_enable_clock(void);
void sysahbclk_ct32b1_disable_clock(void);
void sysahbclk_ct32b1_enable_clock(void);
void sysahbclk_ssp_disable_clock(void);
void sysahbclk_ssp_enable_clock(void);
void sysahbclk_uart_disable_clock(void);
void sysahbclk_uart_enable_clock(void);
void sysahbclk_adc_disable_clock(void);
void sysahbclk_adc_enable_clock(void);
void sysahbclk_usbreg_disable_clock(void);
void sysahbclk_usbreg_enable_clock(void);
void sysahbclk_wdt_disable_clock(void);
void sysahbclk_wdt_enable_clock(void);
void sysahbclk_iocon_disable_clock(void);
void sysahbclk_iocon_enable_clock(void);

void usbclk_set_clock_source_usbpll_out(void);
void usbclk_set_clock_source_mainclk(void);

void usbclk_disable(void);
void usbclk_set_divider(uint32_t d);

void runcfg_irc_out_power_on(void);
void runcfg_irc_out_power_off(void);
void runcfg_irc_power_on(void);
void runcfg_irc_power_off(void);
void runcfg_flash_power_on(void);
void runcfg_flash_power_off(void);
void runcfg_bod_power_on(void);
void runcfg_bod_power_off(void);
void runcfg_adc_power_on(void);
void runcfg_adc_power_off(void);
void runcfg_sysosc_power_on(void);
void runcfg_sysosc_power_off(void);
void runcfg_wdtosc_power_on(void);
void runcfg_wdtosc_power_off(void);
void runcfg_syspll_power_on(void);
void runcfg_syspll_power_off(void);
void runcfg_usbpll_power_on(void);
void runcfg_usbpll_power_off(void);
void runcfg_usbphy_power_on(void);
void runcfg_usbphy_power_off(void);


#endif

