# My Shell- C ***simple shell***
![](https://st2.depositphotos.com/1084193/8786/v/600/depositphotos_87862980-stock-illustration-dna-abstract-icon-and-element.jpg)
## My shell

My shell is a basic command line interface that prints a prompt for the user to type a command and then prints exactly what the user typed on the next line.

## **Syntax**

Myhell executes the commands entered by the user along with the arguments provided. 

In the "man" file, which can be used to access the manual for a given command or any command for more information, including system calls, libraries and important files.

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
