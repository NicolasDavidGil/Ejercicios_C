/*
 *			 Ejer4_2.c
 *  		Created on: 13 abr. 2022
 *      	Author: Gil Nicolás David
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ejer4_2.h"


int PedirGradosCelcius(char mensaje[], char mensajeError[], int min, int max)
{
	int gradosC;

	printf("%s", mensaje);
	scanf("%d", &gradosC);
	while(gradosC > max || gradosC < min)
	{
		printf("%s", mensajeError);
		scanf("%d", &gradosC);
	}

	return gradosC;
}

int PedirGradosFahrenheit(char mensaje[], char mensajeError[], int min, int max)
{
	int gradosF;

	printf("%s", mensaje);
	scanf("%d", &gradosF);
	while(gradosF > max || gradosF < min)
	{
		printf("%s", mensajeError);
		scanf("%d", &gradosF);
	}

	return gradosF;
}

//(32 °F − 32) × 5/9 = 0 °C fah a celcius

int PasarFahrenheitCelcius(int gradosF)
{
	int conversionFahCel;

	conversionFahCel = (gradosF - 32) * 5/9;

	return conversionFahCel;
}


//(0 °C × 9/5) + 32 = 32 °F cel a fah

int PasarCelciusFahrenheit(int gradosC)
{
	int conversionCelFah;

	conversionCelFah = (gradosC * 9/5) + 32;

	return conversionCelFah;

}
