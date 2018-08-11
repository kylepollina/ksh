// sh_kyle.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include "include/sh_kyle.h"

int main(void)
{
	printf("===============================================\n");
	printf(" sh_kyle - A 'shell' style command prompt used\n");
	printf("           for testing and running programs\n");
	printf("           I've made.\n");
	printf("===============================================\n");
	printf("                              By: Kyle Pollina\n");
	printf("Type HELP for more options...\n");
	printf("Type Q to quit\n");

	run();	

	return 0;
}

void run()
{
	char *input_str = malloc(sizeof(char) * MAXBUF); 
	
	printf("sh_kyle>> ");
	fgets(input_str, MAXBUF, stdin);

	list_t *input = stringToList(input_str);

	printList(input);




	/* if(strcmp(input_str, "help") == 0 || strcmp(input_str, "HELP") == 0){ */
	/* 	printf("sh_kyle Copyright Kyle Pollina 2018\n"); */
	/* 	printf("These are the commands you can run...\n\n"); */

	/* 	printf("create list\t\t\tCreates a linked list\n"); */
	/* } */			

	/* printf("sh_kyle>> "); */
	/* scanf("%s", input_str); */

}

