// testing.c
//  program to test datastructures
//  Kyle Pollina

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/datastructures.h"

linkedlist_t *list;
bool linkedlist_exists = FALSE;

int main(void)
{
	printf("Cracking the Coding Interview Practice: Datastructures\n");
	printf("Author: Kyle Pollina\n");
	printf("======================================================\n\n");


	printf("Type help for more information. Type Q to quit\n\n");	
	printf(">");

	char *str = (char *)malloc(sizeof(char *) * 20);
	scanf("%s", str);		// wait for user input

	// quit if user inputs Q or q
	while(!(strcmp(str, "Q") == 0 || strcmp(str, "q") == 0)) {

		// help or HELP inputted
		if(strcmp(str, "help") == 0 || strcmp(str, "HELP") == 0){
			printf("To create a linked list type lc\n");
			printf("To add to a linked list type la\n");
			printf("To print linked list type	 lp\n");
			printf("Type Q to quit\n\n");
		}

		// create linked list
		if(strcmp(str, "lc") == 0){
			if(linkedlist_exists == TRUE)
				printf("Linked list already created\n");
			else {
				linkedlist_exists = TRUE;
				list = new_linkedlist(ID_INT);		// creates an integer linked list
				printf("Linked list successfully created\n");
			}
		}

		// add to a linked list
		if(strcmp(str, "la") == 0 && list == NULL) 
			printf("Linked list does not exist\n");

		else if(strcmp(str, "la") == 0) {
			printf("Enter numbers you would like to add to the linked list. When finished, enter f\n");
			printf("add>");

			scanf("%s", str);

			while(!(strcmp(str, "f") == 0 || strcmp(str, "F") == 0)) {
				if(linkedlist_add_int(list, atoi(str)) == -1)
					printf("Error adding value\n");
				printf("add>");

				scanf("%s", str);
			}
		}

		if(strcmp(str, "lrl") == 0){
			printf("Removing last element in list...\n");
			if(linkedlist_remove_last(list) == 0)
				printf("Successful removal of last element in list\n");
			else
				printf("Failed...\n");
		}

		if(strcmp(str, "lrf") == 0){
			printf("Removing first element in list...\n");
			if(linkedlist_remove_first(list) == 0)
				printf("Successful removal of first element in list\n");
			else
				printf("Failed...\n");
		}





		// print linked list
		if(strcmp(str, "lp") == 0) {
			printf("Printing linked list...\n");
			linkedlist_print(list);
		}



		printf(">");
		scanf("%s", str);	// wait for user input
	}  


	free(str);
}
