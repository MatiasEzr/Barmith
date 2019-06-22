#include <string.h>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include "Game.h"
#include "Celda.h"
#include "Terreno.h"
#include "Bandido.h"
#include "Lista.h"
#include "Vagon.h"
#include <ctime> //time.h o ctime agregan funciones que leen el reloj interno del procesador. la funcion time(NULL) devuelve el tiempo actual en milisegundos. la usamos para los aleatorios.
#include <stdlib.h>//permite utilizar itoa(int,char,int); y la funcion para aleatorios rand()

/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearGame(Game &game,int fila,int columna,int anchoCelda,int altoCelda,int altoSprite){
    game.gameover=false;
    game.intervalo=0;

    game.anchoCelda=anchoCelda;
    game.altoCelda=altoCelda;
    game.altoSprite=altoSprite;

    game.fila=fila;
    game.columna=columna;

    game.terreno= new Terreno*[game.fila];
    for (int f = 0; f < game.fila; f++){
        game.terreno[f] = new Terreno[game.columna];
    }
    strcpy(game.direccion,"direccion");
    crearLista(game.minas,NULL);
    crearLista(game.comanda,NULL);
}
/*----------------------------------------------------------------------------*/
int getAnchoCelda(Game &game){
    return game.anchoCelda;
}
/*----------------------------------------------------------------------------*/
int getAltoCelda(Game &game){
    return game.altoCelda;
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

void setTerreno(Game &game, SDL_Renderer * renderer){
    srand(time(0));
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            Terreno terreno;
            char aux [2];//cadena que guarda valores entre 0 y 4
            itoa((rand()%6),aux,10);//valor aleatorio entre 0 y 4, pasados a string en base 10
            crearTerreno(terreno,f,c,getAnchoCelda(game),getAltoCelda(game),renderer,aux);
            game.terreno[f][c]=terreno;
        }
    }
}

/*----------------------------------------------------------------------------*/
Terreno** getTerreno(Game &game){
    return game.terreno;
}
/*----------------------------------------------------------------------------*/
void setMinas(Game &game, SDL_Renderer * renderer){
    ifstream entrada("Minas.txt");

    string strposx,strposy,strcoditem,strip,strseq1,strseq2,strseq3,strseq4,strseq5;
    int posX,posY,coditem,ip,seq1,seq2,seq3,seq4,seq5;
    string cadena;
    while(!entrada.eof()){
          getline(entrada,cadena,'\n');
          if(cadena != ""){
              stringstream cadena2(cadena);
              Mina *mina = new Mina;

              getline(cadena2,strposx,';');
              posX=atoi(strposx.c_str());

              getline(cadena2,strposy,';');
              posY=atoi(strposy.c_str());

              getline(cadena2,strcoditem,';');
              coditem=atoi(strcoditem.c_str());

              getline(cadena2,strip,';');
              ip=atoi(strip.c_str());

              getline(cadena2,strseq1,';');
              seq1=atoi(strseq1.c_str());

              getline(cadena2,strseq2,';');
              seq2=atoi(strseq2.c_str());

              getline(cadena2,strseq3,';');
              seq3=atoi(strseq3.c_str());

              getline(cadena2,strseq4,';');
              seq4=atoi(strseq4.c_str());

              getline(cadena2,strseq5,';');
              seq5=atoi(strseq5.c_str());

              int secuencia[5] = {seq1,seq2,seq3,seq4,seq5};
              crearMina(*mina, renderer, posY, posX, getAnchoCelda(game), getAltoCelda(game), game.altoSprite, ip, secuencia,coditem);
              ubicarMina(game, mina);

              adicionarFinal(game.minas,mina);

              cadena2.clear();
          }
    }
    entrada.close();
    fflush(stdin);
}
/*----------------------------------------------------------------------------*/
Lista getMinas(Game &game){
    return game.minas;
}
/*----------------------------------------------------------------------------*/


void setComanda(Game &game){
 ifstream entrada("Comanda.txt");

    string codItem,strcantidad;
    int cantidad;
    string cadena;
    while(!entrada.eof()){
          getline(entrada,cadena,'\n');
          if(cadena != ""){
              stringstream cadena2(cadena);
              Comanda *comanda = new Comanda;

              getline(cadena2,codItem,';');

              getline(cadena2,strcantidad,';');
              cantidad=atoi(strcantidad.c_str());

              crearComanda(*comanda,codItem,cantidad);
              adicionarFinal(game.comanda,comanda);

              cadena2.clear();
          }
    }
    entrada.close();
    fflush(stdin);

}
/*----------------------------------------------------------------------------*/
Lista getComanda(Game &game){
    return game.comanda;
}
/*----------------------------------------------------------------------------*/

