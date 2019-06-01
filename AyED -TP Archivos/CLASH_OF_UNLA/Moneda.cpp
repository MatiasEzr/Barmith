#include "Moneda.h"

#include <stdlib.h>
#include <stdio.h>


void crear_Moneda(Moneda &moneda){
    moneda.cantMonedas=0;
}
void destruir_Moneda(Moneda &moneda){}


void set_cantMonedas(Moneda &moneda, int cmonedas){
    moneda.cantMonedas=cmonedas;
}
int get_cantMoneda(Moneda &moneda){
    return moneda.cantMonedas;
}

