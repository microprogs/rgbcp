# Сборка firmware
# ARM Cortex-M3 GNU Toolchain в директории: ~/gnu-cortex-m3/toolchain/

CROSS_COMPILE=export PATH="$$HOME/gnu-cortex-m3/toolchain/bin:$$PATH" ; arm-none-eabi-
CC=$(CROSS_COMPILE)gcc
AS=$(CROSS_COMPILE)as
LD=$(CROSS_COMPILE)ld
CPREPROC=$(CROSS_COMPILE)cpp
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump
STRIP=$(CROSS_COMPILE)strip
SIZE=$(CROSS_COMPILE)size
STRINGS=$(CROSS_COMPILE)strings
READELF=$(CROSS_COMPILE)readelf
NM=$(CROSS_COMPILE)nm

DBIN=bin
DSRC=src
DINC=inc
DLIB=lib
DUTILS=utils

FWEXT=$(DUTILS)/fwext/fwext
FWSUM=$(DUTILS)/fwsum/fwsum
FWCHECK=$(DUTILS)/fwcheck/fwcheck


OUTELF=firmware.elf
OUTBIN=firmware.bin
LDSCRIPT=link.ld

CFLAGS=-std=gnu99 -Wall -Werror -Os -mcpu=cortex-m3 -mthumb -mno-thumb-interwork -I$(DINC) -I$(DSRC)
LDFLAGS=-nostdlib -Xlinker --gc-sections -T $(DSRC)/$(LDSCRIPT) -o $(DBIN)/$(OUTELF)

LOGSZ=firmware.log.size
LOGSTR=firmware.log.strings
LOGRDELF=firmware.log.readelf
LOGNM=firmware.log.nm
LOGDASM=firmware.log.dasm

.PHONY: all
all: compile

.PHONY: compile
compile: clean
	$(CC) $(CFLAGS) $(LDFLAGS) $(DSRC)/*.c $(DLIB)/*.c
	cd $(DBIN) && $(SIZE) -A -x $(OUTELF) | tee $(LOGSZ)
	cd $(DBIN) && $(STRINGS) -t x $(OUTELF) | tee $(LOGSTR)
	cd $(DBIN) && $(READELF) -a $(OUTELF) | tee $(LOGRDELF)
	cd $(DBIN) && $(READELF) -S $(OUTELF) | tee $(LOGNM)
	cd $(DBIN) && $(OBJDUMP) -d $(OUTELF) | tee $(LOGDASM)
	cd $(DBIN) && $(OBJCOPY) --strip-unneeded -O binary $(OUTELF) $(OUTBIN)
	ls -l $(DBIN)/$(OUTBIN)
	$(FWEXT) $(DBIN)/$(OUTBIN)
	$(FWSUM) $(DBIN)/$(OUTBIN)
	$(FWCHECK) $(DBIN)/$(OUTBIN)
	echo "########## BUILD COMPLETE ##########"

#	$(AS) --version
#	$(LD) --version
#	$(CPREPROC) --version
#	$(STRIP) --version

.PHONY: clean
clean:
	cd $(DBIN) && rm -f $(OUTELF) $(OUTBIN) $(LOGSZ) $(LOGSTR) $(LOGRDELF) $(LOGNM) $(LOGDASM) 2>/dev/null
	echo "########## CLEAN COMPLETE ##########"
