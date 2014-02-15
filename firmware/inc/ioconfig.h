#ifndef IOCONFIG_H
#define IOCONFIG_H

#include <types.h>


/* PIO2_6 */
void iocfg_pio2_6_set_func_gpio(void);
void iocfg_pio2_6_set_resistor_none(void);
void iocfg_pio2_6_set_resistor_pull_down(void);
void iocfg_pio2_6_set_resistor_pull_up(void);
void iocfg_pio2_6_set_resistor_repeater(void);
void iocfg_pio2_6_set_hysteresis_disable(void);
void iocfg_pio2_6_set_hysteresis_enable(void);

/* PIO2_0 */
void iocfg_pio2_0_set_func_gpio(void);
void iocfg_pio2_0_set_func_dtr(void);
void iocfg_pio2_0_set_resistor_none(void);
void iocfg_pio2_0_set_resistor_pull_down(void);
void iocfg_pio2_0_set_resistor_pull_up(void);
void iocfg_pio2_0_set_resistor_repeater(void);
void iocfg_pio2_0_set_hysteresis_disable(void);
void iocfg_pio2_0_set_hysteresis_enable(void);

/* PIO0_0 */
void iocfg_pio0_0_set_func_reset(void);
void iocfg_pio0_0_set_func_gpio(void);
void iocfg_pio0_0_set_resistor_none(void);
void iocfg_pio0_0_set_resistor_pull_down(void);
void iocfg_pio0_0_set_resistor_pull_up(void);
void iocfg_pio0_0_set_resistor_repeater(void);
void iocfg_pio0_0_set_hysteresis_disable(void);
void iocfg_pio0_0_set_hysteresis_enable(void);

/* PIO0_1 */
void iocfg_pio0_1_set_func_gpio(void);
void iocfg_pio0_1_set_func_clkout(void);
void iocfg_pio0_1_set_func_ct32b0_mat2(void);
void iocfg_pio0_1_set_func_usb_ftoggle(void);
void iocfg_pio0_1_set_resistor_none(void);
void iocfg_pio0_1_set_resistor_pull_down(void);
void iocfg_pio0_1_set_resistor_pull_up(void);
void iocfg_pio0_1_set_resistor_repeater(void);
void iocfg_pio0_1_set_hysteresis_disable(void);
void iocfg_pio0_1_set_hysteresis_enable(void);

/* PIO1_8 */
void iocfg_pio1_8_set_func_gpio(void);
void iocfg_pio1_8_set_func_ct16b1_cap0(void);
void iocfg_pio1_8_set_resistor_none(void);
void iocfg_pio1_8_set_resistor_pull_down(void);
void iocfg_pio1_8_set_resistor_pull_up(void);
void iocfg_pio1_8_set_resistor_repeater(void);
void iocfg_pio1_8_set_hysteresis_disable(void);
void iocfg_pio1_8_set_hysteresis_enable(void);

/* PIO0_2 */
void iocfg_pio0_2_set_func_gpio(void);
void iocfg_pio0_2_set_func_ssel(void);
void iocfg_pio0_2_set_func_ct16b0_cap0(void);
void iocfg_pio0_2_set_resistor_none(void);
void iocfg_pio0_2_set_resistor_pull_down(void);
void iocfg_pio0_2_set_resistor_pull_up(void);
void iocfg_pio0_2_set_resistor_repeater(void);
void iocfg_pio0_2_set_hysteresis_disable(void);
void iocfg_pio0_2_set_hysteresis_enable(void);

/* PIO2_7 */
void iocfg_pio2_7_set_func_gpio(void);
void iocfg_pio2_7_set_resistor_none(void);
void iocfg_pio2_7_set_resistor_pull_down(void);
void iocfg_pio2_7_set_resistor_pull_up(void);
void iocfg_pio2_7_set_resistor_repeater(void);
void iocfg_pio2_7_set_hysteresis_disable(void);
void iocfg_pio2_7_set_hysteresis_enable(void);

/* PIO2_8 */
void iocfg_pio2_8_set_func_gpio(void);
void iocfg_pio2_8_set_resistor_none(void);
void iocfg_pio2_8_set_resistor_pull_down(void);
void iocfg_pio2_8_set_resistor_pull_up(void);
void iocfg_pio2_8_set_resistor_repeater(void);
void iocfg_pio2_8_set_hysteresis_disable(void);
void iocfg_pio2_8_set_hysteresis_enable(void);

