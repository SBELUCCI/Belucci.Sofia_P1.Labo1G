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

void mostrarUnTipo(eTipo tipo);
void mostrarTodosTipos(eTipo tipos[], int tamTipos);

int cargarDescripcionTipo(eTipo tipos[], int tamTipos,
		int idTipos, char descripcionTipos[]);
int validarIdTipos(int id, eTipo tipos[], int tamTipos);



#endif /* ETIPO_H_ */
