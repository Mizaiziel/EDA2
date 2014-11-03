/* 
 * File:   main.cpp
 * Author: Miza
 *
 * Created on 29 de octubre de 2014, 18:23
 */

#include "p2.hpp"

int main() 
{
    int num_alumnos = 0;
    printf("Inserte el número de alumnos:\n");
    scanf("%d", &num_alumnos);
    
    Lista * lista = crearLista();
    
    int num_insertados = 0;
    while (num_insertados < num_alumnos)
    {
        printf("Alumno num %d\n", num_insertados + 1);
        int dni, edad;
        float promedio;
        printf("DNI:");
        scanf("%d",&dni);
        printf("Edad:");
        scanf("%d",&edad);
        printf("Promedio:");
        scanf("%f",&promedio);
        Alumno * a = crearAlumno(dni,edad,promedio);
        Nodo * n = (Nodo*) malloc (sizeof(Nodo));
        n->ID = a;
        insertarNodoNuevo(lista, n);
        printf("Alumno insertado..\n");
        num_insertados++;
    }
    
    printf("Buscar estudiante - Inserte DNI:");
    int dni = -1;
    scanf("%d", &dni);
    Nodo * n = buscarElemento(lista, dni);
    if (n == NULL) printf("Alumno con DNI %d no encontrado.\n", dni);
    else print(n);

    printf("Imprimiendo datos de todos los estudiantes:\n");
    recorrerLista(lista);
    
    printf("Eliminando último alumno..\n");
    ultimoElemento(lista);
    eliminarNodo(lista, lista->actual);
    
    printf("Modificar un estudiante:\n");
    printf("DNI:");
    scanf("%d", &dni);
    printf("Nuevo promedio:");
    float promedio = 0;
    scanf("%f", &promedio);
    modificarElemento(lista, dni, promedio);
    printf("Modificar otro estudiante:\n");
    printf("DNI:");
    scanf("%d", &dni);
    printf("Nuevo promedio:");
    promedio = 0;
    scanf("%f", &promedio);
    modificarElemento(lista, dni, promedio);

    printf("Imprimiendo datos de todos los estudiantes:\n");
    recorrerLista(lista);
    
    return 0;
}

