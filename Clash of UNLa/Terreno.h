#ifndef __MAPA_H__
#define __MAPA_H__

#include "Locomotora.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
    int fila;
    int columna;

    PtrNodoVagon ptrNodoVagon;
    Bandido *ptrBandido;
    Mina *ptrMina;
    Moneda *ptrMoneda;
}Terreno;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el terreno no debe haber sido creado.
  post: el terreno queda creado y preparado para ser usado.

  terreno : estructura de datos a ser creado.
*/
void crearTerreno(Terreno &mapa,int fila,int columna);
/*----------------------------------------------------------------------------*/
/*
  pre : el terreno debe haber sido creado.
  post: se dibuja el terreno

  bandido: estructura de datos a ser usado.

*/

void dibujarTerreno(SDL_Renderer* renderer,Terreno &mapa, int intervalo);
/*----------------------------------------------------------------------------*/
/*
  pre : el terreno debe haber sido creado.
  post: se destruye el terreno

  terreno: estructura de datos a ser usado.

*/
void destruirTerreno(Terreno &mapa);
#endif
