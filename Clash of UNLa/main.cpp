#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Game.h"
#include "Vagon.h"
#include "Bandido.h"
#include "Mina.h"
#include "Moneda.h"
#include "Item.h"
#include "Lista.h"
#include "Parametros.h"

using namespace std;

#define milisegundos 100 //30


int numeroStringRand(string numero);
void correrGame(Game &game,int anchoVentana,int altoVentana);
void leerArchivos(Game &game,SDL_Renderer *renderer);
void imprimirMinas(Game &game);
void imprimirComanda(Game &game);

void controlarEventos(Game &game,SDL_Event &event,const unsigned char *keys);
void cambiarDireccion(Game &game,Lista &locomotora);

void cambiarFila(Game &game,PtrNodoLista ptrNodo);
void cambiarColumna(Game &game,PtrNodoLista ptrNodo);
bool evaluarColisiones(Game &game,PtrNodoLista ptrNodo);
int main(int argc, char** argv) {

        int anchoCelda = 50;
        int altoCelda = 40;
        int altoSprite = 50;

        int anchoVentana = 800;
        int altoVentana = 600;

        int filas = altoVentana/altoCelda;
        int columnas = anchoVentana/anchoCelda;


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
            cout << "======================" << endl;
            cout<<"Lector de minas"<<endl;
            cout << "======================" << endl;
             PtrNodoLista nodo=primero(game.minas);
             while(nodo !=finLista()){
                //El nodo apunta al dato, y casteo el dato a mina
                Mina* mina =(Mina*) nodo->ptrDato;
                cout<<"posX:"<<getColumna(mina)<<";posY:"<<getFila(mina)<<";codItem:"<<getCodItem(mina)<<";IP:"<<getIP(*mina)<<";";
                for(int i=0;i<5;i++){
                    cout<<"seq["<<i+1<<"]:"<<getSecuencia(*mina)[i]<<" ";
                }
                cout<<endl;
                nodo = siguiente(game.minas, nodo);
                }
             }
              // Agrego un par de l�neas a la consola
            cout << endl;
            cout << endl;
            cout << endl;


        }
