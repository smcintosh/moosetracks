.DELETE_ON_ERROR:

ifeq ($(BUILD_ARCH),)
$(error "Build arch was not specified. Source the setenv.build script prior to make.")
endif

ifeq ($(SRCTOP),)
$(error "Source directory was not specified. Source the setenv.build script prior to make.")
endif

OUTPUT_TOP = _$(BUILD_ARCH)

include $(SRCTOP)/make/configs/$(BUILD_ARCH).mk

MTRACKS_VERSION = 0.1

.PHONY: default
default: all

ifeq ($(MAKELEVEL),0)

%: | $(OUTPUT_TOP)
	$(MAKE) -C $(OUTPUT_TOP) --no-print-directory \
		-f $(SRCTOP)/makefile $(MAKECMDGOALS)

_$(BUILD_ARCH):
	$(MKDIR) -p _$(BUILD_ARCH)

.PHONY: clean
clean:
	$(RM) -rf _$(BUILD_ARCH)

else

VPATH = $(SRCTOP)

include $(SRCTOP)/make/flags.mk
include $(SRCTOP)/make/rules.mk

include $(SRCTOP)/local.mk
include $(SRCTOP)/make/targets.mk

endif

Makefile: ;
%.mk: ;
%.d: ;
