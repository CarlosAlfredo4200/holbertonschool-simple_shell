# -base- My Shell- C ***simple shell***
![](https://st2.depositphotos.com/1084193/8786/v/600/depositphotos_87862980-stock-illustration-dna-abstract-icon-and-element.jpg)
## CCSH

CCSH is a basic command line interface that prints a prompt for the user to type a command and then prints exactly what the user typed on the next line.

For proper compilation it uses:

* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## **Example of how to launch the shell after compiling:**

 *   ./shell

        *       Output: prompt to terminal: $ 

## **Syntax**

The shell works by using commands given by the user input. The shell commands take in the following syntax: command name {arguments}. The shell executes a command after it is written by user using the command followed by the arguments.

cat holberton.h The above example takes in a command by the user followed with the arguments. In this case the command is cat (to view file without opening file) followed by argument the file name in this case holberton.h.

For more information on cat, you can use the man command which will show a manual of the given command or any command you wish to know more information on. It contains system calls, libraries and other important files.

The shell also contains two builtins which are commands that are within the shell itself. The two builtins are exit and env. You can also use help command to know which builtins are provided by the shell. The help command works similarly to the manual where it provides further detail or information on given builtin.

### **Compilation**


All files will be compiled with the following: 


        * gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## **List of useful commands**
* ls - will list all files and directories in current working directory
* /bin/ls - command is used to run the "ls" program from the "/bin" location on a Unix system.
* /bin/ls -l - on a command line on a Unix system will display a list of files and directories in the current directory (or in a specified directory if provided with     an additional argument) with detailed information for each.
* ls -l /pmp - will display a list of files and directories in the "/tmp" directory with detailed information for each one. 
* exit - can be used within a shell script to terminate the execution of the script.

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
