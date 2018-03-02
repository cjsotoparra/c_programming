/*
* File: phoneCalls.c
* Author: Christian Soto
* Purpose: creates a linked list within a linked list that contain phone who have called eachother.
*          it also frees the memory after the program is done or exists early.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct y{
	int count;
	struct y *next;
	char phoneNumberY[9];
}nodeY;

typedef struct x{
	struct x *next;
	struct y *callList;
	char phoneNumberX[9];
}nodeX;

nodeX *removeList(nodeX *head);

nodeY *removeCallList(nodeY *head);

nodeX *removeHeadFromList(nodeX *head);

nodeY *removeHeadFromCallList(nodeY *head);

nodeY *insertIntoCallList(nodeY *head, char *phone2)
{
	nodeY  *cur  =  head;
        nodeY  **ptrInPrev = &head;

        while (cur != NULL && strcmp(cur->phoneNumberY, phone2) < 0)
        {
                ptrInPrev = &cur->next;
                cur       =  cur->next;
        }


        /* when we get here, either 'cur' is NULL, or cur->name is greater
         * than or equal to name.  If they are equal, then print an error;
         * if not, then insert *BEFORE* cur.  Note that it's possible that
         * 'cur' might be the head of the list, but that won't matter.
         */
        if (cur != NULL && strcmp(cur->phoneNumberY, phone2) == 0)
        {
                cur->count++;
                return head;
        }


        /* allocate the node; fill in its fields; then add it to the list */
        nodeY *newNode = malloc(sizeof(nodeY));
        if (newNode == NULL)
        {
                perror("Failed to allocate a new node for the linked list");
                exit(1);
        }

        strcpy(newNode->phoneNumberY, phone2);
	newNode->count = 1;
        newNode->next = cur;
        *ptrInPrev = newNode;

        /* if we inserted in the middle, then 'ptrInPrev' was part of a
         * previous node struct, and so the head hasn't changed.  But if
         * we inserted at the head, then 'ptrInPrev' actually pointed at our
         * own 'head' parameter!
         *
         * Either way, 'head' still/now contains the head of the updated list.
         */
        return head;

}


nodeX *insertIntoList(nodeX *head, char *phone, char *phone2){
	/* search for the correct position.  Note the use of a pointer-pointer
	 * here to eliminate the need for special-case code dealing with an
	 * empty list.
	 */

	/* Style Note:
	 * -----------
	 * A pointer-pointer is an unusual but efficient way to implement
	 * this.  Without a pointer-pointer, you have to cover two cases:
	 *      - We need to append to the tail (including the case of
	 *        an empty string)
	 *      - We need to insert *BEFORE* a node
	 *
	 * You thus tend to compare the key value to the key in the *NEXT*
	 * element, which is a little hard to read.  And worse, you have to
	 * insert in two ways: sometimes you modify the head, and sometimes
	 * you don't.
	 *
	 * The pointer-pointer eliminates that problem.  The pointer-pointer
	 * always stores the pointer that we will modify if we insert "here".
	 * When the loop begins, this actually points to the head pointer -
	 * meaning that when we insert, we are modifying the head pointer
	 * directly!  However, as soon as we move into the list, the
	 * pointer-pointer points to a 'next' field *INSIDE* one of the other
	 * structs.
	 *
	 * In general, 'cur' stores the node we're looking at (which could
	 * be NULL), and 'ptrInPrev' points at the pointer *VARIABLE* that
	 * we used to find 'cur'.
	 */

	nodeX  *cur       =  head;
	nodeX **ptrInPrev = &head;

	while (cur != NULL && strcmp(cur->phoneNumberX, phone) < 0)
	{
		ptrInPrev = &cur->next;
		cur       =  cur->next;
	}


	/* when we get here, either 'cur' is NULL, or cur->name is greater
	 * than or equal to name.  If they are equal, then print an error;
	 * if not, then insert *BEFORE* cur.  Note that it's possible that
	 * 'cur' might be the head of the list, but that won't matter.
	 */
	if (cur != NULL && strcmp(cur->phoneNumberX, phone) == 0)
	{
		cur->callList = insertIntoCallList(cur->callList, phone2);
		return head;
	}


	/* allocate the node; fill in its fields; then add it to the list */
	nodeX *newNode = malloc(sizeof(nodeX));
	if (newNode == NULL)
	{
		perror("Failed to allocate a new node for the linked list");
		exit(1);
	}

	strcpy(newNode->phoneNumberX, phone);
	newNode->callList = insertIntoCallList(newNode->callList, phone2);

	newNode->next = cur;
	*ptrInPrev = newNode;

	/* if we inserted in the middle, then 'ptrInPrev' was part of a
	 * previous node struct, and so the head hasn't changed.  But if
	 * we inserted at the head, then 'ptrInPrev' actually pointed at our
	 * own 'head' parameter!
	 *
	 * Either way, 'head' still/now contains the head of the updated list.
	 */
	return head;
}

void printList(nodeX *head){
	nodeX *cur;
	nodeY *cur2;

	/* now, start over from the beginning, and print out all of the
	 * elements.
	 */
	cur = head;
	while (cur != NULL)
	{
		// leading space *BEFORE* each element!
		printf(" %s:", cur->phoneNumberX);
		cur2 = cur->callList;
		while(cur2 != NULL){
			printf(" %s, %d", cur2->phoneNumberY, cur2->count);
			cur2 = cur2->next;
		}

		cur = cur->next;
		printf("\n");
	}

	return;
}




