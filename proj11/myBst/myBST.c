#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int i;
	struct node *left;
	struct node *right;
}node;

node *create_node(node *newNode){
	node *newNode = malloc(node *);

	if(newNode==NULL){
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}//if statement for error checking

	newNode->i=0;
	newNode->left=NULL;
	newNode->right=NULL;

}

int main (){



	return 0;
}
