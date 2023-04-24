#include "shell.h"

/**
* _strcat - Concatenar two strings
* @stringOne: string where is concatenated
* @stringTwo: string to copy
*
* Return: string one
*/

char *_strcat(char *stringOne, char *stringTwo)
{
	int i = 0, j = 0;

	while (stringOne[i] != '\0')
	{
		i++;
	}

	while (stringTwo[j] != '\0')
	{
		stringOne[i] = stringTwo[j];
		i++;
		j++;
	}

stringOne[i] = '\0';
return (stringOne);
}
