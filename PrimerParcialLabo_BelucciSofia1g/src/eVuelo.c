/*
 * eVuelo.c
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */


#include "eVuelo.h"

int inicializarVuelo(eVuelo vuelos[], int tamVuelos) {

	int todoOk = 0;

	if (vuelos != NULL && tamVuelos > 0) {
		for (int i = 0; i < tamVuelos; i++) {
			vuelos[i].isEmpty = LIBRE;

		}

		todoOk = 1;
	}

	return todoOk;

}

int buscarIndiceLibreVuelos(int *pIndice, eVuelo vuelos[], int tamVuelos) {
	int todoOk = 0;
	int indice = OCUPADO;

	if (pIndice != NULL && vuelos != NULL && tamVuelos > 0) {
		*pIndice = OCUPADO;

		for (int i = 0; i < tamVuelos; i++) {
			if (vuelos[i].isEmpty == LIBRE) {

				indice = i;
				break;
			}

		}

		*pIndice = indice;

		todoOk = 1;
	}

	return todoOk;

}


int altaVuelo(int *pIndice, eVuelo vuelos[], int tamVuelos, eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, eDestino destinos[], int tamDestinos) {
	int todoOk = 0;
	int indice;
	eVuelo auxVuelo;


	if (pIndice != NULL && vuelos != NULL && tamVuelos > 0) {


		buscarIndiceLibreVuelos(&indice, vuelos, tamVuelos);


		if (indice == OCUPADO) {


			puts("No hay lugar en el sistema para realizar el alta.\n \n");
		} else {
			auxVuelo.id = *pIndice;


			mostrarTodosAviones(aviones, tamAviones, aerolineas, tamAerolinea, tipos, tamTipos);
			utn_getNumeroInt(&auxVuelo.idAvion, "Ingrese el ID del avión deseado:  ", "ERROR: ingrese un ID de avión válido", 0, 99999, 100);


						while(!validarIdAvion(auxVuelo.idAvion, aviones, tamAviones))
						{
							mostrarTodosAviones(aviones, tamAviones, aerolineas, tamAerolinea, tipos, tamTipos);
										utn_getNumeroInt(&auxVuelo.idAvion, "Ingrese el ID del avión deseado:  ", "ERROR: ingrese un ID de avión válido ", 0, 99999, 100);


						}




			mostrarTodosDestinos(destinos, tamDestinos);

			utn_getNumeroInt(&auxVuelo.idDestino, "Ingrese el ID del destino deseado:  ", "ERROR: ingrese un ID de destino válido ", 0, 9999999, 100);


									while(!validarIdDestino(auxVuelo.idDestino, destinos, tamDestinos))
									{
										mostrarTodosDestinos(destinos, tamDestinos);

													utn_getNumeroInt(&auxVuelo.idDestino, "Ingrese el ID del destino deseado:  ", "ERROR: ingrese un ID de destino válido ", 0, 9999999, 100);

									}

									printf("INGRESE LA FECHA DE VUELO\n");
									utn_getNumeroInt(&auxVuelo.fechaVuelo.dia, "Ingrese el día deseado del vuelo:  ", "Error: ingrese un dia valido", 1, 31, 100);
									utn_getNumeroInt(&auxVuelo.fechaVuelo.mes, "Ingrese el mes deseado del vuelo:  ", "Error: ingrese un mes valido", 1, 12, 100);
									utn_getNumeroInt(&auxVuelo.fechaVuelo.anio, "Ingrese el año deseado del vuelo:  ", "Error: ingrese un año valido", 1, 2030, 100);







			auxVuelo.isEmpty = OCUPADO;

			vuelos[indice] = auxVuelo;
			(*pIndice)++;


		}

		todoOk = 1;
	}

	return todoOk;

}



void mostrarUnVuelo(eVuelo vuelo, eAvion aviones[], int tamAviones, eDestino destinos[], int tamDestinos, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos) {

	char descripcionAerolineas[20];
	char descripcionTipos[20];
	char descripcionDestinos[20];


	cargarDescripcionAerolinea(aerolineas, tamAerolineas,
			aviones->idAerolinea, descripcionAerolineas);
	cargarDescripcionTipo(tipos, tamTipos, aviones->idTipo, descripcionTipos);
	cargarDescripcionDestino(destinos, tamDestinos, vuelo.idDestino, descripcionDestinos);

	printf("| %d | %-20s | %-20s | %d | %-20s  | %.2f  | %02d/%02d/%02d |\n", vuelo.id, descripcionAerolineas,
			descripcionTipos, aviones->capacidad, descripcionDestinos, destinos->precio, vuelo.fechaVuelo.dia, vuelo.fechaVuelo.mes, vuelo.fechaVuelo.anio);
	puts("_______________________________________________");

}


void mostrarTodosVuelos(eVuelo vuelos[],int tamVuelos, eAvion aviones[], int tamAviones, eDestino destinos[], int tamDestinos, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos) {
	if (aviones != NULL && tamAviones > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE DESTINOS----------");
		puts("===============================================");
		puts(
				"| ID |    AEROLINEA    | TIPO DE AVIÓN | CAPACIDAD DEL AVIÓN |  DESTINOS  |   PRECIO DE VUELO  |    FECHA DE VUELO  |");
		puts("===============================================");

		for (int i = 0; i < tamVuelos; i++) {
			if (vuelos[i].isEmpty == OCUPADO) {


				mostrarUnVuelo(vuelos[i], aviones, tamAviones, destinos, tamDestinos, aerolineas,  tamAerolineas, tipos, tamTipos);

			}

		}

	}

}
