#include "myShell.h"


void shell_exec(char **args)
{

int i;
pid_t child_pid;
for (i = 0; i < shell_num_builtins(); i++)
{
if (strcmp(args[0], builtins[i].name) == 0)
{
builtins[i].func(args);
return;
}
}

child_pid = fork();
if (child_pid == 0)
{
execvp(args[0], args);
perror("shell");
exit(1);
}
else if (child_pid > 0)
{
int status;
do {
waitpid(child_pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
else
{
perror("shell");
}
}



char **shell_split_line(char *line)
{
int length = 0;
int capacity = 16;
char *delimiters;
char *token;
char **new_tokens;
char **tokens = malloc(capacity * sizeof(char *));
if (!tokens)
{
perror("shell");
exit(1);
}

delimiters = " \t\r\n\a";
token = strtok(line, delimiters);

while (token != NULL)
{
tokens[length++] = token;

if (length >= capacity)
{
capacity *= 2;
new_tokens = realloc(tokens, capacity *sizeof(char *));
if (!new_tokens)
{
free(tokens);
perror("shell");
exit(1);
}
tokens = new_tokens;
}

token = strtok(NULL, delimiters);
}

tokens[length] = NULL;
(return) tokens;
}

char *shell_read_line()
{
int capacity = 128;
int position = 0;
char *buffer = malloc(capacity *sizeof(char));
int c;

if (!buffer)
{
perror("shell");
exit(1);
}

while (1)
{
c = getchar();

if (c == EOF || c == '\n')
{
buffer[position] = '\0';
(return) buffer;
}
else
{
buffer[position++] = c;
}

if (position >= capacity)
{
capacity *= 2;
buffer = realloc(buffer, capacity *sizeof(char));
if (!buffer)
{
perror("shell");
exit(1);
}
}
}
