#!/bin/bash

if [ $# != 2 ]; then
	echo "Usage: fwread <flash_device> <firmware_file.bin>" >&2
	exit 1
fi

sudo umount $1
cat /dev/null > $2
sudo dd if=$1 of=$2 bs=512 count=32768 skip=4

