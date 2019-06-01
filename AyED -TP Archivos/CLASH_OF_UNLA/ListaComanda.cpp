#include "ListaComanda.h"



ResultadoComparacion_Comanda compararDato_Comanda(DatoJ dato1, DatoJ dato2) {
    if (get_codItem(dato1) > get_codItem(dato2)) {
        return MAYOR;
    }
    else if (get_codItem(dato1) < get_codItem(dato2)) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de datos a ser creado.
*/
void crearLista_Comanda(Lista_Comanda &lista){
    lista.primero=fin();

}

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia_Comanda(Lista_Comanda &lista){
    return (primero_Comanda(lista) == fin());
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representación del fin de la lista.
*/
PtrNodoLista_Comanda fin(){
    return NULL;
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoLista_Comanda primero_Comanda(Lista_Comanda &lista){
    return lista.primero;
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoLista_Comanda siguiente_Comanda(Lista_Comanda &lista, PtrNodoLista_Comanda ptrNodo){
    if ((! listaVacia_Comanda(lista)) && (ptrNodo != fin()))
        return ptrNodo->sgte;
    else
        return fin();
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoLista_Comanda anterior_Comanda(Lista_Comanda &lista, PtrNodoLista_Comanda ptrNodo){
    PtrNodoLista_Comanda ptrPrevio = fin();
    PtrNodoLista_Comanda ptrCursor = primero_Comanda(lista);

  while (( ptrCursor != fin()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente_Comanda(lista,ptrCursor);
  }
  return ptrPrevio;


}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoLista_Comanda ultimo_Comanda(Lista_Comanda &lista){
    return anterior_Comanda(lista,fin());
}


PtrNodoLista_Comanda crearNodoLista_Comanda(DatoJ dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoLista_Comanda ptrAux = new NodoLista_Comanda;

  ptrAux->dato = dato;
  ptrAux->sgte = fin();

  return ptrAux;
}





/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoLista_Comanda adicionarPrincipio_Comanda(Lista_Comanda &lista, DatoJ dato){
 /* crea el nodo */
  PtrNodoLista_Comanda ptrNuevoNodo = crearNodoLista_Comanda(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;

}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vacía agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoLista_Comanda adicionarDespues_Comanda(Lista_Comanda &lista, DatoJ dato, PtrNodoLista_Comanda ptrNodo){
PtrNodoLista_Comanda ptrNuevoNodo = fin();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia_Comanda(lista))
    ptrNuevoNodo = adicionarPrincipio_Comanda(lista,dato);

  else {
    if (ptrNodo != fin()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista_Comanda(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;

}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoLista_Comanda adicionarFinal_Comanda(Lista_Comanda &lista, DatoJ dato){
    /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues_Comanda(lista,dato,ultimo_Comanda(lista));
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoLista_Comanda adicionarAntes_Comanda(Lista_Comanda &lista, DatoJ dato, PtrNodoLista_Comanda ptrNodo){
  PtrNodoLista_Comanda ptrNuevoNodo = fin();

  if (! listaVacia_Comanda(lista)) {
    if (ptrNodo != primero_Comanda(lista))
      ptrNuevoNodo = adicionarDespues_Comanda(lista,dato,anterior_Comanda(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio_Comanda(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato_Comanda(Lista_Comanda &lista, DatoJ &dato, PtrNodoLista_Comanda ptrNodo){
if ( (! listaVacia_Comanda(lista)) && (ptrNodo != fin()))
    ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato_Comanda(Lista_Comanda &lista, DatoJ &dato, PtrNodoLista_Comanda ptrNodo){
if ((! listaVacia_Comanda(lista)) && (ptrNodo != fin()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodo_Comanda(Lista_Comanda &lista, PtrNodoLista_Comanda ptrNodo){
PtrNodoLista_Comanda ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia_Comanda(lista)) && (ptrNodo != fin())) {

    if (ptrNodo == primero_Comanda(lista))
      lista.primero = siguiente_Comanda(lista,primero_Comanda(lista));

    else {
      ptrPrevio = anterior_Comanda( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }

}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero_Comanda(Lista_Comanda &lista){
if (! listaVacia_Comanda(lista))
    eliminarNodo_Comanda(lista,primero_Comanda(lista));
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo_Comanda(Lista_Comanda &lista){
if (! listaVacia_Comanda(lista))
    eliminarNodo_Comanda(lista,ultimo_Comanda(lista));
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarLista_Comanda(Lista_Comanda &lista){
/* retira uno a uno los nodos de la lista */
  while (! listaVacia_Comanda(lista))
    eliminarNodo_Comanda(lista,primero_Comanda(lista));
}


/******************************************************************************/
/* Definición de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearLista().
  post: si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoLista_Comanda localizarDato_Comanda(Lista_Comanda &lista , DatoJ dato){
bool encontrado = false;
   DatoJ datoCursor;
   PtrNodoLista_Comanda ptrCursor = primero_Comanda(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato_Comanda(lista,datoCursor,ptrCursor);
    if (compararDato_Comanda(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente_Comanda(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin();

  return ptrCursor;

}

/*----------------------------------------------------------------------------*/
/*
  pre : lista fue creada con crearLista() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoLista_Comanda insertarDato_Comanda(Lista_Comanda &lista, DatoJ dato){
  PtrNodoLista_Comanda ptrPrevio = primero_Comanda(lista);
  PtrNodoLista_Comanda ptrCursor = primero_Comanda(lista);
  PtrNodoLista_Comanda ptrNuevoNodo;
  DatoJ datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin()) && (! ubicado)) {

    obtenerDato_Comanda(lista,datoCursor,ptrCursor);
    if (compararDato_Comanda(datoCursor,dato) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente_Comanda(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero_Comanda(lista))
    ptrNuevoNodo = adicionarPrincipio_Comanda(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues_Comanda(lista,dato,ptrPrevio);

  return ptrNuevoNodo;


}



PtrNodoLista_Comanda insertarDato_Comanda2(Lista_Comanda &lista, DatoJ dato){
  PtrNodoLista_Comanda ptrPrevio = primero_Comanda(lista);
  PtrNodoLista_Comanda ptrCursor = primero_Comanda(lista);
  PtrNodoLista_Comanda ptrNuevoNodo;
  DatoJ datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin()) && (! ubicado)) {

    obtenerDato_Comanda(lista,datoCursor,ptrCursor);
    if (compararDato_Comanda(datoCursor,dato) == MENOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente_Comanda(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero_Comanda(lista))
    ptrNuevoNodo = adicionarPrincipio_Comanda(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues_Comanda(lista,dato,ptrPrevio);

  return ptrNuevoNodo;


}

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLista().
  post : elimina el dato de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarDato_Comanda(Lista_Comanda &lista, DatoJ dato){
 /* localiza el dato y luego lo elimina */
  PtrNodoLista_Comanda ptrNodo = localizarDato_Comanda(lista,dato);
  if (ptrNodo != fin())
    eliminarNodo_Comanda(lista,ptrNodo);

}
/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLista().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenar_Comanda(Lista_Comanda &lista){
  Lista_Comanda temp = lista;
  PtrNodoLista_Comanda ptrCursor = primero_Comanda(temp);
  crearLista_Comanda(lista);
  while ( ptrCursor != fin() ) {
        DatoJ dato;
        obtenerDato_Comanda( temp, dato, ptrCursor);
        insertarDato_Comanda( lista, dato );
        eliminarNodo_Comanda( temp, ptrCursor );
        ptrCursor = primero_Comanda(temp);
  }
  eliminarLista_Comanda( temp );

}


void reordenar_Comanda2(Lista_Comanda &lista){
  Lista_Comanda temp = lista;
  PtrNodoLista_Comanda ptrCursor = primero_Comanda(temp);
  crearLista_Comanda(lista);
  while ( ptrCursor != fin() ) {
        DatoJ dato;
        obtenerDato_Comanda( temp, dato, ptrCursor);
        insertarDato_Comanda2( lista, dato );
        eliminarNodo_Comanda( temp, ptrCursor );
        ptrCursor = primero_Comanda(temp);
  }
  eliminarLista_Comanda( temp );

}

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLista().
  post : devuelve la cantidad de datos que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitud_Comanda(Lista_Comanda &lista){
  PtrNodoLista_Comanda ptrCursor = primero_Comanda(lista);
  int longitud = 0;
  while ( ptrCursor != fin() ) {
        longitud++;
        ptrCursor = siguiente_Comanda( lista, ptrCursor);
  }
  return longitud;

}

