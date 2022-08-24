/*
 * Productos.c
 *
 *  Created on: 20 may. 2022
 *      Author: Gil Nicolás David
 */

#include "Producto.h"

void MenuPrincipal(void)
{
	eProducto unProducto[LEN];
	eProducto mayores700[LEN];
	int opcionMain;
	int contadorIngresos = 0;
	int posicionLibre;
	int idBorrar;
	int seBorro;
	int idModificar;
	int ordenOK;
	int creadorID = 1000;

	IniciarArray(unProducto);
	IniciarArray(mayores700);
	do
	{
		opcionMain = MenuInteractivo();
		switch(opcionMain)
		{
		case 1:
			posicionLibre = BuscarEspacio(unProducto);
			if(posicionLibre != -1)
			{
				LlenarUnProducto(unProducto, posicionLibre, &creadorID);
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
			if(contadorIngresos > 0)
			{
				Informes(unProducto, mayores700);
			}else
			{
				printf("\nNo hay productos ingresados aun.\n");
			}
			break;
		case 8:
			printf("\nTodo esto se va a borrar, pero gracias por usar nuestro programa.\n");
			break;
		}
	}while(opcionMain != 8);

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
														"7 - INFORMES.\n"
														"8 - SALIR\n"
														"Ingrese una opcion: ", 1, 8);

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

void LlenarUnProducto(eProducto list[], int index, int* id)
{
	list[index].idProducto = *id;
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
					retorno = 0;
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
			}
		}
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

void Informes(eProducto list[], eProducto mayores[])
{
	eProducto madeChina[LEN];
	eProducto MacCaros[LEN];
	int opcionInformes;
	float mayorPrecio;
	int masSetecientos;
	float promedio1;
	float promedio2;
	float promedio3;
	float promedio4;
	float masBaratoIPHONE = -1;
	int huboUnChina;
	int huboUnMac;
	float accesorioMasCaro;

	IniciarArray(madeChina);
	IniciarArray(MacCaros);

	mayorPrecio = ProductoMasCaro(list);
	masSetecientos = MasSetecientos(list, mayores);
	promedio1 = PromedioPorTipo(list, 1);
	promedio2 = PromedioPorTipo(list, 2);
	promedio3 = PromedioPorTipo(list, 3);
	promedio4 = PromedioPorTipo(list, 4);
	masBaratoIPHONE = MasBaratoIphone(list);
	huboUnChina = MadeInChina(list, madeChina);
	huboUnMac = MacMasCaros(list, MacCaros);
	accesorioMasCaro = AccesoriosMasCaros(list);

	printf("=======================================================================================================\n"
				"BIENVENIDO A INFORMES\n"
			"=======================================================================================================\n");
	do
	{
		opcionInformes = MenuInformes();
		switch(opcionInformes)
		{
		case 1:
			printf("Los productos mas caros son:\n");
			PrintTitle();
			for(int i = 0; i < LEN; i++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].precioProducto == mayorPrecio)
				{
					PrintUnProducto(list[i]);
				}
			}
			break;
		case 2:
			if(masSetecientos != -1)
			{
				printf("Los productos que superan los 700 son: \n");
				PrintTodosProductos(mayores, LEN);
			}else
			{
				printf("No hubo productos que superen los 700.\n");
			}
			break;
		case 3:
			printf("Los promedios por tipo de productos son los siguientes:\n");
			if(promedio1 != -1)
			{
				printf("El promedio de los Iphone es: %.2f\n", promedio1);
			}else
			{
				printf("No se han ingresado productos Iphone.\n");
			}
			if(promedio2 != -1)
			{
				printf("El promedio de los Mac es: %.2f\n", promedio2);
			}else
			{
				printf("No se han ingresado productos Mac.\n");
			}
			if(promedio3 != -1)
			{
				printf("El promedio de los Ipad es: %.2f\n", promedio3);
			}else
			{
				printf("No se han ingresado productos Ipad.\n");
			}
			if(promedio4 != -1)
			{
				printf("El promedio de los accesorios es: %.2f\n", promedio4);
			}else
			{
				printf("No se han ingresado productos de accesorios.\n");
			}
			break;
		case 4:
			if(masBaratoIPHONE != -1)
			{
				printf("Los productos IPHONE mas baratos son: \n");
				PrintTitle();
				for(int i = 0; i < LEN; i++)
				{
					if(list[i].isEmpty == OCUPADO && list[i].precioProducto == masBaratoIPHONE)
					{
						PrintUnProducto(list[i]);
					}
				}
			}else
			{
				printf("No se ingreso ningun producto del tipo IPHONE. \n");
			}
			break;
		case 5:
			if(huboUnChina != -1)
			{
				printf("Los productos que provienen de China son: \n");
				PrintTodosProductos(madeChina, LEN);
			}else
			{
				printf("No se registraron productos provenientes de China.\n");
			}
			break;
		case 6:
			huboUnMac = MacMasCaros(list, MacCaros);
			if(huboUnMac != -1)
			{
				printf("Los productos Mac que superan los 700 son: \n");
				PrintTodosProductos(MacCaros, LEN);
			}else
			{
				printf("No se registraron productos Mac que superen los 700.\n");
			}
			break;
		case 7:
			if(accesorioMasCaro != -1)
			{
				printf("Los accesorios mas caros son:\n");
				PrintTitle();
				for(int i = 0; i < LEN; i++)
				{
					if(list[i].isEmpty == OCUPADO && list[i].tipoProducto == 4)
					{
						if(list[i].precioProducto == accesorioMasCaro)
						{
							PrintUnProducto(list[i]);
						}
					}
				}
			}else
			{
				printf("No se han ingresado accesorios.\n");
			}
			break;
		}
	}while(opcionInformes != 8);
}

