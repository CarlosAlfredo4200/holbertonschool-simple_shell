#include "shell.h"
/**
 * run_com - execute the command
 *@arg: concatenate of the strings and path
 *@av: program
 *@env: environment
 *@string: command line
 *@np: number of proces
 *@c: Checker add new test
 *Return: 0 success
 */

int run_com(char **arg, char **av, char **env, char *string, int np, int c)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (arg == NULL)
		exit(errno);

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(string);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
