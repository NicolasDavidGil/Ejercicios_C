/*
 ============================================================================
 Name        : 		Ejercicioz10_2.c
 Author      : 		Gil Nicolas David
 Description : 	Crear las siguientes estructuras en c, y definir la manera más óptima de relacionarlas.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 	1	- Producto-Proveedor (Donde el producto solo puede tener un único proveedor)

												Producto(1,1)								Proveedor(1,n)
												idProducto (int)						idProveedor(int)
												descripcion(string)					razonSocial(string)
												precio(float)								direccion(eDireccion)
												idProveedore
 *
 */
typedef struct
{
	char domicilio[50];
	char localidad[50];
	char ciudad[50];
	int telefono;
}eDireccion;

typedef struct
{
	int idProveedor;
	char razonSocial[50];
	eDireccion;
}Proveedor;

typedef struct
{
	int idProducto;
	char descripcionProducto[50];
	float precio;
	int idProveedor;
}Producto;



// 2 - Dueño-Mascota (Donde la mascota solo puede tener un único dueño)
/*
 *
Dueño																	Mascota
idDueño(int)													idMascota(int)
nombre(string)														nombre(string)
edad (int)																raza(eRaza)
sexo(char)																sexo(char)
 *
 */

typedef struct
{
	int idDuenio;
	char nombre[50];
	int edad;
	char sexoDuenio; // f , m
}Duenio;

typedef struct
{
	char raza[50];
	char observaciones[50];
}Raza;

typedef struct
{
	int idMascota;
	char nombreMascota[50];
	Raza;
	char sexoMascota;
	int idDuenio;
}Mascota;


/*
 * 3  - Alumno-Localidad (Donde un alumno solo vive en una localidad)
 *
Alumno												Localidad
idAlumno(int)									idLocalida(int)
nombre(string)									descripcion(string)
idLocalidad										codigoPostal(int)
 *
 */

typedef struct
{
	int idLocalidad;
	char descripcion[50];
	int codigoPostal;
}Localidad;

typedef struct
{
	int idAlumno;
	char nombre[50];
	int idLocalidad;
}Alumno;

int main(void)
{
	return 0;
}
