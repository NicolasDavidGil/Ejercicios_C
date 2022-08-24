/*
 * Inputs.h
 *
 *  Created on: 9 may. 2022
 *      Author: Gil Nicolás David
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define NUM "0123456789"

/// @fn 			int RequestInt(char[])
/// @brief 		Pide numero entero validandolo
///
/// @param mensaje Lo que se mostrara al usuario
/// @return lo que el usuario ingresa
int RequestInt(char mensaje[]);

/// @fn 			int RequestIntInRange(char[], int, int)
/// @brief 		invoca a RequestInt y valida ademas el numero en un rango especifico
///
/// @param mensaje lo que mostrar RequestInt
/// @param minimo del rango
/// @param maximo del rango
/// @return
int RequestIntInRange(char mensaje[], int minimo, int maximo);

/// @fn 			float RequestFloat(char[])
/// @brief		Pide numero entero validandolo que sea numeros
///
/// @param mensaje lo que mostrar al usuario
/// @return lo que el usuario ingresa
float RequestFloat(char mensaje[]);

/// @fn float RequestFloatInRange(char[], float, float)
/// @brief		invoca a RequestFloat y valida ademas el numero en un rango especifico
///
/// @param mensaje lo que mostrar RequestFloat
/// @param minimo del rango
/// @param maximo del rango
/// @return lo que el usuario ingresa
float RequestFloatInRange(char mensaje[], float minimo, float maximo);

/// @fn 			int ValidateNumber(char[])
/// @brief		valida que lo que se ingreso sean solo numeros
///
/// @param numero para validar
/// @return 1 ok / -1 error
int ValidateNumber(char numero[]);

/// @fn 			void RequestString(char[], char[], int)
/// @brief		pide el ingreso de una cadena de caracteres
///
/// @param mensaje a mostrar al usuario
/// @param string variable a guardar
/// @param len tamaño permitido
void RequestString(char mensaje[], char string[], int len);

/// @fn 			int CorrectString(char[], int)
/// @brief		Corrije la cadena ingresada por el usurio
///
/// @param string ingreso del usuario
/// @param len
/// @return 1 ok / -1 error
int CorrectString(char string[], int len);

/// @fn 			int ValidateString(char[])
/// @brief 		valida la cadena ingresada por el usuario
///
/// @param string
/// @return 1 ok / -1 error
int ValidateString(char string[]);

/// @fn 			void PolishString(char[])
/// @brief		Acomoda la cadena ingresada por el usuario
///
/// @param cadena
void PolishString(char cadena[]);

/// @fn 			void RequestAlphaDigit(char[], char[], int)
/// @brief 		pide el ingreso de una cadena tanto de letras como numeros
///
/// @param mensaje
/// @param cadena
/// @param len
void RequestAlphaDigit(char mensaje[], char cadena[], int len);


#endif /* INPUTS_H_ */
