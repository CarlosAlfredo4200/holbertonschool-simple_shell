#include "shell.h"

/**
 * _strlen - size of a string
 * @s: string
 *
 * Return: int
 */

int _strlen(char *s)
{
	int k = 0;

	while (*(s + k) != '\0')
		++k;
	return (k);
}
