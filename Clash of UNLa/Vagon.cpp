#include "Vagon.h"
#include "Item.h"
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <stdlib.h>//permite utilizar itoa(int,char,int);
#include <SDL.h>
#include <SDL_image.h>

void crearVagon(Vagon &vagon,char miniatura[],int fila,int columna, char direccion[], int anchoCelda, int altoCelda, int altoSprite,int capacidad,Item item){
    strcpy(vagon.miniatura,miniatura);
    vagon.fila=fila;//coordenada logica y
    vagon.columna=columna;//coordenada logica x
    strcpy(vagon.direccion,direccion);
    vagon.anchoCelda=anchoCelda;
    vagon.altoCelda=altoCelda;
    vagon.altoSprite=altoSprite;
    vagon.item=item;
}
/*----------------------------------------------------------------------------*/
int getFila(Vagon &vagon){
    return vagon.fila;
}
/*----------------------------------------------------------------------------*/
int getColumna(Vagon &vagon){
    return vagon.columna;
}
/*----------------------------------------------------------------------------*/
void setFila(Vagon &vagon,int desplazamiento){
    vagon.fila=vagon.fila+desplazamiento;
}
/*----------------------------------------------------------------------------*/
void setColumna(Vagon &vagon,int desplazamiento){
    vagon.columna=vagon.columna+desplazamiento;
}
/*----------------------------------------------------------------------------*/
void dibujarVagon(Vagon &vagon,SDL_Renderer* renderer,int intervalo){
    char imagen[10] = "img/";    //strcat(<cadena_destino>, <cadena_fuente>);
    strcat(imagen,vagon.miniatura);  //La funci�n strcat a�ade el contenido de la <cadena_fuente> a la <cadena_destino>.
    strcat(imagen,"/");

    strcat(imagen,vagon.direccion);strcat(imagen,"/");

    char cadenaIntervalo[5];
    itoa(intervalo,cadenaIntervalo,10);
    strcat(imagen,cadenaIntervalo);strcat(imagen,".png");

    //img\c1\aba\0.png

    vagon.imagen=IMG_LoadTexture(renderer,imagen);
    //SDL_QueryTexture(vagon.imagen,NULL,NULL,0,0);//tal vez este no haga filaalta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    //evaluamos los desplazamientos
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    if(strcmp(vagon.direccion,"aba")==0)desplazamientoVertical=1;
    if(strcmp(vagon.direccion,"arr")==0)desplazamientoVertical=-1;
    if(strcmp(vagon.direccion,"der")==0)desplazamientoHorizontal=1;
    if(strcmp(vagon.direccion,"izq")==0)desplazamientoHorizontal=-1;

    vagon.rectImag.y=((vagon.fila*vagon.altoCelda)+vagon.altoCelda-(vagon.altoSprite-vagon.altoCelda))+(desplazamientoVertical*(vagon.altoCelda/10)*intervalo);//coordenada de dibujo y
    vagon.rectImag.x=((vagon.columna*vagon.anchoCelda)+vagon.anchoCelda)+(desplazamientoHorizontal*(vagon.anchoCelda/10)*intervalo);//coordenada de dibujo x
    vagon.rectImag.w=vagon.anchoCelda;//70
    vagon.rectImag.h=vagon.altoSprite;//70

    SDL_RenderCopy(renderer,vagon.imagen,NULL,&(vagon.rectImag));
}
/*----------------------------------------------------------------------------*/
void destruirVagon(Vagon &vagon){
    SDL_DestroyTexture(vagon.imagen);
    //delete &vagon;
}
/*----------------------------------------------------------------------------*/
char* getDireccion(Vagon &vagon){
    return vagon.direccion;
}
/*----------------------------------------------------------------------------*/
void setDireccion(Vagon &vagon,char direccion[]){
    strcpy(vagon.direccion,direccion);
}
/*----------------------------------------------------------------------------*/