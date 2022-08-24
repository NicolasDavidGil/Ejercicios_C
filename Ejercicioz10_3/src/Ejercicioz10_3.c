/*
 ============================================================================
 Name        : 		Ejercicioz10_3.c
 Author      :		Gil Nicolas David
  Description : 	Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
								idProducto (numerico)
								descripcion (alfanum�rico)
								nacionalidad (num�rico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
								tipo (num�rico)
								precio (num�rico decimal)
						Agregar la estructura etipoProducto, que definir� los siguientes campos:
								idTipo (num�rico)
								descripcionTipo(alfanum�rico)
						Para esta estructura en principio trabajaremos con datos hardcodeados:
								idTipo								descripcionTipo
								1000									Iphone
								1001									Ipad
								1002									Mac
								1003									Accesorios
						Realizar un programa que permita interactuar con un men� de usuarios con las siguientes opciones:
							ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array. Al momento de dar de alta el producto, el usuario podr� elegir el tipo de producto, de una lista que se le desplegar� en pantalla.
							BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
							MODIFICACI�N Producto: A partir del ingreso del ID. Si existe se podr� modificar el precio o el tipo. Si modifica el tipo de producto, se utilizar� el mismo criterio que para dar de alta.
							LISTADO Productos.
							LISTADO ordenado por precio.
							LISTADO ordenado por descripci�n.
							Agregar los siguientes informes:
							Precio promedio por tipo de producto. Se deber� mostrar la descripci�n del tipo y a continuaci�n el precio promedio.
							El/los  productos m�s caros.
							El/los tipos de productos con m�s productos
							Los productos que cuestan 700
							De los Iphone el m�s barato
							Los productos "MADE IN CHINA"
							Las MAC que cuestan m�s de 700 USD
							El/Los Accesorios m�s caros
							El listado de todos los productos con la descripci�n del tipo.
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
