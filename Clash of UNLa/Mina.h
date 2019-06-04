#ifndef __MINA_H__
#define __MINA_H__

#include <SDL.h>
#include "Item.h"
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
    int f;
    int c;
    int ip;
    int secuencia[5];
    Item item;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Mina;
/*----------------------------------------------------------------------------*/
/*
  pre : la mina no debe haber sido creada.
  post: la mina queda creada y preparado para ser usado.

  Mina : estructura de datos a ser creado.
*/
void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCelda,
                int altoCelda, int altoSprite, int ip, int secuencia[5], Item item);
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
  post: se setea la fila donde se encontrara de la mina.

  mina: estructura de datos a ser usada.
  fila: fila donde estara la mina.
*/
void setFila(Mina &mina, int fila);

/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creada.
  post: se obtiene la columna donde se encuentra la mina.

  return : columna
*/
int getColumna(Mina *mina);

/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creada.
  post: se setea la columna donde se encontrara de la mina.

  mina: estructura de datos a ser usada.
  columna: columna donde estara la mina.
*/
void setColumna(Mina &mina, int columna);

/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creado.
  post: se obtiene el intervalo de produccion de la mina.

  return: intervalo de produccion
*/
int getIP(Mina &mina);

/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creada.
  post: se setea el intervalo de produccion de la mina.

  mina: estructura de datos a ser usada.
  IP: intervalo de produccion a setear
*/
void setIP(Mina &mina, int IP);

/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creado.
  post: se obtiene el la secuencia de produccion de la mina.

  return: secuencia de produccion
*/
int* getSecuencia(Mina &mina);

/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creada.
  post: se setea la secuencia de la mina.

  mina: estructura de datos a ser usada.
  secuencia: secuencia de la mina a setear.
*/
void setSecuencia(Mina &mina, int secuencia[5]);
/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creado.
  post: se obtiene el item que produce la mina.

  return: item
*/
Item getItem(Mina &mina);

/*----------------------------------------------------------------------------*/
/*
  pre : la mina debe haber sido creada.
  post: se setea el item de la mina.

  mina: estructura de datos a ser usada.
  item: item que producira la mina.
*/
void setItem(Mina &mina, Item item);

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

