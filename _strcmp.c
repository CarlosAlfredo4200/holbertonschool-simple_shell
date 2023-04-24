#include "shell.h"

/**
 * _strcmp - compare if bouth string are equals
 * @s1: string one
 * @s2: string two
 *
 * Return: 0 if bouth are equals
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] ; i++)
		if (s1[i] == '\0')
			return (0);
	return (s1[i] - s2[i]);

}
