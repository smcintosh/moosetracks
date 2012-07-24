mtracks_CFILES = \
	mtracks/bin/mtracks.c \
	mtracks/bin/mtracks_add_receipt.c \
	mtracks/bin/mtracks_cli.c \
	mtracks/bin/mtracks_version.c

mtracks_OBJS = $(mtracks_CFILES:.c=$O)

INCLUDEDIRS_mtracks/bin += \
	$(SRCTOP)/mtracks/h

mtracks/bin/mtracks: $(mtracks_OBJS) mtracks/lib/libutil$A

mtracks/bin/mtracks_version$O: \
	CPPFLAGS += -DMTRACKS_VERSION='"$(MTRACKS_VERSION)"'

.PHONY: mtracks
mtracks: mtracks/bin/mtracks

-include $(mtracks_CFILES:.c=.d)
