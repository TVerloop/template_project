#!/bin/make -f

# Set cross compiler to arm none eabi for baremetal arm.
GCC_CROSS_PREFIX = arm-none-eabi-

CXX		= $(GCC_CROSS_PREFIX)g++
CC		= $(GCC_CROSS_PREFIX)gcc
AS		= $(GCC_CROSS_PREFIX)gcc -x assembler-with-cpp
OBJCOPY = $(GCC_CROSS_PREFIX)objcopy
OBJDUMP = $(GCC_CROSS_PREFIX)objdump
SIZE 	= $(GCC_CROSS_PREFIX)size
RM		= rm -f

#------------------------------------------------------------------------------#
# Project name.
#------------------------------------------------------------------------------#

PROJECT_NAME = template_project

#------------------------------------------------------------------------------#
# Linker scripts.
#------------------------------------------------------------------------------#

LD_SCRIPTS =  link/stm32f030x4.ld

#------------------------------------------------------------------------------#
# Object file directory.
#------------------------------------------------------------------------------#

OBJ_DIR = obj

#------------------------------------------------------------------------------#
# Build directory
#------------------------------------------------------------------------------#

BUILD_DIR = build

#------------------------------------------------------------------------------#
# Include directories.
#------------------------------------------------------------------------------#

INC_DIRS =  include

#------------------------------------------------------------------------------#
# Library directories.
#------------------------------------------------------------------------------#

LIBS_DIRS =

#------------------------------------------------------------------------------#
# Libraries.
#------------------------------------------------------------------------------#

LIBS =

#------------------------------------------------------------------------------#
# Source directories.
#------------------------------------------------------------------------------#

SRCS_DIRS =  src

#------------------------------------------------------------------------------#
# C++ Source files.
#------------------------------------------------------------------------------#

CXX_SRCS =  main.cpp

#------------------------------------------------------------------------------#
# C Source files.
#------------------------------------------------------------------------------#

CC_SRCS =  vectors.c
CC_SRCS += startup.c

#------------------------------------------------------------------------------#
# Assembler source files.
#------------------------------------------------------------------------------#

AS_SRCS =

#------------------------------------------------------------------------------#
# Extention for C++ files.
#------------------------------------------------------------------------------#

CXX_EXT = cpp

#------------------------------------------------------------------------------#
# Extention for C files.
#------------------------------------------------------------------------------#

CC_EXT  = c

#------------------------------------------------------------------------------#
# Extention for Assembler files.
#------------------------------------------------------------------------------#

AS_EXT  = asm

#------------------------------------------------------------------------------#
# Flags used by all compilers and linkers.
#------------------------------------------------------------------------------#

CORE_FLAGS =

#------------------------------------------------------------------------------#
# Flags used by C++ compiler.
#------------------------------------------------------------------------------#

CXX_FLAGS =

#------------------------------------------------------------------------------#
# Flags used by C compiler.
#------------------------------------------------------------------------------#

CC_FLAGS =

#------------------------------------------------------------------------------#
# Flags used by Assembler compiler.
#------------------------------------------------------------------------------#

AS_FLAGS =

#------------------------------------------------------------------------------#
# Defines shared between all sources.
#------------------------------------------------------------------------------#

CORE_DEFS =

#------------------------------------------------------------------------------#
# Defines for C++ sources.
#------------------------------------------------------------------------------#

CXX_DEFS =

#------------------------------------------------------------------------------#
# Defines for C sources.
#------------------------------------------------------------------------------#

CC_DEFS =

#------------------------------------------------------------------------------#
# Defines for Assembler sources.
#------------------------------------------------------------------------------#

AS_DEFS =

#------------------------------------------------------------------------------#
# Optimization level
# 0: No optimization
#    https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-O0
# 1: Optimize.
#    https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-O1
# 2: Optimize even more.
#    https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-O2
# 3: Optimize yet more.
#    https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-O3
# s: Optimize for size.
#    https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-Os
# g: Optimize debugging experience.
#    https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-Og
#------------------------------------------------------------------------------#

OPTIMIZATION  = s

#------------------------------------------------------------------------------#
# Use link time optimization.
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-flto
#------------------------------------------------------------------------------#

USE_LTO = TRUE

