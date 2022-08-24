/*
 ============================================================================
 Name        : 			Ejercicio_15_2.c
 Author      : 			Gil Nicolas David
Description : 			Realizar una funci�n que reciba como par�metro un puntero a entero.
								La funci�n le pedir� al usuario
								que cargue un valor por medio del puntero.
								Retornar� si pudo cargarlo o no.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int PedirNumPuntero(int* p);

int main(void)
{
	setbuf(stdout, NULL);
	int num;
	int* pNum = NULL;
	int todoOK;

	pNum = &num;

	todoOK = PedirNumPuntero(pNum);

	if(todoOK == 1)
	{
		printf("Su numero es: %d", num);
	}else
	{
		printf("Salio mal.");
	}

	return EXIT_SUCCESS;
}

int PedirNumPuntero(int* p)
{
	int retorno = -1;

	printf("Ingrese un numero: ");
	scanf("%d", p);

	if(p != NULL)
	{
		retorno = 1;
	}

	return retorno;
}
