/*
 ============================================================================
 Name        : 			Ejercicio2_1.c
 Author      : 		Gil Nicolas David
 Description :		Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números.
 	 	 	 	 	 	 	 	Probar la aplicación con distintos valores.

 Ejemplo 1:  3 - 5 - 7 - 9 - 1
 Ejemplo 2:  2 - 1 - 8 -1 - 2

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN 5

int main(void)
{
	setbuf(stdout, NULL);
	int numero;
	int promedio = 0;

	for(int i = 0; i < LEN; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);
		promedio = promedio + numero;
	}

	printf("El promedio de los 5 numeros es: %d", promedio / LEN);
	return 0;
}