#------------------------------------------------------------------------------#
# Platform target.
# CORTEX_M0: Build process will be optimized for cortex-m0 targets
# CORTEX_M3: Build process will be optimized for cortex-m3 targets
#------------------------------------------------------------------------------#

PLATFORM = CORTEX_M0

#------------------------------------------------------------------------------#
# Build type.
# DEBUG  : Optimization is not used, debugging info is generated.
# RELEASE: Program will be optimized according to given settings.
#------------------------------------------------------------------------------#

BUILD_TYPE = RELEASE

#------------------------------------------------------------------------------#
# C++ language standard.
#------------------------------------------------------------------------------#

CXX_STD = gnu++17

#------------------------------------------------------------------------------#
# C language standard.
#------------------------------------------------------------------------------#

CC_STD = c11

#------------------------------------------------------------------------------#
# Define variables for storing flags.
#------------------------------------------------------------------------------#

# Store all formated shared flags.
CORE_FLAGS_F =

# Store all formated C++ flags.
CXX_FLAGS_F =

# Store all formated C flags.
CC_FLAGS_F =

# Store all formated Assembler flags.
AS_FLAGS_F =

# Store all formatted Linker flags.
LD_FLAGS_F =

#------------------------------------------------------------------------------#
# Define and format default flags.
#------------------------------------------------------------------------------#

# This enables all the warnings about constructions that some users consider
# questionable.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall
CORE_FLAGS_F += -Wall

# This enables some extra warning flags that are not enabled by -Wall.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wextra
CORE_FLAGS_F += -Wextra

# Turn all warnings into errors.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Werror
CORE_FLAGS_F += -Werror

# Warn about an invalid memory access that is found by Pointer Bounds Checker.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Werror
CORE_FLAGS_F += -Wchkp

# Give a warning when a value of type float is implicitly promoted to double.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wdouble-promotion
CORE_FLAGS_F += -Wdouble-promotion

# Warn if the compiler detects paths that trigger erroneous or undefined
# behavior due to dereferencing a null pointer.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wnull-dereference
CORE_FLAGS_F += -Wnull-dereference

# if there exists a path from the function entry to a use of the variable that
# is initialized, but there exist some other paths for which the variable is not
# initialized, the compiler emits a warning if it cannot prove the uninitialized
# paths are not executed at run time.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wmaybe-uninitialized
CORE_FLAGS_F += -Wno-maybe-uninitialized

# Do not warn whenever a typedef locally defined in a function is not used.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wunused-local-typedefs
CORE_FLAGS_F += -Wno-unused-local-typedefs

# Do not warn whenever a local or static variable is unused aside from its
# decleration.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wunused-variable
CORE_FLAGS_F += -Wno-unused-variable

# Do not warn whenever a static function is declared but not defined or a
# non-inline static function is unused
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wunused-function
CORE_FLAGS_F += -Wno-unused-function

# Place each data item into its own section in the output file if the target
# supports arbitrary sections.
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-fdata-sections
CORE_FLAGS_F += -fdata-sections

# Place each function into its own section in the output file if the target
# supports arbitrary sections.
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-ffunction-sections
CORE_FLAGS_F += -ffunction-sections

# Do not use the standard system startup files when linking.
# https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#index-nostartfiles
CORE_FLAGS_F += -nostartfiles

# Disable generation of information about every class with virtual functions for
# use by the C++ run-time type identification features
# https://gcc.gnu.org/onlinedocs/gcc/C_002b_002b-Dialect-Options.html#index-fno-rtti
CXX_FLAGS_F += -fno-rtti

# Disables exception handling
# https://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html#index-fexceptions
CXX_FLAGS_F += -fno-exceptions

# Attempt to convert calls to virtual functions to direct calls.
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-fdevirtualize
CXX_FLAGS_F += -fdevirtualize

# Add the directory dir to the list of directories to be searched for header
# files during preprocessing.
# https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html#index-I
INC_DIRS_F = $(patsubst %, -I%, $(INC_DIRS) .)

# Add directory dir to the list of directories to be searched for -l.
# https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html#index-L
LIB_DIRS_F = $(patsubst %, -L%, $(LIB_DIRS) .)

# Determine the C++ language standard.
# https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html#index-std=
CXX_FLAGS_F += -std=$(CXX_STD)

# Determine the C language standard.
# https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html#index-std=
CC_FLAGS_F  += -std=$(CC_STD)

