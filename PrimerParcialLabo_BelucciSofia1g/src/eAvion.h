/*
 * eAvion.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef EAVION_H_
#define EAVION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"
#include "eAerolinea.h"
#include "eTipo.h"

#define LIBRE 1
#define VACIO 0
#define OCUPADO -1


typedef struct {

	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int isEmpty;



}eAvion;


int inicializarAvion(eAvion aviones[], int tamAvion);
int buscarIndiceLibreAvion(int *pIndice, eAvion aviones[], int tamAvion);
int altaAvion(int *pIndice, eAvion aviones[], int tamAvion, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos);
void mostrarUnAvion(eAvion avion, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos);
void mostrarTodosAviones(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos);

#endif /* EAVION_H_ */
