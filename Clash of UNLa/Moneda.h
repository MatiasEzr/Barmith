#ifndef __MONEDA_H__
#define __MONEDA_H__

#include <SDL.h>

/**
    AXIOMAS:
    F y C no pueden estar fuera de rango.
    invervaloFinal [0..IM]
    monedaVida [0..IV]
*/

/**
    Definición del tipo de dato.
*/

typedef struct{
    int fila;
    int columna;
    int monedaVida;
    int intervaloFinal;
	SDL_Texture *imagen;
    SDL_Rect rectImag;

}Moneda;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : la moneda no debe haber sido creada.
  post: la moneda queda creada y preparada para ser usada.

  moneda : estructura de datos a ser creado.
*/
void crearMoneda(Moneda &moneda,SDL_Renderer* renderer, int fila,int columna, int anchoCelda, int altoCelda, int altoSprite,int intervaloVida,int intervaloFinal);
/*----------------------------------------------------------------------------*/
/*
  pre : la moneda  debe haber sido creada.
  post: se obtiene la fila donde se encuentra la moneda.

  return : fila
*/

int getFila(Moneda *moneda);
/*----------------------------------------------------------------------------*/
/*
  pre : la moneda  debe haber sido creada.
  post: se obtiene la columna donde se encuentra la moneda.

  return : columna
*/

int getColumna(Moneda *moneda);

/*----------------------------------------------------------------------------*/

/*
  pre : la moneda tiene que estar creada.
  post: Se obtiene el intervaloVida

  moneda : estructura de datos a ser usada.


*/

int getIntervaloVida(Moneda &moneda);
/*----------------------------------------------------------------------------*/

/*
  pre : la moneda tiene que estar creada.
  post: Se setea el intervaloVida

  moneda : estructura de datos a ser usada.
  return:intervaloVida

*/

bool setIntervaloVida(Moneda &moneda, int monedaVida);
/*----------------------------------------------------------------------------*/


/*
  pre : la moneda tiene que estar creada.
  post: Se obtiene el intervaloVida

  moneda : estructura de datos a ser usada.


*/

int getIntervaloFinal(Moneda &moneda);
/*----------------------------------------------------------------------------*/

/*
  pre : la moneda tiene que estar creada.
  post: Se setea el intervaloVida

  moneda : estructura de datos a ser usada.
  return:intervaloVida

*/

bool setIntervaloFinal(Moneda &moneda, int intervaloFinal);
/*----------------------------------------------------------------------------*/
/*
  pre : la moneda debe haber sido creada.
  post: se dibuja la moneda

  moneda: estructura de datos a ser usado.
  renderer

*/


void dibujarMoneda(Moneda *moneda,SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : la moneda no debe haber sido creado.
  post: se destruye la moneda.
  moneda: estructura de datos a ser usado.

*/

void destruirMoneda(Moneda *moneda);


void reemplazarMoneda(Moneda *moneda,SDL_Renderer *renderer);

#endif
