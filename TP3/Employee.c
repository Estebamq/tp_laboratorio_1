#include <stdlib.h>
#include "Employee.h"
#include <string.h>


Employee* employee_new()
{
  Employee* employee;
  employee = (Employee*)calloc(sizeof(Employee),1);

  return employee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* employee;
    employee = employee_new();

    employee->id=atoi(idStr);
    strcpy(employee->nombre,nombreStr);
    employee->horasTrabajadas = atoi(horasTrabajadasStr);
    employee->sueldo = atoi(sueldoStr);
    return employee;

}

void employee_delete(Employee* This)
{
    if(This!=NULL)
        free(This);
}

int employee_setNombre(Employee* This,char* nombre)
{
    int retorno=0;

    if(This!=NULL && nombre!=NULL)
    {
        strcpy(This->nombre,nombre);
        retorno = 1;
    }

    return retorno;


}

int employee_getNombre(Employee* This,char* nombre)
{
    int retorno = 0;

    if(This!=NULL)
    {
        strcpy(nombre,This->nombre);
        retorno=1;
    }

    return retorno;

}



int employee_setSueldo(Employee* This,int sueldo)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->sueldo=sueldo;
        retorno = 1;
    }

    return retorno;

}
int employee_getSueldo(Employee* This,int* sueldo)
{
    int retorno=0;

    if(This!=NULL)
    {
        *sueldo = This->sueldo;
        retorno = 1;
    }

    return retorno;

}

int employee_setId(Employee* This,int id)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->id=id;
        retorno = 1;
    }

    return retorno;

}
int employee_getId(Employee* This,int* id)
{
    int retorno=0;

    if(This!=NULL)
    {
        *id = This->id;
        retorno = 1;
    }

    return retorno;

}

int employee_setHorasTrabajadas(Employee* This,int horasTrabajadas)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->horasTrabajadas=horasTrabajadas;
        retorno = 1;
    }

    return retorno;

}
int employee_getHorasTrabajadas(Employee* This,int* horasTrabajdas)
{
    int retorno=0;

    if(This!=NULL)
    {
        *horasTrabajdas = This->horasTrabajadas;
        retorno = 1;
    }

    return retorno;


}


int employee_CompareByName(void* employeeI, void* employeeII)
{
     int retorno;
     char auxNameI [60];
     char auxNameII[60];

    if((employeeI != NULL)&&(employeeII !=NULL))
    {
        employee_getNombre(employeeI, auxNameI);
        employee_getNombre(employeeII, auxNameII);

        retorno = strcmp(auxNameI, auxNameII);

    }

    return retorno;
}

int employee_CompareById(void* employeeI, void* employeeII)
{

    int retorno;

    if((employeeI != NULL)&&(employeeII !=NULL))
    {
        int auxIdA, auxIdB;
        employee_getId(employeeI,&auxIdA);
        employee_getId(employeeII,&auxIdB);

        if(auxIdA > auxIdB)
        {
            retorno = 1;
        }
        else if(auxIdA == auxIdB)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }



    }
    return retorno;
}

int employee_CompareBySueldo(void* employeeI, void* employeeII)
{

    int retorno;

    if((employeeI != NULL)&&(employeeII !=NULL))
    {
        int auxIdA, auxIdB;
        employee_getSueldo(employeeI,&auxIdA);
        employee_getSueldo(employeeII,&auxIdB);

        if(auxIdA > auxIdB)
        {
            retorno = 1;
        }
        else if(auxIdA == auxIdB)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }



    }
    return retorno;
}

int employee_CompareByHsHombre(void* employeeI, void* employeeII)
{

    int retorno;

    if((employeeI != NULL)&&(employeeII !=NULL))
    {
        int auxIdA, auxIdB;
        employee_getHorasTrabajadas(employeeI,&auxIdA);
        employee_getHorasTrabajadas(employeeI,&auxIdB);

        if(auxIdA > auxIdB)
        {
            retorno = 1;
        }
        else if(auxIdA == auxIdB)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }



    }
    return retorno;
}


