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

int altaAvion(int *pId, eAvion aviones[], int tamAvion, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos) {
	int todoOk = 0;
	int indice;
	eAvion auxAvion;


	if (pId != NULL && aviones != NULL && tamAvion > 0) {

		buscarIndiceLibreAvion(&indice, aviones, tamAvion);


		if (indice == OCUPADO) {


			puts("No hay lugar en el sistema para realizar el alta.\n \n");
		} else {
			auxAvion.id = *pId;

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


			mostrarTodosPilotos(pilotos, tamPilotos);

			utn_getNumeroInt(&auxAvion.idPiloto, "Ingrese el ID del piloto que desea:  ", "ERROR: reingrese un ID de piloto válido:  ", 0, 100, 100);

			while(!validarIdPiloto(auxAvion.idPiloto, pilotos, tamPilotos))
			{
				mostrarTodosPilotos(pilotos, tamPilotos);

				utn_getNumeroInt(&auxAvion.idPiloto, "Ingrese el ID del piloto que desea:  ", "ERROR: reingrese un ID de piloto válido:  ", 0, 100, 100);

			}

			auxAvion.isEmpty = OCUPADO;

			aviones[indice] = auxAvion;
			(*pId)++;


		}

		todoOk = 1;
	}

	return todoOk;

}

void mostrarUnAvion(eAvion avion, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos) {

	char descripcionAerolineas[20];
	char descripcionTipos[20];
	char descripcionPilotos[30];


	cargarDescripcionAerolinea(aerolineas, tamAerolinea,
			avion.idAerolinea, descripcionAerolineas);
	cargarDescripcionTipo(tipos, tamTipos, avion.idTipo, descripcionTipos);
	cargarDescripcionPiloto(pilotos, tamPilotos, avion.idPiloto, descripcionPilotos);

	printf("| %d | %-20s | %-20s | %d |  %-10s \n", avion.id, descripcionAerolineas,
			descripcionTipos, avion.capacidad, descripcionPilotos);
	puts("_______________________________________________");

}

void mostrarTodosAviones(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos) {
	if (aviones != NULL && tamAviones > 0) {
		puts("\n\n===============================================");
		puts("----------LISTA DE AVIONES INGRESADOS----------");
		puts("===============================================");
		puts(
				"| ID |    AEROLINEA    | TIPO DE AVIÓN | CAPACIDAD DEL AVIÓN |  NOMBRE DEL PILOTO  |");
		puts("===============================================");

		for (int i = 0; i < tamAviones; i++) {
			if (aviones[i].isEmpty == OCUPADO) {

				mostrarUnAvion(aviones[i], aerolineas, tamAerolinea, tipos, tamTipos, pilotos, tamPilotos);

			}
		//	ordenarAviones(aviones, tamAviones); poner en el main

		}

	}

}

int buscarAvion(int id, int *pIndice, eAvion aviones[], int tamAviones) {

	int todoOk = 0;
	int indice = OCUPADO;

	if (pIndice != NULL && aviones != NULL && tamAviones > 0) {
		*pIndice = OCUPADO;

		for (int i = 0; i < tamAviones; i++) {
			if (!aviones[i].isEmpty == VACIO && aviones[i].id == id) {

				indice = i;
				break;
			}

		}
		*pIndice = indice;

		todoOk = 1;
	}

	return todoOk;

}



