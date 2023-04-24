#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


char *enter_line(void);
char **tokenizer(char *string);
char *find_path(char **env);
int _putchar(char c);
int tokenizer_path(char **arg, char **env);
int run_com(char **arg, char **av, char **env, char *lineptr, int np, int c);
char *length(char *str);
void _getenv(char **env);
void exit_shell(char **arg, char *lineptr, int _exit);

char *_strcat(char *stringOne, char *stringTwo);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *deli);
char *_strdup(char *string);
unsigned int _strcspn(char *s, char *accept);
size_t _strncmp(char *s1, char *s2, size_t n);
#endif
