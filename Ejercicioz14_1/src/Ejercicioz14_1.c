/*
 ============================================================================
 Name        : 		Ejercicioz14_1.c
 Author      : 		Gil Nicolas David
 Description : 	Agregar la estructura eFabricanteDePantalla (idFabricante y descripcion).
							Esta estructura se relaciona con el tipo de producto. Un fabricante puede producir pantallas para varios tipos, pero un tipo de producto solo tendrá un fabricante de pantalla.
							Solo se trabajará con los datos hardcodeados de la estructura fabricante.

								IdFabricante 			Descripcion
								1								Foxconn
								2								Sharp
								3								Japan Display Inc


 ============================================================================
 */

#include "Productos.h"

int main(void)
{
	setbuf(stdout, NULL);

	mainMenu();

	return EXIT_SUCCESS;
}
