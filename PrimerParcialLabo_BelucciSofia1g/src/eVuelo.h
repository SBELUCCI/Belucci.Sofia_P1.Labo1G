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

int inicializarVuelo(eVuelo vuelos[], int tamVuelos);
int buscarIndiceLibreVuelos(int *pIndice, eVuelo vuelos[], int tamVuelos);
int altaVuelo(int *pIndice, eVuelo vuelos[], int tamVuelos, eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, eDestino destinos[], int tamDestinos);
void mostrarUnVuelo(eVuelo vuelo, eAvion aviones[], int tamAviones, eDestino destinos[], int tamDestinos, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos);
void mostrarTodosVuelos(eVuelo vuelos[],int tamVuelos, eAvion aviones[], int tamAviones, eDestino destinos[], int tamDestinos, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos);

#endif /* EVUELO_H_ */
