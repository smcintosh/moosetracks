mtracks_CFILES = \
	mtracks/bin/mtracks.c \
	mtracks/bin/mtracks_add_receipt.c \
	mtracks/bin/mtracks_cli.c \
	mtracks/bin/mtracks_version.c

mtracks_OBJS = $(mtracks_CFILES:.c=$O)

sql_test_SRCS = \
	mtracks/bin/sql_test.c

sql_test_OBJS = $(sql_test_SRCS:.c=$O)

sql_test_LIBS = \
	mtracks/lib/libtracksql$A \
	mtracks/lib/libutil$A

INCLUDEDIRS_mtracks/bin += \
	$(SRCTOP)/mtracks/h

mtracks/bin/mtracks$E: $(mtracks_OBJS) mtracks/lib/libutil$A

mtracks/bin/sql_test$E: $(sql_test_OBJS) $(sql_test_LIBS)
mtracks/bin/sql_test$E: LDLIBS += -lsqlite3

mtracks/bin/mtracks_version$O: \
	CPPFLAGS += -DMTRACKS_VERSION='"$(MTRACKS_VERSION)"'

.PHONY: mtracks
mtracks: mtracks/bin/mtracks$E

.PHONY: sql_test
sql_test: mtracks/bin/sql_test$E

-include $(mtracks_CFILES:.c=.d)
