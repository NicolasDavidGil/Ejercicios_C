/*
 ============================================================================
 Name        : 			Ejercicio2_3.c
 Author      : 			Gil Nicolas David
Ejercicio2_3 :	 	Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,
 	 	 	 	 	 	 	 	 de cada persona debemos obtener los siguientes datos:
								número de cliente,
								estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
								 edad( solo mayores de edad, más de 17),
								temperatura corporal (validar por favor)
								y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
								NOTA: El precio por pasajero es de $600.
								Se debe informar (solo si corresponde):

								a) La cantidad de personas con estado "viudo" de más de 60 años.
								b) el número de cliente y edad de la mujer soltera más joven.
								c) cuánto sale el viaje total sin descuento.
								d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%,
								que solo mostramos si corresponde.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PRECIO 600

int main(void)
{
	setbuf(stdout, NULL);
	int numeroCliente;
	char estadoCivil;
	int edadCliente;
	float temperaturaCliente;
	char generoCliente;
	int respuesta;
	int contadorViudos60 = 0;
	int edadMasJoven;
	int numeroClienteMasJoven;
	int flagPrimerSoltera = 0;
	int precioTotal;
	int contador = 0;
	int contadorMayores60 = 0;
	int precioDescuento;
	int flagDescuento = 0;
	do
	{
		printf("Ingrese numero de cliente: ");
		scanf("%d", &numeroCliente);

		printf("Ingrese su estado civil: ");
		fflush(stdin);
		scanf("%c", &estadoCivil);
		while(estadoCivil != 's' && estadoCivil  != 'v' && estadoCivil != 'c')
		{
			printf("Error, reingrese estado civil: s , c o v");
			fflush(stdin);
			scanf("%c", &estadoCivil);
		}

		printf("Ingrese su edad: ");
		scanf("%d", &edadCliente);
		while(edadCliente < 17)
		{
			printf("Error, reingrese su edad: ");
			scanf("%d", &edadCliente);
		}

		printf("Ingrese su temperatura: ");
		scanf("%f", &temperaturaCliente);
		while(temperaturaCliente > 36)
		{
			printf("Error, reingrese su temperatura: ");
			scanf("%f", &temperaturaCliente);
		}

		printf("Ingrese su genero  femenino, masculino o  no binario: " );
		fflush(stdin);
		scanf("%c", &generoCliente);
		while(generoCliente != 'f' && generoCliente != 'm' && generoCliente != 'o')
		{
			printf("Error, reingrese su genero  femenino, masculino o  no binario: " );
			fflush(stdin);
			scanf("%c", &generoCliente);
		}

		switch(estadoCivil)
		{
		case 's':
			if(flagPrimerSoltera == 0 || edadCliente < edadMasJoven)
			{
				numeroClienteMasJoven = numeroCliente;
				edadMasJoven = edadCliente;
				flagPrimerSoltera = 1;
			}
			break;
		case 'v':
			if(edadCliente > 60)
			{
				contadorViudos60++;
			}
			break;
		}
		precioTotal = PRECIO * (contador + 1);
		if(edadCliente > 60)
		{
			contadorMayores60++;
		}
		contador++;

		printf("Desea ingresar otro cliente??\n"
					"1- Para realizar otro ingreso.\n"
					"Cualquier otra tecla para finalizar.\n"
					"Ingrese una opcion: ");
		scanf("%d", &respuesta);
	}while(respuesta == 1);

	if(contadorMayores60 > (contador / 2))
	{
		precioDescuento = precioTotal - (precioTotal * 0.25);
		flagDescuento = 1;
	}

	if(contadorViudos60  >  0)
	{
		printf("La cantidad de personas viudas mayores de 60 es: %d\n", contadorViudos60);
	}else
	{
		printf("No se ingresaron personas viudas mayores de 60.\n");
	}
	if(flagPrimerSoltera == 1)
	{
		printf("La soltera mas joven posee el numero de cliente %d y su edad es %d\n", numeroClienteMasJoven, edadMasJoven);
	}else
	{
		printf("No se ingresaron mujeres solteras.\n");
	}
	printf("El viaje sin descuentos cuesta: %d \n", precioTotal);

	if(flagDescuento == 1)
	{
		printf("El viaje cuenta con un descuento del 25 porciento, el total es: %d \n", precioDescuento);
	}

	return 0;
}
/*b) el número de cliente y edad de la mujer soltera más joven.
								c) cuánto sale el viaje total sin descuento.
								d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%,
								que solo mostramos si corresponde.*/
