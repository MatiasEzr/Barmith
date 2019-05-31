#ifndef ___LOCOMOTORA_H__
#define ___LOCOMOTORA_H__

#include "Vagon.h"

#ifndef NULL
#define NULL 0
#endif


//Contiene un vagon y un puntero al siguiente vagon.
/* Tipo de Estructura de los Nodos de la Locomotora. */
struct NodoLocomotora{
    Vagon vagon; // dato almacenado
	NodoLocomotora* siguiente;// puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Locomotora, el cual se usa para recorrer
   la ListaLocomotora y acceder a sus Datos. */
typedef NodoLocomotora* PtrNodoVagon;


//Contiene un puntero al primeroNodoVagon
typedef struct{
	PtrNodoVagon primero; // puntero al primer nodo de la lista
}Locomotora;


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

  /*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de datos a ser creado.
  */
void crearLocomotora(Locomotora &locomotora);
/*----------------------------------------------------------------------------*/

/*
  pre : lista Creada con crearLocomotora().
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return: representación del fin de la lista.
*/
PtrNodoVagon finLista();
/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLocomotora().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/

bool listaVacia(Locomotora &locomotora);

/*----------------------------------------------------------------------------*/

/*
  pre : lista Creada con crearLocomotora().
  post: devuelve el puntero al primer elemento de la lista(primer vagon), o devuelve fin() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoVagon primero(Locomotora &locomotora);
/*----------------------------------------------------------------------------*/

/*
  pre : lista Creada con crearLocomotora().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoVagon siguiente(Locomotora &locomotora, PtrNodoVagon ptrNodoVagon);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLocomotora().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoVagon anterior(Locomotora &locomotora, PtrNodoVagon ptrNodoVagon);

/*----------------------------------------------------------------------------*/

/*
  pre : lista Creada con crearLocomotora().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoVagon ultimo(Locomotora &locomotora);
/*----------------------------------------------------------------------------*/

PtrNodoVagon crearNodo(Vagon vagon);
/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLocomotora().
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  locomotora : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/

PtrNodoVagon adicionarPrincipio(Locomotora &locomotora, Vagon vagon);
/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLocomotora().
  post: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  locomotora : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar.
  ptrNodoVagon : puntero al nodo antes del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/

PtrNodoVagon adicionarAntes(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodoVagon);
/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLocomotora().
  post: agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vacía agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().

  locomotora : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar.
  ptrNodoVagon : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/

PtrNodoVagon adicionarDespues(Locomotora &locomotora, Vagon vagon, PtrNodoVagon ptrNodoVagon);
/*----------------------------------------------------------------------------*/

/*
  pre : lista creada con crearLocomotora().
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.

  locomotora : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoVagon adicionarFinal(Locomotora &locomotora, Vagon vagon);
/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLocomotora().
  post: elimina el nodo apuntado por ptrNodoVagon. No realiza accion si la lista
        esta vacia o si ptrNodoVagon apunta a fin().

  locomotora : lista sobre la cual se invoca la primitiva.
  ptrNodoVagon : puntero al nodo que se desea eliminar.
*/

void eliminarNodo(Locomotora &locomotora, PtrNodoVagon ptrNodoVagon);
/*----------------------------------------------------------------------------*/

/*
  pre : lista creada con crearLocomotora().
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(Locomotora &locomotora);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLocomotora().
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(Locomotora &locomotora);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLocomotora().
  post: elimina todos los Nodos(Vagones) de la lista quedando destruida e inhabilitada
        para su uso.

  locomotora : lista sobre la cual se invoca la primitiva.
*/
void eliminarLocomotora(Locomotora &locomotora);



/*----------------------------------------------------------------------------*/
/******************************************************************************/
/* Definición de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearLocomotora().
  post: si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoVagon localizarDato(Locomotora &locomotora , Vagon vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : lista fue creada con crearLocomotora() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoVagon insertarDato(Locomotora &locomotora, Vagon vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLocomotora().
  post : elimina el vagon de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarDato(Locomotora &locomotora, Vagon vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLocomotora().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenar(Locomotora &locomotora);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLocomotora().
  post : devuelve la cantidad de datos que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitud(Locomotora &locomotora);

#endif

