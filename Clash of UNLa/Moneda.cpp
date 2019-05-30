#include "Moneda.h";
#include <SDL.h>
#include <SDL_image.h>

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda, int altoSprite){
    moneda.f=f;//coordenada logica y
    moneda.c=c;//coordenada logica x

    moneda.imagen=IMG_LoadTexture(renderer,"img/moneda.png");
    //SDL_QueryTexture(moneda.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    moneda.rectImag.y=(moneda.f*altoCelda)+altoCelda-(altoSprite-altoCelda);//coordenada de dibujo y
    moneda.rectImag.x=(moneda.c*anchoCelda)+anchoCelda;//coordenada de dibujo x
    moneda.rectImag.w=anchoCelda;//ancho
    moneda.rectImag.h=altoSprite;//alto
}
int getFila(Moneda *moneda){
    return moneda->f;
}
int getColumna(Moneda *moneda){
    return moneda->c;
}
void dibujarMoneda(Moneda *moneda,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,moneda->imagen,NULL,&(moneda->rectImag));
}
void destruirMoneda(Moneda *moneda){
    SDL_DestroyTexture(moneda->imagen);
}


