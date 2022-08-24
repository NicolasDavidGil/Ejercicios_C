/*
 ============================================================================
 Name        : 			Ejercicio5_3Anexo.c
 Author      : 			Gil Nicolas David
 Description : 		Crear un Array de 5 elementos de tipo numérico donde se cargarán edades.
								Agregar la funcionalidad para la opción 1 del Menú del ejercicio anterior utilizando funciones, es decir una función que inicialice el Array.
								Agregar la funcionalidad para la opción 2 del Menú utilizando funciones, es decir una función que le pida los números o edades al usuario para cargar el Array de forma secuencial.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int MenuInteractivo(void);
void LlenarVector(int p[], int len);
void CargarVector(int p[], int len);

int main(void)
{
	setbuf(stdout, NULL);
	int edades[TAM];
	int respuestaMain;
	do
	{
		respuestaMain = MenuInteractivo();
		switch(respuestaMain)
		{
		case 1:
			LlenarVector(edades, TAM);
			printf("\nVector inicializado.\n");
			break;
		case 2:
			CargarVector(edades, TAM);
			break;
		case 3:
			printf("\nUd ha seleccionado la opción 3- Mostrar.\n");
			break;
		case 4:
			printf("\nUd ha seleccionado la opción 4-Calcular Promedio.\n");
			break;
		case 5:
			printf("\nUd ha seleccionado la opción 5- Ordenar.\n");
			break;
		}
	}while(respuestaMain != 6);


	printf("\nUsted ha seleccionado la opcion 6 - Salir.");


	return EXIT_SUCCESS;
}

int MenuInteractivo(void)
{
	int opcion;

	printf("1-Inicializar\n"
				"2-Cargar\n"
				"3-Mostrar\n"
				"4-Calcular Promedio\n"
				"5-Ordenar\n"
				"6-Salir\n"
				"Ingrese una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

void LlenarVector(int p[], int len)
{
	for(int i = 0; i < len; i++)//Inicializa el vector con 0 en todos sus indices.
	{
		p[i] = 0;
	}
}

void CargarVector(int p[], int len)
{
	for(int i = 0; i < len; i++)
	{
		do
		{
			printf("Ingrese un numero mayor de 0: ");
			scanf("%d", &p[i]);
		}while(p[i]  < 1);
	}
}

