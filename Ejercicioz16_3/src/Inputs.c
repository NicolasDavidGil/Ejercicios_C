/*
 * Inputs.c
 *
 *  Created on: 23 may. 2022
 *      Author: Gil Nicolas David
 */

#include "Inputs.h"

int RequestInt(char mensaje[])
{
    char cadena[10];
    int resultado;
    int auxValidacion;

    do
    {
        printf("%s ", mensaje);
        scanf("%s", cadena);
        auxValidacion = ValidateInt(cadena);
        if(auxValidacion == FALSE)
        {
            printf("\nNumero Invalido.\n");
        }
    }while(auxValidacion == FALSE);

    resultado = atoi(cadena);

    return resultado;
}

int RequestIntInRange(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int numero;
	int auxValidar;

	do
	{
		numero = RequestInt(mensaje);
		if(numero < minimo || numero > maximo)
		{
			printf("\n%s..\n", mensajeError);
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
        printf("%s ", mensaje);
        scanf("%s", cadena);
        auxValidacion = ValidateFloatBiggerZero(cadena);
        if(auxValidacion == FALSE)
        {
            printf("\nNumero invalido.\n");
        }
    }while(auxValidacion == -1);

    resultado = atof(cadena);

    return resultado;
}

float RequestFloatInRange(char mensaje[], char mensajeError[], float minimo, float maximo)
{
	float numero;
	int auxValidar;

	do
	{
		numero = RequestFloat(mensaje);
		if(numero < minimo || numero > maximo)
		{
			printf("\n%s.\n", mensajeError);
			auxValidar = -1;
		}else
		{
			auxValidar = 0;
		}
	}while(auxValidar == -1);

	return numero;
}

int ValidateFloatBiggerZero(char cadena[])
{
    int retorno = TRUE;
    int point;
    int len;
    retorno = 1;
    point = 0;
    len = strlen(cadena);
    if (isdigit(cadena[0])  || (cadena[0] == '.' && len > 1) || (cadena[1] == '.' && len > 2))
    {
            for (int i = 1; i < len; i++)
            {
                if (!isdigit(cadena[i]))
                {
                    if (cadena[i] == '.')
                    {
                        point++;
                        if (point > 1)
                        {
                            retorno = FALSE;
                            break;
                        }
                    } else
                    {
                        retorno = FALSE;
                        break;
                    }
                }
            }
    } else
	{
		retorno = FALSE;
	}
    return retorno;
}

int ValidateInt(char cadena[])
{
    int retorno = TRUE;
    int len;

    retorno = 1;
    len = strlen(cadena);

    if (isdigit(cadena[0]) || (cadena[0] == '-' && len > 1))
    {
        for(int i = 1; i < len; i++)
        {
                if (!isdigit(cadena[i]))
                {
                    retorno = FALSE;
                    break;
                }
        }
    } else
    {
        retorno = FALSE;
    }

    return retorno;
}

void RequestString(char mensaje[], char string[], int len)
{

	char entryString[len];
	int lenString;

	lenString = sizeof(entryString);

	printf("%s", mensaje);

	while (CorrectString(entryString, lenString) == FALSE || ValidateString(entryString))
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

	retorno = FALSE;
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
					retorno = TRUE;
				}
			}
		}

	return retorno;
}


int ValidateString(char string[])
{
	int validacion;
	int len;

	validacion = FALSE;

	len = strlen(string);

	if(len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (isalpha(string[i]))
			{
				validacion = TRUE;
			}
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

void PolishFlyCode(char cadena[])
{
	int len;

	len = strlen(cadena);

	for(int i = 0; i < len; i++)
	{
		cadena[i] = toupper(cadena[i]);
	}
}

int CheckOnlyLetters(char string[])
{
	int check;
	int len;

	len = strlen(string);

	for(int i = 0; i < len; i++)
	{
		if(isdigit(string[i]) == 0)
		{
			check = TRUE;
		}else
		{
			check = FALSE;
		}
	}

	return check;
}
