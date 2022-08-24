/*
 ============================================================================
 Name        : 		Ejercicioz16_1.c
 Author      : 		Gil Nicolas David
 Description : 	Ejercicio 16-1:
							Realizar una función que reciba un puntero a char y dos char.
							La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo.
							Retornando la cantidad de reemplazos o -1 en caso de error.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEN 5

int reemplazoChar(char cadena[], char uno, char dos, int len);

int main(void)
{
	setbuf(stdout, NULL);

	char cadena[LEN] = "Holas";
	char uno = 's';
	char dos = 'x';
	int retorno;

	retorno = reemplazoChar(cadena, uno, dos, LEN);
	if(retorno != -1)
	{
		printf("\nSu cadena fue corregida %d veces y quedo asi: %s\n", retorno, cadena);
	}else
	{
		puts("\nSu cadena no ha sido modificada.\n");
	}

	return EXIT_SUCCESS;
}

int reemplazoChar(char cadena[], char uno, char dos, int len)
{
	int contador = 0;

	for(int i = 0; i < len; i++)
	{
		if(strcmp(&cadena[i], &uno)== 0)
		{
			contador++;
			strcpy(&cadena[i], &dos);
		}
	}

	if(contador == 0)
	{
		contador--;
	}


	return contador;
}
