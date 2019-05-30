#ifndef __VAGON_H__
#define __VAGON_H__

#include <SDL.h>

typedef struct{
    char tipo[3];
    int f;
    int c;
    char direccion[4];
    int anchoCelda;
    int altoCelda;
    int altoSprite;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Vagon;

void crearVagon(Vagon &vagon,char tipo[], int f,int c, char direccion[], int anchoCelda, int altoCelda, int altoSprite);
int getFila(Vagon &vagon);
int getColumna(Vagon &vagon);
void setFila(Vagon &vagon,int desplazamiento);
void setColumna(Vagon &vagon,int desplazamiento);
void dibujarVagon(Vagon &vagon,SDL_Renderer* renderer,int intervalo);
void destruirVagon(Vagon &vagon);
char* getDireccion(Vagon &vagon);
void setDireccion(Vagon &vagon,char direccion[]);

#endif
