#ifndef COLA_ITEM_H
#define COLA_ITEM_H

#include "Item.h"

#ifndef NULL
#define NULL      0
#endif

/* Tipo de Estructura de los Nodos de la Cola */
struct NodoColaItem {
    Item dato; // dato almacenado
    NodoColaItem* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Cola, el cual se usa para recorrer
   la Cola y acceder a sus Datos. */
typedef NodoColaItem* PtrNodoColaItem;

/*Estructura de la Cola*/
struct colaItem{
    PtrNodoColaItem fondo,frente;
    // punteros al ultimo(mas reciente elemento) y primer(menos reciente elemento) de la cola
};

/*pre-requisitor: deve pasarse una instancia de cola sin inicializar
post-requisitos: la cola queda inicializada*/
void cCola(colaItem& cola);

/*pre-requisitor: debe pasarse una instancia de cola
post-requisitos: la cola queda desalojada de memoria*/
void dCola(colaItem& cola);

/*pre-requisitor: debe pasarse una instancia de cola
post-requisitos: se devuelve "true" si no hay elementos
                 y "false" cuando tiene elementos*/
bool esVacia(colaItem& cola);

/*pre-requisitor: debe pasarse una instancia de cola y
                una variable de tipo dato
post-requisitos: se crea un nodo con el dato pasado y
                 es agregado al fondo de la cola*/
void encolar(colaItem& cola, Item dato);

/*pre-requisitor: debe pasarse una instancia de cola y
                una variable de tipo dato para rescatar el valor del nodo
post-requisitos: el nodo al frente de la cola es quitado y
                 su valor es salvado en la variable pasada*/
void desencolar(colaItem& cola, Item& dato);

/*pre-requisitos: debe pasarse una instancia de cola
                y una variable para tomar el dato al frente de la cola
post-requisitos: el dato al frente de la cola quedara salvado en la variable pasada*/
void elSiguiente(colaItem cola, Item& dato);

/*pre-requisitos:debe pasarse una instancia de cola
post-requisitos:se devolvera la longitud de la cola*/
int longitud(colaItem cola);
#endif
