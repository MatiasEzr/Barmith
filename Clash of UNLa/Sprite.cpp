#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include <string>
#include <iostream>
//Lista
using namespace std;
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearSprite(Sprite &sprite, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer){
            sprite.f=f;//coordenada logica y
            sprite.c=c;//coordenada logica x
            sprite.imagen= IMG_LoadTexture(renderer,"sprite.png");

            sprite.rectImag.y=f* altoCasillero;//coordenada de dibujo y
            sprite.rectImag.x= c* anchoCasillero;//coordenada de dibujo x
            sprite.rectImag.w= anchoCasillero;//ancho
            sprite.rectImag.h= altoCasillero;//alto
        }
/*----------------------------------------------------------------------------*/
void dibujarSprite(Sprite &sprite, SDL_Renderer* renderer){
            SDL_RenderCopy(renderer, sprite.imagen,NULL,&(sprite.rectImag));
        }


/*----------------------------------------------------------------------------*/
int getF(Sprite sprite){
    return sprite.f;

}
/*----------------------------------------------------------------------------*/
void setF(Sprite &sprite, int f){
sprite.f=f;
}
/*----------------------------------------------------------------------------*/

int getC(Sprite sprite){
return sprite.c;
}
/*----------------------------------------------------------------------------*/
void setC(Sprite &sprite,int c){
sprite.c=c;
}

/*----------------------------------------------------------------------------*/

int getAnchoCasillero(Sprite sprite){
return sprite.anchoCasillero;
}
/*----------------------------------------------------------------------------*/
void setAnchoCasillero(Sprite &sprite,int anchoCasillero){
sprite.anchoCasillero=anchoCasillero;
}
/*----------------------------------------------------------------------------*/

int getAltoCasillero(Sprite sprite){
return sprite.altoCasillero;
}
/*----------------------------------------------------------------------------*/
void setAltoCasillero(Sprite &sprite,int altoCasillero){
sprite.altoCasillero=altoCasillero;
}

/*----------------------------------------------------------------------------*/
void destruirSprite(Sprite &sprite){
            SDL_DestroyTexture(sprite.imagen);
        }
/*----------------------------------------------------------------------------*/
/******************************************************************************/

