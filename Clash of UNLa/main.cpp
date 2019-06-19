#include <iostream>
#include <string.h>/
#include <conio.h>
#include <stdlib.h>//permite utilizar new y delete


#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "Vagon.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
#include "Item.h"
#include "Lista.h"
#include "Parametros.h"

using namespace std;

#define milisegundos 30

void correrGame(Game &game,int anchoVentana,int altoVentana);
void leerArchivos(Game &game,SDL_Renderer *renderer);
void imprimirMinas(Game &game);

void controlarEventos(Game &game,SDL_Event &event,const unsigned char *keys);
void cambiarDireccion(PtrNodoLista ptrNodo,char direccion[]);

void cambiarCapaInicio(Game &game,PtrNodoLista ptrNodo);
void cambiarCapaFinal(Game &game,PtrNodoLista ptrNodo);
void cambiarColumna(Game &game,PtrNodoLista ptrNodo);
bool evaluarColisiones(Game &game,PtrNodoLista ptrNodo);
int main(int argc, char** argv) {

        /*datos que leo desde un archivo************/
        int filas = 15;
        int columnas = 20;
        int anchoCelda = 70;
        int altoCelda = 40;
        int altoSprite = 70;
        /********************************************/

        int anchoVentana = 800;
        int altoVentana = 600;


    Game game;
    crearGame(game,filas,columnas,anchoCelda,altoCelda,altoSprite);
    correrGame(game,anchoVentana,altoVentana);

    cout<<"presione una tecla para salir..."<<endl;
    getch();
    return 0;
}

void leerArchivos(Game &game,SDL_Renderer *renderer){

}


void imprimirMinas(Game &game){

     if(!listaVacia(game.minas)){
            cout<<"Lector de minas"<<endl;
             PtrNodoLista nodo=primero(game.minas);
             while(nodo !=finLista()){
                //El nodo apunta al dato, y casteo el dato a casilla
                Mina* mina =(Mina*) nodo->ptrDato;
                cout<<"posX:"<<getColumna(mina)<<";posY:"<<getFila(mina)<<";codItem: "<<";IP: "<<getIP(*mina)<<";seq: "<<getSecuencia(*mina)<<endl;
                nodo = siguiente(game.minas, nodo);
                }

             }

        }

