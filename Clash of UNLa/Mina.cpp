#include "Mina.h";
#include <SDL.h>
#include <SDL_image.h>
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda,
               int altoSprite, int ip, int secuencia[5], Item item){
    mina.c=c;//coordenada logica x
    mina.f=f;//coordenada logica y
    mina.ip=ip;//intervalo de produccion
    mina.item=item;//item de la mina
    for(int i=0;i<5;i++){
        mina.secuencia[i] = secuencia[i];
    }
    mina.imagen=IMG_LoadTexture(renderer,"img/mina.png");


    mina.rectImag.y=(mina.f*altoCelda);//coordenada de dibujo y
    mina.rectImag.x=(mina.c*anchoCelda);//coordenada de dibujo x
    mina.rectImag.w=anchoCelda;//ancho
    mina.rectImag.h=altoSprite;//alto
}
/*----------------------------------------------------------------------------*/
int getFila(Mina *mina){
    return mina->f;
}
/*----------------------------------------------------------------------------*/
void setFila(Mina &mina, int fila){
    mina.f = fila;
}
/*----------------------------------------------------------------------------*/
int getColumna(Mina *mina){
    return mina->c;
}
/*----------------------------------------------------------------------------*/
void setColumna(Mina &mina, int columna){
    mina.c = columna;
}
/*----------------------------------------------------------------------------*/
int getIP(Mina &mina){
    return mina.ip;
}
/*----------------------------------------------------------------------------*/
void setIP(Mina &mina, int IP){
    mina.ip = IP;
}
/*----------------------------------------------------------------------------*/
int* getSecuencia(Mina &mina){
    return mina.secuencia;
}
/*----------------------------------------------------------------------------*/
void setSecuencia(Mina &mina, int secuencia[5]){
    for(int i=0;i<5;i++){
        mina.secuencia[i] = secuencia[i];
    }
}
/*----------------------------------------------------------------------------*/
Item getItem(Mina &mina){
    return mina.item;
}
/*----------------------------------------------------------------------------*/
void setItem(Mina &mina, Item item){
    mina.item = item;
}
/*----------------------------------------------------------------------------*/
void dibujarMina(Mina *mina,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,mina->imagen,NULL,&(mina->rectImag));
}
/*----------------------------------------------------------------------------*/
void destruirMina(Mina *mina){
    SDL_DestroyTexture(mina->imagen);
}

