#ifndef MYSHELL_H
#define MYSHELL_H
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "builtins.h"

void shell_exit(char **args);
void shell_cd(char **args);
void shell_help(char **args);
int shell_num_builtins(void);
void shell_exec(char **args);
char **shell_split_line(char *line);
char *shell_read_line();
int main(void);
#endif
