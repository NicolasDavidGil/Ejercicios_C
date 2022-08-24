/*
 ============================================================================
 Name        : 			Ejercicio5_2.c
 Author      : 		Gil Nicolas David
 Description :		Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
								a)	Cantidad de positivos y negativos.
								b)	Sumatoria de los pares.
								c)	El mayor de los impares.
								d)	Listado de los números ingresados.
								e)	Listado de los números pares.
								f)	Listado de los números de las posiciones impares.
								Se deberán utilizar funciones y vectores.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN 10

void PedirNumero(int p[], int minimo, int maximo);
void MostrarNumeros(int p[]);
void MostrarPares(int p[]);
void MostrarIMpares(int p[]);
int CalculosPositivoNegativo(int p[], int aux);
void CalculosParesImpares(int p[], int aux);


int main(void)
{
	setbuf(stdout, NULL);
	int vector[LEN];
	int contadorPositivos ;
	int contadorNegativos;


	PedirNumero(vector, -1000, 1000);

	contadorNegativos = CalculosPositivoNegativo(vector, 0);
	contadorPositivos = CalculosPositivoNegativo(vector, 1);


	printf("\nLa cantidad de positivos es: %d\n"
				"La cantidad de negativos es: %d \n", contadorPositivos, contadorNegativos);
	CalculosParesImpares(vector, 0);
	CalculosParesImpares(vector, 1);
	MostrarNumeros(vector);
	MostrarPares(vector);
	MostrarIMpares(vector);


	return 0;
}

void PedirNumero(int p[], int minimo, int maximo)
{
	for(int i = 0; i < LEN; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &p[i]);
		while(p[i] > maximo || p[i] < minimo)
		{
			printf("Error, reingrese un numero: ");
			scanf("%d", &p[i]);
		}
	}
}

void MostrarNumeros(int p[])
{
	for(int i = 0; i< LEN; i++)
	{
		printf("\nEl numero %d ingresado es: %d", i+1,p[i]);
	}
}

void MostrarPares(int p[])
{
	for(int i= 0; i< LEN; i++)
	{
		if(p[i] %2 == 0)
		{
			printf("\nEl numero %d es par y es: %d", i+1, p[i]);
		}
	}
}

void MostrarIMpares(int p[])
{
	for(int i= 0; i< LEN; i++)
	{
		if(p[i] %2 != 0)
		{
			printf("\nEl numero %d es impar y es: %d", i+1, p[i]);
		}
	}
}

int CalculosPositivoNegativo(int p[], int aux)
{
	int retorno;
	int contadorPos = 0;
	int contadorNeg = 0;
	for(int i= 0; i< LEN; i++)
		{
			if(p[i]> 0)
			{
				contadorPos++;
			}else
			{
				contadorNeg++;
			}
		}
	if(aux == 1)
	{
		retorno =  contadorPos;
	}else if(aux == 0)
	{
		retorno = contadorNeg;
	}
	return retorno;
}

void CalculosParesImpares(int p[], int aux)
{
	int sumaPares = 0;
	int flagPrimerImpar = 0;
	int mayorImpar;
	for(int i = 0; i < LEN; i++)
	{
		if(p[i] %2 == 0)
		{
			sumaPares = sumaPares + p[i];
		}else
		{
			if(flagPrimerImpar == 0 || p[i] > mayorImpar)
			{
				mayorImpar = p[i];
				flagPrimerImpar = 1;
			}
		}
	}
	if(aux == 0)
	{
		printf("La suma de los numeros pares es: %d\n", sumaPares);
	}else
	{
		printf("El mayor numero impar es: %d\n", mayorImpar);
	}
}
