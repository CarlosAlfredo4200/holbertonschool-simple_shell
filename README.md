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

* cat - prints and concatenates files to the standard output
* cp -copies a file into another file
* grep - helps to search for a file in a specific pattern
* less - will let you go backward and forward in the files
* ls - will list all files and directories in current working directory
* mv - helps to move one file into another file
* pwd - given you the current working directory

## **Builtins**
There are two builtins programmed into the shell. Below is a description and use for each builtin.

* env - The env command is a command that tells the shell program to display all of the environment variables with their values. It is a way to access those values through the shell.

## **Exiting commands and the shell**
To exit out of a command or process the user can use ctrl c. Control c stops a process and causes it to abort. The user can also utilize the command ctrl D which will just exit. When the command ctrl D is used an exit status of 0 is given. Using exit, you can input its exit status or it is defaulted to the status of the last command executed.

# **Files**

1. README.md : Current file, contains information about this project.
2. holberton.h : Header file, contains all prototypes for funcitons used, as well as libriaries
3. hsh.c: Main file that uses most functions and executes them within this file
4. ghostinshell.png: Image in readme file
5. _getenv.c : Contains the code for _printf
6. _getline.c: File for getting prompt and user input
7. which.c: File containing the specific functions for conversion specifiers
8. builtin_execute.c: Executing the builtins
9. builtins.c: File containing the two builtins
10. child.c: File that forks and creates parent child processee
11. free.c: File with free malloc functions
12. prompt.c: File with actual prompt line $
13. tokenizer.c: File that creates function to tokenize an array of strings
14. utility_functions.c: helper functions

# Authors
* Carlos Alfredo Montoya Goez
* Camilo Palacios
