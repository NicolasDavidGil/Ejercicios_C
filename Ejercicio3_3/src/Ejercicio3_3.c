/*
 ============================================================================
 Name        : 		Ejercicio3_3.c
 Author      : 		Gil Nicolas David
 Ejercicio3_3: 	 Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int PedirNumero(void);
int main(void)
{
	setbuf(stdout, NULL);
	int num;

	num = PedirNumero();
	printf("Su numero es: %d", num);
	return 0;
}

int PedirNumero(void)
{
	int numeroIngresado;
	printf("Ingrese un numero: ");
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
