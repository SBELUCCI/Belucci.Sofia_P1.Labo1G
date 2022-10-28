/*
 * eTipo.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef ETIPO_H_
#define ETIPO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"

typedef struct {

	int id;
	char descripcionTipo[20];


}eTipo;


/// @brief Se encarga de mostrar un solo tipo de avión
///
/// @param tipo Se manda una variable de tipo eTipo
void mostrarUnTipo(eTipo tipo);

/// @brief Se encarga de mostrar todos los tipos de avión que se ingresaron
///
/// @param tipos Recibe un array de tipos de aviones.
/// @param tamTipos Es el tamaño máximo de tipos de aviones.
void mostrarTodosTipos(eTipo tipos[], int tamTipos);


/// @brief Se encarga de cargar la descripcion del campo eTipo para poder mostrarla y que no sea un ID.
///
/// @param tipos Recibe un array de tipos de aviones.
/// @param tamTipos Es el tamaño máximo que se permiten de tipos de aviones.
/// @param idTipos Se le pasa un dato de tipo int donde se guardará.
/// @param descripcionTipos Es la descripcion a copiar que luego se mostrará en mostrarAviones
/// @return
int cargarDescripcionTipo(eTipo tipos[], int tamTipos,
		int idTipos, char descripcionTipos[]);

/// @brief Se encarga de validar la existencia de los tipos de ID ingresados.
///
/// @param id se le pasa un ID para validar
/// @param tipos Recibe un array de tipos de aviones
/// @param tamTipos Es el tamaño máximo de tipos de aviones
/// @return
int validarIdTipos(int id, eTipo tipos[], int tamTipos);



#endif /* ETIPO_H_ */
