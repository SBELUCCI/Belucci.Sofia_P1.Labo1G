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

void mostrarUnDestino(eDestino destino);
void mostrarTodosDestinos(eDestino destinos[], int tamDestinos);
int validarIdDestino(int id, eDestino destinos[], int tamDestinos);
int cargarDescripcionDestino(eDestino destinos[], int tamDestinos,
		int idDestinos, char descripcionDestinos[]);



#endif /* EDESTINO_H_ */
