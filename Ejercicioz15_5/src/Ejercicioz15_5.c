/*
 ============================================================================
 Name        : 		Ejercicioz15_5.c
 Author      : 		Gil Nicolas David
 Description : 	Escriba una función que reciba dos números enteros y los devuelva ordenados.
 	 	 	 	 	 	 	 Es decir que en el primer parámetro debe devolver el menor valor y en el 2do. el mayor.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void OrdenarDosNumeros(int* p1, int* p2);

int main(void)
{
	setbuf(stdout, NULL);

	int num1 = 5;
	int num2 = 2;
	int *pNum1 = NULL;
	int *pNum2 = NULL;

	pNum1 = &num1;
	pNum2 = &num2;

	OrdenarDosNumeros(pNum1, pNum2);

	printf("El menor numero es: %d\n", num1);
	printf("El mayor numero es: %d", num2);


	return EXIT_SUCCESS;
}

void OrdenarDosNumeros(int* p1, int* p2)
{
	int aux;

	if(*p1 > *p2)
	{
		aux = *p1;
		*p1 = *p2;
		*p2 = aux;
	}

}
