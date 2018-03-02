#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

char **extendArray(char **oldArray, int oldLen, int newLen){

	char **newArray = (char**)calloc(newLen , sizeof(char *));

	if(newArray==NULL){
		return NULL;
	}

	int i;
	for(i=0; i<oldLen; i++){

		newArray[i] = oldArray[i];
	}

	free(oldArray);

	return  newArray;

}

void sortArray(char **array, int len){

	char *ptr;
	int i ,j;

	for(i=0; i<len-1 ; i++){

		for(j=0; j<len-i-1; j++){

			if(strcmp(array[j], array[j+1]) >0){
				ptr = array[j];
				array[j]=array[j+1];
				array[j+1]=ptr;
			}
		}
	}

}

void printArray(char **lineArray, int len, char *str ){

        printf("The file '%s' had %d lines.\n", str, len);

        int i;
        for(i=0; i<len; i++){

                printf("%s\n", lineArray[i]);
        }



}

void freeArray(char **lineArray, int len){

	int i;

	for(i=0; i<len; i++){

		free(lineArray[i]);
	}

	free(lineArray);

}
