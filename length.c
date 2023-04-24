#include "shell.h"

/**
 * length - check equals character
 * @str: string of chars
 * Return: string
 */

char *length(char *str)
{
	int i;

	for (i = 0; str[i] != '='; i++)
		;
	return (str + i + 1);
}
