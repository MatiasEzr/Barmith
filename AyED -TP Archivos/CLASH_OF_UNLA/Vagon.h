#ifndef VAGON_H
#define VAGON_H

#include "Comanda.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "string.h"


typedef struct{
    int capMax;
    Comanda c;
}Vagon;

//------------------------------
void crear_vagon(Vagon &vagon);


void destruir_vagon(Vagon &v);


void set_capMax(Vagon &v, int capMax);
int get_capMax(Vagon &v);

Comanda& get_item(Vagon &v);
void set_item(Vagon &v, Comanda &com);

//----------------------

#endif // VAGON_H
