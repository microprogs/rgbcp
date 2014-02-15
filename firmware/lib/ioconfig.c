#include <ioconfig.h>
#include <bits.h>
#include <mmap.h>


/*
The I/O configuration registers control the electrical characteristics of the pins. 
The following characteristics are configurable:
  * pin function
  * internal pull-up/pull-down or Repeater mode function
  * hysteresis
  * analog input or digital mode for pins hosting the ADC inputs
  * I2C mode for pins hosting the I2C-bus function

The IOCON registers control the function (GPIO or peripheral function), the input mode,
and the hysteresis of all PIO pins. In addition, the I2C-bus pins can be configured for
different I2C-bus modes. If a pin is used as input pin for the ADC, an analog input mode
can be selected.

The FUNC bits in the IOCON registers can be set to GPIO (FUNC = 000) or to a
peripheral function. If the pins are GPIO pins, the GPIOnDIR registers determine whether
the pin is configured as an input or output (see Table 142). For any peripheral function, the
pin direction is controlled automatically depending on the pin’s functionality. The
GPIOnDIR registers have no effect for peripheral functions.

The MODE bits in the IOCON register allow the selection of on-chip pull-up or pull-down
resistors for each pin or select the repeater mode.
The possible on-chip resistor configurations are pull-up enabled, pull-down enabled, or no
pull-up/pull-down. The default value is pull-up enabled.
The repeater mode enables the pull-up resistor if the pin is at a logic HIGH and enables
the pull-down resistor if the pin is at a logic LOW. This causes the pin to retain its last
known state if it is configured as an input and is not driven externally. The state retention is
not applicable to the Deep power-down mode. Repeater mode may typically be used to
prevent a pin from floating (and potentially using significant power if it floats to an
indeterminate state) if it is temporarily not driven.

The input buffer for digital functions can be configured with hysteresis or as plain buffer
through the IOCON registers (see the LPC1311/13/43/44 data sheet for details).
If the external pad supply voltage VDD is between 2.5 V and 3.6 V, the hysteresis buffer
can be enabled or disabled. If VDD is below 2.5 V, the hysteresis buffer must be disabled
to use the pin in input mode.

In A/D-mode, the digital receiver is disconnected to obtain an accurate input voltage for
analog-to-digital conversions. This mode is available in those IOCON registers that
control pins which can function as ADC inputs. If A/D mode is selected, Hysteresis and
Pin mode settings have no effect.

If the I2C function is selected by the FUNC bits of registers IOCON_PIO0_4 (Table 102)
and IOCON_PIO0_5 (Table 103), then the I2C-bus pins can be configured for different
I2C-modes:
• Standard mode/Fast-mode I2C with input glitch filter (this includes an open-drain
output according to the I2C-bus specification).
• Fast-mode Plus with input glitch filter (this includes an open-drain output according to
the I2C-bus specification). In this mode, the pins function as high-current sinks.
• Standard, open-drain I/O functionality without input filter.
Remark: Either Standard mode/Fast-mode I2C or Standard I/O functionality should be
selected if the pin is used as GPIO pin.

*/






/* PIO2_6 */
void iocfg_pio2_6_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_6), 0b111);
}

void iocfg_pio2_6_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_6), 0b11000);
}

void iocfg_pio2_6_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_6), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_6),  0b01000);
}

void iocfg_pio2_6_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_6), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_6),  0b10000);
}

void iocfg_pio2_6_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_6), 0b11000);
}

void iocfg_pio2_6_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_6), 0b100000);
}

void iocfg_pio2_6_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_6), 0b100000);
}



/* PIO2_0 */
void iocfg_pio2_0_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_0), 0b111);
}

void iocfg_pio2_0_set_func_dtr(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_0), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_0),  0b001);
}

void iocfg_pio2_0_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_0), 0b11000);
}

void iocfg_pio2_0_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_0),  0b01000);
}

void iocfg_pio2_0_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_0),  0b10000);
}

void iocfg_pio2_0_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_0), 0b11000);
}

void iocfg_pio2_0_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_0), 0b100000);
}

void iocfg_pio2_0_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_0),  0b100000);
}


