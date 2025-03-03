
DSTDIR=
PREFIX=/usr/local

all:
	@echo "use 'make install'"

install:
	mkdir -p ${DSTDIR}${PREFIX}
	install -m 755 i3s i3scratch ixx ${DSTDIR}${PREFIX}/bin
	install -m 755 i3sbar-x i3sbar-ws i3sbar-c ${DSTDIR}${PREFIX}/bin

