/*
 *		 	Productos.c
 *  		Created on: 333 Enero 4041
 *     	Author: Gil Nicolas David
 */


#include "Productos.h"

void mainMenu(void)
{
	eProducto unProducto[LEN];
	TipoProducto unTipo[4] = {	{1000, "IPHONE"},
														{1001, "IPad"},
														{1002, "mac"},
														{1003, "Accesorios"}};
	int choise;
	int lastID =  1000;
	int count = 0;

	startStruct(unProducto);

	do
	{
		choise = InteractiveMenu();
		switch(choise)
		{
		case 1:
			if(newProduct(unProducto, unTipo, lastID) == 0)
			{
				puts("\nProducto cargado correctamente.\n");
				lastID++;
				count ++;
			}else
			{
				puts("\nError en la carga del producto.\n");
			}
			break;
		case 2:
			if(count > 0)
			{
				if(deleteProduct(unProducto, unTipo) == 0)
				{
					puts("\nProducto eliminado.\n");
					count --;
				}
			}else
			{
				puts("\nNo hay productos cargados para eliminar.\n");
			}
			break;
		case 3:
			if(count > 0)
			{
				if(Modifyproduct(unProducto, unTipo) == 0)
				{
					puts("\nProducto modificado.\n");
				}else
				{
					puts("\nModificacion cancelada.\n");
				}
			}else
			{
				puts("\nNo hay productos cargados para modificar.\n");
			}
			break;
		case 4:
			if(count > 0)
			{
				PrintAllProducts(unProducto, unTipo, LEN);
			}else
			{
				puts("\nNo hay productos para listar.\n");
			}
			break;
		case 5:
			if(count > 0)
			{
				if(SortByPrice(unProducto, LEN) == 0)
				{
						PrintAllProducts(unProducto, unTipo, LEN);
				}
			}else
			{
				puts("\nNo hay productos cargados.\n");
			}
			break;
		case 6:
			if(count > 0)
			{
				if(SortByName(unProducto, LEN) == 0)
				{
					PrintAllProducts(unProducto, unTipo, LEN);
				}
			}else
			{
				puts("\nNo hay productos para sortear.\n");
			}
			break;
		case 7:
			if(count > 0)
			{
				Informes(unProducto, unTipo);
			}else
			{
				puts("\nNo hay productos cargados.\n");
			}
			break;
		case 8:
			puts("\nTodo esto sera borrado, pero gracias por el momento.\n");
			break;
		}

	}while(choise != 8);

}

int InteractiveMenu(void)
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

void startStruct(eProducto list[])
{
	for(int i = 0; i < LEN; i++)
	{
		list[i].isEmpty = LIBRE;
	}
}

int findFreeSpace(eProducto list[])
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

int newProduct(eProducto list[], TipoProducto tipo[], int lastID)
{
	int retorno = -1;
	int n;

	n =findFreeSpace(list);

	if(n != -1)
	{
		list[n].idProducto = lastID;
		RequestString("\nIngrese nombre producto: ", list[n].descripcion, SIZE);
		list[n].nacionalidadProducto = nacionalityMenu();
		list[n].idTipo = typeMenu();
		list[n].idTipo += 999;
		list[n].precioProducto = RequestFloatInRange("\nIngrese precio producto: ", 1, INT_MAX);
		list[n].isEmpty =OCUPADO;
		retorno = 0;
	}else
	{
		puts("\nNo quedan lugares libres.\n");
	}
	return retorno;
}

int deleteProduct(eProducto list[], TipoProducto prod[])
{
	int retorno = -1;
	int idToDelete;
	int n;
	int confirm;

	PrintUsedID(list);

	idToDelete = RequestIntInRange("Ingrese el id del producto a borrar: ", 1, INT_MAX);

	n = findByID(list, idToDelete);

	if(n != -1)
	{
		puts("Producto encontrado.");
		PrintOneProduct(list[n], prod);

		printf("Confirma eliminacion."
					"1 - Para eliminar."
					"Cualquier otra tecla cancelar");
		confirm = RequestIntInRange("Que desea hacer: ", 1, INT_MAX);
		if(confirm == 1)
		{
			list[n].isEmpty = BORRADO;
			retorno = 0;
		}else
		{
			puts("Eliminacion cancelada.");
		}
	}
	return retorno;
}

int Modifyproduct(eProducto this[], TipoProducto prod[])
{
	int retorno = -1;
	int choice;
	int idChoice;
	int n;

	PrintUsedID(this);

	idChoice = RequestIntInRange("Ingrese el id del producto a modificar: ", 1, INT_MAX);

	n = findByID(this, idChoice);

	if(n != -1)
	{
		puts("Producto encontrado.");

		PrintOneProduct(this[n], prod);

		choice = ModifyMenu();
		switch(choice)
		{
		case 1:
			RequestString("Ingrese la nueva descripcion del producto.", this[n].descripcion, SIZE);
			retorno = 0;
			break;
		case 2:
			this[n].nacionalidadProducto = nacionalityMenu();
			retorno = 0;
			break;
		case 3:
			this[n].idTipo = typeMenu();
			retorno = 0;
			break;
		case 4:
			this[n].precioProducto = RequestFloatInRange("Ingrese el nuevo precio del producto: ", 1, INT_MAX);
			retorno = 0;
			break;
		}
	}else
	{
		puts("No se encontro producto para ese id.");
	}

	return retorno;
}

