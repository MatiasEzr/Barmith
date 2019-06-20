#include "Moneda.h";
#include <SDL.h>
#include <SDL_image.h>

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer, int fila,int columna, int anchoCelda, int altoCelda, int altoSprite,int intervaloVida){
    moneda.fila=fila;//coordenada logica y
    moneda.columna=columna;//coordenada logica x

    moneda.imagen=IMG_LoadTexture(renderer,"img/moneda.png");

    moneda.rectImag.y=(moneda.fila*altoCelda);//coordenada de dibujo y
    moneda.rectImag.x=(moneda.columna*anchoCelda);//coordenada de dibujo x
    moneda.rectImag.w=anchoCelda;//ancho
    moneda.rectImag.h=altoSprite;//alto
    moneda.intervaloVida=intervaloVida;

}
/*----------------------------------------------------------------------------*/
int getFila(Moneda *moneda){
    return moneda->fila;
}
/*----------------------------------------------------------------------------*/
int getColumna(Moneda *moneda){
    return moneda->columna;
}

/*----------------------------------------------------------------------------*/
int intervaloVida(Moneda *moneda){
 return moneda->intervaloVida;
}
/*----------------------------------------------------------------------------*/
bool setIntervaloVida(Moneda &moneda, int intervaloVida){
  moneda.intervaloVida=intervaloVida;
}

/*----------------------------------------------------------------------------*/
void dibujarMoneda(Moneda *moneda,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,moneda->imagen,NULL,&(moneda->rectImag));
}
/*----------------------------------------------------------------------------*/
void destruirMoneda(Moneda *moneda){
    SDL_DestroyTexture(moneda->imagen);
}



