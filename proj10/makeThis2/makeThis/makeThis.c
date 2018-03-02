/*
 * File:    driver.c
 * Authors: Christian Soto
 *
 * Purpose: The purpose of this file is to act as a main program for the 
 *          makefile reader program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"


int main (int argc, char *argv[]){

	//variables that will be needed
	FILE *fp;
	size_t n =0;
	char *line=NULL;
	char *filename=NULL;
	char *tName=NULL;
	char *targetName=NULL;
	char *commandStr=NULL;
	target *list=NULL;

	//if too many arumenets are given then it is an error and exit the program
	if(argc > 4){
		fprintf(stderr, "Usage: example_makeThis [-f <file>] [target]\n");
		exit(1);
	}

	//variables that will be need for error checking
	int fileN = 0;
	int targetN =1;
	int i;

	//loop thorugh the arguements starting at 1
	for(i=1; i<argc; i++){

		//if the -f flag is found, then incrmenet the fileN
		//to indecate a filename is needed
		if(strcmp(argv[i], "-f")==0){
			fileN =1;
			continue;
		}//if statment

		//if fileN is 1 then wee need to look and open file
		if(fileN==1){
			filename=strdup(argv[i]);

			//error check for strdup
			if(filename==NULL){
				fprintf(stderr, "No memory left\n");
				exit(1);
			}
			//once we get filename, fileN is set to 0
			fileN=0;
			continue;
		}//if statement 2

		if(targetN==1){
			tName = strdup(argv[i]);
			if(tName==NULL){
                                fprintf(stderr, "No memory left\n");
                                exit(1);
			}
			targetN=0;
		}else{

			fprintf(stderr,"Duplicate Targets\n");
			exit(1);
		}//if else
	}

	if(fileN==1){
		fprintf(stderr,"No file given\n");
		exit(1);
	}

	if(filename==NULL){
		filename=strdup("makefileDefault");
		if(filename==NULL){
			fprintf(stderr,"out of Memory\n");
			exit(1);
		}
	}


	fp = fopen(filename, "r");
	if(fp==NULL){
		fprintf(stderr, "The file '%s' did not exist.\n", filename);
		exit(1);
	}//if statement

	while(1){

		line = NULL;
		n = 0;

		if(getline(&line, &n, fp)<0){

			break;
		}

		line[strlen(line)-1]='\0';
		if(line[0]== '\t'){
			commandStr = trimwhitespace(line);

			if(targetName==NULL){
				fprintf(stderr,"Command with no target\n");
				exit(1);
			}else{
				addCommand(list, targetName, commandStr);
			}

		}else{

			line = trimwhitespace(line);

			if(strlen(line)==0){
				continue;
			}

			if (countTargets(line) != 1) {
				fprintf(stderr,"Invalid Target line\n");
				exit(1);
			}
			char * pch;
 			pch = strtok (line, ": \t");

			if(pch == NULL){
				fprintf(stderr,"Error, invalid target line\n");
				exit(1);
			}else{
				targetName = trimwhitespace(pch);

				list=addTarget(list,targetName, 1);
				pch =  strtok(NULL, ": \t");

				while(pch !=NULL){
					list = addTarget(list, pch, 0);
					addDep(list, targetName, pch);
					pch = strtok(NULL, ": \t");
				}
			}


		}
	}

	//printList(list);

	//no targets
	if(tName==NULL){
		if(list!=NULL){
			tName = list->targetName;
		}
	}

	postOrder(list, tName);


	return 0;
}
