#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "menu.h"
#include "Passenger.h"
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
		setbuf(stdout,NULL);
		int opcion = 0;
	    int nextId = 1001;
	    int auxId = 1000;
	    int flagArchivo = 0;
	    int flagGuardado = 0;
	    char salir = 'n';

	    LinkedList* listaPasajeros = ll_newLinkedList();

	    validacionId(&auxId, "id.csv");

	    do
	    {
	        opcion = menu();
	        switch(opcion)
	        {
	        case 1:
	            if(auxId == 1000)
	            {
	                if(flagArchivo == 0)
	                {
	                    if(controller_loadFromText("data.csv", listaPasajeros))
	                    {
	                        flagArchivo = 1;
	                    }
	                }
	                else
	                {
	                    printf("Ya se realizo la carga del archivo anteriormente\n");
	                }
	            }
	            else
	            {
	                if(flagArchivo == 0)
	                {
	                    if(controller_loadFromText("data2.csv", listaPasajeros))
	                    {
	                        flagArchivo = 1;
	                    }
	                }
	                else
	                {
	                    printf("Ya se realizo la carga del archivo anteriormente\n");
	                }
	            }
	            break;
	        case 2:
	            if(auxId == 1000)
	            {
	                if(flagArchivo == 0)
	                {
	                    if(controller_loadFromBinary("data.bin", listaPasajeros))
	                    {
	                        flagArchivo = 1;
	                    }
	                }
	                else
	                {
	                    printf("Ya se realizo la carga del archivo anteriormente\n");
	                }
	            }
	            else
	            {
	                if(flagArchivo == 0)
	                {
	                    if(controller_loadFromBinary("data2.bin", listaPasajeros))
	                    {
	                        flagArchivo = 1;
	                    }
	                }
	                else
	                {
	                    printf("Ya se realizo la carga del archivo anteriormente\n");
	                }
	            }
	            break;
	        case 3:
	            controller_addPassenger(listaPasajeros, &nextId, "id.csv");
	            break;
	        case 4:
	            if(ll_isEmpty(listaPasajeros))
	            {
	                printf("No se puede modificar sin cargar los pasajeros\n");
	            }
	            else
	            {
	                controller_editPassenger(listaPasajeros, nextId);
	            }
	            break;
	        case 5:
	            if(ll_isEmpty(listaPasajeros))
	            {
	                printf("No se puede dar de baja sin cargar los pasajeros\n");
	            }
	            else
	            {
	                controller_removePassenger(listaPasajeros, nextId);
	            }
	            break;
	        case 6:
	            if(ll_isEmpty(listaPasajeros))
	            {
	                printf("No se puede listar sin cargar los pasajeros\n");
	            }
	            else
	            {
	                controller_ListPassenger(listaPasajeros);
	            }
	            break;
	        case 7:
	            if(ll_isEmpty(listaPasajeros))
	            {
	                printf("No se puede ordenar sin cargar los pasajeros\n");
	            }
	            else
	            {
	                controller_sortPassenger(listaPasajeros);
	            }
	            break;
	        case 8:
	            if(ll_isEmpty(listaPasajeros))
					{
						printf("No se puede grabar sin cargar los archivos anteriormente");
					}
					else
					{
						controller_saveAsText("data2.csv" , listaPasajeros);
						controller_saveAsTextId("id.csv" , nextId);
						flagGuardado = 1;
					}
	            break;
	        case 9:
	            if(ll_isEmpty(listaPasajeros))
					{
						printf("No se puede grabar sin cargar los archivos anteriormente");
					}
					else
					{
						controller_saveAsBinary("data2.bin" , listaPasajeros);
						controller_saveAsTextId("id.csv" , nextId);//guarda el id
						flagGuardado = 1;
					}
	            break;
	        case 10:
	            if(flagGuardado == 0)
	            {
	                printf("Para salir del programa primero debe realizar un guardado!!\n");
	            }
	            else
	            {
	                printf("Adios!!\n");
	                salir = 's';
	            }
	            break;
	        }
	        system("pause");
	        system("cls");
	    }while(salir != 's');

	    free(listaPasajeros);

	    return 0;
}