void correrGame(Game &game,int anchoVentana,int altoVentana){
if(SDL_Init(SDL_INIT_EVERYTHING)>=0){
        int anchoCelda=game.anchoCelda;
        int altoCelda=game.altoCelda;
        int altoSprite=game.altoSprite;
        SDL_Window *window;
        SDL_Renderer *renderer;

        window = SDL_CreateWindow(
            "Clash of UNLa",
            SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
            anchoVentana,altoVentana,
            SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC
            );

        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        IMG_Init(IMG_INIT_PNG);

        SDL_Event event;
        const unsigned char *keys;
        keys = SDL_GetKeyboardState(NULL);





        setTablero(game,renderer);
        setTerreno(game);
        setMinas(game, renderer);
        Lista locomotora;
        crearLista(locomotora,NULL);
        Vagon vagon1, vagon2, vagon3, vagon4, vagon5;
        Item item;
        //C1 es la locomotora
        crearVagon(vagon1,"c1", 0, 4,"der",anchoCelda, altoCelda, altoSprite,1,item);//el primero es c1
        ubicarVagon(game,adicionarPrincipio(locomotora,&vagon1));
        setDireccion(game,getDireccion(*(Vagon*)primero(locomotora)->ptrDato));//la direccion de la game es = a la del primer vagon

        //Vagones c2
        crearVagon(vagon2,"c2", 0, 3,"der",anchoCelda, altoCelda, altoSprite,2,item);
        ubicarVagon(game,adicionarFinal(locomotora,&vagon2));
        crearVagon(vagon3,"c2", 0, 2,"der",anchoCelda, altoCelda, altoSprite,3,item);
        ubicarVagon(game,adicionarFinal(locomotora,&vagon3));
        crearVagon(vagon4,"c2", 0, 1,"der",anchoCelda, altoCelda, altoSprite,4,item);
        ubicarVagon(game,adicionarFinal(locomotora,&vagon4));
        crearVagon(vagon5,"c2", 0, 0,"der",anchoCelda, altoCelda, altoSprite,5,item);
        ubicarVagon(game,adicionarFinal(locomotora,&vagon5));


        Bandido bandido;
        Bandido *ptrBandido = &bandido;
        crearBandido(bandido,renderer,4,9,anchoCelda, altoCelda, altoSprite,item,3);
        ubicarBandido(game,ptrBandido);

        Moneda moneda;
        Moneda *ptrMoneda = &moneda;
        crearMoneda(moneda,renderer,4,6,anchoCelda, altoCelda, altoSprite,5);
        ubicarMoneda(game,ptrMoneda);


        dibujarTablero(game,renderer);
        dibujarSprite(game,renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(500);


        while(!getGameOver(game)){
            controlarEventos(game,event,keys);//setea la direccion siguiente en game.direccion

            if(getIntervalo(game)==10){
                setIntervalo(game,0);
                cambiarColumna(game,primero(locomotora));//fila del tablero
                cambiarCapaFinal(game,primero(locomotora));//capa del mapa
                //hasta aca todos los carritos se encuentran en su punto casilla de tablero
                //podemos evaluar la adquisición de monedas, de minas o ataques de bandidos

                //luego redireccionamos a todos los vagons desde el primero
                cambiarDireccion(primero(locomotora),getDireccion(game));


                setGameOver(game,evaluarColisiones(game,primero(locomotora)));

            }
            if(!getGameOver(game)){
                if(getIntervalo(game)==1){
                    //desde el princpio de la lista, si se mira hacia abajo o hacia arribaen el intervalo 1
                    //entonces lo desplazo a la siquietne capa
                    cambiarCapaInicio(game,primero(locomotora));//capa del mapa
                }


                SDL_RenderClear(renderer);
                dibujarTablero(game,renderer);
                dibujarSprite(game,renderer);
                SDL_RenderPresent(renderer);
                SDL_Delay(milisegundos);

                setIntervalo(game,getIntervalo(game)+1);
            }
        }
        cout<<"Destruimos las instancias"<<endl;
        eliminarLista(locomotora);
        destruirGame(game);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        cout<<"Fin del juego"<<endl;
    }
}



bool evaluarColisiones(Game &game,PtrNodoLista ptrNodo){
    bool colision=true;
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    Vagon *vagon = (Vagon*)ptrNodo->ptrDato;
    if(strcmp(getDireccion(*vagon),"aba")==0)desplazamientoVertical=1;
    if(strcmp(getDireccion(*vagon),"arr")==0)desplazamientoVertical=-1;
    if(strcmp(getDireccion(*vagon),"der")==0)desplazamientoHorizontal=1;
    if(strcmp(getDireccion(*vagon),"izq")==0)desplazamientoHorizontal=-1;

    int c=getColumna(*vagon)+desplazamientoHorizontal;
    int f=getFila(*vagon)+desplazamientoVertical;

    if((c>=0 && c<getColumnaLimite(game)) && (f>=0 && f<getFilaLimite(game))){
        //el tren aun se encuentra en el tablero!
        Celda celdaAux =getTablero(game)[f][c];
        if(celdaAux.ptrNodoVagon==NULL){
            //y el tren no se chocoará con otro vagón
            colision=false;
        }else{
            cout<<"Chocamos con otro vagon en "<<f<<"/"<<c<<endl;
        }
    }else{
        cout<<"Nos salimos del cuadrante en "<<f<<"/"<<c<<endl;
    }
    return colision;
}

void cambiarColumna(Game &game,PtrNodoLista ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        Vagon *vagon = (Vagon*)ptrNodo->ptrDato;
        if(strcmp(getDireccion(*vagon),"der")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(*vagon),"izq")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);// game.mapa
            terrenoAux[getFila(*vagon)*2][getColumna(*vagon)].ptrNodoVagon=NULL;
            terrenoAux[getFila(*vagon)*2][getColumna(*vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(game);// game.tablero
            tableroAux[getFila(*vagon)][getColumna(*vagon)].ptrNodoVagon=NULL;
            tableroAux[getFila(*vagon)][getColumna(*vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
            setColumna(*vagon,desplazamiento);
        }
        delete vagon;
        cambiarColumna(game,ptrNodo->sgte);
    }
}
void cambiarCapaInicio(Game &game, PtrNodoLista ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        Vagon *vagon = (Vagon*)ptrNodo->ptrDato;
        if(strcmp(getDireccion(*vagon),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(*vagon),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);// game.mapa
            terrenoAux[getFila(*vagon)*2][getColumna(*vagon)].ptrNodoVagon=NULL;
            terrenoAux[(getFila(*vagon)*2)+desplazamiento][getColumna(*vagon)].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(game);// game.mapa
            tableroAux[getFila(*vagon)][getColumna(*vagon)].ptrNodoVagon=NULL;
        }
        delete vagon;
        cambiarCapaInicio(game,ptrNodo->sgte);
    }
}
void cambiarCapaFinal(Game &game, PtrNodoLista ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        Vagon *vagon = (Vagon*)ptrNodo->ptrDato;
        if(strcmp(getDireccion(*vagon),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(*vagon),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);// game.mapa
            terrenoAux[(getFila(*vagon)*2)+desplazamiento][getColumna(*vagon)].ptrNodoVagon=NULL;
            terrenoAux[(getFila(*vagon)*2)+desplazamiento+desplazamiento][getColumna(*vagon)].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(game);// game.mapa
            tableroAux[getFila(*vagon)+desplazamiento][getColumna(*vagon)].ptrNodoVagon=ptrNodo;
            setFila(*vagon,desplazamiento);//actualizo la fila en la que se encuentra
        }
        delete vagon;
        cambiarCapaFinal(game,ptrNodo->sgte);
    }
}



