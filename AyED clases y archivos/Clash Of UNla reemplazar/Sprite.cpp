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
void crearSprite(Sprite &sprite, int f, int c, int anchoCelda, int altoCelda, SDL_Renderer* renderer){
            sprite.f=f;//coordenada logica y
            sprite.c=c;//coordenada logica x
            sprite.imagen= IMG_LoadTexture(renderer,"sprite.png");

            sprite.rectImag.y=f* altoCelda;//coordenada de dibujo y
            sprite.rectImag.x= c* anchoCelda;//coordenada de dibujo x
            sprite.rectImag.w= anchoCelda;//ancho
            sprite.rectImag.h= altoCelda;//alto
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

int getAnchoCelda(Sprite sprite){
return sprite.anchoCelda;
}
/*----------------------------------------------------------------------------*/
void setAnchoCelda(Sprite &sprite,int anchoCelda){
sprite.anchoCelda=anchoCelda;
}
/*----------------------------------------------------------------------------*/

int getAltoCelda(Sprite sprite){
return sprite.altoCelda;
}
/*----------------------------------------------------------------------------*/
void setAltoCelda(Sprite &sprite,int altoCelda){
sprite.altoCelda=altoCelda;
}

/*----------------------------------------------------------------------------*/
void destruirSprite(Sprite &sprite){
            SDL_DestroyTexture(sprite.imagen);
        }
/*----------------------------------------------------------------------------*/
/******************************************************************************/

