#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL.h>
#include <SDL_image.h>

#include <string>
using namespace std;
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/


typedef struct{
            int f;
            int c;
            int anchoCelda;
            int altoCelda;
            SDL_Texture *imagen;
            SDL_Rect rectImag;
            }Sprite;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el sprite no debe haber sido creado.
  post: el sprite queda creado y preparado para ser usado.

  sprite : estructura de datos a ser creado.
*/
void crearSprite(Sprite &sprite, int f, int c, int anchoCelda, int altoCelda, SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : el sprite debe haber sido creado.
  post: se obtiene la celda en la que se encuentra el sprite creado pasado por parametro.

  sprite : estructura de datos a ser usada.
  return: Celda en la que se encuentra el sprite.
*/

int getF(Sprite sprite);
/*----------------------------------------------------------------------------*/

/*
  pre : el sprite debe haber sido creado.
  post: se setea la celda del sprite creado pasado por parametro.

  sprite : estructura de datos a ser usada.
  celda: valor a cargar en el sprite.
*/

void setF(Sprite &sprite, int f);
/*----------------------------------------------------------------------------*/

/*
  pre : el sprite debe haber sido creado.
  post: se obtiene el item del sprite creado pasado por parametro.

  sprite : estructura de datos a ser usada.
  return: Item del sprite.
*/

int getC(Sprite sprite);
/*----------------------------------------------------------------------------*/

/*
  pre : el sprite debe haber sido creado.
  post: se setea el item del sprite creado pasado por parametro.
  sprite : estructura de datos a ser usada.
  item: valor a cargar en el sprite.
*/

void setC(Sprite &sprite, int c);
/*----------------------------------------------------------------------------*/


/*
  pre : el sprite debe haber sido creado.
  post: se obtiene la cantidad en la que se encuentra el sprite creado pasado por parametro.

  sprite : estructura de datos a ser usada.
  return: Cantidad de items que pide el sprite.
*/

int getAnchoCelda(Sprite sprite);
/*----------------------------------------------------------------------------*/

/*
  pre : el sprite debe haber sido creado.
  post: se setea la cantidad del sprite creado pasado por parametro.

  sprite : estructura de datos a ser usada.
  cantidad: valor a cargar en el sprite.
*/

void setAnchoCelda(Sprite &sprite, int AnchoCelda);
/*----------------------------------------------------------------------------*/


/*
  pre : el sprite  debe haber sido creado.
  post: el sprite queda destruido (iniciado a su origen).

  sprite : estructura de datos a ser destruido.
*/

int getAnchoCelda(Sprite sprite);
/*----------------------------------------------------------------------------*/

/*
  pre : el sprite debe haber sido creado.
  post: se setea la cantidad del sprite creado pasado por parametro.

  sprite : estructura de datos a ser usada.
  cantidad: valor a cargar en el sprite.
*/

void setAnchoCelda(Sprite &sprite, int AnchoCelda);
/*----------------------------------------------------------------------------*/


/*
  pre : el sprite  debe haber sido creado.
  post: el sprite queda destruido (iniciado a su origen).

  sprite : estructura de datos a ser destruido.
*/

void destructor(Sprite &sprite);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _SPRITE_H
