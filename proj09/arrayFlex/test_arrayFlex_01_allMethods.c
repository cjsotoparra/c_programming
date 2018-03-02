/*
 * File:   test_arrayFlex_01_allMethods.c
 * Author: Christian soto
 *
 * Purpose: the purpose of this file is to call all the methods in the header
 *          file and make sure they are working properly.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrFlex.h"

int main (){

	//test Arrflex methods
	ArrFlex *arr1 = arrFlex_new();

	//test insert and add
	int rc1 = arrFlex_insert(arr1, 0, 'a');
	printf("%d\n", rc1);
	int rc2 = arrFlex_add   (arr1, 'b');
	printf("%d\n", rc2);
	int rc4 = arrFlex_add   (arr1, 'c');
	printf("%d\n", rc4);

	//test clone
	ArrFlex *arr2 = arrFlex_clone(arr1);
	printf("arr1 = %s\n",arr1->str);
	printf("arr2 = %s\n", arr2->str);

	//test size
	 printf("%d\n", arrFlex_size(arr1));
	 arrFlex_insert(arr1, 0, 'A');
	 printf("%d\n", arrFlex_size(arr1));
	 printf("%d\n", arrFlex_size(arr2));

	//test get and set
	int rcS = arrFlex_set(arr1, 6, 't');
	printf("%d\n", rcS);
	int rcS2 = arrFlex_set(arr1, -2, 't');
        printf("%d\n", rcS2);
	int rcS3 = arrFlex_set(arr1, 3, 't');
        printf("%d\n", rcS3);

	int rcG = arrFlex_get(arr1, 6);
        printf("%d\n", rcG);
        int rcG2 = arrFlex_get(arr1, -2);
        printf("%d\n", rcG2);
        int rcG3 = arrFlex_get(arr1, 3);
        printf("%d\n", rcG3);

	//test append
	int app = arrFlex_append(arr1, arr2);
	printf("%d\n", app);

	//test delete
	int del =arrFlex_delete(arr1, -2);
	printf("%d\n", del);
	int del2 =arrFlex_delete(arr1, 8);
        printf("%d\n", del2);

	ArrFlex *arr3 = arrFlex_new();
	int del3 =arrFlex_delete(arr3, 2);
        printf("%d\n", del3);

	int del4 =arrFlex_delete(arr1, 6);
        printf("%d\n", del4);

	int del5 =arrFlex_delete(arr1, 3);
        printf("%d\n", del5);

	//test toString
	arrFlex_toString(arr1);
	arrFlex_toString(arr3);

	//test free
	free(arrFlex_toString(arr1));
	free(arrFlex_toString(arr1));
	free(arr1);
	free(arr2);
	free(arr3);
return 0;
}
