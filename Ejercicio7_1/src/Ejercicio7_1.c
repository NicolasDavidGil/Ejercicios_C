/*
 ============================================================================
 Name        : 		Ejercicio7_1.c
 Author      :		Gil Nicolas David
 Description :
							Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
							idProducto (numerico)
							descripcion (alfanumérico)
							nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
							tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
							precio (numérico decimal)

							Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
							ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
							BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
							MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
							LISTADO Productos.
							LISTADO ordenado por precio.
							LISTADO ordenado por descripción.
 ============================================================================
 */

#include "Funciones7_1.h"

int main(void)
{
	setbuf(stdout, NULL);

	int idProducto[CANTIDAD];
	char descripcionProducto[CANTIDAD][TAM];
	int nacionalidadProducto[CANTIDAD];
	int tipoProducto[CANTIDAD];
	float precioProducto[CANTIDAD];
	int contadorDatos = 0;
	int creadorID = 1000;
	int respuestaMain;

	IniciarVectores(idProducto);

	do
	{
		respuestaMain = MenuInteractivo();
		switch(respuestaMain)
		{
		case 1:
			if(LlenarDatos(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto, creadorID) == 0 )
			{
				contadorDatos++;
				creadorID++;
			}
			break;
		case 2:
			if(BajaProducto(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto) == 0)
			{
				contadorDatos--;
			}
			break;
		case 3:
			if(ModificarProducto(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto) == 0)
			{
				puts("\nProducto modificado.\n");
			}
			break;
		case 4:
			ListarProductos(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto);
			break;
		case 5:
			OrdenarVectorPorPrecio(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto, CANTIDAD);
			ListarProductos(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto);
			break;
		case 6:
			OrdenarVectorPorDescripcion(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto, CANTIDAD);
			ListarProductos(idProducto, descripcionProducto, nacionalidadProducto, tipoProducto, precioProducto);
			break;
		case 7:
			printf("\nGracias por usar nuestro programa.\n");
			break;
		}
	}while(respuestaMain != 7);

	return 0;
}


