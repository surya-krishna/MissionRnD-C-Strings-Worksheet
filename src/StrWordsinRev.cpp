/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/

#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int i, j, sub_start, k, sub_end, fl = 1;
	char ch;
	for (i = 0; i < len / 2; i++)
	{

		ch = input[i];
		input[i] = input[len - 1 - i];
		input[len - 1 - i] = ch;
	}
	sub_start = 0;
	for (i = 0; i < len + 1; i++)
	{
		if ((input[i] == ' ' || input[i] == '\0') && input[i - 1] != ' ')
		{
			sub_end = i;
			for (j = sub_start, k = sub_end - 1; j < (sub_start + sub_end) / 2; j++, k--)
			{

				ch = input[j];
				input[j] = input[k];
				input[k] = ch;
			}
		}
		if (input[i] == ' '&&input[i + 1] != ' ')
		{
			sub_start = i + 1;
		}
	}
}
