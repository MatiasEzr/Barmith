#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include "Celda.h"
#include "Terreno.h"
#include "Lista.h"
#include "Comanda.h"
#include "Parametros.h"
#include "Estacion.h"
#include "Vagon.h"
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
    bool gameover;
    int intervalo;
    int contadorSegundo;
    int contadorMonedas;
    int anchoCelda;
    int altoCelda;
    int fila;
    int columna;

    Terreno** terreno;
    char direccion[4];
    Lista minas;
    Lista comanda;
    Parametros parametros;
}Game;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearGame(Game &game,int fila,int columna,int anchoCelda,int altoCelda);
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Game &game);
/*----------------------------------------------------------------------------*/
int getAltoCelda(Game &game);
/*----------------------------------------------------------------------------*/
int getIntervalo(Game &game);
/*----------------------------------------------------------------------------*/
void setIntervalo(Game &game, int intervalo);
/*----------------------------------------------------------------------------*/
int getContadorSegundo(Game &game);

/*----------------------------------------------------------------------------*/
void setContadorSegundo(Game &game,int contadorSegundo);
/*----------------------------------------------------------------------------*/
void setTerreno(Game &game, SDL_Renderer * renderer);
/*----------------------------------------------------------------------------*/
Terreno** getTerreno(Game &game);
/*----------------------------------------------------------------------------*/
void leerMinas(Game &game, SDL_Renderer * renderer);
/*----------------------------------------------------------------------------*/
Lista getMinas(Game &game);

/*----------------------------------------------------------------------------*/
Lista getComanda(Game &game);
/*----------------------------------------------------------------------------*/
void leerComanda(Game &game);
/*----------------------------------------------------------------------------*/

Parametros getParametros(Game &game);
/*----------------------------------------------------------------------------*/
void setParametros(Game &game, string clave, string valor);
/*----------------------------------------------------------------------------*/
void leerParametros(Game &game);
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void dibujarTerreno(Game game,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
void dibujarEntidades(Game game,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
bool getGameOver(Game &game);
/*----------------------------------------------------------------------------*/
void setGameOver(Game &game, bool flag);
/*----------------------------------------------------------------------------*/
void destruirGame(Game &game,SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
void ubicarVagon(Game &game,PtrNodoLista ptrNodo);
/*----------------------------------------------------------------------------*/
void ubicarBandido(Game &game,Bandido *bandido);
/*----------------------------------------------------------------------------*/
void ubicarMina(Game &game,Mina *mina);
/*----------------------------------------------------------------------------*/
void ubicarMoneda(Game &game,Moneda *moneda);
/*----------------------------------------------------------------------------*/
void ubicarEstacion(Game &game,Estacion *estacion);
/*----------------------------------------------------------------------------*/
void setDireccion(Game &game,char direccion[]);
/*----------------------------------------------------------------------------*/
char* getDireccion(Game &game);
/*----------------------------------------------------------------------------*/
int getColumna(Game &game);
/*----------------------------------------------------------------------------*/
int getFila(Game &game);
/*----------------------------------------------------------------------------*/
void evaluarColision(Game &game,Lista &locomotora,Lista &monedas,Lista &bandidos,SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
void actualizarMinas(Game &game);
/*----------------------------------------------------------------------------*/
int contadorMonedas(Game &game);
void setContadorMonedas(Game &game, int contadorMonedas);
/*----------------------------------------------------------------------------*/
void generarBandidos(Game &game,Lista &bandidos, SDL_Renderer* renderer,int VB);
/*----------------------------------------------------------------------------*/
void generarMonedas(Game &game,Lista &monedas, SDL_Renderer* renderer,int VM);
/*----------------------------------------------------------------------------*/
void actualizarBandidos(Game &game,Lista &bandidos, SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
void actualizarMonedas(Game &game,Lista &monedas, SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
void dibujarPuntuacion(Game &game, SDL_Renderer * renderer, Lista &locomotora);
/*----------------------------------------------------------------------------*/
void nuevaPosicionVagon(Game &game, Vagon * ultimo, int &posX, int &posY, char * direccion);
/*----------------------------------------------------------------------------*/
void agregarVagon(Game &game, Lista &locomotora, Estacion &estacion);
/*----------------------------------------------------------------------------*/
int numeroStringRand(string numero);
/*----------------------------------------------------------------------------*/
void encuentroConBandido(Game &game, Lista &locomotora, Lista &bandidos);
/*----------------------------------------------------------------------------*/
void pedirItem(Game &game,Lista &locomotora, Bandido &bandido);
/*----------------------------------------------------------------------------*/


void controlarEventos(Game &game,SDL_Event &event,const unsigned char *keys);
void cambiarDireccion(Game &game,Lista &locomotora);

void cambiarFila(Game &game,PtrNodoLista ptrNodo);
void cambiarColumna(Game &game,PtrNodoLista ptrNodo);
bool evaluarColisiones(Game &game,PtrNodoLista ptrNodo);
#endif
