#
# Flags are determined by the compiler name
#
COMPILER_NAME := $(notdir $(CC))

################################################################################
# C preprocessor flags
################################################################################
INCLUDEDIRS = \
	$(INCLUDEDIRS_$(@D))

CPPFLAGS += \
	$(addprefix -I,$(INCLUDEDIRS)) \
	$(CPPFLAGS_$(@D))

################################################################################
# C compile flags
################################################################################

# Debug flags
ifeq ($(DEBUG_ftr),on)
DEBUG_CFLAGS_gcc = -g
endif

# Optimization flags
ifeq ($(OPTIMIZATION_ftr),on)
OPTIM_CFLAGS_gcc = -O3
endif

# Automatic dependency generation flags 
ifeq ($(AUTODEPS_ftr),on)
AUTODEPS_CFLAGS_gcc = -MMD
endif

# Warnings
#WARN_CFLAGS_gcc = -Werror -Wall -Wextra

CFLAGS += \
	$(WARN_CFLAGS_$(COMPILER_NAME)) \
	$(DEBUG_CFLAGS_$(COMPILER_NAME)) \
	$(OPTIM_CFLAGS_$(COMPILER_NAME)) \
	$(AUTODEPS_CFLAGS_$(COMPILER_NAME)) \
	$(CFLAGS_$(@D))

################################################################################
# Archiver flags
################################################################################
ARFLAGS = \
	$(ARFLAGS_$(@D))

################################################################################
# Linker flags
################################################################################
LDFLAGS += \
	$(LDFLAGS_$(@D))
LDLIBS += \
	$(LDLIBS_$(@D))
