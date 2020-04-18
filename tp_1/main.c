#include <stdlib.h>
#include "calculo.h"
#include<windows.h>

int main()
{
    system("COLOR 1f");
    // DECLARO VARIABLES
    int numero1;
    int numero2;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int resultadosFactorialUno;
    int resultadosFactorialDos;
    int opcion;
    int flagA=0;
    int flagB=0;


    //*****MENU DE LA CALCULADORA*****

    do
    {
        printf("\n...............CALCULADORA..............\n");
        if(flagA==0)
        {
            printf("\n1.Ingresar 1er operando (A = X )");
        }
        else
        {
            printf("\n1.Ingresar 1er operando (A = %d )",numero1);
        }
        if(flagB==0)
        {
            printf("\n2.Ingresar 2do operando (B = Y )" );
        }
        else
        {
            printf("\n2.Ingresar 2do operando (B = %d )",numero2);
        }
        printf("\n3.Calcular todas las operaciones");
        printf("\n a)Calcular la suma (A+B)\n b)Calcular la resta (A-B)\n c)Calcular la division (A/B)\n d)Calcular la multiplicacion (A*B)\n e)Calcular el factorial (A!) y (B!)\n");
        printf("4.Informar resultados \n5.SALIR");
        printf("\n.........................................\n");
        printf("\nElija una Opcion: ");

        fflush(stdin);
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:

            printf("el valor de A es =");
            scanf("%d", &numero1);
            flagA=1;
            break;

        case 2:
            printf("el valor de B es =");
            scanf("%d", &numero2);
            flagB=1;
            break;

        case 3:
            // OPERACIONES ARITMETICAS
            if(flagA!=0 && flagB!=0)
            {
                resultadoSuma = sumar(numero1,numero2);
                resultadoResta = restar(numero1,numero2);
                if(numero2 != 0)
                {
                    resultadoDivision = dividir(numero1,numero2);
                }
                resultadoMultiplicacion = multiplicar(numero1, numero2);


                if(numero1>0)
                {
                    resultadosFactorialUno = factorial(numero1);
                }
                if(numero2>0)
                {
                    resultadosFactorialDos = factorial(numero2);
                }
                printf("Operaciones realizadas con EXITO\n");
            }
                else
            {
                printf("ERROR, Verifique que ingreso todos los valores para operar\n");
            }

            break;

        case 4:
            printf("\n1.El resultado de %d + %d = %d \n", numero1,numero2,resultadoSuma);
            printf("\n2.El resultado de %d - %d = %d \n", numero1,numero2,resultadoResta);
            if(numero2 != 0)
            {
                printf("\n3.El resultado de %d / %d = %.2f\n", numero1,numero2,resultadoDivision);
            }
            else
            {
                printf("\n3.No se puede dividir por 0\n");
            }
            printf("\n4.El resultado de %d * %d = %d \n", numero1, numero2, resultadoMultiplicacion);
            if(numero1<0)
            {
                printf("\nEl factorial de %d no se puede realizar \n",numero1);
            }
            else if(numero1==0)
            {
                printf("El factorial de %d es: 1",numero1);
            }
            else
            {
                printf("\nEl factorial de %d es: %d \n", numero1, resultadosFactorialUno);
            }
            if(numero2<0)
            {
                printf("\nEl factorial de %d no se puede realizar \n",numero2);
            }
            else if(numero2==0)
            {
                printf("El factorial de %d es: 1",numero2);
            }
            else
            {
                printf("\nEl factorial de %d es: %d \n", numero2, resultadosFactorialDos);
            }

            break;

        default :
            if(opcion==5)
            {
                printf("Usted SALIO!\n");
            }
            else
            {
                printf("\nERROR, OPCION INCORRECTA! \n");
            }

        }

        system("pause");
        system("cls");

    }
    while(opcion != 5);



    return 0;

}


