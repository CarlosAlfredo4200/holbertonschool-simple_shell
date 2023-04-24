#include "shell.h"

/**
 * _strncmp - compare characteres of two strings
 * @s1: string one
 * @s2: string two
 * @n: number of characteres for compare
 *
 * Return: 0
 */


size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}
