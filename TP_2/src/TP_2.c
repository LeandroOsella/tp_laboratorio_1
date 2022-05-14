/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "input.h"
#include "menu.h"
#include "arrayPassenger.h"

#define TAM 2000

int main(void) {

	    setbuf(stdout,NULL);

		char salir = 'n';
	    int flagAltas = 0;
	    int nextId = 10000;

	    int id = 0;
	    char nombre[51];
	    char apellido[51];
	    float precio = 0;
	    char codigoVuelo[10];
	    int tipoPasajero = 0;
	    int estadoVuelo = 0;

	    int orden;
	    int opcion;

	    ePasajero pasajeros[TAM]; /* =
	    {
	        {10000,"leandro", "osella",100000,"a3aa4a6aaa",1,1,0},
	        {10001,"sebastian", "zrinshi",200000,"cccc34c7cc",2,2,0},
	        {10002,"felipe", "niksevich",600000,"d2d32d375d",1,3,0},
	        {10003,"valentin", "costa",400000,"b3b2bbbb5b",1,3,0},
	        {10004,"yanzon", "nicolas",100000,"e2e3ee45ee",3,2,0},
	        {10005,"telma", "malano",300000,"f3f376ff8f",2,1,0}
	    };*/

	    inicializarPasajeros(pasajeros, TAM);



	    do
	    {
	        switch(menu())
	        {
	        case 1:
	            if(altaPasajero(pasajeros, TAM,id,nombre,apellido,precio,tipoPasajero,codigoVuelo,&nextId,estadoVuelo)==0)
	            {
	                printf("Error al dar de alta!!\n");
	            }
	            else
	            {
	                printf("\nAlta exitosa!!\n");
	                flagAltas = 1;
	            }
	            break;
	        case 2:
	            if(flagAltas == 0)
	            {
	                printf("Error. Para realizar una MODIFICACION, primero debe dar de ALTA!!\n");
	            }
	            else
	            {
	                modificarPasajero(pasajeros, TAM);
	            }
	            break;
	        case 3:
	            if(flagAltas == 0)
	            {
	                printf("Error. Para realizar una BAJA, primero debe dar de ALTA!!\n");
	            }
	            else
	            {
	                bajaPasajero(pasajeros,TAM,id);
	            }
	            break;
	        case 4:
	            if(flagAltas == 0)
	            {
	                printf("Error. Para INFORMAR pasajeros, primero debe dar de ALTA!!\n");
	            }
	            else
	            {
	                printf("      ******INFORMES******\n");
	                printf("1- Listado por Apellido y Tipo de pasajero.\n");
	                printf("2- Total y promedio de precios y cuantos pasajeros que superan el promedio.\n");
	                printf("3- Listado por codigo de vuelo y vuelos ACTIVOS.\n");

	                utn_getInt("Ingrese una opcion: ", "Error. Ingrese una opcion valida.",1,4,100, &opcion);

	                switch(opcion)
	                {
	                case 1:
	                    utn_getInt("Ingrese orden (1 ASC / 0 DESC): ", "Error. Ingrese una opcion valida.",0,1,100, &orden);
	                    system("cls");
	                    ordenarPasajeros(pasajeros, TAM,orden);
	                    break;

	                case 2:
	                    calculoPromedios(pasajeros, TAM);
	                    break;

	                case 3:
	                    utn_getInt("Ingrese orden (1 ASC / 0 DESC): ", "Error. Ingrese una opcion valida.",0,1,100, &orden);
	                    system("cls");
	                    ordenarPasajerosPorCodigo(pasajeros,TAM,orden);
	                    listarPasajerosActivos(pasajeros, TAM);
	                    break;
	                }
	            }
	            break;
	        case 5:
	            salir = 's';
	            printf("Salida exitosa!!\n");
	            break;
	        }

	        system("pause");
	    }
	    while(salir != 's');

	return EXIT_SUCCESS;
}
