#include "Vagon.h"
#include "Item.h"
#include "Pila.h"
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <stdlib.h>//permite utilizar itoa(int,char,int);
#include <SDL.h>
#include <SDL_image.h>

void crearVagon(Vagon &vagon,char miniatura[],int fila,int columna, char direccion[], int anchoCelda, int altoCelda,int capacidad,string item){
    strcpy(vagon.miniatura,miniatura);
    vagon.fila= fila;//coordenada logica y
    vagon.columna=columna;//coordenada logica x
    strcpy(vagon.direccion,direccion);
    vagon.anchoCelda=anchoCelda;
    vagon.altoCelda= altoCelda;
    vagon.detenido=false;
    crearPila(vagon.cajas);
    vagon.capacidad = capacidad;
    vagon.cantidadItem = 0;
    vagon.codItem=item;
}
/*----------------------------------------------------------------------------*/
char* getMiniatura(Vagon &vagon){
    return vagon.miniatura;
}
/*----------------------------------------------------------------------------*/
void setMiniatura(Vagon &vagon,char miniatura[]){
    strcpy(vagon.miniatura,miniatura);
}
/*----------------------------------------------------------------------------*/

int getFila(Vagon &vagon){
    return vagon.fila;
}
/*----------------------------------------------------------------------------*/
void setFila(Vagon &vagon,int desplazamiento){
    vagon.fila=vagon.fila+desplazamiento;
}
/*----------------------------------------------------------------------------*/
int getColumna(Vagon &vagon){
    return vagon.columna;
}

/*----------------------------------------------------------------------------*/
void setColumna(Vagon &vagon,int desplazamiento){
    vagon.columna=vagon.columna+desplazamiento;
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Vagon &vagon){
    return vagon.anchoCelda;
}
/*----------------------------------------------------------------------------*/
void setAnchoCelda(Vagon &vagon,int anchoCelda){
    vagon.anchoCelda=anchoCelda;
}
/*----------------------------------------------------------------------------*/

int getAltoCelda(Vagon &vagon){
    return vagon.altoCelda;
}
/*----------------------------------------------------------------------------*/
void setAltoCelda(Vagon &vagon,int altoCelda){
    vagon.altoCelda=altoCelda;
}
/*----------------------------------------------------------------------------*/
int getAltoSprite(Vagon &vagon){
    return vagon.altoSprite;
}
/*----------------------------------------------------------------------------*/
void setAltoSprite(Vagon &vagon,int altoSprite){
    vagon.altoSprite=altoSprite;
}
/*----------------------------------------------------------------------------*/


void dibujarVagon(Vagon &vagon,SDL_Renderer* renderer,int intervalo){
    char imagen[10] = "img/";    //strcat(<cadena_destino>, <cadena_fuente>);
    strcat(imagen,vagon.miniatura);  //La función strcat añade el contenido de la <cadena_fuente> a la <cadena_destino>.
    strcat(imagen,"/");

    strcat(imagen,vagon.direccion);strcat(imagen,"/");

    if(!(vagon.detenido)){
        char cadenaIntervalo[5];
        itoa(intervalo,cadenaIntervalo,10);
        strcat(imagen,cadenaIntervalo);
    }
    else{
        strcat(imagen,"0");
    }
    strcat(imagen,".png");
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

    if(!(vagon.detenido)){
        vagon.rectImag.y= vagon.fila*vagon.altoCelda +(desplazamientoVertical*(vagon.altoCelda/10)*intervalo);//coordenada de dibujo y
        vagon.rectImag.x= vagon.columna*vagon.anchoCelda +(desplazamientoHorizontal*(vagon.anchoCelda/10)*intervalo);//coordenada de dibujo x
        vagon.rectImag.w=vagon.anchoCelda;
        vagon.rectImag.h=vagon.altoCelda;
    }
    else{
        vagon.rectImag.y= vagon.fila*vagon.altoCelda;//coordenada de dibujo y
        vagon.rectImag.x= vagon.columna*vagon.anchoCelda;//coordenada de dibujo x
        vagon.rectImag.w=vagon.anchoCelda;
        vagon.rectImag.h=vagon.altoCelda;
    }

    SDL_RenderCopy(renderer,vagon.imagen,NULL,&(vagon.rectImag));
}
/*----------------------------------------------------------------------------*/
void destruirVagon(Vagon &vagon){
    SDL_DestroyTexture(vagon.imagen);
    eliminarPila(vagon.cajas);
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
int getCapacidad(Vagon &vagon){
    return vagon.capacidad;
}
/*----------------------------------------------------------------------------*/
void setCapacidad(Vagon &vagon, int capacidad){
    vagon.capacidad = capacidad;
}
/*----------------------------------------------------------------------------*/
int getCantidadItem(Vagon &vagon){
    return vagon.cantidadItem;
}
/*----------------------------------------------------------------------------*/
void setCantidadItem(Vagon &vagon, int cantidadItem){
    vagon.cantidadItem = cantidadItem;
}
/*----------------------------------------------------------------------------*/
string getCodItem(Vagon &vagon){
    return vagon.codItem;
}
/*----------------------------------------------------------------------------*/
void setCodItem(Vagon &vagon, string codItem){
    vagon.codItem = codItem;
}
/*----------------------------------------------------------------------------*/
Pila * getCajas(Vagon &vagon){
    return &(vagon.cajas);
}
/*----------------------------------------------------------------------------*/
void setCajas(Vagon &vagon, Pila cajas){
    vagon.cajas = cajas;
}
/*----------------------------------------------------------------------------*/
