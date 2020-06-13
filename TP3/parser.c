#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmple = employee_new();
    int retorno = 0;
    int rd ;
    char auxId[40];
    char auxNombre[40];
    char auxHsTrabajadas[40];
    char auxSalario[40];

    // Leo la primera fila que tiene las descripciones de los tipos de datos para que no se cargue en la estructura
    rd = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHsTrabajadas,auxSalario);

    while(!feof(pFile))
    {
        rd = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHsTrabajadas,auxSalario);
            if(rd==4)
            {
                auxEmple = employee_newParametros(auxId ,auxNombre, auxHsTrabajadas, auxSalario);
                ll_add(pArrayListEmployee, auxEmple );
                retorno++;
            }
     }
        printf("%d empleados fueron cargados a la lista en modo texto\n", retorno);

        return retorno;


}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee auxEmpleado;
    int retorno = 0;

    // Leo la primera fila que tiene las descripciones de los tipos de datos para que no se cargue en la estructura
    fread(&auxEmpleado, sizeof(Employee), 1, pFile);

    while(!feof(pFile))
    {
        Employee *nuevoEmpleado = employee_new();
        employee_setId(nuevoEmpleado,auxEmpleado.id);
        employee_setHorasTrabajadas(nuevoEmpleado,auxEmpleado.horasTrabajadas);
        employee_setNombre(nuevoEmpleado,auxEmpleado.nombre);
        employee_setSueldo(nuevoEmpleado,auxEmpleado.sueldo);
        retorno ++;
        ll_add(pArrayListEmployee, nuevoEmpleado);
        fread(&auxEmpleado, sizeof(Employee), 1, pFile);
    }
            printf("%d empleados fueron cargados a la lista en modo binario \n", retorno);

    return retorno;
}
