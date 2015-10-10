BINPATH=

CC=$(BINPATH)arm-none-eabi-gcc
AR=$(BINPATH)arm-none-eabi-ar

# Check for valid float argument
ifneq ($(FLOAT_TYPE), hard)
ifneq ($(FLOAT_TYPE), soft)
override FLOAT_TYPE = soft
endif
endif

vpath %.c src

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m3
CFLAGS += -msoft-float

CFLAGS += -ffreestanding -nostdlib

# Includes
CFLAGS += -Iinc -I$(BASEDIR)/lib/CMSIS/Include -I$(BASEDIR)/lib/CMSIS/Device/ST/STM32L1xx/Include

# Default to STM32L1XX_MD if no device is passed
ifeq ($(DEVICE_DEF), )
DEVICE_DEF = STM32L1XX_MD
endif

CFLAGS += -D$(DEVICE_DEF)

# Sources
SRCS = misc.c \
	stm32l1xx_i2c.c \
	stm32l1xx_adc.c \
	stm32l1xx_iwdg.c \
	stm32l1xx_aes.c \
	stm32l1xx_lcd.c \
	stm32l1xx_aes_util.c \
	stm32l1xx_opamp.c \
	stm32l1xx_comp.c \
	stm32l1xx_pwr.c \
	stm32l1xx_crc.c \
	stm32l1xx_rcc.c \
	stm32l1xx_dac.c \
	stm32l1xx_rtc.c \
	stm32l1xx_dbgmcu.c \
	stm32l1xx_sdio.c \
	stm32l1xx_dma.c \
	stm32l1xx_spi.c \
	stm32l1xx_exti.c \
	stm32l1xx_syscfg.c \
	stm32l1xx_flash.c \
	stm32l1xx_tim.c \
	stm32l1xx_flash_ramfunc.c \
	stm32l1xx_usart.c \
	stm32l1xx_fsmc.c \
	stm32l1xx_wwdg.c \
	stm32l1xx_gpio.c


OBJS = $(SRCS:.c=.o)
LIBNAME = libstdperiph.a

all: $(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBNAME): $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) $(LIBNAME)
	