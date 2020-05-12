#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployee.h"
#define TAM 1000



int main()
{
    eEmployee emple[TAM];
    employeeInit(emple,TAM);
    harcodeStruct(emple,TAM);
    char seguir;
    int id=100;
    int idBaja;
    int retorno;
    int respBaja;
    int idModifica;

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            retorno=addEmployees(emple,TAM,id);
            if(retorno!=-1)
            {
                printf("El ALTA del empleado se realizo con exito!!!\n");
                id++;
            }
            else
            {
                printf("NO se pudo realizar el ALTA del empleado!!!\n");
            }
            system("pause");
            break;

        case 2:
            system("cls");
            printf("\nMODIFICAR empleado\n\n");
            printEmployees(emple,TAM);
            printf("Ingrese el ID del empleado a  MODIFICAR: ");
            scanf("%d",&idModifica);
            modifyEmployee(emple,TAM,idModifica);
            system("pause");
            break;

        case 3:
            system("cls");
            printf("\n\t\tBAJA empleado\n\n");
            printEmployees(emple,TAM);
            printf("Ingrese el ID del empleado a dar de baja: ");
            scanf("%d",&idBaja);
            respBaja = removeEmployee(emple,TAM,idBaja);
            if(respBaja!=-1)
            {
                printf("La BAJA se realizo con Exito!!\n");

            }else{
                printf("ERROR: Id invalido o id dado de baja\n");
            }
            system("pause");
            break;

        case 4:
            system("cls");
            printf("\t\t\t***Lista de Empleados***\n\n");
            printEmployees(emple,TAM);
            system("pause");
            break;


        case 5:
            system("cls");
            printf("\nDesea salir s/n?: ");
            fflush(stdin);
            scanf("%s",&seguir);
            if(seguir=='s')
            {
                printf("\n Usted SALIO!!");
            }
            break;
        default:
            printf("/nOpcion incorrecta! \n");
            system("pause");
            fflush(stdin);
        }


    }
    while(seguir != 's');

    return 0;

}
