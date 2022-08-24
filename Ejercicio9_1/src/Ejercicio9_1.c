/*
 ============================================================================
 Name        : 		Ejercicio9_1.c
 Author      : 		Gil Nicolas David
 Description : 	Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
							idProducto (numerico)
							descripcion (alfanumérico)
							nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
							tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
							precio (numérico decimal)
							Realizar un programa que permita interactuar con un menu de usuarios con las siguientes opciones:
							ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
							BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
							MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
							LISTADO Productos.
							LISTADO ordenado por precio.
							LISTADO ordenado por descripcion.
					-->	Agregar los siguientes informes:
							El/los  productos mas caros.
							Los productos que cuestan 700
							Precio promedio por tipo de producto.
							De los Iphone el mas barato
							Los productos "MADE IN CHINA"
							Las MAC que cuestan mas de 700 USD
							El/Los Accesorios mas caros

 ============================================================================
 */

#include "Producto.h"

int main(void)
{
	setbuf(stdout, NULL);

	MenuPrincipal();

	return EXIT_SUCCESS;
}
