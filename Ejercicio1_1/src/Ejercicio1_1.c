/*
 ============================================================================
 Name        : 			Ejercicio1_1.c
 Author      : 		Gil Nicolas David
 Description : 	Ingresar dos números enteros, sumarlos y mostrar el resultado.
 Ejemplo	: 			Si ingresamos 3 y 2 el programa mostrará: “La suma entre 3 y 2
 	 	 	  	  	  	  	  	da como resultado 5”
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int PedirNumero (char mensaje[]);

int main(void)
{
	int numeroUno;
	int numeroDos;
	setbuf(stdout, NULL);

	numeroUno = PedirNumero("Ingrese el primer numero: ");
	numeroDos = PedirNumero("Ingrese el segundo numero: ");

	printf("La suma de %d y %d da como resultado: %d", numeroUno, numeroDos, numeroUno + numeroDos);

	return 0;
}

int PedirNumero (char mensaje[])
{
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
