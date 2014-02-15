#include <sysctrl.h>
#include <bits.h>
#include <mmap.h>
#include <armv7m.h>
#include <delay.h>



/* sysmemremap */
void remap_vectors_to_boot_rom(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.sysmemremap), 0b11);
}

void remap_vectors_to_sram(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.sysmemremap), 0b11);
	set_all_bits_one(&(mmap->apb_system_control.sysmemremap),  0b01);
}

void remap_vectors_to_flash(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.sysmemremap), 0b11);
	set_all_bits_one(&(mmap->apb_system_control.sysmemremap),  0b10);
}


/* presetctrl */
void ssp_reset_enabled(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.presetctrl), 0b1);
}

void ssp_reset_disabled(void)
{
	set_all_bits_one(&(mmap->apb_system_control.presetctrl),  0b1);
}

void i2c_reset_enabled(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.presetctrl), 0b10);
}

void i2c_reset_disabled(void)
{
	set_all_bits_one(&(mmap->apb_system_control.presetctrl),  0b10);
}


/* syspllctrl */
void syspll_set_first_divider_1(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
}

void syspll_set_first_divider_2(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b00001);
}

void syspll_set_first_divider_3(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b00010);
}

void syspll_set_first_divider_4(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b00011);
}

void syspll_set_first_divider_5(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b00100);
}

void syspll_set_first_divider_6(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b00101);
}

void syspll_set_first_divider_7(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b00110);
}

void syspll_set_first_divider_8(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b00111);
}

void syspll_set_first_divider_9(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01000);
}

void syspll_set_first_divider_10(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01001);
}

void syspll_set_first_divider_11(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01010);
}

void syspll_set_first_divider_12(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01011);
}

void syspll_set_first_divider_13(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01100);
}

void syspll_set_first_divider_14(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01101);
}

void syspll_set_first_divider_15(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01110);
}

void syspll_set_first_divider_16(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b01111);
}

void syspll_set_first_divider_17(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10000);
}

void syspll_set_first_divider_18(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10001);
}

void syspll_set_first_divider_19(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10010);
}

void syspll_set_first_divider_20(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10011);
}

void syspll_set_first_divider_21(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10100);
}

void syspll_set_first_divider_22(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10101);
}

void syspll_set_first_divider_23(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10110);
}

void syspll_set_first_divider_24(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b10111);
}

void syspll_set_first_divider_25(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11000);
}

void syspll_set_first_divider_26(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11001);
}

void syspll_set_first_divider_27(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11010);
}

void syspll_set_first_divider_28(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11011);
}

void syspll_set_first_divider_29(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11100);
}

void syspll_set_first_divider_30(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11101);
}

void syspll_set_first_divider_31(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11110);
}

void syspll_set_first_divider_32(void)
{
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b11111);
}

void syspll_set_second_diviver_2(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b1100000);
}

void syspll_set_second_diviver_4(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b1100000);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b0100000);
}

void syspll_set_second_diviver_8(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllctrl), 0b1100000);
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b1000000);
}

void syspll_set_second_diviver_16(void)
{
	set_all_bits_one(&(mmap->apb_system_control.syspllctrl),  0b1100000);
}

void syspll_set_dividers_12MHz_to_12Mhz(void)
{
	syspll_set_first_divider_1();		//12 MHz
	syspll_set_second_diviver_2();		//12 MHz	
}

void syspll_set_dividers_12MHz_to_24Mhz(void)
{
	syspll_set_first_divider_2();		//24 MHz
	syspll_set_second_diviver_8();		//24 MHz
}

void syspll_set_dividers_12MHz_to_36Mhz(void)
{
	syspll_set_first_divider_3();		//36 MHz
	syspll_set_second_diviver_8();		//36 MHz
}

void syspll_set_dividers_12MHz_to_48Mhz(void)
{
	syspll_set_first_divider_4();		//48 MHz
	syspll_set_second_diviver_4();		//48 MHz
}

void syspll_set_dividers_12MHz_to_72Mhz(void)
{
	syspll_set_first_divider_6();		//72 MHz
	syspll_set_second_diviver_4();		//72 MHz
}


/* syspllstat */
uint32_t syspll_is_locked(void)
{
	return bit_is_set(&(mmap->apb_system_control.syspllstat), 0);
}

/* usbpllctrl */
void usbpll_set_first_divider_1(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
}

void usbpll_set_first_divider_2(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b00001);
}

void usbpll_set_first_divider_3(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b00010);
}

void usbpll_set_first_divider_4(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b00011);
}

void usbpll_set_first_divider_5(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b00100);
}

void usbpll_set_first_divider_6(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b00101);
}

