/*
* File: collatz.c
* Author: Christian Soto
* Purpose: The purpose of this program is to run the recursive funtion of Collatz Conjecture.
*          Instead of running an infinte loop for when the number is reached, we will stop
*          we stop until we reach a number which is less than or equal to the starting number
*/


#include <stdio.h>
#include <stdlib.h>

/*
* Method: con
* Arguments: int i, int j
* Assumptions: The method assumes that both arguements are both positive natural numbers
*	       that are greater than 1.
* Purpose:  The purpose of this method is to take in two integers i and j and set i as the starting point
*           and j as the ending point.  It will then go into the while loop and run the the recursive funtion
*           3i+1 for when it is odd and i/2 for when it is even.  If i is equal to or less j.  1 is going to be
*           our base case because it will then become an infinite loop.  With each iteration, it will print out
*           a number that is greater than J or unitl it reaches 1, in which case we just print out the string
*           and return.
*/

void con (int i, int j){

	//Enter iteration until i is greater than or equal to j or i is 1.
	while(i>=j){

		//base case, just print out string and return
		if(i==1){

			printf(" 4 2 1");
			return;
		} //if statement 1

		//Check to see if i is even or odd
		if(i%2==0){

			//this code executes when i is even
			i=i/2;
			printf(" %d", i);

		}else {

			//this code executes when i is odd.
			i=(3*i) + 1;
			printf(" %d", i);
		}//if else statement

	}//while loop

}//con

/*
* Method: main
* Arguments: none.
* Assumptions: The method assumes that the user will input natural numbers above 0.  If not, it will then
*              throw erros and an exit status of 1.
* Purpose:  The purpose of this method is to scan for integers and make sure they are valid.  If they are valid,
*           then it will print out numbers according to collatz conjuncture.  If they are not valid, then the
*           exit status will be 1 and depending on what the user inputted, it will either exit the program or
*           keep scanning.for more integers but the exit status will still be 1.  If no errors are encountered,
*           then the exit status will be 0.
*/

int main (){

 	int res = 0,	// variable to hold the return value of scanf
	    i,		// value of the integer that is inputted by the user.
            j,		// variable to pass into function con
            retValue=0;	// variable to keep track of the exit status

	//iterate until EOF is reached or scanf returns 0.
	while((res=scanf("%d" , &i)) > 0){

		//Error check to see if the integer is greater than 0.
		if(i<=0){

			//if value is less than one then print out error statement to stderr and change the exit status
			fprintf(stderr, "ERROR: The input %d cannot be tested, because it is a non-postive.\n", i);
			retValue=1;

		} else{

			//else inetger is valid then run the function con and print out the numbers of collatz conjunture
			printf("%d:", i);
			j=i;
			con(i, j);
			printf("\n");

		}// if else statement

	}// while loop

	//error check to see if scanf returned 0 because something other than an integer was entered
	if(res==0){

		//print out error statement to stderr and exit the program with exit status 1.
		fprintf(stderr,"ERROR: An element on the input stream is not an integer.\n");
		exit(1);
	}//error checking

//return the value of the exit status.
return retValue;

}//main
