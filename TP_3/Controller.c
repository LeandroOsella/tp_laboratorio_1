#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    FILE* f;
    if(path != NULL && pArrayListPassenger != NULL)
    {
        f = fopen(path, "r");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if(parser_PassengerFromText(f, pArrayListPassenger))
            {
                printf("Se realizo la carga del archivo\n");
                todoOk = 1;
            }
            else
            {
                printf("No se realizo la carga del archivo\n");
            }
        }
        fclose(f);
    }
    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    FILE* f;
    if(path != NULL && pArrayListPassenger != NULL)
    {
        f = fopen(path, "rb");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if(parser_PassengerFromBinary(f, pArrayListPassenger))
            {
                printf("Se realizo la carga del archivo\n");
                todoOk = 1;
            }
            else
            {
                printf("No se realizo la carga del archivo\n");
            }
        }
        fclose(f);
    }
    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id, char* path)
{
    int todoOk = 0;
    Passenger* aux = NULL;

    if(pArrayListPassenger != NULL)
    {
        if(newPassenger(aux, id, path, pArrayListPassenger))
        {
            (*id)++;
            todoOk = 1;
        }
        else
        {
            Passenger_delete(aux);
        }
    }
    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, int nextId)
{
    int todoOk = 0;
    int idx;
    int index = 0;
    int opcion = 0;
    char nombre[128];
    char apellido[128];
    float precio;
    char codigoVuelo[10];
    int tipoPasajero;
    char auxTipoPasajero[20];
    int estadoVuelo;
    char auxEstadoVuelo[20];

    Passenger* aux = NULL;

    if(pArrayListPassenger != NULL)
    {
        controller_ListPassenger(pArrayListPassenger);
        utn_getInt("Ingrese el id a modificar: ", "Error, reingrese", 1, nextId, 100, &idx);
        controller_searchPassenger(pArrayListPassenger, idx, &index);
        aux = (Passenger*) ll_get(pArrayListPassenger, index);

        printf("1-Modificar Nombre: \n");
        printf("2-Modificar Apellido: \n");
        printf("3-Modificar Precio: \n");
        printf("4-Modificar Codigo de Vuelo: \n");
        printf("5-Modificar tipo de pasajero: \n");
        printf("6-Modificar estado de vuelo: \n");
        printf("7-cancelar: \n");
        utn_getInt("Ingrese una opcion: ", "Error, reingrese", 1, 7, 10, &opcion);
        switch(opcion)
        {
        case 1:
            utn_getString("Ingrese nombre: ", "Error, reingrese", 128, 100, nombre);
            Passenger_setNombre(aux, nombre);
            break;
        case 2:
            utn_getString("Ingrese apellido: ", "Error, reingrese", 128, 100, apellido);
            Passenger_setApellido(aux, apellido);
            break;
        case 3:
            utn_getFloat("Ingrese precio(2 millones max): ", "Error, reingrese.",1,2000000,100,&precio);
            Passenger_setPrecio(aux, precio);
            break;
        case 4:
            printf("Ingrese codigo de vuelo (numeros y letras. 7 caracteres en total): ");
            fflush(stdin);
            gets(codigoVuelo);
            while(strlen(codigoVuelo)!=7)
            {
                printf("Error. Reingrese codigo de vuelo (numeros y letras pero menor a 7 caracteres): ");
                fflush(stdin);
                gets(codigoVuelo);
            }
            Passenger_setCodigoVuelo(aux, codigoVuelo);
            break;
        case 5:
            utn_getInt("Ingrese tipo de pasajero (1-FirstClass | 2-ExecutiveClass | 3-EconomyClass): ", "Error, reingrese.",1,3,100,&tipoPasajero);
            switch(tipoPasajero)
            {
            case 1:
                strcpy(auxTipoPasajero, "FirstClass");
                break;
            case 2:
                strcpy(auxTipoPasajero, "ExecutiveClass");
                break;
            case 3:
                strcpy(auxTipoPasajero, "EconomyClass");
                break;
            }
            Passenger_setTipoPasajero(aux, auxTipoPasajero);
            break;
        case 6:
            utn_getInt("Ingrese estado de vuelo (1-Aterrizado | 2-En Horario | 3-En Vuelo | 4-Demorado): ", "Error, reingrese.",1,4,100,&estadoVuelo);
            switch(estadoVuelo)
            {
            case 1:
                strcpy(auxEstadoVuelo, "Aterrizado");
                break;
            case 2:
                strcpy(auxEstadoVuelo, "En Horario");
                break;
            case 3:
                strcpy(auxEstadoVuelo, "En Vuelo");
                break;
            case 4:
                strcpy(auxEstadoVuelo, "Demorado");
                break;
            }
            Passenger_setEstadoVuelo(aux, auxEstadoVuelo);
            break;
        }

    }
    return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, int nextId)
{
    int todoOk = 0;
    int idx;
    int index = 0;
    if(pArrayListPassenger != NULL)
    {
        controller_ListPassenger(pArrayListPassenger);
        utn_getInt("Ingrese el id a eliminar: ", "Error, reingrese", 1, nextId, 100, &idx);

        controller_searchPassenger(pArrayListPassenger, idx, &index);
        if(ll_remove(pArrayListPassenger, index))
        {
            printf("Baja realizada con exito\n");
            todoOk = 1;
        }
    }
    return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int tam = 0;
    Passenger* aux = NULL;
    if(pArrayListPassenger != NULL)
    {
        printf("Id    Nombre        Apellido          Precio        Codigo       Tipo    Estado\n");

        tam = ll_len(pArrayListPassenger);
        for(int i = 0; i < tam ; i++)
        {
            aux = (Passenger*) ll_get(pArrayListPassenger, i);
            if(aux != NULL)
            {
                mostrarPasajero(aux);
                todoOk = 1;
            }
        }

    }
    return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int opcion = 0;
    if(pArrayListPassenger != NULL)
    {
        printf("1- Nombre Ascendente:\n");
        printf("2- Nombre Descendente:\n");
        printf("3- Apellido Ascendente:\n");
        printf("4- Apellido Descendente:\n");
        printf("5- Precio Ascendente:\n");
        printf("6- Precio Descendente:\n");
        printf("7- Codigo de vuelo Ascendente:\n");
        printf("8- Codigo de vuelo Descendente:\n");
        printf("9- Tipo de pasajero Ascendente:\n");
        printf("10- Tipo de pasajero Descendente:\n");
        printf("11- Estado de vuelo Ascendente:\n");
        printf("12- Estado de vuelo Descendente:\n");
        printf("13- cancelar\n");
        utn_getInt("Ingrese una opcion: ", "Error, reingrese", 1, 13, 10, &opcion);
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListPassenger, passenger_sortNombre, 1);
            todoOk = 1;
            break;
        case 2:
            ll_sort(pArrayListPassenger, passenger_sortNombre, 0);
            todoOk = 1;
            break;
        case 3:
            ll_sort(pArrayListPassenger, passenger_sortApellido, 1);
            todoOk = 1;
            break;
        case 4:
            ll_sort(pArrayListPassenger, passenger_sortApellido, 0);
            todoOk = 1;
            break;
        case 5:
            ll_sort(pArrayListPassenger, passenger_sortPrecio, 1);
            todoOk = 1;
            break;
        case 6:
            ll_sort(pArrayListPassenger, passenger_sortPrecio, 0);
            todoOk = 1;
            break;
        case 7:
            ll_sort(pArrayListPassenger, passenger_sortCodigoVuelo, 1);
            todoOk = 1;
            break;
        case 8:
            ll_sort(pArrayListPassenger, passenger_sortCodigoVuelo, 0);
            todoOk = 1;
            break;
        case 9:
            ll_sort(pArrayListPassenger, passenger_sortTipoPasajero, 1);
            todoOk = 1;
            break;
        case 10:
            ll_sort(pArrayListPassenger, passenger_sortTipoPasajero, 0);
            todoOk = 1;
            break;
        case 11:
            ll_sort(pArrayListPassenger, passenger_sortEstadoVuelo, 1);
            todoOk = 1;
            break;
        case 12:
            ll_sort(pArrayListPassenger, passenger_sortEstadoVuelo, 0);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int tam = 0;
    int id;
    char nombre[128];
    char apellido[128];
    float precio;
    char codigoVuelo[20];
    char tipoPasajero[20];
    char estadoVuelo[20];

    Passenger* aux = NULL;
    FILE* f = NULL;

    if(path != NULL && pArrayListPassenger != NULL)
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            tam = ll_len(pArrayListPassenger);
            fprintf(f,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
            for(int i = 0; i < tam; i++)
            {
                aux = (Passenger*)ll_get(pArrayListPassenger, i);
                if(aux != NULL)
                {
                    if((Passenger_getNombre(aux, nombre) &&
                            Passenger_getApellido(aux, apellido) &&
                            Passenger_getId(aux, &id) &&
                            Passenger_getPrecio(aux, &precio) &&
                            Passenger_getCodigoVuelo(aux, codigoVuelo) &&
                            Passenger_getTipoPasajero(aux, tipoPasajero) &&
                            Passenger_getEstadoVuelo(aux, estadoVuelo)))
                    {
                        fprintf(f,"%d, %s, %s, %.0f, %s, %s, %s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
                        todoOk = 1;
                    }
                }
            }
            if(todoOk == 1)
            {
                printf("Guardado con exito\n");
            }
        }
        fclose(f);
    }
    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int tam = 0;
    Passenger* aux = NULL;
    FILE* f = NULL;

    if(path != NULL && pArrayListPassenger != NULL)
    {
        f = fopen(path, "wb");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            tam = ll_len(pArrayListPassenger);
            for(int i = 0; i < tam; i++)
            {
                aux = (Passenger*)ll_get(pArrayListPassenger, i);
                if(aux != NULL)
                {
                    fwrite(aux, sizeof(Passenger), 1, f);
                    todoOk = 1;
                }
            }
            if(todoOk == 1)
            {
                printf("Guardado con exito\n");
            }
        }
    }
    return todoOk;
}

int controller_searchPassenger(LinkedList* pArrayListPassenger, int id, int* index)
{
    int todoOk = 0;
    int auxId = 0;
    int tam = 0;
    Passenger* aux = NULL;
    if(pArrayListPassenger != NULL)
    {
        tam = ll_len(pArrayListPassenger);
        for(int i = 0; i < tam; i++)
        {
            aux = ll_get(pArrayListPassenger, i);
            Passenger_getId(aux, &auxId);
            if(auxId==id)
            {
                *index = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int controller_saveAsTextId(char* path, int id)
{
    int todoOk = 0;

    FILE* f = NULL;

    if(path != NULL && id > 0)
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            fprintf(f,"%d\n", id);
            todoOk = 1;
        }
        if(todoOk == 1)
        {
            printf("Id guardado con exito\n");
        }
        fclose(f);
    }
    return todoOk;
}

