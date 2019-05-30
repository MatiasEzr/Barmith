#ifndef __MINA_H__
#define __MINA_H__

#include <SDL.h>

typedef struct{
    int f;
    int c;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Mina;

void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda, int altoSprite);
int getFila(Mina *mina);
int getColumna(Mina *mina);
void dibujarMina(Mina *mina,SDL_Renderer* renderer);
void destruirMina(Mina *mina);

#endif

