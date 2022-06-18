/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

#include "empleado.h"


int main(void)
{
    /*
    startTesting(1);   //ll_newLinkedList (Utilizada para crear la lista de empleados)
    startTesting(2);  // ll_len (utilizada para mostrar el tamanio del array y en mostrarEmpleados)
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add (Utilizada para agregar al emp1)
    startTesting(6);  // ll_get (Utilizada en el primer mostrar empleados)
    startTesting(7);  // ll_set (Utilizada para reemplazar al emp1 por el emp2)
    startTesting(8);  // ll_remove (Utilizada para remover al emp2 de la lista)
    startTesting(9);  // ll_clear (Utilizada para limpiar listEmpleados)
    startTesting(10); // ll_deleteLinkedList (Utilizada para eliminar la lista clonada)
    startTesting(11); // ll_indexOf (Utilizada para buscar al emp1 luego de agregarlo nuevamente con ll_add)
    startTesting(12); // ll_isEmpty (Utilizada para comprobar si la lista esta vacia o no)
    startTesting(13); // ll_push (Utilizada para colocar al emp2 en el indice 15)
    startTesting(14); // ll_pop (Utilizada para eliminar al emp2 de la posicion 15)
    startTesting(15); // ll_contains (Utilizada para determinar si el emp1 esta o no en la lista)
    startTesting(16); // ll_containsAll (Utilizada para determinar si todos los elementos de listaClonada3 estan dentro de listaClonada2)
    startTesting(17); // ll_subList (Utilizada para crear una nueva lista compuesta de 15 elementos de la lista de empleados cargada)
    startTesting(18); // ll_clone (Utilizada para clonar la listaEmpleados antes de utilizar ll_clear)
    startTesting(19); // ll_sort (Utilizada para ordenar la lista de empleados por apellido de manera ascendente)
    */

    int tamanioLinkedList;
    int indiceEmp1;
    int estadoLista;
    int contains;
    int containsAll;

    char nombreEmp1[20];
    char apellidoEmp1[20];
    int edadEmp1 = 55;
    char auxEdadEmp1[10];
    int sueldoEmp1 = 200000;
    char auxSueldoEmp1[10];

    char nombreEmp2[20];
    char apellidoEmp2[20];
    int edadEmp2 = 40;
    char auxEdadEmp2[10];
    int sueldoEmp2 = 100000;
    char auxSueldoEmp2[10];

    strcpy(nombreEmp1, "Chino");
    strcpy(apellidoEmp1, "Palacios");
    itoa(edadEmp1, auxEdadEmp1, 10);
    itoa(sueldoEmp1, auxSueldoEmp1, 10);

    strcpy(nombreEmp2, "Leandro");
    strcpy(apellidoEmp2, "Osella");
    itoa(edadEmp2, auxEdadEmp2, 10);
    itoa(sueldoEmp2, auxSueldoEmp2, 10);

    Employee* emp1 = employee_newParametros(nombreEmp1, apellidoEmp1, auxEdadEmp1, auxSueldoEmp1);
    Employee* emp2 = employee_newParametros(nombreEmp2, apellidoEmp2, auxEdadEmp2, auxSueldoEmp2);

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosClonada = NULL;
    LinkedList* listaEmpleadosClonada2 = NULL;
    LinkedList* listaEmpleadosClonada3 = NULL;
    LinkedList* nuevaLista = NULL;

    controller_loadFromText("data.csv", listaEmpleados);

    tamanioLinkedList = ll_len(listaEmpleados);
    printf("\nTamanio del LinkedList: %d\n\n", tamanioLinkedList);

    mostrarEmpleados(listaEmpleados); // muestro los empleados cargados del archivo

    system("pause");
    system("cls");

    printf("Agrego un empleado (Chino Palacios) con ll_add\n\n");

    if(ll_add(listaEmpleados, emp1)==0) //agrego un empleado
    {
        printf("Empleado agregado con exito!!\n");
    }

    printf("\nLista de empleados actualizada!!\n\n");

    mostrarEmpleados(listaEmpleados); //muestro los empleados con el emp1

    system("pause");
    system("cls");

    printf("Modifico al empleado agregado anteriormente con ll_set\n\n");

    if(ll_set(listaEmpleados, 20, emp2)==0)
    {
        printf("Empleado modificado con exito!!\n");
    }

    printf("\nLista de empleados actualizada!!\n\n");

    mostrarEmpleados(listaEmpleados); // muestro los empleados habiendo usado el ll_set para cambiar al emp1 por el emp2

    system("pause");
    system("cls");

    printf("Elimino al empleado con ll_remove\n\n");

    if(ll_remove(listaEmpleados, 20)==0) // remuevo al emp2 usando ll_remove
    {
        printf("Empleado eliminado con exito!!\n");
    }
    printf("\nLista de empleados actualizada!!\n\n");

    mostrarEmpleados(listaEmpleados); // muestro la nueva lista despues de eliminar al emp2

    system("pause");
    system("cls");

    listaEmpleadosClonada = ll_clone(listaEmpleados); // clono la lista de empleados para poder limpiarla y no perder los datos
    if(ll_clear(listaEmpleados)==0)// elimino todos los elementos de la lista
    {
        printf("\nLista vaciada con ll_clear!!\n\n");
    }

    mostrarEmpleados(listaEmpleados); //muestro que la lista se limpio de manera correcta

    system("pause");
    system("cls");

    listaEmpleadosClonada2 = ll_clone(listaEmpleadosClonada); // vuelvo a clonar la lista para poder usar el ll_delete y no perder los datos
    if(ll_deleteLinkedList(listaEmpleadosClonada)==0) // elimino la lista y sus elementos
    {
        printf("\nLista eliminada con ll_deleteLinkedList!!\n\n");
    }

    mostrarEmpleados(listaEmpleadosClonada);

    system("pause");
    system("cls");

    printf("Busqueda de Chino Palacios con ll_indexOf\n\n");
    ll_add(listaEmpleadosClonada2, emp1); // agrego al chino para buscarlo con indexOf
    indiceEmp1 = ll_indexOf(listaEmpleadosClonada2, emp1); // busco al chino con ll_indexOf
    printf("El empleado solicitado se encuentra en el indice %d\n\n", indiceEmp1); //muestro el indice donde se encuentra

    system("pause");
    system("cls");

    printf("Comprueo estado de la lista con ll_isEmpty\n");
    estadoLista = ll_isEmpty(listaEmpleadosClonada2); // cargo la variable estadoLista con lo que me retorne ll_isEmpty (-1, 0 , 1)
    if(estadoLista==0)
    {
        printf("\nLista cargada con datos!!\n\n");
    }
    else
    {
        if(estadoLista)
        {
            printf("\nLista vacia!!\n\n");
        }
        else
        {
            printf("\nError!!\n\n");
        }
    }

    system("pause");
    system("cls");

    printf("Coloco al emp2 (Leandro Osella) en una posicion deseada con ll_push\n");

    if(ll_push(listaEmpleadosClonada2, 15, emp2)==0) //coloco al empleado en el indice 15 con ll_push
    {
        printf("\nEmpleado colocado con exito!!\n\n");
    }

    mostrarEmpleados(listaEmpleadosClonada2); //muestro la lista actualizada

    system("pause");
    system("cls");

    printf("Elimino al emp2 (Leandro Osella) de la posicion 15 con ll_pop\n");
    ll_pop(listaEmpleadosClonada2, 15); //utilizo ll_pop para eliminar al empleado y retornar su direccion de memoria

    printf("\nEmpleado eliminado con exito!!\n\n");

    mostrarEmpleados(listaEmpleadosClonada2);

    system("pause");
    system("cls");

    printf("Me fijo si emp1 (Chino Palacios) se encuentra en la lista utilizando ll_contains\n");
    contains = ll_contains(listaEmpleadosClonada2, emp1); //me fijo si el emp1 esta en la lista con ll_contains
    if(contains)
    {
        printf("\nEl empleado se encuentra en la lista!!\n\n");
    }
    else
    {
        if(contains==0)
        {
            printf("\nEl empleado NO se encuentra en la lista!!\n\n");
        }
        else
        {
            printf("\nError\n\n");
        }
    }

    system("pause");
    system("cls");

    printf("Determino si todos los elementos de listaClonada3 estan dentro de listaClonada2 utilizando ll_containsAll\n");
    listaEmpleadosClonada3 = ll_clone(listaEmpleadosClonada2); //clono la lista cargada con empleados para poder utilizar ll_containsAll
    containsAll = ll_containsAll(listaEmpleadosClonada2, listaEmpleadosClonada3); //utilizo ll_containsAll para determinar si todos los elementos de una lista se encuentran dentro de otra
    if(containsAll)
    {
        printf("\nTodos los elementos estan contenidos!!\n\n");
    }
    else
    {
        if(containsAll==0)
        {
            printf("\nTodos los elementos no estan contenidos en la lista!!\n\n");
        }
        else
        {
            printf("\nError\n\n");
        }
    }

    system("pause");
    system("cls");

    printf("Creo una nueva lista utilizando ll_sublist\n\n");
    nuevaLista = ll_subList(listaEmpleadosClonada2, 0, 15); //creo una nueva lista utilizando ll_sublist
    mostrarEmpleados(nuevaLista);

    system("pause");
    system("cls");

    printf("Ordeno los empleados por apellido de manera ascendente utilizando ll_sort\n\n");
    ll_sort(listaEmpleadosClonada2, employee_CmpApellido, 1); //llamo a ll_sort pasandole employee_cmpapellido para ordenar a los empleados por apellido de manera ascendente
    mostrarEmpleados(listaEmpleadosClonada2);



return 0;
}

