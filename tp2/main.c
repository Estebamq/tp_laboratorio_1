#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployee.h"
#define TAM 1000



int main()
{
    eEmployee emple[TAM];
    employeeInit(emple,TAM);
    harcodeStruct(emple,4);
    char seguir;
    char name[20];
    char lastName[20];
    float salary;
    int sector;
    int id=100;
    int idBaja;
    int respBaja;
    int idModifica;
    int retornoNombre;
    int retornoApellido;
    int retornoSalario;
    int retornoSector;

    do
    {
        switch(menu())
        {

        //ALTA EMPLEADO
        case 1:
            system("cls");
            printf("\n\t***ALTA EMPLEADO***\n\n");
           retornoNombre=getName("ingrese el Nombre: ","Error \n",2,20,2,name);
            retornoApellido=getName("Ingrese el Apellido: ","Error \n",4,20,2,lastName);
            retornoSalario=getFloat("Ingrese el Salario: ","Error \n",4,6,2,&salary);
            retornoSector=getUnsignedInt("ingrese el sector: ","Error \n",1,4,2,&sector);
            if(retornoNombre!=-1 && retornoApellido!=-1 && retornoSalario!=-1 && retornoSalario!=-1 && retornoSector!=-1 )
            {   addEmployees(emple,TAM,id,name,lastName,salary,sector);
                printf("El ALTA del empleado se realizo con exito!!!\n");
                id++;
                system("pause");
            }
            else
            {
                printf("NO se pudo realizar el ALTA del empleado!!!\n");
            }
            system("pause");
            break;
        //MODIFICA EMPLEADO
        case 2:
            if(emptyEmployees(emple,TAM)!=-1)
            {
                system("cls");
                printf("\nMODIFICAR empleado\n\n");
                printEmployees(emple,TAM);
                printf("Ingrese el ID del empleado a  MODIFICAR: ");
                scanf("%d",&idModifica);
                modifyEmployee(emple,TAM,idModifica);
                system("pause");
            }
            else
            {
                printf("no ingreso empleados");
            }
            break;

        //BAJA EMPLEADO
        case 3:
            if(emptyEmployees(emple,TAM)!=-1)
            {
                system("cls");
                printf("\n\t\tBAJA empleado\n\n");
                printEmployees(emple,TAM);
                printf("Ingrese el ID del empleado a dar de baja: ");
                scanf("%d",&idBaja);
                respBaja = removeEmployee(emple,TAM,idBaja);
                if(respBaja!=-1)
                {
                    printf("La BAJA se realizo con Exito!!\n");

                }
                else
                {
                    printf("ERROR: Id invalido o id dado de baja\n");
                }
                system("pause");
            }
            else
            {
                printf("no ingreso empleados");
            }
            break;

        //MUESTRA EMPLEADO
        case 4:
          if(emptyEmployees(emple,TAM)!=-1)
            {
                system("cls");
                sortEmployees(emple,TAM);
                printf("\t\t\t***Lista de Empleados***\n\n");
                printEmployees(emple,TAM);
                printPromedEmployees(emple,TAM);
                system("pause");
            }
            else
            {
                printf("no ingreso empleados");
            }
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
