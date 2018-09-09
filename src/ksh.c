// ksh.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include "../include/ksh.h"

int main(int argc, char **argv)
{
    printf("Type help for more options...\n");
    printf("Type exit to quit\n");

    ksh();	

    return 0;
}

// main loop
void ksh()
{
    char *input_str = malloc(sizeof(char) * MAXBUF); 
    int status = TRUE;      // loop status

    do {
        printf("ksh> ");
        fgets(input_str, MAXBUF, stdin);

        char **args = ksh_split_line(input_str);

        status = ksh_execute(args);

    } while(!status);

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

    return 0;    
}

