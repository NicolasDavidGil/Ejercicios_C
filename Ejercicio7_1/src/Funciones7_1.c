/*
 * Funciones7_1.c
 *
 *  Created on: 8 may. 2022
 *      Author: Gil Nicolás David
 *
 *
 */

#include "Funciones7_1.h"

int MenuInteractivo(void)
{
	int opcion;

	printf("\n1 - ALTA PRODUCTO\n"
				"2 - BAJA PRODUCTO\n"
				"3 - MODIFICACION PRODUCTO\n"
				"4 - LISTADO PRODUCTOS\n"
				"5 - LISTADO POR PRECIO\n"
				"6 - LISTADO POR DESCRIPCION\n"
				"7 - SALIR");

	opcion = RequestIntInRange("\nIngrese una opcion: ", "Opcion no valida", 1, 7);

	return opcion;
}

void IniciarVectores(int id[])
{
	for(int i = 0; i < CANTIDAD; i++)
	{
		id[i] = TRUE;
	}
}

int BuscarEspacio(int id[])
{
	int index = -1;

	for(int i = 0; i < CANTIDAD; i++)
	{
		if(id[i] == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}

int LlenarDatos(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int newID)
{
	int i;
	int retorno = FALSE;

	i = BuscarEspacio(id);

	if(i != -1)
	{
		id[i] = newID;

		RequestString("\nIngrese la descripcion del producto: ", descripcion[i], TAM);

		printf("\nIngrese la nacionalidad del producto.\n"
					"1 - EEUU\n"
					"2 - CHINA\n"
					"3 - OTRO\n");
		nacion[i] = RequestIntInRange("Nacionalidad:  ", "Opcion no valida", 1, 3);

		printf("\nIngrese el tipo de producto.\n"
					"1 - IPHONE\n"
					"2 - MAC\n"
					"3 - IPAD\n"
					"4 - ACCESORIOS\n");
		tipo[i] = RequestIntInRange("Opcion: ", "Opcion no valida", 1, 4);

		precio[i] = RequestIntInRange("\nIngrese el precio del producto: ", "valor no valido", 1, INT_MAX);

		printf("\nArticulo cargado exitosamente.\n"
					"\nID : %d\n"
					"Descripcion: %s\n"	, id[i]
														 	,descripcion[i]);
		retorno = 0;

	}else
	{
		printf("\nNo se dispone de mas lugares libres.\n");
	}

	return retorno;
}

int BuscarProductoPorID(int id[])
{
	int index = FALSE;
	int indice;

	indice = RequestIntInRange("\nIngrese el id del producto a buscar: ", "Ingreso no valido", 1000, 2000);

	for(int i = 0; i < CANTIDAD; i++)
	{
		if(id[i] == indice && id[i] != FALSE)
		{
			index = indice;
		}
	}
	return index;
}

int BajaProducto(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD])
{
	int index;
	int confirmacion;
	int retorno = FALSE;

	index = BuscarProductoPorID(id);

	if(index != FALSE)
	{
		printf("\nProducto encontrado.\n"
					"Id del producto: %d \n"
					"Nombre producto: %s\n", index, descripcion[index]);
		printf("\n1 - Para confirmar borrado.\n"
					"Cualquier otra tecla para cancelar.\n");
		confirmacion = RequestIntInRange("\nQue desea hacer: ", "Opcion no valida", 1, INT_MAX);
		if(confirmacion == 1)
		{
			id[index] = ELIMINADO;
			printf("\nProducto eliminado.\n");
			retorno = TRUE;
		}else
		{
			printf("\nSe ha cancelado la eliminacion del producto\n");
		}
	}else
	{
		printf("\nEl producto que busco no existe o ha sido eliminado\n");
	}
	return retorno;
}

int ModificarProducto(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD])
{
	int retorno = FALSE;
	int respuesta;
	int index;

	index = BuscarProductoPorID(id);
	if(index != -1)
	{
		printf("\nProducto encontrado.\n"
					"Id del producto: %d \n"
					"Nombre producto: %s\n", index, descripcion[index]);
		printf("\n1 - Para modificar precio.\n"
					"2 - Para modificar tipo."
					"3 - Para volver sin modificar.");

		respuesta = RequestIntInRange("\nQue desea hacer: ", "Opcion no validad", 1, 3);
		switch(respuesta)
		{
		case 1:
			precio[index] = RequestFloatInRange("\nIngrese el nuevo precio del producto: ", "Ingreso no valido", 1, INT_MAX);
			retorno = TRUE;
			break;
		case 2:
			printf("\nIngrese el tipo de producto.\n"
						"1 - IPHONE\n"
						"2 - MAC\n"
						"3 - IPAD\n"
						"4 - ACCESORIOS\n");
			tipo[index] = RequestIntInRange("\nIngrese opcion: ", "Opcion no valida", 1, 4);
			retorno = TRUE;
			break;
		case 3:
			printf("\nSe ha cancelado la modificacion.\n");
			break;
		default:
			printf("\nOpcion no valida.\n");
			break;
		}
	}else
	{
		printf("\nNo se ha encontrado el producto solicitado\n");
	}

	return retorno;
}

