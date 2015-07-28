# Builds gtkitc for demo purposes. Feel free to integrate into your own makefiles for your projects.

TESTSDIR = testsuite/
ALGSDIR = algorithms/
COREDIR = corecode/
INCS = -I $(COREDIR)inc -I $(TESTSDIR)inc -I $(ALGSDIR)inc

BASECODE = $(wildcard $(COREDIR)src/*.c)
TESTCODE = $(wildcard $(TESTSDIR)src/*.c)
ALGSCODE = $(wildcard $(ALGSDIR)src/*.c)
ALLSOURCE = $(BASECODE) $(ALGSCODE) $(TESTCODE)

RMF = rm -f
GCCWALL = gcc -g -Wall

.PHONY: clean

all:
	$(GCCWALL) $(INCS) $(ALLSOURCE) -std=c89 -pedantic -o gtkitc

clean:
	$(RMF) gtkitc *.o *~
