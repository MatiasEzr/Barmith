#include "Comanda.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



using namespace std;
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearComanda(Comanda &comanda,string codItem,int cantidad){
    comanda.codItem=codItem;
    comanda.cantidad=cantidad;
}
/*----------------------------------------------------------------------------*/

void destruirComanda(Comanda &comanda){}
/*----------------------------------------------------------------------------*/

void setcodItem(Comanda &comanda,string codItem){
    comanda.codItem=codItem;
}
/*----------------------------------------------------------------------------*/

string getCodItem(Comanda &comanda){
    return comanda.codItem;
}
/*----------------------------------------------------------------------------*/

void setCantidad(Comanda &comanda,int cantidad){
    comanda.cantidad=cantidad;
}
/*----------------------------------------------------------------------------*/

int getCantidad(Comanda &comanda){
    return comanda.cantidad;
}

