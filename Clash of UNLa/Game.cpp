#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include "Game.h"
#include "Celda.h"
#include "Terreno.h"
#include "Bandido.h"
#include "Lista.h"
#include "Vagon.h"
#include <ctime>
#include <stdlib.h>
#include "Caja.h"
#include "Mina.h"
#include <SDL_ttf.h>
#include <string>



/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/

void crearGame(Game &game,int fila,int columna,int anchoCelda,int altoCelda,int altoSprite){
    game.gameover=false;
    game.intervalo=0;
    game.contadorSegundo=0;
    game.contadorMonedas=0;
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
    crearParametros(game.parametros);

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
int getContadorSegundo(Game &game){
    return game.contadorSegundo;
}
/*----------------------------------------------------------------------------*/
void setContadorSegundo(Game &game, int contadorSegundo){
    game.contadorSegundo=contadorSegundo;
}
/*----------------------------------------------------------------------------*/
int getContadorMonedas(Game &game){
    return game.contadorMonedas;
}
/*----------------------------------------------------------------------------*/
void setContadorMonedas(Game &game, int contadorMonedas){
    game.contadorMonedas=contadorMonedas;
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
void leerMinas(Game &game, SDL_Renderer * renderer){
    ifstream entrada("Minas.txt");

    string strposx,strposy,strcoditem,strip,strseq1,strseq2,strseq3,strseq4,strseq5;
    int posX,posY,ip,seq1,seq2,seq3,seq4,seq5;
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
              crearMina(*mina, renderer, posY, posX, getAnchoCelda(game), getAltoCelda(game), game.altoSprite, ip, secuencia,strcoditem);
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


void leerComanda(Game &game){
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

void leerParametros(Game &game){
    ifstream entrada("Parametros.txt");
    string clave,valor;
     if(entrada.fail()){
         cout<<"No se pudo abrir el archivo Parametros.txt ";
        exit(EXIT_FAILURE);
    }
    while(!entrada.eof()){
    getline(entrada,clave,'=');
    getline(entrada,valor);
    setParametros(game,clave,valor);
    }
    entrada.close();
    fflush(stdin);
}

void setParametros(Game &game, string clave, string valor){
    if (clave == "s" || clave == "S")
        game.parametros.claveS = valor;
    else if (clave == "p" || clave == "P")
        game.parametros.claveP = valor;
    else if (clave == "a" || clave == "A")
        game.parametros.claveA = valor;
    else if (clave == "posXE")
        game.parametros.claveposXE = valor;
    else if (clave == "posYE")
        game.parametros.claveposYE = valor;
    else if (clave == "im" ||  clave == "IM")
        game.parametros.claveIM = valor;
    else if (clave == "vm" || clave == "VM")
        game.parametros.claveVM = valor;
    else if (clave == "ib" || clave == "IB")
        game.parametros.claveIB = valor;
    else if (clave == "vb" || clave == "VB")
        game.parametros.claveVB =valor;
    else if (clave == "ip" || clave == "IP")
        game.parametros.claveIP =valor;

    }

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
int getColumna(Game &game){
    return game.columna;
}
/*----------------------------------------------------------------------------*/
int getFila(Game &game){
    return game.fila;
}
/*----------------------------------------------------------------------------*/
void evaluarColision(Game &game,Lista &locomotora,Lista &monedas,SDL_Renderer *renderer){
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
        recolectarCajas(*(game.terreno[fila][columna].ptrMina), locomotora);
        while(nodo!=finLista()){
            vagon = (Vagon*)nodo->ptrDato;
            vagon->detenido = true;
            nodo = siguiente(locomotora, nodo);
        }
    }
    else if(game.terreno[fila][columna].ptrEstacion!=NULL && !(vagon->detenido)){
        while(nodo!=finLista()){
            vagon = (Vagon*)nodo->ptrDato;
            vagon->detenido = true;
            nodo = siguiente(locomotora, nodo);
        }
    }

    else if(game.terreno[fila][columna].ptrMoneda!=NULL && !(vagon->detenido)){
      reemplazarMoneda(game.terreno[fila][columna].ptrMoneda,renderer);
      game.terreno[fila][columna].ptrMoneda=NULL;
      game.contadorMonedas=game.contadorMonedas+1;

    }
     if(game.terreno[fila][columna].ptrMina==NULL && game.terreno[fila][columna].ptrEstacion==NULL && vagon->detenido){
        while(nodo!=finLista()){
            vagon = (Vagon*)nodo->ptrDato;
            vagon->detenido = false;
            nodo = siguiente(locomotora, nodo);
        }
    }
}
/*----------------------------------------------------------------------------*/
void actualizarMinas(Game &game){
    PtrNodoLista ptrMina = primero(game.minas);
    while(ptrMina!=finLista()){
        Mina * mina = (Mina*)ptrMina->ptrDato;
        if(getIntervarloActual(*mina)==getIP(*mina)){
            Caja *caja = new Caja;
            int *secuencia = getSecuencia(*mina);
            crearCaja(*caja,secuencia[getSecuenciaActual(*mina)],secuencia[getSecuenciaActual(*mina)],
                      secuencia[getSecuenciaActual(*mina)],getCodItem(mina));
            encolar(mina->cajas,caja);
            setIntervaloActual(*mina,0);
            if(getSecuenciaActual(*mina)==4){
                setSecuenciaActual(*mina,0);
            }
            else{
                setSecuenciaActual(*mina, getSecuenciaActual(*mina)+1);
            }
        }
        else{
            setIntervaloActual(*mina, getIntervarloActual(*mina)+1);
        }
        ptrMina = siguiente(game.minas,ptrMina);
    }
}
/*----------------------------------------------------------------------------*/

void dibujarPuntuacion(Game &game, SDL_Renderer * renderer, Lista &locomotora){
    int oro=0; int plata=0; int bronce=0; int platino=0; int carbon=0; int roca=0;
    int oroMax,plataMax,bronceMax,platinoMax,carbonMax,rocaMax;
    PtrNodoLista ptrVagon = primero(locomotora);

    while(ptrVagon!=finLista()){
        Vagon * vagon = (Vagon*)ptrVagon->ptrDato;
        if(getCodItem(*vagon)=="oro"){
            oro += getCantidadItem(*vagon);
        }
        else if(getCodItem(*vagon)=="plata"){
            plata += getCantidadItem(*vagon);
        }
        else if(getCodItem(*vagon)=="bronce"){
            bronce += getCantidadItem(*vagon);
        }
        else if(getCodItem(*vagon)=="platino"){
            platino += getCantidadItem(*vagon);
        }
        else if(getCodItem(*vagon)=="carbon"){
            carbon += getCantidadItem(*vagon);
        }
        else if(getCodItem(*vagon)=="roca"){
            roca += getCantidadItem(*vagon);
        }
        ptrVagon = siguiente(locomotora, ptrVagon);
    }

    PtrNodoLista ptrComanda = primero(game.comanda);
    while(ptrComanda!=finLista()){
        Comanda * comanda = (Comanda*)ptrComanda->ptrDato;
        if(getCodItem(*comanda)=="oro"){oroMax = getCantidad(*comanda);}
        else if(getCodItem(*comanda)=="plata"){plataMax = getCantidad(*comanda);}
        else if(getCodItem(*comanda)=="bronce"){bronceMax = getCantidad(*comanda);}
        else if(getCodItem(*comanda)=="platino"){platinoMax = getCantidad(*comanda);}
        else if(getCodItem(*comanda)=="roca"){rocaMax = getCantidad(*comanda);}
        else if(getCodItem(*comanda)=="carbon"){carbonMax = getCantidad(*comanda);}
        ptrComanda = siguiente(game.comanda,ptrComanda);
    }
    stringstream ss;
    ss << "Oro: " << oro << "/" << oroMax <<
            "  Plata: "<< plata << "/" << plataMax <<
            "  Bronce: " << bronce << "/" << bronceMax <<
            "  Platino: " << platino << "/" << platinoMax <<
            "  Roca: " << roca << "/" << rocaMax <<
            "  Carbon: " << carbon << "/" << carbonMax<<
             "  Monedas:"<<game.contadorMonedas;
    string temp = ss.str();
    char const * puntuacion = temp.c_str();
    TTF_Font* arial = TTF_OpenFont("arial.ttf", 16);

    SDL_Color blanco = {255, 255, 255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Blended(arial,puntuacion,blanco);

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    int texW = 0;
    int texH = 0;
    TTF_SizeText(arial, puntuacion, &texW, &texH);

    SDL_Rect Message_rect = {0, 0, texW, texH};

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    TTF_CloseFont(arial);
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
}
/*----------------------------------------------------------------------------*/
void generarMonedas(Game &game,Lista &monedas, SDL_Renderer* renderer,int VM){
    Moneda *moneda= new Moneda;
    int intervaloFinal=game.contadorSegundo+VM;
    bool is=false;
    srand(time(NULL));
    int fila = rand()%15; //Definir los drops para que no colisiones con los sprites
    int columna=rand()%20;
    while(is!=true){
         int fila = rand()%15; //Definir los drops para que no colisiones con los sprites
         int columna=rand()%20;
        if(game.terreno[fila][columna].ptrEstacion==NULL && game.terreno[fila][columna].ptrMoneda==NULL &&
           game.terreno[fila][columna].ptrMina==NULL  && game.terreno[fila][columna].ptrBandido==NULL && game.terreno[fila][columna].ptrNodoVagon==NULL){
            crearMoneda(*moneda,renderer,fila,columna,game.anchoCelda,game.altoCelda,game.altoSprite,VM,intervaloFinal);
            ubicarMoneda(game,moneda);
            adicionarFinal(monedas,moneda);
            is=true;
        }
    }


}
/*------------------------------------------------------*/
void actualizarMonedas(Game &game,Lista &monedas, SDL_Renderer* renderer){
PtrNodoLista ptrMoneda= primero(monedas);
while(ptrMoneda!=finLista()){
    Moneda *moneda= (Moneda*) ptrMoneda->ptrDato;
            if(getContadorSegundo(game)==moneda->intervaloFinal){
                reemplazarMoneda(moneda,renderer); //Reemplazar por suelo original
                game.terreno[moneda->fila][moneda->columna].ptrMoneda=NULL;
                eliminarNodo(monedas,ptrMoneda);

            }
       ptrMoneda=siguiente(monedas,ptrMoneda);
}

}

void destruirGame(Game &game,SDL_Renderer* renderer){
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            destruirTerreno(game.terreno[f][c]);
        }
    }
    eliminarLista(game.minas);
}
