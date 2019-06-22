#include "Cola.h"

void crearCola(Cola &cola){
     cola.primero=NULL;
     cola.ultimo=NULL;
     }

void destruirCola(Cola &cola){
     while(!colaVacia(cola)){
                       desencolar(cola);
                       }           
     }

PtrNodoCola  encolar(Cola &cola,PtrDato dato){
     
if(cola.primero==NULL){
    cola.primero=crearNodoCola(dato);
    cola.ultimo=cola.primero;
    return cola.ultimo;
    }
else{
    cola.ultimo->sgte=crearNodoCola(dato);
    cola.ultimo=cola.ultimo->sgte;
    return cola.ultimo;
    }
}

PtrDato desencolar(Cola &cola){
        PtrDato devolver;
if (colaVacia(cola))
    {return NULL;}
else
  {devolver = (cola.primero)->ptrDato;}
  PtrNodoCola nodoAux;
  nodoAux = cola.primero->sgte;
  delete (cola.primero);
  cola.primero = nodoAux;
  if (cola.primero == NULL)
    {cola.ultimo = NULL;}
  return devolver;
     }
        

bool colaVacia(Cola &cola){
     bool devuelve=false;
     if(cola.ultimo==NULL){
                          devuelve=true;
                          }
     return devuelve;                     
     }

PtrNodoCola first(Cola &cola){
        PtrNodoCola busca;
        PtrNodoCola aux;
        if(!colaVacia(cola)){
                            busca=cola.ultimo->sgte;
                            aux=cola.ultimo;
                            while(busca!=NULL){
                            aux=busca;                    
                            busca=busca->sgte;
                            }
        }
        return aux;                    
        }

PtrNodoCola crearNodoCola(PtrDato dato){
            PtrNodoCola aux;
            aux=new NodoCola;
            aux->ptrDato=dato;
            aux->sgte=NULL;
            return aux;
            }
