#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"
#define TAM_DATA 30
#define TAM_NAME 60
#define TAM_DEC 15

typedef struct
{
	int id;
	char nombre[TAM_NAME];
	char apellido[TAM_NAME];
	float precio;
	int tipoPasajero;
	char codigoVuelo[TAM_DATA];
	char estadoVuelo[TAM_DATA];
}Passenger;

typedef struct
{
	int statusFlight;
	char desc_StatusFlight[TAM_DATA];
	int typePassenger;
	char desc_TypePassenger[TAM_DATA];
} StatusFlightAndTypePassenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precio, char* codigo, char* estado);
void Passenger_delete();

int Passenger_setId(Passenger* this,int idPasajero);
int Passenger_getId(Passenger* this,int* idPasajero);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo (Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo (Passenger* this,char* estadoVuelo);

void Passenger_printOne(Passenger* this);

int Passenger_find(LinkedList* this, int id);

int Passenger_sortById(void* pasajeroUno, void* pasajeroDos);
int Passenger_sortByApellido(void* pasajeroUno, void* pasajeroDos);
int Passenger_sortByTipoPasajero(void* pasajeroUno, void* pasajeroDos);
int Passenger_sortByCodigoVuelo(void* pasajeroUno, void* pasajeroDos);

#endif /* PASSENGER_H_ */
