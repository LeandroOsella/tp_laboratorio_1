/*
 * arrayPassenger.h
 *
 *  Created on: 14 may 2022
 *      Author: leaos
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoVuelo[10];
    int tipoPasajero;
    int estadoVuelo;
    int isEmpty;
}ePasajero;

#endif /* ARRAYPASSENGER_H_ */

/** \brief recorre el array de pasajeros y pone en 1 el campo isEmpty de cada posicion
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo Ok y 0 si hubo algun error
 *
 */
int inicializarPasajeros(ePasajero* pasajeros, int tam);
/** \brief recorre el array de pasajeros y busca la primer posicion libre, es decir, con el campo esEmpty en 1
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param pIndex int* direccion de memoria de la variable donde se guardara la posicion libre encontrada
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int buscarLibre(ePasajero* pasajeros, int tam, int* pIndex);
/** \brief permite dar de alta un pasajero ubicandolo en la primer posicion libre del array
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param id int variable auxiliar para guardar el id
 * \param nombre[] char variable auxiliar para guardar el nombre
 * \param apellido[] char variable auxiliar para guardar el apellido
 * \param precio float variable auxiliar para guardar el precio
 * \param tipoPasajero int variable auxiliar para guardar el tipo de pasajero
 * \param codigoVuelo[] char variable auxiliar para guardar el codigo de vuelo
 * \param pNextId int* puntero a la direccion de memoria de la variable donde se encuentra el id asignado al pasajero
 * \param estadoVuelo int variable auxiliar para guardar el estado de vuelo
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int altaPasajero(ePasajero* pasajeros, int tam, int id, char nombre[], char apellido[], float precio, int tipoPasajero, char codigoVuelo[], int* pNextId, int estadoVuelo);
/** \brief muestra un pasajero
 *
 * \param unPasajero ePasajero  pasajero del array que se desea mostrar
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int mostrarPasajero(ePasajero unPasajero);
/** \brief muestra en pantalla un listado con todos los pasajeros cuyo campo isEmpty este en 0
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarPasajeros(ePasajero* pasajeros, int tam);
/** \brief muestra un menu de opciones de modificacion de pasajero y pide seleccionar una
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menuModificarPasajero();
/** \brief recorre el array de pasajeros y busca al pasajero que tenga el mismo id que le pasamos a la funcion por parametro
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param id int id del pasajero que deseamos buscar
 * \param pIndex int* puntero a variable donde se guarda el indice del pasajero encontrado. En caso de no encontrarlo pIndex se carga con -1
 * \return int retorna 1 si todo OK y 0 si hubo algun error
 *
 */
int buscarPasajero(ePasajero* pasajeros, int tam, int id, int* pIndex);
/** \brief permite realizar la modificacion de alguno de los datos de un pasajero
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int modificarPasajero(ePasajero* pasajeros, int tam);
/** \brief realiza la baja logica de un pasajero, es decir, pone su campo isEmpty en 1
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param id int id del pasajero que deseamos dar de baja
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int bajaPasajero(ePasajero* pasajeros, int tam, int id);
/** \brief recorre el array de pasajeros y los ordena por tipo de pasajero y apellido
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param orden int orden en el que queremos que se ordenen los pasajeros 1 para Ascendente 0 para Descendente
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int ordenarPasajeros(ePasajero* pasajeros, int tam, int orden);
/** \brief calcula el total de los precios de los vuelos, el promedio de precios y cuantos pasajeros superan el promedio
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int calculoPromedios(ePasajero* pasajeros, int tam);
/** \brief ordena los pasajeros por estado de vuelo y por codigo de vuelo
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param orden int orden en el que queremos que se ordenen los pasajeros 1 para Ascendente 0 para Descendente
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int ordenarPasajerosPorCodigo(ePasajero* pasajeros, int tam, int orden);
/** \brief muestra en pantalla a todos los pasajeros con vuelos activos
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarPasajerosActivos(ePasajero* pasajeros, int tam);

/** \brief permite realizar la carga forzada de un maximo de 10 pasajeros
 *
 * \param pasajeros ePasajero* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param cant int cantidad de pasajeros que se desean cargar
 * \param pId int* puntero a id que se le asigna a cada pasajero
 * \param pFlag int* puntero a bandera del alta de pasajero
 * \param pFlagCarga int* puntero a bandera de carga forzada (evita que se realize mas de 1 vez)
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int hardcodearPassengers(ePasajero* pasajeros, int tam, int cant, int* pId, int* pFlag, int* pFlagCarga);
