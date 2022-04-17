/*
 * menu.h
 *
 *  Created on: 15 abr 2022
 *      Author: leaos
 */

#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */

/** \brief muestra un menu de opciones y recibe 5 variables para actualizar valores en el menu.
 *
 * \param kilometros float kilometros ingresados.
 * \param flagKilometros int bandera para saber si se han ingresado kilometros o no.
 * \param precioAerolineas float precio de Aerolineas.
 * \param precioLatam float precio de Latam
 * \param flagPrecios int bandera para saber si se han ingresado los precios o no.
 * \return int retorna la opcion seleccionada.
 *
 */
int menu(float kilometros, int flagKilometros, float precioAerolineas, float precioLatam, int flagPrecios);
