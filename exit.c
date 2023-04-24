#include "shell.h"


/**
 * exit_shell - function for close the process
 * @arg: pointer with the direction argument.
 * @string: input string
 * @_exit: value of exit
 * Return: 0
 */
void exit_shell(char **arg, char *string, int _exit)
{
	int exit_status = 0;

	if (!arg[1])
	{
		free(string);
		free(arg);
		exit(_exit);
	}
	exit_status = atoi(arg[1]);

	free(string);
	free(arg);
	exit(exit_status);
}
