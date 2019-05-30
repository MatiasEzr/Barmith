#ifndef __PARTIDA_H__
#define __PARTIDA_H__

#include <SDL.h>
#include "Celda.h"
#include "Terreno.h"
#include "Locomotora.h"
typedef struct{
    bool gameover;
    int intervalo;

    int anchoCelda;
    int altoCelda;
    int altoSprite;

    int filas;
    int columnas;
    int filasTerreno;

    Celda** tablero;

    Terreno** mapa;

    char direccion[4];

}Partida;

void crearPartida(Partida &partida,int filas,int columnas,int anchoCelda,int altoCelda, int altoSprite);
int getAnchoCelda(Partida &partida);
int getAltoCelda(Partida &partida);
int getIntervalo(Partida &partida);
void setIntervalo(Partida &partida, int intervalo);
void setTablero(Partida &partida,SDL_Renderer *renderer);
Celda** getTablero(Partida &partida);
void setTerreno(Partida &partida);
Terreno** getTerreno(Partida &partida);
void dibujarTablero(Partida partida,SDL_Renderer *renderer);
bool getGameOver(Partida &partida);
void setGameOver(Partida &partida, bool flag);
void destruirPartida(Partida &partida);
void ubicarVagon(Partida &partida,PtrNodoVagon ptrNodo);
void ubicarBandido(Partida &partida,Bandido *bandido);
void ubicarMina(Partida &partida,Mina *mina);
void ubicarMoneda(Partida &partida,Moneda *moneda);
void setDireccion(Partida &partida,char direccion[]);
char* getDireccion(Partida &partida);
int getColumnaLimite(Partida &partida);
int getFilaLimite(Partida &partida);
#endif
