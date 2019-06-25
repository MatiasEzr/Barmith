#ifndef BANDIDO_H__
#define BANDIDO_H__
#include <string>

#include <SDL.h>

using namespace std;


/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
    int fila;
    int columna;
    int cantidadItem;
    string codItem;
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
void crearBandido(Bandido &bandido,SDL_Renderer* renderer, int fila,int columna, int anchoCelda, int altoCelda, int altoSprite,string codItem, int cantidadItem);
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
  post: se obtiene la cantidadstring que pide el bandido

  return : cantidadstring
*/
int getCantidadItem(Bandido *bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido  debe haber sido creado.
  post: se obtiene el string que pide el bandido

  return : string
*/
string getCodItem(Bandido *bandido);
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
