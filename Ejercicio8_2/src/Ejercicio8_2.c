/*
 ============================================================================
 Name        : 	 Ejercicio8_2.c
 Author      : 	 Gil Nicolas David
 Description : Una empresa importadora de productos apples decide registrar de sus productos los siguientes datos;:

 	 	 	 	 	 	 IdProducto (numerico)
 	 	 	 	 	 	 descripcion(alfanumerico)
 	 	 	 	 	 	 nacionalidad(numerico, con define EEUU, CHINA, OTROS)
 	 	 	 	 	 	 tipo(numerico, con define IPHONE, MAC, IPAD, ACCESORIOS)
 	 	 	 	 	 	 precio(numerico decimal)

 	 	 	 	 	 	 Realizar un programa que permita interactuar con un menu de usuarios con las siguientes opciones:

 	 	 	 	 	 	 ALTA Producto: Se ingresaran los datos de UN solo producto, siempre y cuando haya lugar disponible en el array.
 	 	 	 	 	 	 BAJA Producto: A partir del ingreso del id. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
 	 	 	 	 	 	 MODIFICACION Producto: a partir del ingreso del id. Si existe se podra modificar  el precio o el tipo.
 	 	 	 	 	 	 LISTADO Productos.
 	 	 	 	 	 	 LISTADO ordenado por precio.
 	 	 	 	 	 	 LISTADO ordenado por descripcion
 ============================================================================
 */

#include "Productos.h"

int main(void)
{
	setbuf(stdout, NULL);

	MenuPrincipal();

	return EXIT_SUCCESS;
}
