/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	
	float quo,cng;
	int in,k=0,pos=0;
	quo = number / 10;
	
	if (number < 0)
	{
		str[0] = '-';
		quo = -quo;
		pos++;
		k++;
	}

	while (quo > 1)
	{
		quo = quo / 10;
		pos++;
	}
	cng = quo * 10;
	in = (int)cng;
	while ((cng - in) != 0 &&k!=pos+afterdecimal+1)
	{
		cng = cng - in;
		str[k] = (char)(in + 48);
		cng = cng * 10;
		in = (int)cng;
		k++;
		if (k == pos+1)
		{
			str[k] = '.';
			k++;
		}
	}
	str[k] = (char)(in + 48);
	str[k + 1] = '\0';

}
