/*
 ============================================================================
 Name        : 		Ejercicio1_3.c
 Author      : 	Gil Nicolas David
 Description : Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe. En caso de que no exista también informarlo.
 Ejemplo:

1   5   3     el 3 es del medio
5   1   5    no hay numero del medio
3  5   1     el 3 es del medio
3   1   5    el 3 es del medio
5   3   1    el 3 es del medio

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int PedirNumeroEntero (char mensaje[]);

int main(void)
{
	setbuf(stdout, NULL);
	int num1;
	int num2;
	int num3;
	num1 = PedirNumeroEntero("Ingrese primer numero: ");
	num2 = PedirNumeroEntero("Ingrese segundo numero: ");
	num3 = PedirNumeroEntero("Ingrese tercer numero: ");

	if((num1 > num2 && num1 < num3) ||( num1 > num3 && num1 < num2))
	{
		printf("%d\t%d\t%d\t el %d es el del medio", num1, num2, num3, num1);
	}
	if((num2 > num1 && num2 < num3) || (num2 > num3 && num2 < num1))
	{
		printf("%d\t%d\t%d\t el %d es el del medio", num1, num2, num3, num2);
	}
	if((num3 > num1 && num3 < num2) || (num3 > num2 && num3 < num1))
	{
		printf("%d\t%d\t%d\t el %d es el del medio", num1, num2, num3, num3);
	}
	if(num1 == num2 || num1 == num3 || num2 == num3)
	{
		printf("%d\t%d\t%d\t No hay numero del medio", num1, num2, num3);
	}
	return 0;
}


int PedirNumeroEntero (char mensaje[])
{
	int numeroIngresado;

	printf("%s \n", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
