#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OCUPADO 0
#define LIBRE 1

typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;



int menu();
int employeeInit(eEmployee emple[],int cant);
int addEmployees(eEmployee emple[],int tam, int id);
int printEmployees(eEmployee emple[],int tam);
int printEmployee(eEmployee emple);
int removeEmployee(eEmployee empl[],int, int id);
int modifyEmployee(eEmployee empl[],int, int id);
void harcodeStruct(eEmployee empleado[],int tam );
int findEmployeeById(eEmployee emple[],int tam,int id);
int sortEmployees(eEmployee empl[],int tam);

