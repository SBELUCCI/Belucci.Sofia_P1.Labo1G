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

void mostrarUnaAerolinea(eAerolinea aerolinea);
void mostrarTodasAerolineas(eAerolinea aerolineas[], int tamAerolineas);
int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tamAerolineas,
		int idAerolinea, char descripcionAerolinea[]);
int validarIdAerolinea(int id, eAerolinea aerolineas[], int tamAerolinea);


#endif /* EAEROLINEA_H_ */
