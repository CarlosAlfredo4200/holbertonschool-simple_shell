#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int envPrint(void);
char *_strdup(char *string);
int cmd_read(char *s, size_t file_stream __attribute__((unused)));
char *fnPath(char *command);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);
char *_getenv(char *var);
int compStr(char *s1, char *s2, int n);
int main(int argc, char *argv[]);
#endif