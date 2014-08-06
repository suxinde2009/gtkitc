# Builds gtkitc for demo purposes. Feel free to integrae into your own makefiles for your projects.
# To build just do: make -f gtkitc.mk

# Aliases
BASE = ./base/
RMF = rm -f
GCCWALL = gcc -Wall

.PHONY: cleanall cleanobj cleanexe

all:
	$(GCCWALL) main.c $(BASE)node.c -o gtkitc

# Phonies
cleanall:
	$(RMF) gtkitc *.o *~

cleanobj:
	$(RMF) gtkitc.o

cleanexe:
	$(RMF) gtkitc