/*void setParametros(Game &game){
    ifstream entrada("Parametros.txt");

    string strcoditem,str;
    string codItem;

    string cadena;
    while(!entrada.eof()){
          getline(entrada,cadena,'\n');
          if(cadena != ""){
              stringstream cadena2(cadena);
              Parametros *parametros = new Parametros;

              getline(cadena2,strcoditem,';');
              codItem=atoi(strcoditem.c_str());



              crearParametros(*parametros,);
              game.parametros=*parametros;

              delete parametros;
              cadena2.clear();
          }
    }
    entrada.close();
    fflush(stdin);
}
*/
/*----------------------------------------------------------------------------*/
Parametros getParametros(Game &game){
    return game.parametros;
}
/*----------------------------------------------------------------------------*/
void dibujarTerreno(Game game,SDL_Renderer *renderer){
 for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            dibujarTerreno(game.terreno[f][c], renderer);
        }
    }
}
/*----------------------------------------------------------------------------*/
void dibujarEntidades(Game game,SDL_Renderer *renderer){
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            dibujarEntidad(game.terreno[f][c], renderer, game.intervalo);
        }
    }

}
/*----------------------------------------------------------------------------*/
void destruirGame(Game &game){
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            destruirTerreno(game.terreno[f][c]);
        }
    }
    eliminarLista(game.minas);
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
void ubicarVagon(Game &game,PtrNodoLista ptrNodo){
    game.terreno[getFila(*(Vagon*)ptrNodo->ptrDato)][getColumna(*(Vagon*)ptrNodo->ptrDato)].ptrNodoVagon=ptrNodo;//celda.ptrNosoVagon=ptrNodo
}
/*----------------------------------------------------------------------------*/
void ubicarBandido(Game &game,Bandido *bandido){
    game.terreno[getFila(bandido)][getColumna(bandido)].ptrBandido=bandido;
}
/*----------------------------------------------------------------------------*/
void ubicarMina(Game &game,Mina *mina){
    game.terreno[getFila(mina)][getColumna(mina)].ptrMina=mina;
}
/*----------------------------------------------------------------------------*/
void ubicarMoneda(Game &game,Moneda *moneda){
    game.terreno[getFila(moneda)][getColumna(moneda)].ptrMoneda=moneda;
}
/*----------------------------------------------------------------------------*/
void ubicarEstacion(Game &game,Estacion *estacion){
        game.terreno[getFila(estacion)][getColumna(estacion)].ptrEstacion=estacion;

}
/*----------------------------------------------------------------------------*/

void setDireccion(Game &game,char direccion[]){
    strcpy(game.direccion,direccion);
}
char* getDireccion(Game &game){
    return game.direccion;
}
/*----------------------------------------------------------------------------*/
int getColumnaLimite(Game &game){
    return game.columna;
}
/*----------------------------------------------------------------------------*/
int getFilaLimite(Game &game){
    return game.fila;
}
/*----------------------------------------------------------------------------*/
void evaluarColisionConMina(Game &game,Lista &locomotora){
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    Vagon *vagon = (Vagon*)primero(locomotora)->ptrDato;
    PtrNodoLista nodo = primero(locomotora);
    if(strcmp(getDireccion(*vagon),"aba")==0)desplazamientoVertical=1;
    if(strcmp(getDireccion(*vagon),"arr")==0)desplazamientoVertical=-1;
    if(strcmp(getDireccion(*vagon),"der")==0)desplazamientoHorizontal=1;
    if(strcmp(getDireccion(*vagon),"izq")==0)desplazamientoHorizontal=-1;

    int columna=getColumna(*vagon)+desplazamientoHorizontal;
    int fila=getFila(*vagon)+desplazamientoVertical;

    if(game.terreno[fila][columna].ptrMina!=NULL && !(vagon->detenido)){
        while(nodo!=finLista()){
            vagon = (Vagon*)nodo->ptrDato;
            vagon->detenido = true;
            nodo = siguiente(locomotora, nodo);
        }
    }
    else if(game.terreno[fila][columna].ptrMina==NULL && vagon->detenido){
        while(nodo!=finLista()){
            vagon = (Vagon*)nodo->ptrDato;
            vagon->detenido = false;
            nodo = siguiente(locomotora, nodo);
        }
    }
}
/*----------------------------------------------------------------------------*/
