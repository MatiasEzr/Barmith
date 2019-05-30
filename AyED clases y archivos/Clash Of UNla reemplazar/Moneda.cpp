#include "Moneda.h";
#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/


void crearMoneda(Moneda &moneda,Sprite  &sprite, int intervaloVida){
   moneda.sprite=sprite;
   moneda.intervaloVida=intervaloVida;
}
/*----------------------------------------------------------------------------*/

Sprite getSprite(Moneda *moneda){
    return moneda->sprite;
}
/*----------------------------------------------------------------------------*/

bool setSprite(Moneda &moneda, Sprite &sprite){
    moneda.sprite=sprite;
}
/*----------------------------------------------------------------------------*/
int intervaloVida(Moneda *moneda){
 return moneda->intervaloVida;
}
/*----------------------------------------------------------------------------*/
bool setIntervaloVida(Moneda &moneda, int intervaloVida){
  moneda.intervaloVida=intervaloVida;
}


int getFila(Moneda *moneda){
    return moneda->sprite.f;
}
int getColumna(Moneda *moneda){
    return moneda->sprite.c;
}

void dibujarMoneda(Moneda *moneda,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,moneda->sprite.imagen,NULL,&(moneda->sprite.rectImag));
}
void destruirMoneda(Moneda *moneda){
    SDL_DestroyTexture(moneda->sprite.imagen);
}


