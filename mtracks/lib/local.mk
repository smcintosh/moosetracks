INCLUDEDIRS_mtracks/lib += \
	$(SRCTOP)/mtracks/h

libutil_SRCS = \
	mtracks/lib/xmalloc.c \
	mtracks/lib/xstrdup.c \
	mtracks/lib/xcalloc.c

libutil_OBJS = $(libutil_SRCS:.c=$O)

libtracksql_SRCS = \
	mtracks/lib/add_receipt.c \
	mtracks/lib/add_vendor.c \
	mtracks/lib/db_connect.c \
	mtracks/lib/mtracks_sqlite_strerror.c

libtracksql_OBJS = $(libtracksql_SRCS:.c=$O)

mtracks/lib/libutil$A: $(libutil_OBJS)
mtracks/lib/libtracksql$A: $(libtracksql_OBJS)

.PHONY: libutil
libutil: mtracks/lib/libutil$A

.PHONY: libtracksql
libtracksql: mtracks/lib/libtracksql$A

-include $(libutil_SRCS:.c=.d)
-include $(libtracksql_SRCS:.c=.d)
