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

/**
    AXIOMAS:
    fila y columna no pueden estar fuera de rango.
    fila >= 0
    columna >= 0
    intervalo > 0
    contadorSegundo >=0
    contadorMonedas >=0
    anchoCelda > 0
    altoCelda > 0
    direccion: ["der","izq","arr","aba"]

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
/*
  pre : game no debe haber sido creado.
  post: game queda creado y preparado para ser usado.

  Game : estructura de datos a ser creado.
*/
void crearGame(Game &game,int fila,int columna,int anchoCelda,int altoCelda);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se obtiene el ancho de la Celda.

  Game : estructura de datos a ser creado.
*/
int getAnchoCelda(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se obtiene el alto de la Celda.

  Game : estructura de datos a ser creado.
*/
int getAltoCelda(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se obtiene el intervalo de tiempo.

  Game : estructura de datos a ser creado.
*/
int getIntervalo(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se setea el intervalo de tiempo.

  Game : estructura de datos a ser creado.
  intervalo: dato a asignar.
*/
void setIntervalo(Game &game, int intervalo);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se obtiene el contador de los segundos transcurridos.

  Game : estructura de datos a ser creado.
*/
int getContadorSegundo(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se setea el contador de los segundos.

  Game : estructura de datos a ser creado.
  contadorSegundo: dato a asignar.
*/
void setContadorSegundo(Game &game,int contadorSegundo);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se setea el terreno a utilizar.

  Game : estructura de datos a ser creado.
  render
*/
void setTerreno(Game &game, SDL_Renderer * renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se obtiene el terreno generado.

  Game : estructura de datos a ser creado.
*/
Terreno** getTerreno(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: lee los datos almacenados en minas.txt para su uso.

  Game : estructura de datos a ser creado.
  render
*/
void leerMinas(Game &game, SDL_Renderer * renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: crea una lista de Minas y devuelve su contenido.

  Game : estructura de datos a ser creado.
*/
Lista getMinas(Game &game);

/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: crea una lista de comanda y devuelve su contenido.

  Game : estructura de datos a ser creado.
*/
Lista getComanda(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  lee los datos que se encuentran de comanda.txt para su uso.

  Game : estructura de datos a ser creado.
*/
void leerComanda(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se obtiene los datos de parametros.

  Game : estructura de datos a ser creado.
*/
Parametros getParametros(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  modifica los datos clave y valor de parametros.

  Game : estructura de datos a ser creado.
  clave: dato a asignar
  valor: dato a asignar
*/
void setParametros(Game &game, string clave, string valor);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  lee los datos que se encuentran de parametros.txt para su uso.

  Game : estructura de datos a ser creado.
*/
void leerParametros(Game &game);
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  se dibuja el terreno.

  Game : estructura de datos a ser creado.
  render
*/
void dibujarTerreno(Game game,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  se dibuja las entidades sobre el terreno.

  Game : estructura de datos a ser creado.
  render
*/
void dibujarEntidades(Game game,SDL_Renderer *renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  indica la finalizacion del programa.

  Game : estructura de datos a ser creado.
*/
bool getGameOver(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  setea el estado del programa e indica su finalizacion.

  Game : estructura de datos a ser creado.
  flag: dato a asignar
*/
void setGameOver(Game &game, bool flag);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se elimina game.

  Game : estructura de datos a ser creado.
  render
*/
void destruirGame(Game &game,SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  indica la posicion donde se situara el vagon en el terreno.

  Game : estructura de datos a ser creado.
*/
void ubicarVagon(Game &game,PtrNodoLista ptrNodo);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  indica la posicion donde se situara el bandido en el terreno.

  Game : estructura de datos a ser creado.
*/
void ubicarBandido(Game &game,Bandido *bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  indica la posicion donde se situaran las minas en el terreno.

  Game : estructura de datos a ser creado.
*/
void ubicarMina(Game &game,Mina *mina);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  indica la posicion donde se situara moneda en el terreno.

  Game : estructura de datos a ser creado.
*/
void ubicarMoneda(Game &game,Moneda *moneda);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  indica la posicion donde se situara la estacion en el terreno.

  Game : estructura de datos a ser creado.
*/
void ubicarEstacion(Game &game,Estacion *estacion);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: situa el movimiento del vagon.

  Game : estructura de datos a ser creado.
  direccion: dato a asignar
*/
void setDireccion(Game &game,char direccion[]);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  se obtiene la direccion del movimiento del vagon.

  Game : estructura de datos a ser creado.
*/
char* getDireccion(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  se obtiene la cantidad de columnas a utilizar.

  Game : estructura de datos a ser creado.
*/
int getColumna(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  se obtiene la cantidad de filas a utilizar.

  Game : estructura de datos a ser creado.
*/
int getFila(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se controla el desplazamiento del vagon y sus interacciones.

  Game : estructura de datos a ser creado.
*/
void evaluarColision(Game &game,Lista &locomotora,Lista &monedas,Lista &bandidos,SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: al interactuar con mina se modifica sus datos.

  Game : estructura de datos a ser creado.
*/
void actualizarMinas(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  indica la cantidad de interacciones con moneda.

  Game : estructura de datos a ser creado.
*/
int contadorMonedas(Game &game);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post:  situa la cantidad de interacciones de moneda.

  Game : estructura de datos a ser creado.
*/
void setContadorMonedas(Game &game, int contadorMonedas);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: bandido es generado y ubicado en el terreno.

  Game : estructura de datos a ser creado.
*/
void generarBandidos(Game &game,Lista &bandidos, SDL_Renderer* renderer,int VB);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: moneda es generado y ubicado en el terreno.

  Game : estructura de datos a ser creado.
*/
void generarMonedas(Game &game,Lista &monedas, SDL_Renderer* renderer,int VM);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: bandido es eliminado al finalizar su intervalo de vida.

  Game : estructura de datos a ser creado.
*/
void actualizarBandidos(Game &game,Lista &bandidos, SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: moneda es eliminada al finalizar su intervalo de vida.

  Game : estructura de datos a ser creado.
*/
void actualizarMonedas(Game &game,Lista &monedas, SDL_Renderer* renderer);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se dibuja la puntuacion.

  Game : estructura de datos a ser creado.
*/
void dibujarPuntuacion(Game &game, SDL_Renderer * renderer, Lista &locomotora);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: vagon es situado en una nueva posicion del terreno.

  Game : estructura de datos a ser creado.
*/
void nuevaPosicionVagon(Game &game, Vagon * ultimo, int &posX, int &posY, char * direccion);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: al interactuar con estacion y cumplir las condiciones, se crea un nuevo vagon.

  Game : estructura de datos a ser creado.
*/
void agregarVagon(Game &game, Lista &locomotora, Estacion &estacion);
/*----------------------------------------------------------------------------*/
/*
  pre : se debe haber ingresado el dato
  post: devuelve el valor de la cadena como un entero.

  Game : estructura de datos a ser creado.
*/
int numeroStringRand(string numero);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: al interactuar la locomotora con el bandido se modifican/eliminan los items almacenados o
  en caso de no poseer, se elimina un vagon/locomotora.

  Game : estructura de datos a ser creado.
*/
void encuentroConBandido(Game &game, Lista &locomotora, Lista &bandidos);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: situa la cantidad de items que seran eliminados al interactuar con bandido.

  Game : estructura de datos a ser creado.
*/
void pedirItem(Game &game,Lista &locomotora, Bandido &bandido);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se obtiene la direccion del vagon, en base a las teclas seleccionadas.

  Game : estructura de datos a ser creado.
*/
void controlarEventos(Game &game,SDL_Event &event,const unsigned char *keys);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: se situa la direccion de la locomotora.

  Game : estructura de datos a ser creado.
*/
void cambiarDireccion(Game &game,Lista &locomotora);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: modifica el valor de la fila en el que se encuentra la locomotora.

  Game : estructura de datos a ser creado.
*/
void cambiarFila(Game &game,PtrNodoLista ptrNodo);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: modifica el valor de la columna en el que se encuentra la locomotora.

  Game : estructura de datos a ser creado.
*/
void cambiarColumna(Game &game,PtrNodoLista ptrNodo);
/*----------------------------------------------------------------------------*/
/*
  pre : game debe haber sido creado.
  post: devuelve el estado de la locomotora y su interaccion con el entorno.

  Game : estructura de datos a ser creado.
  return: estado de gameover
*/
bool evaluarColisiones(Game &game,PtrNodoLista ptrNodo);
#endif
