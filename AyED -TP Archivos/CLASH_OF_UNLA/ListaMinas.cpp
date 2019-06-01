#include "ListaMinas.h"



ResultadoComparacion_Minas compararDato_Minas(DatoJ_m dato1, DatoJ_m dato2) {
    if (getPosX(dato1) > getPosX(dato2)) {
        return MAYOR_m;
    }
    else if (getPosX(dato1) < getPosX(dato2)) {
        return MENOR_m;
    }
    else {
        return IGUAL_m;
    }
}

ResultadoComparacion_Minas compararDato_Minas2(DatoJ_m dato1, DatoJ_m dato2) {
    if (getPosY(dato1) > getPosY(dato2)) {
        return MAYOR_m;
    }
    else if (getPosY(dato1) < getPosY(dato2)) {
        return MENOR_m;
    }
    else {
        return IGUAL_m;
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
void crearLista_Minas(Lista_Minas &lista){
    lista.primero=fin_Minas();

}

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia_Minas(Lista_Minas &lista){
    return (primero_Minas(lista) == fin_Minas());
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representación del fin de la lista.
*/
PtrNodoLista_Minas fin_Minas(){
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
PtrNodoLista_Minas primero_Minas(Lista_Minas &lista){
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
PtrNodoLista_Minas siguiente_Minas(Lista_Minas &lista, PtrNodoLista_Minas ptrNodo){
    if ((! listaVacia_Minas(lista)) && (ptrNodo != fin_Minas()))
        return ptrNodo->sgte;
    else
        return fin_Minas();
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
PtrNodoLista_Minas anterior_Minas(Lista_Minas &lista, PtrNodoLista_Minas ptrNodo){
    PtrNodoLista_Minas ptrPrevio = fin_Minas();
    PtrNodoLista_Minas ptrCursor = primero_Minas(lista);

  while (( ptrCursor != fin_Minas()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente_Minas(lista,ptrCursor);
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
PtrNodoLista_Minas ultimo_Minas(Lista_Minas &lista){
    return anterior_Minas(lista,fin_Minas());
}


PtrNodoLista_Minas crearNodoLista_Minas(DatoJ_m dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoLista_Minas ptrAux = new NodoLista_Minas;

  ptrAux->dato = dato;
  ptrAux->sgte = fin_Minas();

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
PtrNodoLista_Minas adicionarPrincipio_Minas(Lista_Minas &lista, DatoJ_m dato){
 /* crea el nodo */
  PtrNodoLista_Minas ptrNuevoNodo = crearNodoLista_Minas(dato);

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
PtrNodoLista_Minas adicionarDespues_Minas(Lista_Minas &lista, DatoJ_m dato, PtrNodoLista_Minas ptrNodo){
PtrNodoLista_Minas ptrNuevoNodo = fin_Minas();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia_Minas(lista))
    ptrNuevoNodo = adicionarPrincipio_Minas(lista,dato);

  else {
    if (ptrNodo != fin_Minas()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista_Minas(dato);

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
PtrNodoLista_Minas adicionarFinal_Minas(Lista_Minas &lista, DatoJ_m dato){
    /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues_Minas(lista,dato,ultimo_Minas(lista));
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
PtrNodoLista_Minas adicionarAntes_Minas(Lista_Minas &lista, DatoJ_m dato, PtrNodoLista_Minas ptrNodo){
  PtrNodoLista_Minas ptrNuevoNodo = fin_Minas();

  if (! listaVacia_Minas(lista)) {
    if (ptrNodo != primero_Minas(lista))
      ptrNuevoNodo = adicionarDespues_Minas(lista,dato,anterior_Minas(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio_Minas(lista,dato);
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
void colocarDato_Minas(Lista_Minas &lista, DatoJ_m &dato, PtrNodoLista_Minas ptrNodo){
if ( (! listaVacia_Minas(lista)) && (ptrNodo != fin_Minas()))
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
void obtenerDato_Minas(Lista_Minas &lista, DatoJ_m &dato, PtrNodoLista_Minas ptrNodo){
if ((! listaVacia_Minas(lista)) && (ptrNodo != fin_Minas()))
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
void eliminarNodo_Minas(Lista_Minas &lista, PtrNodoLista_Minas ptrNodo){
PtrNodoLista_Minas ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia_Minas(lista)) && (ptrNodo != fin_Minas())) {

    if (ptrNodo == primero_Minas(lista))
      lista.primero = siguiente_Minas(lista,primero_Minas(lista));

    else {
      ptrPrevio = anterior_Minas( lista , ptrNodo );
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
void eliminarNodoPrimero_Minas(Lista_Minas &lista){
if (! listaVacia_Minas(lista))
    eliminarNodo_Minas(lista,primero_Minas(lista));
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo_Minas(Lista_Minas &lista){
if (! listaVacia_Minas(lista))
    eliminarNodo_Minas(lista,ultimo_Minas(lista));
}

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarLista_Minas(Lista_Minas &lista){
/* retira uno a uno los nodos de la lista */
  while (! listaVacia_Minas(lista))
    eliminarNodo_Minas(lista,primero_Minas(lista));
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
PtrNodoLista_Minas localizarDato_Minas(Lista_Minas &lista , DatoJ_m dato){
bool encontrado = false;
   DatoJ_m datoCursor;
   PtrNodoLista_Minas ptrCursor = primero_Minas(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin_Minas()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato_Minas(lista,datoCursor,ptrCursor);
    if (compararDato_Minas(datoCursor,dato) == IGUAL_m)
      encontrado = true;
    else
      ptrCursor = siguiente_Minas(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin_Minas();

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
PtrNodoLista_Minas insertarDato_Minas(Lista_Minas &lista, DatoJ_m dato){
  PtrNodoLista_Minas ptrPrevio = primero_Minas(lista);
  PtrNodoLista_Minas ptrCursor = primero_Minas(lista);
  PtrNodoLista_Minas ptrNuevoNodo;
  DatoJ_m datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin_Minas()) && (! ubicado)) {

    obtenerDato_Minas(lista,datoCursor,ptrCursor);
    if (compararDato_Minas(datoCursor,dato) == MAYOR_m)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente_Minas(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero_Minas(lista))
    ptrNuevoNodo = adicionarPrincipio_Minas(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues_Minas(lista,dato,ptrPrevio);

  return ptrNuevoNodo;


}



PtrNodoLista_Minas insertarDato_Minas2(Lista_Minas &lista, DatoJ_m dato){
  PtrNodoLista_Minas ptrPrevio = primero_Minas(lista);
  PtrNodoLista_Minas ptrCursor = primero_Minas(lista);
  PtrNodoLista_Minas ptrNuevoNodo;
  DatoJ_m datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin_Minas()) && (! ubicado)) {

    obtenerDato_Minas(lista,datoCursor,ptrCursor);
    if (compararDato_Minas2(datoCursor,dato) == MENOR_m)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente_Minas(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero_Minas(lista))
    ptrNuevoNodo = adicionarPrincipio_Minas(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues_Minas(lista,dato,ptrPrevio);

  return ptrNuevoNodo;


}

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLista().
  post : elimina el dato de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarDato_Minas(Lista_Minas &lista, DatoJ_m dato){
 /* localiza el dato y luego lo elimina */
  PtrNodoLista_Minas ptrNodo = localizarDato_Minas(lista,dato);
  if (ptrNodo != fin_Minas())
    eliminarNodo_Minas(lista,ptrNodo);

}
/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLista().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenar_Minas(Lista_Minas &lista){
  Lista_Minas temp = lista;
  PtrNodoLista_Minas ptrCursor = primero_Minas(temp);
  crearLista_Minas(lista);
  while ( ptrCursor != fin_Minas() ) {
        DatoJ_m dato;
        obtenerDato_Minas( temp, dato, ptrCursor);
        insertarDato_Minas( lista, dato );
        eliminarNodo_Minas( temp, ptrCursor );
        ptrCursor = primero_Minas(temp);
  }
  eliminarLista_Minas( temp );

}


void reordenar_Minas2(Lista_Minas &lista){
  Lista_Minas temp = lista;
  PtrNodoLista_Minas ptrCursor = primero_Minas(temp);
  crearLista_Minas(lista);
  while ( ptrCursor != fin_Minas() ) {
        DatoJ_m dato;
        obtenerDato_Minas( temp, dato, ptrCursor);
        insertarDato_Minas2( lista, dato );
        eliminarNodo_Minas( temp, ptrCursor );
        ptrCursor = primero_Minas(temp);
  }
  eliminarLista_Minas( temp );

}

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLista().
  post : devuelve la cantidad de datos que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitud_Minas(Lista_Minas &lista){
  PtrNodoLista_Minas ptrCursor = primero_Minas(lista);
  int longitud = 0;
  while ( ptrCursor != fin_Minas() ) {
        longitud++;
        ptrCursor = siguiente_Minas( lista, ptrCursor);
  }
  return longitud;

}
