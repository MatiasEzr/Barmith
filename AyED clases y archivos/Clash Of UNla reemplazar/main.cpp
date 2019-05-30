#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <conio.h>// agrega la funcuion getch(); que es trabante de procesos

#include <Windows.h>//sonido
#include <MMsystem.h>//sonido
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Bandido.h"
#include "Partida.h"
#include "Celda.h"



#define milisegundos 30
using namespace std;

void evaluarEventosTeclado(Partida &partida,SDL_Event &event,const unsigned char *keys);
void cambiarDireccion(PtrNodoVagon ptrNodo,char direccion[]);

void cambiarCapaInicio(Partida &partida,PtrNodoVagon ptrNodo);
void cambiarCapaFinal(Partida &partida,PtrNodoVagon ptrNodo);
void cambiarColumna(Partida &partida,PtrNodoVagon ptrNodo);
bool evaluarColisiones(Partida &partida,PtrNodoVagon ptrNodo);
/*
void dibujarPersona(Persona &persona, SDL_Renderer* renderer);
void destruirPersona(Persona &persona);
void dibujarSuperficie(SDL_Renderer *renderer);
void reubicamosPersonaALaDerecha (Persona &persona);
void reubicamosPersonaALaIzquierda (Persona &persona);
void reubicamosPersonaAbajo (Persona &persona);
void reubicamosPersonaArriba(Persona &persona);
void correrHaciaLaIzquierda(Persona &persona, int subIntervalo);
void correrHaciaLaDerecha(Persona &persona, int subIntervalo);
void correrHaciaArriba(Persona &persona, int subIntervalo);
void correrHaciaAbajo(Persona &persona, int subIntervalo);
*/
int main(int argc, char** argv) {
        /*Datos que leo desde un archivo************/

        int filas = 20;int columnas = 15; int anchoCelda = 40;  int altoCelda = 40; int altoSprite = 70;

        /********************************************/
        int anchoVentana = columnas*anchoCelda;
        int altoVentana = filas*altoCelda;


    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;

        window = SDL_CreateWindow("Juego", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, altoVentana, anchoVentana,
        SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);

        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);



        IMG_Init(IMG_INIT_PNG);



        Partida partida;
        crearPartida(partida,filas,columnas,anchoCelda,altoCelda,altoSprite);
        setTablero(partida,renderer);
        setTerreno(partida);

        Locomotora locomotora;
        crearLocomotora(locomotora);

        Vagon vagon;
        crearVagon(vagon,"c1", 0, 4,"der",anchoCelda, altoCelda, altoSprite);//el primero es c1
        ubicarVagon(partida,adicionarPrincipio(locomotora,vagon));
        setDireccion(partida,getDireccion(primero(locomotora)->vagon));//la direccion de la partida es = a la del primer vagon

        crearVagon(vagon,"c2", 0, 3,"der",anchoCelda, altoCelda, altoSprite);//los demás son c2
        ubicarVagon(partida,adicionarUltimo(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 2,"der",anchoCelda, altoCelda, altoSprite);
        ubicarVagon(partida,adicionarUltimo(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 1,"der",anchoCelda, altoCelda, altoSprite);
        ubicarVagon(partida,adicionarUltimo(locomotora,vagon));
        crearVagon(vagon,"c2", 0, 0,"der",anchoCelda, altoCelda, altoSprite);
        ubicarVagon(partida,adicionarUltimo(locomotora,vagon));




        /*
        Bandido bandido;
        Item item;
        Bandido *ptrBandido = &bandido;
        Sprite sprite;//aparece en el cuadrante 5,5
        crearSprite(sprite,5,5,40,40,renderer);
        crearBandido(bandido,sprite,item,5,5);
        ubicarBandido(partida,ptrBandido);

        Mina mina;
        Mina *ptrMina = &mina;
        Sprite sprite2;//aparece en el cuadrante 5,5
        crearSprite(sprite2,5,5,40,40,renderer);
        crearMina(mina,sprite2,item,1);
        ubicarMina(partida,ptrMina);

        Moneda moneda;
        Moneda *ptrMoneda = &moneda;
        Sprite sprite3;//aparece en el cuadrante 5,5
        crearSprite(sprite3,5,5,40,40,renderer);
        crearMoneda(moneda,sprite3,5);
        ubicarMoneda(partida,ptrMoneda);

*/



        ///ELEMENTOS Y FLAGS DEL JUEGO
        const unsigned char *keys;
        keys= SDL_GetKeyboardState(NULL);



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
        //podemos evaluar la adquisición de monedas, de minas o ataques de villanos

        //luego redireccionamos a todos los Vagons desde el primero
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
destruirLocomotora(locomotora);
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
    cout<<"Chocamos con otro Vagon en "<<f<<"/"<<c<<endl;
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
    Terreno **TerrenoAux=getTerreno(partida);// partida.Terreno
    TerrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
    TerrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)+desplazamiento].ptrNodoVagon=ptrNodo;
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
    Terreno **TerrenoAux=getTerreno(partida);// partida.Terreno
    TerrenoAux[getFila(ptrNodo->vagon)*2][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
    TerrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
    Celda **tableroAux=getTablero(partida);// partida.Terreno
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
    Terreno **TerrenoAux=getTerreno(partida);// partida.Terreno
    TerrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=NULL;
    TerrenoAux[(getFila(ptrNodo->vagon)*2)+desplazamiento+desplazamiento][getColumna(ptrNodo->vagon)].ptrNodoVagon=ptrNodo;
    Celda **tableroAux=getTablero(partida);// partida.Terreno
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


/*

void crearPersona(Persona &persona, int f, int c, int anchoCelda, int altoCelda, SDL_Renderer* renderer){
    persona.f=f;//coordenada logica y
    persona.c=c;//coordenada logica x
    persona.imagen= IMG_LoadTexture(renderer,"persona.png");

    persona.rectImag.y=f* altoCelda;//coordenada de dibujo y
    persona.rectImag.x= c* anchoCelda;//coordenada de dibujo x
    persona.rectImag.w= anchoCelda;//ancho
    persona.rectImag.h= altoCelda;//alto
}

void dibujarPersona(Persona &persona, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, persona.imagen,NULL,&(persona.rectImag));
}

void destruirPersona(Persona &persona){
    SDL_DestroyTexture(persona.imagen);
}

void dibujarSuperficie(SDL_Renderer *renderer){
         SDL_Surface* Loading_Surf;
         SDL_Texture: SDL_Texture *Terreno;
         Loading_Surf=SDL_LoadBMP("Terreno.bmp");
         Terreno= SDL_CreateTextureFromSurface(renderer,Loading_Surf);
         SDL_FreeSurface(Loading_Surf);
         SDL_RenderCopy(renderer,Terreno,NULL,NULL);
}

void correrHaciaLaDerecha(Persona &persona, int subIntervalo){
    persona.rectImag.x= (persona.c* 40) + ((40/10)*subIntervalo) ;
}//40 es el ancho del Celda, y 10 es la cantidad de imágenes del intervalo.

void correrHaciaLaIzquierda(Persona &persona, int subIntervalo){
    persona.rectImag.x= (persona.c* 40) - ((40/10)*subIntervalo) ;
}//40 es el ancho del Celda, y 10 es la cantidad de imágenes del intervalo.

void correrHaciaAbajo(Persona &persona, int subIntervalo){
    persona.rectImag.y= (persona.f* 40) + ((40/10)*subIntervalo) ;
}//40 es el ancho del Celda, y 10 es la cantidad de imágenes del intervalo.

void correrHaciaArriba(Persona &persona, int subIntervalo){
    persona.rectImag.y= (persona.f* 40) - ((40/10)*subIntervalo) ;
}//40 es el ancho del Celda, y 10 es la cantidad de imágenes del intervalo.

void reubicamosPersonaALaDerecha (Persona &persona){
    persona.c=persona.c+1; //o persona.c++;
}
void reubicamosPersonaALaIzquierda (Persona &persona){
    persona.c=persona.c-1; //o persona.c--;
}
void reubicamosPersonaAbajo (Persona &persona){
    persona.f=persona.f+1; //o persona.f++;
}
void reubicamosPersonaArriba (Persona &persona){
    persona.f=persona.f-1; //o persona.f--;
}


*/



//main anterior
/* while(gameOver==0){
                //aquí según los eventos de teclado podríamos cambiar las coordenadas de persona… tarea para la casa ;)
                SDL_RenderClear(renderer);//borro el renderer
                dibujarSuperficie(renderer);
                dibujarPersona(persona,renderer);
                dibujarPersona(sprite2,renderer);
                SDL_RenderPresent(renderer);// dibuja el renderer, aplica todos los cambios que se hicieron en dibujarPersona()



                ///Control de eventos mouse/teclado

                if(SDL_PollEvent(&event)){
                typeEvent= event.type;
                if(typeEvent==SDL_QUIT){
                    gameOver=1;
                }

                else if(typeEvent== SDL_MOUSEBUTTONDOWN){
                    if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                       //Pendiente
                    }
                                                        }
                else if(typeEvent == SDL_KEYDOWN){
                    if(keys[SDL_SCANCODE_ESCAPE]){
                        gameOver=1;
                    }
                    else if(keys[SDL_SCANCODE_LEFT]){
                     reubicamosPersonaALaIzquierda(persona);
                    correrHaciaLaIzquierda(persona,subIntervalo);



                    }
                    else if(keys[SDL_SCANCODE_RIGHT]){
                                reubicamosPersonaALaDerecha(persona);
                                correrHaciaLaDerecha(persona,subIntervalo);


                    }
                    else if(keys[SDL_SCANCODE_UP]){
                                reubicamosPersonaArriba(persona);
                                correrHaciaArriba(persona,subIntervalo);


                    }
                    else if(keys[SDL_SCANCODE_DOWN]){
                                reubicamosPersonaAbajo(persona);
                                correrHaciaAbajo(persona,subIntervalo);


                    }
                    }
         }

*/



