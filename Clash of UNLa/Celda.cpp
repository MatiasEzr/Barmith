#include "Celda.h"
//#include "Locomotora.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);


/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearCelda(Celda &celda,Sprite &sprite,char rand[]){
    celda.sprite=sprite;

    //celda.ptrNodoCarro=NULL;//al principio no tiene carros
    //celda.ptrVillano=NULL;//un unico villano por celda
    //celda.ptrMoneda=NULL;
}
/*----------------------------------------------------------------------------*/
void dibujarCelda(SDL_Renderer* renderer,Celda &celda){
    SDL_RenderCopy(renderer,celda.sprite.imagen,NULL,&(celda.sprite.rectImag));
}

/*----------------------------------------------------------------------------*/
void destruirCelda(Celda &celda){
    SDL_DestroyTexture(celda.sprite.imagen);
    //delete &celda;
}
/*----------------------------------------------------------------------------*/
