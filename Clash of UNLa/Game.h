#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include "Celda.h"
#include "Terreno.h"
#include "Locomotora.h"
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
    bool gameover;
    int intervalo;

    int anchoCelda;
    int altoCelda;
    int altoSprite;

    int fila;
    int columna;
    int filaTerreno;

    Celda** tablero;

    Terreno** terreno;

    char direccion[4];

}Game;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearGame(Game &game);
void setAltoSprite(Game &game,int altoSprite);
int getAltoSprite(Game &game);
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Game &game);
/*----------------------------------------------------------------------------*/
void setAnchoCelda(Game &game,int anchoCelda);
/*----------------------------------------------------------------------------*/
int getAltoCelda(Game &game);
/*----------------------------------------------------------------------------*/
void setAltoCelda(Game &game,int altoCelda);
/*----------------------------------------------------------------------------*/
int getIntervalo(Game &game);
/*----------------------------------------------------------------------------*/
void setIntervalo(Game &game, int intervalo);
/*----------------------------------------------------------------------------*/
Celda** getTablero(Game &game);
/*----------------------------------------------------------------------------*/
void setTablero(Game &game,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
Terreno** getTerreno(Game &game);
/*----------------------------------------------------------------------------*/
void setTerreno(Game &game);
/*----------------------------------------------------------------------------*/
void dibujarTablero(Game game,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
void dibujarSprite(Game game,SDL_Renderer *renderer);

/*----------------------------------------------------------------------------*/
bool getGameOver(Game &game);
/*----------------------------------------------------------------------------*/
void setGameOver(Game &game, bool flag);
/*----------------------------------------------------------------------------*/
void destruirGame(Game &game);
/*----------------------------------------------------------------------------*/
void ubicarVagon(Game &game,PtrNodoVagon ptrNodo);
/*----------------------------------------------------------------------------*/
void ubicarBandido(Game &game,Bandido *bandido);
/*----------------------------------------------------------------------------*/
void ubicarMina(Game &game,Mina *mina);
/*----------------------------------------------------------------------------*/
void ubicarMoneda(Game &game,Moneda *moneda);
/*----------------------------------------------------------------------------*/
void setDireccion(Game &game,char direccion[]);
/*----------------------------------------------------------------------------*/
char* getDireccion(Game &game);
/*----------------------------------------------------------------------------*/
int getColumna(Game &game);
/*----------------------------------------------------------------------------*/
void setColumna(Game &game,int columna);
/*----------------------------------------------------------------------------*/
int getFila(Game &game);
/*----------------------------------------------------------------------------*/
void setFila(Game &game,int fila);
/*----------------------------------------------------------------------------*/
int getFilaTerreno(Game &game);
/*----------------------------------------------------------------------------*/
void setFilaTerreno(Game &game);
#endif
