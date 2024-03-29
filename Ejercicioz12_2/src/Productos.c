/*
 *		 	Productos.c
 *  		Created on: 333 Enero 4041
 *     	Author: Gil Nicolas David
 */


#include "Productos.h"

void mainMenu(void)
{
	eProducto unProducto[LEN];

	TipoProducto unTipo[TYPESYZE] = {	{1000, "IPHONE"},
																		{1001, "IPAD"},
																		{1002, "MAC"},
																		{1003, "ACCESORIOS"}};

	Nacionalidad unaNacionalidad[NATIONSIZE]  = {	{1, "EEUU"},
																							{2, "CHINA"},
																							{3, "OTRO"}	};

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
			if(newProduct(unProducto, unTipo, unaNacionalidad, lastID, -1) == 0)
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
				if(deleteProduct(unProducto, unTipo, unaNacionalidad) == 0)
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
				if(Modifyproduct(unProducto, unTipo, unaNacionalidad) == 0)
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
				PrintAllProducts(unProducto, unTipo, unaNacionalidad, LEN);
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
						PrintAllProducts(unProducto, unTipo, unaNacionalidad, LEN);
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
					PrintAllProducts(unProducto, unTipo, unaNacionalidad, LEN);
				}
			}else
			{
				puts("\nNo hay productos para sortear.\n");
			}
			break;
		case 7:
			if(count > 0)
			{
				if(SortByNation(unProducto, unaNacionalidad, LEN) == 0)
				{
					PrintAllProducts(unProducto, unTipo, unaNacionalidad, LEN);
				}
			}else
			{
				puts("\nNo hay productos para sortear.\n");
			}
			break;
		case 8:
			modificacionTipo(unProducto, unTipo, unaNacionalidad, lastID);
			break;
		case 9:
			modificacionNacionalidad(unProducto, unTipo, unaNacionalidad, lastID);
			break;
		case 10:
			if(count > 0)
			{
				Informes(unProducto, unTipo, unaNacionalidad);
			}else
			{
				puts("\nNo hay productos cargados.\n");
			}
			break;
		case 11:
			puts("\nTodo esto sera borrado, pero gracias por el momento.\n");
			break;
		}

	}while(choise != 11);

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
														"7 - LISTADO POR NACIONALIDAD\n"
														"8 - ALTA, BAJA Y MODIFICACION DE TIPO\n"
														"9 - ALTA, BAJA Y MODIFICACION DE NACIONALIDAD\n"
														"10 - INFORMES.\n"
														"11 - SALIR\n"
														"Ingrese una opcion: ", 1, 11);

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

int newProduct(eProducto list[], TipoProducto tipo[], Nacionalidad nacion[], int lastID, int aux)
{
	int retorno = -1;
	int n;

	n =findFreeSpace(list);

	if(n != -1)
	{
		list[n].idProducto = lastID;
		RequestString("\nIngrese nombre producto: ", list[n].descripcion, PRODUCTSIZE);
		if(aux == 1 || aux == 2 || aux == 3)
		{
			list[n].idNacionalidad = aux;
		}else
		{
			list[n].idNacionalidad = nacionalityMenu(nacion);
		}
		if(aux == 1 || aux == 2 || aux == 3 || aux == -1)
		{
			list[n].idTipo = typeMenu(tipo);
		}else
		{
			list[n].idTipo = aux;
		}
		list[n].precioProducto = RequestFloatInRange("\nIngrese precio producto: ", 1, INT_MAX);
		list[n].isEmpty =OCUPADO;
		retorno = 0;
	}else
	{
		puts("\nNo quedan lugares libres.\n");
	}
	return retorno;
}

int deleteProduct(eProducto list[], TipoProducto prod[], Nacionalidad nacion[])
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
		PrintOneProduct(list[n], prod, nacion);

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