int modificarAvion(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos) {

	int todoOk = 0;
	int id;
	int indice;
	char confirma = 'n';
	int opcionSeleccionada;



	eAvion auxAvion;

	if (aviones != NULL && tamAviones > 0) {

		puts("\n\n--------------MODIFICACIÓN DE AVIONES-----------------");


		mostrarTodosAviones(aviones, tamAviones, aerolineas, tamAerolinea, tipos, tamTipos, pilotos, tamPilotos);

		utn_getNumeroInt(&id, "Ingrese el id del Avión a modificar:  ", "ERROR", 0, 10000, 100);


		buscarAvion(id, &indice, aviones, tamAviones);



		if (indice == OCUPADO) {


			printf("No existe un avión con ese ID %d \n", id);


		} else {


			mostrarUnAvion(aviones[indice], aerolineas, tamAerolinea, tipos, tamTipos, pilotos, tamPilotos);

			auxAvion = aviones[indice];

			do {
				opcionSeleccionada =
						menuOpciones("\n\n******MODIFICACION ABM********\n\n",
								"¿Qué dato desea modificar? \n 1) MODIFICAR TIPO DEL AVIÓN\n 2) MODIFICAR CAPACIDAD DEL AVIÓN\n 3) NOMBRE DEL PILOTO\n 4) VOLVER AL MENÚ PRINCIPAL \n \n ============================= \n \n");

				switch (opcionSeleccionada) {
				case 1:

					puts("Usted eligió modificar: TIPO DE AVIÓN\n");
					mostrarTodosTipos(tipos, tamTipos);
					utn_getNumeroInt(&auxAvion.idTipo, "Ingrese el nuevo ID del tipo de avión deseado:   ", "ERROR. Debe ingresar un ID válido.", 0, 999999, 1000);
					while(!validarIdTipos(auxAvion.idTipo, tipos, tamTipos))
														{
															mostrarTodosTipos(tipos, tamTipos);

															utn_getNumeroInt(&auxAvion.idTipo, "ERROR. Ingrese un ID de tipo de avión válido: ", "Reingresar un número válido de ID.", 1, 10000000, 999);


														}

					break;
				case 2:
					puts("Usted eligió modificar: CAPACIDAD DEL AVIÓN\n");
					utn_getNumeroInt(&auxAvion.capacidad, "Ingrese la nueva capacidad del avión (entre 10 y 300 personas):  ", "ERROR al ingresar la capacidad del avión.", 10, 300, 100);
					break;


				case 3:
					puts("Usted eligió modificar: NOMBRE DEL PILOTO DEL AVIÓN\n");

					mostrarTodosPilotos(pilotos, tamPilotos);
					utn_getNumeroInt(&auxAvion.idPiloto, "Ingrese el nuevo ID del piloto deseado:  ", "ERROR: ingrese un ID de piloto valido:  ", 0, 100, 100);

					while(!validarIdPiloto(auxAvion.idPiloto, pilotos, tamPilotos))
					{

						mostrarTodosPilotos(pilotos, tamPilotos);
						utn_getNumeroInt(&auxAvion.idPiloto, "Ingrese el nuevo ID del piloto deseado:  ", "ERROR: ingrese un ID de piloto valido:  ", 0, 100, 100);

					}



					break;

				case 4:


					mostrarUnAvion(aviones[indice], aerolineas, tamAerolinea, tipos, tamTipos, pilotos, tamPilotos);
					utn_getChar(&confirma, "¿Está seguro que desea modificar este dato? n = NO / s = SI : ", "Ocurrio un ERROR", 100);

					if (confirma == 's') {

						aviones[indice] = auxAvion;
						puts("¡MODIFICACION EXITOSA!");

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
			} while (opcionSeleccionada != 4);

		}

	}

	return todoOk;

}



int bajaAvion(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos) {
	int todoOk = 0;
	int id;
	int indice;
	char confirma = 'n';

	if (aviones != NULL && tamAviones > 0) {

		printf("\n\n--------BAJA DEL AVIÓN-------- \n \n ");


		mostrarTodosAviones(aviones, tamAviones, aerolineas, tamAerolinea, tipos, tamTipos, pilotos, tamPilotos);

		utn_getNumeroInt(&id, "Ingrese el ID del avión a dar de baja:  ", "ERROR", 0, 10000, 100);


			buscarAvion(id, &indice, aviones, tamAviones);



		if (indice == OCUPADO) {


			printf("No existe un avión con ese ID %d \n", id);




		} else {


			mostrarUnAvion(aviones[indice], aerolineas, tamAerolinea, tipos, tamTipos, pilotos, tamPilotos);
			utn_getChar(&confirma, "¿Está seguro que desea dar de baja este avión?: n = NO / s = SI:  ", "Ocurrio un ERROR", 100);

			if (confirma != 's') {

				puts("Se ha cancelado la baja");

			} else {

				aviones[indice].isEmpty = LIBRE;
				printf("¡Baja de avión exitosa!");

			}



		}

		todoOk = 1;
	}

	return todoOk;
}

int validarIdAvion(int id, eAvion aviones[], int tamAviones) {
	int esValido = 0;

	if (aviones != NULL && tamAviones > 0) {
		for (int i = 0; i < tamAviones; i++) {
			if (aviones[i].id == id) {

				esValido = 1;
				break;

			}

		}

	}

	return esValido;
}


int cargarCapacidadAvion(eAvion aviones[], int tamAviones,
		int idAviones, int* capacidadAvion) {
	int todoOk = 0;
	int flag = 1;

	if ((aviones != NULL && tamAviones > 0) && capacidadAvion > 0) {

		todoOk = 1;
		for (int i = 0; i < tamAviones; i++) {
			if (aviones[i].id == idAviones) {

				*capacidadAvion = aviones[i].capacidad;

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



int ordenarAviones(eAvion aviones[], int tamAviones)
{
	int todoOk = 0;
	eAvion auxAvion;

	if(aviones != NULL && tamAviones > 0)
	{

		for(int i = 0; i < tamAviones - 1; i++)
		{
			for(int j = i + 1; j < tamAviones; j++)
			{
				if((aviones[i].idAerolinea > aviones[j].idAerolinea) || (aviones[i].idAerolinea == aviones[j].idAerolinea && aviones[i].capacidad > aviones[j].capacidad))

				{

					auxAvion = aviones[i];
					aviones[i] = aviones[j];
					aviones[j] = auxAvion;
				}



			}
		}

		todoOk = 1;
	}


	return todoOk;
}


