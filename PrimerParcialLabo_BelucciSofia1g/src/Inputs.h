/*
 * Inputs.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int getIntMenu(char mensaje[]);
int myGets(char *cadena, int longitud);
int esNumerica(char *cadena);
int getInt(int *pResultado);
int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
int getFloat(float *pResultado);
int isValidFloat(char *pBuffer, int limite);
int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getChar(char *pChar, char *mensaje, char *mensajeError,
		int reintentos);
int getString(char *pBuffer, int limite);
int isValidNombre(char *pBuffer, int limite);
int utn_getNombre(  char *pNombre, int limite, char *mensaje,
                    char *mensajeError, int reintentos);


#endif /* INPUTS_H_ */