/* PIO0_0 */
void iocfg_pio0_0_set_func_reset(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.reset_pio0_0), 0b111);
}

void iocfg_pio0_0_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.reset_pio0_0), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.reset_pio0_0),  0b001);
}

void iocfg_pio0_0_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.reset_pio0_0), 0b11000);
}

void iocfg_pio0_0_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.reset_pio0_0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.reset_pio0_0),  0b01000);
}

void iocfg_pio0_0_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.reset_pio0_0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.reset_pio0_0),  0b10000);
}

void iocfg_pio0_0_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.reset_pio0_0),  0b11000);
}

void iocfg_pio0_0_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.reset_pio0_0), 0b100000);
}

void iocfg_pio0_0_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.reset_pio0_0),  0b100000);
}


/* PIO0_1 */
void iocfg_pio0_1_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b111);
}

void iocfg_pio0_1_set_func_clkout(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_1_bootld),  0b001);
}

void iocfg_pio0_1_set_func_ct32b0_mat2(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_1_bootld),  0b010);
}

void iocfg_pio0_1_set_func_usb_ftoggle(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_1_bootld),  0b011);
}

void iocfg_pio0_1_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b11000);
}

void iocfg_pio0_1_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_1_bootld),  0b01000);
}

void iocfg_pio0_1_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_1_bootld),  0b10000);
}

void iocfg_pio0_1_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_1_bootld), 0b11000);
}

void iocfg_pio0_1_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_1_bootld), 0b100000);
}

void iocfg_pio0_1_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_1_bootld),  0b100000);
}


/* PIO1_8 */
void iocfg_pio1_8_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_8), 0b111);
}

void iocfg_pio1_8_set_func_ct16b1_cap0(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_8), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_8),  0b001);
}

void iocfg_pio1_8_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_8), 0b11000);
}

void iocfg_pio1_8_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_8), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_8),  0b01000);
}

void iocfg_pio1_8_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_8), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_8),  0b10000);
}

void iocfg_pio1_8_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_8), 0b11000);
}

void iocfg_pio1_8_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_8), 0b100000);
}

void iocfg_pio1_8_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_8),  0b100000);
}


/* PIO0_2 */
void iocfg_pio0_2_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_2_ssel), 0b111);
}

void iocfg_pio0_2_set_func_ssel(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_2_ssel), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_2_ssel),  0b001);
}

void iocfg_pio0_2_set_func_ct16b0_cap0(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_2_ssel), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_2_ssel),  0b010);
}

void iocfg_pio0_2_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_2_ssel), 0b11000);
}

void iocfg_pio0_2_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_2_ssel), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_2_ssel),  0b01000);
}

void iocfg_pio0_2_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_2_ssel), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_2_ssel),  0b10000);
}

void iocfg_pio0_2_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_2_ssel), 0b11000);
}

void iocfg_pio0_2_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_2_ssel), 0b100000);
}

void iocfg_pio0_2_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_2_ssel),  0b100000);
}


/* PIO2_7 */
void iocfg_pio2_7_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_7), 0b111);
}

void iocfg_pio2_7_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_7), 0b11000);
}

void iocfg_pio2_7_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_7), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_7),  0b01000);
}

void iocfg_pio2_7_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_7), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_7),  0b10000);
}

void iocfg_pio2_7_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_7), 0b11000);
}

void iocfg_pio2_7_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_7), 0b100000);
}

void iocfg_pio2_7_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_7),  0b100000);
}


/* PIO2_8 */
void iocfg_pio2_8_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_8), 0b111);
}

void iocfg_pio2_8_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_8), 0b11000);
}

void iocfg_pio2_8_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_8), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_8),  0b01000);
}

void iocfg_pio2_8_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_8), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_8),  0b10000);
}

void iocfg_pio2_8_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_8), 0b11000);
}

void iocfg_pio2_8_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_8), 0b100000);
}

void iocfg_pio2_8_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_8),  0b100000);
}


/* PIO2_1 */
void iocfg_pio2_1_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_1), 0b111);
}

void iocfg_pio2_1_set_func_dsr(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_1), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_1),  0b001);
}

