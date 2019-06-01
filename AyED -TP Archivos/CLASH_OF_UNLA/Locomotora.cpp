
#include "Locomotora.h"

void crear_Locomotora(Locomotora &l){
    l.id=0;
    crear_vagon(l.contenedor);
}
void destruir_Locomotora(Locomotora &l){
destruir_vagon(l.contenedor);
}


void set_id(Locomotora &l, int id){
    l.id=id;
}
int get_id(Locomotora &l){
    return l.id;
}

Vagon& get_contenedor(Locomotora &l){
    return l.contenedor;
}
void set_contenedor(Locomotora &l, Vagon &v){
    l.contenedor=v;
}
