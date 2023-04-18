#include "myShell.h"
char* shell_read_line() {
  char *line = NULL;
  size_t buflen = 0;
  ssize_t strlen;
  errno = 0;
  strlen = getline(&line, &buflen, stdin);
  if (strlen < 0) {
    if (errno) {
      perror("shell");
    }
    exit(1);
  }
  return line;
}
