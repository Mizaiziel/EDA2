/* 
 * File:   main.cpp
 * Author: Miza
 *
 * Created on 29 de octubre de 2014, 18:23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sElemento
{
    int DNI;
    int Edad;
    float Promedio;
};
typedef struct sElemento* Alumno;

struct sRegistro
{
    Alumno ID;
    struct sRegistro *sigNodo;
};
typedef struct sRegistro* Nodo;

struct sLista
{
    Nodo primero;
    Nodo actual;
};
typedef struct sLista* Lista;
        
Alumno crearAlumnoRandom()
{
    Alumno a = (Alumno)malloc(sizeof(Alumno));
    float f = (float)(rand()%10)/(float)(rand()%10);
    int d = rand()%999999;
    int e = 18 + rand()%22;
    a->DNI = d;
    a->Edad = e;
    a->Promedio = f;
    return a;
}
Alumno crearAlumno()
{
    
    float f;
    int i;
    Alumno a = (Alumno)malloc(sizeof(Alumno));
    printf("Introduciremos uno por uno los datos del alumno.\n");
    printf("Primero el DNI del Alumno:\n");
    fscanf(stdin," %d",&i);
    a->DNI = i;
    printf("Ahora escriba la edad del alumno:\n");
    fscanf(stdin," %d",&i);
    a->Edad = i;
    printf("Por ultimo escriba el Promedio del alumno:\n");
    fscanf(stdin," %f",&f);
    a->Promedio = f;
    return a;
}
void printAlumno(Nodo n)
{
    printf("El alumno con DNI %d, tiene %d años y su promedio es: %f.\n",n->ID->DNI,n->ID->Edad,n->ID->Promedio);
}
Alumno alumnoVacio()
{
    Alumno n = (Alumno) malloc(sizeof(struct sElemento));
    return n;
}
Nodo nodoVacio()
{
    Nodo n = (Nodo)malloc(sizeof(struct sRegistro));
    n->ID = alumnoVacio();
    return n;
}
Lista siguienteNodo(Lista l)
{
    l->actual= l->actual->sigNodo;
    return l;
}
Lista crearLista()
{
    Lista l = (Lista)malloc(sizeof(struct sLista));
    Nodo n = nodoVacio();
    n->ID = 0;
    n->sigNodo = 0;
    l->actual = n;
    l->primero = n;
    return l;
}
bool listaVacia(Lista l)
{
    if(l->primero->ID == 0)
        return 1;
    else
        return 0;
}
Lista primerElemento(Lista l)
{
    l->actual = l->primero;
    return l;
}
Lista buscarAnterior(Lista l, Nodo n)
{
    primerElemento(l);
    while(l->actual->sigNodo != n)
        siguienteNodo(l);
    return l;
}

Lista insertarNuevoNodo(Lista l, Alumno a)
{
    Nodo n = nodoVacio();
    if(listaVacia(l) == 1)
    {
        n->ID = a;
        l->primero->ID = n->ID;
        l->primero->sigNodo = l->actual;
        l->actual = l->primero; 
    }
    else
    {
        n->ID = l->actual->ID;
        n->sigNodo = l->actual->sigNodo;
        l->actual->ID = a;
        l->actual->sigNodo = n;
    }
    return l;
}
Lista eliminarNodo(Lista l, Nodo n)
{
    if(l->actual->ID == NULL)
        printf("Ha llegado al final de la lista\n");
    else
        buscarAnterior(l, l->actual);
    l->actual->sigNodo = n->sigNodo;
    free(n);
    
    
    return l;
}

Nodo ultimoElemento(Lista l)
{
    while(l->actual->sigNodo != NULL)
        siguienteNodo(l);
    return l->actual;
}
void recorrerLista(Lista l)
{
    l = primerElemento(l);
    while(l->actual->sigNodo->ID->DNI != 0)
    {
        printAlumno(l->actual);
        l = siguienteNodo(l);
    }
}
Nodo buscarElemento(Lista l, int i)
{
    primerElemento(l);
    while(l->actual->sigNodo != NULL)
    {
        if(l->actual->ID->DNI == i)
            return l->actual;
        siguienteNodo(l);
    }
    return 0;
}
void modificarElemento(Lista l, Nodo n)
{
    char c[8];
    float f;
    int i;
    printf("Escriba que desea modificar: DNI,Edad o Promedio.\n");
    scanf("%c",c);
    if(strcmp(c, "Promedio")==0)
    {
        printf("Ahora escriba el Promedio que desea que el alumno tenga:\n");
        scanf(" %f",&f);
        n->ID->Promedio = f;
    }
    else if (strcmp(c, "Edad")==0)
    {
        printf("Ahora escriba la edad del alumno:\n");
        scanf(" %d",&i);
        n->ID->Edad = i;
    }
    else if (strcmp(c, "DNI")==0)
    {
        printf("Ahora escriba el DNI del alumno:\n");
        scanf(" %d",&i);
        n->ID->DNI = i;
    }  
    else
        printf("Error al seleccionar lo que se desea cambiar");
}
Lista cambiarOrden(Lista l )
{
    Nodo n = (Nodo)malloc(sizeof(Nodo));
    n->ID = l->actual->ID;
    l->actual->ID = l->actual->sigNodo->ID;
    l->actual->sigNodo->ID = n->ID;
    free (n);
    return l;
}
Lista ordenarLista (Lista l)
{
    primerElemento(l);
    while(l->actual->sigNodo != NULL)
    {
        if(l->actual->ID->DNI > l->actual->sigNodo->ID->DNI)
        {
            cambiarOrden(l);
            primerElemento(l);
        }    
        siguienteNodo(l);;
    }
    return l;
}
/*
 * 
 */
