#include "myShell.h"


void shell_help(char **args) {
  char *helptext;
  printf("args[0]: %s\n", args[0]);
    helptext = "shell - the Kinda Aimless Shell. "
        "The following commands are built in:\n"
        "  cd       Change the working directory.\n"
        "  exit     Exit the shell.\n"
        "  help     Print this help text.\n"
      ;
    printf("%s", helptext);
    printf("args[0]: %s\n", args[0]);
}
