// sh_kyle.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include "../include/sh_kyle.h"

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
	
	while(TRUE){
		printf("sh_kyle>> ");
		fgets(input_str, MAXBUF, stdin);
		list_t *input = stringToList(input_str);

		if(listLength(input) >= 1){
			node_t *first = input->head->next;

			if(strcmp(first->str, "q") == 0 || strcmp(first->str, "Q") == 0)
				break;
			
			process_input(input);
		}	

		else
			printf("WOOOPS\n");
	} 

	free(input_str);
}

//TODO document
void process_input(list_t *input)
{
	printf("begin pi\n");
	node_t *first = input->head->next;
	int numargs = listLength(input) - 1;

	/* printf("id: %x\n", first->id); */

	if(first->id == ID_STR){
		// HELP
		if(strcmp(first->str, "help") == 0 || strcmp(first->str, "HELP") == 0){
			if(numargs >= 1){
				node_t *arg1 = first->next;

				if(arg1->id == ID_STR && strcmp(arg1->str, "create") == 0){
					printf("--create: Create can be used to create a datastructure.\n");
					printf("--To create a doubly linked use the command\n");
					printf("	create list\n");
				}

				else{
					printf("--help: argument not recognized\n");
				}
			}
			
			else{
				printf("\nsh_kyle Copyright Kyle Pollina 2018\n");
				printf("These are the commands you can run...\n\n");

				printf(" create <arg>\t\t\tCreates the given datastructure\n");
				printf(" -create list\t\t\tCreates a doubly linked list\n");
				printf("\nYou can also run 'help <command>' on any of the above commands\n");
			}			 
		}
	}	
	else if(first->id == ID_INT){}
}
