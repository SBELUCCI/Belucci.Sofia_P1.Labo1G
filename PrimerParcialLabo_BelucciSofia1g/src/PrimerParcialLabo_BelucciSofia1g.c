/*
 ============================================================================
 Name        : PrimerParcialLabo_BelucciSofia1g.c
 Author      : Sofia Belucci
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Menu_opciones.h"
#include "Inputs.h"
#include "eFecha.h"
#include "eAerolinea.h"
#include "eTipo.h"
#include "eAvion.h"
#include "eDestino.h"
#include "eVuelo.h"

#define TAM_AEROLINEAS 5
#define TAM_TIPO 4
#define TAM_DESTINO 4
#define TAM_AVION 5


int main(void) {
	setbuf(stdout, NULL);

	eAvion listaAviones[TAM_AVION];

	int opcionIngresada;
	char confirmacion = 'n';
	int proximoIdAvion = 1000;

	int flagAltaHecha = 0;



	eAerolinea listaAerolineas[TAM_AEROLINEAS] =

	{
			{1000, "Lan"},
			{1001,"Iberia"},
			{1002,"Norwegian"},
			{1003,"American"},
			{1004, "Austral"}

	};
	eTipo listaTipo[TAM_TIPO] =
					{

		{5000, "Jet"},
		{5001,"Helice"},
		{5002,"Planeador"},
		{5003,"Carga"}


					};


	eDestino listaDestino[TAM_DESTINO] =
	{
			{20000,"Calafate", 22250},
			{20001,"Miami", 103000},
			{20002,"Milan", 84400},
			{20003,"Amsterdam", 95600}

	};


	inicializarAvion(listaAviones, TAM_AVION);

	do{

		opcionIngresada = menuOpciones("\n --------MENÚ PRINCIPAL--------\n \n",
					" 1) ALTA AVIÓN\n 2) MODIFICAR AVION\n 3) BAJA AVIÓN\n 4) LISTAR AVIONES\n 5)LISTAR AEROLINEAS\n 6) LISTAR TIPOS\n 7) LISTAR DESTINOS\n 8)ALTA VUELO\n 9) LISTAR VUELOS\n 10) SALIR DEL PROGRAMA \n \n ============================= \n \n");

		switch(opcionIngresada)
		{
		case 1:
			if(altaAvion(&proximoIdAvion, listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO)== 1)
			{
				puts("\n¡Alta cargada exitosamente!\n");
				flagAltaHecha = 1;
			}else
			{

				puts("ERROR: no se pudo realizar la carga del alta del avión.\n");
			}
			break;
		case 2:


			modificarAvion(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO);




					break;
		case 3:







					break;
		case 4:

			mostrarTodosAviones(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO);


					break;
		case 5:

			mostrarTodasAerolineas(listaAerolineas, TAM_AEROLINEAS);


					break;
		case 6:

			mostrarTodosTipos(listaTipo, TAM_TIPO);


					break;
		case 7:


			mostrarTodosDestinos(listaDestino, TAM_DESTINO);

					break;
		case 8:
					break;
		case 9:
					break;
		case 10:

			utn_getChar(&confirmacion, "\n ¿Está seguro que desea salir del programa? s: SI / n: NO = ","ERROR", 100);

								if (confirmacion == 's') {
									puts("\n ¡Gracias por utilizar nuestro servicio!");
								}
					break;

		default:
			puts("\n ERROR: La opción es incorrecta. Ingrese nuevamente otro número entre el 1 y 10. \n");
			break;




		}


	}while(opcionIngresada != 10 || confirmacion != 's' );





	return 0;
}
