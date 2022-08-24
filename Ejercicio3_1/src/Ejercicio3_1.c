/*
 ============================================================================
 Name        : 			Ejercicio3_1.c
 Author      : 			Gil Nicolas David
Ejercicio3_1 :	 	Crear una función que muestre por pantalla el número flotante
   	   	   	   	   	   	   	   que recibe como parámetro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void MostrarFloat(float numero);

int main(void)
{
	setbuf(stdout, NULL);

	MostrarFloat(2.31);

	return 0;
}

void MostrarFloat(float numero)
{
	printf("%.2f", numero);
}
