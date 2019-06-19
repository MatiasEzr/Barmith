#ifndef COMANDA_H
#define COMANDA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;



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


void crearComanda(Comanda &comanda,string codItem, int cantidad);
/*----------------------------------------------------------------------------*/

void destruirComanda(Comanda &comanda);
/*----------------------------------------------------------------------------*/

void setCodItem(Comanda &comanda, string codItem);
/*----------------------------------------------------------------------------*/

string getCodItem(Comanda &comanda);
/*----------------------------------------------------------------------------*/

void setCantidad(Comanda &comanda, int cant);
/*----------------------------------------------------------------------------*/

int getCantidad(Comanda &comanda);




#endif // COMANDA_H




