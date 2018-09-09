// ksh.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include "../include/ksh.h"

int main(int argc, char **argv)
{
    printf("Type HELP for more options...\n");
    printf("Type Q to quit\n");

    ksh();	

    return 0;
}

// main loop
void ksh()
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

        status = ksh_execute(args);

    } while(status); 

    free(input_str);
}

// launches programs in new processes
// execvp(args[0], args)
//      executes the program name at args[0] with a
//      vector of string arguments args
// perror()
//      prints system error message + 'ksh'
int ksh_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0){
        // Child process
        if(execvp(args[0], args) == -1){
            perror("ksh");
        }
        exit(EXIT_FAILURE);
    } 
    else if(pid < 0){
        // Error forking
        perror("ksh");
    } 
    else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;    
}




























// BUILT IN COMMANDS. USER MADE COMMANDS GO IN /src/usrfunc.c

// HELP or help 
/* void help(list_t *arguments) */ 
/* { */
/* 	if(listLength(arguments) >= 1){ */
/* 		node_t *arg1 = arguments->head->next; */

/* 		if(arg1->id == ID_STR && strcmp(arg1->str, "create") == 0){ */
/* 			printf("\ncreate -- create can be used to create a datastructure.\n"); */
/* 			printf("To create a doubly linked use the command\n"); */
/* 			printf("	create list\n\n"); */
/* 		} */

/* 		else{ */
/* 			printf("--help: argument not recognized. Try running 'help' or 'HELP'\n"); */
/* 		} */
/* 	} */

/* 	else{ */
/* 		printf("===============================================\n"); */
/* 		printf(" sh_kyle - A 'shell' style command prompt used\n"); */
/* 		printf("           for testing and running programs\n"); */
/* 		printf("           I've made.\n"); */
/* 		printf("===============================================\n"); */
/* 		printf("                              By: Kyle Pollina\n"); */
/* 		printf("These are the commands you can run...\n\n"); */

/* 		printf("<command>\t\t\tDescription\n"); */
/* 		printf("create <arg>\t\t\tCreates the given datastructure\n"); */
/* 		printf("\nYou can also run 'help <command>' on any of the above commands\n"); */
/* 	} */			 
/* } */