int Modifyproduct(eProducto this[], TipoProducto prod[], Nacionalidad nacion[])
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

		PrintOneProduct(this[n], prod, nacion);

		choice = ModifyMenu();
		switch(choice)
		{
		case 1:
			RequestString("Ingrese la nueva descripcion del producto.", this[n].descripcion, PRODUCTSIZE);
			retorno = 0;
			break;
		case 2:
			this[n].idNacionalidad = nacionalityMenu(nacion);
			retorno = 0;
			break;
		case 3:
			this[n].idTipo = typeMenu(prod);
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

int SortByNation(eProducto list[], Nacionalidad nacion[], int len)
{
	int retorno = -1;
	eProducto auxiliar;
	char auxUno[PRODUCTSIZE];
	char auxDos[PRODUCTSIZE];

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len -1; i++)
		{
			for(int j = i+1; j < len; j++)
			{
				getNation(list[i], nacion, auxUno);
				getNation(list[j], nacion, auxDos);
				if(strcmpi(auxUno, auxDos) > 0
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

void getNation(eProducto list, Nacionalidad nacion[], char* aux)
{
	for(int i = 0; i < NATIONSIZE; i++)
	{
		if(list.idNacionalidad == nacion[i].idNacionalidad)
		{
			strcpy(aux, nacion[i].descripcionNacionalidad);
			break;
		}
	}
}

int nacionalityMenu(Nacionalidad list[])
{
	int opcion;
	puts("\nID NACION |  NACIONALIDAD\n");
	for(int i = 0; i < 3; i++)
	{
		printf("%3s %d \t|%10s\n"," ", list[i].idNacionalidad, list[i].descripcionNacionalidad);
	}
	opcion = RequestIntInRange("Ingrese la nacionalidad del producto: ", 1, 3);
	return opcion;
}

int typeMenu(TipoProducto list[])
{
	int opcion;
	puts("\nID TIPO | TIPO PRODUCTO\n");
	for(int i = 0; i < 4; i++)
	{
		printf("%3s %d \t|%10s\n"," ",  i+1, list[i].descripcion);
	}
	opcion = RequestIntInRange("Tipo de producto: ", 1, 4);
	opcion += 999;
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
																	,"TIPO PRODUCTO |\n"
	      "========================================================================================================================================\n");
}

void PrintOneProduct(eProducto list, TipoProducto prod[], Nacionalidad nacion[])
{
	printf("%d \t %3s| %10s %5s| %5s %.2f %2s|"	,list.idProducto
																						," "
																						,list.descripcion
																						," "
																						," "
																						,list.precioProducto
																						," ");
	PrintNacionality(list, nacion);
	printTypeProduct(list, prod);
	printf("\n");
}

int PrintAllProducts(eProducto list[], TipoProducto prod[], Nacionalidad nacion[], int length)
{
    if(length >= 0)
    {
    	PrintTitle();
    	 for(int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
            	PrintOneProduct(list[i], prod, nacion);
            }
        }

    }
    return 0;
}

void PrintNacionality(eProducto list, Nacionalidad this[])
{
	for(int i = 0; i < NATIONSIZE; i++)
	{
		if(list.idNacionalidad == this[i].idNacionalidad)
		{
			printf("%10s %3s|", this[i].descripcionNacionalidad, " ");
		}
	}
}

void printTypeProduct(eProducto list, TipoProducto prod[])
{
	for(int i = 0; i < TYPESYZE; i++)
	{
		if(list.idTipo == prod[i].idTipo)
		{
			printf("%4s %s |", " ", prod[i].descripcion);
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

void Informes(eProducto list[], TipoProducto prod[], Nacionalidad nacion[])
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
					PrintOneProduct(list[i], prod, nacion);
				}
			}
			break;
		case 2:
			if(masSetecientos != -1)
			{
				printf("\nLos productos que superan los 700 son: \n");
				PrintAllProducts(mayores700, prod, nacion, LEN);
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
						PrintOneProduct(list[i], prod, nacion);
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
				PrintAllProducts(madeChina, prod, nacion, LEN);
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
				PrintAllProducts(MacCaros, prod, nacion, LEN);
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
							PrintOneProduct(list[i], prod, nacion);
						}
					}
				}
			}else
			{
				printf("No se han ingresado accesorios.\n");
			}
			break;
		case 8:
			contadorImportanciones(list);
			break;
		case 9:
			soloIphone(list);
			break;
		case 10:
			nacionConMasProductos(list);
			break;
		case 11:
			PromedioPorNacion(list);
			break;
		}
	}while(opcionInformes != 12);
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
													"8 - Cantidad de productos importados por tipo. \n"
													"9 - La nacionalidad que solo fabrica Iphone.\n"
													"10 - La nacionalidad con m�s tipos de productos fabricados.\n"
													"11 - El precio promedio de productos por nacionalidad.\n"
													"12 - Volver al menu principal.\n"
													"Ingrese una opcion: ", 1, 12);

	return opcion;
}
/*La nacionalidad que solo fabrica Iphone.
							Los productos, ordenados por nacionalidad alfab�ticamente.
							La nacionalidad con m�s tipos de productos fabricados.
							El precio promedio de productos por nacionalidad
 *
 */

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
		if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == 2)
		{
			made[i] = list[i];
			retorno = 1;
		}
	}
	return retorno;
}

