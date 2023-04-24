#include "myShell.h"


void execute_ls(char **av, char **env)
{
    pid_t child_pid;
    int status;
    char *ls_path;
    char *new_path;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        
        ls_path = getenv("LS_PATH");
        if (ls_path == NULL)
        {
            fprintf(stderr, "No se encontró la variable de entorno LS_PATH\n");
            exit(EXIT_FAILURE);
        }

        new_path = malloc(strlen(ls_path) + strlen(getenv("PATH")) + 2);
        if (new_path == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(new_path, "%s:%s", ls_path, getenv("PATH"));
        setenv("PATH", new_path, 1);
        free(new_path);

      
        execve("/bin/ls", av, env);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(&status);
    }
}

#define MAX_COMMAND 10

void prompt(char **av, char **env)
{
    char *string = NULL;
    size_t n = 0;
    ssize_t num_char;
    char *argv[MAX_COMMAND];
    pid_t child_pid;
    int i, j;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("cisfun$ ");
        num_char = getline(&string, &n, stdin);
        if (num_char == -1)
        {
            free(string);
            exit(EXIT_SUCCESS);
        }

         i = 0;
        while (string[i])
        {
            if (string[i] == '\n')
                string[i] = 0;
            i++;
        }

        j = 0;
        argv[j] = strtok(string, " ");
        while (argv[j] != NULL)
        {
            argv[++j] = strtok(NULL, " ");
        }

        if (strcmp(argv[0], "ls") == 0)
        {
            execute_ls(argv, env);
            continue;
        }

        child_pid = fork();
        if (child_pid == -1)
        {
            free(string);
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            if ((argv[0] == NULL) || strlen(argv[0]) == 0)
            {
                continue;
            }
            else if (execve(argv[0], argv, env) == -1)
            {
                printf("%s: No such file or directory\n", av[0]);
            }
        }
        else
            wait(NULL);
    }
}

