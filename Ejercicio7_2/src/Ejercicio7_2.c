/*
 ============================================================================
 Name        : 		Ejercicio7_2.c
 Author      : 		Gil Nicolas David
 Description : 	Anexo vectores paralelos
							Ejercicio 7-2: Dados 3 vectores paralelos de tipo entero:
								Cargar el vector A y B de manera secuencial.
								El tercer vector C, deberá cargarse con el mayor de los elementos del mismo componente.
								Mostrar los 3 vectores, ordenados de menor a mayor por el vector C

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define LEN 5
#define TRUE 0
#define FALSE -1

void CargarVector(int vec[]);
int RequestInt(char mensaje[]);
int RequestIntInRange(char mensaje[], char mensajeError[], int minimo, int maximo);
int ValidateInt(char cadena[]);

int main(void)
{
	setbuf(stdout, NULL);

	int vectorA[LEN];
	int vectorB[LEN];

	CargarVector(vectorA);
	CargarVector(vectorB);

	return 0;
}

void CargarVector(int vec[])
{
	for(int i = 0; i < LEN; i++)
	{
		vec[i] = RequestIntInRange("Ingrese numero: ", "Ingreso no valido", 1, INT_MAX);
	}
}

int RequestInt(char mensaje[])
{
    char cadena[10];
    int resultado;
    int auxValidacion;

    do
    {
        printf("%s ", mensaje);
        scanf("%s", cadena);
        auxValidacion = ValidateInt(cadena);
        if(auxValidacion == FALSE)
        {
            printf("\nNumero Invalido.\n");
        }
    }while(auxValidacion == FALSE);

    resultado = atoi(cadena);

    return resultado;
}

int RequestIntInRange(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int numero;
	int auxValidar;

	do
	{
		numero = RequestInt(mensaje);
		if(numero < minimo || numero > maximo)
		{
			printf("\n%s..\n", mensajeError);
			auxValidar = -1;
		}else
		{
			auxValidar = 0;
		}
	}while(auxValidar == -1);

	return numero;
}

int ValidateInt(char cadena[])
{
    int retorno = TRUE;
    int len;

    retorno = 1;
    len = strlen(cadena);

    if (isdigit(cadena[0]) || (cadena[0] == '-' && len > 1))
    {
        for(int i = 1; i < len; i++)
        {
                if (!isdigit(cadena[i]))
                {
                    retorno = FALSE;
                    break;
                }
        }
    } else
    {
        retorno = FALSE;
    }

    return retorno;
}