void ListarProductos(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD])
{
	for(int i = 0; i < CANTIDAD; i++)
	{
		ListarUnProducto(id, descripcion, nacion, tipo, precio, i);
	}
}

void ListarUnProducto(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int index)
{
	if(id[index] != TRUE && id[index] != ELIMINADO)
	{
		printf("\n--------------------------------------------------------------------------\n"
					"Id del producto: %d\n", id[index]);
		printf("Descripcion producto: %s\n", descripcion[index]);
		printf("\nEl precio del producto es: %.2f\n", precio[index]);
		puts("Nacionalidad producto: ");
		ListarNacionProducto(nacion, index);
		puts("Tipo de producto: ");
		ListarTipoProducto(tipo, index);
	}
}

void ListarNacionProducto(int nacion[], int index)
{
	switch(nacion[index])
	{
	case 1:
		printf("EEUU\n");
		break;
	case 2:
		printf("CHINA\n");
		break;
	case 3:
		printf("OTRO\n");
		break;
	}
}

void ListarTipoProducto(int tipo[], int index)
{
	switch(tipo[index])
	{
	case 1:
		printf("IPHONE\n");
		break;
	case 2:
		printf("MAC\n");
		break;
	case 3:
		printf("IPAD\n");
		break;
	case 4:
		printf("ACCESORIOS\n");
		break;
	}
}

void OrdenarVectorPorPrecio(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int filas)
{
	char auxiliar[30];
	int auxId;
	int auxNacion;
	int auxTipo;
	float auxPrecio;

	for(int i = 0; i< filas - 1; i++)
	{
		for(int j = i+1; j< filas; j++)
		{
			if(precio[i] > precio[j])
			{
				strcpy(auxiliar, descripcion[i]);
				strcpy(descripcion[i], descripcion[j]);
				strcpy(descripcion[j], auxiliar);
				auxId = id[i];
				id[i] = id[j];
				id[j] = auxId;
				auxNacion = nacion[i];
				nacion[i] = nacion[j];
				nacion[j] = auxNacion;
				auxTipo = tipo[i];
				tipo[i] = tipo[j];
				tipo[j] = auxTipo;
				auxPrecio = precio[i];
				precio[i] = precio[j];
				precio[j] = auxPrecio;
			}
		}
	}
}

void OrdenarVectorPorDescripcion(int id[CANTIDAD], char descripcion[][TAM], int nacion[CANTIDAD], int tipo[CANTIDAD], float precio[CANTIDAD], int filas)
{
	char auxiliar[30];
	int auxId;
	int auxNacion;
	int auxTipo;
	float auxPrecio;

	for(int i = 0; i < filas - 1; i++)
	{
		for(int j = i + 1; j < filas; j++)
		{
			if(strcmp(descripcion[i], descripcion[j]) > 0)
			{
				strcpy(auxiliar, descripcion[i]);
				strcpy(descripcion[i], descripcion[j]);
				strcpy(descripcion[j], auxiliar);
				auxId = id[i];
				id[i] = id[j];
				id[j] = auxId;
				auxNacion = nacion[i];
				nacion[i] = nacion[j];
				nacion[j] = auxNacion;
				auxTipo = tipo[i];
				tipo[i] = tipo[j];
				tipo[j] = auxTipo;
				auxPrecio = precio[i];
				precio[i] = precio[j];
				precio[j] = auxPrecio;
			}
		}
	}
}
