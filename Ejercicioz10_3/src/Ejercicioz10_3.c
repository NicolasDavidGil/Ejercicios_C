/*
 ============================================================================
 Name        : 		Ejercicioz10_3.c
 Author      :		Gil Nicolas David
  Description : 	Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
								idProducto (numerico)
								descripcion (alfanumérico)
								nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
								tipo (numérico)
								precio (numérico decimal)
						Agregar la estructura etipoProducto, que definirá los siguientes campos:
								idTipo (numérico)
								descripcionTipo(alfanumérico)
						Para esta estructura en principio trabajaremos con datos hardcodeados:
								idTipo								descripcionTipo
								1000									Iphone
								1001									Ipad
								1002									Mac
								1003									Accesorios
						Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
							ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array. Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto, de una lista que se le desplegará en pantalla.
							BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
							MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo. Si modifica el tipo de producto, se utilizará el mismo criterio que para dar de alta.
							LISTADO Productos.
							LISTADO ordenado por precio.
							LISTADO ordenado por descripción.
							Agregar los siguientes informes:
							Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
							El/los  productos más caros.
							El/los tipos de productos con más productos
							Los productos que cuestan 700
							De los Iphone el más barato
							Los productos "MADE IN CHINA"
							Las MAC que cuestan más de 700 USD
							El/Los Accesorios más caros
							El listado de todos los productos con la descripción del tipo.
							Por cada tipo la lista de productos.
 ============================================================================
 */

#include "Productos.h"

int main(void)
{
	setbuf(stdout, NULL);

	mainMenu();

	return 0;
}
