###########################################################################
## Makefile for calling other makefiles
###########################################################################

###########################################################################
## MACROS
###########################################################################
###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################
## Toolchain Name:          Arduino ARM


###########################################################################
## TOOLCHAIN MACROS
###########################################################################
# ARDUINO_ROOT = Intrinsically defined
# ARDUINO_PACKAGES_TOOLS_ROOT = Intrinsically defined
# ARDUINO_PORT = Intrinsically defined
# ARDUINO_MCU = Intrinsically defined
# ARDUINO_BAUD = Intrinsically defined
# ARDUINO_PROTOCOL = Intrinsically defined
# ARDUINO_F_CPU = Intrinsically defined
SHELL = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
ARDUINO_TOOLS = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin
SLIB_PATH = C:/Users/TP-EEA/DOCUME~1/MATLAB/R2021a/ArduinoStaticLibrary/ArduinoNano33IoT/FasterRuns


#-------------------------
# Directives/Utilities
#-------------------------
RM                        = 
ECHO                      = echo
MV                        = 


#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM Assembler
AS_PATH := $(ARDUINO_TOOLS)
AS := $(AS_PATH)/arm-none-eabi-gcc

# C Compiler: Arduino ARM C Compiler
CC_PATH := $(ARDUINO_TOOLS)
CC := $(CC_PATH)/arm-none-eabi-gcc

# Linker: Arduino ARM Linker
LD_PATH = $(ARDUINO_TOOLS)
LD := $(LD_PATH)/arm-none-eabi-gcc


# C++ Compiler: Arduino ARM C++ Compiler
CPP_PATH := $(ARDUINO_TOOLS)
CPP := $(CPP_PATH)/arm-none-eabi-g++

# C++ Linker: Arduino ARM C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD := $(CPP_LD_PATH)/arm-none-eabi-gcc

# Archiver: Arduino ARM Archiver
AR_PATH := $(ARDUINO_TOOLS)
AR := $(AR_PATH)/arm-none-eabi-ar

# Indexing: Arduino ARM Ranlib
RANLIB_PATH := $(ARDUINO_TOOLS)
RANLIB := $(RANLIB_PATH)/arm-none-eabi-ranlib

# Execute: Execute
EXECUTE = $(PRODUCT)


# Builder: GMAKE Utility
MAKE_PATH = C:/Program Files/MATLAB/R2021a/bin/win64
MAKE = $(MAKE_PATH)/gmake


#--------------------------------------
# Faster Runs Build Configuration
#--------------------------------------
ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -std=gnu11 \
                       -Os \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP 
CPPFLAGS             = -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions  \
                       -Os \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP 
CPP_LDFLAGS          =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
CPP_SHAREDLIB_LDFLAGS =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =


