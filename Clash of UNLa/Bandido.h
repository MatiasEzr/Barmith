#ifndef __BANDIDO_H__
#define __BANDIDO_H__

#include <SDL.h>
#include "Item.h"

/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
    int fila;
    int columna;
    Item item;
    int cantidadItem;
	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Bandido;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido no debe haber sido creado.
  post: el bandido queda creado y preparado para ser usado.

  bandido : estructura de datos a ser creado.
*/
void crearBandido(Bandido &bandido,SDL_Renderer* renderer, int fila,int columna, int anchoCelda, int altoCelda, int altoSprite,Item item, int cantidadItem);
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido  debe haber sido creado.
  post: se obtiene la fila donde se encuentra el bandido.

  return : fila
*/


int getFila(Bandido *bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido  debe haber sido creado.
  post: se obtiene la columna donde se encuentra el bandido.

  return : fila
*/

int getColumna(Bandido *bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido  debe haber sido creado.
  post: se obtiene la cantidadItem que pide el bandido

  return : cantidadItem
*/
int getCantidadItem(Bandido *bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido  debe haber sido creado.
  post: se obtiene el Item que pide el bandido

  return : Item
*/
Item getItem(Bandido *bandido);
/*----------------------------------------------------------------------------*/
///SETTERS

/*
  pre : el bandido debe haber sido creado.
  post: se dibuja el bandido

  bandido: estructura de datos a ser usado.
  renderer

*/


void dibujarBandido(Bandido *bandido,SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido debe haber sido creado.
  post: se destruye el bandido

  bandido: estructura de datos a ser usado.

*/

void destruirBandido(Bandido *bandido);
/*----------------------------------------------------------------------------*/

#endif
