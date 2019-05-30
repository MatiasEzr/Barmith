#ifndef __TERRENO_H__
#define __TERRENO_H__

//include celdas
#include "Celda.h"
#include "Vagon.h"

typedef struct{
    int f;
    int c;
    PtrNodoVagon ptrNodoVagon;
    Bandido *ptrBandido;
    Mina *ptrMina;
    Moneda *ptrMoneda;
}Terreno;


void crearTerreno(Terreno &terreno,int f,int c);
void dibujarTerreno(SDL_Renderer* renderer,Terreno &terreno, int intervalo);
void destruirTerreno(Terreno &terreno);

/*void crearTabla(SDL_Renderer* renderer,Terreno &terreno);
void dibujarTabla(SDL_Renderer* renderer,Terreno &terreno);
void destruirTabla(Terreno &terreno);
void setF(Terreno &terreno, int f);
int getF(Terreno &terreno);
void setC(Terreno &terreno, int c);
int getC(Terreno &terreno);
*/
#endif
