/*
 ============================================================================
 Name        :	 Ejercicio4_2.c
 Author      :	 Gil Nicolas David
 Description : Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit,
 	 	 	 	 	 	 validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada tipo de escala.
 	 	 	 	 	 	 Las validaciones se hacen en una biblioteca.
 	 	 	 	 	 	 Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Ejer4_2.h"


int main(void)
{
	setbuf(stdout, NULL);

	//Inicio pedir grados celcius

	int gradosCel;

	gradosCel = PedirGradosCelcius("Ingrese grados Celcius: ", "Error, ingrese grados entre 0 y 100: ", 0, 100);

	//Fin pedir grados celcius

	//Inicio pedir grados fahrenheit

	int gradosFah;

	gradosFah = PedirGradosFahrenheit("Ingrese grados Fahrenheit: ", "Error, valores entre 32 y 212 solamente: ", 32, 212);

	//Fin pedir grados fahrenheit

	//pasaje de celcius a fahrenheit

	int gradosCpasadosaF;

	gradosCpasadosaF = PasarCelciusFahrenheit(gradosCel);

	//pasaje de fahrenheit a celcius

	int gradosFpasadosC;

	gradosFpasadosC = PasarFahrenheitCelcius(gradosFah);

	printf("Sus grados Celcius ingresados son; %d \n", gradosCel);
	printf("Sus grados Fahrenheit ingresados son; %d \n", gradosFah);
	printf("Sus grados Celcius pasados a Fahrenheit son; %d \n", gradosCpasadosaF);
	printf("Sus grados Fahrenheit pasados a Celcius son; %d \n", gradosFpasadosC);

	return 0;
}