int ModifyMenu(void)
{
	int choice;

	printf("Modificacion: "
				"1 - Para modificar descripcion del producto."
				"2 - Para modificar nacionalidad del producto."
				"3 - Para modificar el tipo del producto."
				"4 - Para modificar precio del producto.");
	choice = RequestIntInRange("Ingrese una opcion: ", 1, 4);
	return choice;
}

int SortByPrice(eProducto list[], int len)
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

int SortByName(eProducto list[], int len)
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

int nacionalityMenu(void)
{
	int opcion;

	opcion = RequestIntInRange("\nIngrese nacionalidad del producto.\n"
														"1 - PARA EEUU\n"
														"2 - PARA CHINA\n"
														"3 - PARA OTRO\n"
														"Nacionalidad: ", 1, 3);
	return opcion;
}

int typeMenu(void)
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

void PrintUsedID(eProducto* list)
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

int findByID(eProducto* list, int id)
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

void PrintTitle(void)
{
    printf("\n========================================================================================================================================\n"
    			"%10s %10s %10s %10s %10s " ,"ID PRODUCTO |"
																	,"NOMBRE PRODUCTO |"
																	,"PRECIO PRODUCTO |"
																	,"NACIONALIDAD |"
																	,"TIPO PRODUCTO \n"
	      "========================================================================================================================================\n");
}

void PrintOneProduct(eProducto list, TipoProducto prod[])
{
	printf("%d \t%10s\t \t%.2f"	,list.idProducto
														,list.descripcion
														,list.precioProducto);
	PrintNacionality(list);
	printf("%8s", "     ");
	printTypeProduct(list, prod);
	printf("\n");
}

int PrintAllProducts(eProducto list[], TipoProducto prod[], int length)
{
    if(length >= 0)
    {
    	PrintTitle();
    	 for(int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
            	PrintOneProduct(list[i], prod);
            }
        }

    }
    return 0;
}

void PrintNacionality(eProducto list)
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

void printTypeProduct(eProducto list, TipoProducto prod[])
{
	for(int i = 0; i < 4; i++)
	{
		if(list.idTipo == prod[i].idTipo)
		{
			printf("%s", prod[i].descripcion);
		}
	}
}

void InitArray(eProducto list[])
{
	for(int i = 0; i < LEN; i++)
	{
		list[i].isEmpty = LIBRE;
	}
}

void Informes(eProducto list[], TipoProducto prod[])
{
	eProducto mayores700[LEN];
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

	InitArray(madeChina);
	InitArray(MacCaros);
	InitArray(mayores700);

	mayorPrecio = ProductoMasCaro(list);
	masSetecientos = MasSetecientos(list, mayores700);
	promedio1 = PromedioPorTipo(list, 1);
	promedio2 = PromedioPorTipo(list, 2);
	promedio3 = PromedioPorTipo(list, 3);
	promedio4 = PromedioPorTipo(list, 4);
	masBaratoIPHONE = MasBaratoIphone(list);
	huboUnChina = MadeInChina(list, madeChina);
	huboUnMac = MacMasCaros(list, MacCaros);
	accesorioMasCaro = AccesoriosMasCaros(list);

	printf("\n=======================================================================================================\n"
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
					PrintOneProduct(list[i], prod);
				}
			}
			break;
		case 2:
			if(masSetecientos != -1)
			{
				printf("\nLos productos que superan los 700 son: \n");
				PrintAllProducts(mayores700, prod, LEN);
			}else
			{
				printf("\nNo hubo productos que superen los 700.\n");
			}
			break;
		case 3:
			printf("\nLos promedios por tipo de productos son los siguientes:\n");
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
				printf("\nLos productos IPHONE mas baratos son: \n");
				PrintTitle();
				for(int i = 0; i < LEN; i++)
				{
					if(list[i].isEmpty == OCUPADO && list[i].precioProducto == masBaratoIPHONE)
					{
						PrintOneProduct(list[i], prod);
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
				PrintAllProducts(madeChina, prod, LEN);
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
				PrintAllProducts(MacCaros, prod, LEN);
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
					if(list[i].isEmpty == OCUPADO && list[i].idTipo == 1003)
					{
						if(list[i].precioProducto == accesorioMasCaro)
						{
							PrintOneProduct(list[i], prod);
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
		if(list[i].isEmpty == OCUPADO && list[i].idTipo == 1003)
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
		if(list[i].isEmpty == OCUPADO && list[i].idTipo == 1002)
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
		if(list[i].isEmpty == OCUPADO && list[i].idTipo == 1000)
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
			switch(list[i].idTipo)
			{
			case 1000:
				acumuladorIphone = acumuladorIphone + list[i].precioProducto;
				contadorIphone++;
				break;
			case 1001:
				acumuladorIpad = acumuladorIpad + list[i].precioProducto;
				contadorIpad++;
				break;
			case 1002:
				acumuladorMac = acumuladorMac + list[i].precioProducto;
				contadorMac++;
				break;
			case 1003:
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
