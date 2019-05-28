#include "Mina.h";
#include <SDL.h>
#include <SDL_image.h>


/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearMina(Mina &mina,Sprite &sprite, Item &item, int intervaloProduccion /*,int secuencia[]*/){
   mina.sprite=sprite;
   mina.item=item;
   mina.intervaloProduccion=intervaloProduccion;
   //mina.secuencia=secuencia;

}
/*----------------------------------------------------------------------------*/

Sprite getSprite(Mina *mina){
    return mina->sprite;
}
/*----------------------------------------------------------------------------*/

bool setSprite(Mina &mina, Sprite &sprite){
    mina.sprite=sprite;
}
/*----------------------------------------------------------------------------*/

int getItem(Mina *mina){
    return mina->item;
}

/*----------------------------------------------------------------------------*/

bool setItem(Mina& mina, Item &item){
    mina.item=item;
}
/*----------------------------------------------------------------------------*/
int getIntervaloProduccion(Mina &mina){
    return mina.intervaloProduccion;
}
/*----------------------------------------------------------------------------*/
bool setIntervaloProduccion(Mina &mina, int intervaloProduccion){
 mina.intervaloProduccion=intervaloProduccion;
}
/*----------------------------------------------------------------------------*/

void dibujarMina(Mina *mina,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,mina->sprite.imagen,NULL,&(mina->sprite.rectImag));
}

/*----------------------------------------------------------------------------*/
void destruirMina(Mina *mina){
    SDL_DestroyTexture(mina->sprite.imagen);
}

/*----------------------------------------------------------------------------*/

