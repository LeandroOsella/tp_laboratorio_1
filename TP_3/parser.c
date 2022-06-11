#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
	char buffer[7][128];
	int titulo = 1;
	Passenger* newPassenger = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			if((fscanf(pFile, "%[^,], %[^,], %[^,], %[^,],%[^,], %[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3], buffer[4], buffer[5], buffer[6]) == 7) && titulo != 1)
			{
				newPassenger = Passenger_newParametros(buffer[0],buffer[1],buffer[2],buffer[3], buffer[4], buffer[5], buffer[6]);
				if(newPassenger != NULL)
				{
					ll_add(pArrayListPassenger, newPassenger);
					todoOk = 1;
				}
			}
			else
			{
				titulo = 0;
			}
		}
	}
    return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    Passenger* aux = NULL;
    if(pFile!=NULL && pArrayListPassenger!=NULL)
    {
        do
        {
        	aux = Passenger_new();
            if(aux!=NULL)
            {
                if(fread(aux,sizeof(Passenger),1,pFile))
                {
                    ll_add(pArrayListPassenger,aux);
                    todoOk = 1;
                }
                else
                {
                    Passenger_delete(aux);
                }
            }
        }while(!feof(pFile));
    }
    return todoOk;
}
