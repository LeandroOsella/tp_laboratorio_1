/*
 * funciones.h
 *
 *  Created on: 15 abr 2022
 *      Author: leaos
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



#endif /* FUNCIONES_H_ */

/** \brief recibe un flotante y le aplic aun descuento del 10%.
 *
 * \param precio float precio recibido al cual se le aplica el descuento.
 * \return float retorna el precio con el descuento aplicado.
 *
 */
float calcularDescuentoDebito(float precio);

/** \brief recibe un flotante y le aplica un interes del 25%.
 *
 * \param precio float precio recibido al cual se le aplica el interes.
 * \return float retorna como resultado el precio con el interes aplicado.
 *
 */
float calcularInteresCredito(float precio);

/** \brief recibe un flotante (precio en pesos en este caso) y realiza una conversion a Bitcoin.
 *
 * \param precio float precio con el cual se realiza la conversion.
 * \return float retorna el valor en Bitcoin.
 *
 */
float calcularPrecioBitcoin(float precio);

/** \brief calcula el precio unitario utilizando el precio ingresado y los kilometros recorridos.
 *
 * \param precio float precio ingresado por el usuario.
 * \param kilometros float kilometros ingresados por el usuario.
 * \return float retorna el precio unitario resultado de realizar precio / kilometros.
 *
 */
float calcularPrecioUnitario(float precio, float kilometros);
