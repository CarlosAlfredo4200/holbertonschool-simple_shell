#include "shell.h"

/**
 * _strcpy - copy one string
 * @dest: where the new string is copied
 * @src: string to copy
 *
 * Return: 0
 */

char *_strcpy(char *dest, char *src)
{
	int k = 0;

	while (src[k] != '\0')
	{
		dest[k] = src[k];
		++k;
	}
	dest[k] = '\0';
	++k;
	return (dest);
}
