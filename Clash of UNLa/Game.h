#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include "Celda.h"
#include "Terreno.h"
#include "Lista.h"
#include "Comanda.h"
#include "Parametros.h"
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

    Lista minas;

    Comanda comanda;

    Parametros parametros;
}Game;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearGame(Game &game,int fila,int columna,int anchoCelda,int altoCelda, int altoSprite);
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Game &game);
/*----------------------------------------------------------------------------*/
int getAltoCelda(Game &game);
/*----------------------------------------------------------------------------*/
int getIntervalo(Game &game);
/*----------------------------------------------------------------------------*/
void setIntervalo(Game &game, int intervalo);
/*----------------------------------------------------------------------------*/
void setTablero(Game &game,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
Celda** getTablero(Game &game);
/*----------------------------------------------------------------------------*/
void setTerreno(Game &game);
/*----------------------------------------------------------------------------*/
Terreno** getTerreno(Game &game);
/*----------------------------------------------------------------------------*/
void setMinas(Game &game, SDL_Renderer * renderer);
/*----------------------------------------------------------------------------*/
Lista getMinas(Game &game);

/*----------------------------------------------------------------------------*/
Comanda getComanda(Game &game);
/*----------------------------------------------------------------------------*/
void setComanda(Game &game);
/*----------------------------------------------------------------------------*/

Parametros getParametros(Game &game);
/*----------------------------------------------------------------------------*/
void setParametros(Game &game);
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
void ubicarVagon(Game &game,PtrNodoLista ptrNodo);
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
int getColumnaLimite(Game &game);
/*----------------------------------------------------------------------------*/
int getFilaLimite(Game &game);
/*----------------------------------------------------------------------------*/
#endif