void usbpll_set_first_divider_7(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b00110);
}

void usbpll_set_first_divider_8(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b00111);
}

void usbpll_set_first_divider_9(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01000);
}

void usbpll_set_first_divider_10(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01001);
}

void usbpll_set_first_divider_11(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01010);
}

void usbpll_set_first_divider_12(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01011);
}

void usbpll_set_first_divider_13(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01100);
}

void usbpll_set_first_divider_14(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01101);
}

void usbpll_set_first_divider_15(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01110);
}

void usbpll_set_first_divider_16(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b01111);
}

void usbpll_set_first_divider_17(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10000);
}

void usbpll_set_first_divider_18(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10001);
}

void usbpll_set_first_divider_19(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10010);
}

void usbpll_set_first_divider_20(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10011);
}

void usbpll_set_first_divider_21(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10100);
}

void usbpll_set_first_divider_22(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10101);
}

void usbpll_set_first_divider_23(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10110);
}

void usbpll_set_first_divider_24(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b10111);
}

void usbpll_set_first_divider_25(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11000);
}

void usbpll_set_first_divider_26(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11001);
}

void usbpll_set_first_divider_27(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11010);
}

void usbpll_set_first_divider_28(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11011);
}

void usbpll_set_first_divider_29(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11100);
}

void usbpll_set_first_divider_30(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11101);
}

void usbpll_set_first_divider_31(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b11111);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11110);
}

void usbpll_set_first_divider_32(void)
{
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b11111);
}

void usbpll_set_second_diviver_2(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b1100000);
}

void usbpll_set_second_diviver_4(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b1100000);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b0100000);
}

void usbpll_set_second_diviver_8(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllctrl), 0b1100000);
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b1000000);
}

void usbpll_set_second_diviver_16(void)
{
	set_all_bits_one(&(mmap->apb_system_control.usbpllctrl),  0b1100000);
}

void usbpll_set_dividers_12MHz_to_48Mhz(void)
{
	usbpll_set_first_divider_4();		//48 MHz
	usbpll_set_second_diviver_4();		//48 MHz
}



/* usbpllstat */
uint32_t usbpll_is_locked(void)
{
	return bit_is_set(&(mmap->apb_system_control.usbpllstat), 0);
}



/* sysoscctrl */
void sysosc_disable(void)
{
	set_bit_one(&(mmap->apb_system_control.sysoscctrl), 0);
	delay_ticks(500);
}

void sysosc_enable_1MHz_20MHz(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysoscctrl), 0);
	set_bit_zero(&(mmap->apb_system_control.sysoscctrl), 1);
	delay_ticks(500);
}

void sysosc_enable_15MHz_25MHz(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysoscctrl), 0);
	set_bit_one(&(mmap->apb_system_control.sysoscctrl), 1);
	delay_ticks(500);
}


/* syspllclksel, syspllclkuen */
void syspll_set_clock_source_irc(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllclksel),  0b11);

	set_bit_one(&(mmap->apb_system_control.syspllclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.syspllclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.syspllclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.syspllclkuen), 0))
		no_operation();
}

void syspll_set_clock_source_sysosc(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.syspllclksel),  0b11);
	set_all_bits_one(&(mmap->apb_system_control.syspllclksel),   0b01);

	set_bit_one(&(mmap->apb_system_control.syspllclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.syspllclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.syspllclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.syspllclkuen), 0))
		no_operation();
}


/* usbpllclksel, usbpllclkuen */
void usbpll_set_clock_source_irc(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllclksel),  0b11);

	set_bit_one(&(mmap->apb_system_control.usbpllclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.usbpllclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.usbpllclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.usbpllclkuen), 0))
		no_operation();
}

void usbpll_set_clock_source_sysosc(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbpllclksel),  0b11);
	set_all_bits_one(&(mmap->apb_system_control.usbpllclksel),   0b01);

	set_bit_one(&(mmap->apb_system_control.usbpllclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.usbpllclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.usbpllclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.usbpllclkuen), 0))
		no_operation();
}


/* mainclksel, mainclkuen */
void mainclk_set_clock_source_irc(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.mainclksel),  0b11);

	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.mainclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.mainclkuen),  0))
		no_operation();
}

void mainclk_set_clock_source_syspll_in(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.mainclksel),  0b11);
	set_all_bits_one(&(mmap->apb_system_control.mainclksel),   0b01);

	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.mainclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.mainclkuen),  0))
		no_operation();
}

void mainclk_set_clock_source_wdtosc(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.mainclksel),  0b11);
	set_all_bits_one(&(mmap->apb_system_control.mainclksel),   0b10);

	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.mainclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.mainclkuen),  0))
		no_operation();
}

