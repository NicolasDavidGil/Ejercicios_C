/*
 ============================================================================
 Name        : 		Ejercicio5_2Anexo.c
 Author      : 		Gil Nicolas David
 Description : 	Realizar un programa que desde el main llame o invoque a la función que muestre el Menú del punto anterior.
							Utilizar funciones y bibliotecas.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int MenuInteractivo(void);

int main(void)
{
	setbuf(stdout, NULL);
	int respuestaMain;

	do
	{

		respuestaMain = MenuInteractivo();
		switch(respuestaMain)
		{
		case 1:
			printf("\nUd ha seleccionado la opción 1- Inicializar.\n");
			break;
		case 2:
			printf("\nUd ha seleccionado la opción 2- Cargar.\n");
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

	return 0;
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