###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################
#---------------
# C Compiler
#---------------
CFLAGS_SKIPFORSIL = -MMD -mcpu=cortex-m0plus -fpermissive -DF_CPU=48000000L -DARDUINO_SAMD_NANO_33_IOT -DARDUINO_ARCH_SAMD -D__SAMD21G18A__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x8057 -DUSBCON -DUSB_MANUFACTURER=\""Arduino LLC\"" -DUSB_PRODUCT=\""Arduino NANO 33 IoT\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_NANO33_IOT_ -DCRYSTALLESS -DARDUINO_VIRTUAL_COM_PORT -DARDUINO_WIFI_LIB_NINA -DARDUINO_NUM_SERIAL_PORTS=2 -DARDUINO_ARM_CORTEX_M0_PLUS -DARDUINO_ARM
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)
#-----------------
# C++ Compiler
#-----------------
CPPFLAGS_SKIPFORSIL = -MMD -mcpu=cortex-m0plus -fpermissive -DF_CPU=48000000L -DARDUINO_SAMD_NANO_33_IOT -DARDUINO_ARCH_SAMD -D__SAMD21G18A__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x8057 -DUSBCON -DUSB_MANUFACTURER=\""Arduino LLC\"" -DUSB_PRODUCT=\""Arduino NANO 33 IoT\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_NANO33_IOT_ -DCRYSTALLESS -DARDUINO_VIRTUAL_COM_PORT -DARDUINO_WIFI_LIB_NINA -DARDUINO_NUM_SERIAL_PORTS=2 -DARDUINO_ARM_CORTEX_M0_PLUS -DARDUINO_ARM
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)
#---------------
# C++ Linker
#---------------
CPP_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAMD_ROOT)/hardware/samd/$(SAMD_LIB_VERSION)/variants/nano_33_iot/linker_scripts/gcc/flash_with_bootloader.ld --specs=nano.specs --specs=nosys.specs -mcpu=cortex-m0plus -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -L$(ARDUINO_SAMD_ROOT)/tools/CMSIS/$(SAMD_CMSIS_VERSION)/CMSIS/Lib/GCC -l arm_cortexM0l_math
CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)
#------------------------------
# C++ Shared Library Linker
#------------------------------
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAMD_ROOT)/hardware/samd/$(SAMD_LIB_VERSION)/variants/nano_33_iot/linker_scripts/gcc/flash_with_bootloader.ld --specs=nano.specs --specs=nosys.specs -mcpu=cortex-m0plus -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -L$(ARDUINO_SAMD_ROOT)/tools/CMSIS/$(SAMD_CMSIS_VERSION)/CMSIS/Lib/GCC -l arm_cortexM0l_math
CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)
#-----------
# Linker
#-----------
LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAMD_ROOT)/hardware/samd/$(SAMD_LIB_VERSION)/variants/nano_33_iot/linker_scripts/gcc/flash_with_bootloader.ld --specs=nano.specs --specs=nosys.specs -mcpu=cortex-m0plus -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -L$(ARDUINO_SAMD_ROOT)/tools/CMSIS/$(SAMD_CMSIS_VERSION)/CMSIS/Lib/GCC -l arm_cortexM0l_math
LDFLAGS += $(LDFLAGS_SKIPFORSIL)
#--------------------------
# Shared Library Linker
#--------------------------
SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAMD_ROOT)/hardware/samd/$(SAMD_LIB_VERSION)/variants/nano_33_iot/linker_scripts/gcc/flash_with_bootloader.ld --specs=nano.specs --specs=nosys.specs -mcpu=cortex-m0plus -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -L$(ARDUINO_SAMD_ROOT)/tools/CMSIS/$(SAMD_CMSIS_VERSION)/CMSIS/Lib/GCC -l arm_cortexM0l_math
SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)


-include codertarget_assembly_flags.mk


###########################################################################
## Define Macros
###########################################################################
SLMKPATH=C:/PROGRA~3/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/arduinobase/staticmakefiles
MODELMK=tutoSimulinkArduino.mk
SLIB_PATH=C:/Users/TP-EEA/DOCUME~1/MATLAB/R2021a/ArduinoStaticLibrary/ArduinoNano33IoT/FasterRuns
VARIANT_HEADER_PATH=$(ARDUINO_SAMD_ROOT)/hardware/samd/1.8.9/variants/nano_33_iot
ARDUINO_SKETCHBOOK_ROOT=C:/PROGRA~3/MATLAB/SupportPackages/R2021a/aIDE/portable/sketchbook/libraries
ARDUINO_BASESUPPORTPKG_ROOT=C:/PROGRA~3/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/arduinobase
ARDUINO_SAMD_BOARDS=1


###########################################################################
## Export Variables
###########################################################################
export AR
export RANLIB
export AS
export CC
export CPP
export ASFLAGS
export CFLAGS
export CPPFLAGS
export ARFLAGS
export SLIB_PATH
export VARIANT_HEADER_PATH
export ARDUINO_SKETCHBOOK_ROOT
export ARDUINO_BASESUPPORTPKG_ROOT
export ARDUINO_SAMD_BOARDS


###########################################################################
## PHONY TARGETS
###########################################################################
.PHONY : all
all : 
	@echo "### Generating static library."
	"$(MAKE)" -j13 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f wifinina.mk all
	"$(MAKE)" -j13 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f samdcomm.mk all
	"$(MAKE)" -j13 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f samdcore.mk all
	"$(MAKE)" -j13 SHELL="$(SHELL)" -f "$(MODELMK)" all

