#include <usbdrvrom.h>
#include <types.h>
#include <usbtypes.h>
#include <usbdesc.h>
#include <sysctrl.h>
#include <delay.h>


__attribute__((section(".usb_drv_ram")))
uint8_t usb_drv_ram_buffers[0x180] = {0};


/* Must be static, not stack */
static struct USB_DEVICE_INFO DeviceInfo;
static struct HID_DEVICE_INFO HidDevInfo;


/*
This function configures the LPC134x assuming an external crystal with 12 MHz clock
frequency:
 * The system PLL is configured to output a 48 MHz clock.
 * The main clock is connected to the system PLL output, and the input to the USB clock
   divider is connected to the main clock.
 * The USB bit in the AHB clock divider is set to 1.
 * The USB pins are connected to the USB block, and the USB PHY is enabled.
 * The USB clock divider is set to 1.
 * The USB PLL is enabled.
*/
void usbdrvrom_init_clk_pins(void)
{
	ROM_JMP_TABLE_PTR->pUSBD->init_clk_pins();
}

/*
When the user application is active the interrupt handlers are mapped in the user flash
space. The user application must provide an interrupt handler for the USB interrupt and
call this function in the interrupt handler routine. The driver interrupt handler takes
appropriate action according to the data received on the USB bus and the configured
device type (HID or MSC).
*/
void usbdrvrom_isr(void)
{
	ROM_JMP_TABLE_PTR->pUSBD->isr();
}

/*
This function must be called by the application software after the clock and pin
initialization. A pointer to the structure describing the USB device type is passed as a
parameter to this function. The USB device type can be HID or MSC. The pointer is stored
for future reference. The USB device controller is initialized and the corresponding USB
interrupt channel is enabled in the NVIC.
*/
void usbdrvrom_init(struct USB_DEVICE_INFO *devInfoPtr)
{
	ROM_JMP_TABLE_PTR->pUSBD->init(devInfoPtr);
}

/*
This function is called after the USB initialization. This function uses the soft connect
feature to make the device visible on the USB bus. This function is called only after the
application is ready to handle the USB data. The enumeration process is started by the
host after the device detection. The driver handles the enumeration process according to
the USB device type pointer passed in the USB initialization function.
*/
void usbdrvrom_connect(uint32_t con)
{
	ROM_JMP_TABLE_PTR->pUSBD->connect(con);
}

void usbdrvrom_init_connect(void)
{
	extern void GetInReport (uint8_t src[], uint32_t length);
	extern void SetOutReport (uint8_t dst[], uint32_t length);

	HidDevInfo.idVendor = USB_VENDOR_ID;
	HidDevInfo.idProduct = USB_PROD_ID;
	HidDevInfo.bcdDevice = USB_DEVICE; 
	HidDevInfo.strDescPtr = (uint32_t)&USB_StringDescriptor[0];
	HidDevInfo.inReportCount = USBHID_IN_BUF_SIZE;
	HidDevInfo.outReportCount = USBHID_OUT_BUF_SIZE;
	HidDevInfo.sampleInterval = USBHID_INTERVAL_MSEC;
	HidDevInfo.inReport = GetInReport;
	HidDevInfo.outReport = SetOutReport;

	DeviceInfo.devType = USB_DEVICE_CLASS_HUMAN_INTERFACE;
	DeviceInfo.devDetailPtr = (uint32_t)&HidDevInfo;

	/* Enable Timer32_1, IOCON, and USB blocks (for USB ROM driver) */
	sysahbclk_iocon_enable_clock();
	sysahbclk_ct32b1_enable_clock();
	sysahbclk_usbreg_enable_clock();


	/* Use pll and pin init function in rom */
	usbdrvrom_init_clk_pins();

	/* insert a delay between clk init and usb init */
	delay_ticks(500);

	usbdrvrom_init(&DeviceInfo); 		/* USB Initialization */
	usbdrvrom_connect(TRUE);     		/* USB Connect */
}

