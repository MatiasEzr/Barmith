#include "Bandido.h"
#include <cstring>
#include <string>
#include <iostream>
//Lista
using namespace std;
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearBandido(Bandido &bandido){
bandido.celda=NULL;
bandido.item=NULL;
bandido.cantidad=0;
bandido.intervaloVida=0;
//crearListabandido.);
}
/*----------------------------------------------------------------------------*/
Celda getCelda(Bandido bandido){
    return bandido.celda;
}
/*----------------------------------------------------------------------------*/
void setCelda(Bandido &bandido, Celda celda){
bandido.celda=celda;
}
/*----------------------------------------------------------------------------*/

int getItem(Bandido bandido){
return bandido.item;
}
/*----------------------------------------------------------------------------*/
void setItem(Bandido &bandido,Item item){
bandido.item=item;
}

/*----------------------------------------------------------------------------*/

int getCantidad(Bandido bandido){
return bandido.cantidad;
}
/*----------------------------------------------------------------------------*/
void setCantidad(Bandido &bandido,int cantidad){
bandido.cantidad=cantidad;
}

/*----------------------------------------------------------------------------*/
void destructor(Bandido &bandido){
bandido.celda=NULL;
bandido.item=NULL;
bandido.cantidad=0;
bandido.intervaloVida=0;
}
/*----------------------------------------------------------------------------*/
/******************************************************************************/

