#include "myShell.h"
{
    int num;
    int status = 0;

    do {
        printf(" ");
        scanf("%d", &num);

        if (num < 0) {
            printf("Error: El número debe ser positivo.\n");
            status = 1;
        } else {
            printf("El número ingresado es: %d\n", num);
        }
    } while (status);

    return 0;
}
