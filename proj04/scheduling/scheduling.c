#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
* File: scheduling.c
* Author: Christian Soto
* Purpose: The purpose of this program is to print out the number of slots avaible, or size of array, print the max, min
*          and the slots where the max and min show up.  Then it will print the average number, and the numbers insde the
*	   the array.
*/

/*
*  Function: average
*  Arguments: int iarr[], int sz
*  Assumptions: the size is above 0 and there are elements in the array to add together
*  Purpose:  The purpose of average is to add all elements together and then print out the 
*	     the average.
*/

void average(int iarr[], int sz){

	//create average and index vairables
	int i;
	int average= 0;
	float avg;

	//iterate throught the loop and add all elements
	for(i=0; i<sz; i++){

	average+= iarr[i];
	}

	//get the floating number and print it
	 avg = (float)average/sz;
	printf("%.2f\n", avg);

}//average

/*
*  Function: minM
*  Arguments: int iarr[], int sz
*  Assumptions: the size is above 0 and there are elements in the array to add together
*  Purpose:  The purpose of minM is to just find the minimun element it the array and return it.
*/


int minM (int iarr[], int sz){

	//create and declare index and min element. set min to the first element
	int i;
	int min= iarr[0];

	//iterate throught the array to find the min
	for(i=0; i<sz; i++){

		if(min>iarr[i]){
			min=iarr[i];
		}
	}

	//return the min value
	return min;

}//minM

/*
*  Function: findmax
*  Arguments: int iarr[], int sz, int marray, int min
*  Assumptions: the size is above 0 for both arrays
*  Purpose:  The purpose of findmax is to find where the max shows up int the array and print out the slots.
*/


void findmax(int iarr[], int sz, int marray[], int max){

	//create indeces
	int i;
	int j =0;

	//iterate and find where the max occurs in the array
	for(i=0; i<sz; i++){

		//if the max is found, then add the location to marray, and increment j;
		if(max==iarr[i]){

			marray[j]=i;
			j++;
		}//if statement
	}//for loop 1

	//iterate through marray and print it's slots (elements)
	for(i = 0; i<j; i++){

		printf(" %d", marray[i]);

	}//for loop 2

	//print a new line
	printf("\n");

}//findmax

/*
*  Function: findmin
*  Arguments: int iarr[], int sz, int marray, int min
*  Assumptions: the size is above 0 for both arrays
*  Purpose:  The purpose of findmin is to find where the min shows up int the array and print out the slots.
*/


void findmin(int iarr[], int sz, int marray[], int min){

	//Create indexes
	int i;
	int j=0;

	//iterate through the array and find where the location of where min occurs
	for(i=0; i<sz; i++){

		//if min is found, then add the location to marray
		if(min==iarr[i]){

			marray[j]=i;
			j++;
		}//if statement
	}//for loop1

	//print the min slots
	for(i=0; i<j; i++){

		printf(" %d", marray[i]);
	}//for loop 2

	//print a new line
	printf("\n");

}//findmin

/*
*  Function: maxM
*  Arguments: int iarr[], int sz
*  Assumptions: the size is above 0 and there are elements in the array to add together
*  Purpose:  The purpose of maxnM is to just find the maximum element it the array and return it.
*/


int maxM(int iarr[], int sz){

	//create max variable and index
	int i;
	int max;

	//first set max to the first element in the array
	max = iarr[0];
	for(i=0; i<sz; i++){

		//if max is less then the current number in array, then max is set to the number
		if(max<iarr[i]){
			max=iarr[i];
		}//if statement
	}//for loop

	//return the max value
	return max;

}//maxM

/*
*  Function: countSlots
*  Arguments: int iarr[], int sz, intstart, int end
*  Assumptions: the size is above 0 
*  Purpose:  The purpose of countSlots is too populate the array according to how many 
*	     slots are inputted.
*/

void countSlots(int iarr[], int sz, int start, int end){

	//create index i and set to start
	int i;

	//iterate until the end is reached
	for(i=start; i<=end ; i++){

		//increment at the array location
		iarr[i]++;
	}//for loop

}//countSlots

/*
*  Function: intialize
*  Arguments: int iarr[], int sz
*  Assumptions: the size is above 0 for both arrays
*  Purpose:  The purpose of intialize is just intialize the array with 0
*/

void intialize( int sz, int iarr[]){

	int i;

	//intialize array to 0
	for(i=0; i<sz; i++){

	iarr[i]=0;

	}

}//intialize

/*
*  Function: main
*  Arguments: none
*  Assumptions: the size of the array is not negative
*  Purpose:  The purpose of main is too intialize the array with 0, populate accoring to the slots
*	     inputted, and print out all the caluactions.
*/

int main (){

	int sz;
	int ret;

	ret= scanf("%d", &sz);

	if(ret<1){
		fprintf(stderr,"ERROR: Could not read the schedule size from stdin.  rc=%d\n", ret);
		exit(1);
	}

	if(sz<1){
		fprintf(stderr, "ERROR: The schedule size is not valid.  slotCount=%d\n", sz);
		exit(1);
	}

	//if the sz and ret are good values, the we create the array and malloc for size
	int *iarr = malloc (sz*sizeof(int));

	//intailize the array to all 0
	intialize(sz, iarr);

	//scan for the range of slots
	int ret2;
	int rc= 0;
	int start, end;
	while((ret2=scanf("%d %d", &start, &end))>0){

		//error checking for start and end
		if(start>end){
			fprintf(stderr, "ERROR: start > end.  slotCount=%d : start=%d end=%d\n",sz, start, end);
			rc =1;

		} else if(start<0 || end < 0){
			fprintf(stderr,"ERROR: One or both of the endpoints of the current range is invalid.  slotCount=%d : start=%d end=%d\n", sz, start, end);
			rc =1;
		} else if(start>= sz || end>=sz){
			fprintf(stderr, "ERROR: One or both of the endpoints of the current range is invalid.  slotCount=%d : start=%d end=%d\n", sz, start, end);
			rc = 1;
		}else {

			countSlots(iarr, sz, start, end);

		}//else if statment
	}


	//check the return value of ret2
	if(ret2==0){
		fprintf(stderr, "ERROR: Could not read the next range.  rc=%d\n", ret2);
		exit(1);
	}

	//create an array to store min and max slots, and min and max values
	int *marray = malloc(sz*sizeof(int));
	int min = minM(iarr, sz);
	int max = maxM(iarr, sz);

	//iterate and print the array first
	printf("%d:", sz);
	int k;
	for(k=0; k<sz; k++){

		printf(" %d", iarr[k]);

	}//for loop for printint array iarr

	//print the rest of the results
	printf("\n");
	printf("minimum: %d\n", min);
	printf("minimum-slots:");
	findmin(iarr, sz, marray, min);
	printf("maximum: %d\n", max);
	printf("maximum-slots:");
	findmax(iarr, sz, marray, max);
	printf("average: ");
	average(iarr, sz);

//return the return code
return rc;

}//main
