/*
 * Productos.c
 *
 *  Created on: 20 may. 2022
 *      Author: Gil Nicolás David
 */
#include "Productos.h"

void MenuPrincipal(void)
{
	eProducto unProducto[LEN];
	int opcionMain;
	int contadorIngresos = 0;
	int posicionLibre;
	int idBorrar;
	int seBorro;
	int idModificar;
	int ordenOK;
	int creadorID = 1000;

	IniciarArray(unProducto);
	do
	{
		opcionMain = MenuInteractivo();
		switch(opcionMain)
		{
		case 1:
			posicionLibre = BuscarEspacio(unProducto);
			if(posicionLibre != -1)
			{
				unProducto[posicionLibre].idProducto = creadorID;
				LlenarUnProducto(unProducto, posicionLibre);
				contadorIngresos++;
				creadorID++;
			}else
			{
				printf("\nNo queda espacio libre para cargar\n");
			}
			break;
		case 2:
			if(contadorIngresos > 0)
			{
				PrintID(unProducto);
				idBorrar = RequestIntInRange("\nIngrese el id a borrar: ", 1000, 1020);
				seBorro = BajaProducto(unProducto, idBorrar);
				if(seBorro != -1)
				{
					printf("\nProducto eliminado.\n");
					contadorIngresos--;
				}else
				{
					printf("Error en la eliminacion del producto.\n");
				}
			}else
			{
				printf("\nNo hay productos cargados para dar de baja.\n");
			}
				break;
		case 3:
			if(contadorIngresos > 0)
			{
				PrintID(unProducto);
				idModificar = RequestIntInRange("\nIngrese el id a borrar: ", 1000, 1020);
				ModificarProducto(unProducto, idModificar);
			}else
			{
				printf("\nNo hay productos cargados para modificar.\n");
			}
			break;
		case 4:
			if(contadorIngresos > 0)
			{
				PrintTodosProductos(unProducto, LEN);
			}else
			{
				printf("\nNo hay productos cargados para mostrar.\n");
			}
			break;
		case 5:
			if(contadorIngresos > 0)
			{
				ordenOK = OrdenarPorPrecio(unProducto, LEN);
				if(ordenOK != -1)
				{
					PrintTodosProductos(unProducto, LEN);
				}
			}else
			{
				printf("\nNo hay productos cargados para mostrar.\n");
			}
			break;
		case 6:
			if(contadorIngresos > 0)
			{
				ordenOK = OrdenarPorDescripcion(unProducto, LEN);
				if(ordenOK != -1)
				{
					PrintTodosProductos(unProducto, LEN);
				}
			}else
			{
				printf("\nNo hay productos cargados para mostrar.\n");
			}
			break;
		case 7:
			printf("\nTodo esto se va a borrar, pero gracias por usar nuestro programa.\n");
			break;
		}
	}while(opcionMain != 7);

}

int MenuInteractivo(void)
{
	int opcion;

	opcion = RequestIntInRange("1 - ALTA PRODUCTO\n"
														"2 - BAJA PRODUCTO\n"
														"3 - MODIFICACION PRODUCTO\n"
														"4 - LISTADO PRODUCTOS\n"
														"5 - LISTADO POR PRECIO\n"
														"6 - LISTADO POR DESCRIPCION\n"
														"7 - SALIR\n"
														"Ingrese una opcion: ", 1, 7);

	return opcion;
}

void IniciarArray(eProducto list[])
{
	for(int i = 0; i < LEN; i++)
	{
		list[i].isEmpty = LIBRE;
	}
}

int BuscarEspacio(eProducto list[])
{
	int index = -1;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}

void LlenarUnProducto(eProducto list[], int index)
{
	RequestString("\nIngrese descripcion del producto: ", list[index].descripcion, SIZE);
	list[index].nacionalidadProducto = MenuNacionalidad();
	list[index].tipoProducto = MenuTipoProducto();
	list[index].precioProducto = RequestFloatInRange("Ingrese precio del producto: ", 1, 1000000);
	list[index].isEmpty = OCUPADO;
}

int MenuNacionalidad(void)
{
	int opcion;

	opcion = RequestIntInRange("\nIngrese nacionalidad del producto.\n"
														"1 - PARA EEUU\n"
														"2 - PARA CHINA\n"
														"3 - PARA OTRO\n"
														"Nacionalidad: ", 1, 3);
	return opcion;
}

