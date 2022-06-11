#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pFile != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			char idStr[TAM_DATA];
			char nombre[TAM_NAME];
			char apellido[TAM_NAME];
			char precio[TAM_DATA];
			char estado[TAM_DATA];
			char tipo[TAM_DATA];
			char codigo[TAM_DATA];
			Passenger* unPasajero;

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, apellido, precio, codigo, tipo, estado);
			while(1)
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, apellido, precio, codigo, tipo, estado) == 7)
				{
					if(strcmp(tipo,"FirstClass") == 0)
					{
						strcpy(tipo, "1");
					}
					else
					{
						if(strcmp(tipo,"ExecutiveClass") == 0)
						{
							strcpy(tipo, "2");
						}
						else
						{
							strcpy(tipo, "3");
						}
					}

					unPasajero = Passenger_newParametros(idStr, nombre, tipo, apellido, precio, codigo, estado);

					if(unPasajero != NULL)
					{
						ll_add(pArrayListPassenger, unPasajero);
						retorno = 0;
					}
				}

				if(feof(pFile) != 0)
				{
					break;
				}
			}
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = 0;
	Passenger auxiliar;
	Passenger* new;
	if(pFile!=NULL)
	{
		while(!feof(pFile))
		{
			fread(&auxiliar, sizeof(Passenger),1,pFile);
			Passenger_printOne(&auxiliar);
		}
	}
    return ret;
}
