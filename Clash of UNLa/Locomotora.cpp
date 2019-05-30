#include "Locomotora.h"
#include "Vagon.h"
void crearLocomotora(Locomotora &locomotora){
    locomotora.primero=NULL;
}
bool listaVacia(Locomotora &locomotora){
    return (locomotora.primero == NULL);
}
PtrNodoVagon primero(Locomotora &locomotora){
    return locomotora.primero;
}
PtrNodoVagon siguiente(Locomotora &locomotora, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrNodoAux=NULL;
    if ((!listaVacia(locomotora)) && (ptrNodo != NULL)){
        ptrNodoAux = ptrNodo->siguiente;
    }
    return ptrNodoAux;
}
PtrNodoVagon anterior(Locomotora &locomotora, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrPrevio = NULL;
    PtrNodoVagon ptrCursor = primero(locomotora);

    while (( ptrCursor != NULL) && (ptrCursor != ptrNodo)) {
        ptrPrevio = ptrCursor;
        ptrCursor = siguiente(locomotora,ptrCursor);
    }

    return ptrPrevio;
}
PtrNodoVagon ultimo(Locomotora &locomotora){
    return anterior(locomotora,NULL);
}
PtrNodoVagon crearNodo(Vagon vagon){
    PtrNodoVagon ptrAux = new Nodo;//reservo memoria para el nodo
    ptrAux->vagon =vagon;
    ptrAux->siguiente = NULL;
    return ptrAux;
}
PtrNodoVagon adicionarPrincipio(Locomotora &locomotora, Vagon vagon){
    PtrNodoVagon ptrNuevoNodo = crearNodo(vagon);//crea el nodo
    ptrNuevoNodo->siguiente=locomotora.primero;//lo incorpora al principio de la lista
    locomotora.primero = ptrNuevoNodo;
    return ptrNuevoNodo;
}
PtrNodoVagon adicionarAntes(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrNuevoNodo = NULL;
    if(listaVacia(locomotora)){//si la lista esta vacia se adiciona al principio
        ptrNuevoNodo = adicionarPrincipio(locomotora,vagon);
    }else{
        if (ptrNodo != NULL){
            if(ptrNodo==primero(locomotora)){
                ptrNuevoNodo = adicionarPrincipio(locomotora,vagon);
            }else{
                ptrNuevoNodo = crearNodo(vagon);
                PtrNodoVagon nodoAnterior = anterior(locomotora,ptrNodo);
                nodoAnterior->siguiente=ptrNuevoNodo;
                ptrNuevoNodo->siguiente = ptrNodo;
            }
        }
    }
    return ptrNuevoNodo;
}
PtrNodoVagon adicionarDespues(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodo){
    PtrNodoVagon ptrNuevoNodo = NULL;
    if(listaVacia(locomotora)){//si la lista esta vacia se adiciona al principio
        ptrNuevoNodo = adicionarPrincipio(locomotora,vagon);
    }else{
        if (ptrNodo != NULL){
            ptrNuevoNodo = crearNodo(vagon);
            ptrNuevoNodo->siguiente = ptrNodo->siguiente;
            ptrNodo->siguiente = ptrNuevoNodo;
        }
    }
    return ptrNuevoNodo;
}
PtrNodoVagon adicionarUltimo(Locomotora &locomotora, Vagon vagon){
    return adicionarDespues(locomotora,vagon,ultimo(locomotora));
}
void eliminarNodo(Locomotora &locomotora, PtrNodoVagon ptrNodo){
    if ((!listaVacia(locomotora)) && (ptrNodo != NULL)) {//verifica que la lista no esté vacia y que ptrNodo exista
        if (ptrNodo == primero(locomotora)){//si es el primero entonces hago que la lista apunte a su siguiente
            locomotora.primero = siguiente(locomotora,ptrNodo);
        }else {
            PtrNodoVagon ptrPrevio = anterior(locomotora, ptrNodo);
            ptrPrevio->siguiente = ptrNodo->siguiente;
        }
        destruirVagon(ptrNodo->vagon);//como circulo es un TDA hay que llamar a su destructor.
        delete ptrNodo;//borro el nodo
   }
}
void destruirLocomotora(Locomotora &locomotora){
    while (!listaVacia(locomotora)){
        eliminarNodo(locomotora,primero(locomotora));
    }
}
int longitud(Locomotora &locomotora){
    PtrNodoVagon ptrCursor = primero(locomotora);
    int longitud = 0;
    while(ptrCursor != NULL) {
        longitud++;
        ptrCursor = siguiente(locomotora, ptrCursor);
    }
    return longitud;
}
