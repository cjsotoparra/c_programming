.PHONY: all clean

all: phoneCalls

phoneCalls: phoneCalls.c
	gcc -Wall -g -fprofile-arcs -ftest-coverage phoneCalls.c -o phoneCalls
clean:
	/bin/rm -f phoneCalls
