/*
 * funciones.c
 *
 *  Created on: 15 abr 2022
 *      Author: leaos
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float calcularDescuentoDebito(float precio)
{
    float resultado;
    float descuento;

    descuento = (float) precio * 10 / 100;
    resultado = precio - descuento;

    return resultado;
}

float calcularInteresCredito(float precio)
{
    float resultado;
    float interes;

    interes = (float) precio * 25 / 100;
    resultado = precio + interes;

    return resultado;
}

float calcularPrecioBitcoin(float precio)
{
    float precioBitcoin;

    precioBitcoin = (float) precio / 4606954.55;

    return precioBitcoin;
}

float calcularPrecioUnitario(float precio, float kilometros)
{
    float resultado;

    resultado = (float) precio / kilometros;

    return resultado;
}


