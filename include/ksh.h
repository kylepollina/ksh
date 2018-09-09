// ksh.h
//  header for ksh.c
//  Kyle Pollina

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "defaults.h"

#define MAXBUF 1024

// ksh.c
void ksh();
void process_input(char **args);
int  ksh_launch(char **args);

// ksh_split_line.c
char **ksh_split_line(char *input_str);

// ksh_execute.c
int ksh_execute(char **args);
