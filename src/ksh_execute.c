// ksh_execute.c
//  executes builtin programs and user programs for ksh
//  kyle pollina

#include "../include/ksh.h"

int ksh_help(char **args);
int ksh_cd  (char **args);
int ksh_exit(char **args);

// array of all command strings
char *builtin_str[] = {
    "help",
    "cd",
    "exit"
};

// array of all command function pointers
int (*builtin_func[]) (char **) = {
    &ksh_help,
    &ksh_cd,
    &ksh_exit
};

// returns the number of commands
int ksh_num_cmds()
{
    return sizeof(builtin_str) / sizeof(char *);
}

// returns  1 if program executes properly
//          -1 if program fails to execute properly
int ksh_execute(char **args)
{
    int i;

    if(args[0] == NULL){
        return -1;
    }

    for(i = 0; i < ksh_num_cmds(); i++){
        if(strcmp(args[0], builtin_str[i]) == 0){
            return (*builtin_func[i])(args);
        } 
    }

    return ksh_launch(args);
}


int ksh_help(char **args)
{
    return 0;
}

int ksh_cd(char **args)
{
    return 0;
}

int ksh_exit(char **args)
{
    return 0;
}
