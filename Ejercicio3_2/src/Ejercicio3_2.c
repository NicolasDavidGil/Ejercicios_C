/*
 ============================================================================
 Name        : 		Ejercicio3_2.c
 Author      : 		Gil Nicolas David
 Description : 	Crear una función que permita determinar si un número es par o no.
 	 	 	 	 	 	 	 La función retorna 1 en caso afirmativo y 0 en caso contrario.
 	 	 	 	 	 	 	 Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int ValidarParImpar(int numero);

int main(void)
{
	setbuf(stdout, NULL);
	int validacion;
	int numero;
	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	validacion = ValidarParImpar(numero);
	if(validacion == 1)
	{
		printf("El numero es par.");
	}else
	{
		printf("El numero es impar.");
	}
	return 0;
}


int ValidarParImpar(int numero)
{
	if(numero %2 == 0)
	{
		return 1;
	}else
	{
		return 0;
	}
}
