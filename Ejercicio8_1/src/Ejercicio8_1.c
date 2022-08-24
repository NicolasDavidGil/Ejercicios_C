/*
 ============================================================================
 Name        : 			Ejercicio8_1.c
 Author      : 			Gil Nicolas David
 Description : 		Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
								Crear una función que permita cargar los datos de un jugador y otra que los muestre.
								Una tercera función calculará el promedio de goles

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[50];
	int golesMetidos;
	int patidosJugados;
	float promedioGol;
}eJugador;

eJugador PedirDatos(char nombre[], int goles, int partidos);

void MostrarEstructura(char nombre[], int goles, int partidos, float promedio);

float CalcularPromedio (int goles, int partidos);


int main(void)
{
	setbuf(stdout, NULL);
	eJugador player;
	float promedioGoles;

	player = PedirDatos(player.nombre, player.golesMetidos, player.patidosJugados);

	promedioGoles = CalcularPromedio(player.golesMetidos, player.patidosJugados);

	player.promedioGol = promedioGoles;

	MostrarEstructura(player.nombre, player.golesMetidos, player.patidosJugados, player.promedioGol);

	return 0;
}


eJugador PedirDatos(char nombre[], int goles, int partidos)
{
	eJugador jugador;
	printf("Ingrese el nombre del jugador: ");
	fflush(stdin);
	scanf("%[^\n]", jugador.nombre);
	printf("Ingrese goles metidos: ");
	scanf("%d", &jugador.golesMetidos);
	printf("Ingrese partidos jugados: ");
	scanf("%d", &jugador.patidosJugados);

	return jugador;
}

void MostrarEstructura(char nombre[], int goles, int partidos, float promedio)
{
	printf("El nombre del jugador es: %s \n", nombre);
	printf("La cantidad de goles realizados son: %d \n", goles);
	printf("La cantidad de partidos jugados son: %d \n", partidos);
	printf("Su promedio de gol fue: %.2f \n", promedio);
}

float CalcularPromedio (int goles, int partidos)
{
	float promedio;

	promedio = (float)goles / partidos;

	return promedio;
}
