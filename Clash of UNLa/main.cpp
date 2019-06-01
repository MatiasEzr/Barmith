#include <iostream>//iostream: es una libreria que nos permite la entrada (cin) y salida (cout) de datos
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <conio.h>// agrega la funcuion getch(); que es trabante de procesos
#include <stdlib.h>//permite utilizar new y delete


#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"
#include "Locomotora.h"
#include "Vagon.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
#include "Item.h"

using namespace std;

#define milisegundos 30

void evaluarEventosTeclado(Game &game,SDL_Event &event,const unsigned char *keys);
void cambiarDireccion(PtrNodoVagon ptrNodo,char direccion[]);

void cambiarCapaInicio(Game &game,PtrNodoVagon ptrNodo);
void cambiarCapaFinal(Game &game,PtrNodoVagon ptrNodo);
void cambiarColumna(Game &game,PtrNodoVagon ptrNodo);
bool evaluarColisiones(Game &game,PtrNodoVagon ptrNodo);
int main(int argc, char** argv) {
        //PlaySound(TEXT("media/musica.wav"),NULL, SND_ASYNC);
        //Si no se escucha la m�sica es porque hay que agregar un linck al codeblocks:
        //settings->complier...->linker settings-> link libraries-> add-> escribimos winmm ->aceptamos todo.
        /*datros que leo desde un archivo************/
        int filas = 20;
        int columnas = 15;
        int anchoCelda =70;
        int altoCelda = 40;
        int altoSprite = 70;
        /********************************************/

        int anchoVentana = (columnas+2)*anchoCelda;
        int altoVentana = (filas+2)*altoCelda;;


    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){

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

        Game game;
        crearGame(game,filas,columnas,anchoCelda,altoCelda,altoSprite);
        setTablero(game,renderer);
        setTerreno(game);

        Locomotora locomotora;
        crearLocomotora(locomotora);
        Vagon vagon;
        Item item;
        //C1 es la locomotora
        crearVagon(vagon,"c1", 0, 4,"der",anchoCelda, altoCelda, altoSprite,1,item);//el primero es c1
        ubicarVagon(game,adicionarPrincipio(locomotora,vagon));
        setDireccion(game,getDireccion(primero(locomotora)->vagon));//la direccion de la game es = a la del primer vagon

        //Vagones c2
        crearVagon(vagon,"c2", 0, 3,"der",anchoCelda, altoCelda, altoSprite,2,item);
        ubicarVagon(game,adicionarFinal(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 2,"der",anchoCelda, altoCelda, altoSprite,3,item);
        ubicarVagon(game,adicionarFinal(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 1,"der",anchoCelda, altoCelda, altoSprite,4,item);
        ubicarVagon(game,adicionarFinal(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 0,"der",anchoCelda, altoCelda, altoSprite,5,item);
        ubicarVagon(game,adicionarFinal(locomotora,vagon));

        Bandido bandido;
        Bandido *ptrBandido = &bandido;
        crearBandido(bandido,renderer,4,9,anchoCelda, altoCelda, altoSprite,item,3);
        ubicarBandido(game,ptrBandido);

        Mina mina;
        Mina *ptrMina = &mina;
        crearMina(mina,renderer,4,2,anchoCelda, altoCelda, altoSprite);
        ubicarMina(game,ptrMina);

        Moneda moneda;
        Moneda *ptrMoneda = &moneda;
        crearMoneda(moneda,renderer,4,6,anchoCelda, altoCelda, altoSprite,5);
        ubicarMoneda(game,ptrMoneda);


        dibujarTablero(game,renderer);
        dibujarSprite(game,renderer);
        SDL_RenderPresent(renderer);//APLICA EL CAMBIO
        SDL_Delay(500);
        while(!getGameOver(game)){

            evaluarEventosTeclado(game,event,keys);//setea la direccion siguiente en game.direccion

            if(getIntervalo(game)==10){
                setIntervalo(game,0);

                cambiarColumna(game,primero(locomotora));//fila del tablero
                cambiarCapaFinal(game,primero(locomotora));//capa del mapa
                //hasta aca todos los carritos se encuentran en su punto casilla de tablero
                //podemos evaluar la adquisici�n de monedas, de minas o ataques de bandidos

                //luego redireccionamos a todos los vagons desde el primero
                cambiarDireccion(primero(locomotora),getDireccion(game));

                //setGameOver(game,evaluarColisiones(game,primero(locomotora)));

            }
            if(!getGameOver(game)){
                if(getIntervalo(game)==1){
                    //desde el princpio de la lista, si se mira hacia abajo o hacia arribaen el intervalo 1
                    //entonces lo desplazo a la siquietne capa
                    cambiarCapaInicio(game,primero(locomotora));//capa del mapa
                }

                //Render
                SDL_RenderClear(renderer);//borro todo
                dibujarTablero(game,renderer);
                dibujarSprite(game,renderer);
                SDL_RenderPresent(renderer);//APLICA EL CAMBIO
                SDL_Delay(milisegundos);

                setIntervalo(game,getIntervalo(game)+1);//game.intervalo++;
            }
        }//FIN DEL BUCLE
        cout<<"Destruimos locomotora"<<endl;
        eliminarLocomotora(locomotora);
        cout<<"Destruimos game"<<endl;
        destruirGame(game);
        cout<<"Destruimos renderer"<<endl;
        SDL_DestroyRenderer(renderer);
        cout<<"Destruimos window"<<endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        cout<<"GAME OVER!"<<endl;
    }//find el if
    cout<<"presione una tecla para salir..."<<endl;
    getch();
    return 0;
}
/*bool evaluarColisiones(Game &game,PtrNodoVagon ptrNodo){
    bool colision=true;
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    if(strcmp(getDireccion(ptrNodo->vagon),"aba")==0)desplazamientoVertical=1;
    if(strcmp(getDireccion(ptrNodo->vagon),"arr")==0)desplazamientoVertical=-1;
    if(strcmp(getDireccion(ptrNodo->vagon),"der")==0)desplazamientoHorizontal=1;
    if(strcmp(getDireccion(ptrNodo->vagon),"izq")==0)desplazamientoHorizontal=-1;

    int c=getColumna(ptrNodo->vagon)+desplazamientoHorizontal;
    int f=getFila(ptrNodo->vagon)+desplazamientoVertical;

    if((c>=0 && c<getColumnaLimite(game)) && (f>=0 && f<getFilaLimite(game))){
        //el tren aun se encuentra en el tablero!
        Celda celdaAux =getTablero(game)[f][c];
        if(celdaAux.ptrNodoVagon==NULL){
            //y el tren no se chocoar� con otro vag�n
            colision=false;
        }else{
            cout<<"Chocamos con otro vagon en "<<f<<"/"<<c<<endl;
        }
    }else{
        cout<<"Nos salimos del cuadrante en "<<f<<"/"<<c<<endl;
    }
    return colision;
}
*/
void cambiarColumna(Game &game,PtrNodoVagon ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->vagon),"der")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->vagon),"izq")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);// game.mapa
            terrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            terrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(game);// game.tablero
            tableroAux[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            tableroAux[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
            setColumna(ptrNodo->vagon,desplazamiento);
        }
        cambiarColumna(game,ptrNodo->siguiente);
    }
}
void cambiarCapaInicio(Game &game, PtrNodoVagon ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->vagon),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->vagon),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);// game.mapa
            terrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            terrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(game);// game.mapa
            tableroAux[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
        }
        cambiarCapaInicio(game,ptrNodo->siguiente);
    }
}
void cambiarCapaFinal(Game &game, PtrNodoVagon ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->vagon),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->vagon),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);// game.mapa
            terrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            terrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(game);// game.mapa
            tableroAux[getFila(ptrNodo->vagon)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
            setFila(ptrNodo->vagon,desplazamiento);//actualizo la fila en la que se encuentra
        }
        cambiarCapaFinal(game,ptrNodo->siguiente);
    }
}



void cambiarDireccion(PtrNodoVagon ptrNodo,char direccion[]){
    if(ptrNodo!=NULL){
        //validar la direccion;
        char dirAnterior[4];
        strcpy(dirAnterior,getDireccion(ptrNodo->vagon));//guardo la direccion anterior
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
            setDireccion(ptrNodo->vagon,direccion);//cargo la nueva direcci�n
        }
        cambiarDireccion(ptrNodo->siguiente,dirAnterior);
    }
}
void evaluarEventosTeclado(Game &game,SDL_Event &event,const unsigned char *keys){
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
