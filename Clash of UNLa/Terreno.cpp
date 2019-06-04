#include "Terreno.h"
#include "Bandido.h";
#include "Mina.h"
#include "Moneda.h"
#include "Vagon.h"
#include "Lista.h"

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearTerreno(Terreno &terreno,int fila,int columna){
    terreno.fila=fila;
    terreno.columna=columna;

    terreno.ptrNodoVagon=NULL;
    terreno.ptrBandido=NULL;
    terreno.ptrMina=NULL;
    terreno.ptrMoneda=NULL;
}
/*----------------------------------------------------------------------------*/
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
        dibujarVagon(*(Vagon*)terreno.ptrNodoVagon->ptrDato,renderer,intervalo);
    }
}
/*----------------------------------------------------------------------------*/
void destruirTerreno(Terreno &terreno){
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
    //delete &terreno;
}
/*----------------------------------------------------------------------------*/

