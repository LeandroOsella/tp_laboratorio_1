/*
 * input.h
 *
 *  Created on: 14 may 2022
 *      Author: leaos
 */

#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */

int isChar(char string[]);
int getString(char input[], int tam);
int SizeString(char string[]);
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);
int isInt(char input[]);
int getInt(int* input);
/** \brief
 *
 * \param mensaje[] char mensaje que informa al usuario que debe ingresar
 * \param mensajeError[] char mensaje que salta en pantalla en caso de error
 * \param min int numero minimo que puede ingresar el usuario
 * \param max int numero maximo que puede ingresar el usuario
 * \param reintentos int reintentos que tiene el usuario para ingresar numeros validos
 * \param input int* puntero a la direccion de memoria del entero que se debe ingresar
 * \return int retorna -1 si hubo error y 0 si todo OK.
 *
 */
int utn_getInt(char mensaje[], char mensajeError[], int min, int max, int reintentos, int* input);
int isFloat(char input[]);
int getFloat(float* input);
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);
