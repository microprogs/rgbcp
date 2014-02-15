#ifndef MMAP_IOCONFIG_H
#define MMAP_IOCONFIG_H

#include <types.h>

struct memio_ioconfig
{
	uint32_t pio2_6;						//default (0x000000D0), pin#1  - PIO2_6
	uint32_t __reserved0;					//default (0x????????)
	uint32_t pio2_0;						//default (0x000000D0), pin#2  - PIO2_0/~DTR
	uint32_t reset_pio0_0;					//default (0x000000D0), pin#3  - ~RESET/PIO0_0
	uint32_t pio0_1_bootld;					//default (0x000000D0), pin#4  - PIO0_1/CLKOUT/CT32BO_MAT2/USB_FTOGGLE
	uint32_t pio1_8;						//default (0x000000D0), pin#9  - PIO1_8/CT16B1_CAP0
	uint32_t __reserved1;					//default (0x????????)
	uint32_t pio0_2_ssel;					//default (0x000000D0), pin#10 - PIO0_2/SSEL/CT16B0_CAP0
	uint32_t pio2_7;						//default (0x000000D0), pin#11 - PIO2_7
	uint32_t pio2_8;						//default (0x000000D0), pin#12 - PIO2_8
	uint32_t pio2_1;						//default (0x000000D0), pin#13 - PIO2_1/~DSR
	uint32_t pio0_3_usb_vbus;				//default (0x000000D0), pin#14 - PIO0_3/USB_VBUS
	uint32_t pio0_4_scl;					//default (0x00000000), pin#15 - PIO0_4/SCL
	uint32_t pio0_5_sda;					//default (0x00000000), pin#16 - PIO0_5/SDA
	uint32_t pio1_9;						//default (0x000000D0), pin#17 - PIO1_9/CT16B1_MAT0
	uint32_t __reserved2;					//default (0x????????)
	uint32_t pio2_4;						//default (0x000000D0), pin#18 - PIO2_4
	uint32_t pio2_5;						//default (0x000000D0), pin#21 - PIO2_5
	uint32_t __reserved3;					//default (0x????????)
	uint32_t pio0_6_sck;					//default (0x000000D0), pin#22 - PIO0_6/~USB_CONNECT/SCK
	uint32_t pio0_7;						//default (0x000000D0), pin#23 - PIO0_7/~CTS
	uint32_t pio2_9;						//default (0x000000D0), pin#24 - PIO2_9
	uint32_t pio2_10;						//default (0x000000D0), pin#25 - PIO2_10
	uint32_t pio2_2;						//default (0x000000D0), pin#26 - PIO2_2/~DCD
	uint32_t pio0_8_miso;					//default (0x000000D0), pin#27 - PIO0_8/MISO/CT16B0_MAT0
	uint32_t pio0_9_mosi_swo;				//default (0x000000D0), pin#28 - PIO0_9/MOSI/CT16B0_MAT1/SWO
	uint32_t jtag_tck_swclk_pio0_10_sck;	//default (0x000000D0), pin#29 - SWCLK/PIO0_10/SCK/CT16B0_MAT2
	uint32_t pio1_10_ad6;					//default (0x000000D0), pin#30 - PIO1_10/AD6/CT16B1_MAT1
	uint32_t pio2_11_sck;					//default (0x000000D0), pin#31 - PIO2_11/SCK
	uint32_t r_jtag_tdi_pio0_11_ad0;		//default (0x000000D0), pin#32 - R/PIO0_11/AD0/CT32B0_MAT3
	uint32_t r_jtag_tms_pio1_0_ad1;			//default (0x000000D0), pin#33 - R/PIO1_0/AD1/CT32B1_CAP0
	uint32_t r_jtag_tdo_pio1_1_ad2;			//default (0x000000D0), pin#34 - R/PIO1_1/AD2/CT32B1_MAT0
	uint32_t r_jtag_ntrst_pio1_2_ad3;		//default (0x000000D0), pin#35 - R/PIO1_2/AD3/CT32B1_MAT1
	uint32_t pio3_0;						//default (0x000000D0), pin#36 - PIO3_0
	uint32_t pio3_1;						//default (0x000000D0), pin#37 - PIO3_1
	uint32_t pio2_3;						//default (0x000000D0), pin#38 - PIO2_3/~RI
	uint32_t swdio_pio1_3_ad4;				//default (0x000000D0), pin#39 - SWDIO/PIO1_3/AD4/CT32B1_MAT2
	uint32_t pio1_4_ad5;					//default (0x000000D0), pin#40 - PIO1_4/AD5/CT32B1_MAT3/WAKEUP
	uint32_t pio1_11_ad7;					//default (0x000000D0), pin#42 - PIO1_11/AD7
	uint32_t pio3_2;						//default (0x000000D0), pin#43 - PIO3_2
	uint32_t pio1_5;						//default (0x000000D0), pin#45 - PIO1_5/~RTS/CT32B0_CAP0
	uint32_t pio1_6_rxd;					//default (0x000000D0), pin#46 - PIO1_6/RXD/CT32B0_MAT0
	uint32_t pio1_7_txd;					//default (0x000000D0), pin#47 - PIO1_7/TXD/CT32B0_MAT1
	uint32_t pio3_3;						//default (0x000000D0), pin#48 - PIO3_3
	uint32_t sckloc;						//default (0x00000000)
	uint32_t __reserved4[0x00000FD3];		//default (0x????????)
} __attribute__((packed));

#endif

