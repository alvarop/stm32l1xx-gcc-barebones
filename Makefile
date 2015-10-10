# Sources

SRCS = main.c
S_SRCS = 

# USB
# SRCS += usbd_usr.c usbd_cdc_vcp.c usbd_desc.c usb_bsp.c usbd_core.c

# Project name

PROJ_NAME = stm32l1xx-gcc-barebones
OUTPATH = build

OUTPATH := $(abspath $(OUTPATH))

BASEDIR := $(abspath ./)

AS=$(BINPATH)arm-none-eabi-as
CC=$(BINPATH)arm-none-eabi-gcc
LD=$(BINPATH)arm-none-eabi-gcc
OBJCOPY=$(BINPATH)arm-none-eabi-objcopy
OBJDUMP=$(BINPATH)arm-none-eabi-objdump
SIZE=$(BINPATH)arm-none-eabi-size

LINKER_SCRIPT = stm32_flash.ld

CPU = -mcpu=cortex-m4 -mthumb

CFLAGS  = $(CPU) -c -std=gnu99 -g -O2 -Wall
LDFLAGS  = $(CPU) -mlittle-endian -mthumb-interwork -nostartfiles -Wl,--gc-sections,-Map=$(OUTPATH)/$(PROJ_NAME).map,--cref --specs=nano.specs

CFLAGS += -msoft-float

# Default to STM32L1XX_MD if no device is passed
ifeq ($(DEVICE_DEF), )
DEVICE_DEF = STM32L1XX_MD
endif

CFLAGS += -D$(DEVICE_DEF)

#vpath %.c src
vpath %.a lib

# Includes
INCLUDE_PATHS = -I$(BASEDIR) -I$(BASEDIR)/lib/CMSIS/Include -I$(BASEDIR)/lib/CMSIS/Device/ST/STM32L1xx/Include

# Library paths
LIBPATHS = -L$(BASEDIR)/lib/STM32F4xx_StdPeriph_Driver
# LIBPATHS += -L$(BASEDIR)/lib/STM32_USB_Device_Library/Core -L$(BASEDIR)/lib/STM32_USB_OTG_Driver

# Libraries to link
LIBS = -lstdperiph -lc -lgcc -lnosys
LIBS += -lusbdevcore -lusbcore

# Extra includes
INCLUDE_PATHS += -I$(BASEDIR)/lib/STM32F4xx_StdPeriph_Driver/inc
# INCLUDE_PATHS += -I$(BASEDIR)/lib/STM32_USB_OTG_Driver/inc
# INCLUDE_PATHS += -I$(BASEDIR)/lib/STM32_USB_Device_Library/Core/inc

#CFLAGS += -Map $(OUTPATH)/$(PROJ_NAME).map

OBJS = $(SRCS:.c=.o)
OBJS += $(S_SRCS:.s=.o)

###################################################

.PHONY: lib proj

all: lib proj
	$(SIZE) $(OUTPATH)/$(PROJ_NAME).elf

lib:
	$(MAKE) -C lib FLOAT_TYPE=$(FLOAT_TYPE) BINPATH=$(BINPATH) DEVICE_DEF=$(DEVICE_DEF) BASEDIR=$(BASEDIR)

proj: $(OUTPATH)/$(PROJ_NAME).elf

.s.o:
	$(AS) $(CPU) -o $(addprefix $(OUTPATH)/, $@) $<

.c.o:
	$(CC) $(CFLAGS) -std=gnu99 $(INCLUDE_PATHS) -o $(addprefix  $(OUTPATH)/, $@) $<

$(OUTPATH)/$(PROJ_NAME).elf: $(OBJS)
	$(LD) $(LDFLAGS) -T$(LINKER_SCRIPT) $(LIBPATHS) -o $@ $(addprefix $(OUTPATH)/, $^) $(LIBS) $(LD_SYS_LIBS)
	$(OBJCOPY) -O ihex $(OUTPATH)/$(PROJ_NAME).elf $(OUTPATH)/$(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(OUTPATH)/$(PROJ_NAME).elf $(OUTPATH)/$(PROJ_NAME).bin
	$(OBJDUMP) -S --disassemble $(OUTPATH)/$(PROJ_NAME).elf > $(OUTPATH)/$(PROJ_NAME).dis

clean:
	rm -f $(OUTPATH)/*.o
	rm -f $(OUTPATH)/$(PROJ_NAME).elf
	rm -f $(OUTPATH)/$(PROJ_NAME).hex
	rm -f $(OUTPATH)/$(PROJ_NAME).bin
	rm -f $(OUTPATH)/$(PROJ_NAME).dis
	rm -f $(OUTPATH)/$(PROJ_NAME).map
	# Remove this line if you don't want to clean the libs as well
	$(MAKE) clean -C lib
	