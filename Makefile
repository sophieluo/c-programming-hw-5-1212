#########################################################
#  file name   : Makefile                               #
#  author      : Thomas Farmer                          #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################
#
#

all: lc4 lc4_loader

lc4: lc4.c lc4_loader.c
	clang lc4.c lc4_loader.c lc4_memory.c -o lc4

lc4_loader: lc4_loader.c lc4_memory.c
	clang lc4_loader.c lc4.c lc4_memory.c -o lc4_loader

clean:
	rm -rf *.o

clobber: clean
	rm -rf lc4_loader lc_4
