// sh_kyle.c
//  a 'shell' style command prompt used for testing and running programs I've made
//  Kyle Pollina

#include "include/sh_kyle.h"

int main(void)
{
	printf("===============================================\n");
	printf(" sh_kyle - A 'shell' style command prompt used\n");
	printf("           for testing and running programs\n");
	printf("           I've made.\n");
	printf("===============================================\n");
	printf("                              By: Kyle Pollina\n");
	printf("Type HELP for more options...\n");
	printf("Type Q to quit\n");

	run();	

	return 0;
}

void run()
{
	char *input_str = malloc(sizeof(char) * MAXBUF); 
	
	printf("sh_kyle>> ");
	fgets(input_str, MAXBUF, stdin);

	list_t *input = parse_input(input_str);

	print_list(input);

	/* if(strcmp(input_str, "help") == 0 || strcmp(input_str, "HELP") == 0){ */
	/* 	printf("sh_kyle Copyright Kyle Pollina 2018\n"); */
	/* 	printf("These are the commands you can run...\n\n"); */

	/* 	printf("create list\t\t\tCreates a linked list\n"); */
	/* } */			

	/* printf("sh_kyle>> "); */
	/* scanf("%s", input_str); */

}

//TODO documentation. also thinking of seperating this function entirely
list_t *parse_input(char *input_str)
{
	list_t *input = new_list(ID_STR);

	int word_start = 0;
	int word_length;
	char letter;
	int length = strlen(input_str);

	for(int i = 0; i < length; i++){
		letter = input_str[i];
		word_length = i - word_start;
		bool is_int = TRUE;

		if(isdigit(letter) == FALSE)
			is_int = FALSE;

		// end of a word
		if(letter == ' ' || letter == 10){
			char substring[word_length];
			memcpy(substring, &input_str[word_start], word_length);
			substring[word_length] = '\0';


			if(is_int == TRUE)
				list_add_int(input, atoi(substring));
			else
				list_add_str(input, substring);

			word_start = i + 1;
			word_length = 0;
		}
	}

	return input;
}
