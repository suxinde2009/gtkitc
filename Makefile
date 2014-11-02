# Builds gtkitc for demo purposes. Feel free to integrate into your own makefiles for your projects.
# To build just do: make -f gtkitc.mk

# Aliases
BASEDIR = ./base/
TESTSDIR = ./testsuite/
BASECODE = $(BASEDIR)sll.c $(BASEDIR)dll.c $(BASEDIR)bt.c
TESTCODE = $(TESTSDIR)sll_tests.c
RMF = rm -f
GCCWALL = gcc -g -Wall

.PHONY: clean

all:
	$(GCCWALL) main.c $(BASECODE) $(TESTCODE) -std=c89 -pedantic -o gtkitc

clean:
	$(RMF) gtkitc *.o *~