# Predefine all specified macros.
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-D
CXX_FLAGS_F += $(pathsubst %, -D%, $(CORE_DEFS) $(CXX_DEFS))
CC_FLAGS_F  += $(pathsubst %, -D%, $(CORE_DEFS) $(CC_DEFS))
AS_FLAGS_F  += $(pathsubst %, -D%, $(CORE_DEFS) $(AS_DEFS))

# output a rule suitable for make describing the dependencies of the main
# source file.
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-MD
CXX_FLAGS_F += -MD
CC_FLAGS_F  += -MD
AS_FLAGS_F  += -MD

# This options instruct CPP to add a phony target for each dependency other than
# the main file.
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-MP
CXX_FLAGS_F += -MP
CC_FLAGS_F  += -MP
AS_FLAGS_F  += -MP

# When used with -M or -MM, specifies a file to write the dependencies to.
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-MF
CXX_FLAGS_F += -MF $(OBJ_DIR_F)$(@F:.o=.d)
CC_FLAGS_F  += -MF $(OBJ_DIR_F)$(@F:.o=.d)
AS_FLAGS_F  += -MF $(OBJ_DIR_F)$(@F:.o=.d)


# Generate for every object file a Assembler listing file.
CXX_FLAGS_F += -Wa,-ahlms=$(OBJ_DIR_F)$(notdir $(<:.$(CXX_EXT)=.lst))
CC_FLAGS_F  += -Wa,-ahlms=$(OBJ_DIR_F)$(notdir $(<:.$(CC_EXT)=.lst))
AS_FLAGS_F  += -Wa,-ahlms=$(OBJ_DIR_F)$(notdir $(<:.$(AS_EXT)=.lst))

LD_FLAGS_F += -Wl,-Map=$(@:.elf=.map)

LD_FLAGS_F += -Wl,--cref

LD_FLAGS_F += -Wl,--no-warn-mismatch


LD_FLAGS_F += -Wl,--gc-sections

# Use script as the linker script. This option is supported by most systems
# using the GNU linker.
# https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#index-T
LD_FLAGS_F += $(patsubst %, -T%, $(LD_SCRIPTS))

#------------------------------------------------------------------------------#
# Cortex-M0 Specific settings.
#------------------------------------------------------------------------------#

ifeq ($(PLATFORM), CORTEX_M0)

# This option specifies the name of the target ARM processor for which GCC
# should tune the performance of the code.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-mtune-3
CORE_FLAGS_F += -mtune=cortex-m0

# This option specifies the name of the target ARM processor for which GCC
# should tune the performance of the code.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-march-1
CORE_FLAGS_F += -march=armv6-m

# Select between generating code that executes in ARM and Thumb states.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-mthumb
CORE_FLAGS_F += -mthumb

PLATFORM_DIR = cortex_m0

endif

#------------------------------------------------------------------------------#
# Cortex-M3 Specific settings.
#------------------------------------------------------------------------------#

ifeq ($(PLATFORM), CORTEX_M3)

# This option specifies the name of the target ARM processor for which GCC
# should tune the performance of the code.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-mtune-3
CORE_FLAGS_F += -mtune=cortex-m3

# This option specifies the name of the target ARM processor for which GCC
# should tune the performance of the code.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-march-1
CORE_FLAGS_F += -march=armv7-m

# Select between generating code that executes in ARM and Thumb states.
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-mthumb
CORE_FLAGS_F += -mthumb

PLATFORM_DIR = cortex_m3

endif

ifeq ($(PLATFORM_DIR), )

$(error "Platform $(PLATFORM) is not valid.")

endif
#------------------------------------------------------------------------------#
# Debug build specific options.
#------------------------------------------------------------------------------#

ifeq ($(BUILD_TYPE), DEBUG)

# Produce debugging information in the operating system’s native format
# https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#index-g
CORE_FLAGS_F += -g

# Produce debugging information for use by GDB.
# https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#index-ggdb
CXX_FLAGS_F += -ggdb
CC_FLAGS_F  += -ggdb
AS_FLAGS_F  += -ggdb

# Optimize debugging experience. -Og enables optimizations that do not interfere
# with debugging.
# https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#index-Og
CXX_FLAGS_F += -Og
CC_FLAGS_F  += -Og
AS_FLAGS_F  += -Og

BUILD_TYPE_DIR = debug

endif

