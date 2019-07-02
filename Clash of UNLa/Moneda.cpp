#include "Moneda.h";
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer, int fila,int columna, int anchoCelda, int altoCelda, int altoSprite,int monedaVida,int intervaloFinal){
    moneda.fila=fila;//coordenada logica y
    moneda.columna=columna;//coordenada logica x

    moneda.imagen=IMG_LoadTexture(renderer,"img/moneda.png");

    moneda.rectImag.y=(moneda.fila*altoCelda);//coordenada de dibujo y
    moneda.rectImag.x=(moneda.columna*anchoCelda);//coordenada de dibujo x
    moneda.rectImag.w=anchoCelda;//ancho
    moneda.rectImag.h=altoSprite;//alto
    moneda.monedaVida=monedaVida;
    moneda.intervaloFinal=intervaloFinal;

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
int getIntervaloVida(Moneda &moneda){
 return moneda.monedaVida;
}
int getIntervaloFinal(Moneda &moneda){
 return moneda.intervaloFinal;
}

/*----------------------------------------------------------------------------*/
bool setMonedaVida(Moneda &moneda, int monedaVida){
  moneda.monedaVida=monedaVida;
}
/*----------------------------------------------------------------------------*/
bool setIntervaloFinal(Moneda &moneda, int intervaloFinal){
  moneda.intervaloFinal=intervaloFinal;
}
/*----------------------------------------------------------------------------*/
void dibujarMoneda(Moneda *moneda,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,moneda->imagen,NULL,&(moneda->rectImag));
}
/*----------------------------------------------------------------------------*/
void reemplazarMoneda(Moneda *moneda,SDL_Renderer *renderer){
   /* srand(time(NULL));
    int i=0;
    i=rand()%5;
    stringstream aux;
    aux <<"img/suelo_"<<i<<".png";
*/
    moneda->imagen=IMG_LoadTexture(renderer,"img/suelo_01.png");


}
/*----------------------------------------------------------------------------*/
void destruirMoneda(Moneda *moneda){
SDL_DestroyTexture(moneda->imagen);
}