void soloIphone(eProducto list[])
{
	int chinaIphone = 0;
	int eeuuIphone = 0;
	int otrosIphone = 0;
	int eeuuNoIphone = 0;
	int chinaNoIphone = 0;
	int otrosNoIphone = 0;

	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == 1 && list[i].idTipo == 1000)
		{
			eeuuIphone = 1;
		}else if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == 1 && list[i].idTipo != 1000)
		{
			eeuuNoIphone = 1;
		}
		if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == 2 && list[i].idTipo == 1000)
		{
			chinaIphone = 1;
		}else if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == 2 && list[i].idTipo != 1000)
		{
			chinaNoIphone = 1;
		}
		if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == 3 && list[i].idTipo == 1000)
		{
			otrosIphone = 1;
		}else if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == 3 && list[i].idTipo != 1000)
		{
			otrosNoIphone = 1;
		}
	}

	if(chinaIphone == 1 && chinaNoIphone == 0)
	{
		puts("China tiene cargados solo productos Iphone.\n");
	}else if(chinaIphone == 1 && chinaNoIphone == 1)
	{
		puts("China tiene cargados mas productos ademas de Iphone.\n");
	}else
	{
		puts("China no tiene cargados productos Iphone.\n");
	}

	if(eeuuIphone == 1 && eeuuNoIphone == 0)
	{
		puts("EEUU tiene cargados solo productos Iphone.\n");
	}else if(eeuuIphone == 1 && eeuuNoIphone == 1)
	{
		puts("EEUU tiene cargados mas productos ademas de Iphone.\n");
	}else
	{
		puts("EEUU no tiene cargados productos Iphone.\n");
	}

	if(otrosIphone == 1 && otrosNoIphone == 0)
	{
		puts("Otros paises tienen cargados solo productos Iphone.\n");
	}else if(otrosIphone == 1 && otrosNoIphone == 1)
	{
		puts("Otros paises tienen cargados mas productos ademas de Iphone.\n");
	}else
	{
		puts("Otros paises no tienen cargados productos Iphone.\n");
	}
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

void PromedioPorNacion(eProducto list[])
{
	float promedioEEUU;
	float promedioCHINA;
	float promedioOTROS;
	int contadorEEUU = 0;
	int contadorCHINA = 0;
	int contadorOTROS = 0;
	int acumuladorEEUU = 0;
	int acumuladorCHINA = 0;
	int acumuladorOTROS = 0;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			switch(list[i].idNacionalidad)
			{
			case 1:
				acumuladorEEUU = acumuladorEEUU + list[i].precioProducto;
				contadorEEUU++;
				break;
			case 2:
				acumuladorCHINA = acumuladorCHINA + list[i].precioProducto;
				contadorCHINA++;
				break;
			case 3:
				acumuladorOTROS = acumuladorOTROS + list[i].precioProducto;
				contadorOTROS++;
				break;
			}
		}
	}
	if(contadorEEUU > 0)
	{
		promedioEEUU = (float)acumuladorEEUU / contadorEEUU;
		printf("\nEl promedio de los productos de EEUU es: %.2f\n", promedioEEUU);
	}else
	{
		puts("\nNo hay productos de EEUU.\n");
	}
	if(contadorCHINA > 0)
	{
		promedioCHINA = (float)acumuladorCHINA / contadorCHINA;
		printf("\nEl promedio de los productos de China es: %.2f\n", promedioCHINA);
	}else
	{
		puts("\nNo hay productos de China.\n");
	}
	if(contadorOTROS > 0)
	{
		promedioOTROS = (float)acumuladorOTROS / contadorOTROS;
		printf("\nEl promedio de los productos de Otros paises es: %.2f\n", promedioOTROS);
	}else
	{
		puts("\nNo hay productos de otros paises.\n");
	}
}

