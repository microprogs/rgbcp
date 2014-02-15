#include <usbdesc.h>
#include <usbtypes.h>
#include <types.h>

/* USB String Descriptor (optional) */
const uint8_t USB_StringDescriptor[] = {
  /* Index 0x00: LANGID Codes */
  0x04,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  WBVAL(NXP_VID), /* US English */    /* wLANGID */
  /* Index 0x04: Manufacturer */
  0x1C,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'M',0,
  'I',0,
  'C',0,
  'R',0,
  'O',0,
  'P',0,
  'R',0,
  'O',0,
  'G',0,
  'S',0,
  'L',0,
  'A',0,
  'B',0,
  /* Index 0x20: Product */
  0x28,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'R',0,
  'G',0,
  'B',0,
  ' ',0,
  'C',0,
  'O',0,
  'R',0,
  'T',0,
  'E',0,
  'X',0,
  'M',0,
  ' ',0,
  'P',0,
  'R',0,
  'O',0,
  'J',0,
  'E',0,
  'C',0,
  'T',0,
  /* Index 0x48: Serial Number */
  0x1A,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'R',0,
  'G',0,
  'B',0,
  'C',0,
  'P',0,
  '-',0,
  'D',0,
  'R',0,
  'A',0,
  'F',0,
  'T',0,
  '0',0,
  /* Index 0x62: Interface 0, Alternate Setting 0 */
  0x0E,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'H',0,
  'I',0,
  'D',0,
  ' ',0,
  ' ',0,
  ' ',0,
};


