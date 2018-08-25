// sh_kyle.h
//  header for sh_kyle.c
//  Kyle Pollina

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defaults.h"
#include "linkedlist.h"
#define MAXBUF 1024

void run();
void process_input(list_t *input);
void help(list_t *arguments);
list_t *stringToList();
void exec_usrfunc(list_t *input);
