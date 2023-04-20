#ifndef SS_H
#define SS_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _printenv(void);
char *_strdup(char *string);
int cmd_read(char *s, size_t _attribute_((unused))file_stream);
char *pathfinder(char *cmd);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);
char *_getenv(char *var);
int _str_n_cmp(char *s1, char *s2, int n);
#endif