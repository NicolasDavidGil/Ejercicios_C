/*
 * Productos.h
 *
 *  Created on: 20 may. 2022
 *      Author: Gil Nicolas David
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include "Inputs.h"

#define LEN 20
#define SIZE 52
#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1


typedef struct
{
	int idProducto;
	char descripcion[SIZE];
	int nacionalidadProducto;
	int tipoProducto;
	float precioProducto;
	int isEmpty;
}eProducto;

void MenuPrincipal(void);

int MenuInteractivo(void);

void IniciarArray(eProducto list[]);

int BuscarEspacio(eProducto list[]);

void LlenarUnProducto(eProducto list[], int index);

int MenuNacionalidad(void);

int MenuTipoProducto(void);

void PrintID(eProducto* list);

int EncontrarPorID(eProducto* list, int id);

int BajaProducto(eProducto* list, int id);

void ModificarProducto(eProducto* list, int id);

void PrintTipoProducto(eProducto list);

void PrintNacionalidadProducto(eProducto list);

void PrintUnProducto(eProducto list);

int PrintTodosProductos(eProducto* list, int length);

void PrintTitle(void);

int OrdenarPorPrecio(eProducto list[], int len);

int OrdenarPorDescripcion(eProducto list[], int len);

#endif /* PRODUCTOS_H_ */


