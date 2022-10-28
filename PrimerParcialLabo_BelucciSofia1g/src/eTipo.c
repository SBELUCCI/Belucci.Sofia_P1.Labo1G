/*
 * eTipo.c
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#include "eTipo.h"

void mostrarUnTipo(eTipo tipo) {

	printf("| %d | %-20s  |\n", tipo.id, tipo.descripcionTipo);
	puts("_______________________________________________");

}

void mostrarTodosTipos(eTipo tipos[], int tamTipos) {
	if (tipos != NULL && tamTipos > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE TIPOS DE AVIONES----------");
		puts("===============================================");
		puts(
				"| ID | TIPO DE AVIÓN          |");
		puts("===============================================");

		for (int i = 0; i < tamTipos; i++) {


				mostrarUnTipo(tipos[i]);


		}

	}

}

int cargarDescripcionTipo(eTipo tipos[], int tamTipos,
		int idTipos, char descripcionTipos[]) {
	int todoOk = 0;
	int flag = 1;

	if (tipos != NULL && tamTipos > 0 && descripcionTipos != NULL) {

		todoOk = 1;
		for (int i = 0; i < tamTipos; i++) {
			if (tipos[i].id == idTipos) {

				strcpy(descripcionTipos, tipos[i].descripcionTipo);
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

int validarIdTipos(int id, eTipo tipos[], int tamTipos) {
	int esValido = 0;

	if (tipos != NULL && tamTipos > 0) {
		for (int i = 0; i < tamTipos; i++) {
			if (tipos[i].id == id) {

				esValido = 1;
				break;

			}

		}

	}

	return esValido;
}


