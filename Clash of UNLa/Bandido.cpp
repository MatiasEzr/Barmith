#include "Bandido.h"
#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
//Lista
using namespace std;
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
bool crearBandido(Bandido &bandido,Sprite &sprite,Item &item, int cantidad, int intervaloVida){
bandido.sprite=sprite;
bandido.item=item;
bandido.cantidad=cantidad;
bandido.intervaloVida=intervaloVida;
}
/*----------------------------------------------------------------------------*/
Sprite getSprite(Bandido bandido){
    return bandido.sprite;

}
/*----------------------------------------------------------------------------*/
bool setSprite(Bandido &bandido, Sprite &sprite){
bandido.sprite=sprite;
}
/*----------------------------------------------------------------------------*/

Item getItem(Bandido bandido){
return bandido.item;
}
/*----------------------------------------------------------------------------*/
void setItem(Bandido &bandido,Item &item){
bandido.item=item;
}

/*----------------------------------------------------------------------------*/

int getCantidad(Bandido bandido){
return bandido.cantidad;
}
/*----------------------------------------------------------------------------*/
void setCantidad(Bandido &bandido,int cantidad){
bandido.cantidad=cantidad;
}

/*----------------------------------------------------------------------------*/
int getIntervaloVida(Bandido &bandido){
    return bandido.intervaloVida;
}
/*----------------------------------------------------------------------------*/
bool setIntervaloVida(Bandido &bandido, int intervaloVida){
 bandido.intervaloVida=intervaloVida;
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*void destructor(Bandido &bandido){
bandido.celda=NULL;
bandido.item=NULL;
bandido.cantidad=0;
bandido.intervaloVida=0;
}*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/

