/*
 ============================================================================
 Name        : 		Ejercicio10_1.c
 Author      : 		Gil Nicolas David
 Description : 	Dada la estructura
							eAlumno (legajo, nombre, nota1, nota2, promedio),
							de qué manera la podría relacionar con la estructura
							eCurso (idCurso, descripcion, duracion), teniendo en cuenta que un alumno puede cursar solo un curso

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 10
#define SIZE 52

typedef struct
{
	int legajo;
	char nombre[SIZE];
	float nota1;
	float nota2;
	float promedio;
	int idCurso;//se agrega a cada alumno el id del curso unico que realiza
}eAlumno;

typedef struct
{
	int idCurso;
	char descripcion[SIZE];
	int duracion;
}eCurso;

//Puede haber muchos alumnos y muchos cursos pero sabmos que cada alumno solo tendra un curso.

