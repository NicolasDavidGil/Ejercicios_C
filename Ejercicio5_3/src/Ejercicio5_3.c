/*
 ============================================================================
 Name        : 			Ejercicio5_3.c
 Author      : 			Gil Nicolas David
 Description : 		Realizar un programa que permita el ingreso de 10 números enteros distintos de cero. La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).
 	 	 	 	 	 	 	 	Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores (Según la recta numérica de los reales, hasta llegar a cero).
								Utilizar funciones y vectores.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void LlenarVector(int p[], int len);
void CargarVector(int p[]);
void MostraVector(int p[]);
float PromedioPositivos(int p[]);
int SumaAntecesores(int p[]);

int main(void)
{
	setbuf(stdout, NULL);
	int numeros[TAM];
	float promedioPositivos;
	int sumaAntecesores;

	LlenarVector(numeros, TAM);

	CargarVector(numeros);
	promedioPositivos = PromedioPositivos(numeros);
	sumaAntecesores = SumaAntecesores(numeros);
	MostraVector(numeros);

	if(promedioPositivos > 0)
	printf("\n El promedio de los positivos es: %.2f \n", promedioPositivos);
	else{
			printf("No se ingresaron positivos.");
	}

	if(sumaAntecesores < 0)
	{
		printf("La suma de los antecesores del menor negativo es: %d\n",  sumaAntecesores);
	}else
	{
		printf("No se ingresaron negativos");
	}
	return 0;
}

void LlenarVector(int p[], int len)
{
	for(int i = 0; i < len; i++)//Inicializa el vector con 0 en todos sus indices.
	{
		p[i] = 0;
	}
}

void CargarVector(int p[])
{
	for(int i = 0; i < TAM; i++)
	{
		if(p[i] == 0)
		{
			printf("Ingrese un numero: ");
			scanf("%d", &p[i]);
			while(p[i] == 0)
			{
				printf("Error, el numero debe ser != de 0: ");
				scanf("%d", &p[i]);
			}
		}
	}
}

void MostraVector(int p[])
{
	printf("\n");
	for(int i = 0; i < TAM; i++)
	{
		printf("El numero %d ingresado es: %d\n", i+1, p[i]);
	}
}
float PromedioPositivos(int p[])
{
	float promedio = 0;
	int contadorP = 0;
	float sumaP;
	for(int i = 0; i < TAM; i++)
	{
		if(p[i] >  0)
		{
			sumaP = sumaP + p[i];
			contadorP++;
		}
	}

	promedio = sumaP / contadorP;

	return promedio;
}

int SumaAntecesores(int p[])
{
	int flagPrimerNeg = 0;
	int menorNegativo;
	int sumaAntecesores = 0;
	for(int i = 0; i < TAM; i++)
	{
		if(p[i] < 0)
		{
			if(flagPrimerNeg == 0 || p[i] < menorNegativo)
			{
				menorNegativo = p[i];
				flagPrimerNeg = 1;
			}
		}
	}
	for(int i = menorNegativo; i < 0; i++)
	{
		sumaAntecesores = sumaAntecesores + i;
	}



	return sumaAntecesores;
}
