/*	datastructures.c
	Kyle Pollina
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/datastructures.h"

struct linkedlist *list;
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
			printf("To add to a linked list type la <number>\n");
			printf("Type Q to quit\n\n");
		}

		// create linked list
		if(strcmp(str, "lc") == 0){
			if(linkedlist_exists == TRUE)
				printf("Linked list already created\n");
			else {
				linkedlist_exists = TRUE;
				list = new_linkedlist();
				printf("Linked list successfully created\n");
			}
		}

		// add to a linked list
		if(strcmp(str, "la") == 0){
			printf("Enter numbers you would like to add to the linked list. When finished, enter f\n");
			printf("add>");

			scanf("%s", str);
			
		}
		printf(">");
		scanf("%s", str);	// wait for user input
	}  


	free(str);
}
