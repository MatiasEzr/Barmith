#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Terreno.h"
//include vehiculo
#include "Celda.h"

//include monedas

void crearTerreno(Terreno &terreno,int f,int c){
    terreno.f=f;//coordenada logica y
    terreno.c=c;//coordenada logica x

    terreno.ptrNodoVagon=NULL;//al principio no tiene vagons
    terreno.ptrBandido=NULL;//un unico villano por casilla
    terreno.ptrMina=NULL;
    terreno.ptrMoneda=NULL;
}
void dibujarTerreno(SDL_Renderer* renderer,Terreno &terreno, int intervalo){
    if(terreno.ptrBandido!=NULL){
        dibujarBandido(terreno.ptrBandido,renderer);
    }
    if(terreno.ptrMina!=NULL){
        dibujarMina(terreno.ptrMina,renderer);
    }
    if(terreno.ptrMoneda!=NULL){
        dibujarMoneda(terreno.ptrMoneda,renderer);
    }
    if(terreno.ptrNodoVagon!=NULL){
        dibujarVagon(terreno.ptrNodoVagon->vagon,renderer,intervalo);
    }
}



void setF(Terreno &terreno, int f){
    terreno.f = f;
}
int getF(Terreno &terreno, int c){
    return terreno.f;
}



void setC(Terreno &terreno, int c){
    terreno.c = c;
}
int getC(Terreno &terreno){
    return terreno.c;
}
/*
void crearTabla(SDL_Renderer* renderer, Terreno &terreno){
    char imagen[30]="img/suelo_";
	strchr(imagen,rand()%6);
    strcat(imagen,".png");
    terreno.sprite.imagen=IMG_LoadTexture(renderer,imagen);

    terreno.sprite.rectImag.y=terreno.f;//dibujo y
    terreno.sprite.rectImag.x=terreno.c;//dibujo x
}
void dibujarTabla(SDL_Renderer* renderer,Terreno &terreno){
    for(int f=0;f<terreno.f;f++){
        for(int c=0;c<terreno.c;c++){
            dibujarCelda(renderer,terreno.tablero[f][c]);
        }
    }
}
*/
void destruirTerreno(Terreno &terreno){
    //la Locomotora se destruye en otro lugar, pero aquí hay otros tda:
    if(terreno.ptrBandido!=NULL){
        destruirBandido(terreno.ptrBandido);
        delete terreno.ptrBandido;
    }
    if(terreno.ptrMina!=NULL){
        destruirMina(terreno.ptrMina);
        delete terreno.ptrMina;
    }
    if(terreno.ptrMoneda!=NULL){
        destruirMoneda(terreno.ptrMoneda);
        delete terreno.ptrMoneda;
    }
    //delete &terreno;
}


