
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"

int main (int argc, char *argv[]){

	FILE *fp;
	int status = 0;
	int index = 0;
	size_t n =0;

	if(argc < 1){
		return status;
	}


	//iterate through the arguements
	for(index = 1; index < argc; index++){
		char **lineArray = malloc(16 * sizeof (char*));
		int arraylen = 16;
        	char *sentance = NULL;
        	int lines = 0;

		if(lineArray==NULL){
			fprintf(stderr,"Out of memore\n");
			exit(1);
		}

		fp = fopen(argv[index],"r");

		//error check
		if(fp == NULL){
			fprintf(stderr, "The file '%s' did not exist.\n", argv[index]);
			status =1;
			continue;
		}//if statment for error checking

		//read through the file until the end is rreached
		while(getline(&sentance, &n, fp) > 0){

			int len = strlen(sentance);

			if(sentance[len-1] == '\n'){
				sentance[len-1] = '\0';
			}


			if(lines >= arraylen){

				lineArray=extendArray(lineArray, arraylen, arraylen+100);

				if(lineArray==NULL){
					fprintf(stderr,"Out of memory\n");
					exit(1);
				}

				arraylen= arraylen+100;

			}

			lineArray[lines] = sentance;
			lines++;
			sentance = NULL;
			n=0;
		}//while loop

		//print the number of lines

		sortArray(lineArray, lines);
		printArray(lineArray, lines, argv[index]);
		freeArray(lineArray, lines);

		//close the file for it is not needed any more
		fclose(fp);

	}//for loop


	 return status;

}//main
