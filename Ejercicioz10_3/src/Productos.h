/*
 * 	Productos.h
 *  	Created on: 333 Enero 4041
 *      Author: Gil Nicolas David
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include "Inputs.h"

typedef struct
{
	int idTipo;
	char descripcion[50];
}TipoProducto;

typedef struct
{
	int idProducto;
	char descripcion[SIZE];
	int nacionalidadProducto;
	int idTipo;
	float precioProducto;
	int isEmpty;
}eProducto;

void mainMenu(void);

int InteractiveMenu(void);

void startStruct(eProducto list[]);

int findFreeSpace(eProducto list[]);

int newProduct(eProducto list[], TipoProducto tipo[], int lastID);

int deleteProduct(eProducto list[], TipoProducto prod[]);

int Modifyproduct(eProducto this[], TipoProducto prod[]);

int ModifyMenu(void);

int SortByPrice(eProducto list[], int len);

int SortByName(eProducto list[], int len);

int nacionalityMenu(void);

int typeMenu(void);

void PrintUsedID(eProducto* list);

int findByID(eProducto* list, int id);

void InitArray(eProducto list[]);

void PrintTitle(void);

void PrintOneProduct(eProducto list, TipoProducto prod[]);

int PrintAllProducts(eProducto list[], TipoProducto prod[], int length);

void PrintNacionality(eProducto list);

void printTypeProduct(eProducto list, TipoProducto prod[]);

void Informes(eProducto list[], TipoProducto prod[]);

int MenuInformes(void);

float ProductoMasCaro(eProducto list[]);

int MasSetecientos(eProducto list[], eProducto mayores700[]);

float PromedioPorTipo(eProducto list[], int aux);

float MasBaratoIphone(eProducto list[]);

float AccesoriosMasCaros(eProducto list[]);

int MadeInChina(eProducto list[], eProducto made[]);

int MacMasCaros(eProducto list[], eProducto macs[]);

#endif /* PRODUCTOS_H_ */
