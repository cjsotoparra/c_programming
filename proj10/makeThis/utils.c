/*
 * File:   utils.c
 * Author: Christian Soto
 *
 * Purpose: Implements code to search through a set of files (representing
 * makefile) to find certain interesting targets and dependents.
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"



/* addTarget()
 *
 * Input:  The old Big List, and two integers to add.
 * Output: The updated Big List
 *
 * This might require that we allocate a new node into the Big List (or maybe
 * it might not); it might also require that we allocate a new node to the
 * Little List (or it might not).
 *
 * This returns NULL if there is a memory error; it will also clean up the
 * entire list if this happens.
 */
target *addTarget(target *list, char *targetName, int targetFlag){
	target  *cur   =  list;
	target **pPrev = &list;

	while (cur != NULL && strcmp(cur->targetName, targetName)!=0)
	{
		pPrev = &cur->next;
		cur   =  cur->next;
	}


	if(cur !=NULL && strcmp(cur->targetName, targetName)==0){
		if(cur->targetFlag==1 && targetFlag==1){
			fprintf(stderr,"Duplicate Targets\n");
			exit(1);
		}

		if(cur->targetFlag==0 && targetFlag==1){
			cur->targetFlag=1;
		}

	}else{

		target *newNode = malloc(sizeof(target));
		 if (newNode == NULL){
                        freeList(list);
                        return NULL;
                }

		newNode->targetName=strdup(targetName);
		if(newNode->targetName==NULL){
			free(newNode);
			freeList(list);
			return NULL;
		}

		newNode->deps=NULL;
		newNode->commands=NULL;
		newNode->visitedFlag=0;
        	newNode->primaryFlag=0;
        	newNode->targetFlag=targetFlag;

		newNode->next=cur;
		*pPrev = newNode;
	}
	return list;
}



/* freeList()
 *
 * Input:  The current list (which might be NULL)
 *
 * Frees all of the nodes (both Big and Little) in the current list.
 */
void freeList(target *list){
	return;
}

void addDep(target *head,char *targetName, char *depName){
        target  *cur  =  head;
	target  *cur3 = head;
	dep *cur2 = NULL;
	dep *prev2=NULL;
        while (cur != NULL && strcmp(cur->targetName, targetName) != 0){
                cur =  cur->next;

        }

	while (cur3 != NULL && strcmp(cur3->targetName, depName) != 0){

	        cur3 =  cur3->next;
        }


        /* allocate the node; fill in its fields; then add it to the list */
        dep *newNode = malloc(sizeof(dep));
        if (newNode == NULL)
        {
                perror("Failed to allocate a new node for the linked list");
                exit(1);
        }

	cur2 = cur->deps;
	prev2 = cur2;

	while(cur2!=NULL){
		prev2 = cur2;
		cur2=cur2->next;
	}

	newNode->dTarget= cur3;
	newNode->next = NULL;
	if(prev2==NULL){
		cur->deps = newNode;
	}else{
		prev2->next = newNode;
                cur =  cur->next;

        }


}

void addCommand(target *head, char *targetName, char *commandStr){
	target  *cur  =  head;
        command *cur2 = NULL;
        command *prev2=NULL;

        while (cur != NULL && strcmp(cur->targetName, targetName) != 0){
                cur =  cur->next;

        }

	cur2 = cur->commands;
	prev2 = cur2;
	while (cur2 != NULL){
		prev2 = cur2;
		cur2 = cur2->next;
        }

	command *newNode = malloc(sizeof(command));
	if(newNode==NULL){
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}
	newNode->next = NULL;
	newNode->theCommand = strdup(commandStr);
	if(newNode->theCommand==NULL){
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}

	if(prev2==NULL){
		cur->commands=newNode;
	}else{
		prev2->next=newNode;
	}

}

void printList(target *head){
        target *cur=NULL;
        dep *cur2=NULL;
	command *cur3=NULL;


//         now, start over from the beginning, and print out all of the
  //       elements.

        cur = head;
        while (cur != NULL)
        {
                // leading space *BEFORE* each element!
                printf("%s :", cur->targetName);
                cur2 = cur->deps;
                while(cur2 != NULL){
                        printf(" %s", cur2->dTarget->targetName);
                        cur2 = cur2->next;

                }
		printf("\n");
		cur3= cur->commands;
		while(cur3 != NULL){
                        printf("\t%s\n", cur3->theCommand);
                        cur3 = cur3->next;

                }

                cur = cur->next;
        }

        return;
}

char *trimwhitespace(char *str){
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

void postOrderTraverse(target *t){

        dep *cur2 = NULL;
        command *cur3=NULL;

        cur2 = t->deps;
        while(cur2!=NULL){
        	if(cur2->dTarget->visitedFlag ==0){
			postOrderTraverse(cur2->dTarget);
		}
                cur2 = cur2->next;
        }

	if(t->visitedFlag ==0){
        	printf("%s\n", t->targetName);

        	cur3 = t->commands;
        	while(cur3!=NULL){
                	printf("  %s\n", cur3->theCommand);
                	cur3 = cur3->next;
       	 	}
	}

	t->visitedFlag=1;

}

void postOrder(target *head, char *targetName){

	target *cur = head;
	dep *cur2 = NULL;
	command *cur3=NULL;

	while(cur !=NULL && strcmp(cur->targetName, targetName)!=0){
		cur = cur->next;
	}

	if(cur==NULL){
		fprintf(stderr,"Target not in the list\n");
		return;
	}

	cur2 = cur->deps;
	while(cur2!=NULL){
		postOrderTraverse(cur2->dTarget);
		cur2 = cur2->next;
	}

	printf("%s\n", cur->targetName);

	cur3 = cur->commands;
        while(cur3!=NULL){
		printf("  %s\n", cur3->theCommand);
                cur3 = cur3->next;
        }

}

int countTargets(char *line){
	int i=0;
	int count = 0;
	int inchars = 0;


	while(i < strlen(line) && line[i] !=':'){

		if(inchars==0 && !isspace(line[i])){

			inchars=1;
			count++;
		}

		if(inchars==1 && isspace(line[i])){

			inchars=0;
		}
		i++;
	}
	return count;
}
