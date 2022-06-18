#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "input.h"

Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if(newEmployee != NULL)
    {
        employee_setNombre(newEmployee, " ");
        employee_setApellido(newEmployee, " ");
        employee_setEdad(newEmployee, 0);
        employee_setSueldo(newEmployee, 0);
    }
    return newEmployee;
}

Employee* employee_newParametros(char* nombreStr, char* apellidoStr, char* edadStr, char* sueldoStr)
{
    Employee* newEmployee = NULL;
    if(nombreStr!= NULL && apellidoStr != NULL &&  edadStr!=NULL && sueldoStr!= NULL)
    {
        newEmployee = employee_new();
        if(newEmployee != NULL)
        {
            if(!(employee_setApellido(newEmployee, apellidoStr) &&
                    employee_setEdad(newEmployee, atoi(edadStr)) &&
                    employee_setNombre(newEmployee, nombreStr) &&
                    employee_setSueldo(newEmployee, atof(sueldoStr))))
            {
                employee_delete(newEmployee);
            }
        }
    }
    return newEmployee;
}

void employee_delete(Employee* this)
{
    free(this);
    this = NULL;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setApellido(Employee* this,char* apellido)
{
    int todoOk = 0;

    if(this != NULL && apellido != NULL)
    {
        strcpy(this->apellido, apellido);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getApellido(Employee* this,char* apellido)
{
    int todoOk = 0;

    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido, this->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setEdad(Employee* this,int edad)
{
    int todoOk = 0;

    if(this != NULL)
    {
        this->edad = edad;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getEdad(Employee* this,int* edad)
{
    int todoOk = 0;

    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int todoOk = 0;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int mostrarEmpleado(Employee* this)
{
    int todoOk = 0;
    char nombre[128];
    char apellido[128];
    int edad;
    float sueldo;

    if(this != NULL
            && employee_getNombre(this, nombre)
            && employee_getApellido(this, apellido)
            && employee_getEdad(this, &edad)
            && employee_getSueldo(this, &sueldo))
    {
        printf("%-16s   %-16s    %d    %.2f\n", nombre, apellido, edad, sueldo);
        todoOk = 1;
    }
    return todoOk;
}

int newEmpleado(Employee* this, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char nombre[20];
    char apellido[20];
    int edad;
    int sueldo;

    char sueldoAux[10];
    char edadAux[10];


    utn_getString("Ingrese el nombre: ","Error, reingrese: ", 20, 100, nombre);
    utn_getString("Ingrese el apellido: ","Error, reingrese: ", 20, 100, apellido);
    utn_getInt("Ingrese edad: ", "Error, reingrese: ", 18, 70, 100, &edad);
    utn_getInt("Ingrese sueldo: ", "Error, reingrese: ", 10000, 900000, 100, &sueldo);

    itoa(sueldo, sueldoAux, 10);
    itoa(edad, edadAux, 10);


    this = employee_newParametros(nombre, apellido, edadAux, sueldoAux);
    if(this != NULL)
    {
        todoOk = 1;
        ll_add(pArrayListEmployee, this);
    }
    else
    {
        employee_delete(this);
    }
    return todoOk;
}

int employee_CmpNombre(void* a, void* b)
{
    int retorno = 0;
    Employee* emp1;
    Employee* emp2;

    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        retorno = strcmp(emp1->nombre, emp2->nombre);
    }
    return retorno;
}

int employee_CmpApellido(void* a, void* b)
{
    int retorno = 0;
    Employee* emp1;
    Employee* emp2;

    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        retorno = strcmp(emp1->apellido, emp2->apellido);
    }
    return retorno;
}

int employee_CmpSueldo(void* a, void* b)
{
    int retorno = 0;
    Employee* emp1;
    Employee* emp2;

    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->sueldo > emp2->sueldo)
        {
            retorno = 1;
        }
        else
        {
            if(emp1->sueldo < emp2->sueldo)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}

int employee_CmpEdad(void* a, void* b)
{
    int retorno = 0;
    Employee* emp1;
    Employee* emp2;

    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->edad > emp2->edad)
        {
            retorno = 1;
        }
        else
        {
            if(emp1->edad < emp2->edad)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}



int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[4][128];
    int titulo = 1;
    Employee* newEmployee = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if((fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]) == 4) && titulo != 1)
            {
                newEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(newEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, newEmployee);
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

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "r");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                printf("Se realizo la carga del archivo\n");
                todoOk = 1;
            }
            else
            {
                printf("No se realizo la carga del archivo\n");
            }
        }
        fclose(f);
    }
    return todoOk;
}

int mostrarEmpleados(LinkedList* listaEmpleados)
{
    int todoOk = 0;
    Employee* aux = NULL;

    printf("Nombre             Apellido           Edad    Sueldo\n"); // muestro los empleados cargados del archivo
    for(int i=0; i<ll_len(listaEmpleados); i++)
    {
        aux = (Employee*) ll_get(listaEmpleados, i);
        mostrarEmpleado(aux);
    }
    todoOk = 1;

    return todoOk;
}
