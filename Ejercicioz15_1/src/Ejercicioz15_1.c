/*
 ============================================================================
 Name        : 			Ejercicioz15_1.c
 Author      : 			Gil Nicolas David
 Description : 		Realizar el ordenamiento de un vector de enteros.
 	 	 	 	 	 	 	 	 Para ello deberán crear una función que se encargue de realizar el intercambio de los dos valores que se van a ordenar (función swap), que solo puede recibir dos parámetros.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OrdenarVector(int vector[], int len);
void PrintVector(int vector[], int len);

int main(void)
{
	setbuf(stdout, NULL);

	int vector[10] = {1, 8, 3, 6, 9, 10, 4, 7, 5, 2};
	int longitud;

	longitud = sizeof(vector);

	OrdenarVector(vector, longitud);

	PrintVector(vector, longitud);

	return EXIT_SUCCESS;
}

void OrdenarVector(int vector[], int len)
{
	int auxiliar;

	for(int i = 0; i < len -1; i++)
	{
		for(int j = i + 1; j < len; j++)
		{
			if(vector[i] > vector[j])
			{
				auxiliar = vector[i];
				vector[i] = vector[j];
				vector[j] = auxiliar;
			}
		}
	}
}

void PrintVector(int vector[], int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("El numero %d es: %d\n", i + 1, vector[i]);
	}
}
