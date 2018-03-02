/*
 * File:    arrFlex.c
 * Authors: Christian Soto
 *
 * Purpose: The purpose of this file is to
 *         fill in the code for the algorithms of the prototype headers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrFlex.h"

ArrFlex *arrFlex_new(){

	ArrFlex *newArr = malloc(sizeof(ArrFlex));

	//error check
	if(newArr==NULL){
		return NULL;
	}

	newArr->len = 16;
	newArr->str = malloc(newArr->len);
	newArr->elements=0;

	//set all values to null
	memset(newArr->str, '\0', newArr->len);

	//return new arrFlex
	return newArr;
}//arrFlex_new

void arrFlex_free(ArrFlex *obj){

	//create a pointer and free the string
	char *ptr = obj->str;

	//free the pointer
	free(ptr);

	//free the object
	free(obj);

}//arrFlex_free

ArrFlex *arrFlex_clone(ArrFlex *obj){

	//malloc new arrflex
	ArrFlex *newArr = malloc (sizeof(obj));

	//error check
	if(newArr==NULL){
		return NULL;
	}

	//copy all elements into new arrflex obj;
	char *tempStr = malloc(obj->len);
	int i;
	for(i=0; i< obj->elements;i++){
		tempStr[i] = obj->str[i];
	}

	newArr->str = tempStr;
	newArr->len = obj->len;
	newArr->elements = obj->elements;

	//return newArr
	return newArr;
}//clone

void printA(ArrFlex *obj){

	printf("%s\n", obj->str);
	printf("%d\n", obj->elements);
}

int arrFlex_size(ArrFlex *obj){

	return obj->elements;

}//size

int arrFlex_set(ArrFlex *obj, int index, char val){

	//error check to see if the index is valid
	if(index <0 ){
		return -1;
	}

	 if(index > obj->elements){
                return -1;
        }


	//set the new value at the index
	obj->str[index] = val;
	return 0;

}//set


int arrFlex_get(ArrFlex *obj, int index){

	//error check to see if the index is valius
	if(index <0){
                return -1;
        }

	 if(!(index < obj->elements)){
                return -1;
        }


	//return the eleement at index of the struct
	return obj->str[index];


}//get

int arrFlex_add(ArrFlex *obj, char newVal){

	if(obj->elements==obj->len-1){

		//make temp string bigger and set length
		char *tempStr= malloc(obj->len*2);

		//error check
		if(tempStr==NULL){
			return -1;
		}

		//copy all elements from obj->str
		int i;
		for(i=0; i<= obj->len-1 ; i++){
			tempStr[i] = obj->str[i];
		}

		//free current obj->str
		free(obj->str);

		//point obj->str to tempStr
		obj->str = tempStr;

		//add the new value to the string
		obj->str[obj->elements] = newVal;
                obj->elements++;
		return 0;

	}else {
		//just add the element into the string
		obj->str[obj->elements] = newVal;
		obj->elements++;
		return 0;
	}
}//add

int arrFlex_append(ArrFlex *obj, ArrFlex *arrayToAdd){


	//create char pointer and make it the size of both arrays
	char *tempStr = malloc(obj->len + arrayToAdd->len);

	if(tempStr==NULL){
		return -1;
	}

	//copy elements
	memcpy(tempStr, obj->str, obj->elements * sizeof(char));
	printf("%s\n", tempStr);
	//copy all elements from arrayToAdd
	memcpy(tempStr+arrayToAdd->elements+1, arrayToAdd->str, arrayToAdd->elements * sizeof(char));

	printf("%s\n", tempStr);

	//make the obj->str point to tempStr and free old obj->str
	obj->str=tempStr;
	obj->elements = obj->elements+arrayToAdd->elements;
	return 0;

}//append

int arrFlex_insert(ArrFlex *obj, int index, char value){

	//error check to make sure the index is valid
	if(index < 0 ){
		return -1;
	}

	printf("%d\n", obj->elements);
	printf("%d\n", index);

	if(index > obj->elements){
		return -1;
	}


	if(obj->elements==obj->len-1){

		//create new string pointer
		char *tempStr = malloc(obj->len*2);

		//error check
		if(tempStr==NULL){
			return -1;
		}else{

			//copy all elements from obj->str
			int i;
			for(i=0; i< obj->len-1 ; i++){
				tempStr[i]=obj->str[i];
			}

			//now just point new string to obj
			free(obj->str);
			obj->str = tempStr;

			//shift right
			int j;
			for(j=obj->elements-1; j>index; j--){
				obj->str[j+1] = obj->str[j];
			}

			//insert new element at index
			obj->str[index]=value;
			obj->elements++;
			return 0;
		}//if else
	}

	//if index==obj.elemtnets, just call add method
	if(index==obj->elements){
		return arrFlex_add(obj, value);
	}else{

		//shift right
		 int h;
                 for(h=obj->elements-1; h>=index; h--){
                                obj->str[h+1] = obj->str[h];
                 }

                 //insert new element at index and update elements
                  obj->str[index]=value;
		  obj->elements++;
		  return 0;
	}

}//insert

int arrFlex_delete(ArrFlex *obj, int index){

	 //error check to make sure the index is valid
        if(index < 0){
                return -1;
        }

	 if(index > obj->elements){
                return -1;
        }


	//error check for empty array
	if(obj->elements==0){
		return -1;
	}

	//if the last element is being deleted then just make it a null character
	if(index==obj->elements-1){
		obj->str[index]='\0';
		obj->elements--;
		return 0;
	}else{

		//shift elements
		int i;
		for(i=index; i< obj->elements; i++){
			obj->str[i]=obj->str[i+1];
		}

		//delete
		obj->str[obj->elements]='\0';
		obj->elements--;
		return 0;
	}

}//delete

ArrFlex *arrFlex_subArray(ArrFlex *obj, int start, int end){

	//error check index
	if(start<0 || end<start || end > obj->elements){
		return NULL;
	}

	//malloc string and new arrFlex and error check
	ArrFlex *newArr = malloc(sizeof(obj));
	if(newArr==NULL){
		return NULL;
	}

	char *sub = malloc (end-start);
	//error check
	if(sub==NULL){
		return NULL;
	}


	//copy elements
	int i;
	for(i=start ; i<end; i++){

		sub[i] = obj->str[i];
	}

	//point newArr to string
	newArr->str=sub;

	//return new object
	return newArr;
}//subArray

char *arrFlex_toString(ArrFlex *obj){

	char *buff = malloc(obj->elements);
	if(buff==NULL){
		return NULL;
	}

	if(obj->elements==0){
		return buff;
	}

	//copy elements
	int i;
	for(i=0; i< obj->elements; i++){

		buff[i]=obj->str[i];
	}

	//insert '\0' char at the end
	buff[obj->elements]='\0';

	//return the buff
	return buff;


}
