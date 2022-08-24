/*
 * 	  Funciones_TP2.c
 * 	  Created on: 20 abr. 2022
 *      Author: Gil Nicolás David
 */

#include "ArrayPassenger.h"


int InitPassengers(ePassenger* list, int len)
{
	int retorno;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = LIBRE;
		}
		retorno = 1;
	}else
	{
		retorno = 0;
	}

	return retorno;
}


int AddPassenger(ePassenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, int statusFlight, char flycode[])
{
	int retorno = -1;
	int indice;


	if(list != NULL && len > 0)
	{
	    indice = FindFreeSpace(list, len);  //no necesito verificar que haya lugar libre porque ya lo hizo RequestPassenger
	                                        						//solo necesito saber cual es ese espacio libre
	    list[indice].id = id;
        strcpy(list[indice].name, name);
        strcpy(list[indice].lastName, lastName);
        list[indice].price = price;
        list[indice].typePassenger = typePassenger;
        list[indice].statusFlight = statusFlight;
        strcpy(list[indice].flycode, flycode);
        list[indice].isEmpty = OCUPADO;
        retorno = 1;
	}


	return retorno;
}


int FindPassengerById(ePassenger list[], int len,int id)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == OCUPADO)
        {
            index = i;
            break;
        }
    }

    return index;
}

void ModifyPassenger(ePassenger list[], int len, int idAModificar)
{
    int index;
    int respuesta;

    index = FindPassengerById(list, len, idAModificar);

    if(list != NULL && len > 0 && index != -1)
    {
         PrintPassengerFound(list, index);

        do
        {
            respuesta = RequestIntInRange("\nQue datos desea modificar.\n"
																	"(1) - Modificar nombre.\n"
																	"(2) - Modificar apellido.\n"
																	"(3) - Modificar precio.\n"
																	"(4) - Modificar tipo de pasajero.\n"
																	"(5) - Modificar codigo de vuelo.\n"
																	"(6) - Salir de modificacion.\n"
																	"Ingrese una opcion: ", 1, 6);
            switch(respuesta)
            {
                case 1:
                    RequestString("Ingrese el nuevo nombre: ", list[index].name, SIZE_NAME);
                    break;
                case 2:
                    RequestString("Ingrese el nuevo apellido: ", list[index].lastName, SIZE_NAME);
                    break;
                case 3:
                    list[index].price = RequestFloatInRange("Ingrese el nuevo precio del vuelo: ", LIBRE, MAX_PRICE);
                    break;
                case 4:
                    list[index].typePassenger = TypePassenger();
                    break;
                case 5:
                    RequestAlphaDigit("Ingrese el nuevo codigo de vuelo: ", list[index].flycode, SIZE_CODE);
                    break;
                case 6:
                    printf("\nVolviendo al menu principal.\n");
                    system("pause");
                    break;
                default:
                    printf("\nOpcion Incorrecta, reingrese.\n");
                    break;

            }
        }while(respuesta != 6);
    }
}

int RemovePassenger(ePassenger* list, int len, int idABorrar)
{
    int retorno = 0;
    int confirmacion;
    int index;
    char anulacion[SIZE_CODE] = "Eliminado";

    index = FindPassengerById(list, len, idABorrar);

    if(list != NULL && len > 0 && index != -1)
    {
		PrintPassengerFound(list, index);

		confirmacion = RequestIntInRange(	"Confirmar eliminacion de pasajero.\n"
																					"(1) - Para confirmar.\n"
																					"(2) - Para cancelar.\n"
																					"Que desea hacer: ", 1, 2);
		if(confirmacion == 1)
		{
			strcpy(list[index].name, anulacion);
			strcpy(list[index].lastName, anulacion);
			strcpy(list[index].flycode, anulacion);
			list[index].price = 0;
			list[index].typePassenger = 0;
			list[index].statusFlight = 0;
			list[index].isEmpty = ELIMINADO;
			retorno = 1;
        }else
        {
            printf("\nEliminacion cancelada.\n");
        }
    }else
    {
    	printf("\nNo se encontro pasajero para ese id.\n");
    }
    return retorno;
}


int SortPassengers(ePassenger* list, int len, int order)
{
	int retorno = -1;

	if(order == 1)
	{
		printf("\nOrden ascendiente establecida.\n");
		SortPassengerByLastNameUpward(list, len);
		retorno = 1;
	}else
	{
		printf("\nOrden descendiente establecida.\n");
		SortPassengerByLastNameDescendant(list, len);
		retorno = 1;
	}
	return retorno;
}

