/*
 ============================================================================
 Name        : Ejercicio3_5.c
 Author      : Gil Nicolas David
 Description : Realizar un programa en donde se puedan utilizar los prototipos
 de la función Sumar en sus 4 combinaciones.
 (Apunta a que entiendan el concepto de independencia del código)
 int Sumar1(int, int);
 int Sumar2(void);
 void  Sumar3(int, int);
 void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int Sumar1(int, int);
int Sumar2(void);
void  Sumar3(int, int);
void Sumar4(void);

int main(void)
{
	setbuf(stdout, NULL);
	//Inicio Sumar1
	int numeroUnoSumar1;
	int numeroDosSumar1;
	int resultadoSumar1;
	printf("Ingrese un numero: ");
	scanf("%d", &numeroUnoSumar1);
	printf("Ingrese otro numero: ");
	scanf("%d", &numeroDosSumar1);
	resultadoSumar1 = Sumar1(numeroUnoSumar1, numeroDosSumar1);

	printf("El resultado de Sumar1 es: %d \n", resultadoSumar1);
	//Fin Sumar1

	//Inicio Sumar2

	int resultadoSumar2;
	resultadoSumar2 = Sumar2();

	printf("EL resultado de Sumar2 es %d \n", resultadoSumar2);

	//Fin de Sumar2

	//Inicio Sumar3

	int numeroUnoSumar3;
	int numeroDosSumar3;

	printf("Ingrese un numero: ");
	scanf("%d", &numeroUnoSumar3);

	printf("Ingrese otro numero: ");
	scanf("%d", &numeroDosSumar3);

	Sumar3(numeroUnoSumar3, numeroDosSumar3);

	//Fin Sumar3


	//Inicio Sumar4

	Sumar4();

	//Fin Sumar4
	return 0;
}

int Sumar1(int numeroUno, int numeroDos) //Recibe dos numeros, los suma y devuelve el resultado.
{
	int resultado;
	resultado = numeroUno + numeroDos;

	return resultado;
}

int Sumar2(void) // Pide dos numeros, los suma y devuelve el resultado.
{
	int numero1;
	int numero2;
	int resultado;

	printf("Ingrese un numero: ");
	scanf("%d", &numero1);

	printf("Ingrese otro numero:");
	scanf("%d", &numero2);

	resultado = numero1 + numero2;

	return resultado;
}


void  Sumar3(int numero1, int numero2)
{
	printf("El resultado de Sumar3 es: %d \n", numero1 + numero2);
}


void Sumar4(void)
{
	int numero1;
	int numero2;

	printf("Ingrese un numero: ");
	scanf("%d", &numero1);

	printf("Ingrese otro numero:");
	scanf("%d", &numero2);

	printf("El resultado de Sumar4 es: %d \n", numero1 + numero2);
}

