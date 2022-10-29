/*
 * eVuelo.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef EVUELO_H_
#define EVUELO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"
#include "eFecha.h"
#include "eAerolinea.h"
#include "eAvion.h"
#include "eTipo.h"
#include "eDestino.h"

#define LIBRE 1
#define VACIO 0
#define OCUPADO -1


typedef struct {

	int id;
	int idAvion;
	int idDestino;
	eFecha fechaVuelo;
	int isEmpty;



}eVuelo;

/// @brief Esta funcion se encarga de poner enn estado libre todos los indices de los vuelos para luego ir cargandolos.
///
/// @param vuelos Recibe una estructura de tipo vuelos y array de tipo de vuelos.
/// @param tamVuelos tamaño máximo de los vuelos.
/// @return retorna 1 en caso de éxito, sino 0 si ocurre un error.
int inicializarVuelo(eVuelo vuelos[], int tamVuelos);

/// @brief Busca un indice libre para después poder realizar el alta
///
/// @param pIndice Recibe un puntero de tipo indice.
/// @param vuelos recibe una estructura de vuelos y un array de vuelos
/// @param tamVuelos tamaño máximo de vuelos
/// @return retorna 1 en caso de éxito, sino retorna 0.
int buscarIndiceLibreVuelos(int *pIndice, eVuelo vuelos[], int tamVuelos);

/// @brief  Pide los datos correspondientes del campo de la estructura eVuelo y da de alta un vuelo.
///
/// @param pId Es el puntero del ID que luego en el main se le asigna la dirección de memoria del primer ID que tendrá la primera carga y luego se incrementará
/// @param vuelos Recibe el array de vuelos de su estructura.
/// @param tamVuelos Es el tamaño máximo permitido de aviones.
/// @param aviones Recibe el array de aviones de su estructura para trabajar con estos datos.
/// @param tamAviones Es el tamaño máximo permitido de aviones.
/// @param aerolineas Recibe el array de aerolineas de su estructura para trabajar con estos datos.
/// @param tamAerolinea Es el tamaño máximo permitido de aerolíneas.
/// @param tipos Recibe el array de tipos de aviones de su estructura para trabajar con estos datos.
/// @param tamTipos Es el tamaño máximo permitido de tipos de aviones.
/// @param destinos Recibe el array de destinos de su estructura para trabajar con estos datos.
/// @param tamDestinos Es el tamaño máximo permitido de destinos.
/// @return retorna 1 en caso de exito, sino 0 si ocurre un error.
int altaVuelo(int *pId, eVuelo vuelos[], int tamVuelos, eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, eDestino destinos[], int tamDestinos, ePiloto pilotos[], int tamPilotos);

/// @brief Se encarga de mostrar solamente un vuelo
///
/// @param vuelo Recibe una variable vuelo.
/// @param aviones Recibe el array de aviones de su estructura para trabajar con estos datos.
/// @param tamAviones Es el tamaño máximo permitido de aviones.
/// @param destinos Recibe el array de destinos de su estructura para trabajar con estos datos.
/// @param tamDestinos Es el tamaño máximo permitido de destinos.
/// @param aerolineas  Recibe el array de aerolineas de su estructura para trabajar con estos datos.
/// @param tamAerolineas Es el tamaño máximo permitido de aerolíneas.
/// @param tipos Recibe el array de tipos de aviones de su estructura para trabajar con estos datos.
/// @param tamTipos  Es el tamaño máximo permitido de tipos de aviones.
void mostrarUnVuelo(eVuelo vuelo, eAvion aviones[], int tamAviones, eDestino destinos[], int tamDestinos, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);


/// @brief Se encarga de mostrar todos los vuelos ingresados por el usuario
///
/// @param vuelos Recibe el array de vuelos de su estructura.
/// @param tamVuelos Es el tamaño máximo de vuelos
/// @param aviones Recibe el array de aviones de su estructura para trabajar con estos datos.
/// @param tamAviones Es el tamaño máximo permitido de aviones.
/// @param destinos Recibe el array de destinos de su estructura para trabajar con estos datos.
/// @param tamDestinos Es el tamaño máximo permitido de destinos.
/// @param aerolineas Recibe el array de aerolineas de su estructura para trabajar con estos datos.
/// @param tamAerolineas Es el tamaño máximo permitido de aerolíneas.
/// @param tipos Recibe el array de tipos de aviones de su estructura para trabajar con estos datos.
/// @param tamTipos Es el tamaño máximo permitido de tipos de aviones.
void mostrarTodosVuelos(eVuelo vuelos[],int tamVuelos, eAvion aviones[], int tamAviones, eDestino destinos[], int tamDestinos, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);

#endif /* EVUELO_H_ */
