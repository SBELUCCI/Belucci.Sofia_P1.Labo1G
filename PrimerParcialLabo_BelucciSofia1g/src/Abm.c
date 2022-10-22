/*
 * Abm.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Sofia Belucci
 */

#include "Abm.h"

int inicializarAvion(eAvion vec[], int tam) {

	int todoOk = 0;

	if (vec != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			vec[i].isEmpty = LIBRE;

		}

		todoOk = 1;
	}

	return todoOk;

}

int buscarLibre(int *pIndice, eAvion vec[], int tam) {
	int todoOk = 0;
	int indice = OCUPADO;

	if (pIndice != NULL && vec != NULL && tam > 0) {
		*pIndice = OCUPADO;

		for (int i = 0; i < tam; i++) {
			if (vec[i].isEmpty == LIBRE) {

				indice = i;
				break;
			}

		}

		*pIndice = indice;

		todoOk = 1;
	}

	return todoOk;

}

int cargarDescripcionAerolinea(eAerolinea aerolinea[], int tamAerolineas,
		int idAerolinea, char descripcionAerolinea[]) {
	int todoOk = 0;
	int flag = 1;

	if (aerolinea != NULL & tamAerolineas > 0 && descripcionAerolinea != NULL) {

		todoOk = 1;
		for (int i = 0; i < tamAerolineas; i++) {
			if (aerolinea[i].id == idAerolinea) {

				strcpy(descripcionAerolinea, aerolinea[i].descripcionAerolinea);
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

int cargarDescripcionTipo(eTipo tipo[], int tamTipo,
		int idTipo, char descripcionTipo[]) {
	int todoOk = 0;
	int flag = 1;

	if (tipo != NULL & tamTipo > 0 && descripcionTipo != NULL) {

		todoOk = 1;
		for (int i = 0; i < tamTipo; i++) {
			if (tipo[i].id == idTipo) {

				strcpy(descripcionTipo, tipo[i].descripcionTipo);
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

int validarIdAerolinea(int id, eAerolinea aerolinea[], int tamAerolinea) {
	int esValido = 0;

	if (aerolinea != NULL && tamAerolinea > 0) {
		for (int i = 0; i < tamAerolinea; i++) {
			if (aerolinea[i].id == id) {

				esValido = 1;
				break;

			}

		}

	}

	return esValido;
}

int validarIdTipo(int id, eTipo tipo[], int tamTipo) {
	int esValido = 0;

	if (tipo != NULL && tamTipo > 0) {
		for (int i = 0; i < tamTipo; i++) {
			if (tipo[i].id == id) {

				esValido = 1;
				break;

			}

		}

	}

	return esValido;
}

int altaAvion(int *pId, eAvion avion[], int tamAvion, eAerolinea aerolinea[],
		int tamAerolinea, eTipo tipo[], int tamTipo) {
	int todoOk = 0;
	int indice;
	eAvion auxAvion;
	eAerolinea auxAerolinea;
	eTipo auxTipo;

	if (pId != NULL && avion != NULL && tamAvion > 0) {
		buscarLibre(&indice, avion, tamAvion);

		if (indice == OCUPADO) {

			puts("No hay lugar en el sistema para realizar el alta.\n \n");
		} else {
			auxAvion.id = *pId;

			//id aerolinea


			utn_getNumeroInt(&auxAerolinea.id,
					"Ingrese el id de la Aerolinea:  ",
					"ERROR al cargar la aerolinea", 1, 30000, 10000);

			while(!validarIdAerolinea(auxAvion.idAerolinea, aerolinea, tamAerolinea))
			{
				mostrarAerolinea(aerolinea, tamAerolinea);

				utn_getNumeroInt(&auxAvion.idAerolinea, "Error. Ingrese un id de aerolinea válido.", "Vuelva a intentarlo", 1, 10000000, 999);


			}


			utn_getNumeroInt(&auxTipo.id,
								"Ingrese el id de la Aerolinea:  ",
								"ERROR al cargar la aerolinea", 1, 30000, 10000);

			while(!validarIdTipo(auxAvion.idTipo,tipo, tamTipo))
			{

				mostrarTipo(tipo, tamTipo);

				utn_getNumeroInt(&auxAvion.idTipo, "Error. Ingrese un id de tipo válido.", "Vuelva a intentarlo", 1, 10000000, 999);


			}

			//id tipo

			utn_getNumeroInt(&auxAvion.capacidad,
					"Ingrese la capacidad del avion (pasajeros entre 10 y 300):  ",
					"Ha ocurrido un error al ingresar la capacidad.", 10, 300,
					100);

			auxAvion.isEmpty = OCUPADO;

			avion[indice] = auxAvion;
			(*pId)++;

		}

		todoOk = 1;
	}

	return todoOk;

}

void mostrarUnAvion(eAvion avion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo) {

	char descripcionAerolinea[20];
	char descrpcionTipo[20];

	if (cargarDescripcionAerolinea(aerolinea, tamAerolineas, avion.idAerolinea,
			descripcionAerolinea) == 1 && cargarDescripcionTipo(tipo, tamTipo, avion.idTipo, descrpcionTipo) == 1) {

		printf("| %d | %-20s  | %-20s   | %d | \n", avion.id, descripcionAerolinea,
				descrpcionTipo, avion.capacidad);
		puts("_______________________________________________");
	}

}


void mostrarTodosAviones(eAvion avion[], int tamAvion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo) {
	if (avion != NULL && tamAvion > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE AVIONES INGRESADOS----------");
		puts("===============================================");
		puts(
				"| ID | AEROLINEA     | TIPO | CAPACIDAD | ");
		puts("===============================================\n\n");

		for (int i = 0; i < tamAvion; i++) {
			if (avion[i].isEmpty == OCUPADO) {

				mostrarUnAvion(avion[i],aerolinea,tamAerolineas, tipo,  tamTipo);


			}

		}

	}

}


void mostrarAerolinea(eAerolinea aerolinea[], int tamAerolinea)

{
	printf("*****AEROLINEAS***** \n\n");
	printf("| ID | AEROLINEA    |\n");
	printf("======================\n");

	for(int i = 0; i < tamAerolinea; i++)
	{
		if(aerolinea[i].isEmpty == OCUPADO){

			printf("%d  |    %-10s |\n", aerolinea[i].id, aerolinea[i].descripcionAerolinea);


		}
	}
}


void mostrarTipo(eTipo tipo[], int tamTipo)

{
	printf("****TIPOS DE AVIONES***** \n\n");
	printf("| ID | TIPO   |\n");
	printf("======================\n");

	for(int i = 0; i < tamTipo; i++)
	{
		if(tipo[i].isEmpty == OCUPADO){

			printf("%d  |    %-10s |\n", tipo[i].id, tipo[i].descripcionTipo);


		}
	}
}


int buscarAvion(int id, int *pIndice, eAvion avion[], int tamAvion) {

	int todoOk = 0;
	int indice = OCUPADO;

	if (pIndice != NULL && avion != NULL && tamAvion > 0) {
		*pIndice = OCUPADO;

		for (int i = 0; i < tamAvion; i++) {
			if (!avion[i].isEmpty == VACIO && avion[i].id == id) {

				indice = i;
				break;
			}

		}
		*pIndice = indice;

		todoOk = 1;
	}

	return todoOk;

}

int bajaAvion(eAvion avion[], int tamAvion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo) {
	int todoOk = 0;
	int id;
	int indice;
	char confirma = 'n';

	if (avion != NULL && tamAvion > 0) {

		printf("\n\n**** BAJA AVION***** \n \n ");

		mostrarTodosAviones(avion, tamAvion, aerolinea, tamAerolineas, tipo, tamTipo);

		utn_getNumeroInt(&id, "Ingrese el id del avion a dar de baja:  ", "ERROR", 0, 10000, 100);


		buscarAvion(id, &indice, avion, tamAvion);

		if (indice == OCUPADO) {

			printf("No existe un avion con ese id %d \n", id);
		} else {



			mostrarUnAvion(avion[indice], aerolinea, tamAerolineas, tipo, tamTipo);
			utn_getChar(&confirma, "Ingrese confirmación: n = NO / s = SI:  ", "Ocurrio un ERROR", 100);

			if (confirma != 's') {

				puts("Se ha cancelado la baja");

			} else {

				avion[indice].isEmpty = LIBRE;
				printf("Baja de avión exitosa!!");

			}

		}

		todoOk = 1;
	}

	return todoOk;
}


int modificarAvion(eAvion avion[], int tamAvion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo) {

	int todoOk = 0;
	int id;
	int indice;
	char confirma = 'n';
	int opcionSeleccionada;



	eAvion auxAvion;
	eAerolinea auxAerolineas;
	eTipo auxTipo;


	if (avion != NULL && tamAvion > 0) {

		puts("--------------MODIFICACION DE AVIONES-----------------");


		mostrarTodosAviones(avion, tamAvion, aerolinea, tamAerolineas, tipo, tamTipo);

		utn_getNumeroInt(&id, "Ingrese el id de la persona a modificar:  ", "ERROR", 0, 10000, 100);


		buscarAvion(id, &indice, avion, tamAvion);

		if (indice == OCUPADO) {
			printf("No existe una avion con ese id %d \n", id);

		} else {


			mostrarUnAvion(avion[indice], aerolinea, tamAerolineas, tipo, tamTipo);

			auxAvion = avion[indice];

			do {
				opcionSeleccionada =
						menuOpciones("******MODIFICACION AVION********\n\n",
								"¿Qué dato desea modificar? \n 1) MODIFICAR TIPO DE AVION\n 2) MODIFICAR CAPACIDAD DEL AVION 3) VOLVER AL MENU PRINCIPAL\n \n \n ============================= \n \n");

				switch (opcionSeleccionada) {
				case 1:

					utn_getNumeroInt(&auxAerolineas.id,
									"Ingrese el id de la Aerolinea:  ",
									"ERROR al cargar la aerolinea", 1, 30000, 10000);

							while(!validarIdAerolinea(&auxAvion.idAerolinea, aerolinea, tamAerolineas))
							{
								mostrarAerolinea(aerolinea, tamAerolineas);

								utn_getNumeroInt(&auxAvion.idAerolinea, "Error. Ingrese un id de aerolinea válido.", "Vuelva a intentarlo", 1, 10000000, 999);


							}

					break;
				case 2:

					utn_getNumeroInt(&auxTipo.id,
													"Ingrese el id de la Aerolinea:  ",
													"ERROR al cargar la aerolinea", 1, 30000, 10000);

								while(!validarIdTipo(&auxAvion.idTipo,tipo, tamTipo))
								{

									mostrarTipo(tipo, tamTipo);

									utn_getNumeroInt(&auxAvion.idTipo, "Error. Ingrese un id de tipo válido.", "Vuelva a intentarlo", 1, 10000000, 999);
								}


					break;
				case 3:


					mostrarUnAvion(avion[indice], aerolinea, tamAerolineas, tipo, tamTipo);
					utn_getChar(&confirma, "¿Confirma la modificación? n = NO / s = SI : ", "Ocurrio un ERROR", 100);

					if (confirma == 's') {

						avion[indice] = auxAvion;
						puts("MODIFICACION EXITOSA!!");

						puts("Volviendo al Menú Principal del ABM...\n \n");
						todoOk = 1;
					} else {
						puts("Se ha cancelado la modificacion");
					}
					break;

				default:
					puts(
							"\n ERROR: La opción es incorrecta. Ingrese nuevamente otro número \n");
					break;

				}
			} while (opcionSeleccionada != 2);

		}

	}

	return todoOk;

}

void mostrarDestino(eDestino destino[], int tamDestino)

{
	printf("****DESTINOS***** \n\n");
	printf("| ID | DESTINO   |   PRECIO  |\n");
	printf("======================\n");

	for(int i = 0; i < tamDestino; i++)
	{
		if(destino[i].isEmpty == OCUPADO){

			printf("%d  |    %-10s |  %.2f\n", destino[i].id, destino[i].descripcionDestino, destino[i].precio);


		}
	}
}

