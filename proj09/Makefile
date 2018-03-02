
FLAGS = -g -fprofile-arcs -ftestcoverage -Wall
tname = test_arrayFlex_
tstSrc = $(wildcard test_array_Flex_*.c)
tstExe = $(tstSrc:.c=)

.PHONY: all clean
all: $(tstExe)

$(tstExe):%  : %.o arrFlex.o
	gcc $(FLAGS) -o $@ $*.o arrFlex.o

%.o: %.c arrFlex.h
	gcc $(FLAGS) -c $<
clean:
	/bin/rm -f *.gcno *.gcov *.o *.out *.gcda