int scanC(char *argV2, char*argV){
	int status = 0;
	int i;
	int len, len2;

	//check the lenght first
	len = strlen(argV);
	len2 = strlen(argV2);

	if(len<8 || len2<8){
		return 1;
	}//if statemetn

	//iterate through the first characters to see if they are digits
	for(i=0; i<2 ; i++){
		if(!isdigit(argV[i]) || !isdigit(argV2[i])){
			return 1;
		}//if statement
	}//for loop

	//look for the hyphen
	if(argV[3] !='-' || argV2[3] != '-'){
		return 1;
	}//if statment

	//look at the rest of the characters to see if they are digits
	for(i=4 ; i<8 ; i++){
		if(!isdigit(argV[i]) || !isdigit(argV[i])){
			return 1;
		}//if statement
	}//for loop
//return the status
return status;
}

int scanList(nodeX *head, char *phone1, char *phone2){

	nodeX *cur;
        nodeY *cur2;

        /* now, start over from the beginning, and print out all of the
         * elements.
         */
        cur = head;

        while (cur != NULL && strcmp(cur->phoneNumberX, phone1) !=0)
        {

		cur = cur->next;
	}

	if(cur != NULL && strcmp(cur->phoneNumberX, phone1) ==0)
	{
                cur2 = cur->callList;

                while(cur2 != NULL && strcmp(cur2->phoneNumberY, phone2) !=0){

                        cur2 = cur2->next;
                }

                if(cur2 != NULL && strcmp(cur2->phoneNumberY, phone2) ==0){
			return cur2->count;
		}
        }

	return 0;
}

int inDirect(nodeX *head, char *phone1, char *phone2){

	nodeX *cur;
        nodeY *cur2;

        /* now, start over from the beginning, and print out all of the
         * elements.
         */
        cur = head;

        while (cur != NULL && strcmp(cur->phoneNumberX, phone1) !=0)
        {

                cur = cur->next;
        }

        if(cur != NULL && strcmp(cur->phoneNumberX, phone1) ==0)
        {
                cur2 = cur->callList;

                while(cur2 != NULL){

			if(strcmp(cur2->phoneNumberY, phone2) != 0 && scanList(head, phone2, cur2->phoneNumberY)){
				return 1;
			}

                 	cur2 = cur2->next;
		}

        }

	return 0;
}

/* removeHeadFromList(LLNode*)
 *
 * Removes the head node from the list, and frees the memory; returns the new
 * head pointer.  If the list is now empty, this will return NULL.
 *
 * If the list was already empty, then this will print an error to stderr, and
 * set (global) retval to 1; however, it returns an (unmodified) head pointer.
 * Thus, the calling code doesn't have to check the return value for any
 * error condition.
 */
nodeX *removeHeadFromList(nodeX *head)
{

	nodeX *retval = head->next;   // could be NULL

	removeCallList(head->callList);
	free(head);

	return retval;
}

nodeY *removeHeadFromCallList(nodeY *head)
{

        nodeY *retval = head->next;   // could be NULL

        free(head);

        return retval;
}

nodeY *removeCallList(nodeY *head)
{

	while(head != NULL){
		head = removeHeadFromCallList(head);
	}

        return head;
}

nodeX *removeList(nodeX *head)
{

	while( head != NULL){
		head = removeHeadFromList(head);
	}


        return head;
}



int main (int argC, char *argV[]){
	FILE *fp;
	int index;
	int ret;
	int status =0;
	nodeX *head = NULL;

	//Need at least 1 file to begin program and two numbers
	if(argC < 4){
		fprintf(stderr, "Usage: %s file\n", argV[0]);
		exit(1);
	}//if statemtn

	//need two different phone numbers
	if(strcmp(argV[argC-1],argV[argC-2]) ==0){
		fprintf(stderr, "Can't use same numbers\n");
		exit(1);
	}//ifs tatment

	//check to see if both numbers are valid
	ret = scanC(argV[argC-2], argV[argC-1]);
	if(ret==1){
		fprintf(stderr, "Last two numbers not valid\n");
		exit(1);
	}//if statement



	//iterate and open files and read from it
	for(index=1; index<argC-2; index++){

			fp = fopen(argV[index],"r");
			//error check
			if(fp == NULL){
				fprintf(stderr,"Could not open file %s\n", argV[index]);
				status=1;
				continue;
			}//if statment

			//read from file using fcanf

				//char *line = NULL;

				char p2[9];
				char p[9];

				//scan the strings of the file into str array
				while( fscanf(fp, "%8s %8s", p, p2) != EOF){

					//check to see if both numbers are valid again
					ret = scanC( p, p2);
					if(ret==1){
						fprintf(stderr, "one of the numbers is not valid\n");
						exit(1);
					}//if statement

					if(strcmp(p2, p)==0){
						fprintf(stderr, "Two numbers can't call each other\n");
						status =1;
					}//if statement

					//check to see if the list already contains the phonenumbers
					head = insertIntoList(head, p, p2);
					head = insertIntoList(head, p2, p);
				}//while loop 2

			//close the file for it is not needed to be open anymore
			 fclose(fp);
	}//for  looop



//	printList(head);

	printf("%d\n", scanList(head, argV[argC-2], argV[argC-1]));
	int ret2 = inDirect(head, argV[argC-2], argV[argC-1]);

	if(ret2==1){
		printf("yes\n");
	}else{
		printf("no\n");
	}

	head = removeList(head);
	return status;
}
