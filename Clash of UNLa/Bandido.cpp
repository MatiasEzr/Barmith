#include "Bandido.h";
#include <SDL.h>
#include <SDL_image.h>

void crearBandido(Bandido &bandido,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda, int altoSprite){
    bandido.f=f;//coordenada logica y
    bandido.c=c;//coordenada logica x

    bandido.imagen=IMG_LoadTexture(renderer,"img/bandido.png");
    //SDL_QueryTexture(bandido.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    bandido.rectImag.y=(bandido.f*altoCelda)+altoCelda-(altoSprite-altoCelda);//coordenada de dibujo y
    bandido.rectImag.x=(bandido.c*anchoCelda)+anchoCelda;//coordenada de dibujo x
    bandido.rectImag.w=anchoCelda;//ancho
    bandido.rectImag.h=altoSprite;//alto
}
int getFila(Bandido *bandido){
    return bandido->f;
}
int getColumna(Bandido *bandido){
    return bandido->c;
}
void dibujarBandido(Bandido *bandido,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,bandido->imagen,NULL,&(bandido->rectImag));
}
void destruirBandido(Bandido *bandido){
    SDL_DestroyTexture(bandido->imagen);
}
