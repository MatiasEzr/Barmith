#ifndef _BANDIDO_H
#define _BANDIDO_H
#include "celda.h"
#include "item.h"

#include <string>
//using namespace std;
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct {
Celda celda;
Item item;
int cantidad;
int intervaloVida;
}Bandido;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido no debe haber sido creado.
  post: el bandido queda creado y preparado para ser usado.

  bandido : estructura de datos a ser creado.
*/
void crearBandido(Bandido &bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : el bandido debe haber sido creado.
  post: se obtiene la celda en la que se encuentra el bandido creado pasado por parametro.

  bandido : estructura de datos a ser usada.
  return: Celda en la que se encuentra el bandido.
*/

Celda getCelda(Bandido bandido);
/*----------------------------------------------------------------------------*/

/*
  pre : el bandido debe haber sido creado.
  post: se setea la celda del bandido creado pasado por parametro.

  bandido : estructura de datos a ser usada.
  celda: valor a cargar en el bandido.
*/

void setCelda(Bandido &bandido, Celda celda);
/*----------------------------------------------------------------------------*/

/*
  pre : el bandido debe haber sido creado.
  post: se obtiene el item del bandido creado pasado por parametro.

  bandido : estructura de datos a ser usada.
  return: Item del bandido.
*/

Item getItem(Bandido bandido);
/*----------------------------------------------------------------------------*/

/*
  pre : el bandido debe haber sido creado.
  post: se setea el item del bandido creado pasado por parametro.
  bandido : estructura de datos a ser usada.
  item: valor a cargar en el bandido.
*/

void setItem(Bandido &bandido, Item item);
/*----------------------------------------------------------------------------*/


/*
  pre : el bandido debe haber sido creado.
  post: se obtiene la cantidad en la que se encuentra el bandido creado pasado por parametro.

  bandido : estructura de datos a ser usada.
  return: Cantidad de items que pide el bandido.
*/

int getCantidad(Bandido bandido);
/*----------------------------------------------------------------------------*/

/*
  pre : el bandido debe haber sido creado.
  post: se setea la cantidad del bandido creado pasado por parametro.

  bandido : estructura de datos a ser usada.
  cantidad: valor a cargar en el bandido.
*/

void setCantidad(Bandido &bandido, int cantidad);
/*----------------------------------------------------------------------------*/


/*
  pre : el bandido  debe haber sido creado.
  post: el bandido queda destruido (iniciado a su origen).

  bandido : estructura de datos a ser destruido.
*/

void destructor(Bandido &bandido);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _BANDIDO_H
