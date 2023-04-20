#include "myShell.h"
int main()
{
  while (true)
    {
      char *line;
      char **tokens;
      printf(" ");
      line = shell_read_line();
      tokens = shell_split_line(line);
      if (tokens[0] != NULL)
	{
	  shell_exec(tokens);
	}
      free(tokens);
      free(line);
    }
}