int MenuTipoProducto(void)
{
	int opcion;

	opcion = RequestIntInRange("\nIngrese tipo de producto.\n"
														"1 - PARA IPHONE\n"
														"2 - PARA MAC\n"
														"3 - PARA IPAD\n"
														"4 - PARA ACCESORIOS\n"
														"Tipo de producto: ", 1, 4);
	return opcion;
}

void PrintID(eProducto* list)
{
	printf("\nID disponibles: \n");

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("%d \n", list[i].idProducto);
		}
	}

}

int EncontrarPorID(eProducto* list, int id)
{
	int index = -1;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].idProducto == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int BajaProducto(eProducto* list, int id)
{
	int index;
	int retorno = -1;

	index = EncontrarPorID(list, id);

	if(index != -1)
	{
		list[index].isEmpty = LIBRE;
		list[index].idProducto = 0;
		retorno = 1;
	}else
	{
		printf("\nEse id no pertenece a ningun producto.\n");
	}
	return retorno;
}

void ModificarProducto(eProducto* list, int id)
{
	int index;
	int opcion;

	index = EncontrarPorID(list, id);

	if(index != -1)
	{
		opcion = RequestIntInRange("\nQue desea modificar\n"
															"1 - Para modificar precio.\n"
															"2 - Para modificar tipo.\n"
															"Opcion: ", 1, 2);
		if(opcion == 1)
		{
			list[index].precioProducto = RequestFloatInRange("Ingrese el nuevo precio del producto: ", 1, 1000000);
			printf("\nProducto Modificado.\n");
		}else
		{
			list[index].tipoProducto = MenuTipoProducto();
			printf("\nProducto Modificado.\n");
		}
	}
}

void PrintTipoProducto(eProducto list)
{
	switch(list.tipoProducto)
	{
	case 1:
		printf("\t%10s","IPHONE");
		break;
	case 2:
		printf("\t%10s","MAC");
		break;
	case 3:
		printf("\t%10s","IPAD");
		break;
	case 4:
		printf("\t%10s","ACCESORIO");
		break;
	}
}

void PrintNacionalidadProducto(eProducto list)
{
	switch(list.nacionalidadProducto)
	{
	case 1:
		printf("\t\t%10s","EEUU");
		break;
	case 2:
		printf("\t\t%10s","CHINA");
		break;
	case 3:
		printf("\t\t%10s","OTRO");
		break;
	}
}

void PrintUnProducto(eProducto list)
{
	printf("%d \t%10s\t \t%.2f"	,list.idProducto
														,list.descripcion
														,list.precioProducto);
	PrintNacionalidadProducto(list);
	PrintTipoProducto(list);
	printf("\n");
}

int PrintTodosProductos(eProducto* list, int length)
{
    if(list != NULL && length >= 0)
    {
    	PrintTitle();
    	 for(int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
            	PrintUnProducto(list[i]);
            }
        }

    }
    return 0;
}

void PrintTitle(void)
{
    printf("========================================================================================================================================\n"
    			"%10s %10s %10s %10s %10s " ,"ID PRODUCTO |"
																	,"NOMBRE PRODUCTO |"
																	,"PRECIO PRODUCTO |"
																	,"NACIONALIDAD |"
																	,"TIPO PRODUCTO \n"
	      "========================================================================================================================================\n");
}

int OrdenarPorPrecio(eProducto list[], int len)
{
	int retorno = -1;
	eProducto auxiliar;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len -1; i++)
		{
			for(int j = i+1; j < len; j++)
			{
				if(list[i].precioProducto < list[j].precioProducto
					&& list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
			}
		}
		retorno = 1; //solo por si hubo algun error
	}
	return retorno;
}

int OrdenarPorDescripcion(eProducto list[], int len)
{
	int retorno = -1;
	eProducto auxiliar;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len -1; i++)
		{
			for(int j = i+1; j < len; j++)
			{
				if(strcmpi(list[i].descripcion, list[j].descripcion) > 0
						&& list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
			}
		}
		retorno = 1; //solo por si hubo algun error
	}
	return retorno;
}







