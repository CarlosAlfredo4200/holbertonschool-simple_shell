#include "myShell.h"

char *name;

int main(int argc, char *argv[])
{
  char *s = NULL;
  size_t buffer_size = 0;
  ssize_t file_stream = 0;
  int status;
  pid_t is_child;

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
      free(s);
      exit(EXIT_FAILURE);
    }

    if (s[file_stream - 1] == '\n')
      s[file_stream - 1] = '\0';

    if (*s == '\0')
      continue;

    if (cmd_read(s, file_stream) == 2)
      break;

    is_child = fork();
    if (is_child < 0) {
      perror("Error:");
      free(s);
      exit(EXIT_FAILURE);
    }
    if (is_child > 0) {
      /* Proceso padre */
      waitpid(is_child, &status, 0);
    } else {
      /* Proceso hijo */
      char *args[] = {"/bin/ls", NULL};
      execve(args[0], args, environ);
      perror("Error:");
      free(s);
      exit(EXIT_FAILURE);
    }

  } while (1);

  free(s);
  s = NULL;
  return (0);
}
