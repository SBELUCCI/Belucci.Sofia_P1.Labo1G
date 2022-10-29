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
#include "ePiloto.h"
#include "Informes.h"

#define TAM_AEROLINEAS 5
#define TAM_TIPO 4
#define TAM_DESTINO 4
#define TAM_AVION 5
#define TAM_VUELOS 5
#define TAM_PILOTO 4


int main(void) {
	setbuf(stdout, NULL);

	eAvion listaAviones[TAM_AVION];
	eVuelo listaVuelos[TAM_VUELOS];

	int opcionIngresada;
	int opcionSeleccionadaInformes;
	char confirmacion = 'n';
	int proximoIdAvion = 1000;
	int proximoIdVuelo = 100;

	int flagAltaAvionHecha = 0;
	int flagAltaVueloHecho = 0;



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

	ePiloto listaPiloto[TAM_PILOTO] =

	{

			{0, "Mauro González", 'm'},
			{1, "Andrea García", 'f'},
			{2, "Juan Carlos Martínez", 'm'},
			{3, "Mariana Montes", 'f'}

	};


	inicializarAvion(listaAviones, TAM_AVION);
	inicializarVuelo(listaVuelos, TAM_VUELOS);

	do{

		opcionIngresada = menuOpciones("\n --------MENÚ PRINCIPAL--------\n \n",
					" 1) ALTA AVIÓN\n 2) MODIFICAR AVION\n 3) BAJA AVIÓN\n 4) LISTAR AVIONES\n 5) LISTAR AEROLINEAS\n 6) LISTAR TIPOS\n 7) LISTAR DESTINOS\n 8) ALTA VUELO\n 9) LISTAR VUELOS\n 10) INFORMES\n 11) SALIR DEL PROGRAMA \n \n ============================= \n \n");

		switch(opcionIngresada)
		{
		case 1:
			if(altaAvion(&proximoIdAvion, listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO)== 1)
			{
				puts("\n¡Alta cargada exitosamente!\n");
				flagAltaAvionHecha = 1;
			}else
			{

				puts("ERROR: no se pudo realizar la carga del alta del avión.\n");
			}
			break;
		case 2:





			if(flagAltaAvionHecha== 1){

					if(modificarAvion(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO) == 1)
					{
						puts("\n\n");
					}else{
						puts("ERROR: No se pudo realizar la modificacion");
					}
					}else{

						puts("ERROR: Deben existir altas de avión cargadas para poder realizar una modificación de avión.");

					}




					break;
		case 3:


			if(flagAltaAvionHecha == 1){

			if(bajaAvion(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO) == 1)
			{
				puts("\n \n");
			}else{
				puts("ERROR: No se pudo realizar la baja");
			}
			}else{
				puts("ERROR: Deben existir altas cargadas para poder realizar una baja de avión.");
			}











					break;
		case 4:
			if(flagAltaAvionHecha == 1)
			{
				ordenarAviones(listaAviones, TAM_AVION);
			mostrarTodosAviones(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO);
			}else
			{
				puts("ERROR: Deben existir altas cargadas para poder mostrar los aviones ingresados.");
			}


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

			if(flagAltaAvionHecha == 1 && altaVuelo(&proximoIdVuelo, listaVuelos, TAM_VUELOS, listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaDestino, TAM_DESTINO, listaPiloto, TAM_PILOTO)== 1)
			{
				puts("\n¡Alta cargada exitosamente!\n");

				flagAltaVueloHecho = 1;

			}else{

				puts("ERROR: no se pudo realizar la carga del alta del vuelo.\n");
			}


					break;
		case 9:
			if(flagAltaVueloHecho == 1)
			{
			mostrarTodosVuelos(listaVuelos, TAM_VUELOS, listaAviones, TAM_AVION, listaDestino, TAM_DESTINO, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO);
			}else
			{
				puts("ERROR: Deben haber altas de vuelos cargadas en el sistema.\n");
			}
					break;


		case 10:

			do{


				opcionSeleccionadaInformes = menuOpciones("\n-------SUBMENÚ DE INFORMES-------\n\n", "1) Mostrar aviones de la aerolinea seleccionada por el usuario\n"
						"2) Mostrar aviones de un tipo de avión seleccionado\n"
						"3) Informar porcentaje de aviones jet sobre el total de aviones de una aerolinea\n"
						"4) Mostrar un listado de los aviones separados por aerolinea\n"
						"5) Informar la o las aerolineas que pueden transportar más pasajeros\n "
						"6) Mostrar la aerolínea con menor cantidad de aviones\n"
						"7) Volver al Menú Principal\n---------------------------------\n\n ");

				switch(opcionSeleccionadaInformes)
				{


				case 1:

					mostrarAvionesAerolineasUsuario(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO);
					break;
				case 2:

					mostrarAvionesTipoUsuario(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO);
					break;
				case 3:
					mostrarPorcentajeAvionesJet(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO);

					break;
				case 4:

					mostrarAvionesPorAerolinea(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS, listaTipo, TAM_TIPO, listaPiloto, TAM_PILOTO);
					break;
				case 5:
					mostrarAerolineaMayorCapacidad(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS);
					break;
				case 6:

					mostrarAerolineaMenorCantidadAviones(listaAviones, TAM_AVION, listaAerolineas, TAM_AEROLINEAS);
					break;
				case 7:



					break;
				default:
					puts("\n ERROR: La opción es incorrecta. Ingrese nuevamente otro número entre el 1 y 7. \n");
					break;
				}






			}while(opcionSeleccionadaInformes != 7);




			break;
		case 11:

			utn_getChar(&confirmacion, "\n ¿Está seguro que desea salir del programa? s: SI / n: NO = ","ERROR", 100);

								if(confirmacion == 's') {
									puts("\n ¡Gracias por utilizar nuestro servicio!");
								}
					break;

		default:
			puts("\n ERROR: La opción es incorrecta. Ingrese nuevamente otro número entre el 1 y 11. \n");
			break;




		}


	}while(opcionIngresada != 11 || confirmacion != 's' );





	return 0;
}
