#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"


/** \brief recibie un string con el menu y devuelve la opcion seleccionada
 *
 * \return int valor del menu
 *
 */
int menu()
{
    int opcion;;
    system("cls");
    printf("  *** ABM EMPLOYEE ***\n\n");
    printf("1- Alta Empleado\n2- Modificacion Empleado\n3- Baja Empleado\n4- Informar sobre Empleados\n5- Salir\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
//********************************************************************************************************
/** \brief inicializa las etructuras para que esten libres
 *
 * \param recibe un array estructura
 * \param int cantidad del array
 * \return int retorna un entero para saber si se hizo o no la operacion
 *
 */
int employeeInit(eEmployee emple[],int cant)
{
    int i;
    int retorno = -1;

    for(i=0; i<cant; i++)
    {
        emple[i].isEmpty=1;
        retorno = 0;
    }

    return retorno; //Devuelve -1 si no logra inicializar los estados o 0 cuando lo hace
}
//********************************************************************************************************
/** \brief Busca un lugar libre y me devuelve el indice de ese lugar
 *
 * \param recibe un array estructura
 * \param int cantidad del array
 * \return int retorna un entero como el indice o -1 si no completa la operacion
 *
 *
 */
int isEmpty(eEmployee emple[],int tam)
{
    int i;
    int indice=-1;//Su valor es -1 si no logra encontrar lugar vacio


    for(i=0; i<tam; i++)
    {
        if(emple[i].isEmpty==LIBRE)
        {
            indice=i;
        }
    }
    return indice;//Devuelve el lugar vacio o -1
}
//*********************************************************************************************************
/** \brief Busca el empleado por id, recibe la estructura, el tamaño del array estructura y el id a buscar
 *
 * \param Recibe un array estructura
 * \param int tamaño
 * \param int Id
 * \return int indice retorna el indice(lugar conde se guardo)
 *
 */
int findEmployeeById(eEmployee emple[],int tam,int id)
{

    int i;
    int indice=-1;//Su valor es -1 si no logra encontrar lugar vacio


    for(i=0; i<tam; i++)
    {
        if(emple[i].id==id)
        {
            indice=i;
            break;
        }
    }
    return indice;//Devuelve el id o -1
}
//********************************************************************************************************
/** \brief Ingreso de empleado,ingresa el id, el nombre, apellido, salario y sector
 *
 * \param emple[] eEmployee
 * \param tam int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int retorna un entero si logra hacer la operacion
 *
 */
int addEmployees(eEmployee emple[],int tam,int id, char name[],char lastName[],float salary,int sector)
{
    int indice;

    indice=isEmpty(emple,tam);

    if(indice!=-1) //ingresa si encuentra lugar vacio
    {

        strcpy(emple[indice].name,name);
        strcpy(emple[indice].lastName,lastName);
        emple[indice].id=id;
        emple[indice].salary=salary;
        emple[indice].sector=sector;
        emple[indice].isEmpty=OCUPADO;
        emple[indice].id= id;

    }


    return indice;
}
//********************************************************************************************************
/** \brief Muestra un empleado
 *
 * \param emple eEmployee
 * \return int retorna un entero si pudo mostrarlo
 *
 */
int printEmployee(eEmployee emple)
{

    int retorno;

    printf("\t%5d\t%8s\t%5s\t%15.2f\t%13d\n", emple.id, emple.name, emple.lastName, emple.salary, emple.sector);
    retorno = 0;

    return retorno;

}

//*******************************************************************************************************

/** \brief Muestra todos los empleados ingresados
 *
 * \param emple[] eEmployee
 * \param tam int
 * \return int retorna un entero 1 si logro hacer la operacion sino retorna un -1
 *
 */
int printEmployees(eEmployee emple[],int tam)
{
    int i;
    int retorno =-1;
    printf("\t ID \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\t\n");
    for(i=0; i<tam; i++)
    {
        if(emple[i].isEmpty==OCUPADO)//muestra en pantalla los estados que esten ocupados
        {

            retorno=printEmployee(emple[i]);
        }
    }
    return retorno;

}
//******************************************************************************************************
/** \brief Da de baja un empleado(baja logica)
 *
 * \param empl[] eEmployee
 * \param tam int
 * \param id int
 * \return int retorna un 1 si logra hacer la operacion, sino retorna -1
 *
 */
int removeEmployee(eEmployee empl[],int tam, int id)
{
    int i;
    int retorno=-1;
    char respuesta;


    for(i=0; i<tam; i++)
    {
        if(empl[i].id==id && empl[i].isEmpty==OCUPADO)
        {
            printf("****Empleado que se dara de baja*****\n");
            printEmployee(empl[i]);
            printf("Dar de baja?s/n ");
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
//**************************************************************************************************
/** \brief Modifica los datos del empleado, recibiendo el ID para modificarlo
 *
 * \param empl[] eEmployee
 * \param tam int
 * \param id int
 * \return int retornac 1 si logro hacer hacer la operacion o -1 si no lo hizo
 *
 */
int modifyEmployee(eEmployee empl[],int tam, int id)
{
    int i;
    int retorno=-1;
    int respuestaModificar;
    char respuesta;
    char seguir;
    int indice=findEmployeeById(empl,tam,id);
    for(i=0; i<tam; i++)
    {
        if( indice!=-1 && empl[i].isEmpty==OCUPADO)
        {
            system("cls");
            printf("*****Empleado que se modificara******\n");
            printf("\t ID \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\t\n");
            printEmployee(empl[indice]);
            printf("Desea Modificar el empleado?s/n ");
            fflush(stdin);
            scanf("%c",&respuesta);
            if(respuesta== 's')
            {
                system("cls");
                do
                {
                    printf("*****Empleado que se modificara******\n");
                    printf("\t ID \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\t\n");
                    printEmployee(empl[indice]);
                    printf("Que desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n Respuesta: ");
                    scanf("%d",&respuestaModificar);
                    switch(respuestaModificar)
                    {
                    case 1:
                        getName("ingrese el nuevo Nombre: ","Error \n",2,20,4,empl[indice].name);
                        break;
                    case 2:
                        getName("Ingrese el nuevo Apellido: ","Error \n",4,20,4,empl[indice].lastName);
                        break;
                    case 3:
                        getFloat("Ingrese nuevo el Salario: ","Error \n",4,6,4,&empl[indice].salary);
                        break;
                    case 4:
                        getUnsignedInt("ingrese el nuevo sector: ","Error \n",1,4,4,&empl[i].sector);
                        break;
                    default:
                        printf("Error: Numero no Valido");
                    }
                    system("pause");
                    system("cls");
                    printf("Desean seguir modificando datos?s/n: ");
                    fflush(stdin);
                    scanf("%c",&seguir);
                }
                while(seguir=='s');
                retorno=1;
            }
            break;
        }
    }
    return retorno;
}

//***********************************************************************************************
/** \brief fuerza el ingreso de datos para testear el programa
 *
 * \param empleado[] eEmployee
 * \param tam int
 * \return void no retorna nada
 *
 */
void harcodeStruct(eEmployee empleado[],int tam )
{
    int  id[]= {1,2,3,4};
    char nombres[][10]= {"Mati","Cristian","Marce","Hernan"};
    char Apellido[][10]= {"Quiroz","Ponce","Quiroz","Sanchez"};
    float salario[]= {200,300,444,777};
    int sector[]= {1,2,3,4};
    int estado=OCUPADO;
    int i;
    for(i=0; i<tam; i++)
    {
        strcpy(empleado[i].name,nombres[i]);
        strcpy(empleado[i].lastName,Apellido[i]);
        empleado[i].id=id[i];
        empleado[i].salary=salario[i];
        empleado[i].sector=sector[i];
        empleado[i].isEmpty=estado;

    }

}

//**********************************************************************************************
/** \brief Ordena empleados por Apellido si encuentra uno igual lo ordena por sector
 *
 * \param empl[] eEmployee
 * \param tam int
 * \return int un 1 si logra realizar la operacion o -1 si no lo logra
 *
 */
int sortEmployees(eEmployee empl[],int tam)
{
    int i;
    int j;
    eEmployee aux;
    int retorno =-1;


    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(empl[i].lastName,empl[j].lastName)>0)
            {
                aux=empl[i];
                empl[i]=empl[j];
                empl[j]=aux;
                if(strcmp(empl[i].lastName,empl[j].lastName)==0 && empl[i].sector<empl[j].sector)
                {
                    aux=empl[i];
                    empl[i]=empl[j];
                    empl[j]=aux;
                }

                retorno=0;
            }
        }
    }
    return retorno;
}

//*******************************************************************************************************

/** \brief verifica si hay empleados ingresados
 *
 * \param emple[] eEmployee
 * \param tam int
 * \return int retorna un entero 1 si logro hacer la operacion sino retorna un -1
 *
 */
int emptyEmployees(eEmployee emple[],int tam)
{
    int i;
    int retorno =-1;
    for(i=0; i<tam; i++)
    {
        if(emple[i].isEmpty==OCUPADO)//muestra en pantalla los estados que esten ocupados
        {

            retorno=printEmployee(emple[i]);
        }
    }
    return retorno;

}

//*******************************************************************************************************

/** \brief Muestra el total de los sueldos, el promedio de los mismos y la cantidad de empleados que superan ese promedio
 *
 * \param emple[] eEmployee
 * \param tam int
 * \return int retorna un entero 1 si logro hacer la operacion sino retorna un -1
 *
 */
int printPromedEmployees(eEmployee emple[],int tam)
{
    int i;
    int retorno =-1;
    int contadorSalario=0;
    float acumuladorSalario;
    int cantEmpleados=0;
    float promedio;

    printf("TOTAL SALARIO \t   PROMEDIO SALARIO \t    CANTIDAD DE EMPLEADOS CON SALARIO MAYOR AL PROMEDIO\t\n");
    for(i=0; i<tam; i++)
    {
        if(emple[i].isEmpty==OCUPADO)//muestra en pantalla los estados que esten ocupados
        {

            retorno=0;
            acumuladorSalario+=emple[i].salary;
            contadorSalario++;
        }
    }
        if(contadorSalario!=0)
        {
            promedio = acumuladorSalario/contadorSalario;
            for(i=0; i<tam; i++)
            {
                if(promedio<emple[i].salary && emple[i].isEmpty==OCUPADO)
                {
                    cantEmpleados++;
                }
            }
            printf("%f \t %18.3f \t %18d\n",acumuladorSalario,promedio,cantEmpleados);
        }

    return retorno;

}
