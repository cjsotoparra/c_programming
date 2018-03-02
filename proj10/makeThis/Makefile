.PHONY: all clean

all: makeThis

utils.o: utils.h utils.c
	 gcc -Wall -g -fprofile-arcs -ftest-coverage -c utils.c -o utils.o

makeThis.o: driver.c utils.h
	gcc -Wall -g -fprofile-arcs -ftest-coverage -c driver.c -o makeThis.o

makeThis: makeThis.o utils.o
	gcc -Wall -g -fprofile-arcs -ftest-coverage makeThis.o utils.o -o makeThis
