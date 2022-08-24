/*
 ============================================================================
 Name        : 		Ejercicio6_1.c
 Author      : 		Gil Nicolas David
 Description : 	Disponemos de dos variables numéricas (a y b).
 	 	 	 	 	 	 	Realizar un algoritmo que permita el intercambio de valores de dichas variables.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 5

int main(void)
{
	setbuf(stdout, NULL);

	int numerosA[LEN] = {1,2,3,4,5};
	int numerosB[LEN] = {6,7,8,9,10};
	int aux[LEN];




	for(int i = 0; i < LEN; i++)
	{
		aux[i] = numerosA[i];
		numerosA[i] = numerosB[i];
		numerosB[i] = aux[i];
	}

	printf("A: \n");
	for(int i = 0; i < LEN; i++)
	{
		printf("%d \n", numerosA[i]);
	}

	printf("B: \n");
	for(int i = 0; i < LEN; i++)
		{
			printf("%d \n", numerosB[i]);
		}

	return 0;
}


