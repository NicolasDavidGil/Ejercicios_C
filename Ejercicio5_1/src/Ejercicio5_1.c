/*
 ============================================================================
 Name        : 		Ejercicio5_1.c
 Author      : 		Gil Nicolas David
 Description : 	Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN 5

void LlenarVector(int p[]);
void MostrarVector(int p[]);
void SumarVector(int p[]);

int main(void)
{
	setbuf(stdout, NULL);
	int vector[LEN];

	LlenarVector(vector);
	MostrarVector(vector);
	SumarVector(vector);

	return 0;
}

void LlenarVector(int p[])
{
	for(int i = 0; i < LEN; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &p[i]);
	}
}

void MostrarVector(int p[])
{
	for(int i = 0; i < LEN; i++)
	{
		printf("El numero %d es: %d \n", i+1, p[i]);
	}
}

void SumarVector(int p[])
{
	int sumaVector = 0;

	for(int i = 0; i < LEN; i++)
	{
		sumaVector = sumaVector + p[i];
	}

	printf("\nLa suma de los numeros del vector es: %d ", sumaVector);

}
