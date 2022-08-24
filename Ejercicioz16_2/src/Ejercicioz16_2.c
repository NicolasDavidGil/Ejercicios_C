/*
 ============================================================================
 Name        : 		Ejercicioz16_2.c
 Author      : 		Gil Nicolas David
 Description : 	Ejercicio 16-2:
							Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
							La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define LEN 5

void llenarVector(int v1[], int len);
void calcularMaximo(int v1[], int* number, int len);

int main(void)
{
	setbuf(stdout, NULL);

	int vector[LEN];
	int maximo;

	llenarVector(vector, LEN);
	calcularMaximo(vector, &maximo, LEN);

	printf("El numero maximo del array es: %d", maximo);

	return EXIT_SUCCESS;
}

void llenarVector(int v1[], int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &v1[i]);
	}
}

void calcularMaximo(int v1[], int* number, int len)
{
	int flagMax = 1;

	for(int i = 0; i < len; i++)
	{
		if(flagMax == 1 || v1[i] > *number)
		{
			*number = v1[i];
			flagMax = 0;
		}
	}
}
