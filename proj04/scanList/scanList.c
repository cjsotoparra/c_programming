#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
* File: scanList.c
* Author: Christian Soto
* Purpose: The purpose of this program is to create an array and populate it, and then ask
*          the user for integers.  Then it will take the integers and scan the array for 
*	   how many times that integer shows up and print that number.
*/


/*
*  Function: scan
*  Arguments: int sz, int iarr[], int el
*  Assumptions: the ize is above 0
*  Purpose:  The purpose of scan is iterate through the array and count how many time
*            el shows up in the array.
*/

void scan(int sz, int iarr[], int el){

	//create and declare index and count variavle
	int i;
	int count=0;

	//scan the list for el and return the count
	for(i = 0; i<sz; i++){

		//check if the elements are equal, if they are increment count
		if(el==iarr[i]){
			count++;
		}
	}

	//print the count
	printf("Number: %d count=%d\n", el, count);

}//scan

/*
*  Function: read
*  Arguments: int sz, int iarr []
*  Assumptions: the size is above 0
*  Purpose:  The purpose of read is read from scanf and populate the array.
*/

void read(int sz, int iarr[]){

	int i;
	int rc;

	//intialize the array
	for(i=0; i < sz; i++){
		rc = scanf("%d", &(iarr[i]));

		//check the return value from scanf
		if(rc<1){
			fprintf(stderr, "ERROR: Could not read element 0 into the array. rc=%d\n", rc);
			exit(1);
		}
	}

	//after intializing, print out the elemtents of the array

	printf("Comparison array (%d elements):", sz);
	for(i=0; i < sz; i++){

		printf(" %d", iarr[i]);
	}

	printf("\n");

}//read


/*
*  Function: main
*  Arguments: none
*  Assumptions: the size is above 0, and that there were no chacartter inputted into scanf
*  Purpose:  The purpose of main is to read in the size of the array, malloc memory for it
*            and populate it.  After that it will scan again to see how many times and interger
*            shows up in the array and print that number.
*/

int main (){

	//declare our return values, size, and elements variavbles that we will be using
	int sz;
	int ret;
	int elements;
	int el;
	int ret2;
	int ret3;

	//scan for the size of the array
	ret=scanf("%d", &sz);

	//check the return value and print an error if the wrong value was put in or nothing was put in
	 if(ret==0 || ret==EOF){
                fprintf(stderr, "Error: Could not read the array-size input.  rc=%d\n", ret);
                exit(1);
         }

	//print error message when the size is negative
	if(sz<0){
		fprintf(stderr, "ERROR: The array-length parameter is negative.  arrLen=%d\n", sz);
		exit(1);
	}

	//if there is no size then there is no need for an array and we can do all of our calculations
	if(sz==0){

		//print the text of an empty array
		printf("Comparison array (%d elements):\n", sz);

		//do all of our calcutlations which will be 0
		while((ret2=scanf("%d", &elements))>0){

			printf("Number: %d count=0\n", elements);
		}//while loop


		//if the return value is 0, then print an error
		 if(ret2==0){
			fprintf(stderr, "Error: Could not read one of the search elements from stdin.\n");
                        exit(1);

		 }//if statement

	}//if statment 3


	//create and malloc the size of the array of sz elements
	int *iarr= malloc(sz*sizeof(int));

	//check the return value
	if(iarr==NULL){
		fprintf(stderr, "Out of memory!\n");
		exit(1);
	}

	//read in the intgers into the array and print out array elements
	read(sz, iarr);

	//scan the elements and print out the times it shows up in the array
	while((ret3=scanf("%d", &el))>0){


		scan(sz, iarr, el);

	}//while loop

	//check the return value of scanf again
	if(ret3==0){
		fprintf(stderr, "ERROR: could not read one of the search elements from stdin\n");
		exit(1);

	}
//return 0
return 0;
}//main
