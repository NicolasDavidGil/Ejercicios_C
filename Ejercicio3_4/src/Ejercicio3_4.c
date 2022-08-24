/*
 ============================================================================
 Name        : 		Ejercicio3_4.c
 Author      : 		Gil Nicolas David
Ejercicio3_4 : 	Especializar la función anterior para que permita validar el entero ingresado en un rango determinado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int PedirNumero(int minimo, int maximo);

int main(void)
{
	setbuf(stdout, NULL);
	int num;

	num = PedirNumero(-50, 50);
	printf("Su numero es: %d", num);

	return 0;
}

int PedirNumero(int minimo, int maximo)
{
	int numeroIngresado;
	do
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numeroIngresado);
	}while(numeroIngresado < minimo || numeroIngresado > maximo);

	return numeroIngresado;
}