void contadorImportanciones(eProducto list[])
{
	int contadorIphone = 0;
	int contadorIpad = 0;
	int contadorMac = 0;
	int contadorAcces = 0;

	for(int i = 0; i < LEN; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			switch(list[i].idTipo)
			{
			case 1000:
				contadorIphone++;
				break;
			case 1001:
				contadorIpad++;
				break;
			case 1002:
				contadorMac++;
				break;
			case 1003:
				contadorAcces++;
				break;
			}
		}
	}
	puts("\nLa cantidad de productos importados es: \n ");
	printf("Iphone: %d\n", contadorIphone);
	printf("Ipad: %d\n", contadorIpad);
	printf("MAC: %d\n", contadorMac);
	printf("Acces: %d\n", contadorAcces);

}

void nacionConMasProductos(eProducto list[])
{
	int contadorEEUU;
	int contadorChina;
	int contadorOtros;

	contadorEEUU = contadorNacionalidadPorTipo(list, 1);
	contadorChina = contadorNacionalidadPorTipo(list, 2);
	contadorOtros = contadorNacionalidadPorTipo(list, 3);

	if(contadorEEUU > contadorChina && contadorEEUU > contadorOtros)
	{
		puts("\nEEUU tiene la mayor cantidad de productos importados.\n");
	}else if(contadorChina > contadorOtros)
	{
		puts("\nChina tiene la mayor cantidad de productos importados.\n");
	}else
	{
		puts("\nOtros paises tiene la mayor cantidad de productos importados.\n");
	}

}

int contadorNacionalidadPorTipo(eProducto list[], int aux)
{
	int contador = 0;
	int flagIphone = 0;
	int flagIpad = 0;
	int flagMac = 0;
	int flagAcces = 0;


	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == aux)
		{
			if(flagIphone == 0 && list[i].idTipo == 1000)
			{
				contador ++;
				flagIphone = 1;
			}
			if(flagIpad == 0 && list[i].idTipo == 1001)
			{
				contador ++;
				flagIpad = 1;
			}
			if(flagMac == 0 && list[i].idTipo == 1002)
			{
				contador ++;
				flagMac = 1;
			}
			if(flagAcces == 0 && list[i].idTipo == 1003)
			{
				contador ++;
				flagAcces = 1;
			}
		}
	}

	return contador;
}

void modificacionTipo(eProducto list[], TipoProducto prod[], Nacionalidad nacion[], int lastID)
{
	int opcion;
	int choice;
	int opcionBorrar;

	opcion = typeMenu(prod);

	do
	{
		puts("Que desea hacer: \n"
				"1- Alta producto con este tipo.\n"
				"2 - Modificar un producto de este tipo.\n"
				"3 - Dar de baja los productos con este tipo.\n"
				"4 - Volver al menu principal.\n");
		choice = RequestIntInRange("Opcion: ", 1, 4);

		switch(choice)
		{
		case 1:
			newProduct(list, prod, nacion, lastID, opcion);
			break;
		case 2:
			productoPorTipo(list, prod, nacion, opcion);
			break;
		case 3:
			puts("Estas seguro, se borraran todos los productos de este tipo"
					"1 - Para confirmar.\n"
					"Cualquier otro numero para cancelar.\n");
			opcionBorrar = RequestIntInRange("Opcion: ", 1, INT_MAX);
			if(opcionBorrar == 1)
			{
				borrarPorTipo(list, opcion);
			}else
			{
				puts("\nEliminacion cancelada.\n");
			}
			break;
		}
	}while(choice != 4);
}

void borrarPorTipo(eProducto list[], int aux)
{
	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idTipo == aux)
		{
			list[i].isEmpty = BORRADO;
		}
	}
}

