#ifndef __PARTIDA_H__
#define __PARTIDA_H__

#include <SDL.h>
#include "Bandido.h"

/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/

typedef struct{
    bool fin;
    int intervalo;

    int anchoCelda;
    int altoCelda;
    int altoSprite;

    int filas;
    int columnas;
    int filasTerreno;

   // Celda** tablero;

   // Terreno** terreno;

    char direccion[4];

}Partida;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/

/*
  pre : No debe estar creado la partida
  post : Se crea la partida y establece un tablero
*/
void crearPartida(Partida &partida,int filas,int columnas,int anchoCelda,int altoCelda, int altoSprite);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : se obtiene el ancho de la celda del tablero
*/
int getAnchoCelda(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : se obtiene el alto de la celda del tablero
*/
int getAltoCelda(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : se obtiene el tiempo en el cual se basara la partida
*/
int getIntervalo(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada y establecido un valor de intervalo
  post : se modifica el valor del intervalo de la partida
*/
void setIntervalo(Partida &partida, int intervalo);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : se setea un dato al tablero y asigna renderizado
*/
void setTablero(Partida &partida,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : se obtiene una celda del tablero
*/
//Celda** getTablero(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida y el terreno debieron ser creadas
  post : se asigna el terreno pasado por parametro
*/
void setTerreno(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida y el terreno debieron ser creados
  post : se obtiene el terreno pasado por parametro
*/
//Terreno** getTerreno(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : dibuja las celdas del tablero y asigna renderizado
*/
void dibujarTablero(Partida partida,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : devolvera el inicio o el fin del programa
*/
bool getFin(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : situa el inicio/fin del programa
*/
void setFin(Partida &partida, bool flag);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida debio ser creada
  post : elimina el tablero e indica el fin del programa
*/
void destruirPartida(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida y el bandido debieron ser creados
  post : otorga una posicion en el tablero al bandido
*/
void ubicarBandido(Partida &partida,Bandido *bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida y las minas debieron ser creados
  post : otorga una posicion en el tablero a las minas
*/
//void ubicarMinas(Partida &partida,Minas *minas);
/*----------------------------------------------------------------------------*/
/*
  pre : la partida y el item debieron ser creados
  post : ubica al item en una direccion del tablero
*/
//void ubicarItem(Partida &partida,Item *item);
/*----------------------------------------------------------------------------*/
/*
  pre : partida debio ser creada
  post : asigna una direccion pasado por parametro
*/
void setDireccion(Partida &partida,char direccion[]);
/*----------------------------------------------------------------------------*/
/*
  pre : partida debio ser creado
  post : se obtiene una direccion pasado por parametro
*/
char* getDireccion(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : partida debio ser creada
  post : se obtiene el limite de columnas en la tabla
*/
int getColumnaLimite(Partida &partida);
/*----------------------------------------------------------------------------*/
/*
  pre : partida debio ser creada
  post : se obtiene el limite de filas en la tabla
*/
int getFilaLimite(Partida &partida);
// void ubicarCarro(Partida &partida,PtrNodoCarro ptrNodo);
#endif
