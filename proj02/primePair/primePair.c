/*
* File: primePair.c
* Author: Christian Soto
* Purpose: The purpose of this program is to print out numbers that have exactly
*          two prime pairs and the prime pairs themselves.
*/

#include <stdio.h>
#include <stdlib.h>

/*
* Method: printFactorsOf
* Arguments: int h
* Assumptions: The method assumes that the arguement has exactly 2 prime factors
* Purpose:  The purpose of this method is similar to that of firstFactor, but with
*           an additional step.  It will find the 2 prime factors and instead of
*           returning the count, it will print the 2 rime factors and not return
*           anything.
*/

void printFactorsOf(int h){

	//set the variable for divisor
	int k =2;

	//iterate through the all the numbers until h is less than 1
	while(h>1){

		//check to see if k divides evenly into h
		if(h%k==0){

			//print the prime factor and change h
			printf(" %d", k);
			h = h/k;
		}else{

			//else just move on to the next divisor
			k++;
		}//else if statement

	}//while loop

	printf("\n");

}//printFactorsOf

/*
* Method: firstFactor
* Arguments: int val
* Assumptions: The method assumes that the int val is at least a natural number
*	       that is equal or greater than 2.
* Purpose:  The purpose of this method is to determine how many prime factors a
*           integer has.  Once it has gone through the algorithm, it wil return
*           the count of prime factors the integer that was passed has.
*/


int firstFactor(int val){

	//set variable for divisor (k) and factor count
	int k = 2;
	int countF = 0;

	//iterate through all the numbers up to but not including val
	while(val>1){

		//check to see if a number divides evenly into val
		if(val%k==0){

			//increment factor count and divide val by divisor
			countF++;
			val = val/k;
		}else{
			k++;
		}//if else statement

	}//while loop

	//return the number of prime factors a number has
	return countF;

}//firstFactor

/*
* Method: main
* Arguments: none.
* Assumptions: The method assumes that both arguements are both positive natura$
*              that are greater than 1.
* Purpose:  The purpose of this method is to take in two integers i and j and s$
*           and j as the ending point.  It will then go into the while loop and$
*           3i+1 for when it is odd and i/2 for when it is even.  If i is equal$
*           our base case because it will then become an infinite loop.  With e$
*           a number that is greater than J or unitl it reaches 1, in which cas$
*           and return.
*/


int main (){

	
	int i,         //This variable will store the first integer from what scanf reads(start)
	    j,	       //This variable will store the second integer fromt what scanf reads(end)
	    res;       //This variable is to store the integer that scanf returns.

	//while loop to read values until a EOF is read or no integers are read
	while((res=scanf(" %d %d", &i, &j)) > 1){

		//Error check to make sure i (start) is not greater than j(end)
		if(i>j){
		 	fprintf(stderr, "ERROR: Start must be <= end\n");
		 	exit(1);
		} // if end is greater than start

		//Error check to make sure i (start) is greater than 2
		if(i<2){
			fprintf(stderr, "ERROR: Start must be >= 2\n");
			exit(1);
		}//if statement

		//If no errors then set h to i (start)
		int h = i;

		//iterate through start and end to find the number of factors for all the numbers
		while(h<=j){

			//check to see if a number has exactly 2 prime factors
			if(firstFactor(h)==2){

				//print prime pair factors of h and then move on to the next number
				printf("%d:", h);
				printFactorsOf(h);
				h++;

			}else {


				//else if a number has more than 2 prime factors or less than, then just move on to next number
				h++;
			}//else if statement

		}//while loop 2

	return 0;
	}//while loop1


	if(res<2){
		fprintf(stderr, "ERROR: Input should be exactly: <start> <end>\n");
		exit(1);
	}//if statement for error checking

return 0;

}
