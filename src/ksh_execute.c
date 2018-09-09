// ksh_execute.c
//  executes builtin programs and user programs for ksh
//  kyle pollina

#include "../include/ksh.h"

int ksh_help(char **args);
int ksh_cd  (char **args);
int ksh_exit(char **args);
int ksh_pwd (char **args);

// array of all command strings
char *builtin_str[] = {
    "help",
    "cd",
    "exit",
    "pwd"
};

// array of all command function pointers
int (*builtin_func[]) (char **) = {
    &ksh_help,
    &ksh_cd,
    &ksh_exit,
    &ksh_pwd
};


// execute the first command in args
// returns  0 if program executes properly
//          ERR if program fails to execute properly
int ksh_execute(char **args)
{
    int i;

    if(args[0] == NULL){
        return ERR;
    }

    for(i = 0; i < ksh_num_cmds(); i++){
        if(strcmp(args[0], builtin_str[i]) == 0){
            return (*builtin_func[i])(args);
        } 
    }

    return ksh_launch(args);
}


// returns the number of commands
int ksh_num_cmds()
{
    return sizeof(builtin_str) / sizeof(char *);
}

// help
int ksh_help(char **args)
{
    if(args[1] == NULL){
        printf("===========================================\n");
        printf(" ksh - A simple shell created from scratch\n");
        printf("       in C\n");
        printf("===========================================\n");
        printf("                              By: Kyle Pollina\n");
        printf("These are the commands you can run...\n\n");

        printf("<command>\t\t<description>\n");
        printf("help\t\t\topen help list\n");
        printf("cd <path>\t\tchange directory\n");
        printf("exit\t\t\tclose shell\n");
    }

    else{
        if(strcmp(args[1], "help") == 0){
            printf("lsh: help <command> - get more info on <command>\n");
        }
        else if(strcmp(args[1], "cd") == 0){
            printf("lsh: cd <path> - change directory to <path>\n");
        }
        else if(strcmp(args[1], "exit") == 0){
            printf("lsh: exit - exit the current iteration of ksh\n");
        }
    }

    return 0;
}

// change directory
int ksh_cd(char **args)
{
    if(args[1] == NULL){
        fprintf(stderr, "lsh: you need to put a path after cd dummy. type 'help cd' for more help\n");
    }
    else{
        if(chdir(args[1]) != 0){
            perror("lsh");
        } 
    }

    return 0;
}

// exit
int ksh_exit(char **args)
{
    return 1;
}

