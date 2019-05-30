#ifndef __MAPA_H__
#define __MAPA_H__

#include "Locomotora.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"

typedef struct{
    int f;
    int c;

    PtrNodoVagon ptrNodoVagon;
    Bandido *ptrBandido;
    Mina *ptrMina;
    Moneda *ptrMoneda;
}Terreno;

void crearTerreno(Terreno &mapa,int f,int c);
void dibujarTerreno(SDL_Renderer* renderer,Terreno &mapa, int intervalo);
void destruirTerreno(Terreno &mapa);
#endif
