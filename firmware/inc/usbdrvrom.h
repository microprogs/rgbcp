#ifndef USBDRVROM_H
#define USBDRVROM_H


#include <types.h>
#include <mmap.h>


#define USBHID_IN_BUF_SIZE 64
#define USBHID_OUT_BUF_SIZE 64
#define USBHID_INTERVAL_MSEC 1


struct USB_DEVICE_INFO
{
	uint16_t devType;
	uint32_t devDetailPtr;
}; 


struct USBD
{
	void (*init_clk_pins)(void);
	void (*isr)(void);
	void (*init)(struct USB_DEVICE_INFO *devInfoPtr); 
	void (*connect)(uint32_t con);
};


#define init_msdstate() *((uint32_t *)(0x10000054)) = 0x0


struct ROM
{
	const struct USBD *pUSBD;
};


struct MSC_DEVICE_INFO
{
	uint16_t idVendor;
	uint16_t idProduct;
	uint16_t bcdDevice;
	uint32_t strDescPtr;
	uint32_t mscInquiryStr;
	uint32_t blockCount;
	uint32_t blockSize;
	uint32_t memorySize;
	void (*msc_write)(uint32_t offset, uint8_t src[], uint32_t length); 
	void (*msc_read)(uint32_t offset, uint8_t dst[], uint32_t length);
};


struct HID_DEVICE_INFO
{
	uint16_t idVendor;
	uint16_t idProduct;
	uint16_t bcdDevice;
	uint32_t strDescPtr;
	uint8_t inReportCount;
	uint8_t outReportCount;
	uint8_t sampleInterval;
	void (*inReport)(uint8_t src[], uint32_t length); 
	void (*outReport)(uint8_t dst[], uint32_t length);
};


#define ROM_OFFSET_JMP_TABLE	((uint32_t)0x00001ff8)
#define ROM_JMP_TABLE_PTR_PTR	((struct ROM**)((uint8_t*)(&(mmap->boot_rom)) + ROM_OFFSET_JMP_TABLE))
#define ROM_JMP_TABLE_PTR		(*ROM_JMP_TABLE_PTR_PTR)

void usbdrvrom_init_clk_pins(void);
void usbdrvrom_isr(void);
void usbdrvrom_init(struct USB_DEVICE_INFO *devInfoPtr);
void usbdrvrom_connect(uint32_t con);

void usbdrvrom_init_connect(void);

#endif

