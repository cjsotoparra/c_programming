.PHONY: all clean

all: lineSort 

utility.o: utility.h utility.c
	gcc -Wall -g -fprofile-arcs -ftest-coverage -c utility.c -o utility.o

lineSort.o: primary.c utility.h
	gcc -Wall -g -fprofile-arcs -ftest-coverage -c primary.c -o lineSort.o

lineSort: lineSort.o utility.o
	 gcc -Wall -g -fprofile-arcs -ftest-coverage lineSort.o  utility.o -o lineSort
clean:
	/bin/rm -f *.gcno *.gcov *.o *.out *.gcda

