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
#include "Moneda.h"
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
void evaluarColision(Game &game,Lista &locomotora,Lista &monedas,Lista &bandidos,SDL_Renderer *renderer){
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
    else  if(game.terreno[fila][columna].ptrEstacion!=NULL && !(vagon->detenido)){
        agregarVagon(game, locomotora, *(game.terreno[fila][columna].ptrEstacion));
        while(nodo!=finLista()){
            vagon = (Vagon*)nodo->ptrDato;
            vagon->detenido = true;
            nodo = siguiente(locomotora, nodo);
        }
    }
    else if(game.terreno[fila][columna].ptrMoneda!=NULL && !(vagon->detenido)){
      reemplazarMoneda(game.terreno[fila][columna].ptrMoneda,renderer);

      PtrNodoLista ptrNodo = primero(monedas);
      PtrNodoLista ptrEliminar;
      while(ptrNodo!=finLista()){
        if((Moneda*)ptrNodo->ptrDato == game.terreno[fila][columna].ptrMoneda){
            ptrEliminar = ptrNodo;
        }
        ptrNodo = siguiente(monedas, ptrNodo);
      }
      eliminarNodo(monedas,ptrEliminar);
      destruirMoneda(game.terreno[fila][columna].ptrMoneda);
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
    while(is!=true){
         int fila = rand()%15; //Definir los drops para que no colisiones con los sprites
         int columna=rand()%16;
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
                destruirMoneda(moneda);
                game.terreno[moneda->fila][moneda->columna].ptrMoneda=NULL;
                eliminarNodo(monedas,ptrMoneda);

            }
       ptrMoneda=siguiente(monedas,ptrMoneda);
}

}
/*----------------------------------------------------------------------------*/
void generarBandidos(Game &game,Lista &bandidos, SDL_Renderer* renderer,int VB){
    Bandido *bandido= new Bandido;
    int intervaloFinal=game.contadorSegundo+VB;
    string codItem;
    bool is=false;
    srand(time(NULL));



    while(is!=true){
         int fila =rand()%getFila(game); //Definir los drops para que no colisiones con los sprites
         int columna=rand()%getColumna(game);
         //Me fijo que la fila y columna dada de forma random no este ya ocupada, si esta ocupada genero otra fila y columna
        if(game.terreno[fila][columna].ptrEstacion==NULL && game.terreno[fila][columna].ptrMoneda==NULL &&
           game.terreno[fila][columna].ptrMina==NULL  && game.terreno[fila][columna].ptrBandido==NULL && game.terreno[fila][columna].ptrNodoVagon==NULL){
            int P= numeroStringRand(game.parametros.claveP); //cantidad del item, pudiendo ser un número entero entre 1 y el máximo permitido (P).
            int opcion=numeroStringRand("6"); //numero random entre 1 y 6 para elegir un codItem
        switch (opcion) {
        case 1:
            codItem="oro";
            break;
        case 2:
            codItem="plata";
            break;
        case 3:
            codItem="bronce";
            break;
        case 4:
            codItem="platino";
            break;
        case 5:
           codItem="roca";
            break;
         case 6:
            codItem="carbon";
            break;
        }
        cout<<"bandido;"<<P<<"codItem:"<<codItem;
            crearBandido(*bandido,renderer,fila,columna,game.anchoCelda,game.altoCelda,game.altoSprite,codItem,P,VB,intervaloFinal);
            ubicarBandido(game,bandido);
            adicionarFinal(bandidos,bandido);
            is=true;
        }
    }


}
/*------------------------------------------------------*/
void actualizarBandidos(Game &game,Lista &bandidos, SDL_Renderer* renderer){
PtrNodoLista ptrBandido= primero(bandidos);
while(ptrBandido!=finLista()){
    Bandido *bandido= (Bandido*) ptrBandido->ptrDato;
            if(getContadorSegundo(game)==bandido->intervaloFinal){
                reemplazarBandido(bandido,renderer); //Reemplazar por suelo original
                destruirBandido(bandido);
                game.terreno[bandido->fila][bandido->columna].ptrBandido=NULL;
                eliminarNodo(bandidos,ptrBandido);
            }
       ptrBandido=siguiente(bandidos,ptrBandido);
}

}
/*------------------------------------------------------*/
void destruirGame(Game &game,SDL_Renderer* renderer){
    for(int f=0;f<game.fila;f++){
        for(int c=0;c<game.columna;c++){
            destruirTerreno(game.terreno[f][c]);
        }
    }
    eliminarLista(game.minas);
}
/*------------------------------------------------------*/
void agregarVagon(Game &game, Lista &locomotora, Estacion &estacion){
    if(getContadorMonedas(game)!=0){
        Vagon * vagon = (Vagon*)ultimo(locomotora)->ptrDato;
        int posX, posY;
        char * direccion = new char;

        nuevaPosicionVagon(game, vagon, posX, posY, direccion);
        if(strcmp(direccion,"nada")!=0){
            Vagon * nuevoVagon = new Vagon;
            crearVagon(*nuevoVagon,"c2", posX, posY,direccion,getAnchoCelda(*vagon), getAltoCelda(*vagon), getAltoSprite(*vagon), 5*getContadorMonedas(game),"nada");
            ubicarVagon(game,adicionarFinal(locomotora,nuevoVagon));
            setContadorMonedas(game, 0);
        }
    }
}
/*------------------------------------------------------*/
void nuevaPosicionVagon(Game &game, Vagon * ultimo, int &posX, int &posY, char * direccion){
    bool arribaNull = false; bool abajoNull = false; bool derechaNull = false; bool izquierdaNull = false;
    int fila = getFila(*ultimo);
    int columna = getColumna(*ultimo);

    if(game.terreno[fila-1][columna].ptrMina == NULL &&
        game.terreno[fila-1][columna].ptrEstacion ==NULL &&
        game.terreno[fila-1][columna].ptrNodoVagon == NULL &&
        fila!=0) arribaNull = true;

    if(game.terreno[fila+1][columna].ptrMina == NULL &&
        game.terreno[fila+1][columna].ptrEstacion ==NULL &&
        game.terreno[fila+1][columna].ptrNodoVagon == NULL &&
        fila!=getFila(game)-1) abajoNull = true;

    if(game.terreno[fila][columna-1].ptrMina == NULL &&
        game.terreno[fila][columna-1].ptrEstacion ==NULL &&
        game.terreno[fila][columna-1].ptrNodoVagon == NULL &&
        columna!=0) izquierdaNull = true;

    if(game.terreno[fila][columna+1].ptrMina == NULL &&
        game.terreno[fila][columna+1].ptrEstacion ==NULL &&
        game.terreno[fila][columna+1].ptrNodoVagon == NULL &&
        columna!=getColumna(game)-1) derechaNull = true;

    strcpy(direccion,"nada");


    if(strcmp(getDireccion(*ultimo),"arr")==0){
        if(abajoNull){
            strcpy(direccion,"arr");
            posX = fila+1;
            posY = columna;
        }
        else if(derechaNull){
            strcpy(direccion,"izq");
            posX = fila;
            posY = columna+1;
        }
        else if (izquierdaNull){
            strcpy(direccion,"der");
            posX = fila;
            posY = columna-1;
        }
    }

    else if(strcmp(getDireccion(*ultimo),"aba")==0){
        if(arribaNull){
            strcpy(direccion,"aba");
            posX = fila-1;
            posY = columna;
        }
        else if(derechaNull){
            strcpy(direccion,"izq");
            posX = fila;
            posY = columna+1;
        }
        else if (izquierdaNull){
            strcpy(direccion,"der");
            posX = fila;
            posY = columna-1;
        }
    }

    else if(strcmp(getDireccion(*ultimo),"der")==0){
        if(izquierdaNull){
            strcpy(direccion,"der");
            posX = fila;
            posY = columna-1;
        }
        else if(arribaNull){
            strcpy(direccion,"aba");
            posX = fila-1;
            posY = columna;
        }
        else if (abajoNull){
            strcpy(direccion,"arr");
            posX = fila+1;
            posY = columna;
        }
    }

    else if(strcmp(getDireccion(*ultimo),"izq")==0){
        if(derechaNull){
            strcpy(direccion,"izq");
            posX = fila;
            posY = columna+1;
        }
        else if(arribaNull){
            strcpy(direccion,"aba");
            posX = fila-1;
            posY = columna;
        }
        else if (abajoNull){
            strcpy(direccion,"arr");
            posX = fila+1;
            posY = columna;
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

void encuentroConBandido(Game &game, Lista &locomotora, Lista &bandidos){
    PtrNodoLista ptrNodoVagon= primero(locomotora);

    while(ptrNodoVagon!=finLista()){
        Vagon * vagon = (Vagon*)ptrNodoVagon->ptrDato;
        int area = atoi(getClaveA(game.parametros).c_str());
        int minI = 0;
        int minJ = 0;
        int maxI = getFila(game)-1;
        int maxJ = getColumna(game)-1;

        if((getFila(*vagon)-area)>0){
            minI = getFila(*vagon) - area;
        }
        if((getColumna(*vagon)-area)>0){
            minJ = getColumna(*vagon) - area;
        }

        if((getFila(*vagon)+area)<getFila(game)-1){
            maxI = getFila(*vagon)+ area;
        }
        if((getColumna(*vagon)+area)<getColumna(game)-1){
            maxJ = getColumna(*vagon) + area;
        }

        for(int i = minI;i<=maxI;i++){
            for(int j = minJ;j<=maxJ;j++){
                if(game.terreno[i][j].ptrBandido!=NULL){
                    pedirItem(game,locomotora,*(game.terreno[i][j].ptrBandido));
                    if(!listaVacia(locomotora)){
                        PtrNodoLista ptrBandido = primero(bandidos);
                        PtrNodoLista ptrEliminar;
                        while(ptrBandido!=finLista()){
                            if((Bandido*)ptrBandido->ptrDato == game.terreno[i][j].ptrBandido){
                                ptrEliminar = ptrBandido;
                            }
                            ptrBandido = siguiente(bandidos, ptrBandido);
                        }
                        eliminarNodo(bandidos,ptrEliminar);

                        destruirBandido(game.terreno[i][j].ptrBandido);
                        game.terreno[i][j].ptrBandido=NULL;
                    }
                }
            }
        }
        ptrNodoVagon = siguiente(locomotora,ptrNodoVagon);
    }
}

void pedirItem(Game &game,Lista &locomotora, Bandido &bandido){
    PtrNodoLista ptrNodoVagon = primero(locomotora);

    while(ptrNodoVagon!=finLista() && getCantidadItem(&bandido)>0){
        Vagon * vagon = (Vagon*)ptrNodoVagon->ptrDato;
        if(getCodItem(*vagon)==getCodItem(&bandido)){
            Pila * cajas = getCajas(*vagon);

            while(getCantidadItem(&bandido)!=0 && !pilaVacia(*cajas)){
                Caja * caja = (Caja*)cima(*cajas)->ptrDato;
                if((getCapacidadActual(*caja)-getCantidadItem(&bandido))<=0){
                    setCantidadItem(bandido, getCantidadItem(&bandido)-getCapacidadActual(*caja));
                    eliminarCaja(*caja);
                    sacar(*cajas);
                }
                else{
                    setCapacidadActual(*caja, getCapacidadActual(*caja)-getCantidadItem(&bandido));
                    setCantidadItem(*vagon, getCantidadItem(*vagon)-getCantidadItem(&bandido));
                    setCantidadItem(bandido, 0);
                }
            }
        }

        ptrNodoVagon = siguiente(locomotora,ptrNodoVagon);
    }

    if(getCantidadItem(&bandido)!=0){
        Vagon * vagon = (Vagon*)ultimo(locomotora)->ptrDato;
        game.terreno[getFila(*vagon)][getColumna(*vagon)].ptrNodoVagon = NULL;
        eliminarNodoUltimo(locomotora);
        if(listaVacia(locomotora)){
            setGameOver(game,true);
        }
    }
}