void iocfg_pio2_1_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_1), 0b11000);
}

void iocfg_pio2_1_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_1), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_1),  0b01000);
}

void iocfg_pio2_1_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_1), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_1),  0b10000);
}

void iocfg_pio2_1_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_1), 0b11000);
}

void iocfg_pio2_1_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_1), 0b100000);
}

void iocfg_pio2_1_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_1),  0b100000);
}


/* PIO0_3 */
void iocfg_pio0_3_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_3_usb_vbus), 0b111);
}

void iocfg_pio0_3_set_func_usb_vbus(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_3_usb_vbus), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_3_usb_vbus),  0b001);
}

void iocfg_pio0_3_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_3_usb_vbus), 0b11000);
}

void iocfg_pio0_3_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_3_usb_vbus), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_3_usb_vbus),  0b01000);
}

void iocfg_pio0_3_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_3_usb_vbus), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_3_usb_vbus),  0b10000);
}

void iocfg_pio0_3_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_3_usb_vbus), 0b11000);
}

void iocfg_pio0_3_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_3_usb_vbus), 0b100000);
}

void iocfg_pio0_3_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_3_usb_vbus),  0b100000);
}


/* PIO0_4 */
void iocfg_pio0_4_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_4_scl), 0b111);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_4_scl), 0b1100000000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_4_scl),  0b0100000000);
}

void iocfg_pio0_4_set_func_scl_i2c_standard_or_fast(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_4_scl), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_4_scl),  0b001);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_4_scl), 0b1100000000);
}

void iocfg_pio0_4_set_func_scl_i2c_fast_plus(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_4_scl), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_4_scl),  0b001);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_4_scl), 0b1100000000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_4_scl),  0b1000000000);
}


/* PIO0_5 */
void iocfg_pio0_5_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_5_sda), 0b111);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_5_sda), 0b1100000000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_5_sda),  0b0100000000);
}

void iocfg_pio0_5_set_func_sda_i2c_standard_or_fast(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_5_sda), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_5_sda),  0b001);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_5_sda), 0b1100000000);
}

void iocfg_pio0_5_set_func_sda_i2c_fast_plus(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_5_sda), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_5_sda),  0b001);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_5_sda), 0b1100000000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_5_sda),  0b1000000000);
}


/* PIO1_9 */
void iocfg_pio1_9_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_9), 0b111);
}

void iocfg_pio1_9_set_func_ct16b1_mat0(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_9), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_9),  0b001);
}

void iocfg_pio1_9_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_9), 0b11000);
}

void iocfg_pio1_9_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_9), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_9),  0b01000);
}

void iocfg_pio1_9_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_9), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_9),  0b10000);
}

void iocfg_pio1_9_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_9),  0b11000);
}

void iocfg_pio1_9_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_9), 0b100000);
}

void iocfg_pio1_9_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_9),  0b100000);
}


/* PIO2_4 */
void iocfg_pio2_4_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_4), 0b111);
}

void iocfg_pio2_4_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_4), 0b11000);
}

void iocfg_pio2_4_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_4), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_4),  0b01000);
}

void iocfg_pio2_4_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_4), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_4),  0b10000);
}

void iocfg_pio2_4_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_4), 0b11000);
}

void iocfg_pio2_4_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_4), 0b100000);
}

void iocfg_pio2_4_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_4),  0b100000);
}


/* PIO2_5 */
void iocfg_pio2_5_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_5), 0b111);
}

void iocfg_pio2_5_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_5), 0b11000);
}

void iocfg_pio2_5_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_5), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_5),  0b01000);
}

void iocfg_pio2_5_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_5), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_5),  0b10000);
}

void iocfg_pio2_5_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_5),  0b11000);
}

void iocfg_pio2_5_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_5), 0b100000);
}

void iocfg_pio2_5_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_5),  0b100000);
}


/* PIO0_6 */
void iocfg_pio0_6_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_6_sck), 0b111);
}

void iocfg_pio0_6_set_func_usb_connect(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_6_sck), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_6_sck),  0b001);
}

