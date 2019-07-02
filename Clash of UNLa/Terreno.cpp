#include "Terreno.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
#include "Vagon.h"
#include "Lista.h"
#include "Estacion.h"
#include <stdio.h>
#include <string.h>
#include <SDL_image.h>

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearTerreno(Terreno &terreno,int fila,int columna, int ancho, int alto, SDL_Renderer* renderer,char rand[]){
    terreno.fila=fila;
    terreno.columna=columna;

    terreno.ptrNodoVagon=NULL;
    terreno.ptrBandido=NULL;
    terreno.ptrMina=NULL;
    terreno.ptrMoneda=NULL;
    terreno.ptrEstacion=NULL;

    char imagen[30]="img/suelo_";
	strcat(imagen,rand);
    strcat(imagen,".png");
    terreno.imagen=IMG_LoadTexture(renderer,imagen);

    terreno.rectImag.y=(terreno.fila*alto);//coordenada de dibujo y
    terreno.rectImag.x=(terreno.columna*ancho);//coordenada de dibujo x
    terreno.rectImag.w=ancho;//ancho
    terreno.rectImag.h=alto;//alto
}
/*----------------------------------------------------------------------------*/
void dibujarTerreno(Terreno &terreno,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,terreno.imagen,NULL,&(terreno.rectImag));
}
void setPtrMina(Terreno &terreno,Mina *mina){
    terreno.ptrMina=mina;
}
/*----------------------------------------------------------------------------*/
void dibujarEntidad(Terreno &terreno,SDL_Renderer* renderer, int intervalo){
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
        dibujarVagon(*(Vagon*)terreno.ptrNodoVagon->ptrDato,renderer,intervalo);
    } if(terreno.ptrEstacion!=NULL){
        dibujarEstacion(terreno.ptrEstacion,renderer);
    }
}
/*----------------------------------------------------------------------------*/
void destruirTerreno(Terreno &terreno){
    SDL_DestroyTexture(terreno.imagen);
    //la locomotora se destruye en otro lugar, pero aquí hay otros tda:
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
    if(terreno.ptrEstacion!=NULL){
        destruirEstacion(*(terreno.ptrEstacion));
        delete terreno.ptrEstacion;
    }
    //delete &terreno;
}
/*----------------------------------------------------------------------------*/

