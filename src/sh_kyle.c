// sh_kyle.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include "../include/sh_kyle.h"

int main(int argc, char **argv)
{
	printf("Type HELP for more options...\n");
	printf("Type Q to quit\n");

	sh_kyle();	

	return 0;
}

// main loop
void sh_kyle()
{
	char *input_str = malloc(sizeof(char) * MAXBUF); 
	int status = TRUE;      // loop status

	do {
		printf("sh_kyle>> ");
		fgets(input_str, MAXBUF, stdin);

        char **args = ksh_split_line(input_str);

        if(strcmp(args[0], "q") == 0 || strcmp(args[0], "Q") == 0){
            status = FALSE;
        }

        else{
            process_input(args);
        }

	} while(status); 

	free(input_str);
}

// processes the linked list of words. executes programs based on commands
void process_input(list_t *input)
{
	node_t *first = input->head->next;

	if(first->id == ID_STR){

		// HELP or help
		if(strcmp(first->str, "help") == 0 || strcmp(first->str, "HELP") == 0){
			help(popfront(input));
		}

		exec_usrfunc(input);
	}	
	else if(first->id == ID_INT){

	}

}

// BUILT IN COMMANDS. USER MADE COMMANDS GO IN /src/usrfunc.c

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
