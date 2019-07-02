#ifndef __MAPA_H__
#define __MAPA_H__

#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
#include "Lista.h"
#include "Estacion.h"
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
    int fila;
    int columna;
    SDL_Texture *imagen;
    SDL_Rect rectImag;

    PtrNodoLista ptrNodoVagon;
    Bandido *ptrBandido;
    Mina *ptrMina;
    Moneda *ptrMoneda;
    Estacion *ptrEstacion;
}Terreno;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el terreno no debe haber sido creado.
  post: el terreno queda creado y preparado para ser usado.

  terreno : estructura de datos a ser creado.
*/
void crearTerreno(Terreno &terreno,int fila,int columna, int ancho, int alto, SDL_Renderer* renderer,char rand[]);
/*----------------------------------------------------------------------------*/
/*
  pre : el terreno debe haber sido creado.
  post: se dibuja el terreno

  bandido: estructura de datos a ser usado.

*/

void dibujarTerreno(Terreno &terreno, SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : el terreno debe haber sido creado.
  post: se dibuja la entidad

  bandido: estructura de datos a ser usado.

*/

void dibujarEntidad(Terreno &terreno, SDL_Renderer* renderer, int intervalo);
/*----------------------------------------------------------------------------*/
/*
  pre : el terreno debe haber sido creado.
  post: se destruye el terreno

  terreno: estructura de datos a ser usado.

*/

void setPtrMina(Terreno &terreno,Mina *mina);
void destruirTerreno(Terreno &terreno);
#endif
