#include "shell.h"


/**
 * tokenizer - split the string you input
 * @string: line of stdin
 *
 * Return: double pointer of the split commands
 */

char **tokenizer(char *string)
{
	char **command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (string == NULL)
		return (NULL);

	for (i = 0; string[i]; i++)
	{
	if (string[i] == ' ')
		size++;
	}
	if ((size + 1) == _strlen(string))
		return (NULL);
	command = malloc(sizeof(char *) * (size + 2));
	if (command == NULL)
		return (NULL);
	token = strtok(string, " \n\t");
	for (i = 0; token != NULL; i++)
	{
	command[i] = token;
	token = strtok(NULL, " \n\t");
	}
	command[i] = NULL;
			return (command);
}
