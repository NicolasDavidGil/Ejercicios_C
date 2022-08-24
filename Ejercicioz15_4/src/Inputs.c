/*
 * Inputs.c
 *
 *  Created on: 9 may. 2022
 *      Author: Gil Nicolás David
 */

#include "Inputs.h"


int RequestInt(char mensaje[])
{
    char cadena[10];
    int resultado;
    int auxValidacion;

    do
    {
        printf("\n%s ", mensaje);
        scanf("%s", cadena);
        auxValidacion = ValidateNumber(cadena);
        if(auxValidacion == -1)
        {
            printf("\nError ingreso incorrecto.\n");
        }
    }while(auxValidacion == -1);

    resultado = atoi(cadena);

    return resultado;
}

int RequestIntInRange(char mensaje[], int minimo, int maximo)
{
	int numero;
	int auxValidar;

	do
	{
		numero = RequestInt(mensaje);
		if(numero < minimo || numero > maximo)
		{
			printf("\nNumero ingresado fuera de rango.\n");
			auxValidar = -1;
		}else
		{
			auxValidar = 0;
		}
	}while(auxValidar == -1);

	return numero;
}

float RequestFloat(char mensaje[])
{
    char cadena[10];
    float resultado;
    int auxValidacion;


    do
    {
        printf("\n%s ", mensaje);
        scanf("%s", cadena);
        auxValidacion = ValidateNumber(cadena);
        if(auxValidacion == -1)
        {
            printf("\nError ingreso incorrecto.\n");
        }
    }while(auxValidacion == -1);

    resultado = atof(cadena);

    return resultado;
}

float RequestFloatInRange(char mensaje[], float minimo, float maximo)
{
	float numero;
	int auxValidar;

	do
	{
		numero = RequestFloat(mensaje);
		if(numero < minimo || numero > maximo)
		{
			printf("\nNumero ingresado fuera de rango.\n");
			auxValidar = -1;
		}else
		{
			auxValidar = 0;
		}
	}while(auxValidar == -1);

	return numero;
}


int ValidateNumber(char numero[])
{
    int retorno = -1;
    int longitud;

    longitud = strlen(numero);

	for(int i = 0; i < longitud; i++)
    {
		if(isdigit(numero[0])  || (numero[0] == '.' && longitud > 1) || (numero[1] == '.' && longitud > 2))
        {
            if(isdigit(numero[i]) || (numero[i] == '.'))
            {
                retorno = 1;
            }
        }
    }
    return  retorno;
}


void RequestString(char mensaje[], char string[], int len)
{

	char entryString[len];
	int lenString;

	lenString = sizeof(entryString);

	printf("%s", mensaje);

	while (CorrectString(entryString, lenString) == -1 || !ValidateString(entryString))
	{
		printf("ERROR! %s", mensaje);
	}

	PolishString(entryString);

	strncpy(string, entryString, len);

}

int CorrectString(char string[], int len)
{
	char stringLocal[len];
	int retorno;
	int lenString;

	retorno = -1;
	lenString = sizeof(stringLocal);

	if (string != NULL && len > 0)
	{
			fflush(stdin);
			if(fgets(stringLocal, lenString, stdin) != NULL)
			{

				if(stringLocal[strnlen(stringLocal, lenString)-1] == '\n')
				{
					stringLocal[strnlen(stringLocal, lenString)-1] = '\0';
				}

				if(strnlen(stringLocal, lenString) <= len && strlen(stringLocal) > 0)
				{
					strncpy(string, stringLocal, len);
					retorno = 0;
				}
			}
		}

	return retorno;
}


int ValidateString(char string[])
{
	int validacion;
	int len;

	validacion = 1;

	len = strlen(string);

	for (int i = 0; i < len; i++)
	{
		if (!isalpha(string[i]) || len == 0)
		{
			validacion = -1;
		}
	}

	return validacion;
}


void PolishString(char cadena[])
{
	int len;

	len = strlen(cadena);

    for(int i = 0; i < len; i++)
    {
        cadena[i] = tolower(cadena[i]);
    }

	cadena[0] = toupper(cadena[0]);

	for(int i = 0; i < len; i++)
	{
		if(cadena[i] == ' ')
		{
			cadena[i+1] = toupper(cadena[i+1]);
		}
	}

}

void RequestAlphaDigit(char mensaje[], char cadena[], int len)
{
	char entryString[len];
	int lenString;

	lenString = sizeof(entryString);

	printf("%s", mensaje);

	while(CorrectString(entryString, lenString) == -1 || lenString > len || entryString[0] == '\n')
	{
		printf("Error %s", mensaje);
	}

	for(int i = 0; i < len; i++)
	{
		entryString[i] = toupper(entryString[i]);
	}

	strncpy(cadena, entryString, len);
}
