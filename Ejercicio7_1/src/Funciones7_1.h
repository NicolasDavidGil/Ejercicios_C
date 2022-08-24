/*
 * Funciones7_1.h
 *
 *  Created on: 8 may. 2022
 *      Author: Gil Nicolás David
 */

#ifndef FUNCIONES7_1_H_
#define FUNCIONES7_1_H_

#include "Inputs.h"

#define CANTIDAD 10
#define TAM 40
#define ELIMINADO -5

void IniciarVectores(int id[]);

int BuscarEspacio(int id[]);

int MenuInteractivo(void);

int LlenarDatos(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int newID);

int BuscarProductoPorID(int id[]);

int BajaProducto(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD]);

int ModificarProducto(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD]);

void ListarUnProducto(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int index);


void ListarProductos(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD]);

void ListarNacionProducto(int nacion[], int index);

void ListarTipoProducto(int tipo[], int index);

void OrdenarVectorPorPrecio(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int filas);

void OrdenarVectorPorDescripcion(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int filas);


#endif /* FUNCIONES7_1_H_ */
