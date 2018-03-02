/*
 * File:   utils.c
 * Author: Christian Soto
 *
 * Purpose: Implements code for the header file utils.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
        struct node *right;
        struct node *left;
        int data;
}node;


void search (int data, node *root){

	//create pointer for itetration
        node *curr = root;

        //go all the way to the left in the tree
        while(curr!=NULL){

		//compare values to see where to go
		if(data < curr->data){
                	curr = curr->left;
		}else if(data > curr->data){
			curr = curr->right;
		}else if(data == curr->data){
			printf("%d found\n",curr->data);
			return;
		}
        }//while

	//if the value was not found, return
	printf("%d NOT found\n", data);
	 return;
}//search

int searchHelper(int data, node *root){

        //create pointer for itetration
        node *curr = root;

        //go all the way to the left in the tree
        while(curr!=NULL){

                //compare values to see where to go
                if(data < curr->data){
                        curr = curr->left;
                }else if(data > curr->data){
                        curr = curr->right;
                }else if(data == curr->data){
                        return 0;
                }
        }//while

        //if the value was not found, return
         return 1;
}//search


int min(node *root){

	//create pointer for itetration
	node *curr = root;

	//go all the way to the left in the tree
	while(curr->left!=NULL){
		curr = curr->left;
	}//while

	//return the min or curr->elements
	printf("%d", curr->data);
	return curr->data;
}//min

int max(node *root){

        //create pointer for itetration
        node *curr = root;

        //go all the way to the left in the tree
        while(curr->right!=NULL){
                curr = curr->right;
        }//while

        //return the min or curr->elements
	printf("%d",curr->data);
        return curr->data;
}//max


node *create_node(int data){
	//malloc a new node
	node *new_node=(node *)malloc(sizeof(node));
	//error check for memory
	if(new_node==NULL){
		fprintf(stderr,"Out of memory\n");
		exit(1);
	}

	//intialize variables and return new node
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;

}//create

node *insert(node *root, int data){

	//create a root node to insert
	if(root==NULL){
		//create root and return it
		root = create_node(data);
		return root;
	}else{
		//go through the tree and see where to insert
		node *curr = root;
		node *prev = NULL;
		int left=0;

		//iterate
		while(curr !=NULL){

			prev = curr;
			//if elem is less than curr->elements, go left
			if(data < curr->data){
				//go left
				left = 1;
				curr = curr->left;
			}else if(data > curr->data){
				//go right
				left = 0;
				curr = curr->right;
			}//else if for going left or right
		}//while

		//check where curr is relative to prev
		if(left){
			//if curr is to the left, create node there
			prev->left = create_node(data);
		}else{
			//esle create new node on the right
			prev->right = create_node(data);
		}//if else

	}//if else


	return root;

}//insert*/

void inOrder(node *t){

	if(t==NULL){

           return;
	}

     inOrder(t->left);

     printf("%d ", t->data);

     inOrder(t->right);

} //inOrder

void preOrder(node *t){

     if(t==NULL){

          return;
	}

	printf("%d ", t->data);
	preOrder(t->left);
	preOrder(t->right);
}

void freeM(node* root){
    if(root != NULL){
        freeM(root->left);
        freeM(root->right);
        free(root);
    }
}


int main(){

	int status =0;
	int ret = 0;
	int arg;
	size_t n = 0;
 	char *line = NULL;
	char cmd [32];
	char *token =NULL;
	node *root=NULL;

	while (getline(&line, &n, stdin) > 0){
		//toekenize line
		token = strtok(line,";");

		//go thorugh and scan for cmds
		while(token !=NULL){

			//read the commands
			ret=sscanf(token, "%31s %d,", cmd, &arg);

			//error checks and output for input p and P
			if(strcmp(cmd,"p")==0 || strcmp(cmd, "P")==0){

				if(ret>1){
					fprintf(stderr,"ERROR: The command '%s' MUST NOT have any parameter.  Error in the command '%s %d'.\n", cmd, cmd, arg);
					status=1;
				}else if(strcmp(cmd,"p")==0){
					preOrder(root);
					printf("\n");
				}else{
					inOrder(root);
					printf("\n");
				}//elesif

			}//if statement for print

			//if statment for max and min
			 if(strcmp(cmd,"m")==0 || strcmp(cmd, "M")==0){

                                if(ret>1){
                                        fprintf(stderr,"ERROR: The command '%s' MUST NOT have any parameter.  Error in the command '%s %d'.\n", cmd, cmd, arg);
                                        status=1;
                                }else if(strcmp(cmd,"m")==0){

					if(root==NULL){
                                                fprintf(stderr, "ERROR: Cannot calculate min because the tree is empty.\n");
                                                status =1;
                                        }else{
                                                min(root);
                                                printf("\n");
                                        }//elese if for min
                                }else{

					if(root==NULL){
						fprintf(stderr, "ERROR: Cannot calculate max because the tree is empty.\n");
						status =1;
					}else{
						max(root);
                                        	printf("\n");
					}//elese if for max 
                                }//eles if

                        }//if statement for max and min

			//if statment for error checks for insert search and delete
			 if(strcmp(cmd,"i")==0 || strcmp(cmd, "s")==0 || strcmp(cmd, "d")==0){

				if(ret<=1){
                                        fprintf(stderr,"ERROR: The command '%s' requires an integer parameter.  Error in the command '%s'.\n", cmd, cmd);
                                        status=1;
                                }else if(strcmp(cmd,"i")==0){
					if(searchHelper(arg, root)==0){
						fprintf(stderr,"ERROR: Could not insert %d into the tree because it already exists.\n", arg);
						status =1;
					}else{
					//insert root or new_node
                                        root = insert(root, arg);
					}
                                }else  if(strcmp(cmd,"s")==0){
					//search for the value
                                        search(arg, root);
                                }else{
					if(searchHelper(arg, root)==1){
                                                fprintf(stderr,"ERROR: Could not delete %d from the tree because it does not exist.\n", arg);
                                                status =1;
                                        }else{
					//delete the node
					root= delete_node(root, arg);
					}
                                }//eles if

			}//if statement for insert, delete and search

			token = strtok(NULL, ";");
		}

		//set line and n back to null and 0.
		line = NULL;
		n = 0;
  	}

	freeM(root);
	return status;
}//main
