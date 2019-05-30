#ifndef __MINA_H__
#define __MINA_H__

#include "Sprite.h"
#include "Item.h"
#include <SDL.h>

/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
    Sprite sprite;
    Item item;
    int intervaloProduccion;
    int secuencia[10];
    //pila cajas
}Mina;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
int getFila(Mina *mina);
int getColumna(Mina *mina);
void dibujarMina(Mina *mina,SDL_Renderer* renderer);
/*

  pre : la mina no debe haber sido creada.
  post: la mina queda creada y preparada para ser usada.

  mina: estructura de datos a ser creado.

*/
void crearMina(Mina &mina,Sprite &sprite, Item &item, int intervaloProduccion);
/*----------------------------------------------------------------------------*/

/*
  pre : la mina tiene que estar creada.
  post: Se obtiene el sprite de la mina.

  mina : estructura de datos a ser usada.
  return: Sprite de la mina.
*/

Sprite getSprite(Mina mina);
/*----------------------------------------------------------------------------*/

/*
  pre : la mina tiene que estar creada.
  post: Se setea el sprite de la mina.

  mina : estructura de datos a ser usada.

*/

bool setSprite(Mina &mina, Sprite &sprite);
/*----------------------------------------------------------------------------*/

/*
  pre : la mina tiene que estar creada.
  post: se obtiene el item de la mina creado pasado por parametro.

  bandido : estructura de datos a ser usada.
  return: Item de la mina.
*/

Item getItem(Mina mina);
/*----------------------------------------------------------------------------*/

/*
  pre : la mina tiene que estar creada.
  post: se setea el item de la mina creado pasado por parametro.
  bandido : estructura de datos a ser usada.
  item: valor a cargar en la mina.
*/

bool setItem(Mina &mina, Item &item);
/*----------------------------------------------------------------------------*/

/*
  pre : la mina tiene que estar creada
  post: se destruye la mina
*/

void destruirMina(Mina *mina);
/*----------------------------------------------------------------------------*/

#endif

/*
  pre : la mina tiene que estar creada
  post: se dibuja la mina



void dibujarMina(Mina *mina,Sprite *sprite);
/*----------------------------------------------------------------------------*/
