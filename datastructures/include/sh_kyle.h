// sh_kyle.h
//  header for sh_kyle.c
//  Kyle Pollina

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "defaults.h"
#include "linkedlist.h"
#define MAXBUF 1024

void run();
list_t *parse_input(char *input_str);
