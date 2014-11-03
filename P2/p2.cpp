#include "p2.hpp"
        
Lista * crearLista()
{
    Lista * lista = (Lista *) malloc(sizeof(Lista));
    Nodo * fantasma = (Nodo *) malloc(sizeof(Nodo));
    fantasma->ID = NULL;
    fantasma->sigNodo = NULL;
    lista->head = fantasma;
    lista->actual = lista->head;
    return lista;
}

bool listaVacia(Lista * lista)
{
    return lista->head->sigNodo == NULL;
}

void primerElemento(Lista * lista)
{
    lista->actual = lista->head->sigNodo;
}

void siguienteElemento(Lista * lista)
{
    lista->actual = lista->actual->sigNodo;
}

void ultimoElemento(Lista * lista)
{
   while (lista->actual->sigNodo != NULL) siguienteElemento(lista); 
}

void insertarNodoNuevo(Lista * lista, Nodo * n)
{
    lista->actual = lista->head;
    while(lista->actual->sigNodo != NULL) // no hemos llegado al final
    {
        Nodo * nodo = lista->actual;
        if (nodo->sigNodo->ID->DNI > n->ID->DNI)
        {
            // DNI menor
            n->sigNodo = nodo->sigNodo;
            nodo->sigNodo = n;
            return;
        }
        if (nodo->sigNodo->ID->DNI == n->ID->DNI)
        {
            // DNI ya existente
            return;
        }
        siguienteElemento(lista);
    }
    // Colocar al final
    lista->actual->sigNodo = n;
    siguienteElemento(lista);
}

void liberarNodo(Nodo * n)
{
    if (n->ID != NULL)
        free(n->ID);
    if (n != NULL)
        free(n);
}

void liberarLista(Lista * lista)
{
    lista->actual = lista->head;
    while (lista->actual->sigNodo != NULL)
    {
        Nodo * siguiente = lista->actual->sigNodo;
        liberarNodo(lista->actual);
        lista->actual = siguiente;
    }
    
    free(lista);
}

void eliminarNodo(Lista * lista, Nodo * n)
{
    lista->actual = lista->head;
    while (lista->actual->sigNodo != NULL)
    {
        if (lista->actual->sigNodo == n)
        {
            lista->actual->sigNodo = n->sigNodo;
            liberarNodo(n);
            return;
        }
        siguienteElemento(lista);
    }
}

void print(Nodo * nodo)
{
    printf("DNI: %d, Edad: %d, Nota: %f\n", nodo->ID->DNI, nodo->ID->Edad, nodo->ID->Promedio);
}

void recorrerLista(Lista * lista)
{
    lista->actual = lista->head;
    while (lista->actual->sigNodo != NULL)
    {
        print(lista->actual->sigNodo);
        siguienteElemento(lista);
    }
}

Nodo * buscarElemento(Lista * lista, int dni)
{
    lista->actual = lista->head;
    while (lista->actual->sigNodo != NULL)
    {
        if (lista->actual->sigNodo->ID->DNI == dni) return lista->actual->sigNodo;
        siguienteElemento(lista);
    }
    return NULL;
}

void modificarElemento(Lista * lista, int dni, float n_Promedio)
{
    Nodo * n = buscarElemento(lista,dni);
    if (n == NULL) return;
    n->ID->Promedio = n_Promedio;
}

Alumno * crearAlumno(int dni, int edad, float promedio)
{
    Alumno * a = (Alumno*) malloc (sizeof(Alumno));
    a->DNI = dni;
    a->Edad = edad;
    a->Promedio = promedio;
    return a;
}
