#include "Mina.h"
#include "Vagon.h"
#include "Caja.h"
#include <SDL.h>
#include <SDL_image.h>
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCelda, int altoCelda,
               int altoSprite, int ip, int secuencia[5], string codItem){
    mina.c=c;//coordenada logica x
    mina.f=f;//coordenada logica y
    mina.ip=ip;//intervalo de produccion
    mina.codItem=codItem;//item de la mina
    for(int i=0;i<5;i++){
        mina.secuencia[i] = secuencia[i];
    }
    mina.intervaloActual = 0;

    mina.imagen=IMG_LoadTexture(renderer,"img/mina.png");

    mina.rectImag.y=(mina.f*altoCelda);//coordenada de dibujo y
    mina.rectImag.x=(mina.c*anchoCelda);//coordenada de dibujo x
    mina.rectImag.w=anchoCelda;//ancho
    mina.rectImag.h=altoSprite;//alto

    crearCola(mina.cajas);
}
/*----------------------------------------------------------------------------*/
int getFila(Mina *mina){
    return mina->f;
}
/*----------------------------------------------------------------------------*/
void setFila(Mina &mina, int fila){
    mina.f = fila;
}
/*----------------------------------------------------------------------------*/
int getColumna(Mina *mina){
    return mina->c;
}
/*----------------------------------------------------------------------------*/
void setColumna(Mina &mina, int columna){
    mina.c = columna;
}
/*----------------------------------------------------------------------------*/
int getIP(Mina &mina){
    return mina.ip;
}
/*----------------------------------------------------------------------------*/
void setIP(Mina &mina, int IP){
    mina.ip = IP;
}
/*----------------------------------------------------------------------------*/
int* getSecuencia(Mina &mina){
    return mina.secuencia;
}
/*----------------------------------------------------------------------------*/
void setSecuencia(Mina &mina, int secuencia[5]){
    for(int i=0;i<5;i++){
        mina.secuencia[i] = secuencia[i];
    }
}
/*----------------------------------------------------------------------------*/
int getSecuenciaActual(Mina &mina){
    return mina.secuenciaActual;
}
/*----------------------------------------------------------------------------*/
void setSecuenciaActual(Mina &mina, int secuencia){
    mina.secuenciaActual = secuencia;
}
/*----------------------------------------------------------------------------*/
int getIntervarloActual(Mina &mina){
    return mina.intervaloActual;
}
/*----------------------------------------------------------------------------*/
void setIntervaloActual(Mina &mina, int intervalo){
    mina.intervaloActual = intervalo;
}
/*----------------------------------------------------------------------------*/
string getCodItem(Mina *mina){
    return mina->codItem;
}
/*----------------------------------------------------------------------------*/
void setCodItem(Mina &mina, string codItem){
    mina.codItem = codItem;
}
/*----------------------------------------------------------------------------*/
void dibujarMina(Mina *mina,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,mina->imagen,NULL,&(mina->rectImag));
}
/*----------------------------------------------------------------------------*/
void destruirMina(Mina *mina){
    SDL_DestroyTexture(mina->imagen);
    eliminarCola(mina->cajas);
}
/*----------------------------------------------------------------------------*/
void recolectarCajas(Mina &mina, Lista &locomotora){
    PtrNodoLista ptrVagon = primero(locomotora);

    while(ptrVagon!=finLista()){
        Vagon *vagon = (Vagon*)ptrVagon->ptrDato;
        if(getCodItem(*vagon)==getCodItem(&mina) || getCodItem(*vagon)=="nada"){
            PtrNodoCola ptrCaja = colaFrente(mina.cajas);
            while(ptrCaja!=finCola()){
                Caja * caja = (Caja*) ptrCaja->ptrDato;
                if((getCapacidad(*vagon)-getCantidadItem(*vagon))>=getCapacidadMaxima(*caja)){
                    if(getCodItem(*vagon)=="nada"){
                        setCodItem(*vagon, getCodItem(&mina));
                    }
                    Caja * cajaLista = new Caja;
                    *cajaLista = *(Caja*)desencolar(mina.cajas);
                    agregar(*getCajas(*vagon), cajaLista);
                    setCantidadItem(*vagon,getCapacidadMaxima(*cajaLista)+getCantidadItem(*vagon));
                    ptrCaja = colaFrente(mina.cajas);
                }
                else{ ptrCaja = finCola();}
            }
        }
        ptrVagon = siguiente(locomotora, ptrVagon);
    }
}
/*----------------------------------------------------------------------------*/
