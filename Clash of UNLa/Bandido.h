#ifndef __VILLANO_H__
#define __VILLANO_H__

#include <SDL.h>

typedef struct{
    int f;
    int c;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Bandido;

void crearBandido(Bandido &bandido,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda, int altoSprite);
int getFila(Bandido *bandido);
int getColumna(Bandido *bandido);
void dibujarBandido(Bandido *bandido,SDL_Renderer* renderer);
void destruirBandido(Bandido *bandido);

#endif
