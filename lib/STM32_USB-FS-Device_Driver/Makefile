BINPATH=

CC=$(BINPATH)arm-none-eabi-gcc
AR=$(BINPATH)arm-none-eabi-ar

vpath %.c src

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m3

ifeq ($(FLOAT_TYPE), hard)
CFLAGS += -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
else
CFLAGS += -msoft-float
endif

CFLAGS += -ffreestanding -nostdlib

# Includes
CFLAGS += -Iinc -I$(BASEDIR) -I$(BASEDIR)/lib/CMSIS/Include -I$(BASEDIR)/lib/CMSIS/Device/ST/STM32L1xx/Include -I$(BASEDIR)/lib/STM32L1xx_StdPeriph_Driver/inc
CFLAGS += -I$(BASEDIR)/lib/Conf -I$(BASEDIR)/lib/STM32_USB-FS-Device_Driver/inc

# Default to STM32L1XX_MD if no device is passed
ifeq ($(DEVICE_DEF), )
DEVICE_DEF = STM32L1XX_MD
endif

CFLAGS += -D$(DEVICE_DEF)

# Sources
SRCS = usb_core.c usb_init.c usb_int.c usb_mem.c usb_regs.c usb_sil.c

OBJS = $(SRCS:.c=.o)
LIBNAME = libusbcore.a

all: $(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBNAME): $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) $(LIBNAME)
	