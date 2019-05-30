#ifndef __CARAVANA_H__
#define __CARAVANA_H__

#include "Vagon.h"

#ifndef NULL
#define NULL 0
#endif

struct Nodo{
    Vagon vagon;
	Nodo* siguiente;
};
typedef Nodo* PtrNodoVagon;

typedef struct{
	PtrNodoVagon primero;
}Locomotora;

void crearLocomotora(Locomotora &locomotora);
bool listaVacia(Locomotora &locomotora);
PtrNodoVagon primero(Locomotora &locomotora);
PtrNodoVagon siguiente(Locomotora &locomotora, PtrNodoVagon ptrNodoVagon);
PtrNodoVagon anterior(Locomotora &locomotora, PtrNodoVagon ptrNodoVagon);
PtrNodoVagon ultimo(Locomotora &locomotora);
PtrNodoVagon crearNodo(Vagon vagon);
PtrNodoVagon adicionarPrincipio(Locomotora &locomotora, Vagon vagon);
PtrNodoVagon adicionarAntes(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodoVagon);
PtrNodoVagon adicionarDespues(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodoVagon);
PtrNodoVagon adicionarUltimo(Locomotora &locomotora, Vagon vagon);
void eliminarNodo(Locomotora &locomotora, PtrNodoVagon ptrNodoVagon);
void destruirLocomotora(Locomotora &locomotora);
int longitud(Locomotora &locomotora);
/*----------------------------------------------------------------------------*/

#endif