void SortPassengerByLastNameUpward(ePassenger list[], int len)
{
	ePassenger listAux;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len -1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if((strcmp(list[i].lastName, list[j].lastName) > 0) && (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO))
					{
						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;
					}else if((strcmp(list[i].lastName, list[j].lastName) == 0) && (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO))
					{
						if(list[i].typePassenger > list[j].typePassenger)
						{
							listAux = list[i];
							list[i] = list[j];
							list[j] = listAux;
						}
					}
				}
			}
		}
}

void SortPassengerByLastNameDescendant(ePassenger list[], int len)
{
	ePassenger listAux;
	for(int i = 0; i < len -1; i++)
	{
		for(int j = i + 1; j < len; j++)
		{
			if((strcmp(list[i].lastName, list[j].lastName) < 0) && (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO))
			{
				listAux = list[i];
				list[i] = list[j];
				list[j] = listAux;
			}else if((strcmp(list[i].lastName, list[j].lastName) == 0) && (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO))
			{
				if(list[i].typePassenger < list[j].typePassenger)
				{
						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;
				}
			}
		}
	}
}


int PrintPassengers(ePassenger* list, int length)
{
    if(list != NULL && length >= 0)
    {
    	 for(int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
            	PrintPassengerOnly(list[i]);
            }
        }

    }
    return 0;
}

void PrintPassengerOnly(ePassenger pasajero)
{
    printf("%d\t\t %10s \t\t%10s\t%10s\t%.2f"
    													,pasajero.id
														,pasajero.name
														,pasajero.lastName
														,pasajero.flycode
														,pasajero.price);
    PrintTypePassenger(pasajero);
    PrintStatusFligth(pasajero);
    printf("\n");
}

void PrintTitle(void)
{
    printf("========================================================================================================================================\n"
    			"%10s %10s %10s %10s %10s %10s %10s" ,"ID PASAJERO |"
																					,"NOMBRE PASAJERO |"
																					,"APELLIDO PASAJERO |"
																					,"CODIGO VUELO |"
																					,"PRECIO VUELO |"
																					,"TIPO PASAJERO |"
																					,"ESTADO DE VUELO |\n"
	      "========================================================================================================================================\n");
}

void PrintTypePassenger(ePassenger pasajero)
{
	switch(pasajero.typePassenger)
	{
	case 1:
		printf("\t%10s","Promocional");
		break;
	case 2:
		printf("\t%10s","Turista");
		break;
	case 3:
		printf("\t%10s","Ejecutiva");
		break;
	case 4:
		printf("\t%10s","Primera Clase");
		break;
	}
}

void PrintStatusFligth(ePassenger pasajero)
{
	switch(pasajero.statusFlight)
	{
	case 1:
		printf("\t%10s","Demorado");
		break;
	case 2:
		printf("\t%10s","Cancelado");
		break;
	case 3:
		printf("\t%10s","Activo");
		break;
	case 4:
		printf("\t%10s","Finalizado");
		break;
	}
}


void SortPassengersByCode(ePassenger* list, int len, int order)
{
	ePassenger listAux;

	if(list != NULL && len > 0 && (order == 1 || order == 2))
	{
		switch(order)
		{
		case 1:
			for(int i = 0; i < len -1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if((strcmpi(list[i].flycode, list[j].flycode) > 0)
							&& (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO))
					{
						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;
					}
				}
			break;
		case 2:
			for(int i = 0; i < len -1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if((strcmpi(list[i].flycode, list[j].flycode) < 0)
							&& (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO))
					{
						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;
					}
				}
			}
			break;
			}
		}
	}
}

void ShowPrices(ePassenger* pasajero,  int len, int contador)
{
	int contadorSuperarProm = 0;
	float totalPrecios = 0;
	float promedioPrecios;

	for(int i = 0; i < len; i++)
	{
		if(pasajero[i].isEmpty == OCUPADO)
		{
			totalPrecios = totalPrecios + pasajero[i].price;
		}
	}

	promedioPrecios = totalPrecios / contador;

	for(int i = 0; i < len; i++)
	{
		if(pasajero[i].isEmpty == OCUPADO && pasajero[i].price > promedioPrecios)
		{
			contadorSuperarProm++;
		}
	}

	printf("\nEl total de los precios es: %.2f\n", totalPrecios);
	printf("El promedio de los precios es: %.2f \n", promedioPrecios);
	printf("La cantidad de pasajeros que superan el precio promedio es: %d \n", contadorSuperarProm);
}

