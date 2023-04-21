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
    {
        // Código del proceso padre
        free(exe_path_str); // Liberar la memoria asignada a exe_path_str

        // Esperar a que el proceso hijo termine sin bloquear la ejecución del programa
        while (waitpid(is_child, &status, WNOHANG) == 0)
        {
            // Aquí puedes poner código adicional para ejecutar mientras esperas
            // a que el proceso hijo termine, si es necesario
        }

        if (WIFEXITED(status))
        {
            // El proceso hijo terminó con éxito
            return WEXITSTATUS(status);
        }
        else
        {
            // El proceso hijo terminó con un error
            return -1;
        }
    }
    else if (is_child == 0)
    {
        // Código del proceso hijo
        (execve(exe_path_str, cmd_arr, environ));
        perror("Error:");
        free(exe_path_str); // Liberar la memoria asignada a exe_path_str
        exit(1);
    }
    return (0);
}
