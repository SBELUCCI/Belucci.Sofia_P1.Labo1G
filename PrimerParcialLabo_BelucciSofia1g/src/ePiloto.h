/*
 * ePiloto.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef EPILOTO_H_
#define EPILOTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	int id;
	char nombre[30];
	char sexo;

}ePiloto;

void mostrarUnPiloto(ePiloto piloto);
void mostrarTodosPilotos(ePiloto pilotos[], int tamPilotos);
int validarIdPiloto(int id, ePiloto pilotos[], int tamPilotos);
int cargarDescripcionPiloto(ePiloto pilotos[], int tamPilotos,
		int idPilotos, char descripcionPilotos[]);



#endif /* EPILOTO_H_ */
