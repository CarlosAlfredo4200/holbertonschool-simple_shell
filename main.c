#include "myShell.h"
int main(void)
{
char *line;
char **args;
int status;
status = 0;

do {
write(1, "$x ", 2);
line = shell_read_line();
args = shell_split_line(line);
shell_exec(args);

free(line);
free(args);

} while (status);

(return) 0;
}
