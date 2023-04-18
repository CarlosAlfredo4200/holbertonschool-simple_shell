#include "myShell.h"

void shell_cd(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "shell: cd: missing argument\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("shell: cd");
    }
  }
}
