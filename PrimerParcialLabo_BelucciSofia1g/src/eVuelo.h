/*
 * eVuelo.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Sofia Belucci
 */

#ifndef EVUELO_H_
#define EVUELO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Inputs.h"
#include "Menu_opciones.h"
#include "eFecha.h"


typedef struct {

	int id;
	int idAvion;
	int idDestino;
	eFecha fechaVuelo;



}eVuelo;


#endif /* EVUELO_H_ */
