#include "shell.h"
/**
 * tokenizer_path - function for split the  path
 * @arg: arguments
 * @around: path variable environment
 *
 * Return: double pointer of the split path
 */
int tokenizer_path(char **arg, char **around)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_string;

	if (stat(*arg, &stat_string) == 0)
		return (-1);
	path_rela = find_path(around);
	if (!path_rela)
		return (-1);
	token = strtok(path_rela, ":");
command = _strlen(*arg);
	while (token)
	{
		value_path = _strlen(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = _strcpy(path_absol, token);
		_strcat(path_absol, "/");
		_strcat(path_absol, *arg);
		if (stat(path_absol, &stat_string) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = strtok(NULL, ":");
	}
	free(path_rela);
	return (-1);
}
