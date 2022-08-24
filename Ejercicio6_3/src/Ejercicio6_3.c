/*
 ============================================================================
 Name        : 			Ejercicio6_3.c
 Author      : 			Gil Nicolas David
 Description : 		EJERCICIO : 6-3
								Pedirle al usuario su nombre y apellido (en variables separadas,
								una para el nombre y otra para el apellido).
								Ninguna de las dos variables se puede  modificar.
								Debemos lograr guardar en una tercer variable el apellido y
								el nombre con el siguiente formato:
								Por ejemplo:
								Si el nombre es juan ignacio y el apellido es gOmEz,
								la salida debería ser:
								1) PASO A MAYUSCULA LAS PRIEMRAS LETRAS
								2) HAGO LA UNION DE LAS VARIABLES
								3) AGARRO EL APELLIDO Y NOMBRE LO PASO TODO A MINUSCUULAS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	setbuf(stdout,NULL);
	char nombre[31];
	char apellido[31];
	char apeNom[70];
	int cantidad;
	int i;

	printf("Ingrese su apellido: ");
	fflush(stdin);
	scanf("%[^\n]", apellido);

	printf("Ingrese su nombre: ");
	fflush(stdin);
	scanf("%[^\n]", nombre);

	//paso a minuscula las cadenas
	strlwr(apellido);
	strlwr(nombre);

	//paso las iniciales mayusculas
	apellido[0] = toupper(apellido[0]);

	nombre[0] = toupper(nombre[0]);

	cantidad = strlen(nombre);//declaro una variable cantidad para que recorra hasta encontrar el espacio
	for(i=0; i<cantidad; i++)//yo tengo que buscar el espacio
	{
		if(nombre[i] == ' ')
		{
			nombre[i+1] = toupper(nombre[i+1]);//uan vez que lo encuentro, le sumo 1, llego a la primera inicial y la paso a mayusculas
		}
	}

	//concateno apellido y nombre en una misma variable
	apeNom[0] = '\0'; //aca puedo limpiar apenom
	strcat(apeNom, apellido);
	strcat(apeNom, "," );
	strcat(apeNom, nombre);

	printf("SU NOMBRE ES: %s, %s", apellido, nombre);

	return 0;
}
