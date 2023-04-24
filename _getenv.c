#include "shell.h"


/**
 * _getenv - search the environment
 * @env: environment
 * Return: 0
 */

void _getenv(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
