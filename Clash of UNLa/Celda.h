#ifndef __SUELO_H__
#define __SUELO_H__

#include <SDL.h>
#include "Locomotora.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"

typedef struct{
    int f;
    int c;
	SDL_Texture *imagen;
    SDL_Rect rectImag;

    PtrNodoVagon ptrNodoVagon;
    Bandido *ptrBandido;
    Mina *ptrMina;
    Moneda *ptrMoneda;

}Celda;

void crearCelda(Celda &celda,int f,int c,int ancho, int alto, SDL_Renderer* renderer,char rand[]);
void dibujarCelda(SDL_Renderer* renderer,Celda &celda);
void destruirCelda(Celda &celda);
#endif

