#include "Comanda.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;

void constructor(Comanda &comanda){
    comanda.codItem=NADA;
    comanda.cantidad=0;
}

void destructor(Comanda &comanda){}

void set_codItem(Comanda &comanda, CodItem codi){
    comanda.codItem=codi;
}
CodItem get_codItem(Comanda &comanda){
    return comanda.codItem;
}

void set_cantidad(Comanda &comanda, int cant){
    comanda.cantidad=cant;
}
int get_cantidad(Comanda &comanda){
    return comanda.cantidad;
}