void iocfg_pio0_6_set_func_sck(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_6_sck), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_6_sck),  0b010);

	set_all_bits_zero(&(mmap->apb_ioconfig.sckloc),     0b11);
	set_all_bits_one(&(mmap->apb_ioconfig.sckloc),      0b10);
}

void iocfg_pio0_6_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_6_sck), 0b11000);
}

void iocfg_pio0_6_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_6_sck), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_6_sck),  0b01000);
}

void iocfg_pio0_6_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_6_sck), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_6_sck),  0b10000);
}

void iocfg_pio0_6_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_6_sck),  0b11000);
}

void iocfg_pio0_6_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_6_sck), 0b100000);
}

void iocfg_pio0_6_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_6_sck),  0b100000);
}


/* PIO0_7 */
void iocfg_pio0_7_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_7), 0b111);
}

void iocfg_pio0_7_set_func_cts(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_7), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_7),  0b001);
}

void iocfg_pio0_7_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_7), 0b11000);
}

void iocfg_pio0_7_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_7), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_7),  0b01000);
}

void iocfg_pio0_7_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_7), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_7),  0b10000);
}

void iocfg_pio0_7_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_7),  0b11000);
}

void iocfg_pio0_7_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_7), 0b100000);
}

void iocfg_pio0_7_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_7),  0b100000);
}


/* PIO2_9 */
void iocfg_pio2_9_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_9), 0b111);
}

void iocfg_pio2_9_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_9), 0b11000);
}

void iocfg_pio2_9_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_9), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_9),  0b01000);
}

void iocfg_pio2_9_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_9), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_9),  0b10000);
}

void iocfg_pio2_9_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_9),  0b11000);
}

void iocfg_pio2_9_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_9), 0b100000);
}

void iocfg_pio2_9_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_9),  0b100000);
}


/* PIO2_10 */
void iocfg_pio2_10_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_10), 0b111);
}

void iocfg_pio2_10_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_10), 0b11000);
}

void iocfg_pio2_10_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_10), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_10),  0b01000);
}

void iocfg_pio2_10_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_10), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_10),  0b10000);
}

void iocfg_pio2_10_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_10),  0b11000);
}

void iocfg_pio2_10_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_10), 0b100000);
}

void iocfg_pio2_10_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_10),  0b100000);
}


/* PIO2_2 */
void iocfg_pio2_2_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_2), 0b111);
}

void iocfg_pio2_2_set_func_dcd(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_2), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_2),  0b001);
}

void iocfg_pio2_2_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_2), 0b11000);
}

void iocfg_pio2_2_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_2), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_2),  0b01000);
}

void iocfg_pio2_2_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_2), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_2),  0b10000);
}

void iocfg_pio2_2_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_2),  0b11000);
}

void iocfg_pio2_2_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_2), 0b100000);
}

void iocfg_pio2_2_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_2),  0b100000);
}


/* PIO0_8 */
void iocfg_pio0_8_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_8_miso), 0b111);
}

void iocfg_pio0_8_set_func_miso(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_8_miso), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_8_miso),  0b001);
}

void iocfg_pio0_8_set_func_ct16b0_mat0(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_8_miso), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_8_miso),  0b010);
}

void iocfg_pio0_8_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_8_miso), 0b11000);
}

void iocfg_pio0_8_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_8_miso), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_8_miso),  0b01000);
}

void iocfg_pio0_8_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_8_miso), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_8_miso),  0b10000);
}

void iocfg_pio0_8_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_8_miso),  0b11000);
}

void iocfg_pio0_8_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_8_miso), 0b100000);
}

void iocfg_pio0_8_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_8_miso),  0b100000);
}


/* PIO0_9 */
void iocfg_pio0_9_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b111);
}

void iocfg_pio0_9_set_func_mosi(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_9_mosi_swo),  0b001);
}

void iocfg_pio0_9_set_func_ct16b0_mat1(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_9_mosi_swo),  0b010);
}

void iocfg_pio0_9_set_func_swo(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_9_mosi_swo),  0b011);
}

void iocfg_pio0_9_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b11000);
}

void iocfg_pio0_9_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_9_mosi_swo),  0b01000);
}

void iocfg_pio0_9_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_9_mosi_swo),  0b10000);
}

