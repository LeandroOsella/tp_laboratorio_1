#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED



#endif // INPUT_H_INCLUDED

int isChar(char string[]);
int getString(char input[], int tam);
int SizeString(char string[]);
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);
int isInt(char input[]);
int getInt(int* input);
int utn_getInt(char mensaje[], char mensajeError[], int min, int max, int reintentos, int* input);
int isFloat(char input[]);
int getFloat(float* input);
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);
