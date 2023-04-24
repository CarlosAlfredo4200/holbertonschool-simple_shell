#include "shell.h"

/**
 * find_path - find the path in the environment
 * @around: around for the path
 *
 * Return: the variable path
 */

char *find_path(char **around)
{
size_t index = 0, var = 0, count = 5;
	char *path = NULL;

	for (index = 0; _strncmp(around[index], "PATH=", 5); index++)
		;
	if (around[index] == NULL)
		return (NULL);

	for (count = 5; around[index][var]; var++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; around[index][var]; var++, count++)
		path[count] = around[index][var];

	path[count] = '\0';
	return (path);
}