void mainclk_set_clock_source_syspll_out(void)
{
	set_all_bits_one(&(mmap->apb_system_control.mainclksel),   0b11);

	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.mainclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.mainclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.mainclkuen),  0))
		no_operation();
}


/* sysahbclkdiv */
void sysahbclk_disable(void)
{
	sysahbclk_set_divider(0);
}

void sysahbclk_set_divider(uint32_t d)
{
	*((volatile uint32_t*)&(mmap->apb_system_control.sysahbclkdiv)) = d & 0x000000FF;
}


/* sysahbclkctrl */
void sysahbclk_ahb2apb_bridge_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 0);
}

void sysahbclk_rom_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 1);
}

void sysahbclk_rom_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 1);
}

void sysahbclk_ram_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 2);
}

void sysahbclk_ram_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 2);
}

void sysahbclk_flashreg_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 3);
}

void sysahbclk_flashreg_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 3);
}

void sysahbclk_flasharray_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 4);
}

void sysahbclk_flasharray_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 4);
}

void sysahbclk_i2c_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 5);
}

void sysahbclk_i2c_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 5);
}

void sysahbclk_gpio_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 6);
}

void sysahbclk_gpio_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 6);
}

void sysahbclk_ct16b0_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 7);
}

void sysahbclk_ct16b0_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 7);
}

void sysahbclk_ct16b1_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 8);
}

void sysahbclk_ct16b1_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 8);
}

void sysahbclk_ct32b0_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 9);
}

void sysahbclk_ct32b0_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 9);
}

void sysahbclk_ct32b1_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 10);
}

void sysahbclk_ct32b1_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 10);
}

void sysahbclk_ssp_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 11);
}

void sysahbclk_ssp_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 11);
}

void sysahbclk_uart_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 12);
}

void sysahbclk_uart_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 12);
}

void sysahbclk_adc_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 13);
}

void sysahbclk_adc_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 13);
}

void sysahbclk_usbreg_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 14);
}

void sysahbclk_usbreg_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 14);
}

void sysahbclk_wdt_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 15);
}

void sysahbclk_wdt_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 15);
}

void sysahbclk_iocon_disable_clock(void)
{
	set_bit_zero(&(mmap->apb_system_control.sysahbclkctrl), 16);
}

void sysahbclk_iocon_enable_clock(void)
{
	set_bit_one(&(mmap->apb_system_control.sysahbclkctrl), 16);
}


/* usbclksel, usbclkuen */
void usbclk_set_clock_source_usbpll_out(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbclksel),  0b11);

	set_bit_one(&(mmap->apb_system_control.usbclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.usbclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.usbclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.usbclkuen), 0))
		no_operation();
}

void usbclk_set_clock_source_mainclk(void)
{
	set_all_bits_zero(&(mmap->apb_system_control.usbclksel),  0b11);
	set_all_bits_one(&(mmap->apb_system_control.usbclksel),   0b01);

	set_bit_one(&(mmap->apb_system_control.usbclkuen),  0);
	set_bit_zero(&(mmap->apb_system_control.usbclkuen), 0);
	set_bit_one(&(mmap->apb_system_control.usbclkuen),  0);
	while (!bit_is_set(&(mmap->apb_system_control.usbclkuen), 0))
		no_operation();
}


/* usbclkdiv */
void usbclk_disable(void)
{
	usbclk_set_divider(0);
}

void usbclk_set_divider(uint32_t d)
{
	*((volatile uint32_t*)&(mmap->apb_system_control.usbclkdiv)) = d & 0x000000FF;
}


/* pdruncfg */
void runcfg_irc_out_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 0);
}

void runcfg_irc_out_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 0);
}

void runcfg_irc_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 1);
}

void runcfg_irc_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 1);
}

void runcfg_flash_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 2);
}

void runcfg_flash_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 2);
}

void runcfg_bod_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 3);
}

void runcfg_bod_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 3);
}

void runcfg_adc_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 4);
}

void runcfg_adc_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 4);
}

void runcfg_sysosc_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 5);
}

void runcfg_sysosc_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 5);
}

void runcfg_wdtosc_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 6);
}

void runcfg_wdtosc_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 6);
}

void runcfg_syspll_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 7);
}

void runcfg_syspll_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 7);
}

void runcfg_usbpll_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 8);
}

void runcfg_usbpll_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 8);
}

void runcfg_usbphy_power_on(void)
{
	set_bit_zero(&(mmap->apb_system_control.pdruncfg), 10);
}

void runcfg_usbphy_power_off(void)
{
	set_bit_one(&(mmap->apb_system_control.pdruncfg), 10);
}

