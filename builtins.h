#ifndef BUILTINS_H
#define BUILTINS_H


struct builtin {
  char *name;
  void (*func)(char **args);
};


extern struct builtin builtins[];

#endif
