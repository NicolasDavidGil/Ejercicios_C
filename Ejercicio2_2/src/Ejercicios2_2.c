/*
 ============================================================================
 Name        : 			Ejercicios2_2.c
 Author      : 		Gil Nicolas David
 Description :		Ejercicio 2-2:
								Ingresar 10 números enteros, distintos de cero.
								Mostrar:
								a.	Cantidad de pares e impares.
								b.	El menor número ingresado.
								c.	De los pares el mayor número ingresado.
								d.	Suma de los positivos.
								e.	Producto de los negativos.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	int numeros;
	int contadorPares = 0;
	int contadorImpares = 0;
	int flagPrimerNumero = 0;
	int menorNumero;
	int flagPrimerPar = 0;
	int mayorPar;
	int acumuladorPositivos = 0;
	int acumuladorNegativos = 1;
	int contador = 0;
	do
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numeros);
		while(numeros == 0)
		{
			printf("Error, reingrese un numero: ");
			scanf("%d", &numeros);
		}
		if(numeros %2 == 0)
		{
			contadorPares++;
			if(flagPrimerPar == 0 || numeros > mayorPar)
			{
				mayorPar = numeros;
				flagPrimerPar = 1;
			}
		}else
		{
			contadorImpares ++;
		}

		if(numeros > 0)
		{
			acumuladorPositivos += numeros;
		}else
		{
			acumuladorNegativos *= numeros;
		}

		if(flagPrimerNumero == 0 || numeros < menorNumero)
		{
			menorNumero = numeros;
			flagPrimerNumero = 1;
		}
		contador++;
	}while(contador < 10);

	printf("La cantidad de pares ingresados es: %d\n"
				"La cantidad de impares es: %d\n", contadorPares, contadorImpares);
	printf("El menor numero ingresado es: %d\n "
				"El mayor numero par ingresado es: %d\n", menorNumero,mayorPar);
	printf("La suma de los positivos es: %d\n"
				"El producto de los negativos es: %d\n", acumuladorPositivos, acumuladorNegativos);


	return 0;
}