/* PIO2_1 */
void iocfg_pio2_1_set_func_gpio(void);
void iocfg_pio2_1_set_func_dsr(void);
void iocfg_pio2_1_set_resistor_none(void);
void iocfg_pio2_1_set_resistor_pull_down(void);
void iocfg_pio2_1_set_resistor_pull_up(void);
void iocfg_pio2_1_set_resistor_repeater(void);
void iocfg_pio2_1_set_hysteresis_disable(void);
void iocfg_pio2_1_set_hysteresis_enable(void);

/* PIO0_3 */
void iocfg_pio0_3_set_func_gpio(void);
void iocfg_pio0_3_set_func_usb_vbus(void);
void iocfg_pio0_3_set_resistor_none(void);
void iocfg_pio0_3_set_resistor_pull_down(void);
void iocfg_pio0_3_set_resistor_pull_up(void);
void iocfg_pio0_3_set_resistor_repeater(void);
void iocfg_pio0_3_set_hysteresis_disable(void);
void iocfg_pio0_3_set_hysteresis_enable(void);

/* PIO0_4 */
void iocfg_pio0_4_set_func_gpio(void);
void iocfg_pio0_4_set_func_scl_i2c_standard_or_fast(void);
void iocfg_pio0_4_set_func_scl_i2c_fast_plus(void);

/* PIO0_5 */
void iocfg_pio0_5_set_func_gpio(void);
void iocfg_pio0_5_set_func_sda_i2c_standard_or_fast(void);
void iocfg_pio0_5_set_func_sda_i2c_fast_plus(void);

/* PIO1_9 */
void iocfg_pio1_9_set_func_gpio(void);
void iocfg_pio1_9_set_func_ct16b1_mat0(void);
void iocfg_pio1_9_set_resistor_none(void);
void iocfg_pio1_9_set_resistor_pull_down(void);
void iocfg_pio1_9_set_resistor_pull_up(void);
void iocfg_pio1_9_set_resistor_repeater(void);
void iocfg_pio1_9_set_hysteresis_disable(void);
void iocfg_pio1_9_set_hysteresis_enable(void);

/* PIO2_4 */
void iocfg_pio2_4_set_func_gpio(void);
void iocfg_pio2_4_set_resistor_none(void);
void iocfg_pio2_4_set_resistor_pull_down(void);
void iocfg_pio2_4_set_resistor_pull_up(void);
void iocfg_pio2_4_set_resistor_repeater(void);
void iocfg_pio2_4_set_hysteresis_disable(void);
void iocfg_pio2_4_set_hysteresis_enable(void);

/* PIO2_5 */
void iocfg_pio2_5_set_func_gpio(void);
void iocfg_pio2_5_set_resistor_none(void);
void iocfg_pio2_5_set_resistor_pull_down(void);
void iocfg_pio2_5_set_resistor_pull_up(void);
void iocfg_pio2_5_set_resistor_repeater(void);
void iocfg_pio2_5_set_hysteresis_disable(void);
void iocfg_pio2_5_set_hysteresis_enable(void);

/* PIO0_6 */
void iocfg_pio0_6_set_func_gpio(void);
void iocfg_pio0_6_set_func_usb_connect(void);
void iocfg_pio0_6_set_func_sck(void);
void iocfg_pio0_6_set_resistor_none(void);
void iocfg_pio0_6_set_resistor_pull_down(void);
void iocfg_pio0_6_set_resistor_pull_up(void);
void iocfg_pio0_6_set_resistor_repeater(void);
void iocfg_pio0_6_set_hysteresis_disable(void);
void iocfg_pio0_6_set_hysteresis_enable(void);

/* PIO0_7 */
void iocfg_pio0_7_set_func_gpio(void);
void iocfg_pio0_7_set_func_cts(void);
void iocfg_pio0_7_set_resistor_none(void);
void iocfg_pio0_7_set_resistor_pull_down(void);
void iocfg_pio0_7_set_resistor_pull_up(void);
void iocfg_pio0_7_set_resistor_repeater(void);
void iocfg_pio0_7_set_hysteresis_disable(void);
void iocfg_pio0_7_set_hysteresis_enable(void);

