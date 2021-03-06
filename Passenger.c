#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "func_ex.h"
#include "LinkedList.h"

Passenger* Passenger_new() {
	Passenger *unPasajero;

	unPasajero = (Passenger*) malloc(sizeof(Passenger));

	return unPasajero;
}
Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *tipoPasajeroStr, char *apellidoStr, char *precio, char *codigo,
		char *estado) {
	Passenger *unPasajero;
	unPasajero = Passenger_new();
	int error = 0;

	if (unPasajero != NULL && Passenger_setId(unPasajero, atoi(idStr)) == 0
			&& Passenger_setNombre(unPasajero, nombreStr) == 0
			&& Passenger_setApellido(unPasajero, apellidoStr) == 0
			&& Passenger_setPrecio(unPasajero, atof(precio)) == 0
			&& Passenger_setCodigoVuelo(unPasajero, codigo) == 0
			&& Passenger_setCodigoVuelo(unPasajero, codigo) == 0
			&& Passenger_setTipoPasajero(unPasajero,
					atoi(tipoPasajeroStr) == 0
							&& Passenger_setEstadoVuelo(unPasajero, estado)
									== 0)) {
		error = 1;
	}
	if (error != 1) {
		unPasajero = NULL;
	}
	return unPasajero;
}
int Passenger_find(LinkedList *this, int id) {
	int retorno = -1;
	int len;
	Passenger *pasajeroAux;
	if (this != NULL && id > 0) {
		len = ll_len(this);
		for (int i = 0; i < len; i++) {
			pasajeroAux = (Passenger*) ll_get(this, i);
			if (pasajeroAux->id == id) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void Passenger_delete(Passenger *this) {
	if (this != NULL) {
		free(this);
	}
}

int Passenger_setId(Passenger *this, int idPasajero) {
	int retorno = -1;

	if (this != NULL && idPasajero > 0) {
		this->id = idPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger *this, int *idPasajero) {
	int retorno = -1;

	if (this != NULL && idPasajero != NULL) {
		*idPasajero = this->id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {
	int retorno = -1;

	if (this != NULL && apellido != NULL) {
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger *this, char *apellido) {
	int retorno = -1;

	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {
	int retorno = -1;

	if (this != NULL && tipoPasajero > 0) {
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {
	int retorno = -1;

	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger *this, float precio) {
	int retorno = -1;

	if (this != NULL && precio > 0) {
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger *this, float *precio) {
	int retorno = -1;

	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger *this, char *estadoVuelo) {
	int retorno = -1;

	if (this != NULL && estadoVuelo != NULL) {
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getEstadoVuelo(Passenger *this, char *estadoVuelo) {
	int retorno = -1;

	if (this != NULL && estadoVuelo != NULL) {
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 0;
	}

	return retorno;
}

void Passenger_printOne(Passenger *this) {
	if (this != NULL) {
		int idPasajero;
		char nombre[TAM_NAME];
		char apellido[TAM_NAME];
		float precio;
		int tipoPasajero;
		char tipoPasajeroConvertido[TAM_DATA];
		char codigoVuelo[TAM_DATA];
		char estadoVuelo[TAM_DATA];

		if (Passenger_getId(this, &idPasajero) == 0
				&& Passenger_getNombre(this, nombre) == 0
				&& Passenger_getApellido(this, apellido) == 0
				&& Passenger_getPrecio(this, &precio) == 0
				&& Passenger_getCodigoVuelo(this, codigoVuelo) == 0
				&& Passenger_getEstadoVuelo(this, estadoVuelo) == 0
				&& Passenger_getTipoPasajero(this, &tipoPasajero) == 0) {
			if (tipoPasajero == 1) {
				strcpy(tipoPasajeroConvertido, "FirstClass");
			} else {
				if (tipoPasajero == 2) {
					strcpy(tipoPasajeroConvertido, "ExecutiveClass");
				} else {
					strcpy(tipoPasajeroConvertido, "EconomyClass");
				}
			}
			printf("%-10d %-15s %-15s %-12.2f %-10s %-13s %s\n", idPasajero,
					nombre, apellido, precio, codigoVuelo,
					tipoPasajeroConvertido, estadoVuelo);
		}
	}
}
int Passenger_sortById(void *pasajeroUno, void *pasajeroDos) {
	int retorno = -1;
	int idPasajeroUno;
	int idPasajeroDos;

	if (pasajeroUno != NULL && pasajeroDos != NULL) {
		if (Passenger_getId(pasajeroUno, &idPasajeroUno) == 0
				&& Passenger_getId(pasajeroDos, &idPasajeroDos) == 0) {
			if (idPasajeroUno > idPasajeroDos) {
				retorno = 1;
			} else {
				retorno = -1;
			}
		}
	}
	return retorno;
}

int Passenger_sortByApellido(void *pasajeroUno, void *pasajeroDos) {
	int retorno = -1;
	char apellidoAuxUno[TAM_NAME];
	char nombreAuxUno[TAM_NAME];
	char apellidoAuxDos[TAM_NAME];
	char nombreAuxDos[TAM_NAME];

	if (pasajeroUno != NULL && pasajeroDos != NULL) {
		if (Passenger_getApellido(pasajeroUno, apellidoAuxUno) == 0
				&& Passenger_getApellido(pasajeroDos, apellidoAuxDos) == 0) {
			retorno = strcmp(apellidoAuxUno, apellidoAuxDos);
			if (retorno == 0
					&& Passenger_getNombre(pasajeroUno, nombreAuxUno) == 0
					&& Passenger_getNombre(pasajeroDos, nombreAuxDos) == 0) {
				retorno = strcmp(nombreAuxUno, nombreAuxDos);
				if (retorno == 0) {
					retorno = Passenger_sortById(pasajeroUno, pasajeroDos);
				}
			}
		}
	}
	return retorno;
}
int Passenger_sortByTipoPasajero(void *pasajeroUno, void *pasajeroDos) {
	int retorno = -1;
	int tipoPasajeroUno;
	int tipoPasajeroDos;

	if (pasajeroUno != NULL && pasajeroDos != NULL
			&& Passenger_getTipoPasajero(pasajeroUno, &tipoPasajeroUno) == 0
			&& Passenger_getTipoPasajero(pasajeroDos, &tipoPasajeroDos) == 0
			&& tipoPasajeroUno > tipoPasajeroDos) {
		retorno = 1;
	} else {
		if (tipoPasajeroDos > tipoPasajeroUno) {
			retorno = -1;
		} else {
			retorno = Passenger_sortByApellido(pasajeroUno, pasajeroDos);
		}
	}
	return retorno;
}

int Passenger_sortByCodigoVuelo(void *pasajeroUno, void *pasajeroDos) {
	int retorno = -1;
	char codigoVueloAuxUno[TAM_DATA];
	char codigoVueloAuxDos[TAM_DATA];
	if (pasajeroUno != NULL && pasajeroDos != NULL) {
		if (Passenger_getCodigoVuelo(pasajeroUno, codigoVueloAuxUno) == 0
				&& Passenger_getCodigoVuelo(pasajeroDos, codigoVueloAuxDos)
						== 0) {
			retorno = strcmp(codigoVueloAuxUno, codigoVueloAuxDos);
			if (retorno == 0) {
				retorno = Passenger_sortByApellido(pasajeroUno, pasajeroDos);
			}
		}
	}
	return retorno;
}
