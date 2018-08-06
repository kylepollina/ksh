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

	char str[100];
	scanf("%s", str);

	while(!(strcmp(str, "Q") == 0 || strcmp(str, "q") == 0)) {
		if(strcmp(str, "help") == 0 || strcmp(str, "HELP") == 0){
			printf("To create a linked list type 'cl'\n");
			printf("To add to a linked list type ...\n");
			printf("Type Q to quit\n\n");
		}	

		scanf("%s", str);
	}  
}
