/*
 * Abm.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef ABM_H_
#define ABM_H_

#define LIBRE 1
#define VACIO 0
#define OCUPADO -1



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"


typedef struct {

	int dia;
	int mes;
	int anio;


}eFecha;

typedef struct {

	int id;
	char descripcionAerolinea[20];
	int isEmpty;




}eAerolinea;

typedef struct {

	int id;
	char descripcionTipo[20];
	int isEmpty;

}eTipo;

typedef struct {

	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int isEmpty;



}eAvion;

typedef struct {

	int id;
	char descripcionDestino[25];
	float precio;
	int isEmpty;



}eDestino;

typedef struct {

	int id;
	int idAvion;
	int idDestino;
	eFecha fechaVuelo;



}eVuelo;



int inicializarAvion(eAvion vec[], int tam);
int buscarLibre(int *pIndice, eAvion vec[], int tam);
int cargarDescripcionAerolinea(eAerolinea aerolinea[], int tamAerolineas,
		int idAerolinea, char descripcionAerolinea[]);
int cargarDescripcionTipo(eTipo tipo[], int tamTipo,
		int idTipo, char descripcionTipo[]);
int validarIdAerolinea(int id, eAerolinea aerolinea[], int tamAerolinea);
int validarIdTipo(int id, eTipo tipo[], int tamTipo);
int altaAvion(int *pId, eAvion avion[], int tamAvion, eAerolinea aerolinea[],
		int tamAerolinea, eTipo tipo[], int tamTipo);
void mostrarUnAvion(eAvion avion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo);
void mostrarTodosAviones(eAvion avion[], int tamAvion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo);
void mostrarAerolinea(eAerolinea aerolinea[], int tamAerolinea);
void mostrarTipo(eTipo tipo[], int tamTipo);
int buscarAvion(int id, int *pIndice, eAvion avion[], int tamAvion);
int bajaAvion(eAvion avion[], int tamAvion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo);
int modificarAvion(eAvion avion[], int tamAvion, eAerolinea aerolinea[], int tamAerolineas, eTipo tipo[], int tamTipo);
void mostrarDestino(eDestino destino[], int tamDestino);





#endif /* ABM_H_ */
