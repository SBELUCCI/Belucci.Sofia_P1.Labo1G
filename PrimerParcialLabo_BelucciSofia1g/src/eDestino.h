/*
 * eDestino.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef EDESTINO_H_
#define EDESTINO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"

typedef struct {

	int id;
	char descripcionDestino[25];
	float precio;




}eDestino;


/// @brief Se encarga de mostrar un solo destino.
///
/// @param destino se le asigna una variable destino de tipo eDestino.
void mostrarUnDestino(eDestino destino);

/// @brief Se encarga de mostrar todos los destinos que ingresa el usuario a traves del ID.
///
/// @param destinos recibe un array de destinos
/// @param tamDestinos Es el tamaño máximo que pueden haber de destinos
void mostrarTodosDestinos(eDestino destinos[], int tamDestinos);

/// @brief Se encarga de validar el ID existente del destino
///
/// @param id Recibe un id a validar
/// @param destinos Recibe un array de destinos
/// @param tamDestinos Es el tamaño máximo de destinos
/// @return retorna 1 si sale bien, sino 0 si sale mal.
int validarIdDestino(int id, eDestino destinos[], int tamDestinos);

/// @brief Se encarga de cargar la decripcion del destino para que no aparezca el ID que el usuario ingresó. O sea, la descripción(string) y no el ID (int).
///
/// @param destinos Recibe un array de destinos
/// @param tamDestinos Es el tamaño máximo de destinos
/// @param idDestinos es el ID que se validara luego
/// @param descripcionDestinos Es la decripcion que luego se mostrará como string
/// @return
int cargarDescripcionDestino(eDestino destinos[], int tamDestinos,
		int idDestinos, char descripcionDestinos[]);

/// @brief Se encarga de cargar los precios de tipo float de los destinos ya hardcodeados
///
/// @param destinos Recibe un array de destinos
/// @param tamDestinos Es el tamaño máximo de destinos
/// @param idDestinos Es el ID a validar y trabajar
/// @param precioDestino Es el precio que luego se guardará y se mostrará.
/// @return
int cargarPreciosDestino(eDestino destinos[], int tamDestinos,
		int idDestinos, float* precioDestino);



#endif /* EDESTINO_H_ */
