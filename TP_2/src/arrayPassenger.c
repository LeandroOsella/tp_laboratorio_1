/*
 * arrayPassenger.c
 *
 *  Created on: 14 may 2022
 *      Author: leaos
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "arrayPassenger.h"
#include "input.h"


int inicializarPasajeros(ePasajero* pasajeros, int tam)
{
    int todoOk = 0;

    if(pasajeros!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            pasajeros[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(ePasajero* pasajeros, int tam, int* pIndex)
{
    int todoOk = 0;

    if(pasajeros!=NULL && tam>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaPasajero(ePasajero* pasajeros, int tam, int id, char nombre[], char apellido[], float precio, int tipoPasajero, char codigoVuelo[], int* pNextId, int estadoVuelo)
{
    int todoOk = 0;
    int indice;

    if(pasajeros!=NULL && tam>0 && pNextId!=NULL)
    {
        if(buscarLibre(pasajeros, tam, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema!!\n\n");
            }
            else
            {
                utn_getString("Ingrese Nombre: ", "Error. Ingrese Nombre valido. ", 51, 100, nombre);

                utn_getString("Ingrese Apellido: ", "Error. Ingrese Apellido valido. ", 51, 100, pasajeros[indice].apellido);

                utn_getFloat("Ingrese precio del vuelo: ", "Error. Ingrese un precio valido. ", 1, 30000000, 100, &precio);

                printf("Ingrese codigo de vuelo (numeros y letras. 10 caracteres en total): ");
                fflush(stdin);
                gets(codigoVuelo);
                while(strlen(codigoVuelo)!=10)
                {
                    printf("Error. Reingrese codigo de vuelo (numeros y letras pero menor a 10 caracteres): ");
                    fflush(stdin);
                    gets(codigoVuelo);
                }

                printf("      ******Tipo de pasajeros******      \n\n");
                printf("1- Ejecutiva\n");
                printf("2- Premium\n");
                printf("3- Turista\n");

                utn_getInt("Ingrese tipo de pasajero: ", "Error. Ingrese un tipo de pasajero valido.",1,3,100, &tipoPasajero);

                printf("      ******Estado del Vuelo******      \n\n");
                printf("1- Activo\n");
                printf("2- Retrasado\n");
                printf("3- Cancelado\n");

                utn_getInt("Ingrese estado del vuelo: ", "Error. Ingrese un estado de vuelo valido.",1,3,100, &estadoVuelo);

                id = *pNextId;
                (*pNextId)++;

                pasajeros[indice].id = id;

                strcpy(pasajeros[indice].nombre, nombre);
                //strcpy(pasajeros[indice].apellido, apellido);

                pasajeros[indice].precio = precio;

                strcpy(pasajeros[indice].codigoVuelo, codigoVuelo);

                pasajeros[indice].tipoPasajero = tipoPasajero;

                pasajeros[indice].estadoVuelo = estadoVuelo;

                pasajeros[indice].isEmpty = 0;

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros!!\n\n");
        }
    }
    return todoOk;
}

int mostrarPasajero(ePasajero unPasajero)
{
    int todoOk = 0;

    if(unPasajero.isEmpty == 0)
    {
        printf(" %5d   %-10s  %-10s  %.2f   %-10s    %d         %d\n", unPasajero.id, unPasajero.nombre, unPasajero.apellido, unPasajero.precio, unPasajero.codigoVuelo,
               unPasajero.tipoPasajero, unPasajero.estadoVuelo);

        todoOk = 1;
    }

    return todoOk;
}

int listarPasajeros(ePasajero* pasajeros, int tam)
{
    int todoOk = 0;
    int flag = 0;
    if(pasajeros != NULL && tam>0)
    {
        printf("      ******Listado de Pasajeros******      \n\n");
        printf(" Id       Nombre     Apellido    Precio        Codigo     Tipo    Estado\n");
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0)
            {
                mostrarPasajero(pasajeros[i]);
                flag++;
                todoOk = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay pasajeros en el sistema!!\n");
        }
    }

    return todoOk;
}

int menuModificarPasajero()
{
    int opcion;

    printf("      ******Campos a Modificar******      \n");
    printf("-------------------------------------\n\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Precio\n");
    printf("4- Tipo de Pasajero\n");
    printf("5- Codigo de Vuelo\n");
    printf("6- Salir\n");

    utn_getInt("Ingrese una opcion: ", "Error. Opcion invalida.",1,6,100,&opcion);

    return opcion;
}

int buscarPasajero(ePasajero* pasajeros, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(pasajeros!=NULL && tam>0 && pIndex!=NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0 && pasajeros[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarPasajero(ePasajero* pasajeros, int tam)
{
    int todoOk = 0;
    int indice;
    char salir = 'n';

    int id;
    char auxNombre[51];
    char auxApellido[51];
    float auxPrecio;
    int auxTipoPasajero;
    char auxCodigoVuelo[10];



    if(pasajeros!=NULL && tam>0)
    {
        listarPasajeros(pasajeros, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(buscarPasajero(pasajeros,tam,id,&indice))
        {
            if(indice == -1)
            {
                printf("No hay un pasajero con id %d\n", id);
            }
            else
            {
                mostrarPasajero(pasajeros[indice]);
                do
                {
                    switch(menuModificarPasajero())
                    {
                    case 1:
                        utn_getString("Ingrese nuevo Nombre: ", "Error. Ingrese un nombre valido.",51,100,auxNombre);

                        strcpy(pasajeros[indice].nombre, auxNombre);
                        printf("Nombre modificado con exito!!\n\n");
                        break;
                    case 2:
                        utn_getString("Ingrese nuevo apellido: ", "Error. Ingrese un apellido valido.",51,100,auxApellido);

                        strcpy(pasajeros[indice].apellido, auxApellido);
                        printf("Apellido modificado con exito!!\n\n");
                        break;
                    case 3:
                        utn_getFloat("Ingrese nuevo precio: ", "Error. Ingrese un precio valido.",1,30000000,100, &auxPrecio);

                        pasajeros[indice].precio = auxPrecio;
                        printf("Precio modificado con exito!!\n\n");
                        break;
                    case 4:
                        printf("      ******Tipo de pasajeros******      \n\n");
                        printf("1- Ejecutiva\n");
                        printf("2- Premium\n");
                        printf("3- Turista\n");

                        utn_getInt("Ingrese nuevo tipo de pasajero: ", "Error. Ingrese un tipo de pasajero valido.",1,3,100,&auxTipoPasajero);

                        pasajeros[indice].tipoPasajero = auxTipoPasajero;
                        printf("Tipo de pasajero modificado con exito!!\n\n");
                        break;
                    case 5:
                        printf("Ingrese nuevo codigo de vuelo (numeros y letras. 10 caracteres en total): ");
                        fflush(stdin);
                        gets(auxCodigoVuelo);
                        while(strlen(auxCodigoVuelo)!=10)
                        {
                            printf("Error. Reingrese codigo de vuelo (numeros y letras pero menor a 10 caracteres): ");
                            fflush(stdin);
                            gets(auxCodigoVuelo);
                        }

                        strcpy(pasajeros[indice].codigoVuelo, auxCodigoVuelo);
                        printf("Codigo de vuelo modificado con exito!!\n\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
                    }
                    system("pause");
                }
                while(salir != 's');

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int bajaPasajero(ePasajero* pasajeros, int tam, int id)
{
    int todoOk = 0;
    int indice;
    char confirma;

    if(pasajeros!=NULL && tam>0)
    {
        listarPasajeros(pasajeros, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(buscarPasajero(pasajeros,tam,id,&indice))
        {
            if(indice == -1)
            {
                printf("No hay un pasajero con id %d\n", id);
            }
            else
            {
                mostrarPasajero(pasajeros[indice]);
                printf("Confirma baja?(s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario!!\n");
                }
                else
                {
                    pasajeros[indice].isEmpty = 1;
                    printf("Baja realizada con exito!!\n\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarPasajeros(ePasajero* pasajeros, int tam, int orden)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if(pasajeros!=NULL && tam>0 && orden>=0 && orden<=1)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(((pasajeros[i].tipoPasajero > pasajeros[j].tipoPasajero) && orden == 1)
                        || ((pasajeros[i].tipoPasajero < pasajeros[j].tipoPasajero) && orden == 0)
                        || ((pasajeros[i].tipoPasajero == pasajeros[j].tipoPasajero) && (strcmp(pasajeros[i].apellido, pasajeros[j].apellido)>0) && orden == 1)
                        || ((pasajeros[i].tipoPasajero == pasajeros[j].tipoPasajero) && (strcmp(pasajeros[i].apellido, pasajeros[j].apellido)<0) && orden == 0))
                {
                    auxPasajero = pasajeros[i];
                    pasajeros[i] = pasajeros[j];
                    pasajeros[j] = auxPasajero;
                }
            }
        }
        listarPasajeros(pasajeros,tam);

        todoOk = 1;
    }
    return todoOk;
}

int calculoPromedios(ePasajero* pasajeros, int tam)
{
    int todoOk = 0;
    int flag = 0;
    int cantPasajeros = 0;
    int cantPasajerosArribaPromedio = 0;
    float acumPrecio = 0;
    float promedioPrecios;

    if(pasajeros!=NULL && tam>0)
    {
        system("cls");
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0)
            {
                cantPasajeros++;
                acumPrecio = acumPrecio + pasajeros[i].precio;
                flag = 1;
            }
        }

        if(flag == 1)
        {
            promedioPrecios = acumPrecio / cantPasajeros;
        }


        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0 && pasajeros[i].precio > promedioPrecios)
            {
                cantPasajerosArribaPromedio++;
            }
        }
        printf("El total de los precios es de %.2f y El promedio es %.2f\n", acumPrecio, promedioPrecios);
        printf("La cantidad de pasajeros que superan el precio promedio es %d\n", cantPasajerosArribaPromedio);

        todoOk = 1;
    }

    return todoOk;
}

int listarPasajerosActivos(ePasajero* pasajeros, int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(pasajeros!=NULL && tam>0)
    {
        printf("      ******Listado de Pasajeros******      \n\n");
        printf(" Id       Nombre     Apellido    Precio        Codigo     Tipo    Estado\n");
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0 && pasajeros[i].estadoVuelo == 1)
            {
                mostrarPasajero(pasajeros[i]);
                flag++;
                todoOk = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay pasajeros en el sistema!!\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarPasajerosPorCodigo(ePasajero* pasajeros, int tam, int orden)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if(pasajeros!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(((pasajeros[i].estadoVuelo > pasajeros[j].estadoVuelo) && orden == 1)
                        || ((pasajeros[i].estadoVuelo < pasajeros[j].estadoVuelo) && orden == 0)
                        || ((pasajeros[i].estadoVuelo == pasajeros[j].estadoVuelo) && (strcmp(pasajeros[i].codigoVuelo, pasajeros[j].codigoVuelo)>0) && orden == 1)
                        || ((pasajeros[i].estadoVuelo == pasajeros[j].estadoVuelo) && (strcmp(pasajeros[i].codigoVuelo, pasajeros[j].codigoVuelo)<0) && orden == 0))
                {
                    auxPasajero = pasajeros[i];
                    pasajeros[i] = pasajeros[j];
                    pasajeros[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearPassengers(ePasajero* pasajeros, int tam, int cant, int* pId, int* pFlag, int* pFlagCarga)
{
    int todoOk = 0;
    int j = 0;
    int indiceLibre;

    ePasajero impostores[10] =
    {
        {00000,"leandro", "osella",100000,"a3aa4a6aaa",1,1,0},
        {00000,"sebastian", "zrinshi",200000,"cccc34c7cc",2,2,0},
        {00000,"felipe", "niksevich",600000,"d2d32d375d",1,3,0},
        {00000,"valentin", "costa",400000,"b3b2bbbb5b",1,3,0},
        {00000,"yanzon", "nicolas",100000,"e2e3ee45ee",3,2,0},
        {00000,"telma", "malano",200000,"a678hj76hg",2,1,0},
        {00000,"melisa", "lescano",100000,"cvfr34v7ic",1,2,0},
        {00000,"francesca", "ricci",600000,"g2h32k685d",2,3,0},
        {00000,"juan", "miele",140000,"c5h2llbb5b",1,3,0},
        {00000,"giuliana", "tognini",160000,"a2v3ce75em",3,1,0}
    };

    if(pasajeros!=NULL && tam>0 && pId!=NULL && cant>0 && cant<=tam)
    {
        buscarLibre(pasajeros, tam, &indiceLibre);
        for(int i=indiceLibre; i<cant+indiceLibre; i++)
        {
            pasajeros[i] = impostores[j];
            pasajeros[i].id = *pId;
            *pId = *pId + 1;
            j++;
        }
        todoOk = 1;
        *pFlag = 1;
        *pFlagCarga = 1;
    }
    return todoOk;
}

