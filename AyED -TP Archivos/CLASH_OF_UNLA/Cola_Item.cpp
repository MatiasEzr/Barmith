#include "Cola_Item.h"

void cCola(colaItem& cola){
    cola.fondo=NULL;
    cola.frente=NULL;
}

void dCola(colaItem& cola){
    Item aux;
    while(!esVacia(cola))
        desencolar(cola,aux);
}

bool esVacia(colaItem& cola){
    return (cola.fondo==NULL && cola.frente==NULL);
}

void encolar(colaItem& cola, Item dato){
    PtrNodoColaItem ptraux= new NodoColaItem;

    ptraux->dato=dato;
    ptraux->sgte=cola.fondo;

    if (cola.frente==NULL)
        cola.frente=ptraux;
    cola.fondo=ptraux;
}

void desencolar(colaItem& cola, Item& dato){
    PtrNodoColaItem ptrauxFrente = cola.frente;
    PtrNodoColaItem cursor = cola.fondo;
    dato=cola.frente->dato;

    //el if a continuacion controla el caso de que un unico elemento forme parte d e la cola
    //si hubiera mas elementos, no se activa
    if (cola.frente==cola.fondo && cola.frente!=NULL && cola.fondo!=NULL){
        cursor=NULL;
        cola.frente=NULL;
        cola.fondo=NULL;
    }
    while (cursor!=NULL){
        if (cursor->sgte==ptrauxFrente){
            cola.frente=cursor;
            cola.frente->sgte=NULL;
        }else{
        cursor = cursor->sgte;
        }
    }
    delete ptrauxFrente;
}

void elSiguiente(colaItem cola, Item& dato){
    dato=cola.frente->dato;
}

int longitud(colaItem cola){
    PtrNodoColaItem ptrCursor = cola.fondo;
    int longitud = 0;
    while ( ptrCursor != NULL ) {
        longitud++;
        ptrCursor = ptrCursor->sgte;
    }
    return longitud;
}
