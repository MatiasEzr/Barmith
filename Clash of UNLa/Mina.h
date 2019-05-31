#ifndef __MINA_H__
#define __MINA_H__

#include <SDL.h>
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
    int f;
    int c;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Mina;
/*----------------------------------------------------------------------------*/
/*
  pre : la mina no debe haber sido creada.
  post: la mina queda creada y preparado para ser usado.

  Mina : estructura de datos a ser creado.
*/
void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda, int altoSprite);
/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creada.
  post: se obtiene la fila donde se encuentra la mina.

  return : fila
*/

int getFila(Mina *mina);
/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creada.
  post: se obtiene la columna donde se encuentra la mina.

  return : columna
*/

int getColumna(Mina *mina);
/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creado.
  post: se dibuja la mina

  mina: estructura de datos a ser usado.
  renderer

*/
void dibujarMina(Mina *mina,SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creado.
  post: se destruye la mina

  mina: estructura de datos a ser usado.


*/
void destruirMina(Mina *mina);
/*----------------------------------------------------------------------------*/

#endif

