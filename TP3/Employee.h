#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "validation.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea espacio para un nuevo empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief crea el espacio para un empleado con parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief DA de baja un empleado
 *
 * \param This Employee*
 * \return void
 *
 */
void employee_delete(Employee* This);

/** \brief Set ID empleado
 *
 * \param This Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* This,int id);

/** \brief Get ID empleado
 *
 * \param This Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* This,int* id);

/** \brief Set NOMBRE empleado
 *
 * \param This Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* This,char* nombre);

/** \brief Get NOMBRE empleado
 *
 * \param This Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* This,char* nombre);

/** \brief Set HORAS TRABAJADAS empleado
 *
 * \param This Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* This,int horasTrabajadas);

/** \brief Get HORAS TRABAJADAS empleado
 *
 * \param This Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* This,int* horasTrabajadas);

/** \brief Set SUELDO empleado
 *
 * \param This Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* This,int sueldo);

/** \brief Get SUELDO empleado
 *
 * \param This Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* This,int* sueldo);

/** \brief Compara por NOMBRE a los empleados
 *
 * \param employeeI void*
 * \param employeeII void*
 * \return int
 *
 */
int employee_CompareByName(void* employeeI, void* employeeII);

/** \brief Compara por ID a los empleados
 *
 * \param employeeI void*
 * \param employeeII void*
 * \return int
 *
 */
int employee_CompareById(void* employeeI, void* employeeII);

/** \brief Compara por SUELDO a los empleados
 *
 * \param employeeI void*
 * \param employeeII void*
 * \return int
 *
 */
int employee_CompareBySueldo(void* employeeI, void* employeeII);

/** \brief Compara por HORAS DE TRABAJO a los empleados
 *
 * \param employeeI void*
 * \param employeeII void*
 * \return int
 *
 */
int employee_CompareByHsHombre(void* employeeI, void* employeeII);



#endif // employee_H_INCLUDED
