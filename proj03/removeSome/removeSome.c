#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
* File: removeSome.c
* Author: Christian Soto
* Purpose: The purpose of this program is to first deteremine whether or not the string that was put in
*	   is a string of letters or numbers, but not both.  If it is a string letters, then it will
*	   print the same string but with the vowels (a,e,i,o,u) removed.  If it is a string of numbers
*	   then it will print the numbers in reverse order and without any evens. If there is an error,
*	   then the exit status will be changed to 1, otherwise it will be 0.
*/

/*
*  Function: noEvens
*  Arguments: char s[], int length
*  Assumptions: this method assumes that the string is numbers only
*  Purpose:  The purpose of this method is too print the numbers in reverse order and with all the even
*	     numbers taken out.  Doubles will not be counted as numbers.
*/

void noEvens( char s[], int length){

	char ch; //create character variable
        int i; //create index variable

	 //iterate through the string in reverse order and print only odds
        for(i = length; i>=0; i--){

                ch = s[i]; //set ch to character at i;

                //check to see is the character is an even, if not then print it
                if(ch%2==0){

                }else{
			printf("%c", ch);
                }

        }//for loop

        printf("\n");

}//noEvens

/*
*  Function: noVowels
*  Arguments: char s[], int length
*  Assumptions: this method assumes that the string is letters only between a and Z
*  Purpose:  The purpose of this method is to print all the letters but without any vowels(a, e, i, o, u).
*/

void noVowels( char s[], int length){

	char ch; //create character variable
	int i; //create index variable

	//iterate through the string and print only letters that are not vowels
	for(i = 0; i<length; i++){

		ch = s[i]; //set ch to character at i;

		//check to see is the character is a vowel, if not then print it
		if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){

		}else{
			printf("%c", ch);
		}

	}//for loop

	//print a new line
	printf("\n");

}//noVowels

/*
*  Function: numbersOnly
*  Arguments: char s[], int length
*  Assumptions: none.
*  Purpose:  The purpose of this method is to determine whether the string has numbers only, not inlcuding doubles.
*            if letter is detected then it returns 1, otherwise it returns 0.
*/

int numbersOnly( char s[], int length){

	char ch; //creat character varable
	int i;  //create index variable

	//iterate through all the charcter in the string
	for(i= 0 ; i<length; i++){
		ch=s[i];  //set ch to the character in the string at i;

		//check if ch is a number. if it is not, then return 1
		if(!isdigit(ch)){
			return 1;
		}// if statement

	}//for loop

//return 0 if only numbers were found in the string.
return 0;
}//numbersOnly

/*
*  Function: lettersOnly
*  Arguments: char s[], int length
*  Assumptions: none.
*  Purpose:  The purpose of this method is to determine whether or not the string has only letters.
*	     If something other than a letter is in the string, then it returns 1, else it returns
*            0.
*/

int lettersOnly (char s[], int length){

	char ch;  //create character variable
	int i; //create index variable

	//iterate through all the characters in the string
	for(i = 0; i<length; i++){
		ch = s[i];  //set ch to the character in the string at i

		//check if each ch is a letter, if it is not, then return 1
		if(!isalpha(ch)){
			return 1;
		} //if statement

	}//for loop

// return 0, if only letters were found in the string
return 0;
}//lettersOnly

/*
*  Function: main
*  Arguments: none.
*  Assumptions: none.
*  Purpose:  The purpose of this method is to scan a string. It will then check if the string is letters or numbers only, but not both.
*	     If the string has letters and numbers then the exit status will be 1 and print out an error, but will keep the program
*	     running.
*/

int main (){

	char s[32];  //create string array
	int ret;  //create return value for scanf
	int len;  //create len of string variable
	int retV=0;  //create exit status variable

	//scan for the string input
	while((ret=scanf(" %31s", s) >0)){

		len = strlen(s); //set len to string length

		//check to see if the string is only letters or strings
		//but not both
		lettersOnly(s , len);
		numbersOnly(s, len);

		//check for errors
		if(lettersOnly(s, len)==1 && numbersOnly(s, len)==1){
			fprintf(stderr, "ERROR: The string '%s' does not appear to be either made of entirely letter, or entirely digits\n", s);
			retV=1;
		} //if statement 1

		//if it is only letters, then print the all the letters except the vowels
		if(lettersOnly(s, len)==0 && numbersOnly(s, len)==1){
			noVowels(s, len);
		}// if statement 2

		//if it is only digits, then print only odd ones and in reverse order
		if(lettersOnly(s, len)==1 && numbersOnly(s, len)==0){
                        noEvens(s, len);
		} //if statement 3


	}//while loop

//return the value of the exit status
return retV;
}//main
