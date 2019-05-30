#ifndef __MONEDA_H__
#define __MONEDA_H__
#include "Sprite.h"
#include <SDL.h>

/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
   Sprite sprite;
   int intervaloVida;
}Moneda;


int getFila(Moneda *moneda);
int getColumna(Moneda *moneda);
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
void dibujarMoneda(Moneda *moneda,SDL_Renderer* renderer);

/*
  pre : la moneda no debe haber sido creada.
  post: la moneda queda creada y preparada para ser usada.

  moneda: estructura de datos a ser creado.

*/
void crearMoneda(Moneda &moneda,Sprite &sprite, int intervaloVida);
/*----------------------------------------------------------------------------*/

/*
  pre : la mina tiene que estar creada.
  post: Se obtiene el sprite de la mina.

  mina : estructura de datos a ser usada.
  return: Sprite de la mina.
*/

Sprite getSprite(Moneda moneda);
/*----------------------------------------------------------------------------*/

/*
  pre : la moneda tiene que estar creada.
  post: Se setea el sprite de la moneda.

  moneda : estructura de datos a ser usada.

*/

bool setSprite(Moneda &moneda, Sprite &sprite);
/*----------------------------------------------------------------------------*/

/*
  pre : la moneda tiene que estar creada.
  post: Se obtiene el intervaloVida

  moneda : estructura de datos a ser usada.


*/

int getIntervaloVida(Moneda moneda);
/*----------------------------------------------------------------------------*/

/*
  pre : la moneda tiene que estar creada.
  post: Se setea el intervaloVida

  moneda : estructura de datos a ser usada.
  return:intervaloVida

*/

bool setIntervaloVida(Moneda &moneda, int intervaloVida);
/*----------------------------------------------------------------------------*/


/*
  pre : la moneda tiene que estar creada
  post: se destruye la moneda
*/

void destruirMoneda(Moneda *moneda);
/*----------------------------------------------------------------------------*/

#endif
