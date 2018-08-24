// sh_kyle.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include "../include/sh_kyle.h"

int main(void)
{
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
			
			if(first->id == ID_STR){
				if(strcmp(first->str, "q") == 0 || strcmp(first->str, "Q") == 0)
					break;
					
				else
					process_input(input);
			}
			else{
				process_input(input);
			}	
		}	
	} 

	free(input_str);
}

// processes the linked list of words. executes programs based on commands
void process_input(list_t *input)
{
	node_t *first = input->head->next;

	/* printf("id: %x\n", first->id); */
	/* printf("input length: %d\n", listLength(input)); */

	if(first->id == ID_STR){

		// HELP or help
		if(strcmp(first->str, "help") == 0 || strcmp(first->str, "HELP") == 0){
			help(popfront(input));
		}
	}	
	else if(first->id == ID_INT){

	}

}

// BUILT IN COMMANDS. USER MADE COMMANDS GO IN /src/usrfunc.c
//TODO create usrfunc.c


// HELP or help 
void help(list_t *arguments) 
{
	if(listLength(arguments) >= 1){
		node_t *arg1 = arguments->head->next;

		if(arg1->id == ID_STR && strcmp(arg1->str, "create") == 0){
			printf("\ncreate -- create can be used to create a datastructure.\n");
			printf("To create a doubly linked use the command\n");
			printf("	create list\n\n");
		}

		else{
			printf("--help: argument not recognized. Try running 'help' or 'HELP'\n");
		}
	}
	
	else{
		printf("===============================================\n");
		printf(" sh_kyle - A 'shell' style command prompt used\n");
		printf("           for testing and running programs\n");
		printf("           I've made.\n");
		printf("===============================================\n");
		printf("                              By: Kyle Pollina\n");
		printf("These are the commands you can run...\n\n");

		printf("<command>\t\t\tDescription\n");
		printf("create <arg>\t\t\tCreates the given datastructure\n");
		printf("\nYou can also run 'help <command>' on any of the above commands\n");
	}			 
}
