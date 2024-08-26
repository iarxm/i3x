
#SRC=src/*
DSTDIR=
PREFIX=/usr/local/

all:
	@echo "use 'make install'"

install:
	mkdir -p ${DSTDIR}${PREFIX}
	install -m 755 i3s i3scratch i3spy i3ws i3cbar ixx ${DSTDIR}${PREFIX}/bin

