#ifndef __MONEDA_H__
#define __MONEDA_H__

#include <SDL.h>

typedef struct{
    int f;
    int c;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Moneda;

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda, int altoSprite);

int getFila(Moneda *moneda);
int getColumna(Moneda *moneda);
void dibujarMoneda(Moneda *moneda,SDL_Renderer* renderer);
void destruirMoneda(Moneda *moneda);

#endif