void iocfg_pio0_9_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_9_mosi_swo),  0b11000);
}

void iocfg_pio0_9_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio0_9_mosi_swo), 0b100000);
}

void iocfg_pio0_9_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio0_9_mosi_swo),  0b100000);
}


/* PIO0_10 */
void iocfg_pio0_10_set_func_swclk(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b111);
}

void iocfg_pio0_10_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck),  0b001);
}

void iocfg_pio0_10_set_func_sck(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck),  0b010);

	set_all_bits_zero(&(mmap->apb_ioconfig.sckloc), 0b11);
}

void iocfg_pio0_10_set_func_ct16b0_mat2(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck),  0b011);
}

void iocfg_pio0_10_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b11000);
}

void iocfg_pio0_10_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck),  0b01000);
}

void iocfg_pio0_10_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck),  0b10000);
}

void iocfg_pio0_10_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck),  0b11000);
}

void iocfg_pio0_10_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck), 0b100000);
}

void iocfg_pio0_10_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.jtag_tck_swclk_pio0_10_sck),  0b100000);
}


/* PIO1_10 */
void iocfg_pio1_10_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b111);
}

void iocfg_pio1_10_set_func_ad6(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b001);
}

void iocfg_pio1_10_set_func_ct16b1_mat1(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b010);
}

void iocfg_pio1_10_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b11000);
}

void iocfg_pio1_10_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b01000);
}

void iocfg_pio1_10_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b10000);
}

void iocfg_pio1_10_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b11000);
}

void iocfg_pio1_10_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_10_ad6), 0b100000);
}

void iocfg_pio1_10_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_10_ad6),  0b100000);
}


/* PIO2_11 */
void iocfg_pio2_11_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_11_sck), 0b111);
}

void iocfg_pio2_11_set_func_sck(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_11_sck), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_11_sck),  0b001);

	set_all_bits_zero(&(mmap->apb_ioconfig.sckloc), 0b11);
	set_all_bits_one(&(mmap->apb_ioconfig.sckloc),  0b01);
}

void iocfg_pio2_11_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_11_sck), 0b11000);
}

void iocfg_pio2_11_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_11_sck), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_11_sck),  0b01000);
}

void iocfg_pio2_11_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_11_sck), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_11_sck),  0b10000);
}

void iocfg_pio2_11_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_11_sck),  0b11000);
}

void iocfg_pio2_11_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_11_sck), 0b100000);
}

void iocfg_pio2_11_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_11_sck),  0b100000);
}


/* PIO0_11 */
void iocfg_pio0_11_set_func_r_jtag_tdi(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b111);
}

void iocfg_pio0_11_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b001);
}

void iocfg_pio0_11_set_func_ad0(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b010);
}

void iocfg_pio0_11_set_func_ct32b0_mat3(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b011);
}

void iocfg_pio0_11_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b11000);
}

void iocfg_pio0_11_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b01000);
}

void iocfg_pio0_11_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b10000);
}

void iocfg_pio0_11_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b11000);
}

void iocfg_pio0_11_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0), 0b100000);
}

void iocfg_pio0_11_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdi_pio0_11_ad0),  0b100000);
}


/* PIO1_0 */
void iocfg_pio1_0_set_func_r_jtag_tms(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b111);
}

void iocfg_pio1_0_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b001);
}

void iocfg_pio1_0_set_func_ad1(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b010);
}

void iocfg_pio1_0_set_func_ct32b1_cap0(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b011);
}

void iocfg_pio1_0_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b11000);
}

void iocfg_pio1_0_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b01000);
}

void iocfg_pio1_0_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b10000);
}

void iocfg_pio1_0_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b11000);
}

void iocfg_pio1_0_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1), 0b100000);
}

void iocfg_pio1_0_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tms_pio1_0_ad1),  0b100000);
}


/* PIO1_1 */
void iocfg_pio1_1_set_func_r_jtag_tdo(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b111);
}

void iocfg_pio1_1_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b001);
}

void iocfg_pio1_1_set_func_ad2(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b010);
}

void iocfg_pio1_1_set_func_ct32b1_mat0(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b011);
}

