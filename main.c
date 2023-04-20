#include "myShell.h"
#define MAX_COMMAND_LENGTH 256

int main(void) {
    char command[MAX_COMMAND_LENGTH]; // Almacena el comando ingresado por el usuario
    int status; // Almacena el estado de ejecución del comando

    while (1) {
        printf("MiShell> "); // Mostrar el prompt
        fgets(command, MAX_COMMAND_LENGTH, stdin); // Leer el comando ingresado por el usuario
        command[strcspn(command, "\n")] = '\0'; // Eliminar el carácter de nueva línea al final del comando

        if (strcmp(command, "exit") == 0) {
            // Salir del intérprete cuando se ingresa el comando "exit"
            break;
        }

        pid_t pid = fork(); // Crear un nuevo proceso hijo

        if (pid == 0) {
            // Proceso hijo
            char *args[] = {command, NULL}; // Crear un arreglo de argumentos para execve, el último elemento debe ser NULL
            execve(command, args, environ); // Ejecutar el comando con execve, pasando el arreglo de argumentos y el entorno

            // Si execve retorna, significa que ha ocurrido un error
            perror("Error al ejecutar el comando");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error al crear el proceso hijo
            perror("Error al crear el proceso hijo");
            exit(EXIT_FAILURE);
        } else {
            // Proceso padre
            waitpid(pid, &status, 0); // Esperar a que el proceso hijo termine
        }
    }

    return 0;
}
