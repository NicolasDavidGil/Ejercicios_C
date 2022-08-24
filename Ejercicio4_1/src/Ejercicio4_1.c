/*
 ============================================================================
 Name        : 		Ejercicio4_1.c
 Author      : 		Gil Nicolas David
Ejercicio4_1 : 	Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
							Utilizar la función PedirNumero de la ejercitación 3-4.
							Por ejemplo:
							5! = 5*4*3*2*1 = 120

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int PedirNumero(void);


int main(void)
{
	setbuf(stdout, NULL);
	int numero;
	int factorial = 1;
	numero = PedirNumero();

	for(int i  = numero; i  > 0;i--)
	{
		factorial = factorial * i;
	}
	printf("El factorial de %d es: %d",numero,factorial);
	return 0;
}

int PedirNumero(void)
{
	int numeroIngresado;
	printf("Ingrese un numero: ");
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
