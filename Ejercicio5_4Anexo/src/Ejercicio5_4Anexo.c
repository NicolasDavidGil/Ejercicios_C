/*
 ============================================================================
 Name        : 		Ejercicio5_4Anexo.c
 Author      : 		Gil Nicolas David
 Description : 	Modificar la funcionalidad de la opción 2 del Menú para que la carga del Array sea de forma aleatoria.
							Agregar la funcionalidad de la opción 3 del Menú para mostrar por pantalla los elementos del Array, o sea las edades.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int MenuInteractivo(void);
void LlenarVector(int p[], int len);
void CargarVector(int p[], int len);
void MostrarVector(int p[],int len);

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
			MostrarVector(edades, TAM);
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

void MostrarVector(int p[], int len)
{
	printf("\n");
	for(int i = 0; i < len; i++)
	{
		printf("La edad %d ingresado es: %d\n", i+1, p[i]);
	}
}
