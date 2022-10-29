/*
 * eAvion.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef EAVION_H_
#define EAVION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"
#include "eAerolinea.h"
#include "eTipo.h"
#include "ePiloto.h"

#define LIBRE 1
#define VACIO 0
#define OCUPADO -1


typedef struct {

	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int idPiloto;
	int isEmpty;



}eAvion;

/// @brief Se encarga de poner todos los indices de listaAviones libres
///
/// @param aviones Recibe un array de aviones
/// @param tamAvion Recibe el tama�o m�ximo que puede existir de aviones.
/// @return retorna 0 en caso de error y 1 en caso de �xito.
int inicializarAvion(eAvion aviones[], int tamAvion);

/// @brief Se encarga de buscar los indices libres para despues poder realizar el alta deseada
///
/// @param pIndice Recibe un indice
/// @param aviones Recibe un array de aviones
/// @param tamAvion Recibe un tama�o m�ximo de aviones.
/// @return retorna 0 en caso de error y 1 en caso de �xito.
int buscarIndiceLibreAvion(int *pIndice, eAvion aviones[], int tamAvion);

/// @brief Se encarga de dar las altas de aviones, en donde se le pide que el usuario complete los campos correspondientes de esta estructura.
///
/// @param pId Recibe el puntero del ID donde en el main se le pasar� la direcci�n de memoria que tendra y se incrementar� a medida que se d� de alta a un avi�n.
/// @param aviones Recibe un array de aviones.
/// @param tamAvion Recibe un tama�o maximo de aviones.
/// @param aerolineas Recibe un array de aerolineas.
/// @param tamAerolineas Recibe un tama�o m�ximo que pueden tener las aerolineas.
/// @param tipos Recibe un array de tipos de aviones
/// @param tamTipos Recibe el tama�o m�ximo de tipos de aviones
/// @return retorna 1 en caso de exito, sino 0 si ocurre un error.
int altaAvion(int *pId, eAvion aviones[], int tamAvion, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);

/// @brief Se encarga de mostrar un solo avi�n
///
/// @param avion recibe una variable de tipo eAvion
/// @param aerolineas recibe un array de aerolineas
/// @param tamAerolinea recibe el tama�o m�ximo del array de aerolineas
/// @param tipos Recibe un array de tipos de aviones
/// @param tamTipos Recibe un tama�o maximo de tipos de aviones
void mostrarUnAvion(eAvion avion, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);

/// @brief Se encarga de mostrar TODOS los aviones ingresados por el usuario.
///
/// @param aviones Recibe un array de aviones
/// @param tamAviones Recibe un tama�o m�ximo de aviones
/// @param aerolineas Recibe un array de aerolineas
/// @param tamAerolinea Es el tama�o maximo del array de aerolineas.
/// @param tipos Recibe un array de tipos de aviones
/// @param tamTipos es el tama�o del array de tipos de aviones.
void mostrarTodosAviones(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);

/// @brief Se encarga de buscar el ID del avi�n, si el mismo es exitente
///
/// @param id recibe un ID a validar
/// @param pIndice Recibe un indice
/// @param aviones Recibe un array de aviones
/// @param tamAviones Recibe el tama�o del array de aviones.
/// @return retorna 1 en caso de exito, sino 0 en caso de error.
int buscarAvion(int id, int *pIndice, eAvion aviones[], int tamAviones);

/// @brief Se encarga de realizar la modificacion del alta de un avi�n ingresando el ID, en caso de que el usuario quiera modificar algun dato.
///
/// @param aviones Recibe un array de aviones
/// @param tamAviones Recibe el tama�o del array de aviones
/// @param aerolineas Recibe un array de aerolineas.
/// @param tamAerolinea Recibe el tama�o del array de aerolineas.
/// @param tipos Recibe el array de tipos de aviones.
/// @param tamTipos Recibe el tama�o maximo de array de tipos de aviones.
/// @return retorna 1 en caso de exito, sino 0 en caso de error.
int modificarAvion(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);

/// @brief Se encarga de realizar una baja l�gica de un avi�n, el usuario ingresa el ID del avi�n a dar de baja.
///
/// @param aviones Recibe un array de aviones
/// @param tamAviones Es el tama�o maximo del array de aviones
/// @param aerolineas Recibe un array de aerolineas
/// @param tamAerolinea Es el tama�o maximo del array de aerolineas
/// @param tipos  Recibe un array de tipos de aviones
/// @param tamTipos Es el tama�o maximo del array de tipos de aviones
/// @return retorna 1 si salio bien, sino  0 en caso de error.
int bajaAvion(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolinea, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);

/// @brief Valida un ID existente de un avi�n
///
/// @param id Se le manda un ID de avion para validar
/// @param aviones Recibe un array de aviones
/// @param tamAviones Recibe el tama�o del array de aviones
/// @return retorna 1 en caso de que sea valido, sino retorna 0 si no es valido.
int validarIdAvion(int id, eAvion aviones[], int tamAviones);

/// @brief Se encarga de cargar la capacidad (int) que ingreso el usuario
///
/// @param aviones Recibe un array de aviones
/// @param tamAviones Es el tama�o del array de aviones
/// @param idAviones Recibe un id del avion a validar
/// @param capacidadAvion Es el dato que se va a guardar para despues mostrar
/// @return
int cargarCapacidadAvion(eAvion aviones[], int tamAviones,
		int idAviones, int* capacidadAvion);

/// @brief Se encarga de ordenar los aviones por doble criterio (Por aerolinea y por capacidad).
///
/// @param aviones  Recibe un array de aviones
/// @param tamAviones Recibe el tama�o del array de aviones
/// @return retorna 1 si sale bien, sino 0 en caso de error.
int ordenarAviones(eAvion aviones[], int tamAviones);
#endif /* EAVION_H_ */
