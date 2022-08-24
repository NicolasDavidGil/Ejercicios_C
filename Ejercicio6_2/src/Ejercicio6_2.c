/*
 ============================================================================
 Name        : 			Ejercicio6_2.c
 Author      : 			Gil Nicolas David
 Description : 		Ejercicio 6-2:
								Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
								Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente.
								(Como máximo 4 for)
Ejemplo:
								Listado 1 : 4, 5, 6, 10, 18, 29
								Listado 2 : -1,-5,-9,-12

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define LEN 10

int main(void)
{
	setbuf(stdout, NULL);

	int numeros[LEN];
	int auxiliar;

	for(int i = 0; i < LEN; i++)
	{
		printf("Ingrese un numero: \n");
		scanf("%d", &numeros[i]);
	}


	for(int i = 0; i < LEN - 1; i++)
	{
		for(int j = i+1; j < LEN; j++)
			{
				if(numeros[i] < 0)
				{
					if(numeros[i] < numeros[j])
					{
						auxiliar = numeros[j];
						numeros[j] = numeros[i];
						numeros[i] = auxiliar;
					}
				}
			}

	}

	for(int i = 0; i< LEN -1; i++)
	{
		for(int k = i+1; k < LEN; k++)
		{
			if(numeros[i] >= 0)
			{
				if(numeros[i] > numeros[k])
				{
					auxiliar = numeros[k];
					numeros[k] = numeros[i];
					numeros[i] =  auxiliar;
				}
			}
		}
	}

	for(int i = 0; i < LEN; i++)
	{
		printf("\n%d\n", numeros[i]);
	}

	return 0;
}