int main() 
{
    
    Lista l = crearLista();
    int i=0;
    //char c [256];
    fprintf(stdout,"Hola.\n ¿Cuantos alumnos desea usted incluir en la lista?\n");
    fscanf(stdin,"%d",&i);
    fprintf(stdout,"%d\n",i);
    /*printf("¿Desea introducir los datos manualmente? (En caso negativo se generaran aleatoriamente,escriba 's' para si y 'n' para no).\n");
    scanf(" %c",c);
    printf("%c\n",*c);
    if(strcmp(c, " s")==1)
    {*/
        for(int cont = 0;cont<i;cont++)    
       {     
           fprintf(stdout,"Alumno numero %d:\n",cont+1);
           Alumno n = crearAlumno();
           insertarNuevoNodo(l,n);   
       }
    /*}
    else if(strcmp(c, " n")==1)
    {
        for(int cont = 0;cont<i;cont++)    
       {     
           insertarNuevoNodo(l,crearAlumnoRandom());   
       }
    }*/
   
    fprintf(stdout,"Se han introducido con exito los siguientes alumno:\n");
    //recorrerLista(l);
	fprintf(stdout,"Elija uno de los DNIs mostrados para buscar al alumno en cuestion:\n");
    fscanf(stdin,"%d",&i);
    Nodo n = buscarElemento(l,i);
    printAlumno(n);
    free(n);
    fprintf(stdout,"Borraremos el ultimo estudiante ya que se ha dado de baja.\n");
    eliminarNodo(l,ultimoElemento(l));
    fprintf(stdout,"Ahora modificaremos los promedios de dos estudiantes que usted elegira, introduciendo sus DNIs.\n");
    fprintf(stdout,"Primer alumno para modidicar:\n");
    fscanf(stdin,"%d",&i);
    buscarElemento(l,i);
    modificarElemento(l,buscarElemento(l,i));
    fprintf(stdout,"Segundo alumno para modidicar:\n");
    fscanf(stdin,"%d",&i);
    buscarElemento(l,i);
    modificarElemento(l,buscarElemento(l,i));
    fprintf(stdout,"Para acabar le mostraremos la lista actualizada.\n");
    recorrerLista(l);
    
    
            
    return 0;
}

