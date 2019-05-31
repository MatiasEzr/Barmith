#ifndef __VAGON_H__
#define __VAGON_H__
#include "Item.h"
#include <SDL.h>

/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
    char miniatura[3];
    int fila;
    int columna;
    char direccion[4];
    int anchoCelda;
    int altoCelda;
    int altoSprite;
	SDL_Texture *imagen;
    SDL_Rect rectImag;
    int capacidad; //5kg*cantidad_monedas
    Item item; //Indica el tipoVagon a traves del item que lleva
}Vagon;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon no debe haber sido creado.
  post: el vagon queda creado y preparado para ser usado.

  Vagon: estructura de datos a ser creado.
*/
void crearVagon(Vagon &vagon,char miniatura[], int fila,int columna, char direccion[], int anchoCelda, int altoCelda, int altoSprite,int capacidad,Item item);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se obtiene la fila donde se encuentra el vagon.

  return : fila
*/

int getFila(Vagon &vagon);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se setea la fila donde se encuentra el vagon.

  vagon: estructura de datos a ser usada.
  desplazamiento:
*/
void setFila(Vagon &vagon,int desplazamiento);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se obtiene la columna donde se encuentra el vagon.

  return : columna
*/
int getColumna(Vagon &vagon);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se setea la columna donde se encuentra el vagon.

  vagon: estructura de datos a ser usada.
  desplazamiento:
*/
void setColumna(Vagon &vagon,int desplazamiento);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon debe haber sido creado.
  post: se dibuja el vagon

  vagon: estructura de datos a ser usado.
  renderer

*/

void dibujarVagon(Vagon &vagon,SDL_Renderer* renderer,int intervalo);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon debe haber sido creado.
  post: se destruye el vagon

  vagon: estructura de datos a ser usado.

*/
void destruirVagon(Vagon &vagon);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se obtiene la  direccion del vagon.

  return : direccion
*/

char* getDireccion(Vagon &vagon);
/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se setea la direccion del vagon.

  vagon:estructura de datos a ser usado
  direccion: datos a cargar
*/
void setDireccion(Vagon &vagon,char direccion[]);



#endif
