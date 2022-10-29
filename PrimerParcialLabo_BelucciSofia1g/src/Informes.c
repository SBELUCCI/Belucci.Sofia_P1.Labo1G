/*
 * Informes.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Sofia Belucci
 */


#include "Informes.h"


int mostrarAvionesAerolineasUsuario(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos)
{
	int todoOk = 0;
	int idAerolinea;
	int flag = 1;

	if(aviones != NULL && tamAviones > 0 && aerolineas != NULL && tamAerolineas > 0)
	{


		puts("\n\n---------MOSTRAR TODOS LOS AVIONES DE LA AEROLINEA DESEADA----------\n");
		mostrarTodasAerolineas(aerolineas, tamAerolineas);

		utn_getNumeroInt(&idAerolinea, "Ingrese el ID de la aerolinea deseada:  ", "ERROR: Ingrese un número de ID de aerolínea válido:  ", 0, 9999999, 100);

		while(!validarIdAerolinea(idAerolinea, aerolineas, tamAerolineas))
		{
			mostrarTodasAerolineas(aerolineas, tamAerolineas);
			utn_getNumeroInt(&idAerolinea, "Ingrese el ID de la aerolinea deseada:  ", "ERROR: Ingrese un número de ID de aerolínea válido:  ", 0, 9999999, 100);

		}

	         	puts("\n\n===============================================");
				puts("----------LISTA DE AVIONES INGRESADOS----------");
				puts("===============================================");
				puts(
						"| ID |    AEROLINEA    | TIPO DE AVIÓN | CAPACIDAD DEL AVIÓN |   NOMBRE DEL PILOTO   |");
				puts("===============================================");

				for (int i = 0; i < tamAviones; i++) {
					if (aviones[i].isEmpty == OCUPADO && aviones[i].idAerolinea == idAerolinea) {

						mostrarUnAvion(aviones[i], aerolineas, tamAerolineas, tipos, tamTipos, pilotos, tamPilotos);
						flag = 0;

					}


				}

				if(flag)
				{
					// poner la descripcion de la aerolinea que ingreso el usuario
					puts("No hay aviones en esta aerolínea");
				}





		todoOk = 1;
	}


	return todoOk;
}



int mostrarAvionesTipoUsuario(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos)
{
	int todoOk = 0;
	int idTipo;
	int flag = 1;

	if(aviones != NULL && tamAviones > 0 && tipos != NULL && tamTipos > 0)
	{


		puts("\n\n---------MOSTRAR TODOS LOS AVIONES DEL TIPO SELECCIONADO----------\n");
		mostrarTodosTipos(tipos, tamTipos);

		utn_getNumeroInt(&idTipo, "Ingrese el ID del tipo de avión deseado:  ", "ERROR: Ingrese un número de ID de tipo de avión válido:  ", 0, 9999999, 100);



		while(!validarIdTipos(idTipo, tipos, tamTipos))
		{
			mostrarTodosTipos(tipos, tamTipos);
        	utn_getNumeroInt(&idTipo, "Ingrese el ID del tipo de avión deseado:  ", "ERROR: Ingrese un número de ID de tipo de avión válido:  ", 0, 9999999, 100);

		}

	        	puts("\n\n============================================================");
				puts("----------LISTA DE TIPOS DE AVIONES AVIONES INGRESADOS----------");
				puts("================================================================");
				puts(
						"| ID |    AEROLINEA    | TIPO DE AVIÓN | CAPACIDAD DEL AVIÓN |   NOMBRE DEL PILOTO  |");
				puts("=================================================================");

				for (int i = 0; i < tamAviones; i++) {
					if (aviones[i].isEmpty == OCUPADO && aviones[i].idTipo == idTipo) {




						mostrarUnAvion(aviones[i], aerolineas, tamAerolineas, tipos, tamTipos, pilotos, tamPilotos);
						flag = 0;

					}


				}

				if(flag)
				{
					// poner la descripcion del tipo de avion que ingreso el usuario
					puts("No hay aviones con este tipo de avión");
				}





		todoOk = 1;
	}


	return todoOk;
}


int mostrarPorcentajeAvionesJet(eAvion aviones[], int tamAviones,eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos)
{

// porcentaje de aviones de tipo jet sobre total de aviones de una aerolinea

	int todoOk = 0;
	int idAerolinea;
	int contadorAerolineaBuscada = 0;
	int contadorAvionJet = 0;
	float porcentaje;


	mostrarTodasAerolineas(aerolineas, tamAerolineas);

	utn_getNumeroInt(&idAerolinea, "Ingrese un ID de una aerolínea:   ", "ERROR: Reingrese ID:  ", 0, 10000, 100);

	while(!validarIdAerolinea(idAerolinea, aerolineas, tamAerolineas))
	{

		mostrarTodasAerolineas(aerolineas, tamAerolineas);

			utn_getNumeroInt(&idAerolinea, "Ingrese un ID de una aerolínea:   ", "ERROR: Reingrese ID:  ", 0, 10000, 100);
	}

	for(int i = 0; i<tamAviones; i++){
		if(aviones[i].idAerolinea == idAerolinea){
			contadorAerolineaBuscada++;
		}
	}

	for(int i = 0; i < tamAviones; i++)
	{
		if(aviones[i].isEmpty == OCUPADO && aviones[i].idTipo == 5000)
		{
			contadorAvionJet++;

		}
	}




	porcentaje = (float)(contadorAvionJet * 100 )/ contadorAerolineaBuscada;

	printf("El porcentaje de aviones sobre la aerolínea deseada es de: %.2f", porcentaje);

	todoOk = 1;








	return todoOk;

}









