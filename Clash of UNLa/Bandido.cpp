#include "Bandido.h";
#include "Vagon.h";
#include "Caja.h";
#include <SDL.h>
#include <SDL_image.h>
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearBandido(Bandido &bandido,SDL_Renderer* renderer, int fila,int columna, int anchoCelda, int altoCelda, int altoSprite,string codItem,int cantidadItem,int vidaBandido,int intervaloFinal){
    bandido.fila=fila;
    bandido.columna=columna;

    bandido.imagen=IMG_LoadTexture(renderer,"img/bandido.png");

    bandido.rectImag.y=(bandido.fila*altoCelda);
    bandido.rectImag.x=(bandido.columna*anchoCelda);
    bandido.rectImag.w=anchoCelda;
    bandido.rectImag.h=altoSprite;
    bandido.codItem=codItem;
    bandido.cantidadItem=cantidadItem;
    bandido.intervaloFinal=intervaloFinal;
    bandido.vidaBandido=vidaBandido;
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
string getCodItem(Bandido * bandido){
    return bandido->codItem;
}
/*----------------------------------------------------------------------------*/
int getCantidadItem(Bandido *bandido){
    return bandido->cantidadItem;
}
/*----------------------------------------------------------------------------*/
void setCantidadItem(Bandido &bandido, int cantidadItem){
    bandido.cantidadItem = cantidadItem;
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
void setCodItem(Bandido *bandido,string codItem){
    bandido->codItem=codItem;
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
void reemplazarBandido(Bandido *bandido,SDL_Renderer *renderer){
   /* srand(time(NULL));
    int i=0;
    i=rand()%5;
    stringstream aux;
    aux <<"img/suelo_"<<i<<".png";
*/
    bandido->imagen=IMG_LoadTexture(renderer,"img/suelo_02.png");
}
/*----------------------------------------------------------------------------*/
void destruirBandido(Bandido *bandido){
    SDL_DestroyTexture(bandido->imagen);
}
/*----------------------------------------------------------------------------*/