void iocfg_pio1_1_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b11000);
}

void iocfg_pio1_1_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b01000);
}

void iocfg_pio1_1_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b10000);
}

void iocfg_pio1_1_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b11000);
}

void iocfg_pio1_1_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2), 0b100000);
}

void iocfg_pio1_1_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_tdo_pio1_1_ad2),  0b100000);
}


/* PIO1_2 */
void iocfg_pio1_2_set_func_r_jtag_ntrst(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b111);
}

void iocfg_pio1_2_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b001);
}

void iocfg_pio1_2_set_func_ad3(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b010);
}

void iocfg_pio1_2_set_func_ct32b1_mat1(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b011);
}

void iocfg_pio1_2_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b11000);
}

void iocfg_pio1_2_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b01000);
}

void iocfg_pio1_2_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b10000);
}

void iocfg_pio1_2_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b11000);
}

void iocfg_pio1_2_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3), 0b100000);
}

void iocfg_pio1_2_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.r_jtag_ntrst_pio1_2_ad3),  0b100000);
}


/* PIO3_0 */
void iocfg_pio3_0_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_0), 0b111);
}

void iocfg_pio3_0_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_0), 0b11000);
}

void iocfg_pio3_0_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_0),  0b01000);
}

void iocfg_pio3_0_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_0), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_0),  0b10000);
}

void iocfg_pio3_0_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_0),  0b11000);
}

void iocfg_pio3_0_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_0), 0b100000);
}

void iocfg_pio3_0_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_0),  0b100000);
}


/* PIO3_1 */
void iocfg_pio3_1_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_1), 0b111);
}

void iocfg_pio3_1_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_1), 0b11000);
}

void iocfg_pio3_1_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_1), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_1),  0b01000);
}

void iocfg_pio3_1_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_1), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_1),  0b10000);
}

void iocfg_pio3_1_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_1),  0b11000);
}

void iocfg_pio3_1_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_1), 0b100000);
}

void iocfg_pio3_1_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_1),  0b100000);
}


/* PIO2_3 */
void iocfg_pio2_3_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_3), 0b111);
}

void iocfg_pio2_3_set_func_ri(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_3), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_3),  0b001);
}

void iocfg_pio2_3_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_3), 0b11000);
}

void iocfg_pio2_3_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_3), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_3),  0b01000);
}

void iocfg_pio2_3_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_3), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_3),  0b10000);
}

void iocfg_pio2_3_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_3),  0b11000);
}

void iocfg_pio2_3_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio2_3), 0b100000);
}

void iocfg_pio2_3_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio2_3),  0b100000);
}


/* PIO1_3 */
void iocfg_pio1_3_set_func_swdio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b111);
}

void iocfg_pio1_3_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b001);
}

void iocfg_pio1_3_set_func_ad4(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b010);
}

void iocfg_pio1_3_set_func_ct32b1_mat2(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b011);
}

void iocfg_pio1_3_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b11000);
}

void iocfg_pio1_3_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b01000);
}

void iocfg_pio1_3_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b10000);
}

void iocfg_pio1_3_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b11000);
}

void iocfg_pio1_3_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.swdio_pio1_3_ad4), 0b100000);
}

void iocfg_pio1_3_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.swdio_pio1_3_ad4),  0b100000);
}


/* PIO1_4 */
void iocfg_pio1_4_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b111);
}

void iocfg_pio1_4_set_func_ad5(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b001);
}

void iocfg_pio1_4_set_func_ct32b1_mat3(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b010);
}

void iocfg_pio1_4_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b11000);
}

void iocfg_pio1_4_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b01000);
}

void iocfg_pio1_4_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b10000);
}

void iocfg_pio1_4_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b11000);
}

void iocfg_pio1_4_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_4_ad5), 0b100000);
}

void iocfg_pio1_4_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_4_ad5),  0b100000);
}


/* PIO1_11 */
void iocfg_pio1_11_set_func_gpio(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_11_ad7),  0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_11_ad7), 0b111);
}

void iocfg_pio1_11_set_func_ad7(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_11_ad7), 0b10000000);

	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_11_ad7), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_11_ad7),  0b001);
}

