/*
 * eAvion.c
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */


#include "eAvion.h"


int inicializarAvion(eAvion aviones[], int tamAvion) {

	int todoOk = 0;

	if (aviones != NULL && tamAvion > 0) {
		for (int i = 0; i < tamAvion; i++) {
			aviones[i].isEmpty = LIBRE;

		}

		todoOk = 1;
	}

	return todoOk;

}

int buscarIndiceLibreAvion(int *pIndice, eAvion aviones[], int tamAvion) {
	int todoOk = 0;
	int indice = OCUPADO;

	if (pIndice != NULL && aviones != NULL && tamAvion > 0) {
		*pIndice = OCUPADO;

		for (int i = 0; i < tamAvion; i++) {
			if (aviones[i].isEmpty == LIBRE) {

				indice = i;
				break;
			}

		}

		*pIndice = indice;

		todoOk = 1;
	}

	return todoOk;

}

int altaAvion(int *pIndice, eAvion aviones[], int tamAvion, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos) {
	int todoOk = 0;
	int indice;
	eAvion auxAvion;


	if (pIndice != NULL && aviones != NULL && tamAvion > 0) {

		buscarIndiceLibreAvion(&indice, aviones, tamAvion);


		if (indice == OCUPADO) {


			puts("No hay lugar en el sistema para realizar el alta.\n \n");
		} else {
			auxAvion.id = *pIndice;

			mostrarTodasAerolineas(aerolineas, tamAerolineas);

			utn_getNumeroInt(&auxAvion.idAerolinea,
								"Ingrese el ID de la Aerolinea deseada:  ",
								"ERROR al cargar el ID la Aerolinea", 1, 30000, 10000);

						while(!validarIdAerolinea(auxAvion.idAerolinea, aerolineas, tamAerolineas))
						{
							mostrarTodasAerolineas(aerolineas, tamAerolineas);

							utn_getNumeroInt(&auxAvion.idAerolinea, "ERROR. Ingrese un ID de Aerolínea válido: ", "Vuelva a ingresar un número válido de ID.", 1, 10000000, 999);


						}




			mostrarTodosTipos(tipos, tamTipos);

			utn_getNumeroInt(&auxAvion.idTipo,
											"Ingrese el ID del tipo de avión deseado:  ",
											"ERROR al cargar el ID del tipo de avión. Reintentelo.", 1, 30000, 10000);

									while(!validarIdTipos(auxAvion.idTipo, tipos, tamTipos))
									{
										mostrarTodosTipos(tipos, tamTipos);

										utn_getNumeroInt(&auxAvion.idTipo, "ERROR. Ingrese un ID de tipo de avión válido: ", "Reingresar un número válido de ID.", 1, 10000000, 999);


									}

			utn_getNumeroInt(&auxAvion.capacidad, "Ingrese la capacidad del avión (entre 10 y 300 personas):  ", "ERROR al ingresar la capacidad del avión.", 10, 300, 100);

			auxAvion.isEmpty = OCUPADO;

			aviones[indice] = auxAvion;
			(*pIndice)++;


		}

		todoOk = 1;
	}

	return todoOk;

}

void mostrarUnAvion(eAvion avion, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos) {

	char descripcionAerolineas[20];
	char descripcionTipos[20];


	cargarDescripcionAerolinea(aerolineas, tamAerolinea,
			avion.idAerolinea, descripcionAerolineas);
	cargarDescripcionTipo(tipos, tamTipos, avion.idTipo, descripcionTipos);

	printf("| %d | %-20s | %-20s | %d | \n", avion.id, descripcionAerolineas,
			descripcionTipos, avion.capacidad);
	puts("_______________________________________________");

}

void mostrarTodosAviones(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos) {
	if (aviones != NULL && tamAviones > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE AVIONES INGRESADOS----------");
		puts("===============================================");
		puts(
				"| ID |    AEROLINEA    | TIPO DE AVIÓN | CAPACIDAD DEL AVIÓN |");
		puts("===============================================");

		for (int i = 0; i < tamAviones; i++) {
			if (aviones[i].isEmpty == OCUPADO) {

				mostrarUnAvion(aviones[i], aerolineas, tamAerolinea, tipos, tamTipos);
			}

		}

	}

}
