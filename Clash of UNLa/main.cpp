#include <iostream>//iostream: es una libreria que nos permite la entrada (cin) y salida (cout) de datos
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <conio.h>// agrega la funcuion getch(); que es trabante de procesos
#include <stdlib.h>//permite utilizar new y delete


#include <SDL.h>
#include <SDL_image.h>

#include "Partida.h"
#include "Locomotora.h"
#include "Vagon.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
#include "Item.h"

using namespace std;

#define milisegundos 30

void evaluarEventosTeclado(Partida &partida,SDL_Event &event,const unsigned char *keys);
void cambiarDireccion(PtrNodoVagon ptrNodo,char direccion[]);

void cambiarCapaInicio(Partida &partida,PtrNodoVagon ptrNodo);
void cambiarCapaFinal(Partida &partida,PtrNodoVagon ptrNodo);
void cambiarColumna(Partida &partida,PtrNodoVagon ptrNodo);
bool evaluarColisiones(Partida &partida,PtrNodoVagon ptrNodo);
int main(int argc, char** argv) {
        //PlaySound(TEXT("media/musica.wav"),NULL, SND_ASYNC);
        //Si no se escucha la música es porque hay que agregar un linck al codeblocks:
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

        Partida partida;
        crearPartida(partida,filas,columnas,anchoCelda,altoCelda,altoSprite);
        setTablero(partida,renderer);
        setTerreno(partida);

        Locomotora locomotora;
        crearLocomotora(locomotora);
        Vagon vagon;
        Item item;
        //C1 es la locomotora
        crearVagon(vagon,"c1", 0, 4,"der",anchoCelda, altoCelda, altoSprite,1,item);//el primero es c1
        ubicarVagon(partida,adicionarPrincipio(locomotora,vagon));
        setDireccion(partida,getDireccion(primero(locomotora)->vagon));//la direccion de la partida es = a la del primer vagon

        //Vagones c2
        crearVagon(vagon,"c2", 0, 3,"der",anchoCelda, altoCelda, altoSprite,2,item);
        ubicarVagon(partida,adicionarFinal(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 2,"der",anchoCelda, altoCelda, altoSprite,3,item);
        ubicarVagon(partida,adicionarFinal(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 1,"der",anchoCelda, altoCelda, altoSprite,4,item);
        ubicarVagon(partida,adicionarFinal(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 0,"der",anchoCelda, altoCelda, altoSprite,5,item);
        ubicarVagon(partida,adicionarFinal(locomotora,vagon));

        Bandido bandido;
        Bandido *ptrBandido = &bandido;
        crearBandido(bandido,renderer,4,9,anchoCelda, altoCelda, altoSprite,item,3);
        ubicarBandido(partida,ptrBandido);

        Mina mina;
        Mina *ptrMina = &mina;
        crearMina(mina,renderer,4,2,anchoCelda, altoCelda, altoSprite);
        ubicarMina(partida,ptrMina);

        Moneda moneda;
        Moneda *ptrMoneda = &moneda;
        crearMoneda(moneda,renderer,4,6,anchoCelda, altoCelda, altoSprite,5);
        ubicarMoneda(partida,ptrMoneda);


        dibujarTablero(partida,renderer);
        SDL_RenderPresent(renderer);//APLICA EL CAMBIO
        SDL_Delay(500);
        while(!getGameOver(partida)){

            evaluarEventosTeclado(partida,event,keys);//setea la direccion siguiente en partida.direccion

            if(getIntervalo(partida)==10){
                setIntervalo(partida,0);

                cambiarColumna(partida,primero(locomotora));//fila del tablero
                cambiarCapaFinal(partida,primero(locomotora));//capa del mapa
                //hasta aca todos los carritos se encuentran en su punto casilla de tablero
                //podemos evaluar la adquisición de monedas, de minas o ataques de bandidos

                //luego redireccionamos a todos los vagons desde el primero
                cambiarDireccion(primero(locomotora),getDireccion(partida));

                setGameOver(partida,evaluarColisiones(partida,primero(locomotora)));

            }
            if(!getGameOver(partida)){
                if(getIntervalo(partida)==1){
                    //desde el princpio de la lista, si se mira hacia abajo o hacia arribaen el intervalo 1
                    //entonces lo desplazo a la siquietne capa
                    cambiarCapaInicio(partida,primero(locomotora));//capa del mapa
                }

                //Render
                SDL_RenderClear(renderer);//borro todo
                dibujarTablero(partida,renderer);
                SDL_RenderPresent(renderer);//APLICA EL CAMBIO
                SDL_Delay(milisegundos);

                setIntervalo(partida,getIntervalo(partida)+1);//partida.intervalo++;
            }
        }//FIN DEL BUCLE
        cout<<"Destruimos locomotora"<<endl;
        eliminarLocomotora(locomotora);
        cout<<"Destruimos partida"<<endl;
        destruirPartida(partida);
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
bool evaluarColisiones(Partida &partida,PtrNodoVagon ptrNodo){
    bool colision=true;
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    if(strcmp(getDireccion(ptrNodo->vagon),"aba")==0)desplazamientoVertical=1;
    if(strcmp(getDireccion(ptrNodo->vagon),"arr")==0)desplazamientoVertical=-1;
    if(strcmp(getDireccion(ptrNodo->vagon),"der")==0)desplazamientoHorizontal=1;
    if(strcmp(getDireccion(ptrNodo->vagon),"izq")==0)desplazamientoHorizontal=-1;

    int c=getColumna(ptrNodo->vagon)+desplazamientoHorizontal;
    int f=getFila(ptrNodo->vagon)+desplazamientoVertical;

    if((c>=0 && c<getColumnaLimite(partida)) && (f>=0 && f<getFilaLimite(partida))){
        //el tren aun se encuentra en el tablero!
        Celda celdaAux =getTablero(partida)[f][c];
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
void cambiarColumna(Partida &partida,PtrNodoVagon ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->vagon),"der")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->vagon),"izq")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(partida);// partida.mapa
            terrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            terrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(partida);// partida.tablero
            tableroAux[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            tableroAux[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
            setColumna(ptrNodo->vagon,desplazamiento);
        }
        cambiarColumna(partida,ptrNodo->siguiente);
    }
}
void cambiarCapaInicio(Partida &partida, PtrNodoVagon ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->vagon),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->vagon),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(partida);// partida.mapa
            terrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            terrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(partida);// partida.mapa
            tableroAux[getFila(ptrNodo->vagon)][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
        }
        cambiarCapaInicio(partida,ptrNodo->siguiente);
    }
}
void cambiarCapaFinal(Partida &partida, PtrNodoVagon ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->vagon),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->vagon),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(partida);// partida.mapa
            terrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
            terrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
            Celda **tableroAux=getTablero(partida);// partida.mapa
            tableroAux[getFila(ptrNodo->vagon)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
            setFila(ptrNodo->vagon,desplazamiento);//actualizo la fila en la que se encuentra
        }
        cambiarCapaFinal(partida,ptrNodo->siguiente);
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
            setDireccion(ptrNodo->vagon,direccion);//cargo la nueva dirección
        }
        cambiarDireccion(ptrNodo->siguiente,dirAnterior);
    }
}
void evaluarEventosTeclado(Partida &partida,SDL_Event &event,const unsigned char *keys){
    if(SDL_PollEvent(&event)){//indica que hay eventos pendientes
        switch(event.type){
            case SDL_QUIT:
                setGameOver(partida, true);
            break;
            case SDL_KEYDOWN:
                if(keys[SDL_SCANCODE_ESCAPE]){
                    setGameOver(partida, true);
                }
                if(keys[SDL_SCANCODE_LEFT]){
                    setDireccion(partida,"izq");
                }
                if(keys[SDL_SCANCODE_RIGHT]){
                    setDireccion(partida,"der");
                }
                if(keys[SDL_SCANCODE_UP]){
                    setDireccion(partida,"arr");
                }
                if(keys[SDL_SCANCODE_DOWN]){
                    setDireccion(partida,"aba");
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
