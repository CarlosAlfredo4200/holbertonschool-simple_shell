#include "myShell.h"
int main()
{
  char *line;
  char **args;
  int status;
  status = 0;

  do
  {
    printf(" ");
    line = shell_read_line();
    args = shell_split_line(line);
    shell_exec(args);

    free(line);
    free(args);

  } while (status);

  return 0;
}
