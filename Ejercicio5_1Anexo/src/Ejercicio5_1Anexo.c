/*
 ============================================================================
 Name        : 		Ejercicio5_1Anexo.c
 Author      : 		Gil Nicolas David
 Description : 	Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ANEXO 5-1:
							Armar un Menú de Opciones con las siguientes opciones
							1-Inicializar
							2-Cargar
							3-Mostrar
							4-Calcular Promedio
							5-Ordenar
							Al ingresar a cada opción del menú deberá imprimir en pantalla el nombre del mismo.
							Ej: Si se presiona la opción 1 mostrar por pantalla “Ud. ha seleccionado lo opción 1-Inicializar”

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN 5

int main(void)
{
	setbuf(stdout, NULL);

	int respuesta;


	do
	{
		printf("1-Inicializar\n"
					"2-Cargar\n"
					"3-Mostrar\n"
					"4-Calcular Promedio\n"
					"5-Ordenar\n"
					"6-Salir\n"
					"Ingrese una opcion: ");
		scanf("%d", &respuesta);
		switch(respuesta)
		{
		case 1:
			printf("Ud ha seleccionado la opción 1- Inicializar.");
			break;
		case 2:
			printf("Ud ha seleccionado la opción 2- Cargar.");
			break;
		case 3:
			printf("Ud ha seleccionado la opción 3- Mostrar.");
			break;
		case 4:
			printf("Ud ha seleccionado la opción 4-Calcular Promedio.");
			break;
		case 5:
			printf("Ud ha seleccionado la opción 5- Ordenar.");
			break;
		}

	}while(respuesta != 6);

	printf("Ud ha seleccionado la opción 6_ Salir.");


	return 0;
}

