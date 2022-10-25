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
