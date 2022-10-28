/*
 * eAerolinea.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef EAEROLINEA_H_
#define EAEROLINEA_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Inputs.h"
#include "Menu_opciones.h"

typedef struct {

	int id;
	char descripcionAerolinea[20];


}eAerolinea;


/// @brief Se encarga de mostrar una sola aerolinea
///
/// @param aerolinea se le asigna una variable aerolinea de tipo eAerolinea
void mostrarUnaAerolinea(eAerolinea aerolinea);

/// @brief Muestra todas las aerolineas cuando el usuario cargo el alta del avión
///
/// @param aerolineas Recibe un array de aerolineas
/// @param tamAerolineas Recibe el tamaño del array de aerolineas
void mostrarTodasAerolineas(eAerolinea aerolineas[], int tamAerolineas);

/// @brief  Se encarga de cargar la descripcion de las aerolineas hardcodeadas para que no se muestren con el ID
///
/// @param aerolineas Recibe un array de aerolineas de tipo eAerolinea
/// @param tamAerolineas Recibe el tamaño del array de aerolineas
/// @param idAerolinea Recibe un id de aerolineas a trabajar
/// @param descripcionAerolinea Recibe la descripcion para copiarle los datos y despues mostrarla
/// @return
int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tamAerolineas,
		int idAerolinea, char descripcionAerolinea[]);

/// @brief Se encarga de validar el ID existente de las aerolineas hardcodeadas
///
/// @param id Se recibe un id de las mismas para validarlas y trabajarlo
/// @param aerolineas Recibe un array de aerolineas
/// @param tamAerolinea Recibe el tamaño del array de aerolineas
/// @return retorna 1 si es valido, y en caso de que no lo sea retornará 0.
int validarIdAerolinea(int id, eAerolinea aerolineas[], int tamAerolinea);


#endif /* EAEROLINEA_H_ */
