/*
 * Informes.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"
#include "eAerolinea.h"
#include "eTipo.h"
#include "ePiloto.h"
#include "eAvion.h"

#define LIBRE 1
#define VACIO 0
#define OCUPADO -1


int mostrarAvionesAerolineasUsuario(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);
int mostrarAvionesTipoUsuario(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);
int mostrarPorcentajeAvionesJet(eAvion aviones[], int tamAviones,eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos);
int mostrarAvionesPorAerolinea(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos);
int mostrarAerolineaMayorCapacidad(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas);
int mostrarAerolineaMenorCantidadAviones(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas);
#endif /* INFORMES_H_ */
