#include "Bandido.h";
#include <SDL.h>
#include <SDL_image.h>
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearBandido(Bandido &bandido,SDL_Renderer* renderer, int fila,int columna, int anchoCelda, int altoCelda, int altoSprite,Item item,int cantidadItem){
    bandido.fila=fila;//coordenada logica y
    bandido.columna=columna;//coordenada logica x

    bandido.imagen=IMG_LoadTexture(renderer,"img/bandido.png");
    //SDL_QueryTexture(bandido.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    bandido.rectImag.y=(bandido.fila*altoCelda);//coordenada de dibujo y
    bandido.rectImag.x=(bandido.columna*anchoCelda);//coordenada de dibujo x
    bandido.rectImag.w=anchoCelda;//ancho
    bandido.rectImag.h=altoSprite;//alto
    bandido.item=item;
    bandido.cantidadItem=cantidadItem;
}
/*----------------------------------------------------------------------------*/
int getFila(Bandido *bandido){
    return bandido->fila;
}
/*----------------------------------------------------------------------------*/
int getColumna(Bandido *bandido){
    return bandido->columna;
}
/*----------------------------------------------------------------------------*/
Item item(Bandido * bandido){
    return bandido->item;
}
/*----------------------------------------------------------------------------*/
int cantidadItem(Bandido *bandido){
    return bandido->cantidadItem;
}
/*----------------------------------------------------------------------------*/

void setFila(Bandido *bandido,int fila){
    bandido->fila=fila;
}
/*----------------------------------------------------------------------------*/
void setColumna(Bandido *bandido,int columna){
    bandido->columna=columna;
}
/*----------------------------------------------------------------------------*/
void setItem(Bandido *bandido,Item item){
    bandido->item=item;
}
/*----------------------------------------------------------------------------*/
void setCantidadItem(Bandido *bandido,int cantidadItem){
    bandido->cantidadItem=cantidadItem;
}
/*----------------------------------------------------------------------------*/
void dibujarBandido(Bandido *bandido,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,bandido->imagen,NULL,&(bandido->rectImag));
}
/*----------------------------------------------------------------------------*/
void destruirBandido(Bandido *bandido){
    SDL_DestroyTexture(bandido->imagen);
}
/*----------------------------------------------------------------------------*/
