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

int altaVuelo(int *pId, eVuelo vuelos[], int tamVuelos, eAvion aviones[],
		int tamAviones, eAerolinea aerolineas[], int tamAerolinea,
		eTipo tipos[], int tamTipos, eDestino destinos[], int tamDestinos, ePiloto pilotos[], int tamPilotos ) {
	int todoOk = 0;
	int indice;
	eVuelo auxVuelo;

	if (pId != NULL && vuelos != NULL && tamVuelos > 0) {

		buscarIndiceLibreVuelos(&indice, vuelos, tamVuelos);

		if (indice == OCUPADO) {

			puts("No hay lugar en el sistema para realizar el alta.\n \n");
		} else {
			auxVuelo.id = *pId;

			mostrarTodosAviones(aviones, tamAviones, aerolineas, tamAerolinea,
					tipos, tamTipos, pilotos, tamPilotos);
			utn_getNumeroInt(&auxVuelo.idAvion,
					"Ingrese el ID del avi�n deseado:  ",
					"ERROR: ingrese un ID de avi�n v�lido", 0, 99999, 100);

			while (!validarIdAvion(auxVuelo.idAvion, aviones, tamAviones)) {
				mostrarTodosAviones(aviones, tamAviones, aerolineas,
						tamAerolinea, tipos, tamTipos, pilotos, tamPilotos);
				utn_getNumeroInt(&auxVuelo.idAvion,
						"ERROR: Ingrese el ID del avi�n deseado:  ",
						"ERROR: ingrese un ID de avi�n v�lido ", 0, 99999, 100);

			}

			mostrarTodosDestinos(destinos, tamDestinos);

			utn_getNumeroInt(&auxVuelo.idDestino,
					"Ingrese el ID del destino deseado:  ",
					"ERROR: ingrese un ID de destino v�lido ", 0, 9999999, 100);

			while (!validarIdDestino(auxVuelo.idDestino, destinos, tamDestinos)) {
				mostrarTodosDestinos(destinos, tamDestinos);

				utn_getNumeroInt(&auxVuelo.idDestino,
						"ERROR: Ingrese el ID del destino deseado:  ",
						"ERROR: ingrese un ID de destino v�lido ", 0, 9999999,
						100);

			}

			printf("INGRESE LA FECHA DE VUELO\n");
			utn_getNumeroInt(&auxVuelo.fechaVuelo.dia,
					"Ingrese el d�a deseado del vuelo:  ",
					"Error: ingrese un dia valido", 1, 31, 100);
			utn_getNumeroInt(&auxVuelo.fechaVuelo.mes,
					"Ingrese el mes deseado del vuelo:  ",
					"Error: ingrese un mes valido", 1, 12, 100);
			utn_getNumeroInt(&auxVuelo.fechaVuelo.anio,
					"Ingrese el a�o deseado del vuelo:  ",
					"Error: ingrese un a�o valido", 1, 2030, 100);

			auxVuelo.isEmpty = OCUPADO;

			vuelos[indice] = auxVuelo;
			(*pId)++;

		}

		todoOk = 1;
	}

	return todoOk;

}

void mostrarUnVuelo(eVuelo vuelo, eAvion aviones[], int tamAviones,
		eDestino destinos[], int tamDestinos, eAerolinea aerolineas[],
		int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos) {

	char descripcionAerolineas[20];
	char descripcionTipos[20];
	char descripcionDestinos[20];
	char descripcionPilotos[30];
	int capacidadAvion;
	float preciosDestino;

	eAvion auxTest;
	int auxIdTipo;


	for(int i = 0; i<tamAviones;i++){
		if(aviones[i].id == vuelo.idAvion){
			auxTest = aviones[i];
		}
	}
	for(int i = 0; i<tamTipos;i++){
		if(tipos[i].id == auxTest.idTipo){
			auxIdTipo = tipos[i].id;
		}
	}

	cargarDescripcionAerolinea(aerolineas, tamAerolineas,
			auxTest.idAerolinea, descripcionAerolineas);
	cargarDescripcionTipo(tipos, tamTipos, auxIdTipo, descripcionTipos);

	cargarDescripcionPiloto(pilotos, tamPilotos, auxTest.idPiloto, descripcionPilotos);
	cargarCapacidadAvion(aviones, tamAviones, vuelo.idAvion, &capacidadAvion);
	cargarDescripcionDestino(destinos, tamDestinos, vuelo.idDestino,
			descripcionDestinos);
	cargarPreciosDestino(destinos, tamDestinos, vuelo.idDestino,
			&preciosDestino);

	printf("| %d | %-20s | %-20s | %d |  %-10s     | %-20s  | %.2f  | %02d/%02d/%02d |\n",
			vuelo.id, descripcionAerolineas, descripcionTipos, capacidadAvion, descripcionPilotos,
			descripcionDestinos, preciosDestino, vuelo.fechaVuelo.dia,
			vuelo.fechaVuelo.mes, vuelo.fechaVuelo.anio);
	puts("_______________________________________________");

}

void mostrarTodosVuelos(eVuelo vuelos[], int tamVuelos, eAvion aviones[],
		int tamAviones, eDestino destinos[], int tamDestinos,
		eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos) {
	if (aviones != NULL && tamAviones > 0) {
		puts("\n\n====================================================================================================================");
		puts("====================================----------LISTA DE DESTINOS----------===============================================");
		puts("========================================================================================================================");
		puts(
				"| ID |    AEROLINEA    | TIPO DE AVI�N | CAPACIDAD DEL AVI�N |     NOMBRE DEL PILOTO    |  DESTINOS  |   PRECIO DE VUELO  |    FECHA DE VUELO  |");
		puts("========================================================================================================================");

		for (int i = 0; i < tamVuelos; i++) {
			if (vuelos[i].isEmpty == OCUPADO) {

				mostrarUnVuelo(vuelos[i], aviones, tamAviones, destinos,
						tamDestinos, aerolineas, tamAerolineas, tipos,
						tamTipos, pilotos, tamPilotos);

			}

		}

	}

}
