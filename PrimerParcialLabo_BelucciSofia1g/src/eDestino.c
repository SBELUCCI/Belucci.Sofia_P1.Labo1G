/*
 * eDestino.c
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */


#include "eDestino.h"


void mostrarUnDestino(eDestino destino) {

	printf("| %d | %-20s  |  %.2f   |\n", destino.id, destino.descripcionDestino, destino.precio);
	puts("_______________________________________________");

}

void mostrarTodosDestinos(eDestino destinos[], int tamDestinos) {
	if (destinos != NULL && tamDestinos > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE DESTINOS----------");
		puts("===============================================");
		puts(
				"| ID | DESTINO            |   PRECIO   |");
		puts("===============================================");

		for (int i = 0; i < tamDestinos; i++) {


				mostrarUnDestino(destinos[i]);


		}

	}

}

int validarIdDestino(int id, eDestino destinos[], int tamDestinos) {
	int esValido = 0;

	if (destinos != NULL && tamDestinos > 0) {
		for (int i = 0; i < tamDestinos; i++) {
			if (destinos[i].id == id) {

				esValido = 1;
				break;

			}

		}

	}

	return esValido;
}


int cargarDescripcionDestino(eDestino destinos[], int tamDestinos,
		int idDestinos, char descripcionDestinos[]) {
	int todoOk = 0;
	int flag = 1;

	if ((destinos != NULL && tamDestinos > 0) && descripcionDestinos != NULL) {

		todoOk = 1;
		for (int i = 0; i < tamDestinos; i++) {
			if (destinos[i].id == idDestinos) {

				strcpy(descripcionDestinos, destinos[i].descripcionDestino);
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


int cargarPreciosDestino(eDestino destinos[], int tamDestinos,
		int idDestinos, float* precioDestino) {
	int todoOk = 0;
	int flag = 1;

	if ((destinos != NULL && tamDestinos > 0) && precioDestino > 0) {

		todoOk = 1;
		for (int i = 0; i < tamDestinos; i++) {
			if (destinos[i].id == idDestinos) {

				*precioDestino = destinos[i].precio;

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


