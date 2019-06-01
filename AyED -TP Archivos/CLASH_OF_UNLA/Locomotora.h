#ifndef LOCOMOTORA_H
#define LOCOMOTORA_H

#include "Vagon.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int id;
    Vagon contenedor;
}Locomotora;

void crear_Locomotora(Locomotora &l);
void destruir_Locomotora(Locomotora &l);


void set_id(Locomotora &l, int id);
int get_id(Locomotora &l);


Vagon& get_contenedor(Locomotora &l);
void set_contenedor(Locomotora &l, Vagon &v);

#endif // LOCOMOTORA_H
