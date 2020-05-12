#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"

int menu()
{
    int opcion;;
    system("cls");
    printf("  *** ABM EMPLOYEE ***\n\n");
    printf("1- Alta Empleado\n2- Modificacion Empleado\n3- Baja Empleado\n4- Informar sobre Empleados\n5- Salir\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
int employeeInit(eEmployee emple[],int cant)
{   int i;
    int retorno = -1;

        for(i=0; i<cant; i++)
        {
                    emple[i].isEmpty=1;
                    retorno = 0;
        }

    return retorno; //Devuelve -1 si no logra inicializar los estados o 0 cuando lo hace
}
int isEmpty(eEmployee emple[],int tam)
{
        int i;
        int indice=-1;//Su valor es -1 si no logra encontrar lugar vacio


        for(i=0;i<tam;i++){
                if(emple[i].isEmpty==LIBRE)
                {
                    indice=i;
                }
        }
        return indice;//Devuelve el lugar vacio o -1
}


int addEmployees(eEmployee emple[],int tam,int id)
{
        int indice;


            indice=isEmpty(emple,tam);

            if(indice!=-1){//ingresa si encuentra lugar vacio

                        system("cls");
                        printf("\n\t***ALTA EMPLEADO***\n\n");
                        printf("ingrese el Nombre: ");
                        fflush(stdin);
                        gets(emple[indice].name);
                        printf("Ingrese el Apellido: ");
                        fflush(stdin);
                        gets(emple[indice].lastName);
                        printf("Ingrese el Salario: ");
                        scanf("%f",&emple[indice].salary);
                        printf("ingrese el sector:\n1.RR.HH.\n2.Produccion\n3.Deposito\n4.Administracion\n\n Elija una opcion: ");
                        scanf("%d",&emple[indice].sector);
                        emple[indice].isEmpty=OCUPADO;
                        emple[indice].id= id;
                        system("pause");

            }


    return indice;
}

int printEmployee(eEmployee emple)
{

       int retorno;

        printf("\t%5d\t%8s\t%5s\t%15.2f\t%13d\n", emple.id, emple.name, emple.lastName, emple.salary, emple.sector);
        retorno = 0;

    return retorno;

}



int printEmployees(eEmployee emple[],int tam)
{
    int i;
    int retorno =-1;
    printf("\t ID \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\t\n");
    for(i=0;i<tam;i++)
        {
            if(emple[i].isEmpty==OCUPADO)//muestra en pantalla los estados que esten ocupados
                {

                    retorno=printEmployee(emple[i]);
                }
        }
   return retorno;

}
int removeEmployee(eEmployee empl[],int tam, int id)
{
    int i;
    int retorno=-1;
    char respuesta;
    int rest;

    for(i=0;i<tam;i++)
        {
            if(empl[i].id==id && empl[i].isEmpty==OCUPADO)
                {
                    printf("****Empleado que se dara de baja*****\n");
                    rest=printEmployee(empl[i]);
                    printf("Dar de baja?s/n ");
                    // printEmployee();
                    fflush(stdin);
                    scanf("%c",&respuesta);
                    if(respuesta== 's')
                        {
                            empl[i].isEmpty=LIBRE;
                            retorno=1;
                        }
                      break;
                }
        }
    return retorno;
}

int modifyEmployee(eEmployee empl[],int tam, int id)
{
    int i;
    int retorno=-1;
    int respuestaModificar;
    char respuesta;
    char seguir;

    for(i=0;i<tam;i++)
        {
            if(empl[i].id==id && empl[i].isEmpty==OCUPADO)
                {   system("cls");
                    printf("*****Empleado que se modificara******\n");
                    printf("\t ID \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\t\n");
                    printEmployee(empl[i]);
                    printf("Desea Modificar el empleado?s/n ");
                    fflush(stdin);
                    scanf("%c",&respuesta);
                    if(respuesta== 's')
                        {
                            system("cls");
                            do{
                            printf("*****Empleado que se modificara******\n");
                            printf("\t ID \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\t\n");
                            printEmployee(empl[i]);
                            printf("Que desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n Respuesta: ");
                            scanf("%d",&respuestaModificar);
                            switch(respuestaModificar)
                            {
                                case 1:
                                    printf("Ingrese nuevo nombre: ");
                                    fflush(stdin);
                                    gets(empl[i].name);

                                break;
                                case 2:
                                    printf("Ingrese nuevo Apellido: ");
                                    fflush(stdin);
                                    gets(empl[i].lastName);
                                break;
                                case 3:
                                    printf("Ingrese nuevo Salario: ");
                                    scanf("%f",&empl[i].salary);
                                break;
                                case 4:
                                    printf("Ingrese nuevo Sector: ");
                                    scanf("%d",&empl[i].sector);
                                    break;
                                default:
                                    printf("Error: Numero no Valido");
                            }
                            system("pause");
                            system("cls");
                            printf("Desean seguir modificando datos?s/n: ");
                            fflush(stdin);
                            scanf("%c",&seguir);
                            }while(seguir=='s');
                            retorno=1;
                        }
                      break;
                }
        }
    return retorno;
}

void harcodeStruct(eEmployee empleado[],int tam )
{
    int  id[4]={1,2,3,4};
    char nombres[4][10]={"Mati","Cristian","Marce","Hernan"};
    char Apellido[4][10]={"Quiroz","Ponce","quiroz","Sanchez"};
    float salario[4]={200,300,444,777};
    int sector[4]={1,2,3,4};
    int estado=OCUPADO;
    int i;
    for(i=0;i<4;i++)
        {
            strcpy(empleado[i].name,nombres[i]);
            strcpy(empleado[i].lastName,Apellido[i]);
            empleado[i].id=id[i];
            empleado[i].salary=salario[i];
            empleado[i].sector=sector[i];
            empleado[i].isEmpty=estado;

        }

}
