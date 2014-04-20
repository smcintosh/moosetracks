#
# Build configuration for Darwin
#

################################################################################
# Tools
################################################################################

MKDIR = /bin/mkdir
RM = /bin/rm
TOUCH = /usr/bin/touch
CC = /usr/bin/gcc
LD = $(CC)
AR = /usr/bin/ar
override ARFLAGS = rcs
SQLITE_LIB_PATH = $(SQLITE_PATH)/lib64

################################################################################
# File extensions
################################################################################

D = .so

################################################################################
# Features
################################################################################
AUTODEPS_ftr = on
DEBUG_ftr = on
FTR_optimization = off

# Common UNIX settings
include $(SRCTOP)/make/configs/unix.mk
