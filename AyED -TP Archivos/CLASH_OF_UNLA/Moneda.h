#ifndef MONEDA_H
#define MONEDA_H

#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int cantMonedas;
}Moneda;

void crear_Moneda(Moneda &moneda);
void destruir_Moneda(Moneda &moneda);


void set_cantMonedas(Moneda &moneda, int cmonedas);
int get_cantMoneda(Moneda &moneda);

#endif // MONEDA_H
