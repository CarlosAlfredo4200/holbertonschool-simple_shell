#include "myShell.h"
char** shell_split_line(char *line) {


  int length = 0;
  int capacity = 16;
  char *delimiters;
  char *token;
  char **tokens;
  
  tokens = malloc(capacity * sizeof(char*));
  if (!tokens) {
    perror("shell");
    exit(1);
  }

  delimiters = " \t\r\n";
  token = strtok(line, delimiters);

  while (token != NULL) {
    tokens[length] = strdup(token);
    length++;

    if (length >= capacity) {
      capacity = (int) (capacity * 1.5);
      tokens = realloc(tokens, capacity * sizeof(char*));
      if (!tokens) {
        perror("shell");
        exit(1);
      }
    }

    token = strtok(NULL, delimiters);

  }
  tokens[length] = NULL;
  return tokens;

}
