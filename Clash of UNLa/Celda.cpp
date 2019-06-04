#include "Celda.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string.h>

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearCelda(Celda &celda,int f,int c,int ancho, int alto, SDL_Renderer* renderer,char rand[]){
    celda.f=f;//coordenada logica y
    celda.c=c;//coordenada logica x

    char imagen[30]="img/suelo_";
	strcat(imagen,rand);
    strcat(imagen,".png");
    celda.imagen=IMG_LoadTexture(renderer,imagen);
    //SDL_QueryTexture(celda.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    celda.rectImag.y=(celda.f*alto)+alto;//coordenada de dibujo y
    celda.rectImag.x=(celda.c*ancho)+ancho;//coordenada de dibujo x
    celda.rectImag.w=ancho;//ancho
    celda.rectImag.h=alto;//alto

    celda.ptrNodoVagon=NULL;//al principio no tiene vagons
    celda.ptrBandido=NULL;//un unico bandido por celda
    celda.ptrMoneda=NULL;
}
void dibujarCelda(SDL_Renderer* renderer,Celda &celda){
    SDL_RenderCopy(renderer,celda.imagen,NULL,&(celda.rectImag));
}
void destruirCelda(Celda &celda){
    SDL_DestroyTexture(celda.imagen);
    //delete &celda;
}
