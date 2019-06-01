#include "Vagon.h"

#include <iostream>
#include <string>
#include "string.h"

using namespace std;

//------------------------------
void crear_vagon(Vagon &vagon){
    vagon.capMax=0;
    constructor(vagon.c);
}


void destruir_vagon(Vagon &v){
destructor(v.c);
}


void set_capMax(Vagon &v, int capMax){
    v.capMax=capMax;
}
int get_capMax(Vagon &v){
    return v.capMax;
}

Comanda& get_item(Vagon &v){
    return v.c;
}
void set_item(Vagon &v, Comanda &com){
    v.c=com;
}


