#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;
    int seguir;

    do{
        printf("1- Ingresar operando Uno:");
        printf("\n2- Ingresar operando Uno:");
        printf("\n3- Ingresar operando Uno:");
        printf("\n4- Ingresar operando Uno:");
        printf("\n5- SALIR");
        printf("\n Elija una opcion: ");
        scanf("%d",&seguir);

    }while(seguir != 5);
    return 0;
}
