#ifndef __VAGON_H__
#define __VAGON_H__
#include "Item.h"
#include <SDL.h>
#include "Pila.h"
#include <string>

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
    int cantidadItem;
    string codItem; //Indica el tipoVagon a traves del item que lleva
    bool detenido;
    Pila cajas;
}Vagon;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
void setAltoSprite(Vagon &vagon,int altoSprite);
/*----------------------------------------------------------------------------*/
int getAltoSprite(Vagon &vagon);
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Vagon &vagon);
/*----------------------------------------------------------------------------*/
void setAnchoCelda(Vagon &vagon,int anchoCelda);
/*----------------------------------------------------------------------------*/
int getAltoCelda(Vagon &vagon);
/*----------------------------------------------------------------------------*/
void setAltoCelda(Vagon &vagon,int altoCelda);
/*----------------------------------------------------------------------------*/
char* getMiniatura(Vagon &vagon);
void setMiniatura(Vagon &vagon,char miniatura[]);


/*
  pre : el vagon no debe haber sido creado.
  post: el vagon queda creado y preparado para ser usado.

  Vagon: estructura de datos a ser creado.
*/
void crearVagon(Vagon &vagon,char miniatura[], int fila,int columna, char direccion[], int anchoCelda, int altoCelda, int altoSprite,int capacidad,string item);

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

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se obtiene la capacidad del vagon.

  vagon:estructura de datos a ser usado.
  return: capacidad del vagon.
*/
int getCapacidad(Vagon &vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se setea la capacidad del vagon.

  vagon:estructura de datos a ser usado
  capacidad: capacidad del vagon.
*/
void setCapacidad(Vagon &vagon, int capacidad);

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se obtiene la cantidad del item del vagon.

  vagon:estructura de datos a ser usado.
  return: cantidad del item del vagon.
*/
int getCantidadItem(Vagon &vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se setea la cantidad del item del vagon.

  vagon:estructura de datos a ser usado.
  cantidadItem: cantidad del item del vagon.
*/
void setCantidadItem(Vagon &vagon, int cantidadItem);

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se obtiene el codigo del item del vagon.

  vagon:estructura de datos a ser usado.
  return: codigo de item de vagon.
*/
string getCodItem(Vagon &vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se setea el condigo de item del vagon.

  vagon:estructura de datos a ser usado.
  codItem: codigo de item del vagon.
*/
void setCodItem(Vagon &vagon, string codItem);

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se obtienen las cajas del vagon.

  vagon:estructura de datos a ser usado.
  return: pila de cajas del vagon.
*/
Pila * getCajas(Vagon &vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : el vagon  debe haber sido creado.
  post: se setean las cajas del vagon.

  vagon:estructura de datos a ser usado.
  cajas: pila de cajas para el vagon.
*/
void setCajas(Vagon &vagon, Pila cajas);
#endif