/* PIO2_9 */
void iocfg_pio2_9_set_func_gpio(void);
void iocfg_pio2_9_set_resistor_none(void);
void iocfg_pio2_9_set_resistor_pull_down(void);
void iocfg_pio2_9_set_resistor_pull_up(void);
void iocfg_pio2_9_set_resistor_repeater(void);
void iocfg_pio2_9_set_hysteresis_disable(void);
void iocfg_pio2_9_set_hysteresis_enable(void);

/* PIO2_10 */
void iocfg_pio2_10_set_func_gpio(void);
void iocfg_pio2_10_set_resistor_none(void);
void iocfg_pio2_10_set_resistor_pull_down(void);
void iocfg_pio2_10_set_resistor_pull_up(void);
void iocfg_pio2_10_set_resistor_repeater(void);
void iocfg_pio2_10_set_hysteresis_disable(void);
void iocfg_pio2_10_set_hysteresis_enable(void);

/* PIO2_2 */
void iocfg_pio2_2_set_func_gpio(void);
void iocfg_pio2_2_set_func_dcd(void);
void iocfg_pio2_2_set_resistor_none(void);
void iocfg_pio2_2_set_resistor_pull_down(void);
void iocfg_pio2_2_set_resistor_pull_up(void);
void iocfg_pio2_2_set_resistor_repeater(void);
void iocfg_pio2_2_set_hysteresis_disable(void);
void iocfg_pio2_2_set_hysteresis_enable(void);

/* PIO0_8 */
void iocfg_pio0_8_set_func_gpio(void);
void iocfg_pio0_8_set_func_miso(void);
void iocfg_pio0_8_set_func_ct16b0_mat0(void);
void iocfg_pio0_8_set_resistor_none(void);
void iocfg_pio0_8_set_resistor_pull_down(void);
void iocfg_pio0_8_set_resistor_pull_up(void);
void iocfg_pio0_8_set_resistor_repeater(void);
void iocfg_pio0_8_set_hysteresis_disable(void);
void iocfg_pio0_8_set_hysteresis_enable(void);

/* PIO0_9 */
void iocfg_pio0_9_set_func_gpio(void);
void iocfg_pio0_9_set_func_mosi(void);
void iocfg_pio0_9_set_func_ct16b0_mat1(void);
void iocfg_pio0_9_set_func_swo(void);
void iocfg_pio0_9_set_resistor_none(void);
void iocfg_pio0_9_set_resistor_pull_down(void);
void iocfg_pio0_9_set_resistor_pull_up(void);
void iocfg_pio0_9_set_resistor_repeater(void);
void iocfg_pio0_9_set_hysteresis_disable(void);
void iocfg_pio0_9_set_hysteresis_enable(void);

/* PIO0_10 */
void iocfg_pio0_10_set_func_swclk(void);
void iocfg_pio0_10_set_func_gpio(void);
void iocfg_pio0_10_set_func_sck(void);
void iocfg_pio0_10_set_func_ct16b0_mat2(void);
void iocfg_pio0_10_set_resistor_none(void);
void iocfg_pio0_10_set_resistor_pull_down(void);
void iocfg_pio0_10_set_resistor_pull_up(void);
void iocfg_pio0_10_set_resistor_repeater(void);
void iocfg_pio0_10_set_hysteresis_disable(void);
void iocfg_pio0_10_set_hysteresis_enable(void);

/* PIO1_10 */
void iocfg_pio1_10_set_func_gpio(void);
void iocfg_pio1_10_set_func_ad6(void);
void iocfg_pio1_10_set_func_ct16b1_mat1(void);
void iocfg_pio1_10_set_resistor_none(void);
void iocfg_pio1_10_set_resistor_pull_down(void);
void iocfg_pio1_10_set_resistor_pull_up(void);
void iocfg_pio1_10_set_resistor_repeater(void);
void iocfg_pio1_10_set_hysteresis_disable(void);
void iocfg_pio1_10_set_hysteresis_enable(void);

/* PIO2_11 */
void iocfg_pio2_11_set_func_gpio(void);
void iocfg_pio2_11_set_func_sck(void);
void iocfg_pio2_11_set_resistor_none(void);
void iocfg_pio2_11_set_resistor_pull_down(void);
void iocfg_pio2_11_set_resistor_pull_up(void);
void iocfg_pio2_11_set_resistor_repeater(void);
void iocfg_pio2_11_set_hysteresis_disable(void);
void iocfg_pio2_11_set_hysteresis_enable(void);