int MenuInformes(void)
{
	int opcion;

	opcion = RequestIntInRange(	"Que desea saber.\n"
													"1 - El o los productos mas caros.\n"
													"2 - Los productos que cuestan mas de 700.\n"
													"3 - Precio promedio por tipo de producto.\n"
													"4 - El iphone mas barato.\n"
													"5 - Los productos procedientes de China.\n"
													"6 - Los productos MAC que cuestan mas de 700.\n"
													"7 - El o los accesorios mas caros.\n"
													"8 - Volver al menu principal.\n"
													"Ingrese una opcion: ", 1, 8);

	return opcion;
}

float AccesoriosMasCaros(eProducto list[])
{
	float precioMasCaro = -1;
	int flagPrimer = 0;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].tipoProducto == 4)
		{
			if(flagPrimer == 0 || list[i].precioProducto > precioMasCaro)
			{
				precioMasCaro = list[i].precioProducto;
				flagPrimer = 1;
			}
		}
	}

	return precioMasCaro;
}

int MacMasCaros(eProducto list[], eProducto macs[])
{
	int retorno = -1;
	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].tipoProducto == 2)
		{
			if(list[i].precioProducto > 700)
			{
				macs[i] = list[i];
				retorno = 1;
			}
		}
	}
	return retorno;
}

int MadeInChina(eProducto list[], eProducto made[])
{
	int retorno = -1;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].nacionalidadProducto == 2)
		{
			made[i] = list[i];
			retorno = 1;
		}
	}
	return retorno;
}

float MasBaratoIphone(eProducto list[])
{
	int flagPrimero = -1;
	float menorPrecio;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].tipoProducto == 1)
		{
			if(flagPrimero == -1 || list[i].precioProducto < menorPrecio)
			{
				menorPrecio = list[i].precioProducto;
				flagPrimero = 0;
			}
		}
	}
	return menorPrecio;
}


float ProductoMasCaro(eProducto list[])
{
	int flagPrimero = -1;
	float mayorPrecio;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].idProducto != 0 && list[i].isEmpty == OCUPADO)
		{
			if(flagPrimero == -1 || list[i].precioProducto > mayorPrecio)
			{
				mayorPrecio = list[i].precioProducto;
				flagPrimero = 0;
			}
		}
	}
	return mayorPrecio;
}

int MasSetecientos(eProducto list[], eProducto mayores700[])
{
	int retorno = -1;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].precioProducto > 700)
		{
			mayores700[i] = list[i];
			retorno = 1;
		}
	}

	return retorno;
}


float PromedioPorTipo(eProducto list[], int aux)
{
	float promedio = -1;
	int contadorIphone = 0;
	int contadorMac= 0;
	int contadorIpad= 0;
	int contadorAcces= 0;
	int acumuladorIphone= 0;
	int acumuladorMac= 0;
	int acumuladorIpad= 0;
	int acumuladorAcces= 0;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			switch(list[i].tipoProducto)
			{
			case 1:
				acumuladorIphone = acumuladorIphone + list[i].precioProducto;
				contadorIphone++;
				break;
			case 2:
				acumuladorMac = acumuladorMac + list[i].precioProducto;
				contadorMac++;
				break;
			case 3:
				acumuladorIpad = acumuladorIpad + list[i].precioProducto;
				contadorIpad++;
				break;
			case 4:
				acumuladorAcces = acumuladorAcces + list[i].precioProducto;
				contadorAcces++;
				break;
			}
		}
	}
	switch(aux)
	{
	case 1:
		if(contadorIphone != 0)
		{
			promedio = (float)acumuladorIphone / contadorIphone;
		}
		break;
	case 2:
		if(contadorMac != 0)
		{
			promedio = (float)acumuladorMac / contadorMac;
		}
		break;
	case 3:
		if(contadorIpad != 0)
		{
			promedio = (float)acumuladorIpad / contadorIpad;
		}
		break;
	case 4:
		if(contadorAcces != 0)
		{
			promedio = (float)acumuladorAcces / contadorAcces;
		}
		break;
	}
	return promedio;
}


