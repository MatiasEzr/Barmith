#include "Locomotora.h"
#include "Vagon.h"

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearLocomotora(Locomotora &locomotora){
    locomotora.primero=NULL;
}
bool listaVacia(Locomotora &locomotora){
    return (locomotora.primero == finLista());
}

/*----------------------------------------------------------------------------*/
PtrNodoVagon finLista() {
  return NULL;
}

/*----------------------------------------------------------------------------*/

PtrNodoVagon primero(Locomotora &locomotora){
    return locomotora.primero;
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon siguiente(Locomotora &locomotora, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrNodoAux=NULL;
    if ((!listaVacia(locomotora)) && (ptrNodo != NULL)){
        ptrNodoAux = ptrNodo->siguiente;
    }
    return ptrNodoAux;
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon anterior(Locomotora &locomotora, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrPrevio = NULL;
    PtrNodoVagon ptrCursor = primero(locomotora);

    while (( ptrCursor != NULL) && (ptrCursor != ptrNodo)) {
        ptrPrevio = ptrCursor;
        ptrCursor = siguiente(locomotora,ptrCursor);
    }

    return ptrPrevio;
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon ultimo(Locomotora &locomotora){
    return anterior(locomotora,NULL);
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon crearNodoLocomotora(Vagon vagon){
    PtrNodoVagon ptrAux = new NodoLocomotora;//reservo memoria para el nodo
    ptrAux->vagon =vagon;
    ptrAux->siguiente = NULL;
    return ptrAux;
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon adicionarPrincipio(Locomotora &locomotora, Vagon vagon){
    PtrNodoVagon ptrNuevoNodoLocomotora = crearNodoLocomotora(vagon);//crea el nodo
    ptrNuevoNodoLocomotora->siguiente=locomotora.primero;//lo incorpora al principio de la lista
    locomotora.primero = ptrNuevoNodoLocomotora;
    return ptrNuevoNodoLocomotora;
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon adicionarAntes(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrNuevoNodoLocomotora = NULL;
    if(listaVacia(locomotora)){//si la lista esta vacia se adiciona al principio
        ptrNuevoNodoLocomotora = adicionarPrincipio(locomotora,vagon);
    }else{
        if (ptrNodo != NULL){
            if(ptrNodo==primero(locomotora)){
                ptrNuevoNodoLocomotora = adicionarPrincipio(locomotora,vagon);
            }else{
                ptrNuevoNodoLocomotora = crearNodoLocomotora(vagon);
                PtrNodoVagon nodoAnterior = anterior(locomotora,ptrNodo);
                nodoAnterior->siguiente=ptrNuevoNodoLocomotora;
                ptrNuevoNodoLocomotora->siguiente = ptrNodo;
            }
        }
    }
    return ptrNuevoNodoLocomotora;
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon adicionarDespues(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrNuevoNodoLocomotora = NULL;
    if(listaVacia(locomotora)){//si la lista esta vacia se adiciona al principio
        ptrNuevoNodoLocomotora = adicionarPrincipio(locomotora,vagon);
    }else{
        if (ptrNodo != NULL){
            ptrNuevoNodoLocomotora = crearNodoLocomotora(vagon);
            ptrNuevoNodoLocomotora->siguiente = ptrNodo->siguiente;
            ptrNodo->siguiente = ptrNuevoNodoLocomotora;
        }
    }
    return ptrNuevoNodoLocomotora;
}
/*----------------------------------------------------------------------------*/
PtrNodoVagon adicionarFinal(Locomotora &locomotora, Vagon vagon){
    return adicionarDespues(locomotora,vagon,ultimo(locomotora));
}
/*----------------------------------------------------------------------------*/


void eliminarNodo(Locomotora &locomotora, PtrNodoVagon ptrNodoVagon){
    if ((!listaVacia(locomotora)) && (ptrNodoVagon != NULL)) {//verifica que la lista no esté vacia y que ptrNodo exista
        if (ptrNodoVagon == primero(locomotora)){//si es el primero entonces hago que la lista apunte a su siguiente
            locomotora.primero = siguiente(locomotora,ptrNodoVagon);
        }else {
            PtrNodoVagon ptrPrevio = anterior(locomotora, ptrNodoVagon);
            ptrPrevio->siguiente = ptrNodoVagon->siguiente;
        }
        destruirVagon(ptrNodoVagon->vagon);//como circulo es un TDA hay que llamar a su destructor.
        delete ptrNodoVagon;//borro el nodo
   }
}
/*----------------------------------------------------------------------------*/

void eliminarNodoPrimero(Locomotora &locomotora) {

  if (! listaVacia(locomotora))
    eliminarNodo(locomotora,primero(locomotora));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(Locomotora &locomotora) {

  if (! listaVacia(locomotora))
    eliminarNodo(locomotora,ultimo(locomotora));
}

/*----------------------------------------------------------------------------*/
void eliminarLocomotora(Locomotora &locomotora){
    while (!listaVacia(locomotora)){
        eliminarNodo(locomotora,primero(locomotora));
    }
}
/*----------------------------------------------------------------------------*/
int longitud(Locomotora &locomotora){
    PtrNodoVagon ptrCursor = primero(locomotora);
    int longitud = 0;
    while(ptrCursor != NULL) {
        longitud++;
        ptrCursor = siguiente(locomotora, ptrCursor);
    }
    return longitud;
}