/* PIO0_11 */
void iocfg_pio0_11_set_func_r_jtag_tdi(void);
void iocfg_pio0_11_set_func_gpio(void);
void iocfg_pio0_11_set_func_ad0(void);
void iocfg_pio0_11_set_func_ct32b0_mat3(void);
void iocfg_pio0_11_set_resistor_none(void);
void iocfg_pio0_11_set_resistor_pull_down(void);
void iocfg_pio0_11_set_resistor_pull_up(void);
void iocfg_pio0_11_set_resistor_repeater(void);
void iocfg_pio0_11_set_hysteresis_disable(void);
void iocfg_pio0_11_set_hysteresis_enable(void);

/* PIO1_0 */
void iocfg_pio1_0_set_func_r_jtag_tms(void);
void iocfg_pio1_0_set_func_gpio(void);
void iocfg_pio1_0_set_func_ad1(void);
void iocfg_pio1_0_set_func_ct32b1_cap0(void);
void iocfg_pio1_0_set_resistor_none(void);
void iocfg_pio1_0_set_resistor_pull_down(void);
void iocfg_pio1_0_set_resistor_pull_up(void);
void iocfg_pio1_0_set_resistor_repeater(void);
void iocfg_pio1_0_set_hysteresis_disable(void);
void iocfg_pio1_0_set_hysteresis_enable(void);

/* PIO1_1 */
void iocfg_pio1_1_set_func_r_jtag_tdo(void);
void iocfg_pio1_1_set_func_gpio(void);
void iocfg_pio1_1_set_func_ad2(void);
void iocfg_pio1_1_set_func_ct32b1_mat0(void);
void iocfg_pio1_1_set_resistor_none(void);
void iocfg_pio1_1_set_resistor_pull_down(void);
void iocfg_pio1_1_set_resistor_pull_up(void);
void iocfg_pio1_1_set_resistor_repeater(void);
void iocfg_pio1_1_set_hysteresis_disable(void);
void iocfg_pio1_1_set_hysteresis_enable(void);

/* PIO1_2 */
void iocfg_pio1_2_set_func_r_jtag_ntrst(void);
void iocfg_pio1_2_set_func_gpio(void);
void iocfg_pio1_2_set_func_ad3(void);
void iocfg_pio1_2_set_func_ct32b1_mat1(void);
void iocfg_pio1_2_set_resistor_none(void);
void iocfg_pio1_2_set_resistor_pull_down(void);
void iocfg_pio1_2_set_resistor_pull_up(void);
void iocfg_pio1_2_set_resistor_repeater(void);
void iocfg_pio1_2_set_hysteresis_disable(void);
void iocfg_pio1_2_set_hysteresis_enable(void);

/* PIO3_0 */
void iocfg_pio3_0_set_func_gpio(void);
void iocfg_pio3_0_set_resistor_none(void);
void iocfg_pio3_0_set_resistor_pull_down(void);
void iocfg_pio3_0_set_resistor_pull_up(void);
void iocfg_pio3_0_set_resistor_repeater(void);
void iocfg_pio3_0_set_hysteresis_disable(void);
void iocfg_pio3_0_set_hysteresis_enable(void);

/* PIO3_1 */
void iocfg_pio3_1_set_func_gpio(void);
void iocfg_pio3_1_set_resistor_none(void);
void iocfg_pio3_1_set_resistor_pull_down(void);
void iocfg_pio3_1_set_resistor_pull_up(void);
void iocfg_pio3_1_set_resistor_repeater(void);
void iocfg_pio3_1_set_hysteresis_disable(void);
void iocfg_pio3_1_set_hysteresis_enable(void);

/* PIO2_3 */
void iocfg_pio2_3_set_func_gpio(void);
void iocfg_pio2_3_set_func_ri(void);
void iocfg_pio2_3_set_resistor_none(void);
void iocfg_pio2_3_set_resistor_pull_down(void);
void iocfg_pio2_3_set_resistor_pull_up(void);
void iocfg_pio2_3_set_resistor_repeater(void);
void iocfg_pio2_3_set_hysteresis_disable(void);
void iocfg_pio2_3_set_hysteresis_enable(void);

