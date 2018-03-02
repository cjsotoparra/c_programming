#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* File: dumpStrings.c
* Author: Christian Soto
* Purpose: The purpose of this program is to print out the index, dec, character, and hexdecimial value
*          of each character in a string of characters
*/

/* 
*  Function: main
*  Arguments: none
*  Assumptions: none.
*  Purpose:  The purpose of main is to scan for characters to out into the
*            string array s, and print out the values.  All hexadeicmals will
*            be in lowercase form.
*/

int main (){

	char s[32]; //create string array
	int ret; //create return value from scanf
	int len;   //index vaiarble
	int count;
	//scan for the string input
	while((ret=scanf(" %31s", s) >0)){
		len = strlen(s);
		int index= 0; //create index variable
		int i; //create iteration loop variable
		char ch; //create char to print information
		count++;

		//iterate through the string
		for(i=0; i<len; i++){
			ch = s[i];
			printf("index=%d ", index);
			printf("char='%c' ", ch);
			printf("dec=%d ", ch);
			printf("hex=0x%02x\n", ch);
			index++;

		}


		printf("count=%d strlen=%d\n", count, len);
		printf("\n");
	}//while loop

//return of exit status
return 0;

}
