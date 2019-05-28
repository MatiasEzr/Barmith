#ifndef __MAPA_H__
#define __MAPA_H__

//include de vehiculo
#include "Minas.h"
//include monedas
#include "Bandido.h"

typedef struct{
    int f;
    int c;

    //PtrNodoCarro ptrNodoCarro;
    Minas *ptrMinas;
    //Moneda *ptrMoneda;
    Bandido *ptrBandido;
}Mapa;

void crearMapa(Mapa &mapa,int f,int c);
void dibujarMapa(SDL_Renderer* renderer,Mapa &mapa, int intervalo);
void destruirMapa(Mapa &mapa);
#endif
