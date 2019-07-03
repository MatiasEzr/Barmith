#ifndef COMANDA_H
#define COMANDA_H


#include <fstream>

using namespace std;

/**
    AXIOMAS:
    codItem > 0
    cantidad < 100 (podria variar segun el objetivo facil/medio/dificil)
*/

/**
    Definición del tipo de dato.
*/

//enum CodItem{oro=1,plata=2,bronce=3,platino=4,roca=5,carbon=6,NADA};
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
    string codItem;
    int cantidad;
}Comanda;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/

/*
pre: La comanda no debe haber sido creada
post: La comanda queda registrada
*/

void crearComanda(Comanda &comanda,string codItem, int cantidad);
/*----------------------------------------------------------------------------*/

/*
pre: Comanda tiene que existir
post: comanda queda inutilizable
*/

void destruirComanda(Comanda &comanda);

/*----------------------------------------------------------------------------*/

/*
pre: Comanda tiene que existir
post: El codItem queda registrado en Comanda
*/

void setCodItem(Comanda &comanda, string codItem);

/*----------------------------------------------------------------------------*/


/*
pre: Comanda tiene que existir
post: Devuelve codItem
*/

string getCodItem(Comanda &comanda);

/*----------------------------------------------------------------------------*/


/*
pre: Comanda tiene que existir
post: La cantidad queda registrada en comanda
*/

void setCantidad(Comanda &comanda, int cant);
/*----------------------------------------------------------------------------*/


/*
pre: Comanda tiene que existir
post: Devuelve cantidad
*/


int getCantidad(Comanda &comanda);


#endif // COMANDA_H




