/* 
 * File:   main.hpp
 * Author: esaezv
 *
 * Created on 3 de noviembre de 2014, 23:49
 */

#ifndef P2_HPP
#define	P2_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sElemento
{
    int DNI;
    int Edad;
    float Promedio;
};
typedef struct sElemento Alumno;

struct sRegistro
{
    Alumno * ID;
    struct sRegistro *sigNodo;
};
typedef struct sRegistro Nodo;

struct sLista
{
    Nodo * head;
    Nodo * actual;
};
typedef struct sLista Lista;

Lista * crearLista();
bool listaVacia(Lista * lista);
void primerElemento(Lista * lista);
void siguienteElemento(Lista * lista);
void ultimoElemento(Lista * lista);
void insertarNodoNuevo(Lista * lista, Nodo * n);
void liberarNodo(Nodo * n);
void liberarLista(Lista * lista);
void eliminarNodo(Lista * lista, Nodo * n);
void print(Nodo * nodo);
void recorrerLista(Lista * lista);
Nodo * buscarElemento(Lista * lista, int dni);
void modificarElemento(Lista * lista, int dni, float n_Promedio);
Alumno * crearAlumno(int dni, int edad, float promedio);

#endif	/* P2_HPP */

