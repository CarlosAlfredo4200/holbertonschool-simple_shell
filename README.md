# My Shell- C ***simple shell***
![](https://st2.depositphotos.com/1084193/8786/v/600/depositphotos_87862980-stock-illustration-dna-abstract-icon-and-element.jpg)
## My shell

My shell is a basic command line interface that prints a prompt for the user to type a command and then prints exactly what the user typed on the next line.

## **Description**

My shell is a program that provides a user interface for accessing the services of an operating system and executing commands. The shell program reads user input and interprets it as commands to be executed by the system. The shell uses system calls to interact with the operating system and execute commands.

The basic structure of a simple shell program consists of a loop that repeatedly reads user input, parses it into tokens and executes the command. The shell supports several types of commands, including built-in commands such as cd, exit, and env, and external commands that require the execution of an executable file. The shell also supports redirection and I/O piping commands, allowing the user to redirect command input and output or to pipe the output of one command as input to another.

A simple shell can be extended to include additional features such as command history, command completion and scripting capabilities. Shell scripts allow users to automate repetitive tasks by creating scripts that execute multiple commands sequentially. 

### **Compilation**


All files will be compiled with the following: 


        * gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## **Builtins Fns**
There are two builtins programmed into the shell. Below is a description and use for each builtin.

* env - The env command is a command that tells the shell program to display all of the environment variables with their values. It is a way to access those values through the shell.

## **Exiting commands and the shell**
To exit out of a command or process the user can use ctrl c. Control c stops a process and causes it to abort. The user can also utilize the command ctrl D which will just exit. When the command ctrl D is used an exit status of 0 is given. Using exit, you can input its exit status or it is defaulted to the status of the last command executed.

# **Files**

1. README.md : Current file, contains information about this project.
2. BuiltinsFns: builtins funtions
3. Authors: This file lists all individuals having contributed content to the repository.
4. FnNoInteractive: a function or shell script that executes automatically without the need for direct user interaction
5. Inicializer funtions: execute commands on a Unix/Linux-like operating system, using a child process approach to execute external commands or path commands, and        waiting for the completion of the child processes before continuing on to the parent process.
6. RecyclingFns: Recycling of previously coded functions, with customized features
7. shell.h: Headers and variables file
8. shell main.c: Main function (prompt) is executed until an exit condition occurs, such as program termination or an interrupt signal.
9. shellutills: contains functions to process the PATH, env and executing

# Authors
* Carlos Alfredo Montoya Goez
* Camilo Palacios
