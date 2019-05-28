#ifndef __CELDA_H__
#define __CELDA_H__

#include <SDL.h>
//#include "Locomotora.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
#include "Sprite.h"

typedef struct{
    Sprite sprite;

    //PtrNodoCarro ptrNodoCarro;
    Bandido *ptrBandido;
    Mina *ptrMina;
    Moneda *ptrMoneda;

}Celda;

void crearCelda(Celda &celda,Sprite *sprite,char rand[]);
void dibujarCelda(SDL_Renderer* renderer,Celda &celda);
void destruirCelda(Celda &celda);
#endif

