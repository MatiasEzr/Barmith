#include "Estacion.h"
#include <SDL.h>
#include <SDL_image.h>

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearEstacion(Estacion &estacion,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda){
    estacion.c=c;//coordenada logica x
    estacion.f=f;//coordenada logica y
    estacion.imagen=IMG_LoadTexture(renderer,"img/estacion.png");

    estacion.rectImag.y=(estacion.f*altoCelda);//coordenada de dibujo y
    estacion.rectImag.x=(estacion.c*anchoCelda);//coordenada de dibujo x
    estacion.rectImag.w=anchoCelda;//ancho
    estacion.rectImag.h=altoCelda;//alto
}

/*----------------------------------------------------------------------------*/
int getFila(Estacion *estacion){
    return estacion->f;
}
/*----------------------------------------------------------------------------*/
void setFila(Estacion &estacion, int fila){
    estacion.f = fila;
}
/*----------------------------------------------------------------------------*/
int getColumna(Estacion *estacion){
    return estacion->c;
}
/*----------------------------------------------------------------------------*/
void setColumna(Estacion &estacion, int columna){
    estacion.c = columna;
}


/*----------------------------------------------------------------------------*/
void dibujarEstacion(Estacion *estacion,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,estacion->imagen,NULL,&(estacion->rectImag));
}
/*----------------------------------------------------------------------------*/
int venderVagon(Estacion &estacion, int cantidadMonedas){
    return CAPACIDAD_VAGON * cantidadMonedas;
}
/*----------------------------------------------------------------------------*/
void destruirEstacion(Estacion &estacion){
    SDL_DestroyTexture(estacion.imagen);
}
