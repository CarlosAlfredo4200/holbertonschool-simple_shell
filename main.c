#include "myShell.h"

int main(void) {

  char *line;
  char **tokens;
  while (true) {
    printf("my_shell: ");
    line = shell_read_line();
    tokens = shell_split_line(line);

    if (tokens[0] != NULL) {
      shell_exec(tokens);
    }

    free(tokens);
    free(line);
  }
}
