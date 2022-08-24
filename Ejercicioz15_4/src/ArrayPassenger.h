/*
 * 		Funciones_TP2.h
 *
 *  		Created on: 20 abr. 2022
 *     	 Author: Gil Nicolás David
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "Inputs.h"

#define SIZE_NAME 52
#define SIZE_CODE 11
#define LEN 2000
#define MAX_CARGA 6
#define MAX_PRICE 5000000
#define LIBRE 1
#define OCUPADO -1
#define ELIMINADO 0

typedef struct
{
	float totalPrecios;
	float promedioPrecios;
	int contadorSuperanProm;
}ePrecios;

typedef struct
{
	int id;
	char name[SIZE_NAME];
	char lastName[SIZE_NAME];
	float price;
	char flycode[SIZE_CODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;


/// @fn 			int InitPassengers(ePassenger*, int)
/// @brief		recorre el array pasajeros y pone todos los valores isEmpty en LIBRE
///
/// @param list
/// @param len
/// @return
int InitPassengers(ePassenger* list, int len);

/// @fn		 	int AddPassenger(ePassenger[], int, int, char[], char[], float, int, int, char[])
/// @brief		Asigna todos los valores recibidos por parametro al primer indice vacio de ePassenger.
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param statusFlight
/// @param flycode
/// @return
int AddPassenger(ePassenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, int statusFlight, char flycode[]);

/// @fn 			int FindPassengerById(ePassenger*, int, int)
/// @brief		Recorre el array passenger buscando un macheo entre los id y el ingreso del usuario
///
/// @param list
/// @param len
/// @param id
/// @return
int FindPassengerById(ePassenger* list, int len,int id);

/// @fn 			void ModifyPassenger(ePassenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param indice
void ModifyPassenger(ePassenger* list, int len, int indice);

/// @fn int RemovePassenger(ePassenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param indice
/// @return
int RemovePassenger(ePassenger* list, int len, int indice);

/// @fn int SortPassengers(ePassenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param order
/// @return
int SortPassengers(ePassenger* list, int len, int order);

/// @fn int PrintPassenger(ePassenger*, int)
/// @brief
///
/// @param list
/// @param length
/// @return
int PrintPassengers(ePassenger* list, int length);

/// @fn void PrintPassengerOnly(ePassenger)
/// @brief
///
/// @param pasajero
void PrintPassengerOnly(ePassenger pasajero);

/// @fn void ForcedLoad(ePassenger*, eCargaForzada*, int)
/// @brief
///
/// @param pasajero
/// @param list
/// @param len
void ForcedLoad (ePassenger* pasajero, ePassenger* list, int len);

/// @fn void SortPassengerByLastNameUpward(ePassenger[], int)
/// @brief
///
/// @param list
/// @param len
void SortPassengerByLastNameUpward(ePassenger list[], int len);

/// @fn void SortPassengerByLastNameDescendant(ePassenger[], int)
/// @brief
///
/// @param list
/// @param len
void SortPassengerByLastNameDescendant(ePassenger list[], int len);

/// @fn void PrintTitle(void)
/// @brief
///
void PrintTitle(void);

/// @fn void PrintTypePassenger(ePassenger[], int)
/// @brief
///
/// @param list
/// @param index
void PrintTypePassenger(ePassenger pasajero);

/// @fn 			void PrintStatusFligth(ePassenger[], int)
/// @brief
///
/// @param list
/// @param index
void PrintStatusFligth(ePassenger pasajero);

/// @fn int SortPassengersByCode(ePassenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param order
/// @return
void SortPassengersByCode(ePassenger* list, int len, int order);

/// @fn void ShowPrices(ePassenger*, int, int)
/// @brief
///
/// @param pasajero
/// @param len
/// @param contador
void ShowPrices(ePassenger* pasajero,  int len, int contador);

/// @fn int RequestPassenger(ePassenger*, int)
/// @brief
///
/// @param list
/// @param len
/// @return
int RequestPassenger(ePassenger* list, int len);

/// @fn int FindFreeSpace(ePassenger*, int)
/// @brief
///
/// @param list
/// @param len
/// @return
int FindFreeSpace(ePassenger* list, int len);

/// @fn int MenuTipoPasajero(void)
/// @brief
///
/// @return
int TypePassenger(void);

/// @fn int MenuEstadoVuelo(void)
/// @brief
///
/// @return
int StatusFligth(void);

/// @fn void PrintActivePassenger(ePassenger)
/// @brief
///
/// @param pasajero
void PrintActivePassenger(ePassenger* pasajero);

/// @fn void PrintPassengerFound(ePassenger*, int)
/// @brief
///
/// @param pasajero
/// @param index
void PrintPassengerFound(ePassenger* pasajero, int index);

/// @fn void PrintID(ePassenger*)
/// @brief
///
/// @param pasajero
void PrintID(ePassenger* pasajero);

#endif /* ARRAYPASSENGER_H_ */
