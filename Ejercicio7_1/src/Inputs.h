/*
 * Inputs.h
 *
 *  Created on: 24 jul. 2022
 *      Author: gpnic
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define TRUE 0
#define FALSE -1

/// @fn 			int RequestInt(char[])
/// @brief		Pide al usuario el ingreso de un entero por medio de un mensaje recibido por parametro,
///						y valida que sea un entero.
/// @param 	mensaje Lo que se le mostrara al usuario a la hora de pedir el valor.
/// @return	el valor ingresado por el usuario validado y en formato int.
int RequestInt(char mensaje[]);

/// @fn 			int RequestIntInRange(char[], char[], int, int)
/// @brief		Usa la funcion RequestInt para obtener el entero validado y luego lo verifica en un rango determinado,
///						repitiendo el proceso siempre que no se cumple con le rango establecido.
/// @param mensaje	a mostrar al usuario, se le pasara a la funcion RequestInt.
/// @param mensajeError para mostrar si el numero esta fuera de rango
/// @param minimo valor menor del rango a verificar.
/// @param maximo valor mayor del rango a verificar.
/// @return el numero ingresado despues de pasar las validaciones en formato int.
int RequestIntInRange(char mensaje[], char mensajeError[], int minimo, int maximo);

/// @fn 			float RequestFloat(char[])
/// @brief		Pide al usuario el ingreso de un flotante por medio de un mensaje recibido por parametro,
///						y valida que sea un flotante o entero.
/// @param 	mensaje Lo que se le mostrara al usuario a la hora de pedir el valor.
/// @return	el valor ingresado por el usuario validado y en formato float.
float RequestFloat(char mensaje[]);

/// @fn 			float RequestFloatInRange(char[], char[], float, float)
/// @brief		Usa la funcion RequestFloat para obtener el entero validado y luego lo verifica en un rango determinado,
///						repitiendo el proceso siempre que no se cumple con le rango establecido.
/// @param 	mensaje a mostrar al usuario, se le pasara a la funcion RequestFloat..
/// @param 	mensajeError para mostrar si el numero esta fuera de rango
/// @param 	minimo valor menor del rango a verificar.
/// @param 	maximo valor mayor del rango a verificar.
/// @return	el numero ingresado despues de pasar las validaciones en formato float.
float RequestFloatInRange(char mensaje[], char mensajeError[], float minimo, float maximo);

/// @fn 			int ValidateFloatBiggerZero(char[])
/// @brief		Valida que el valor ingresado por el usuario sea un numero o un punto(solo permite uno) siempre y
/// 					cuando la longitud sea mayor a solo ese punto
///
/// @param cadena el valor en formato char para validar
/// @return	TRUE si pasa las validaciones, FALSE si no.
int ValidateFloatBiggerZero(char cadena[]);

/// @fn 			int ValidateInt(char[])
/// @brief		Valida que el valor sea un numero entero o negativo.
///
/// @param cadena el valor en formato char para validar.
/// @return	TRUE si pasa las validaciones, FALSE si no.
int ValidateInt(char cadena[]);

/// @fn 			void RequestString(char[], char[], int)
/// @brief		pide el ingreso de una cadena de caracteres
///
/// @param mensaje a mostrar al usuario
/// @param string variable a guardar
/// @param len tamaio permitido
void RequestString(char mensaje[], char string[], int len);

/// @fn 			int CorrectString(char[], int)
/// @brief		Corrije la cadena ingresada por el usurio
///
/// @param string ingreso del usuario
/// @param len largo de la cadena
/// @return TRUE ok / FALSE error
int CorrectString(char string[], int len);

/// @fn 			int ValidateString(char[])
/// @brief 		valida la cadena ingresada por el usuario
///
/// @param string cadena a validar
/// @return TRUE ok / FALSE error
int ValidateString(char string[]);

/// @fn 			void PolishString(char[])
/// @brief		Emprolija la cadena ingresada por el usuario poniendo todos los caracteres en minusculas
///						y las primeras letras en mayusculas.
/// @param cadena string a emprolijar
void PolishString(char cadena[]);

/// @fn 			void PolishFlyCode(char[])
/// @brief		Solo pone las letras en mayusculas para que queden como codigo de vuelo usado en clase.
///
/// @param cadena string a emprolijar.
void PolishFlyCode(char cadena[]);

/// @fn 			int CheckOnlyLetters(char[])
/// @brief 		Verifica que lo que haya en la cadena sean solo letras.
///
/// @param string para analizar.
/// @return TRUE si son solo letras, FALSE si no.
int CheckOnlyLetters(char string[]);


#endif /* INPUTS_H_ */