/* PIO1_3 */
void iocfg_pio1_3_set_func_swdio(void);
void iocfg_pio1_3_set_func_gpio(void);
void iocfg_pio1_3_set_func_ad4(void);
void iocfg_pio1_3_set_func_ct32b1_mat2(void);
void iocfg_pio1_3_set_resistor_none(void);
void iocfg_pio1_3_set_resistor_pull_down(void);
void iocfg_pio1_3_set_resistor_pull_up(void);
void iocfg_pio1_3_set_resistor_repeater(void);
void iocfg_pio1_3_set_hysteresis_disable(void);
void iocfg_pio1_3_set_hysteresis_enable(void);

/* PIO1_4 */
void iocfg_pio1_4_set_func_gpio(void);
void iocfg_pio1_4_set_func_ad5(void);
void iocfg_pio1_4_set_func_ct32b1_mat3(void);
void iocfg_pio1_4_set_resistor_none(void);
void iocfg_pio1_4_set_resistor_pull_down(void);
void iocfg_pio1_4_set_resistor_pull_up(void);
void iocfg_pio1_4_set_resistor_repeater(void);
void iocfg_pio1_4_set_hysteresis_disable(void);
void iocfg_pio1_4_set_hysteresis_enable(void);

/* PIO1_11 */
void iocfg_pio1_11_set_func_gpio(void);
void iocfg_pio1_11_set_func_ad7(void);
void iocfg_pio1_11_set_resistor_none(void);
void iocfg_pio1_11_set_resistor_pull_down(void);
void iocfg_pio1_11_set_resistor_pull_up(void);
void iocfg_pio1_11_set_resistor_repeater(void);
void iocfg_pio1_11_set_hysteresis_disable(void);
void iocfg_pio1_11_set_hysteresis_enable(void);

/* PIO3_2 */
void iocfg_pio3_2_set_func_gpio(void);
void iocfg_pio3_2_set_resistor_none(void);
void iocfg_pio3_2_set_resistor_pull_down(void);
void iocfg_pio3_2_set_resistor_pull_up(void);
void iocfg_pio3_2_set_resistor_repeater(void);
void iocfg_pio3_2_set_hysteresis_disable(void);
void iocfg_pio3_2_set_hysteresis_enable(void);

/* PIO1_5 */
void iocfg_pio1_5_set_func_gpio(void);
void iocfg_pio1_5_set_func_rts(void);
void iocfg_pio1_5_set_func_ct32b0_cap0(void);
void iocfg_pio1_5_set_resistor_none(void);
void iocfg_pio1_5_set_resistor_pull_down(void);
void iocfg_pio1_5_set_resistor_pull_up(void);
void iocfg_pio1_5_set_resistor_repeater(void);
void iocfg_pio1_5_set_hysteresis_disable(void);
void iocfg_pio1_5_set_hysteresis_enable(void);

/* PIO1_6 */
void iocfg_pio1_6_set_func_gpio(void);
void iocfg_pio1_6_set_func_rxd(void);
void iocfg_pio1_6_set_func_ct32b0_mat0(void);
void iocfg_pio1_6_set_resistor_none(void);
void iocfg_pio1_6_set_resistor_pull_down(void);
void iocfg_pio1_6_set_resistor_pull_up(void);
void iocfg_pio1_6_set_resistor_repeater(void);
void iocfg_pio1_6_set_hysteresis_disable(void);
void iocfg_pio1_6_set_hysteresis_enable(void);

/* PIO1_7 */
void iocfg_pio1_7_set_func_gpio(void);
void iocfg_pio1_7_set_func_txd(void);
void iocfg_pio1_7_set_func_ct32b0_mat1(void);
void iocfg_pio1_7_set_resistor_none(void);
void iocfg_pio1_7_set_resistor_pull_down(void);
void iocfg_pio1_7_set_resistor_pull_up(void);
void iocfg_pio1_7_set_resistor_repeater(void);
void iocfg_pio1_7_set_hysteresis_disable(void);
void iocfg_pio1_7_set_hysteresis_enable(void);

/* PIO3_3 */
void iocfg_pio3_3_set_func_gpio(void);
void iocfg_pio3_3_set_resistor_none(void);
void iocfg_pio3_3_set_resistor_pull_down(void);
void iocfg_pio3_3_set_resistor_pull_up(void);
void iocfg_pio3_3_set_resistor_repeater(void);
void iocfg_pio3_3_set_hysteresis_disable(void);
void iocfg_pio3_3_set_hysteresis_enable(void);


#endif

