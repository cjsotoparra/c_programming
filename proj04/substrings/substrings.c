#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*
* File: substrings
* Author: Christian Soto
* Purpose: The purpose of this program is to find th substring of a master string
*/

/*
*  Function: findsubstring
*  Arguments: char s[], char temp[], int len, int len2
*  Assumptions: there is a string s and a string temp as well as none negative inegters len and len2
*  Purpose:  The purpose of  find substring is too find the substring (temp) within a master string (s).
*            
*/

int findsubstring( char s[], char temp[], int len, int len2){

	//declare index and character variables
	int i=0;
	int j=0;
	char ch;
	char ch2;

	//the substring cannot be larger than the master string, return -1 it is
	if(len2>len){
		return -1;
	}//if statment

	//iterate throught he master string in search of the first character in the substring
	for(i= 0; i<=len-len2;i++){

		ch=s[i];
		ch2=temp[0];

		//if statmenet for when the first character was found in the master string
		if(ch==ch2){

			int k =i;
			int d =i;
			//iterate through the substring to see if the rest of the characters are in the master string
			for(j=0; j<len2; j++){

				ch=s[k];
				ch2=temp[j];

				//if one case is not true, then break out of the for loop
				if(ch!=ch2){
					i =d;
					break;
				}//if statment2

				//if len2-1 = j, then we have reached the end of our substring and we return the index i
				if(j==len2-1){

					return i;
				}// if statement 3

				//increment k to get the next integer
				k++;

			}//for loop 2


		}//if statment 1


	}//for loop 1


//return -1 if substring is not found
return -1;
}//find substring

/*
*  Function: main
*  Arguments: none
*  Assumptions: there is a least one master string to work with
*  Purpose:  The purpose of main is to get a master string to work with.  If there is no master string
*	     it prints an error.  The max number of characters the string can be is 120 characters.
*/

int main (){

	//declare master string and len
	char s[121];
	int len=0;

	//read in the master string or print error message if nothing was read or a newline was entered
	if(fgets(s , 121, stdin)== NULL || s[0]=='\n'){
	 fprintf(stderr, "Master string was empty\n");
	 exit(1);
	}

	//remove newline if present
	len =strlen(s)-1;
	if(s[len]=='\n'){
	   s[len] = '\0';
	}


	//declare temp string
	char temp[121];
	int len2=0;

	//read additional lines and compare strings for the substring
	while(fgets(temp, 121, stdin)!=NULL){

		//remove newline if present
		len2 = strlen(temp) -1;
		if(temp[len2]=='\n'){
		   temp[len2]= '\0';
		}

		//find the substring in the master string or return the int value if not found
		printf("%d", findsubstring(s, temp, len, len2));
		printf("\n");


	}//while loop

//return code
return 0;
}//main
