#ifndef _CAJA_H
#define _CAJA_H

#include <string>

using namespace std;

/**
    AXIOMAS:

    codItem > 0
    cantidadItem: No puede contener mas de 5 items
    capacidadMaxima <= 25
    capacidadActual >=0
*/

/**
    Definición del tipo de dato.
*/

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
pre: La caja debe haber sido creada
post: La cantidadItem queda registrada en la caja
*/

void setCantidadItem(Caja &caja, int cantidadItem);
/*----------------------------------------------------------------------------*/
/*
pre: La caja debe haber sido creada
post: Devuelve cantidad de item
*/
int getCantidadItem(Caja &caja);
/*----------------------------------------------------------------------------*/
/*
pre: La caja debe haber sido creada
post: Devuelve capacidad maxima
*/

int getCapacidadMaxima(Caja &caja);
/*----------------------------------------------------------------------------*/

/*
pre: La caja debe haber sido creada
post: Devuelve capacidad actual
*/
int getCapacidadActual(Caja &caja);
/*----------------------------------------------------------------------------*/

/*
pre: La caja debe haber sido creada
post: El codItem queda registrado en la caja
*/
void setCodItem(Caja &caja, string codItem);
/*----------------------------------------------------------------------------*/

/*
pre: La caja debe haber sido creada
post: La capacidadMaxima queda registrado en la caja
*/
void setCapacidadMaxima(Caja &caja, int capacidadActual);
/*----------------------------------------------------------------------------*/

/*
pre: La caja debe haber sido creada
post: La capacidadActual queda registrado en la caja
*/
void setCapacidadActual(Caja &caja, int capacidadMaxima);
/*----------------------------------------------------------------------------*/


/*
pre:La caja debe haber sido creada
post:La caja queda inutilizable
*/
void eliminarCaja(Caja & caja);


#endif //_CAJA_H
