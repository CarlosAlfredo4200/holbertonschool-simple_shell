#include "myShell.h"
#include "builtins.h"

struct builtin builtins[] = {
{"help", shell_help},
{"exit", shell_exit},
{"cd", shell_cd},
};

void shell_exit(char **args __attribute__((unused)))
{
exit(0);
}

void shell_cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "shell: cd: missing argument not found\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("shell: cd");
}
}
}

void shell_help(char **args __attribute__((unused)))
{
char *helptext =

"shell - the Kinda Aimless Shell.\n"
"The following commands are built in:\n"
"  cd       Change the working directory.\n"
"  exit     Exit the shell.\n"
"  help     Print this help text.\n";
printf("%s", helptext);

}

int shell_num_builtins(void);
{

(return sizeof(builtins) / sizeof(struct builtin));

}

