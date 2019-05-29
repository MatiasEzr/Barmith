#include <string.h>
#include <SDL.h>
#include "Partida.h"
#include "Bandido.h"
#include "Celda.h"
#include <ctime> //time.h agrega funciones en base al reloj del procesador.
#include <stdlib.h>

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearPartida(Partida &partida,int filas,int columnas,int anchoCelda,int altoCelda,int altoSprite){
    partida.fin=false;
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
        partida.Terreno[f] = new Terreno[partida.columnas];
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
            Celda Celda;

            char aux [2];//cadena que guarda valores entre 0 y 4
            itoa((rand()%6),aux,10);//valor aleatorio entre 0 y 4, pasados a string en base 10
            crearCelda(Celda,f,c,getAnchoCelda(partida),getAltoCelda(partida),renderer,aux);
            partida.tablero[f][c]=Celda;
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
            destruirTerreno(partida.Terreno[f][c]);
        }
    }
    //delete &partida;
}
bool getfin(Partida &partida){
    return partida.fin;
}
void setfin(Partida &partida, bool flag){
    partida.fin=flag;
}
/*void ubicarVagon(Partida &partida,PtrNodoCarro ptrNodo){
    partida.tablero[getFila(ptrNodo->carro)][getColumna(ptrNodo->carro)].ptrNodoCarro=ptrNodo;//Celda.ptrNosoCarro=ptrNodo
    partida.terreno[getFila(ptrNodo->carro)*2][getColumna(ptrNodo->carro)].ptrNodoCarro=ptrNodo;//Terreno.ptrNosoCarro=ptrNodo
}*/
void ubicarBandido(Partida &partida,Bandido *bandido){
    partida.tablero[getFila(bandido)][getColumna(bandido)].ptrBandido=bandido;
    partida.terreno[(getFila(bandido)*2)-1][getColumna(bandido)].ptrBandido=bandido;
}
void ubicarMinas(Partida &partida,Minas *minas){
    partida.tablero[getFila(minas)][getColumna(minas)].ptrMinas=minas;
    int ajusteFila=(getFila(minas)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.terreno[ajusteFila][getColumna(minas)].ptrMinas=minas;
}
void ubicarItem(Partida &partida,Item *item){
    partida.tablero[getFila(item)][getColumna(item)].ptrItem=item;
    int ajusteFila=(getFila(item)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.terreno[ajusteFila][getColumna(item)].ptrItem=item;
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