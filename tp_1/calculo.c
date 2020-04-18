
#include "calculo.h"




/** \brief Funcion Suma
 *
 * \param a int
 * \param b int
 * \return int
 *
 */
int sumar(int a,int b){
int resultado;

resultado = a + b;

return resultado;

}



/** \brief Funcion Resta
 *
 * \param a int
 * \param b int
 * \return int
 *
 */
int restar(int a, int b){
int resultado;

resultado = a - b;

return resultado;
}



/** \brief Funcion Dividir
 *
 * \param a int
 * \param b int
 * \return float
 *
 */
float dividir(int a, int b){
float resultado;

resultado = (float)a / b;

return resultado;
}



/** \brief Funcion Multiplicar
 *
 * \param a int
 * \param b int
 * \return int
 *
 */
int multiplicar(int a, int b){
int resultado;

resultado = a*b;

return resultado;
}


/** \brief Funcion Factorial
 *
 * \param a int
 * \return int
 *
 */
int factorial(int a)
{

   int resultado;

    if (a == 0)
        {
             resultado = 1;
        }

    else
    {
        resultado = a* factorial(a-1);
    }
    return resultado;
}


