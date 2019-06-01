#ifndef COMANDA_H
#define COMANDA_H

#include <stdlib.h>
#include <stdio.h>

enum CodItem{oro=1,plata=2,bronce=3,platino=4,roca=5,carbon=6,NADA};
typedef struct{
    CodItem codItem;
    int cantidad;
}Comanda;

void constructor(Comanda &comanda);
void destructor(Comanda &comanda);

void set_codItem(Comanda &comanda,  CodItem codi);
int get_codItem(Comanda &comanda);

void set_cantidad(Comanda &comanda, int cant);
int get_cantidad(Comanda &comanda);




#endif // COMANDA_H




