/*
 ============================================================================
 Name        : 		Ejercicio5_8Anexo.c
 Author      : 		Gil Nicolas David
 Description : 	Modificar la función que calcula el promedio en la opción 4 del Menú, para que devuelva el resultado del promedio por parámetro por referencia.
 	 	 	 	 	 	 	 El retorno de la misma debe indicar si funcionó correctamente.

 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int MenuInteractivo(void);
int MenuCase3(void);
void LlenarVector(int p[], int len);
void CargarVector(int p[], int len);
void MostrarVector(int p[],int len);
void MostrarUnElemento(int p[], int len, int posicion);
int CalcularPromedio(int p[], int len, float* promedio);

int main(void)
{
	setbuf(stdout, NULL);
	int edades[TAM];
	int respuestaMain;
	int respuestaCase3;
	int respuestaCase4;
	float promedio=0;
	int posicion;
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
			respuestaCase3 = MenuCase3();
			if(respuestaCase3 == 2)
			{
				MostrarVector(edades, TAM);
			}else
			{
				printf("\nIngrese la posicion a imprimir: ");
				scanf("%d", &posicion);
				MostrarUnElemento(edades, TAM, posicion);
			}

			break;
		case 4:
			respuestaCase4 = CalcularPromedio(edades, TAM, &promedio);
			if(respuestaCase4 == 1)
			{
				printf("\nEl promedio de los numeros ingresados es: %.2f\n", promedio);
			}else
			{
				printf("\nNo se ha podido calcular el promedio.\n");
			}

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

int MenuCase3(void)
{
	int opcion;
	do
	{
		printf("\nDesea imprimir uno o todos los datos\n"
					"1 - Imprimir un solo dato.\n"
					"2 - Imprimir todos los datos.\n"
					"Ingrese una opcion: ");
		scanf("%d", &opcion);
	}while(opcion != 1 && opcion != 2);
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
		printf("\n La edad %d ingresado es: %d\n", i+1, p[i]);
	}
}

void MostrarUnElemento(int p[], int len, int posicion)
{
	printf("\n");
	printf("La edad ingresado es: %d\n", p[posicion]);

}

int CalcularPromedio(int p[], int len, float* promedio)
{
	int acumuladorNumeros = 0;
	float promedioTotal;
	int retorno = -1;

	for(int i = 0; i < len; i++)
	{
		acumuladorNumeros = acumuladorNumeros + p[i];
	}

	promedioTotal = (float)acumuladorNumeros / len;
	*promedio = promedioTotal;
	if(promedio > 0)
	{
		retorno = 1;
	}
	return retorno;
}
