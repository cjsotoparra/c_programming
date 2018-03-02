.PHONY: all clean

all: test_arrayFlex_01_allMethods

arrFlex.o: arrFlex.h arrFlex.c
	gcc -Wall -g -fprofile-arcs -ftest-coverage -c arrFlex.c -o arrFlex.o

test_arrayFlex_01_allMethods.o: test_arrayFlex_01_allMethods.c arrFlex.h
	gcc -Wall -g -fprofile-arcs -ftest-coverage -c test_arrayFlex_01_allMethods.c -o test_arrayFlex_01_allMethods.o

test_arrayFlex_01_allMethods: test_arrayFlex_01_allMethods.o arrFlex.o
	gcc -Wall -g -fprofile-arcs -ftest-coverage test_arrayFlex_01_allMethods.o  arrFlex.o -o test_arrayFlex_01_allMethods
	
clean:
	/bin/rm -f *.gcno *.gcov *.o *.out *.gcda test_arrayFlex_01_allMethods

