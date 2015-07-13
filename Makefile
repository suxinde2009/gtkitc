# Builds gtkitc for demo purposes. Feel free to integrate into your own makefiles for your projects.

TESTSDIR = testsuite/
INCS = -I inc -I $(TESTSDIR)inc
BASECODE = $(wildcard src/*.c)
TESTCODE = $(wildcard $(TESTSDIR)src/*.c) 
RMF = rm -f
GCCWALL = gcc -g -Wall

.PHONY: clean

all:
	$(GCCWALL) $(INCS) main.c $(BASECODE) $(TESTCODE) -std=c89 -pedantic -o gtkitc

clean:
	$(RMF) gtkitc *.o *~
