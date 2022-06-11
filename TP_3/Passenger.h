/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char estadoVuelo[20];
}Passenger;

/** \brief abre un archivo en modo lectura y carga el valor leido en una variable
 *
 * \param id int* variable donde se carga el id leido del archivo
 * \param path char* nombre del archivo
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int validacionId(int* id, char* path);

/** \brief Pide espacio en memoria para un pasajero y lo inicializa
 *
 * \return Passenger* retorna al nuevo pasajero
 *
 */
Passenger* Passenger_new();
/** \brief permite realizar el alta de un pasajero y asignarle sus datos
 *
 * \param idStr char* id del pasajero
 * \param nombreStr char* nombre del pasajero
 * \param apellidoStr char* apellido del pasajero
 * \param precioStr char* precio del vuelo
 * \param codigoDeVueloStr char* codigo del vuelo
 * \param tipoPasajeroStr char* tipo de pasajero
 * \param estadoVueloStr char* estado del vuelo
 * \return Passenger* retorna al pasajero
 *
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoDeVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int newPassenger(Passenger* this, int* id, char* path, LinkedList* pArrayListPassenger);
int mostrarPasajero(Passenger* this);

int passenger_sortNombre(void* a, void* b);
int passenger_sortApellido(void* a, void* b);
int passenger_sortPrecio(void* a, void* b);
int passenger_sortCodigoVuelo(void* a, void* b);
int passenger_sortTipoPasajero(void* a, void* b);
int passenger_sortEstadoVuelo(void* a, void* b);



#endif /* PASSENGER_H_ */
