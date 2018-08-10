// sh_kyle.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/sh_kyle.h"

int main(void)
{
	printf("===============================================\n");
	printf(" sh_kyle - A 'shell' style command prompt used\n");
	printf("           for testing and running programs\n");
	printf("           I've made.\n");
	printf("================================================\n");
	printf("                               By: Kyle Pollina\n");
	printf("Type HELP for more options...\n");
	printf("Type Q to quit\n");

	run();	

	return 0;
}

void run()
{
	char *input_str = malloc(sizeof(char) * 1024); 
	list_t *input = new_list();
	
	printf("sh_kyle >");

	scanf("%s", input_str);

	while(!(strcmp(input_str, "Q") == 0 || strcmp(input_str, "q") == 0)){
		
	}
}
