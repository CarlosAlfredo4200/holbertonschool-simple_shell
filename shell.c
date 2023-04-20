#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
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
        do
	  {
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

  delimiters = " \t\r\n";
  token = strtok(line, delimiters);

  while (token != NULL)
    {
      tokens[length] = token;
      length++;

      if (length >= capacity)
        {
	  capacity = (int)(capacity * 1.5);
	  new_tokens = realloc(tokens, capacity * sizeof(char *));
	  if (!new_tokens)
            {
	      perror("shell");
	      exit(1);
            }
	  tokens = new_tokens;
        }

      token = strtok(NULL, delimiters);
    }

  tokens[length] = NULL;
  return tokens;
}

char *shell_read_line()
{

  size_t buflen;
  ssize_t strlen;
  
  char *line;
  line = NULL;
 
  buflen = 0;
  errno = 0;
   
  strlen = getline(&line, &buflen, stdin);
  if (strlen < 0)
    {
      if (errno)
        {
	  perror("shell");
        }
      exit(1);
    }
  return line;
}
