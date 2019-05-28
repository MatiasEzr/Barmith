#include "Mapa.h"
//include vehiculo
#include "Bandido.h";
#include "Minas.h"
//include monedas

void crearMapa(Mapa &mapa,int f,int c){
    mapa.f=f;//coordenada logica y
    mapa.c=c;//coordenada logica x

    mapa.ptrNodoCarro=NULL;//al principio no tiene carros
    mapa.ptrBandido=NULL;//un unico bandido por casilla
    mapa.ptrMina=NULL;
    mapa.ptrMoneda=NULL;
}
void dibujarMapa(SDL_Renderer* renderer,Mapa &mapa, int intervalo){
    if(mapa.ptrBandido!=NULL){
        dibujarBandido (mapa.ptrBandido,renderer);
    }
    if(mapa.ptrMina!=NULL){
        dibujarMina(mapa.ptrMina,renderer);
    }
    if(mapa.ptrMoneda!=NULL){
        dibujarMoneda(mapa.ptrMoneda,renderer);
    }
    if(mapa.ptrNodoCarro!=NULL){
        dibujarCarro(mapa.ptrNodoCarro->carro,renderer,intervalo);
    }
}
void destruirMapa(Mapa &mapa){
    //la caravana se destruye en otro lugar, pero aquí hay otros tda:
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

