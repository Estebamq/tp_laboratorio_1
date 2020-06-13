#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <limits.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief
 *
 * \return Employee*
 *
 */
Employee* employee_new();
/** \brief
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief
 *
 * \param This Employee*
 * \return void
 *
 */
void employee_delete(Employee* This);

/** \brief
 *
 * \param This Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* This,int id);
/** \brief
 *
 * \param This Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* This,int* id);

/** \brief
 *
 * \param This Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* This,char* nombre);
/** \brief
 *
 * \param This Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* This,char* nombre);

/** \brief
 *
 * \param This Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* This,int horasTrabajadas);
/** \brief
 *
 * \param This Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* This,int* horasTrabajadas);

/** \brief
 *
 * \param This Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* This,int sueldo);
/** \brief
 *
 * \param This Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* This,int* sueldo);

/** \brief
 *
 * \param employeeI void*
 * \param employeeII void*
 * \return int
 *
 */
int employee_CompareByName(void* employeeI, void* employeeII);
/** \brief
 *
 * \param employeeI void*
 * \param employeeII void*
 * \return int
 *
 */
int employee_CompareById(void* employeeI, void* employeeII);

#endif // employee_H_INCLUDED
