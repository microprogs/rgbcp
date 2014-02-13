MEMORY
{
	flash (rx) : ORIGIN = 0x00000000, LENGTH = 0x00008000
	ram   (rw) : ORIGIN = 0x10000000, LENGTH = 0x00002000
}

_flash_start       = ORIGIN(flash);
_flash_size        = LENGTH(flash);
_flash_end         = _flash_start + _flash_size;

_ram_start         = ORIGIN(ram);
_ram_size          = LENGTH(ram);
_ram_end           = _ram_start + _ram_size;

_stack_top         = _ram_end;

ENTRY(reset_handler)

SECTIONS
{
	.text :
	{
		_text = .;
		KEEP(*(.vector_table))
		*(.text*)
		*(.rodata*)
		_etext = .;
	} > flash

	.data :
	{
		_data = .;
		_usb_drv_ram_start = .;
		_usb_drv_ram_size = 0x180;		
		KEEP(*(.usb_drv_ram))
		. = _data + _usb_drv_ram_size;
		_usb_drv_ram_end = .;
		*(.data*)
		_edata = .;
	} > ram AT>flash

	.bss :
	{
		_bss = .;
		*(.bss*)
		*(COMMON)
		_ebss = .;
	} > ram
}

