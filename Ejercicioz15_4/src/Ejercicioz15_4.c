/*
 ============================================================================
 Name        : 	Ejercicioz15_4.c
 Author      : 	Gil Nicolas David
 Description : Refactorizar el TP2 para que trabaje con punteros.

 TP_Laboratorio_2

							1 Enunciado
							Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
							no puede tener más de 2000 pasajeros.

							Datos:

							El sistema deberá tener el siguiente menú de opciones:
							1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
								número de Id. El resto de los campos se le pedirá al usuario.
							2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
								o Precio o Tipo de pasajero o Código de vuelo
							3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
							4. INFORMAR:
								1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
								2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
								promedio.
								3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
							5. Carga Forzada Preferentemente con 5 pasajeros.
							1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
							Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
							carga de algún pasajero.
							2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	printf("=========================================================================================================================================\n"
			"\tB I E N V E N I D O S\n"
			"============================================================================================================================================");

	MainMenu();

	return EXIT_SUCCESS;
}
