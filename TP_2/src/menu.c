/*
 * menu.c
 *
 *  Created on: 14 may 2022
 *      Author: leaos
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"
#include "input.h"

int menu()
{
    int opcion;

    system("cls");
    printf("    ****  Administracion de Pasajeros  ****    \n\n");

    printf("1- ALTAS\n");
    printf("2- MODIFICAR\n");
    printf("3- BAJA\n");
    printf("4- INFORMAR\n");
    printf("5- Salir\n\n");

    utn_getInt("Ingrese una opcion: ", "Ingrese una opcion valida!!", 1, 5, 100, &opcion);

    system("cls");

    return opcion;
}