#------------------------------------------------------------------------------#
# Release build specific options.
#------------------------------------------------------------------------------#

ifeq ($(BUILD_TYPE), RELEASE)

ifneq ($(USE_LTO), )

# This option runs the standard link-time optimizer.
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-flto
CORE_FLAGS_F += -flto

endif

# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-O
CXX_FLAGS_F += -O$(OPTIMIZATION)
CC_FLAGS_F  += -O$(OPTIMIZATION)
AS_FLAGS_F  += -O$(OPTIMIZATION)

BUILD_TYPE_DIR = release

endif

ifeq ($(BUILD_TYPE_DIR), )

$(error "Build type $(BUILD_TYPE) is not valid.")

endif

#------------------------------------------------------------------------------#
# Add user defined flags.
#------------------------------------------------------------------------------#

CORE_FLAGS_F += $(CORE_FLAGS)
CXX_FLAGS_F  += $(CORE_FLAGS_F) $(CXX_FLAGS) $(INC_DIRS_F)
CC_FLAGS_F   += $(CORE_FLAGS_F) $(CC_FLAGS) $(INC_DIRS_F)
AS_FLAGS_F   += $(CORE_FLAGS_F) $(AS_FLAGS) $(INC_DIRS_F)
LD_FLAGS_F   += $(CORE_FLAGS_F) $(LD_FLAGS) $(LIB_DIRS_F)

#------------------------------------------------------------------------------#
# Define object files to be generated for all sources.
#------------------------------------------------------------------------------#

# Create object files for all C++ source files.
CXX_OBJS = $(addprefix $(OBJ_DIR_F), $(CXX_SRCS:.$(CXX_EXT)=.o))
# Create object files for all C source files.
CC_OBJS  = $(addprefix $(OBJ_DIR_F), $(CC_SRCS:.$(CC_EXT)=.o))
# Create object files for all Assembler source files.
AS_OBJS  = $(addprefix $(OBJ_DIR_F), $(AS_SRCS:.$(AS_EXT)=.o))

OBJS = $(strip $(CXX_OBJS) $(CC_OBJS) $(AS_OBJS))

#------------------------------------------------------------------------------#
# Auto generated dependency rules which are generated by GCC.
#------------------------------------------------------------------------------#

DEPS = $(OBJS:.o=.d)

#------------------------------------------------------------------------------#
# End result files to be compilled.
#------------------------------------------------------------------------------#

# Target elf file which will be generated.
ELF = $(BUILD_DIR_F)$(PROJECT_NAME)_$(BUILD_TYPE_DIR).elf
# Intel HEX image which might be generated.
HEX = $(BUILD_DIR_F)$(PROJECT_NAME)_$(BUILD_TYPE_DIR).hex
# Binary image which might be generated.
BIN = $(BUILD_DIR_F)$(PROJECT_NAME)_$(BUILD_TYPE_DIR).bin
# Extended listing file which will be generated.
LSS = $(BUILD_DIR_F)$(PROJECT_NAME)_$(BUILD_TYPE_DIR).lss
# Memory DUMP file which will be generted.
DMP = $(BUILD_DIR_F)$(PROJECT_NAME)_$(BUILD_TYPE_DIR).dmp

#------------------------------------------------------------------------------#
# List generated files.
#------------------------------------------------------------------------------#

GENERATED =  $(wildcard $(patsubst %, $(BUILD_DIR_F)*.%, bin d dmp elf hex lss lst map o))
GENERATED += $(wildcard $(patsubst %, $(OBJ_DIR_F)*.%, bin d dmp elf hex lss lst map o))
GENERATED += $(wildcard $(patsubst %, $(BUILD_TYPE_DIR_F)*.%, bin d dmp elf hex lss lst map o))

#------------------------------------------------------------------------------#
# Set virtual search path.
#------------------------------------------------------------------------------#

VPATH = $(SRCS_DIRS)

#------------------------------------------------------------------------------#
# Properly format build directory.
#------------------------------------------------------------------------------#

ifeq ($(strip $(BUILD_DIR)), )
BUILD_DIR_F =
else
BUILD_DIR_F = $(strip $(BUILD_DIR))/
endif


ifeq ($(strip $(BUILD_TYPE_DIR)), )
BUILD_TYPE_DIR_F = $(BUILD_DIR_F)
else
BUILD_TYPE_DIR_F = $(BUILD_DIR_F)$(strip $(BUILD_TYPE_DIR))/
endif

