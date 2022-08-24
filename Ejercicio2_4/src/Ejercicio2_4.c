/*
 ============================================================================
 Name        : 		Ejercicio2_4.c
 Author      : 		Gil Nicolas David
Ejercicio 2_4 : Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	char caracterIngresado;
	int contadorP = 0;
	for(int i = 0; i < 5; i++)
	{
		printf("Ingrese un caracter: ");
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		if(caracterIngresado == 'p')
		{
			contadorP++;
		}
	}

	if(contadorP > 0)
	{
		printf("La cantidad de letras p ingresadas es: %d", contadorP);
	}else
	{
		printf("No se ingresaron letras p minusculas.");
	}

	return 0;
}
