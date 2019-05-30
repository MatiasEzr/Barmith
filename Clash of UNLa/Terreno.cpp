#include "Terreno.h"
#include "Locomotora.h"
#include "Bandido.h";
#include "Mina.h"
#include "Moneda.h"

void crearTerreno(Terreno &mapa,int f,int c){
    mapa.f=f;//coordenada logica y
    mapa.c=c;//coordenada logica x

    mapa.ptrNodoVagon=NULL;//al principio no tiene vagons
    mapa.ptrBandido=NULL;//un unico bandido por casilla
    mapa.ptrMina=NULL;
    mapa.ptrMoneda=NULL;
}
void dibujarTerreno(SDL_Renderer* renderer,Terreno &mapa, int intervalo){
    if(mapa.ptrBandido!=NULL){
        dibujarBandido(mapa.ptrBandido,renderer);
    }
    if(mapa.ptrMina!=NULL){
        dibujarMina(mapa.ptrMina,renderer);
    }
    if(mapa.ptrMoneda!=NULL){
        dibujarMoneda(mapa.ptrMoneda,renderer);
    }
    if(mapa.ptrNodoVagon!=NULL){
        dibujarVagon(mapa.ptrNodoVagon->vagon,renderer,intervalo);
    }
}
void destruirTerreno(Terreno &mapa){
    //la locomotora se destruye en otro lugar, pero aquí hay otros tda:
    if(mapa.ptrBandido!=NULL){
        destruirBandido(mapa.ptrBandido);
        delete mapa.ptrBandido;
    }
    if(mapa.ptrMina!=NULL){
        destruirMina(mapa.ptrMina);
        delete mapa.ptrMina;
    }
    if(mapa.ptrMoneda!=NULL){
        destruirMoneda(mapa.ptrMoneda);
        delete mapa.ptrMoneda;
    }
    //delete &mapa;
}

