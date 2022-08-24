/*
 * Menus.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Gil Nicolás David
 */

#include "Menus.h"

void MainMenu(void)
{
	LinkedList* Pasajero= ll_newLinkedList();

	ePassenger ArrayCarga[MAX_CARGA] =   {{501, "Nicolas", "Gil", 23000, "A321DC", 2, 3, OCUPADO},
																				{502, "Marina", "Cardozo", 32500, "FE321", 3, 2, OCUPADO},
																				{503, "German", "Scarafilo", 19000, "T87JPI", 4, 4, OCUPADO},
																				{504, "Martin", "Harry", 23000, "NW7412", 1, 1, OCUPADO},
																				{505, "Raffi", "Kocak", 42000, "PFQ417", 3, 3, OCUPADO},
																				{506, "Gianni", "Maggiori", 25000, "NW7412", 1, 1, OCUPADO}};
	int respuestaMain;
	int respuestaCase1;
	int respuestaCase2;
	int respuestaCase3;
	int respuestaCase6;
	int contadorDatos = 0;
	int deleteOK;
	int flagForced = 0;

	 if(Pasajero != NULL && LEN > 0)
    {
        InitPassengers(Pasajero, LEN);
        do
        {
            respuestaMain = InteractiveMenu();
            switch(respuestaMain)
            {
                case 1:
                    respuestaCase1 = RequestPassenger(Pasajero, LEN);
                    if(respuestaCase1 == 1)
                    {
                        printf("\nPasajero cargado exitosamente.\n");
                        contadorDatos++;
                    }else
                    {
                        printf("\nError en la carga del pasajero.\n");
                    }
                    break;
                case 2:
                	if(contadorDatos > 0)
                	{
                		PrintID(Pasajero);
						respuestaCase2 = MenuRequestID("\nBienvenido a la modificacion de pasajero.\n"
																						"Ingrese el id del pasajero que desea modificar: ");

						ModifyPassenger(Pasajero, LEN, respuestaCase2);

                	}else
                	{
                		printf("\nNo hay datos cargados para modificar. Puede cargar con la opcion 1.\n");
                	}
                    break;
                case 3:
                	if(contadorDatos > 0)
                	{
                		PrintID(Pasajero);
                		respuestaCase3 = MenuRequestID("\nBienvenido a la baja de pasajero.\n"
																						"Ingrese el id del pasajero que desea eliminar: ");
						deleteOK = RemovePassenger(Pasajero, LEN, respuestaCase3);
						if(deleteOK == 1)
						{
							printf("\nPasajero eliminado.\n");
							contadorDatos--;
						}
					}else
					{
						printf("\nNo hay datos cargados para borrar. Puede cargar con la opcion 1.\n");
					}
                    break;
                case 4:
                	if(contadorDatos > 0)
                	{
                		MenuCase4(Pasajero,  LEN, contadorDatos);
                	}else
                	{
                		printf("\nNo hay datos cargados para mostrar. Puede cargar con la opcion 1.\n");
                	}
                break;
                case 5:
                	if(flagForced == 0)
                	{
						ForcedLoad(Pasajero, ArrayCarga, LEN);
						printf("\nDatos forzados cargados correctamente.\n");
						contadorDatos = contadorDatos + MAX_CARGA;
						flagForced = 1;
                	}else
                	{
                		printf("\nYa se utilizo la carga forzada.\n");
                	}
                break;
                case 6:
                	respuestaCase6 = MenuCase6();
                	if(respuestaCase6 == 1)
                	{
                		printf("\nTodo esto sera borrado, pero gracias por usar nuestro programa.\n");
                	}else
                	{
                		printf("\nGracias por quedarte, sigamos...\n");
                	}

                break;
                default:
                printf("\nOpcion invalida, por favor reingrese.\n");
                break;
            }
        }while(respuestaCase6 != 1);
    }

}

int InteractiveMenu(void)
{
	int respuesta;

	respuesta = RequestIntInRange("\n¡Qué desea hacer?\n"
																"\n(1) - Alta de pasajero.\n"
																"(2) - Modificar pasajero. \n"
																"(3) - Baja de pasajero. \n"
																"(4) - Informar.\n"
																"(5) - Carga Forzada.\n"
																"(6) - Salir del programa.\n"
																"\nIngrese una opción: ", 1, 6);
	return respuesta;
}

int MenuRequestID(char mensaje[])
{
	int idABuscar;

	idABuscar = RequestInt(mensaje);
	return idABuscar;
}

void MenuCase4(ePassenger* pasajero, int len,  int contador)
{
	int respuesta;
	int ordenSort;
	int orderSortCode;
	int confirmarSortApellido;

	do
	{
		respuesta = RequestIntInRange("\nBienvenido a la sección de informes.\n"
																"\n(1) - Listar los pasajeros alfabéticamente por Apellido y Tipo de pasajero.\n"
																"(2) - Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
																"(3) - Lista de pasajeros por código de vuelo y estados de vuelos (Activos)\n"
																"(4) - Volver al menu principal.\n"
																"Que desea hacer:", 1, 4);
        switch(respuesta)
    	{
    	case 1:
    		ordenSort = SubMenuCase4();
    		confirmarSortApellido = SortPassengers(pasajero, len, ordenSort);
    		if(confirmarSortApellido == 1)
    		{
    			PrintTitle();
    			PrintPassengers(pasajero, LEN);
    		}else
    		{
    			printf("Error en el sort por apellido"); //para control de funcionamiento interno.
    		}
    		break;
    	case 2:
    		ShowPrices(pasajero, len, contador);
    		break;
    	case 3:
    		orderSortCode = SubMenuCase4();
    		SortPassengersByCode(pasajero, LEN, orderSortCode);
    		PrintActivePassenger(pasajero);
    		break;
    	case 4:
    		printf("\nVolviendo al menu principal. \n");
    		system("pause");
    		break;
    	default:
    		printf("\nOpción no válida, reingrese.\n");
    		break;
    	}
    }while(respuesta != 4);

}

int SubMenuCase4(void)
{
	int order;

	order = RequestIntInRange("\nElija el orden en que desea hacerlo.\n"
														"(1) - Para orden ascendente.\n"
														"(2) - Para orden descendente.\n"
														"Que orden prefiere: ", 1, 2);
	return order;
}

int MenuCase6 (void)
{
	int respuesta;

	respuesta = RequestIntInRange("\nEsta a punto de abandonar el programa, esta seguro??\n"
																		"1 - Para salir. \n"
																		"Cualquier otra opción para volver al programa.\n"
																		"Qué desea hacer?: ", 1, 50000000);
	return respuesta;
}