void iocfg_pio1_11_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_11_ad7), 0b11000);
}

void iocfg_pio1_11_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_11_ad7), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_11_ad7),  0b01000);
}

void iocfg_pio1_11_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_11_ad7), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_11_ad7),  0b10000);
}

void iocfg_pio1_11_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_11_ad7),  0b11000);
}

void iocfg_pio1_11_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_11_ad7), 0b100000);
}

void iocfg_pio1_11_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_11_ad7),  0b100000);
}


/* PIO3_2 */
void iocfg_pio3_2_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_2), 0b111);
}

void iocfg_pio3_2_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_2), 0b11000);
}

void iocfg_pio3_2_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_2), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_2),  0b01000);
}

void iocfg_pio3_2_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_2), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_2),  0b10000);
}

void iocfg_pio3_2_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_2),  0b11000);
}

void iocfg_pio3_2_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_2), 0b100000);
}

void iocfg_pio3_2_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_2),  0b100000);
}


/* PIO1_5 */
void iocfg_pio1_5_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_5), 0b111);
}

void iocfg_pio1_5_set_func_rts(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_5), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_5),  0b001);
}

void iocfg_pio1_5_set_func_ct32b0_cap0(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_5), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_5),  0b010);
}

void iocfg_pio1_5_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_5), 0b11000);
}

void iocfg_pio1_5_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_5), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_5),  0b01000);
}

void iocfg_pio1_5_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_5), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_5),  0b10000);
}

void iocfg_pio1_5_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_5),  0b11000);
}

void iocfg_pio1_5_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_5), 0b100000);
}

void iocfg_pio1_5_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_5),  0b100000);
}


/* PIO1_6 */
void iocfg_pio1_6_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_6_rxd), 0b111);
}

void iocfg_pio1_6_set_func_rxd(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_6_rxd), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_6_rxd),  0b001);
}

void iocfg_pio1_6_set_func_ct32b0_mat0(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_6_rxd), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_6_rxd),  0b010);
}

void iocfg_pio1_6_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_6_rxd), 0b11000);
}

void iocfg_pio1_6_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_6_rxd), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_6_rxd),  0b01000);
}

void iocfg_pio1_6_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_6_rxd), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_6_rxd),  0b10000);
}

void iocfg_pio1_6_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_6_rxd),  0b11000);
}

void iocfg_pio1_6_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_6_rxd), 0b100000);
}

void iocfg_pio1_6_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_6_rxd),  0b100000);
}


/* PIO1_7 */
void iocfg_pio1_7_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_7_txd), 0b111);
}

void iocfg_pio1_7_set_func_txd(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_7_txd), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_7_txd),  0b001);
}

void iocfg_pio1_7_set_func_ct32b0_mat1(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_7_txd), 0b111);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_7_txd),  0b010);
}

void iocfg_pio1_7_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_7_txd), 0b11000);
}

void iocfg_pio1_7_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_7_txd), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_7_txd),  0b01000);
}

void iocfg_pio1_7_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_7_txd), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_7_txd),  0b10000);
}

void iocfg_pio1_7_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_7_txd),  0b11000);
}

void iocfg_pio1_7_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio1_7_txd), 0b100000);
}

void iocfg_pio1_7_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio1_7_txd),  0b100000);
}


/* PIO3_3 */
void iocfg_pio3_3_set_func_gpio(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_3), 0b111);
}

void iocfg_pio3_3_set_resistor_none(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_3), 0b11000);
}

void iocfg_pio3_3_set_resistor_pull_down(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_3), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_3),  0b01000);
}

void iocfg_pio3_3_set_resistor_pull_up(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_3), 0b11000);
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_3),  0b10000);
}

void iocfg_pio3_3_set_resistor_repeater(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_3),  0b11000);
}

void iocfg_pio3_3_set_hysteresis_disable(void)
{
	set_all_bits_zero(&(mmap->apb_ioconfig.pio3_3), 0b100000);
}

void iocfg_pio3_3_set_hysteresis_enable(void)
{
	set_all_bits_one(&(mmap->apb_ioconfig.pio3_3),  0b100000);
}


