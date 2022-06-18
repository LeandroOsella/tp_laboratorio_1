#include "../inc/LinkedList.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    char nombre[20];
    char apellido[20];
    int edad;
    float sueldo;
}Employee;

#endif // EMPLEADO_H_INCLUDED

// SETTER Y GETTERS

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setApellido(Employee* this,char* apellido);
int employee_getApellido(Employee* this,char* apellido);

int employee_setEdad(Employee* this,int edad);
int employee_getEdad(Employee* this,int* edad);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

//*******************************************************//
// Employee Cmp

int employee_CmpNombre(void* a, void* b);
int employee_CmpApellido(void* a, void* b);
int employee_CmpEdad(void* a, void* b);
int employee_CmpSueldo(void* a, void* b);

//*****************************************//

Employee* employee_new();
Employee* employee_newParametros(char* nombreStr, char* apellidoStr, char* edadStr, char* sueldoStr);
void employee_delete(Employee* this);
int mostrarEmpleado(Employee* this);
int mostrarEmpleados(LinkedList* listaEmpleados);
int newEmpleado(Employee* this, LinkedList* pArrayListEmployee);


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
