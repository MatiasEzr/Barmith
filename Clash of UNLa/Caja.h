#ifndef _CAJA_H
#define _CAJA_H

#include <string>

using namespace std;
typedef struct{
    string codItem;   //
    int cantidadItem; //Cantidad del item
    int capacidadMaxima; //Capacidad maxima de la caja
    int capacidadActual;
}Caja;
/*
pre:Caja no debe haber sido creada
post: inicializa parametros de Caja en 0
*/

void crearCaja(Caja & caja,int cantidadItem,int capacidadActual,int capacidadMaxima,string codItem);
/*----------------------------------------------------------------------------*/

/*
pre: Que la caja existe
post: Devuelve codItem
*/


string getCodItem(Caja &caja);
/*----------------------------------------------------------------------------*/

/*
pre: Caja creada con crearCaja()
post:
*/

void setCantidadItem(Caja &caja, int cantidadItem);
/*----------------------------------------------------------------------------*/
/*
pre: Caja creada con crearCaja()
post: Devuelve cantidad de item
*/
int getCantidadItem(Caja &caja);
/*----------------------------------------------------------------------------*/
/*
pre: Caja creada con crearCaja()
post: Devuelve capacidad maxima
*/

int getCapacidadMaxima(Caja &caja);
/*----------------------------------------------------------------------------*/

/*
pre: Caja creada con crearCaja()
post: Devuelve capacidad actual
*/
int getCapacidadActual(Caja &caja);
/*----------------------------------------------------------------------------*/

/*
pre: Caja creada con crearCaja()
post: Devuelve tipo de item
*/
void setCodItem(Caja &caja, string codItem);
/*----------------------------------------------------------------------------*/

/*
pre: Caja creada con crearCaja()
post: Devuelve capacidad maxima de vagon
*/
void setCapacidadMaxima(Caja &caja, int capacidadActual);
/*----------------------------------------------------------------------------*/

/*
pre: Caja creada con crearCaja()
post: Devuelve capacidad actual de vagon
*/
void setCapacidadActual(Caja &caja, int capacidadMaxima);
/*----------------------------------------------------------------------------*/


/*
pre: Caja creada con crearCaja()
post:
*/
void eliminarCaja(Caja & caja);


#endif //_CAJA_H
