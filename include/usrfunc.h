// usrfunc.h
//  header for the user defined functions for sh_kyle

#include "sh_kyle.h"

struct cmdent {                    // entry in command table
    char    *cname;                // name of command 
    bool    cbuiltin;              // is this a builtin command?
    int     (*cfunc)(int, char*[]);// function for command 
};

int exec_usrfunc(list_t *input);