int mostrarAvionesPorAerolinea(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPilotos)
{
	int todoOk = 0;
	//char descripcionTipos[20];
	//char descripcionPilotos[30];
	//int flag = 1;



	//cargarDescripcionTipo(tipos, tamTipos, auxAvion.idTipo, descripcionTipos);

	if(aviones != NULL && tamAviones > 0 && aerolineas != NULL && tamAerolineas > 0 && tipos != NULL && tamTipos > 0 && pilotos != NULL && tamPilotos > 0)
	{


		puts("\n------------------LISTA DE AVIONES SEPARADOS POR AEROLINEA---------------------\n\n");
		for(int i = 0; i < tamAerolineas; i++)

		{

			printf("|AEROLINEA:  %-10s |\n", aerolineas[i].descripcionAerolinea);


		}

		for(int j= 0; j < tamAviones; j++)
		{
			if(aviones[j].idAerolinea == aerolineas[j].id)
			{

				printf("|TIPO: %d  | CAPACIDAD: %d   | PILOTO: %d  | ", aviones[j].idTipo, aviones[j].capacidad, aviones[j].idPiloto);



			}


		}



		todoOk = 1;
	}







	return todoOk;

}


int mostrarAerolineaMayorCapacidad(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas)

{
	int todoOk = 0;
	int acumuladoresAerolinea[tamAerolineas];
	int mayorCapacidadAerolinea;


	if(aviones != NULL && tamAviones > 0 && aerolineas != NULL && tamAerolineas > 0)
	{
     for(int i = 0; i < tamAerolineas; i++)
     {

    	 acumuladoresAerolinea[i] = 0;
     }

		puts("--------------AEROLINEA CON MAYOR CAPACIDAD--------------------");

		for(int i = 0; i < tamAerolineas; i++)
		{
			for(int j = 0; j < tamAviones; j++)
			{
				if(aviones[j].isEmpty == OCUPADO && aviones[j].idAerolinea == aerolineas[i].id)
				{

					acumuladoresAerolinea[i]+=aviones[j].capacidad;
				}



			}




		}

		for(int i = 0; i < tamAerolineas; i++)
		{

			if(i == 0 || acumuladoresAerolinea[i] > mayorCapacidadAerolinea)
			{

				mayorCapacidadAerolinea = acumuladoresAerolinea[i];

			}
		}
		for(int i = 0; i < tamAerolineas; i++)
				{

					if(mayorCapacidadAerolinea == acumuladoresAerolinea[i])
					{

						printf("La aerolinea con mayor capacidad es:  %s", aerolineas[i].descripcionAerolinea);

					}
				}






		todoOk = 1;
	}





 return todoOk;

}




int mostrarAerolineaMenorCantidadAviones(eAvion aviones[], int tamAviones, eAerolinea aerolineas[], int tamAerolineas)

{
	int todoOk = 0;
	int contadorAerolinea[tamAerolineas];
	int menorCantidadAviones;


	if(aviones != NULL && tamAviones > 0 && aerolineas != NULL && tamAerolineas > 0)
	{
     for(int i = 0; i < tamAerolineas; i++)
     {

    	 contadorAerolinea[i] = 0;
     }

		puts("--------------AEROLINEA CON MENOR CANTIDAD DE AVIONES--------------------");

		for(int i = 0; i < tamAerolineas; i++)
		{
			for(int j = 0; j < tamAviones; j++)
			{
				if(aviones[j].isEmpty == OCUPADO && aviones[j].idAerolinea == aerolineas[i].id)
				{

					contadorAerolinea[i]++;
				}



			}




		}

		for(int i = 0; i < tamAerolineas; i++)
		{

			if(i == 0 || contadorAerolinea[i] < menorCantidadAviones)
			{

				menorCantidadAviones = contadorAerolinea[i];

			}
		}
		for(int i = 0; i < tamAerolineas; i++)
				{

					if(contadorAerolinea[i] == menorCantidadAviones)
					{

						printf("La aerolinea con menor cantidad de aviones es:  %s", aerolineas[i].descripcionAerolinea);

					}
				}






		todoOk = 1;
	}





 return todoOk;

}