ifeq ($(strip $(OBJ_DIR)), )
OBJ_DIR_F = $(BUILD_TYPE_DIR_F)
else
OBJ_DIR_F = $(BUILD_TYPE_DIR_F)$(strip $(OBJ_DIR))/
endif

#------------------------------------------------------------------------------#
# Dependency rules.
#------------------------------------------------------------------------------#

all: make_output_dir $(ELF) $(HEX) $(BIN) $(LSS) $(DMP) print_size

$(OBJS): $(MAKEFILE_LIST)

$(ELF): $(LD_SCRIPTS)

#------------------------------------------------------------------------------#
# Linking - objects -> elf
#------------------------------------------------------------------------------#

$(ELF) : $(OBJS)
	@echo 'Linking target: $(ELF)'
	$(CXX) $(LD_FLAGS_F) $(OBJS) $(LIBS) -o $@
	@echo ' '

#------------------------------------------------------------------------------#
# Compiling - C++ sources -> objects
#------------------------------------------------------------------------------#

$(OBJ_DIR_F)%.o : %.$(CXX_EXT)
	@echo 'Compiling file: $<'
	$(CXX) -c $(CXX_FLAGS_F) $< -o $@
	@echo ' '

#------------------------------------------------------------------------------#
# Compiling - C sources -> objects
#------------------------------------------------------------------------------#

$(OBJ_DIR_F)%.o : %.$(CC_EXT)
	@echo 'Compiling file: $<'
	$(CC) -c $(CC_FLAGS_F) $< -o $@
	@echo ' '

#------------------------------------------------------------------------------#
# Compiling - ASM sources -> objects
#------------------------------------------------------------------------------#

$(OBJ_DIR_F)%.o : %.$(AS_EXT)
	@echo 'Assembling file: $<'
	$(AS) -c $(AS_FLAGS_F) $< -o $@
	@echo ' '

#------------------------------------------------------------------------------#
# Memory images - elf -> hex, elf -> bin
#------------------------------------------------------------------------------#

$(HEX) : $(ELF)
	@echo 'Creating IHEX image: $(HEX)'
	$(OBJCOPY) -O ihex $< $@
	@echo ' '

$(BIN) : $(ELF)
	@echo 'Creating binary image: $(HEX)'
	$(OBJCOPY) -O binary $< $@
	@echo ' '

#------------------------------------------------------------------------------#
# Extended listing - elf -> lss
#------------------------------------------------------------------------------#

$(LSS) : $(ELF)
	@echo 'Creating extended listing: $(LSS)'
	$(OBJDUMP) -S $< > $@
	@echo ' '

#------------------------------------------------------------------------------#
# Memory dump - elf -> dmp
#------------------------------------------------------------------------------#

$(DMP) : $(ELF)
	@echo 'Creating memory dump: $(DMP)'
	$(OBJDUMP) -x --syms $< > $@
	@echo ' '

#------------------------------------------------------------------------------#
# Print the size of the objects and the .elf file
#------------------------------------------------------------------------------#

print_size :
	@echo 'Size of modules:'
	$(SIZE) -B -t --common $(OBJS)
	@echo ' '
	@echo 'Size of target .elf file:'
	$(SIZE) -B -t --common $(ELF)
	@echo ' '

#------------------------------------------------------------------------------#
# Print the size of the objects and the .elf file
#------------------------------------------------------------------------------#

make_output_dir:
	$(shell mkdir -p $(OBJ_DIR_F) 2>/dev/null)

#------------------------------------------------------------------------------#
# Make clean
#------------------------------------------------------------------------------#

clean :
ifeq ($(strip $(OBJ_DIR_F)), )
	@echo 'Removing all generated output files'
else
	@echo 'Removing all generated output files from output directory: $(BUILD_DIR_F)'
endif
ifneq ($(strip $(GENERATED)), )
	$(RM) $(GENERATED)
else
	@echo 'Nothing to remove...'
endif

#------------------------------------------------------------------------------#
#
#------------------------------------------------------------------------------#

.PHONY: all clean dependents

.SECONDARY:

#------------------------------------------------------------------------------#
# Include dependency rules.
#------------------------------------------------------------------------------#

-include $(DEPS)
