#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct n{
	int tokenC;
	int lineC;
	char **tokens;
	struct n *next;
}node;


/*|Method: tokenize
  |Arugements: char *mystring
  |Purpose: The purpose of this method is return the number of tokens inside a string.
*/

int tokenize(char *mystring, node *newNode, int len){
	char *p = mystring;
	int i;
	int tokenC=0;

	//iterate through the line and count the tokens
	for(i=0; i<strlen(mystring);i++){

		//look for whitespace first and then tokenize the string
		if(isspace(p[i])){

		//	ptr[i]='\0';
		}else {

			tokenC++;
			while(i<strlen(mystring) && !isspace(p[i])){
				i++;
			}//while loop
		}

	}//for loop

	//if string length is zero then set tokenc to 0
	if(strlen(mystring)==0){
	tokenC=0;
	}

	//insert null characters into the string
	for(i=0; i< len; i++){

		if(isspace(p[i])){
			p[i]='\0';
		}//if statement
	}//for loop

	//set newNode->tokenC to token count
	newNode->tokenC= tokenC;

        i=0;
        int index = 0;

	//malloc space for array tokens at tokenC-1
	int sz = newNode->tokenC - 1;
        newNode->tokens= malloc(sizeof(sz));

        while(i < len){

                if((p[i]!='\0')){

                newNode->tokens[index]=p+i;
                index++;

                        while(i<len && p[i]!='\0'){
                                i++;
                        }//while loop

                }else{

                        while(i<len && p[i]=='\0'){
                                i++;
                        }//while loop

                }//if e;se statement

        }//while loop

return 1;

}


/* Method: print
   Argurments: node * hd;
   Purpose:  the purpose is to print the list
*/

void print(node *hd){
	node *pt;
	pt = hd;
	int i=0;

	//first while goes though the list
	while(pt!=NULL){
		i=0;
		//second while loop goes through the array
		printf("Line=%d Tokens: %d\n", pt->lineC, pt->tokenC);
		while(i< pt->tokenC){

			printf("  Line=%d Token:%d:", pt->lineC, i);
			printf(" \"%s\"\n", pt->tokens[i]);
			i++;
		}
	pt= pt->next;
	}



}//print

int main (){

	size_t n;
	char *line = NULL;
	node *hd, dummy;
	hd = &dummy;
	dummy.next= NULL;
	hd=NULL;
	int lines=0;
	int tokens=0;

	while(getline(&line, &n, stdin)>0){

		int len = strlen(line);

		//create pointer node and newNode 
		node *newNode, *ptr;

		//create node and error check
		newNode = malloc(sizeof(node));
		if(newNode ==NULL){
			fprintf(stderr,"out of memory\n");
			exit(1);
		}

		//if the head node is empty then newNode is hd
		if(hd==NULL){
			hd = newNode;
			newNode->lineC=lines;
		}else{

		//go find the next node where you can insert
		ptr = hd;
                	while(ptr->next != NULL){
                		ptr=ptr->next;
                	}

		ptr->next = newNode;
		newNode->lineC=lines;
		}

		//read the line and insert token and the count of tokens
		tokenize(line, newNode, len);

		//insert tokens and tokens count
		//insertTokens(line, newNode, newNode->tokenC, len);
		lines++;
		tokens= tokens+newNode->tokenC;

		line=NULL;
	}

	printf("Lines=%d Tokens=%d\n", lines, tokens);
	print(hd);
return 0;
}