void cambiarDireccion(PtrNodoLista ptrNodo,char direccion[]){
    if(ptrNodo!=NULL){
        //validar la direccion;
        char dirAnterior[4];
        Vagon *vagon = (Vagon*)ptrNodo->ptrDato;
        strcpy(dirAnterior,getDireccion(*vagon));//guardo la direccion anterior
        //si dirAnterior es izq entonces direccion no puede ser der
        //si dirAnterior es der entonces direccion no puede ser izq
        //si dirAnterior es arr entonces direccion no puede ser aba
        //si dirAnterior es aba entonces direccion no puede ser arr
        if(
            (strcmp(dirAnterior,"izq")==0 && strcmp(direccion,"der")!=0) ||
            (strcmp(dirAnterior,"der")==0 && strcmp(direccion,"izq")!=0) ||
            (strcmp(dirAnterior,"arr")==0 && strcmp(direccion,"aba")!=0) ||
            (strcmp(dirAnterior,"aba")==0 && strcmp(direccion,"arr")!=0)
        ){
            setDireccion(*vagon,direccion);//cargo la nueva dirección
        }
        delete vagon;
        cambiarDireccion(ptrNodo->sgte,dirAnterior);
    }
}
void controlarEventos(Game &game,SDL_Event &event,const unsigned char *keys){
    if(SDL_PollEvent(&event)){//indica que hay eventos pendientes
        switch(event.type){
            case SDL_QUIT:
                setGameOver(game, true);
            break;
            case SDL_KEYDOWN:
                if(keys[SDL_SCANCODE_ESCAPE]){
                    setGameOver(game, true);
                }
                if(keys[SDL_SCANCODE_LEFT]){
                    setDireccion(game,"izq");
                }
                if(keys[SDL_SCANCODE_RIGHT]){
                    setDireccion(game,"der");
                }
                if(keys[SDL_SCANCODE_UP]){
                    setDireccion(game,"arr");
                }
                if(keys[SDL_SCANCODE_DOWN]){
                    setDireccion(game,"aba");
                }
                if(keys[SDL_SCANCODE_SPACE]){
                    //
                }
                break;
                /*
            case SDL_MOUSEBUTTONDOWN:
                if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "CLICK","Con el boton izquierdo del mouse.",NULL);
                }
                break;
                */
        }
    }
}


