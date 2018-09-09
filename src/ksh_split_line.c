// ksh_split_line.c
//  tokenize user input into individual arguments
//  Kyle Pollina

#include "../include/ksh.h"
#define KSH_TOK_DELIM   " \t\r\n\a"
#define KSH_TOK_BUFSIZE 64

char **ksh_split_line(char *input_str)
{
    char **tokens = malloc(MAXBUF * sizeof(char *));    // array of args
    char *token;                        // individual args
    int position  = 0;                  // position of token in tokens
    int bufsize   = KSH_TOK_BUFSIZE;    // max size of tokens

    if(!tokens){
        printf("ksh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input_str,KSH_TOK_DELIM);
    while(token != NULL){
        tokens[position] = token;
        position++;

        if(position >= bufsize){        // if more than 64 * n args
            bufsize += KSH_TOK_BUFSIZE;     
            tokens = realloc(tokens, bufsize * sizeof(char *));
            
            if(!tokens){
                printf("ksh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        
        // NULL argument begins where last successful call to strtok ended
        token = strtok(NULL, KSH_TOK_DELIM);    
    }

    tokens[position] = NULL;
    return tokens;
}

