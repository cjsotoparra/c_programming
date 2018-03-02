.PHONY: all

all: makeThis

makeThis: makeThis.o utils.o
	gcc -Wall -g -fprofile-arcs -ftest-coverage makeThis.o utils.o -o makeThis

%.o: %.c utils.h
	gcc -Wall -g -fprofile-arcs -ftest-coverage -c $*.c -o $@
