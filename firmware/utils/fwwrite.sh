#!/bin/bash

if [ $# != 2 ]; then
	echo "Usage: fwwrite <firmware_file.bin> <flash_device>" >&2
	exit 1
fi

if [ ! -f "$1" ]; then
	echo "Can't open firmware file $1" >&2
	exit 1
fi

sudo umount $2
sudo dd if=$1 of=$2 bs=512 count=32768 seek=4 conv=notrunc

