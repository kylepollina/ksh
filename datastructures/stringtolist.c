// stringtolist.c
//  converts a string into a linked list of individual nodes of words
//  Kyle Pollina

#include "include/linkedlist.h"

list_t *stringToList(char *input_str)
{
	list_t *input = newList();

	int word_start = 0;
	int word_len;
	char letter;
	int length = strlen(input_str);
	bool is_int = TRUE;

	for(int i = 0; i < length; i++){
		letter = input_str[i];
		word_len = i - word_start;

		if(!(letter == ' ' || letter == 10) && isdigit(letter) == FALSE)
			is_int = FALSE;

		//end of word
		if(letter == ' ' || letter == 10){
			char substring[word_len + 1];
			memcpy(substring, &input_str[word_start], word_len);
			substring[word_len] = '\0';

			if(word_len != 0){
				if(is_int == TRUE){
					listAddInt(input, atoi(substring));	
				}
				else{
					listAddStr(input, substring);
				}
			}

			word_start = i + 1;
			word_len = 0;
			is_int = TRUE;
		}
	}	

	printf("end stl\n");

	return input;
}

