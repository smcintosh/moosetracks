mtracks_CFILES = \
	mtracks/bin/mtracks.c

mtracks_OBJS = $(mtracks_CFILES:.c=$O)

mtracks/bin/mtracks: $(mtracks_OBJS)

.PHONY: mtracks
mtracks: mtracks/bin/mtracks

-include $(mtracks_CFILES:.c=.d)
