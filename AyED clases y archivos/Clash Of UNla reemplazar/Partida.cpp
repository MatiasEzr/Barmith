#include <string.h>
#include <SDL.h>
#include "Partida.h"
#include "Bandido.h"
#include "Celda.h"
#include <ctime> //time.h agrega funciones en base al reloj del procesador.
#include <stdlib.h>
#include "Mina.h"

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearPartida(Partida &partida,int filas,int columnas,int anchoCelda,int altoCelda,int altoSprite){
    partida.gameOver=false;
    partida.intervalo=0;

    partida.anchoCelda=anchoCelda;
    partida.altoCelda=altoCelda;
    partida.altoSprite=altoSprite;

    partida.filas=filas;
    partida.columnas=columnas;

   partida.tablero= new Celda*[partida.filas];
    for (int f = 0; f < partida.filas; f++){
        partida.tablero[f] = new Celda[partida.columnas];
    }

    partida.terreno= new Terreno*[partida.filasTerreno];
    for (int f = 0; f < partida.filasTerreno; f++){
        partida.terreno[f] = new Terreno[partida.columnas];
    }
    strcpy(partida.direccion,"aba");

}
int getAnchoCelda(Partida &partida){
    return partida.anchoCelda;
}
int getAltoCelda(Partida &partida){
    return partida.altoCelda;
}
int getIntervalo(Partida &partida){
    return partida.intervalo;
}
void setIntervalo(Partida &partida, int intervalo){
    partida.intervalo=intervalo;
}
void setTablero(Partida &partida,SDL_Renderer* renderer){
    srand(time(0));//semilla para aleatorio: cambia el valor inicial del random dentro de la libreria stdlib.h
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            Celda celda;

            char aux [2];//cadena que guarda valores entre 0 y 4
            itoa((rand()%6),aux,10);//valor aleatorio entre 0 y 4, pasados a string en base 10
            crearCelda(celda,f,c,getAnchoCelda(partida),getAltoCelda(partida),renderer,aux);
            partida.tablero[f][c]=celda;

        }
    }
}
Celda** getTablero(Partida &partida){
    return partida.tablero;
}
void setTerreno(Partida &partida){
    for(int f=0;f<partida.filasTerreno;f++){
        for(int c=0;c<partida.columnas;c++){
            Terreno terreno;
            crearTerreno(terreno,f,c);
            partida.terreno[f][c]=terreno;
        }
    }
}
Terreno** getTerreno(Partida &partida){
    return partida.terreno;
}
void dibujarTablero(Partida partida,SDL_Renderer *renderer){
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            dibujarCelda(renderer,partida.tablero[f][c]);
        }
    }
    for(int f=0;f<partida.filasTerreno;f++){
        for(int c=0;c<partida.columnas;c++){
            dibujarTerreno(renderer,partida.terreno[f][c],partida.intervalo);
        }
    }
}
void destruirPartida(Partida &partida){
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            destruirCelda(partida.tablero[f][c]);
        }
    }
    for(int f=0;f<partida.filasTerreno;f++){
        for(int c=0;c<partida.columnas;c++){
            destruirTerreno(partida.terreno[f][c]);
        }
    }
    //delete &partida;
}
bool getGameOver(Partida &partida){
    return partida.gameOver;
}
void setGameOver(Partida &partida, bool flag){
    partida.gameOver=flag;
}
void ubicarVagon(Partida &partida,PtrNodoVagon ptrNodo){
    partida.tablero[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;//Celda.ptrNosoVagon=ptrNodo
    partida.terreno[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;//Terreno.ptrNosoVagon=ptrNodo
}
void ubicarBandido(Partida &partida,Bandido *bandido){

    partida.tablero[getFila(bandido)][getColumna(bandido)].ptrBandido=bandido;
    partida.terreno[(getFila(bandido)*2)-1][getColumna(bandido)].ptrBandido=bandido;

}
void ubicarMina(Partida &partida,Mina *mina){
    partida.tablero[getFila(mina)][getColumna(mina)].ptrMina=mina;
    int ajusteFila=(getFila(mina)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.terreno[ajusteFila][getColumna(mina)].ptrMina=mina;
}
/*void ubicarItem(Partida &partida,Item *item){
    partida.tablero[getFila(item)][getColumna(item)].ptrItem=item;
    int ajusteFila=(getFila(item)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.terreno[ajusteFila][getColumna(item)].ptrItem=item;
}*/
void ubicarMoneda(Partida &partida,Moneda *moneda){
    partida.tablero[getFila(moneda)][getColumna(moneda)].ptrMoneda=moneda;
    int ajusteFila=(getFila(moneda)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.terreno[ajusteFila][getColumna(moneda)].ptrMoneda=moneda;
}
void setDireccion(Partida &partida,char direccion[]){
    strcpy(partida.direccion,direccion);
}
char* getDireccion(Partida &partida){
    return partida.direccion;
}
int getColumnaLimite(Partida &partida){
    return partida.columnas;
}
int getFilaLimite(Partida &partida){
    return partida.filas;
}
