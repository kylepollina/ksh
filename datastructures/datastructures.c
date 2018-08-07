/*	datastructures.c
	Kyle Pollina
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/linkedlist.h"

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
			printf("To create a linked list type 'cl'\n");
			printf("To add to a linked list type ...\n");
			printf("Type Q to quit\n\n");
		}

		// create linked list
		if(strcmp(str, "cl") == 0){
			if(create_linkedlist() == 0)
				printf("Linked list created\n");
			else
				printf("Linked list already created\n");
		}

		printf(">");
		scanf("%s", str);	// wait for user input
	}  


	free(str);
}
