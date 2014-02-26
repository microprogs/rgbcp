#ifndef USBDESC_H
#define USBDESC_H

#include <types.h>


#define WBVAL(x) ((x) & 0xFF),(((x) >> 8) & 0xFF)

//#define USB_DEVICE_DESC_SIZE        (sizeof(USB_DEVICE_DESCRIPTOR))
//#define USB_CONFIGUARTION_DESC_SIZE (sizeof(USB_CONFIGURATION_DESCRIPTOR))
//#define USB_INTERFACE_DESC_SIZE     (sizeof(USB_INTERFACE_DESCRIPTOR))
//#define USB_ENDPOINT_DESC_SIZE      (sizeof(USB_ENDPOINT_DESCRIPTOR))

//#define HID_DESC_OFFSET              0x0012
//#define HID_DESC_SIZE               (sizeof(HID_DESCRIPTOR))
//#define HID_REPORT_DESC_SIZE        (sizeof(HID_ReportDescriptor))

//extern const uint8_t USB_DeviceDescriptor[];
//extern const uint8_t USB_ConfigDescriptor[];
extern const uint8_t USB_StringDescriptor[];

//extern const uint8_t HID_ReportDescriptor[];
//extern const uint16_t HID_ReportDescSize;


#define NXP_VID		  0x1FC9

#define USB_VENDOR_ID NXP_VID 	// Vendor ID
#define USB_PROD_ID   0xA1B2	// Product ID
#define USB_DEVICE    0x0100	// Device ID


#endif

