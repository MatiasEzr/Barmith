#include <string.h>
#include <SDL.h>
#include "Game.h"
#include "Celda.h"
#include "Terreno.h"
#include "Locomotora.h"
#include "Bandido.h"
#include <ctime> //time.h o ctime agregan funciones que leen el reloj interno del procesador. la funcion time(NULL) devuelve el tiempo actual en milisegundos. la usamos para los aleatorios.
#include <stdlib.h>//permite utilizar itoa(int,char,int); y la funcion para aleatorios rand()

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearGame(Game &game){
    game.gameover=false;
    game.intervalo=0;
    game.altoSprite=0;
    game.anchoCelda=0;
    game.altoCelda=0;

    game.fila=0;
    game.columna=0;
    game.filaTerreno =0;

    game.tablero= 0;
    game.terreno= 0;
    strcpy(game.direccion,"aba");

}
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Game &game){
    return game.anchoCelda;
}
/*----------------------------------------------------------------------------*/
void setAnchoCelda(Game &game,int anchoCelda){
    game.anchoCelda=anchoCelda;
}
/*----------------------------------------------------------------------------*/

int getAltoCelda(Game &game){
    return game.altoCelda;
}
/*----------------------------------------------------------------------------*/
void setAltoCelda(Game &game,int altoCelda){
    game.altoCelda=altoCelda;
}
/*----------------------------------------------------------------------------*/
int getAltoSprite(Game &game){
    return game.altoSprite;
}
/*----------------------------------------------------------------------------*/
void setAltoSprite(Game &game,int altoSprite){
    game.altoSprite=altoSprite;
}
/*----------------------------------------------------------------------------*/
int getIntervalo(Game &game){
    return game.intervalo;
}
/*----------------------------------------------------------------------------*/
void setIntervalo(Game &game, int intervalo){
    game.intervalo=intervalo;
}
/*----------------------------------------------------------------------------*/
void setTablero(Game &game,SDL_Renderer* renderer){
    game.tablero= new Celda*[game.fila];
    for (int f = 0; f < game.fila; f++){
        game.tablero[f] = new Celda[game.columna];
    }
    srand(time(0));
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            Celda celda;

            char aux [2];//cadena que guarda valores entre 0 y 4
            itoa((rand()%6),aux,10);//valor aleatorio entre 0 y 4, pasados a string en base 10
            crearCelda(celda,f,c,getAnchoCelda(game),getAltoCelda(game),renderer,aux);
            game.tablero[f][c]=celda;
        }
    }
}
/*----------------------------------------------------------------------------*/
Celda** getTablero(Game &game){
    return game.tablero;
}
/*----------------------------------------------------------------------------*/

void setTerreno(Game &game){
game.terreno=new Terreno*[game.filaTerreno];
   for (int f = 0; f < game.filaTerreno; f++){
        game.terreno[f] = new Terreno[game.columna];
    }

    for(int f=0;f<game.filaTerreno;f++){
        for(int c=0;c<game.columna;c++){
            Terreno terreno;
            crearTerreno(terreno,f,c);
            game.terreno[f][c]=terreno;
        }
    }
}

/*----------------------------------------------------------------------------*/
Terreno** getTerreno(Game &game){
    return game.terreno;
}
/*----------------------------------------------------------------------------*/
void dibujarTablero(Game game,SDL_Renderer *renderer){
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            dibujarCelda(renderer,game.tablero[f][c]);
        }
    }

}
/*----------------------------------------------------------------------------*/
void dibujarSprite(Game game,SDL_Renderer *renderer){
 for(int f=0;f<game.filaTerreno;f++){
        for(int c=0;c<game.columna;c++){
            dibujarTerreno(renderer,game.terreno[f][c],game.intervalo);
        }
    }
}
void destruirGame(Game &game){
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            destruirCelda(game.tablero[f][c]);
        }
    }
    for(int f=0;f<game.filaTerreno;f++){
        for(int c=0;c<game.columna;c++){
            destruirTerreno(game.terreno[f][c]);
        }
    }
    //delete &game;
}
/*----------------------------------------------------------------------------*/
bool getGameOver(Game &game){
    return game.gameover;
}
/*----------------------------------------------------------------------------*/
void setGameOver(Game &game, bool flag){
    game.gameover=flag;
}
/*----------------------------------------------------------------------------*/
void ubicarVagon(Game &game,PtrNodoVagon ptrNodo){
    game.tablero[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;//celda.ptrNosoVagon=ptrNodo
    game.terreno[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;//terreno.ptrNosoVagon=ptrNodo
}
/*----------------------------------------------------------------------------*/
void ubicarBandido(Game &game,Bandido *bandido){
    game.tablero[getFila(bandido)][getColumna(bandido)].ptrBandido=bandido;
    game.terreno[(getFila(bandido)*2)-1][getColumna(bandido)].ptrBandido=bandido;
}
/*----------------------------------------------------------------------------*/
void ubicarMina(Game &game,Mina *mina){
    game.tablero[getFila(mina)][getColumna(mina)].ptrMina=mina;
    int ajusteFila=(getFila(mina)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    game.terreno[ajusteFila][getColumna(mina)].ptrMina=mina;
}
/*----------------------------------------------------------------------------*/
void ubicarMoneda(Game &game,Moneda *moneda){
    game.tablero[getFila(moneda)][getColumna(moneda)].ptrMoneda=moneda;
    int ajusteFila=(getFila(moneda)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    game.terreno[ajusteFila][getColumna(moneda)].ptrMoneda=moneda;
}
/*----------------------------------------------------------------------------*/
void setDireccion(Game &game,char direccion[]){
    strcpy(game.direccion,direccion);
}
char* getDireccion(Game &game){
    return game.direccion;
}
/*----------------------------------------------------------------------------*/
int getFila(Game &game){
    return game.fila;
}
/*----------------------------------------------------------------------------*/

void setFila(Game &game,int fila){
    game.fila=fila;
}
/*----------------------------------------------------------------------------*/

int getColumna(Game &game){
    return game.columna;
}
/*----------------------------------------------------------------------------*/

void setColumna(Game &game,int columna){
    game.columna=columna;
}
/*----------------------------------------------------------------------------*/

int getFilaTerreno(Game &game){
    return game.filaTerreno;
}
/*----------------------------------------------------------------------------*/
void setFilaTerreno(Game &game){
  game.filaTerreno=(getFila(game)*2)-1;
}
