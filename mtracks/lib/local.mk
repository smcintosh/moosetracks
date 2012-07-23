INCLUDEDIRS_mtracks/lib += \
	$(SRCTOP)/mtracks/h

libutil_SRCS = \
	mtracks/lib/xmalloc.c \
	mtracks/lib/xcalloc.c

libutil_OBJS = $(libutil_SRCS:.c=$O)

mtracks/lib/libutil$A: $(libutil_OBJS)

.PHONY: libutil
libutil: mtracks/lib/libutil$A

-include $(libutil_SRCS:.c=.d)
