#ifndef _CELDA_H
#define _CELDA_H
#include <string>
using namespace std;
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct {
int fila;
int columna;
//TipoCelda tipo;
}Celda;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : la no debe haber sido creado.
  post: la celda queda creado y preparado para ser usado.

  celda : estructura de datos a ser creado.
*/
void crearCelda(Celda &celda);


void destructor(Celda &celda);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _CELDA_H
