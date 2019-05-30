#include "Mina.h";
#include <SDL.h>
#include <SDL_image.h>

void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda, int altoSprite){
    mina.f=f;//coordenada logica y
    mina.c=c;//coordenada logica x

    mina.imagen=IMG_LoadTexture(renderer,"img/mina.png");
    //SDL_QueryTexture(mina.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    mina.rectImag.y=(mina.f*altoCelda)+altoCelda-(altoSprite-altoCelda);//coordenada de dibujo y
    mina.rectImag.x=(mina.c*anchoCelda)+anchoCelda;//coordenada de dibujo x
    mina.rectImag.w=anchoCelda;//ancho
    mina.rectImag.h=altoSprite;//alto
}
int getFila(Mina *mina){
    return mina->f;
}
int getColumna(Mina *mina){
    return mina->c;
}
void dibujarMina(Mina *mina,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,mina->imagen,NULL,&(mina->rectImag));
}
void destruirMina(Mina *mina){
    SDL_DestroyTexture(mina->imagen);
}

