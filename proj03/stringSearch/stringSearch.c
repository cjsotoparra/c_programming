
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*  Function: rev
*  Arguments: char s[], char s2[], int len1, int len2
*  Assumptions: none.
*  Purpose:  The purpose of this method is to see if any of the strings that were passed is the
*	     reverse of the first string input. if it is, then it will print the reverse sting
*            and print 1.  Else it does nothing and return 0.
*/

int rev( char s[], char s2[], int len1, int len2){

	char ch; //create character variable
	char ch2; // create character variable 2
	int i; //index variable

	//first check if the lengths are equal, if they are not, then just return
	if(len1 != len2){
	  return 0;
	}//if statement 1

	//iterate through one string and check the character
	for(i=0; i<len1; i++){

	  //set ch2 to the last value of s2 and ch to the first value of s
	  ch=s2[len2-1];
	  ch2=s[i];

		  //if there is a case where the characters are not the same then just return
		  if(ch!=ch2){
			return 0;
	  	  }//if statement

	  //decrement len2 to get the next value of s2
	  len2--;
	}//for loop

	//if we make it out of the for loop, then we know s2 is the reverse of s, then we can print it
	printf("Rev: %s\n", s2);

	return 1;

}//rev

/*
*  Function: duplicates
*  Arguments: char s[], char s2[], int len2
*  Assumptions: Both strings are the same length
*  Purpose:  The purpose of this method is to see if the last string and the current string are duplicate
*            strings.  if they are, then it will print out the duplicate string and return 1, else it just
*            returns 0.
*/


int duplicates(char s[], char s2[], int len2){

	int len= strlen(s2); //get lenght of new incoming string
	int i; 		    //set index varaiable i
	int j=0;	   //create index variable j
	char ch;	//varaabl character created
	char ch2;	//varaiavle character created


	//first we check if the lengths are equal, if not then return 0
	if(len2!=len){
		return 0;
	}

	//next we do a string comparison again
	for(i= 0; i<len; i++){

		//we now set the variables ch and ch2
		ch=s[i];
		ch2=s2[j];

		//next check if there is ever a case where ch and ch2 are not equal, then just return 0
		if(ch!=ch2){
		  return 0;
		}//if statement

		//increment j for the next value of s2
		j++;

	}//for loop

	//return 1 if no mismatches were found and print
	printf("Dup: %s\n", s);
	return 1;
}//duplicats

/*
*  Function: main
*  Arguments: none.
*  Assumptions: Assumes scanf will read a string
*  Purpose:  The purpose of this method is to first read in a string.  If a no string is inputted, then it will
*	     print an error and exit and return 1.  If it scan something, then it will contunie to read strings
*            with scanf and compare it with the first one for the reverse string, any matches, and duplicates 
*            the first string and between the other strings being read.  After all calculations, it will print
*            out the total of reverse, duplicate, and mataches.
*/

int main (){

	char s[32];  //create  string array for first string
	char s2[32]; //create string array for all others
	char s3[32]; //crete string array to hold information

        int ret;  //create return value for scanf
        int len1;  //create len of string variable length1
	int len2;  //create len2 variable for length2
	int stringC=0; //count the number of strings inputed
	int ret2; //other return value from scanf
	int matchC=0; //variable for match count
	int revC= 0 ; //varaible to keep count of reverses
	int duplC= 0; //variavle to keep count of duplicates
	int counter=0; //a veriable to keep the number of counts

	//scan for the first string
	 ret=scanf(" %31s", s);

	//check if scanf read something
	if(ret==1){
	  len1 = strlen(s);
	}// if statement 1

	//iterate through to scan for the other strings
	while((ret2=scanf(" %31s", s2)>0)){
	  stringC++;
	  len2 = strlen(s2);

		//check to see if the first string and the new string being read are a match and print if they are
		if(strcmp(s, s2)==0){
		  matchC++;
		  printf("Mat: %s\n", s2);
		}// if statement 1

		//check to see if it is the reverse of the string
		if(rev(s, s2, len1, len2)==1){
		  revC++;
		}// if statement 2

		 //check to see if there are any duplicates
                if(counter==0){

                        //check the return value of duplicates
                        if(duplicates(s, s2, len1)==1){
                                duplC++;
                        } //if statement 2
                }//if statement 1

                if(counter>0){

                        //check the return value
                        if(duplicates(s2, s3, len2)==1){
                           duplC++;
                        }//if statement 2
                }//if statement

		//copy the string s2 into s3 because we are not with it yet
		strcpy(s3, s2);

		//increment counter
		counter++;
	  }//while loop

	//check the return value
	if(ret<=0){
	  fprintf(stderr, "Error\n");
	  exit(1);
	}//if statement

//print the final results
printf("Totals: strings=%d : m=%d r=%d d=%d\n", stringC, matchC, revC, duplC);
//printf("%d\n", stringC);
return 0;
}//main
