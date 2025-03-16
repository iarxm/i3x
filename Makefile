PREFIX=/usr/local
BINDIR=$(PREFIX)/bin

all:
	@echo "use 'make install'"

install:
	mkdir -p ${BINDIR}
	install -m 755 i3s i3scratch ixx ${BINDIR}
	install -m 755 i3sbar-x i3sbar-ws i3b ${BINDIR}

