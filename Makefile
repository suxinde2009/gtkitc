# Builds gtkitc for demo purposes. Feel free to integrate into your own makefiles for your projects.
# To build just do: make -f gtkitc.mk

# Aliases
BASE = ./base/
RMF = rm -f
GCCWALL = gcc -g -Wall

.PHONY: clean

all:
	$(GCCWALL) main.c $(BASE)sll.c $(BASE)dll.c $(BASE)bt.c -std=c89 -pedantic -o gtkitc

clean:
	$(RMF) gtkitc *.o *~

