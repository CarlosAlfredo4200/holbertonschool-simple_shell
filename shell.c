#include "shell.h"

/**
 * enter_line - read line for the keyboard
 *
 * Return: entering in line
 */

char *enter_line(void)
{

	char *string = NULL;
	size_t user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "cisfun$ ", 14);

	if (getline(&string, &user, stdin) == -1)
	{
		free(string);
		return (NULL);
	}
	return (string);
}