void productoPorTipo(eProducto list[], TipoProducto prod[], Nacionalidad nacion[], int aux)
{
	int opcion;
	int opcionModificacion = 0;

	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idTipo == aux)
		{
			PrintOneProduct(list[i], prod, nacion);
		}
	}

	opcion = RequestIntInRange("Ingrese el id del producto a modificar: ", 1, INT_MAX);

	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idProducto == opcion)
		{
			do
			{
				opcionModificacion = menuModificarTipo();
				switch(opcionModificacion)
				{
				case 1:
					RequestString("Ingrese el nuevo nombre: ", list[i].descripcion, LEN);
					break;
				case 2:
					list[i].idNacionalidad = nacionalityMenu(nacion);
					break;
				case 3:
					list[i].precioProducto = RequestFloatInRange("Ingrese el nuevo precio: ", 0, INT_MAX);
					break;
				}
			}while(opcionModificacion != 4);
			break;
		}
	}

}

int menuModificarTipo(void)
{
	int opcion;

	puts("Que desea modificar\n"
			"1- Modificar nombre.\n"
			"2 - Modificar nacionalidad.\n"
			"3 - Modificar precio.\n"
			"4 - Volver sin modificar.\n");
	opcion = RequestIntInRange("Opcion; ", 1, 4);

	return opcion;
}

void modificacionNacionalidad(eProducto list[], TipoProducto prod[], Nacionalidad nacion[], int lastID)
{
	int opcion;
	int choice;
	int opcionBorrar;

	opcion = nacionalityMenu(nacion);

	do
	{
		puts("Que desea hacer: \n"
				"1- Alta producto con esta nacionalidad.\n"
				"2 - Modificar un producto de esta nacionalidad.\n"
				"3 - Dar de baja los productos con esta nacionalidad.\n"
				"4 - Volver al menu principal.\n");
		choice = RequestIntInRange("Opcion: ", 1, 4);

		switch(choice)
		{
		case 1:
			newProduct(list, prod, nacion, lastID, opcion);
			break;
		case 2:
			productoPorTipo(list, prod, nacion, opcion);
			break;
		case 3:
			puts("Estas seguro, se borraran todos los productos de este tipo"
					"1 - Para confirmar.\n"
					"Cualquier otro numero para cancelar.\n");
			opcionBorrar = RequestIntInRange("Opcion: ", 1, INT_MAX);
			if(opcionBorrar == 1)
			{
				borrarPorNacion(list, opcion);
			}else
			{
				puts("\nEliminacion cancelada.\n");
			}
			break;
		}
	}while(choice != 4);
}

void productoPorNacionalidad(eProducto list[], TipoProducto prod[], Nacionalidad nacion[], int aux)
{
	int opcion;
	int opcionModificacion = 0;

	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == aux)
		{
			PrintOneProduct(list[i], prod, nacion);
		}
	}

	opcion = RequestIntInRange("Ingrese el id del producto a modificar: ", 1, INT_MAX);

	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idProducto == opcion)
		{
			do
			{
				opcionModificacion = menuModificarNacion();
				switch(opcionModificacion)
				{
				case 1:
					RequestString("Ingrese el nuevo nombre: ", list[i].descripcion, LEN);
					break;
				case 2:
					list[i].idTipo = typeMenu(prod);
					break;
				case 3:
					list[i].precioProducto = RequestFloatInRange("Ingrese el nuevo precio: ", 0, INT_MAX);
					break;
				}
			}while(opcionModificacion != 4);
			break;
		}
	}
}


int menuModificarNacion(void)
{
	int opcion;

	puts("Que desea modificar\n"
			"1- Modificar nombre.\n"
			"2 - Modificar tipo.\n"
			"3 - Modificar precio.\n"
			"4 - Volver sin modificar.\n");
	opcion = RequestIntInRange("Opcion; ", 1, 4);

	return opcion;
}

void borrarPorNacion(eProducto list[], int aux)
{
	for(int i = 0; i < PRODUCTSIZE; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idNacionalidad == aux)
		{
			list[i].isEmpty = BORRADO;
		}
	}
}
