#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validation.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE *pArchivo;

    if((pArchivo = fopen(path, "r"))!=NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        retorno= 1;
    }
    else
    {

        printf("Error: no se puedo leer\n");

    }


    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE *pArchivo = fopen(path, "rb");
    if(pArchivo != NULL)
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        retorno= 1;

    }
    else
    {
        printf("Error: El archivo no se pudo cargar.\n");
    }

    fclose(pArchivo);


    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployees = employee_new();
    int retorno = 0;
    char auxId[40];
    char auxNombre[40];
    char auxHsTrabajadas[40];
    char auxSalario[40];
    int intAuxHstrabajadas;
    int intAuxSalario;
    int lenList = ll_len(pArrayListEmployee);
    int intAuxId;
    int i;

    if(pArrayListEmployee !=NULL)
    {
        getUnsignedInt("Ingrese id del nuevo empleado \n","Error",1,4,4,&intAuxId);
        itoa(intAuxId, auxId, 10);

        // VERIFICO QUE EL ID NO EXISTA
        for( i = 0; i <lenList ; i++ )
        {
            newEmployees = (Employee*)ll_get(pArrayListEmployee, i);
            if( newEmployees->id == intAuxId)
            {
                printf("Error: Ese ID ya esta en uso!\n");
                break;

            }
        }

        if( newEmployees->id != intAuxId)
        {
            //INGRESO DATOS CON EL ID VALIDADO
            getName("ingrese nombre \n","Error \n",2,20,4,auxNombre);
            getUnsignedInt("ingrese horas trabajadas \n","Error \n",1,10,4,&intAuxHstrabajadas);
            getUnsignedInt("ingrese salario \n","Error \n",1,10,4,&intAuxSalario);

            itoa(intAuxHstrabajadas,auxHsTrabajadas, 10);
            itoa(intAuxSalario, auxSalario, 10);

            newEmployees = employee_newParametros(auxId,auxNombre, auxHsTrabajadas, auxSalario);
            ll_add(pArrayListEmployee, newEmployees);
            retorno = 1;
        }
    }

    return retorno;

}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *auxEmployee;
    char auxNombre[40];
    int intAuxId;
    int intAuxSalario;
    int intAuxHsTrabajadas;
    int opcion;
    int listLen = ll_len(pArrayListEmployee);
    int i;
    int retorno=0;

    if(pArrayListEmployee != NULL)
    {
        getUnsignedInt("Ingrese el ID que desea modificar:  ","Error \n",1,4,4,&intAuxId);
        system("cls");
        for( i = 0; i <listLen ; i++ )
        {

            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if( intAuxId == auxEmployee->id )
            {
                do
                {
                    getUnsignedInt("**** Modificacion de empleado: Elija una opcion***** \n 1-modificar nombre\n 2-modificar horas trabajadas\n 3-modificar salario 4-Salir","Error \n",1,3,4,&opcion);
                    switch(opcion)
                    {
                    case 1:
                        getName("Ingrese nuevo nombre: ","Error \n",1,40,4,auxNombre);
                        employee_setNombre(auxEmployee, auxNombre);
                        break;
                    case 2:
                        getUnsignedInt("ingrese horas trabajadas: ","Error \n",1,5,4,&intAuxHsTrabajadas);
                        employee_setHorasTrabajadas(auxEmployee, intAuxHsTrabajadas);
                        break;
                    case 3:
                        getUnsignedInt("ingrese salario: ","Error \n",1,10,4,&intAuxSalario);
                        employee_setSueldo(auxEmployee, intAuxSalario);
                        break;
                    default:
                        if(opcion!=4)
                        {
                            printf("Opcion invalida");
                        }
                    }
                }
                while(opcion != 4);
                retorno=1;
            }
        }

    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    int listLen = ll_len(pArrayListEmployee);
    int i;
    int auxId;
    int retorno=0;

    if(pArrayListEmployee !=NULL)
    {
        getUnsignedInt("ingrese ID  a remover","Error \n",1,4,4,&auxId);

        for(i=0; i<listLen; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployee->id == auxId)
            {
                ll_remove(pArrayListEmployee, i);
                printf("Empleado borrado con exito!\n");
                employee_delete(auxEmployee);
                retorno=1;
                break;
            }
        }
        if( auxEmployee->id != auxId)
        {
            printf("Ese Id no existe.\n");
        }

    }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmployee;
    int retorno = 0;
    int auxId;
    char auxNombre[40];
    int auxHsTrabajadas;
    int auxSalario;
    int lenList = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL)
    {
        if(lenList>0)
        {
            printf("   Id\tNombre\tHoras trabajadas\tSueldo \n");

            for(i = 0; i < lenList; i++)
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(pAuxEmployee, &auxId);
                employee_getNombre(pAuxEmployee,auxNombre);
                employee_getHorasTrabajadas(pAuxEmployee,&auxHsTrabajadas);
                employee_getSueldo(pAuxEmployee,&auxSalario);
                printf("%5d  %10s %10d  %15d\n",auxId, auxNombre, auxHsTrabajadas, auxSalario);
            }

            retorno = 1;

        }
        else
        {
            printf("No se cargaron los datos.\n");
        }
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int sentido;
    int retorno=0;

    if(pArrayListEmployee != NULL)
    {
        getUnsignedInt("ingrese por que desea Ordenar:\n 1-Por id\n 2-Por Nombre\n 3-Por Horas trabajadas\n 4-Por Salario\n ","Error \n",1,3,4,&opcion);
        getUnsignedInt("Desea ordenar: \n 0-Descendente 1-Ascendente: ","Error \n",1,3,4,&sentido);

        switch(opcion)
        {
        case 1:


            if(sentido==0 || sentido==1)
            {
                ll_sort(pArrayListEmployee, employee_CompareById, sentido);
                retorno=1;
            }
            else
            {
                printf("opcion incorrecta\n");
            }
            break;
        case 2:

            if(sentido==0 || sentido==1)
            {
                ll_sort(pArrayListEmployee, employee_CompareByName, sentido);
                retorno=1;
            }
            else
            {
                printf("opcion incorrecta\n");
            }

            break;
        case 3:

            if(sentido==0 || sentido==1)
            {
                ll_sort(pArrayListEmployee, employee_CompareByHsHombre, sentido);
                retorno=1;
            }
            else
            {
                printf("opcion incorrecta\n");
            }

            break;
        case 4:

            if(sentido==0 || sentido==1)
            {
                ll_sort(pArrayListEmployee, employee_CompareBySueldo, sentido);
                retorno=1;
            }
            else
            {
                printf("opcion incorrecta\n");
            }

            break;
        default:
            printf("opcion incorrecta \n");
        }

    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int listLen = ll_len(pArrayListEmployee);
    Employee* pAuxEmpleado;
    FILE* pArchivo = fopen(path, "w");
    int i;
    int retorno=0;
    if(pArchivo != NULL)
    {

        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

        if(pArrayListEmployee!=NULL)
        {
            for(i = 0; i < listLen; i++)
            {
                pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(pArchivo, "%d,%s,%d,%d\n", pAuxEmpleado->id, pAuxEmpleado->nombre, pAuxEmpleado->horasTrabajadas, pAuxEmpleado->sueldo);
            }
            printf("Archivo guardado con exito\n");
        }

        retorno= 1;
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
    fclose(pArchivo);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmployee;
    FILE* pArchivo = fopen(path, "wb");

    int listLen = ll_len(pArrayListEmployee);
    int retorno=0;
    int i;

    if(pArchivo != NULL)
    {


        if(pArrayListEmployee!=NULL)
        {
            for(i = 0; i < listLen; i++)
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                fwrite(pAuxEmployee,sizeof(Employee), 1, pArchivo);
            }
            printf("Archivo .bin guardado\n");
            retorno=1;
        }
        else
        {
            printf("Error al guardar\n");
        }
    }
        fclose(pArchivo);
        return retorno;

    }

void menu(int* opcion)
{
    getUnsignedInt("********** TP 3 LINKEDLIST***************\n Menu:\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n 3. Alta de empleado. \n 4. Modificar datos de empleado\n 5. Baja de empleado.\n 6. Listar empleados.\n 7. Ordenar empleados.\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n 10. Salir\n Opcion: ","Error\n",1,3,4,opcion);
}