void ForcedLoad (ePassenger* pasajero, ePassenger* list, int len)
{
	int index;

	if(pasajero != NULL && list != NULL && len > 0)
	{
		for(int j = 0; j < MAX_CARGA; j++)
		{
			index = FindFreeSpace(pasajero, LEN);
			if(index != -1)
			{
				pasajero[index] = list[j];
			}
		}
	}
}


int RequestPassenger(ePassenger* list, int len)
{
	int retorno ;
	int verificarAdd;
	int checkSpace;
	char nombre[SIZE_NAME];
	char apellido[SIZE_NAME];
	float precio;
	char codigoVuelo[SIZE_CODE];
	int tipoPasajero;
	int estadoVuelo;
	int idCreador = 1000;
	int id;


	if(list != NULL && len > 0)
	{
	    checkSpace = FindFreeSpace(list, LEN);  	//reviso que haya al menos un lugar libre para guardar.
	    if(checkSpace != -1)                    					//no uso como indice solo verifico, el indice final lo trae addPassenger.
	    {
    		RequestString("\nIngrese nombre del pasajero: ", nombre, SIZE_NAME);
    		RequestString("\nIngrese apellido del pasajero: ", apellido, SIZE_NAME);
    		precio = RequestFloatInRange("Ingrese precio del vuelo: ", LIBRE, MAX_PRICE);
    		RequestAlphaDigit("\nIngrese el codigo del vuelo: ", codigoVuelo, SIZE_CODE);
    		tipoPasajero = TypePassenger();
    		estadoVuelo = StatusFligth();
    		id = idCreador;
    		idCreador++;

    		verificarAdd = AddPassenger(list, LEN, id, nombre, apellido, precio, tipoPasajero, estadoVuelo, codigoVuelo);
    		if(verificarAdd == 1)
    		{
    		    retorno = 1;
    		}else
    		{
    		    retorno = -1;
    		}
    	}else
	    {
	        printf("\nNo quedan lugares libres.\n");
	    }
	}

	return retorno;
}

int FindFreeSpace(ePassenger* list, int len)
{
	int index = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int TypePassenger(void)
{
	int respuesta;

	respuesta = RequestIntInRange("\nTipo de pasajero.\n"
																		"1 - Promocional.\n"
																		"2 - Turista. \n"
																		"3 - Ejecutiva.\n"
																		"4 - Primera Clase. \n"
																		"Elija tipo de pasajero: ", 1, 4);


	return respuesta;
}

int StatusFligth(void)
{
	int respuesta;
	respuesta = RequestIntInRange("\nTipo de pasajero.\n"
															"1 - Demorado.\n"
															"2 - Cancelado. \n"
															"3 - Activo.\n"
															"4 - Finalizado. \n"
															"Elija estado de vuelo: ", 1, 4);
		return respuesta;
}

void PrintID(ePassenger* pasajero)
{
	printf("\nID disponibles: \n");
	for(int i = 0; i < LEN; i++)
	{
		if(pasajero[i].isEmpty == OCUPADO)
		{
			printf("%d \n",pasajero[i].id);
		}
	}
}

void PrintActivePassenger(ePassenger* pasajero)
{
	int flagActive = 0;

	PrintTitle();
	for(int i = 0; i < LEN; i++)
	{
		if(pasajero[i].isEmpty == OCUPADO && pasajero[i].statusFlight == 3)
		{
			PrintPassengerOnly(pasajero[i]);
			flagActive = 1;
		}
	}
	if(flagActive == 0)
	{
		printf("\nNo tenemos vuelos activos.\n");
	}
}

void PrintPassengerFound(ePassenger* pasajero, int index)
{
	char nomSpace[60];
    char nomApel[100];


    strcpy(nomSpace, (strcat(pasajero[index].name, " ")));
    strcpy(nomApel,(strcat(nomSpace, pasajero[index].lastName)));

    printf("\nPasajero encontrado\n"
            "ID pasajero: %d.\n"
            "Nombre pasajero: %s.\n", pasajero[index].id, nomApel);
}

