ARDUINO_FOLDER  = /project/arduino-1.5.1

ARM_GCC_PREFIX = $(ARDUINO_FOLDER)/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-
CC = $(ARM_GCC_PREFIX)gcc
CPP = $(ARM_GCC_PREFIX)g++
LD = $(ARM_GCC_PREFIX)ld
AR = $(ARM_GCC_PREFIX)ar
OBJCOPY = $(ARM_GCC_PREFIX)objcopy
OBJDUMP = $(ARM_GCC_PREFIX)objdump
SIZE = $(ARM_GCC_PREFIX)size
BOSSAC = $(ARDUINO_FOLDER)/hardware/tools/bossac

OBJ_FOLDER = build
ARDUINO_OBJ_FOLDER = arduino_build

ARDUINO_SYSTEM_C_FILES = $(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/pio.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/usart.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/uotghs_device.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/twi.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/pmc.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/adc.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/rtt.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/dacc.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/wdt.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/pwmc.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/rtc.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/tc.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/udp.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/spi.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/interrupt_sam_nvic.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/adc12_sam3u.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/udphs.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/uotghs_host.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/uotghs.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/source/timetick.c

ARDUINO_VARIANT_CPP_FILES = $(ARDUINO_FOLDER)/hardware/arduino/sam/variants/arduino_due_x/variant.cpp

ARDUINO_CMSIS_C_FILES = $(ARDUINO_FOLDER)/hardware/arduino/sam/system/CMSIS/Device/ATMEL/sam3xa/source/system_sam3xa.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/system/CMSIS/Device/ATMEL/sam3xa/source/gcc/startup_sam3xa.c

ARDUINO_LIB_CPP_FILES = $(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/cxxabi-compat.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/IPAddress.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/Print.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/Reset.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/RingBuffer.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/Stream.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/UARTClass.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/USARTClass.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/wiring_pulse.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/WMath.cpp \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/WString.cpp

ARDUINO_LIB_C_FILES = $(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/cortex_handlers.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/hooks.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/iar_calls_sam3.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/itoa.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/syscalls_sam3.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/WInterrupts.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/wiring_analog.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/wiring.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/wiring_digital.c \
	$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino/wiring_shift.c

DEFINES = -D__SAM3X8E__ \
          -DF_CPU=84000000 \

INCLUDE = -I$(ARDUINO_FOLDER)/hardware/arduino/sam/cores/arduino \
          -I$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam \
          -I$(ARDUINO_FOLDER)/hardware/arduino/sam/system/libsam/include \
          -I$(ARDUINO_FOLDER)/hardware/arduino/sam/variants/arduino_due_x \
          -I$(ARDUINO_FOLDER)/hardware/arduino/sam/system/CMSIS/CMSIS/Include \
          -I$(ARDUINO_FOLDER)/hardware/arduino/sam/system/CMSIS/Device/ATMEL/include \
	  -I$(ARDUINO_FOLDER)/hardware/arduino/sam/system/CMSIS/Device/ATMEL \
          -I$(ARDUINO_FOLDER)/hardware/arduino/sam/system/CMSIS/Device/ATMEL/sam3xa/include \
          -I.

CFLAGS = -c -g -Os -w -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf
CFLAGS += $(INCLUDE)
CFLAGS += $(DEFINES)
CFLAGS += -mthumb
CFLAGS += -mcpu=cortex-m3

CPPFLAGS = -c -g -Os -w -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf
CPPFLAGS += $(INCLUDE)
CPPFLAGS += $(DEFINES)
CPPFLAGS += -mthumb
CPPFLAGS += -mcpu=cortex-m3

ELF2HEXFLAGS = -O binary

.PHONY: arduino-clean clean upload picocom

all: $(OBJ_FOLDER) $(OBJ_FOLDER)/HelloWorld.bin $(OBJ_FOLDER)/HelloWorld.size

list: $(OBJ_FOLDER)/HelloWorld.list

$(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_system.o : $(ARDUINO_SYSTEM_C_FILES)
	$(foreach CFILE,$(ARDUINO_SYSTEM_C_FILES), \
	$(CC) $(CFLAGS) $(CFILE) -c -o $(addsuffix .o, $(addprefix $(ARDUINO_OBJ_FOLDER)/, $(basename $(notdir $(CFILE))))); \
	)
	touch $@

$(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_cmsis.o : $(ARDUINO_CMSIS_C_FILES)
	$(foreach CFILE,$(ARDUINO_CMSIS_C_FILES), \
	$(CC) $(CFLAGS) $(CFILE) -c -o $(addsuffix .o, $(addprefix $(ARDUINO_OBJ_FOLDER)/, $(basename $(notdir $(CFILE))))); \
	)
	touch $@


$(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_variant.o : $(ARDUINO_VARIANT_CPP_FILES)
	$(foreach CFILE,$(ARDUINO_VARIANT_CPP_FILES), \
	$(CPP) $(CFLAGS) $(CFILE) -c -o $(addsuffix .o, $(addprefix $(ARDUINO_OBJ_FOLDER)/, $(basename $(notdir $(CFILE))))); \
	)
	touch $@

$(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_lib.o : $(ARDUINO_LIB_C_FILES) $(ARDUINO_LIB_CPP_FILES)
	$(foreach CFILE,$(ARDUINO_LIB_C_FILES), \
	$(CC) $(CFLAGS) $(CFILE) -c -o $(addsuffix .o, $(addprefix $(ARDUINO_OBJ_FOLDER)/, $(basename $(notdir $(CFILE))))); \
	)
	$(foreach CFILE,$(ARDUINO_LIB_CPP_FILES), \
	$(CPP) $(CFLAGS) $(CFILE) -c -o $(addsuffix .o, $(addprefix $(ARDUINO_OBJ_FOLDER)/, $(basename $(notdir $(CFILE))))); \
	)
	touch $@

arduino-objects: $(ARDUINO_OBJ_FOLDER) $(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_lib.o $(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_variant.o $(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_cmsis.o $(ARDUINO_OBJ_FOLDER)/fake_targets/arduino_system.o

arduino-clean:
	rm -rf $(ARDUINO_OBJ_FOLDER)
clean: 
	rm -rf $(OBJ_FOLDER)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(ARDUINO_OBJ_FOLDER):
	mkdir -p $(ARDUINO_OBJ_FOLDER)
	mkdir -p $(ARDUINO_OBJ_FOLDER)/fake_targets

$(OBJ_FOLDER)/HelloWorld.o : HelloWorld.cpp
	$(CPP) $(CFLAGS) $< -c -o $@

$(OBJ_FOLDER)/HelloWorld.elf : $(OBJ_FOLDER)/HelloWorld.o
	$(CPP) -Os -Wl,--gc-sections -mcpu=cortex-m3 -T$(ARDUINO_FOLDER)/hardware/arduino/sam/variants/arduino_due_x/linker_scripts/gcc/flash.ld -Wl,-Map,$(OBJ_FOLDER)/HelloWorld.map -o $@ -lm -lgcc -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group $^ $(ARDUINO_OBJ_FOLDER)/*.o -Wl,--end-group

$(OBJ_FOLDER)/HelloWorld.bin : $(OBJ_FOLDER)/HelloWorld.elf
	$(OBJCOPY) $(ELF2HEXFLAGS) $< $@

$(OBJ_FOLDER)/HelloWorld.list: $(OBJ_FOLDER)/HelloWorld.elf
	$(OBJDUMP) -h -S --disassemble --syms --line-numbers $< > $@

$(OBJ_FOLDER)/HelloWorld.size:	$(OBJ_FOLDER)/HelloWorld.elf
	@echo ================================================
	@$(SIZE) -d --totals $<

upload: $(OBJ_FOLDER)/HelloWorld.bin
	$(BOSSAC) -p ttyACM3 -e -w -v -b $<

picocom:
	picocom -b 115200 /dev/ttyACM3
