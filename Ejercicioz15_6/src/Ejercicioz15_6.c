/*
 ============================================================================
 Name        : 		Ejercicioz15_6.c
 Author      : 		Gil Nicolas David
 Description : 	Ejercicio 15-6
							Realizar una función que reciba como parámetros dos vectores. La función deberá determinar si el segundo vector está contenido en el primero.
							ANEXO
							1-Realizar una función que reciba un puntero a char y dos char.
							La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido,
							por el segundo. Retornando la cantidad de reemplazos o -1 en caso de error.
							Versión 2. Utilizar aritmetica de punteros

							2-Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
							La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.
							Versión 2. Utilizar aritmetica de punteros

							3-Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
							Realizar una función que cargue un array de 3 estudiantes.
							Recibe un entero.
							Retorna el estudiante dado de alta y por parámetro 0 si funcionó correctamente -1 mal.
							Una vez devuelto el estudiante cargarlo en una posición del array.
							Al final mostrar el array cargado
							Versión 2. Utilizar aritmética de punteros

							4-Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
							Realizar una función que cargue un array de 3 estudiantes.
							Recibe un puntero al array de estudiantes, lo carga y retorna 0 si funcionó correctamente -1 mal.
							Una vez cargados los estudiantes mostrar el array cargado
							Versión 2. Utilizar aritmética de punteros

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define LENUNO 5
#define LENDOS 2

int analizarVectores(int vector1[], int vector2[], int len1, int len2);
int reemplazoChar(char cadena[], char caracterUno, char caracterDos, int len);

int main(void)
{
	setbuf(stdout, NULL);

	int v1[5] = {1, 2, 3, 4, 5};
	int v2[2] = {2, 3};
	char cadena[5] = "HOLAS";
	char* pcad = cadena;
	char carac1 = 'S';
	char carac2 = 'X';

	if(analizarVectores(v1, v2, LENUNO, LENDOS) == 1)
	{
		puts("El vector dos esta contenido en el vector uno.");
	}else
	{
		puts("El vector dos NO esta contenido en el vector uno.");
	}

	if(reemplazoChar(pcad, carac1, carac2, LENUNO) == 1)
	{
		printf("Su cadena reemplaza es: %s", cadena);
	}else
	{
		puts("Error en reemplazo de cadena.");
	}

	return EXIT_SUCCESS;
}

int analizarVectores(int vector1[], int vector2[], int len1, int len2)
{
	int retorno = 0;


	for(int i = 0; i < len1; i++)
	{
		for(int j = 0; j < len2; j++)
		{
			if(vector2[j] == vector1[i])
			{
				retorno = 1;
			}else
			{
				break;
			}
		}
	}


	return retorno;
}

int reemplazoChar(char cadena[], char caracterUno, char caracterDos, int len)
{
	int retorno = 0;

	for(int i = 0; i < len; i++)
	{
		if(strcmp(&cadena[i], &caracterUno) == 0)
		{
			strcpy(&cadena[i], &caracterDos);
			retorno = 1;
		}
	}

	return retorno;
}



















