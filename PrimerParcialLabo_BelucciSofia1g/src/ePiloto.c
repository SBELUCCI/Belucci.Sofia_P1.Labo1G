/*
 * ePiloto.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Sofia Belucci
 */


#include "ePiloto.h"



void mostrarUnPiloto(ePiloto piloto) {

	printf("| %d | %-20s  |  %c   |\n", piloto.id, piloto.nombre, piloto.sexo);
	puts("_______________________________________________");

}

void mostrarTodosPilotos(ePiloto pilotos[], int tamPilotos) {

	if (pilotos != NULL && tamPilotos > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE PILOTOS----------");
		puts("===============================================");
		puts(
				"| ID |     NOMBRE Y APELLIDO      |   SEXO   |");
		puts("===============================================");

		for (int i = 0; i < tamPilotos; i++) {


				mostrarUnPiloto(pilotos[i]);


		}

	}

}


int validarIdPiloto(int id, ePiloto pilotos[], int tamPilotos) {
	int esValido = 0;

	if (pilotos != NULL && tamPilotos > 0) {
		for (int i = 0; i < tamPilotos; i++) {
			if (pilotos[i].id == id) {

				esValido = 1;
				break;

			}

		}

	}

	return esValido;
}


int cargarDescripcionPiloto(ePiloto pilotos[], int tamPilotos,
		int idPilotos, char descripcionPilotos[]) {
	int todoOk = 0;
	int flag = 1;

	if (pilotos != NULL && tamPilotos > 0 && descripcionPilotos != NULL) {

		todoOk = 1;
		for (int i = 0; i < tamPilotos; i++) {
			if (pilotos[i].id == idPilotos) {

				strcpy(descripcionPilotos, pilotos[i].nombre);
				flag = 0;
				break;

			}

		}

		if (flag) {
			todoOk = -1;
		}
	}

	return todoOk;

}

