/*
 * menu.c
 *
 *  Created on: 15 abr 2022
 *      Author: leaos
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(float kilometros, int flagKilometros, float precioAerolineas, float precioLatam, int flagPrecios)
{
    int opcion;

    system("cls");
    if(flagKilometros == 0)
    {
        printf("1- Ingresar kilometros: (km=x)\n");
    }
    else
    {
        printf("1- Ingresar kilometros: (km=%.2f)\n", kilometros);
    }
    if(flagPrecios == 0)
    {
        printf("2- Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)\n");
    }
    else
    {
        printf("2- Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam=%.2f)\n", precioAerolineas, precioLatam);
    }

    printf("3- Calcular todos los costos\n");
    printf("4- Informar Resultados\n");
    printf("5- Carga forzada de datos\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    system("cls");

    return opcion;
}


