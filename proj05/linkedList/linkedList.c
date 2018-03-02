
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//declaring a struct
struct node {
	char *name;
	int num;
	struct node *next;
};
struct node *list=NULL;

/*
 * del()
 */

void del(char word2[]){

	printf("you are in delete\n");
	//create pointer
	struct node *curr;
	struct node *prev;

	curr = list;

	//traverse the list to get to the current node
	while(curr->next!=NULL){

		if(strcmp(curr->name, word2)==0){
			break;
		}
		//move prev and curr pointer
		prev =curr;
		curr= curr->next;
	}

	printf("%s\n", prev->name);
	printf("%s\n", curr->name);

	//unlink curr from the list and free curr memory
	prev->next= prev->next->next;
	free(curr);
	//traverse the list to find the node
}//del

void removeHead(){
	//create pointer
	struct node *curr;
	struct node *prev;

	curr = list;
	prev = curr;
	curr = curr->next;
	list =curr;
	free(prev);


}//removeHead

void insert(char word2[], int val){
	struct node *tmp;
	struct node *newnode;

	newnode = malloc(sizeof(struct node));
	if(newnode ==NULL){
		fprintf(stderr, "out of memory\n");
		exit(1);
	}

	newnode->name = strdup(word2);
	newnode->num = val;

	if(list==NULL){
		list=newnode;
		newnode->next=NULL;
		return;
	}

	if(strcmp(newnode->name, list->name)<0){
		newnode->next = list;
		list = newnode;
		return;
	}

	tmp = list;
	while(tmp->next !=NULL){
		if(strcmp(newnode->name, tmp->name) <0){
			if(strcmp(newnode->name, tmp->name) > 0){
				newnode->next = tmp->next;
				tmp->next = newnode;
				return;
			}else{
				free(newnode);
				return;
			}
		}

	tmp = tmp->next;
	}//while loop

	if(strcmp(tmp->name, newnode->name)==0){
	return;
	}else{
		tmp->next = newnode;
		newnode->next =NULL;
		return;
	}
}//read string

void print(){

	struct node *ptr;
	for(ptr= list; ptr!=NULL; ptr = ptr->next){
		printf(" %s/%d", ptr->name, ptr->num);
	}//for loop

	printf("\n");
}//print

void sort(){
	struct node *ptr1, *ptr2;
	char *tmp;

	for(ptr1 = list; ptr1!=NULL; ptr1 = ptr1->next){
		for(ptr2 = ptr1->next; ptr2!=NULL; ptr2 = ptr2->next){
			if(strcmp(ptr1->name, ptr2->name)>0){
			//ptr1->name is "greater than" ptr2->name - swap them
			tmp = ptr1->name;
			ptr1->name = ptr2->name;
			ptr1->name = tmp;
			}
		}
	}

}//sort

int dup(char word2[]){
	struct node *ptr;

	for(ptr= list; ptr!=NULL ; ptr= ptr->next){

		//check to see if there is a case where word2 and ptr->name are equal
		if(strcmp(ptr->name, word2)==0){
			return 0;
		}
	}//for loop

//return 1 if no such case where word2 == ptr->name
return 1;
}

int main (){

	char buff[81];
	int status=0;
	int len;
	char word1[20];
	char word2[20];
	int val;
	int ret;
	int count=0;

	while(fgets(buff, 81, stdin)>0){

		len = strlen(buff);

		if(buff[len-1]!='\n'){
			fprintf(stderr,"Error: string line length was too long\n");
			exit(1);
		}

		sscanf(buff, "%s %s %d", word1, word2, &val);

		if(strcmp(word1, "insert")==0){

			//first check if the word is alreday in the list, if not then insert it and sort it
			if((ret=dup(word2))==0){
				fprintf(stderr, "ERROR: no duplicates in the list\n");
				status=1;
			} else{
				insert(word2, val);
//				sort();
				count++;
			}//if else statement

		}else if(strcmp(word1, "print")==0){
			//print the list
			printf("%d:", count);
			print();
		}else if(strcmp(word1, "delete")==0){

			//first check to see if the word is in the list, if not then print error, else delete it
			if((ret=dup(word2))==1){
				fprintf(stderr, "Error: word does not exist in the list\n");
				status=1;
			} else{
				del(word2);
				count--;
			}//elese if statement

		}else if(strcmp(word1,"removeHead")==0){

			//if the count is zero, the list is empty and print error message
			if(count==0){
				fprintf(stderr,"ERROR: the list is empty\n");
				status=1;
			} else {
				removeHead();
				count--;
			}//else if statement
		} else {

		}


	}//while loop


return status;
}
