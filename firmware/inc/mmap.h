#ifndef MMAP_H
#define MMAP_H


#include <mmap_gpio.h>
#include <mmap_ioconfig.h>
#include <mmap_sysctrl.h>


// Full Memory Map (4 GB Address Space) for LPC1343
struct memory_map
{
	union
	{
		uint8_t flash[0x00008000];
		struct
		{
			uint8_t flash_vectors[0x00000400];  			//0x00000000 - 0x000003FF: FLASH: Interrupt Table (size 0x00000400)
			uint8_t flash_code[0x00007C00];     			//0x00000400 - 0x00007FFF: FLASH: Code (size 0x00007C00)
		};
	};

	uint8_t __reserved0[0x0FFF8000];						//0x00008000 - 0x0FFFFFFF: ***** Reserved ***** (size 0x0FFF8000)

	union
	{
		uint8_t sram[0x00002000];
		struct
		{
			uint8_t sram_usb_driver_buffers[0x00000180];	//0x10000000 - 0x1000017F: SRAM: USB Driver Buffers (size 0x00000180)
			uint8_t sram_available_ram[0x00001E80];			//0x10000180 - 0x10001FFF: SRAM: Available RAM (size 0x00001E80)
		};
	};

	uint8_t __reserved1[0x0FFEE000];						//0x10002000 - 0x1FFEFFFF: ***** Reserved ***** (size 0x0FFEE000)

	uint8_t boot_rom[0x00004000];							//0x1FFF0000 - 0x1FFF3FFF: BOOT ROM (size 0x00004000)

	uint8_t __reserved2[0x0200C000];						//0x1FFF4000 - 0x21FFFFFF: ***** Reserved ***** (size 0x0200C000)
	uint8_t ahb_sram_bit_addressing[0x02000000];			//0x22000000 - 0x23FFFFFF: AHB SRAM bit-band alias addressing (size 0x02000000)
	uint8_t __reserved3[0x1C000000];						//0x24000000 - 0x3FFFFFFF: ***** Reserved ***** (size 0x1C000000)

	uint8_t apb_i2c[0x00004000];							//0x40000000 - 0x40003FFF: APB: I2C (size 0x00004000)
	uint8_t apb_wdt[0x00004000];							//0x40004000 - 0x40007FFF: APB: WDT (size 0x00004000)
	uint8_t apb_uart[0x00004000];							//0x40008000 - 0x4000BFFF: APB: UART (size 0x00004000)
	uint8_t apb_ct16b0[0x00004000];							//0x4000C000 - 0x4000FFFF: APB: CT16B0 (size 0x00004000)
	uint8_t apb_ct16b1[0x00004000];							//0x40010000 - 0x40013FFF: APB: CT16B1 (size 0x00004000)
	uint8_t apb_ct32b0[0x00004000];							//0x40014000 - 0x40017FFF: APB: CT32B0 (size 0x00004000)
	uint8_t apb_ct32b1[0x00004000];							//0x40018000 - 0x4001BFFF: APB: CT32B1 (size 0x00004000)
	uint8_t apb_adc[0x00004000];							//0x4001C000 - 0x4001FFFF: APB: ADC (size 0x00004000)
	uint8_t apb_usb[0x00004000];							//0x40020000 - 0x40023FFF: APB: USB (size 0x00004000)

	uint8_t __reserved4[0x00014000];						//0x40024000 - 0x40037FFF: ***** Reserved ***** (size 0x00014000)

	uint8_t apb_pmu[0x00004000];							//0x40038000 - 0x4003BFFF: APB: PMU (size 0x00004000)
	uint8_t apb_fmc[0x00004000];							//0x4003C000 - 0x4003FFFF: APB: FMC (size 0x00004000)
	uint8_t apb_ssp[0x00004000];							//0x40040000 - 0x40043FFF: APB: SSP (size 0x00004000)

	union
	{
		uint8_t apb_ioconfig_raw[0x00004000];						//0x40044000 - 0x40047FFF: APB: IOCONFIG (size 0x00004000)
		struct memio_ioconfig apb_ioconfig;
	};

	union
	{
		uint8_t apb_system_control_raw[0x00004000];					//0x40048000 - 0x4004BFFF: APB: System Control (size 0x00004000)
		struct memio_sysctrl apb_system_control;
	};

	uint8_t __reserved5[0x0FFB4000];						//0x4004C000 - 0x4FFFFFFF: ***** Reserved ***** (size 0x0FFB4000)

	union
	{
		uint8_t ahb_gpio_port0_raw[0x00010000];						//0x50000000 - 0x5000FFFF: AHB: GPIO PORT 0 (size 0x00010000)
		struct memio_gpio_port ahb_gpio_port0;
	};

	union
	{
		uint8_t ahb_gpio_port1_raw[0x00010000];						//0x50010000 - 0x5001FFFF: AHB: GPIO PORT 1 (size 0x00010000)
		struct memio_gpio_port ahb_gpio_port1;
	};

	union
	{
		uint8_t ahb_gpio_port2_raw[0x00010000];						//0x50020000 - 0x5002FFFF: AHB: GPIO PORT 2 (size 0x00010000)
		struct memio_gpio_port ahb_gpio_port2;
	};

	union
	{
		uint8_t ahb_gpio_port3_raw[0x00010000];						//0x50030000 - 0x5003FFFF: AHB: GPIO PORT 3 (size 0x00010000)
		struct memio_gpio_port ahb_gpio_port3;
	};

	//0x50040000 - 0xFFFFFFFF: ***** Reserved ***** (size 0xAFFC0000)
	uint8_t __reserved6_0[0x0AFFC000];
	uint8_t __reserved6_1[0x0AFFC000];
	uint8_t __reserved6_2[0x0AFFC000];
	uint8_t __reserved6_3[0x0AFFC000];
	uint8_t __reserved6_4[0x0AFFC000];
	uint8_t __reserved6_5[0x0AFFC000];
	uint8_t __reserved6_6[0x0AFFC000];
	uint8_t __reserved6_7[0x0AFFC000];
	uint8_t __reserved6_8[0x0AFFC000];
	uint8_t __reserved6_9[0x0AFFC000];
	uint8_t __reserved6_10[0x0AFFC000];
	uint8_t __reserved6_11[0x0AFFC000];
	uint8_t __reserved6_12[0x0AFFC000];
	uint8_t __reserved6_13[0x0AFFC000];
	uint8_t __reserved6_14[0x0AFFC000];
	uint8_t __reserved6_15[0x0AFFC000];
} __attribute__((packed));

#define mmap ((volatile struct memory_map *)(0))

#endif

