/*
 * eAerolinea.c
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#include "eAerolinea.h"

void mostrarUnaAerolinea(eAerolinea aerolinea) {

	printf("| %d | %-20s  |\n", aerolinea.id, aerolinea.descripcionAerolinea);
	puts("_______________________________________________");

}

void mostrarTodasAerolineas(eAerolinea aerolineas[], int tamAerolineas) {
	if (aerolineas != NULL && tamAerolineas > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE AEROLINEAS----------");
		puts("===============================================");
		puts(
				"| ID | AEROLINEA            |");
		puts("===============================================");

		for (int i = 0; i < tamAerolineas; i++) {


				mostrarUnaAerolinea(aerolineas[i]);


		}

	}

}

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tamAerolineas,
		int idAerolinea, char descripcionAerolinea[]) {
	int todoOk = 0;
	int flag = 1;

	if ((aerolineas != NULL && tamAerolineas > 0) && descripcionAerolinea != NULL) {

		todoOk = 1;
		for (int i = 0; i < tamAerolineas; i++) {
			if (aerolineas[i].id == idAerolinea) {

				strcpy(descripcionAerolinea, aerolineas[i].descripcionAerolinea);
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

int validarIdAerolinea(int id, eAerolinea aerolineas[], int tamAerolinea) {
	int esValido = 0;

	if (aerolineas != NULL && tamAerolinea > 0) {
		for (int i = 0; i < tamAerolinea; i++) {
			if (aerolineas[i].id == id) {

				esValido = 1;
				break;

			}

		}

	}

	return esValido;
}


