#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "include/linkedlist.h"

list_t *stringToList(char *input_str)
{
	list_t *input = newList(ID_STR);

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
				listAddInt(input, atoi(substring));
			else
				listAddStr(input, substring);

			word_start = i + 1;
			word_length = 0;
			is_int = TRUE;
		}
	}

	return input;
}
