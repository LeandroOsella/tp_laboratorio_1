#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "input.h"


int menu()
{
	int opcion;
	printf("*****************************************************************************\n");
	printf("                                 Menu:\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
	printf("10. Salir\n");
	printf("*****************************************************************************\n");
	utn_getInt("Ingrese una opcion: ", "Opcion no valida ", 1, 10, 5, &opcion);
	return opcion;
}


