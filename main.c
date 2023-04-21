#include "myShell.h"

char *name;

int main(int argc, char *argv[])
{
  char *s = NULL;
  size_t buffer_size = 0;
  ssize_t file_stream = 0;

  (void) argc;
  name = argv[0];

  do {
    if (isatty(STDIN_FILENO) == 1)
      write(1, "$ ", 2);

    file_stream = getline(&s, &buffer_size, stdin);

    if (file_stream == -1) {
      if (isatty(STDIN_FILENO) == 1)
	write(1, "\n", 1);
      perror("getline");
      exit(EXIT_FAILURE);
    }

    if (s[file_stream - 1] == '\n')
      s[file_stream - 1] = '\0';

    if (*s == '\0')
      continue;

    if (cmd_read(s, file_stream) == 2)
      break;
  } while (1);

  free(s);
  s = NULL;
  return (0);
}
