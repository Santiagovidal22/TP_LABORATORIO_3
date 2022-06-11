/********************************************************************************************************
 *   Programa: TP 3
 *
 *	Objetivo:
 *		Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo, para lo cual
 *			se deber� desarrollar una soluci�n implementando la biblioteca LinkedList.
 *
 *		El sistema deber� tener el siguiente men� de opciones:
 *		 	 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 *			 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 *			 3. Alta de pasajero
 *			 4. Modificar datos de pasajero
 *			 5. Baja de pasajero
 *		 	 6. Listar pasajeros
 *			 7. Ordenar pasajeros
 *			 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 *			 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 *			10. Salir
 *
 *	Autor: Santiago Vidal
 *
 ********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "func_ex.h"
#include "Passenger.h"
#include "parser.h"

int main() {
	int opcion;
	int contadorPasajerosAgregados = 0;
	int contadorPasajerosBorrados = 0;
	int largo;
	int errorE;
	int save = 1;
	int errorB;
	int opc;
	int dataCargar = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();

	setbuf(stdout, NULL);

	do {
		utn_getInt(&opcion,
				"\n->>Menu Principal<<--\n\n"
						"  1- \tCargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
						"  2- \tCargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
						"  3- \tAlta de pasajero.\n"
						"  4- \tModificar datos de pasajero.\n"
						"  5- \tBaja de pasajero.\n"
						"  6- \tListar pasajeros.\n"
						"  7- \tOrdenar pasajeros.\n"
						"  8- \tGuardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
						"  9- \tGuardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
						"  10- \tSalir.\n"
						"OPCION: ",
				"\nError. Elija opcion valida.\n", 1, 10);
		largo = ll_len(listaPasajeros);
		switch (opcion) {
		case 1:
			if (dataCargar == 0) {
				if (controller_loadFromText("data.csv", listaPasajeros) == 0) {
					dataCargar = 1;
					printf("\nLos datos han sido cargados exitosamente.\n");
					if (contadorPasajerosAgregados != 0) {
						if (controller_corregirId(listaPasajeros,
								contadorPasajerosAgregados) == 0) {
							printf(
									"\nSe corrigieron los id de los pasajeros agregados anteriormente correctamente.\n");
						} else {
							printf(
									"\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
						}
					}
				} else {
					printf("\nLos datos no se han podido cargar.\n");
				}
			} else {
				printf("\nDatos Cargados.\n");
			}
			break;
		case 2:
			if (dataCargar == 0) {
				dataCargar = 1;
			} else {
				printf("\nDatos Cargados.\n");
			}
			break;
		case 3:
			if (controller_addPassenger(listaPasajeros,
					contadorPasajerosBorrados) == 0) {
				printf("\nSe ha agregado correctamente el pasajero.\n");
				save = 0;
				contadorPasajerosAgregados++;
			} else {
				printf("\nNo se ha podido agregar al pasajero.\n");
			}
			break;
		case 4:
			if (largo != 0) {
				errorE = controller_editPassenger(listaPasajeros);
				switch (errorE) {
				case -1:
					printf(
							"\nError. Error en la lista.\n");
					break;
				case -2:
					printf(
							"Error. El id ingresado no se encuentra\n");
					break;
				case -3:
					printf(
							"Error. Hubo un inconveniente al intentar obtener los datos del pasajero.\n");
					break;
				default:
					save = 0;
				}
			} else {
				printf("\nTodavia no ingreso ningun pasajero.\n");
			}
			printf("\nVolviendo al menu principal.\n");
			break;
		case 5:
			errorB = controller_removePassenger(listaPasajeros);
			switch (errorB) {
			case 0:
				contadorPasajerosBorrados++;
				printf(
						"\nSe ha dado de baja correctamente al pasajero de la lista.\n");
				save = 0;
				break;
			case -1:
				printf("\nError. La lista se encuentra vacia.\n");
				break;
			case -2:
				printf(
						"\nError. El id ingresado no coincide con ningun pasajero de la lista.\n");
				break;
			case -3:
				printf(
						"\nSe ha cancelado la bajada del pasajero de la lista.\n");
				break;
			}
			printf("\nVolviendo al menu principal.\n");
			break;
		case 6:
			if (controller_ListPassenger(listaPasajeros) != 0) {
				printf("\nError. La lista se encuentra vacio.\n");
				printf("\nVolviendo al menu principal.\n");
			}
			break;
		case 7:
			opc = controller_sortPassenger(listaPasajeros);
			switch (opc) {
			case 1:
				printf("\nSe ordeno correctamente los pasajeros por id.\n");
				save = 0;
				break;
			case 2:
				printf(
						"\nSe ordeno correctamente los pasajeros por apellido.\n");
				save = 0;
				break;
			case 3:
				printf(
						"\nSe ordeno correctamente los pasajeros por tipo de pasajero.\n");
				save = 0;
				break;
			case 4:
				printf(
						"\nSe ordeno correctamente los pasajeros por codigo de vuelo.\n");
				save = 0;
				break;
			default:
				printf(
						"\nError. No se pudo ordenar correctamente los pasajeros.\n");
			}
			break;
		case 8:
			if (dataCargar == 0) {
				controller_controlarId("data.csv", listaPasajeros);
			}
			if (controller_saveAsText("data.csv", listaPasajeros, dataCargar)
					== 0) {
				printf(
						"\nSe guardo con exito los datos de los pasajeros en el archivo data.csv (modo texto).\n");
				save = 1;
			} else {
				printf("\nError. No se pudo guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
			}
			break;
		case 9:
			if (dataCargar == 0) {
				controller_controlarId("data.csv", listaPasajeros);
			}
			if (controller_saveAsBinary("data.bin", listaPasajeros, dataCargar)
								== 0) {
			printf("\nSe guardo con exito los datos de los pasajeros en el archivo data.bin (modo binario).\n");
			save = 1;
			}
			else{
				printf("\nError. No se pudo guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
			}

			break;
		default:
			if (save == 0) {
				printf(
						"\nError. No puede cerrar el sistema sin guardar los datos antes\n");
			} else {
				printf("FINALIZADO\n");
			}
		}
	} while (opcion != 10 || save != 1);

	printf("FIN DE PROGRAMA");
	return 0;
}