void imprimirComanda(Game &game){
       if(!listaVacia(game.comanda)){
             cout << "======================" << endl;
            cout << "= Lector de Comanda =" << endl;
            cout << "======================" << endl;
             PtrNodoLista nodo=primero(game.comanda);
             while(nodo !=finLista()){
                //El nodo apunta al dato, y casteo el dato a Comanda
                Comanda* comanda =(Comanda*) nodo->ptrDato;
                cout<<"codItem:"<<comanda->codItem<<";cantidad:"<<comanda->cantidad<<endl;
                 nodo = siguiente(game.comanda, nodo);
                }
             }
         // Agrego un par de l�neas a la consola
            cout << endl;
            cout << endl;
            cout << endl;

        }


 void imprimirParametros(Game &game){
            cout << "======================" << endl;
            cout<<"Lector de Parametros"<<endl;
            cout << "======================" << endl;


            cout<<"S:"<<game.parametros.claveS<<"\nP:"<<game.parametros.claveP<<"\nA:"<<game.parametros.claveA<<endl;
            cout<<"posXE:"<<game.parametros.claveposXE<<"\nposYE:"<<game.parametros.claveposYE<<"\nIM:"<<game.parametros.claveIM<<endl;
            cout<<"VM:"<<game.parametros.claveIM<<"\nIB:"<<game.parametros.claveIB<<"\nVB:"<<game.parametros.claveVB<<"\nIP:"<<game.parametros.claveIP<<endl;
             // Agrego un par de l�neas a la consola
            cout << endl;
            cout << endl;
            cout << endl;

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
        TTF_Init();

        SDL_Event event;
        const unsigned char *keys;
        keys = SDL_GetKeyboardState(NULL);
        leerParametros(game); //Archivo
        imprimirParametros(game);

        leerComanda(game); //Archivo
        imprimirComanda(game);



        setTerreno(game, renderer);
        leerMinas(game, renderer); //Archivo
        imprimirMinas(game);

        Estacion estacion;
        Estacion *ptrEstacion=&estacion;
        crearEstacion(estacion,renderer,8,7,anchoCelda,altoCelda,altoSprite);
        ubicarEstacion(game,ptrEstacion);




        Lista locomotora;
        crearLista(locomotora,NULL);
        Vagon vagon1, vagon2, vagon3, vagon4, vagon5,vagon6,vagon7;

        crearVagon(vagon1,"c1", 0, 7,"der",anchoCelda, altoCelda, altoSprite,0,"");//
        ubicarVagon(game,adicionarPrincipio(locomotora,&vagon1));
        setDireccion(game,getDireccion(*(Vagon*)primero(locomotora)->ptrDato));


        crearVagon(vagon2,"c2", 0, 6,"der",anchoCelda, altoCelda, altoSprite,10,"oro");
        ubicarVagon(game,adicionarFinal(locomotora,&vagon2));
        crearVagon(vagon3,"c2", 0, 5,"der",anchoCelda, altoCelda, altoSprite,30,"bronce");
        ubicarVagon(game,adicionarFinal(locomotora,&vagon3));
        crearVagon(vagon4,"c2", 0, 4,"der",anchoCelda, altoCelda, altoSprite,20,"plata");
        ubicarVagon(game,adicionarFinal(locomotora,&vagon4));
        crearVagon(vagon5,"c2", 0, 3,"der",anchoCelda, altoCelda, altoSprite,22,"roca");
        ubicarVagon(game,adicionarFinal(locomotora,&vagon5));
        crearVagon(vagon6,"c2", 0, 2,"der",anchoCelda, altoCelda, altoSprite,22,"platino");
        ubicarVagon(game,adicionarFinal(locomotora,&vagon6));
         crearVagon(vagon7,"c2", 0, 1,"der",anchoCelda, altoCelda, altoSprite,22,"carbon");
        ubicarVagon(game,adicionarFinal(locomotora,&vagon7));


        Bandido bandido;
        Bandido *ptrBandido = &bandido;
        crearBandido(bandido,renderer,4,9,anchoCelda, altoCelda, altoSprite,"Oro",3);
        ubicarBandido(game,ptrBandido);

        Lista monedas;
        crearLista(monedas,NULL);
        //Moneda *ptrMoneda = &moneda;
        //crearMoneda(moneda,renderer,4,6,anchoCelda, altoCelda, altoSprite,5);
        //ubicarMoneda(game,ptrMoneda);


        dibujarTerreno(game,renderer);
        dibujarEntidades(game,renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        int IM=numeroStringRand(game.parametros.claveIM);//Numero random para IM de entrada
        cout<<IM;
        while(!getGameOver(game)){
            controlarEventos(game,event,keys);

            if(getIntervalo(game)==10){
                setIntervalo(game,0);
                setContadorSegundo(game,getContadorSegundo(game)+1);//Cada vez que pasan los 10 intervalos, suma un segundo
                cout<<"SegundoActual:"<<getContadorSegundo(game)<<endl; //borrar
                Vagon * vagon = (Vagon*)primero(locomotora)->ptrDato;
                if(!(vagon->detenido)){
                    cambiarColumna(game,primero(locomotora));
                    cambiarFila(game,primero(locomotora));
                }

                cambiarDireccion(game, locomotora);
                evaluarColision(game,locomotora,monedas,renderer);
                actualizarMinas(game);
                actualizarMonedas(game,monedas,renderer);

                if(getContadorSegundo(game)==IM){
                    int VM=numeroStringRand(game.parametros.claveVM);
                    generarMonedas(game,monedas,renderer,VM);
                    IM=getContadorSegundo(game)+numeroStringRand(game.parametros.claveIM);
                    cout<<"IM:"<<IM<<endl; //Prueba //borrar
                    cout<<"VM:"<<VM<<endl;
                }

            }
            if(!getGameOver(game)){
                if(getIntervalo(game)==2){
                    setGameOver(game,evaluarColisiones(game,primero(locomotora)));
                }
                SDL_RenderClear(renderer);
                dibujarTerreno(game,renderer);
                dibujarEntidades(game,renderer);
                dibujarPuntuacion(game,renderer,locomotora);
                SDL_RenderPresent(renderer);

                SDL_Delay(milisegundos);

            setIntervalo(game,getIntervalo(game)+1);
            }


        }
        cout<<"Destruimos las instancias"<<endl;
        eliminarLista(locomotora);
        eliminarLista(monedas);
        destruirGame(game,renderer);
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
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

    if((c>=0 && c<getColumna(game)) && (f>=0 && f<getFila(game))){

        Terreno terrenoAux =getTerreno(game)[f][c];
        if(terrenoAux.ptrNodoVagon==NULL){

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
        if(strcmp(getDireccion(*vagon),"der")==0)desplazamiento=1;
        if(strcmp(getDireccion(*vagon),"izq")==0)desplazamiento=-1;
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);
            terrenoAux[getFila(*vagon)][getColumna(*vagon)].ptrNodoVagon=NULL;
            terrenoAux[getFila(*vagon)][getColumna(*vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
            setColumna(*vagon,desplazamiento);
        }
        cambiarColumna(game,ptrNodo->sgte);
    }
}

void cambiarFila(Game &game, PtrNodoLista ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        Vagon *vagon = (Vagon*)ptrNodo->ptrDato;
        if(strcmp(getDireccion(*vagon),"aba")==0)desplazamiento=1;
        if(strcmp(getDireccion(*vagon),"arr")==0)desplazamiento=-1;
        if(desplazamiento!=0){
            Terreno **terrenoAux=getTerreno(game);
            if(ptrNodo->sgte==finLista()){
                terrenoAux[getFila(*vagon)][getColumna(*vagon)].ptrNodoVagon=NULL;
            }
            terrenoAux[getFila(*vagon)+desplazamiento][getColumna(*vagon)].ptrNodoVagon=ptrNodo;
            setFila(*vagon,desplazamiento);
        }
        cambiarFila(game,ptrNodo->sgte);
    }
}



void cambiarDireccion(Game &game, Lista &locomotora){
    PtrNodoLista ptrNodo = primero(locomotora);
    char direccion[4];
    strcpy(direccion, getDireccion(game));
    while(ptrNodo!=finLista()){
        Vagon *vagon = (Vagon*)ptrNodo->ptrDato;
        char dirAnterior[4];
        strcpy(dirAnterior, getDireccion(*vagon));
        if(
            ((strcmp(dirAnterior,"izq")==0 && strcmp(direccion,"der")!=0) ||
            (strcmp(dirAnterior,"der")==0 && strcmp(direccion,"izq")!=0) ||
            (strcmp(dirAnterior,"arr")==0 && strcmp(direccion,"aba")!=0) ||
            (strcmp(dirAnterior,"aba")==0 && strcmp(direccion,"arr")!=0)) &&
            !(vagon->detenido && vagon!=(Vagon*)primero(locomotora)->ptrDato)
        ){
            setDireccion(*vagon,direccion);//cargo la nueva direcci�n
        }
        strcpy(direccion,dirAnterior);
        ptrNodo = siguiente(locomotora, ptrNodo);
    }
}
void controlarEventos(Game &game,SDL_Event &event,const unsigned char *keys){
    if(SDL_PollEvent(&event)){
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

                }
                break;

        }
    }
}

int numeroStringRand(string numero){
    srand(time(NULL));
    int i=0;
    int j = atoi(numero.c_str());
    i=1+rand()%j;
    return i;
}


