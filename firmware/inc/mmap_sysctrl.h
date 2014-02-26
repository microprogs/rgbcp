#ifndef MMAP_SYSCTRL_H
#define MMAP_SYSCTRL_H

#include <types.h>

struct memio_sysctrl
{
	uint32_t sysmemremap;			//default (0x00000002)
	uint32_t presetctrl;			//default (0x00000000)
	uint32_t syspllctrl;			//default (0x00000000)
	uint32_t syspllstat;			//default (0x00000000)
	uint32_t usbpllctrl;			//default (0x00000000)
	uint32_t usbpllstat;			//default (0x00000000)
	uint32_t __reserved0[2];		//default (0x????????)

	uint32_t sysoscctrl;			//default (0x00000000)
	uint32_t wdtoscctrl;			//default (0x00000000)
	uint32_t ircctrl;				//default (0x00000080)
	uint32_t __reserved1[1];		//default (0x????????)
	uint32_t sysresstat;			//default (0x00000000)
	uint32_t __reserved2[3];		//default (0x????????)
	uint32_t syspllclksel;			//default (0x00000000)
	uint32_t syspllclkuen;			//default (0x00000000)
	uint32_t usbpllclksel;			//default (0x00000000)
	uint32_t usbpllclkuen;			//default (0x00000000)
	uint32_t __reserved3[8];		//default (0x????????)

	uint32_t mainclksel;			//default (0x00000000)
	uint32_t mainclkuen;			//default (0x00000000)
	uint32_t sysahbclkdiv;			//default (0x00000001)
	uint32_t __reserved4[1];		//default (0x????????)

	uint32_t sysahbclkctrl;			//default (0x0000485F)
	uint32_t __reserved5[4];		//default (0x????????)
	uint32_t sspclkdiv;				//default (0x00000001)
	uint32_t uartclkdiv;			//default (0x00000000)
	uint32_t __reserved6[4];		//default (0x????????)
	uint32_t traceclkdiv;			//default (0x00000000)

	uint32_t systickclkdiv;			//default (0x00000000)
	uint32_t __reserved7[3];		//default (0x????????)

	uint32_t usbclksel;				//default (0x00000000)
	uint32_t usbclkuen;				//default (0x00000000)
	uint32_t usbclkdiv;				//default (0x00000001)
	uint32_t __reserved8[1];		//default (0x????????)
	uint32_t wdtclksel;				//default (0x00000000)
	uint32_t wdtclkuen;				//default (0x00000000)
	uint32_t wdtclkdiv;				//default (0x00000000)
	uint32_t __reserved9[1];		//default (0x????????)
	uint32_t clkoutclksel;			//default (0x00000000)
	uint32_t clkoutuen;				//default (0x00000000)
	uint32_t clkoutdiv;				//default (0x00000000)
	uint32_t __reserved10[5];		//default (0x????????)
  
	uint32_t pioporcap0;			//default (0x????????)
	uint32_t pioporcap1;			//default (0x????????)
	uint32_t __reserved11[18];		//default (0x00000000)

	uint32_t bodctrl;				//default (0x00000000)
	uint32_t __reserved12[1];		//default (0x????????)
	uint32_t systckcal;				//default (0x00000004)
	uint32_t ___reserved13[41];		//default (0x????????)

	uint32_t startaprp0;			//default (0x????????)
	uint32_t starterp0;				//default (0x????????)
	uint32_t startrsrp0clr;			//default (0x????????)
	uint32_t startsrp0;				//default (0x????????)
	uint32_t startaprp1;			//default (0x????????)
	uint32_t starterp1;				//default (0x????????)
	uint32_t startrsrp1clr;			//default (0x????????)
	uint32_t startsrp1;				//default (0x????????)
	uint32_t __reserved14[4];		//default (0x????????)

	uint32_t pdsleepcfg;			//default (0x00000000)
	uint32_t pdawakecfg;			//default (0x0000FDF0)
	uint32_t pdruncfg;				//default (0x0000FDF0)
	uint32_t __reserved15[110];		//default (0x????????)
	uint32_t device_id;				//default (0x????????)
	uint32_t __reserved16[0xF02];	//default (0x????????)
} __attribute__((packed));


#endif

