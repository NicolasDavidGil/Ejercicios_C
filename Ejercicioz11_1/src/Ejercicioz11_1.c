/*
 ============================================================================
 Name        : 		Ejercicioz11_1.c
 Author      : 		Gil Nicolas David
 Description :
							Al ejercicio 10.3

							Agregar la estructura eNacionalidad, que definir� los siguientes campos:
							*idNacionalidad (num�rico)
							*descripcionNacionalidad(alfanum�rico)

							Para esta estructura en principio trabajaremos con datos hardcodeados:
							id	Nacionalidad		descripcionNacionalidad
							1									EEUU
							2									CHINA
							3									OTRO

							 Realizar un programa que permita interactuar con un men� de usuarios con las siguientes opciones:
							ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array. Al momento de dar de alta el producto, el usuario podr� elegir el tipo de producto, de una lista que se le desplegar� en pantalla.
							BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
							MODIFICACI�N Producto: A partir del ingreso del ID. Si existe se podr� modificar el precio o el tipo. Si modifica el tipo de producto, se utilizar� el mismo criterio que para dar de alta.
							LISTADO Productos.
							LISTADO ordenado por precio.
							LISTADO ordenado por descripci�n.
							Agregar los siguientes informes:
							El/los  productos m�s caros.
							Precio promedio por tipo de producto. Se deber� mostrar la descripci�n del tipo y a continuaci�n el precio promedio.
							El listado de todos los productos con la descripci�n del tipo.
							Por cada tipo la lista de productos.

							Se agregan los siguientes listados:
							El/los tipos de productos con m�s productos importados.

 ============================================================================
 */
#include "Productos.h"

int main(void)
{
	setbuf(stdout, NULL);

	mainMenu();

	return 0;
}
