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
AR = /usr/bin/libtool
override ARFLAGS = -static -o
SFOUR = 

################################################################################
# File extensions
################################################################################

D = .dylib

################################################################################
# Features
################################################################################
AUTODEPS_ftr = on
DEBUG_ftr = on
FTR_optimization = off

# Common UNIX settings
include $(SRCTOP)/make/configs/unix.mk
