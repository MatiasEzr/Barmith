#ifndef _COLA_H_
#define _COLA_H_

#ifndef NULL
#define NULL  0
#endif

typedef void *PtrDato;
typedef struct NodoCola{
       PtrDato ptrDato;
       NodoCola *sgte;
       };
typedef NodoCola *PtrNodoCola;
typedef struct{
        PtrNodoCola primero;
        PtrNodoCola ultimo;
        }Cola;  


PtrNodoCola crearNodoCola(PtrDato dato);


/*Funciones Primitivas*/
/*
   Crea la cola vacia
   Pre: La cola no debe haber sido creada
   Post: Se crea la cola
*/
void crearCola(Cola &cola);
/*
   Destruye la cola
   Pre:La cola debe haber sido creada
   Post: Se eliminan los nodos de la cola
*/
void destruirCola(Cola &cola);
/*
   Ingresa un nodo a la cola
   Pre:La cola debe haber sido creada
   Post: Se encola un nodo con un puntero a un dato generico
*/
PtrNodoCola encolar(Cola &cola,PtrDato dato);
/*
   Elimina el primer nodo y devuelve el puntero al dato del mismo
   Pre: La cola debe haber sido creada
   Post: Elimina el primer nodo
*/
PtrDato desencolar(Cola &cola);
/*
   Se fija si la cola se encuentra vacia
   Pre: La cola debe haber sido creada
   Post: Devuelve true si la cola esta vacia
*/
bool colaVacia(Cola &cola);
/*
   Recorre la cola hasta el primer elemento
   Pre:La cola debe haber sido creada
   Post: Devuelve un puntero al primer elemento de la cola
*/
PtrNodoCola first(Cola &cola);


#endif
     
