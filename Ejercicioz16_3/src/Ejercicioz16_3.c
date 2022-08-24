/*
 ============================================================================
 Name        : 		Ejercicioz16_3.c
 Author      : 		Gil Nicolas David
 Description : 	Ejercicio 16-3:
							Realizar una funci�n que respete el siguiente prototipo:
							int Calculador(int, int(*pFunc)(int, int), int, int*);
							Dicha funci�n deber� recibir dos operandos y un operador representado mediante la funci�n pasada como par�metro.
							El puntero a entero, servir� como par�metro de salida y guardar� el resultado de la operaci�n.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Inputs.h"

int Calculador(int(*pFunc)(int n1, int n2), int*);
int sumarDos(int num1, int num2);

int main(void)
{
	setbuf(stdout, NULL);
	int* resul = 0;
	int retorno;

	retorno = Calculador(sumarDos, resul);
	if(retorno ==1)
	{
		printf("El resultado de su operacion es: %d", *resul);
	}

	return EXIT_SUCCESS;
}

int Calculador(int(*pFunc)(int n1, int n2), int* number)
{
	int retorno = -1;
	int num1;
	int num2;

	num1 = RequestIntInRange("Ingrese un numero entero: ", "Numero no valido", 1, INT_MAX);
	num2 = RequestIntInRange("Ingrese un numero entero: ", "Numero no valido", 1, INT_MAX);

	*number = pFunc(num1, num2);
	if(*number > 0)
	{
		retorno = 1;
	}

	return retorno;
}

int sumarDos(int num1, int num2)
{
	int retorno;

	retorno = num1 + num2;

	return retorno;
}
