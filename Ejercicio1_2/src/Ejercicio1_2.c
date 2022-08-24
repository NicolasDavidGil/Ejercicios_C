/*
 ============================================================================
 Name        : 			Ejercicio1_2.c
 Author      : 		Gil Nicolas David
 Ejercicio 1-2: 	ingresar 3 números y mostrar cuál de los tres es el mayor.
 Ejemplo:				Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el segundo”

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int PedirNumeroEntero (char mensaje[]);

int main(void) //No distingue en caso de numeros iguales, tomara como mayor el ultimo ingresado
{
	setbuf(stdout, NULL);
	int num1;
	int num2;
	int num3;

	num1 = PedirNumeroEntero("Ingrese primer numero: ");
	num2 = PedirNumeroEntero("Ingrese segundo numero: ");
	num3 = PedirNumeroEntero("Ingrese tercer numero: ");

	if(num1 > num2 && num1 > num3)
	{
		printf("El mayor numero es el primero.");
	}else if(num2 > num3)
	{
		printf("El mayor numero es el segundo.");
	}else
	{
		printf("El mayor numero es el tercero.");
	}

	return 0;
}


int PedirNumeroEntero (char mensaje[])
{
	int numeroIngresado;

	printf("%s \n", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}


