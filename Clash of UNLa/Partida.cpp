#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <SDL.h>
#include "Partida.h"
#include "Celda.h"
#include "Terreno.h"
#include "Locomotora.h"
#include "Bandido.h"
#include <ctime> //time.h o ctime agregan funciones que leen el reloj interno del procesador. la funcion time(NULL) devuelve el tiempo actual en milisegundos. la usamos para los aleatorios.
#include <stdlib.h>//permite utilizar itoa(int,char,int); y la funcion para aleatorios rand()

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearPartida(Partida &partida,int filas,int columnas,int anchoCelda,int altoCelda,int altoSprite){
    partida.gameover=false;
    partida.intervalo=0;

    partida.anchoCelda=anchoCelda;
    partida.altoCelda=altoCelda;
    partida.altoSprite=altoSprite;

    partida.filas=filas;
    partida.columnas=columnas;
    partida.filasTerreno = (filas*2)-1;

    partida.tablero= new Celda*[partida.filas];
    for (int f = 0; f < partida.filas; f++){
        partida.tablero[f] = new Celda[partida.columnas];
    }

    partida.mapa= new Terreno*[partida.filasTerreno];
    for (int f = 0; f < partida.filasTerreno; f++){
        partida.mapa[f] = new Terreno[partida.columnas];
    }
    strcpy(partida.direccion,"direccion");

//Prototipo de strcpy char *strcpy (char *cadena1, const char *cadena2);
//Sirve para copiar la cadena cadena2 dentro de cadena1. Devuelve el valor de cadena1. strcpy recibe dos parámetros:
//un apuntador a char (modificable), y un apuntador a char constante. Y devuelve un apuntador a char.
}
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Partida &partida){
    return partida.anchoCelda;
}
/*----------------------------------------------------------------------------*/
int getAltoCelda(Partida &partida){
    return partida.altoCelda;
}
/*----------------------------------------------------------------------------*/
int getIntervalo(Partida &partida){
    return partida.intervalo;
}
/*----------------------------------------------------------------------------*/
void setIntervalo(Partida &partida, int intervalo){
    partida.intervalo=intervalo;
}
/*----------------------------------------------------------------------------*/
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
/*----------------------------------------------------------------------------*/
Celda** getTablero(Partida &partida){
    return partida.tablero;
}
/*----------------------------------------------------------------------------*/
void setTerreno(Partida &partida){
    for(int f=0;f<partida.filasTerreno;f++){
        for(int c=0;c<partida.columnas;c++){
            Terreno mapa;
            crearTerreno(mapa,f,c);
            partida.mapa[f][c]=mapa;
        }
    }
}
/*----------------------------------------------------------------------------*/
Terreno** getTerreno(Partida &partida){
    return partida.mapa;
}
/*----------------------------------------------------------------------------*/
void dibujarTablero(Partida partida,SDL_Renderer *renderer){
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            dibujarCelda(renderer,partida.tablero[f][c]);
        }
    }
    for(int f=0;f<partida.filasTerreno;f++){
        for(int c=0;c<partida.columnas;c++){
            dibujarTerreno(renderer,partida.mapa[f][c],partida.intervalo);
        }
    }
}
/*----------------------------------------------------------------------------*/
void destruirPartida(Partida &partida){
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            destruirCelda(partida.tablero[f][c]);
        }
    }
    for(int f=0;f<partida.filasTerreno;f++){
        for(int c=0;c<partida.columnas;c++){
            destruirTerreno(partida.mapa[f][c]);
        }
    }
    //delete &partida;
}
/*----------------------------------------------------------------------------*/
bool getGameOver(Partida &partida){
    return partida.gameover;
}
/*----------------------------------------------------------------------------*/
void setGameOver(Partida &partida, bool flag){
    partida.gameover=flag;
}
/*----------------------------------------------------------------------------*/
void ubicarVagon(Partida &partida,PtrNodoVagon ptrNodo){
    partida.tablero[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;//celda.ptrNosoVagon=ptrNodo
    partida.mapa[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;//mapa.ptrNosoVagon=ptrNodo
}
/*----------------------------------------------------------------------------*/
void ubicarBandido(Partida &partida,Bandido *bandido){
    partida.tablero[getFila(bandido)][getColumna(bandido)].ptrBandido=bandido;
    partida.mapa[(getFila(bandido)*2)-1][getColumna(bandido)].ptrBandido=bandido;
}
/*----------------------------------------------------------------------------*/
void ubicarMina(Partida &partida,Mina *mina){
    partida.tablero[getFila(mina)][getColumna(mina)].ptrMina=mina;
    int ajusteFila=(getFila(mina)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.mapa[ajusteFila][getColumna(mina)].ptrMina=mina;
}
/*----------------------------------------------------------------------------*/
void ubicarMoneda(Partida &partida,Moneda *moneda){
    partida.tablero[getFila(moneda)][getColumna(moneda)].ptrMoneda=moneda;
    int ajusteFila=(getFila(moneda)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.mapa[ajusteFila][getColumna(moneda)].ptrMoneda=moneda;
}
/*----------------------------------------------------------------------------*/
void setDireccion(Partida &partida,char direccion[]){
    strcpy(partida.direccion,direccion);
}
char* getDireccion(Partida &partida){
    return partida.direccion;
}
/*----------------------------------------------------------------------------*/
int getColumnaLimite(Partida &partida){
    return partida.columnas;
}
/*----------------------------------------------------------------------------*/
int getFilaLimite(Partida &partida){
    return partida.filas;
}
/*----------------------------------------------------------------------------*/
