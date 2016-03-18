/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 31


char ** commonWords(char *str1, char *str2) {

	int i, len=0, j, l, m, k = 0, row = 0, ind = 0;
	char * word = (char *)malloc(sizeof(char)* 100), **str3;

	str3 = (char**)malloc(sizeof(char)* 100);
	for (i = 0; i < 100; i++)
		str3[i] = (char*)calloc(sizeof(char), 100);


	if (str1 == NULL || str2 == NULL)
		return NULL;

	for (i = 0; str1[i] != '\0'; i++)
		len++;

	for (i = 0; i <= len; i++)
	{
		if (str1[i] != ' '&&str1[i] != '\0')
		{
			word[k] = str1[i];

			k++;
		}
		else
		{
			word[k] = '\0';


			l = 0;
			for (j = 0; str2[j] != '\0'; j++)
			{
				if (str2[j] == word[l])
				{
					l++;

				}
				else
				if (l == k)
				{
					break;
				}
				else
				{
					j -= l;

					l = 0;
				}

			}

			printf("\n");
			if (l == k&&k!=0)
			{

				for (m = 0; word[m] != '\0'; m++)
				{
					str3[row][m] = word[m];
				}
				str3[row][m] = '\0';
				printf("\n");
				row++;
			}
			k = 0;

		}

	}


	if (row == 0)
		return NULL;

	return str3;
}

