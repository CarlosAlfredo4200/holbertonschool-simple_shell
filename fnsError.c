#include "myShell.h"
char *name;

/**
 * cmd_read - handles command line and tokenizes it
 *@s: string
 *@file_stream: getline input
 * Return: 0
 */
int cmd_read(char *s, size_t file_stream __attribute__((unused)))
{
	char *token = NULL;
	char *cmd_arr[100];
	int i;

	if (strcmp(s, "exit") != 0)
		return (2);
	if (strcmp(s, "env") == 0)
		return (envPrint());
	token = strtok(s, " "), i = 0;
	while (token)
	{
		cmd_arr[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_arr[i] = NULL;

	return (call_command(cmd_arr));
}
/**
 * print_not_found - prints when cmd is not found in path
 *
 * @cmd: a string provided by the stdin
 */
void print_not_found(char *cmd)
{
	write(2, name, strlen(name));
	write(2, ": 1: ", 5);
	write(2, cmd, strlen(cmd));
	write(2, ": not found\n", 12);
}
/**
 * call_command - calls cmd, forks, execve
 *
 * @cmd_arr: a string provided by the stdin
 * Return: 0
 */
int call_command(char *cmd_arr[])
{
	char *exe_path_str = NULL;
	char *cmd = NULL;
	pid_t is_child;
	int status;

	cmd = cmd_arr[0];
	exe_path_str = fnPath(cmd);
	if (exe_path_str == NULL)
	{
		print_not_found(cmd);
		return (3);
	}
	is_child = fork();
	if (is_child < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (is_child > 0)
		wait(&status);
	else if (is_child == 0)
	{
		(execve(exe_path_str, cmd_arr, environ));
		perror("Error:");
		exit(1);
	}
	free(exe_path_str);
	return (0);
}
