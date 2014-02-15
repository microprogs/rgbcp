#ifndef MMAP_GPIO_H
#define MMAP_GPIO_H

#include <types.h>

struct memio_gpio_port 
{
	union 
	{
		uint32_t mask_data[4096];			//default (0x????????)
		struct 
		{
			uint32_t __reserved0[4095];		//default (0x????????)
			uint32_t data;					//default (0x????????)
		};
	};
	uint32_t __reserved1[4096];				//default (0x????????)
	uint32_t dir;							//default (0x00000000)
	uint32_t is;							//default (0x00000000)
	uint32_t ibe;							//default (0x00000000)
	uint32_t iev;							//default (0x00000000)
	uint32_t ie;							//default (0x00000000)
	uint32_t ris;							//default (0x00000000)
	uint32_t mis;							//default (0x00000000)
	uint32_t ic;							//default (0x00000000)
	uint32_t __reserved2[8184];				//default (0x00000000)
} __attribute__((packed));


#endif

