#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

//Indica la posición inicial del objeto, el centro.
#define XSIZE 600
#define YSIZE 600

#define nave_size 20
#define nave_len 20
#define nave_vel 20
#define misil_size 10
#define misil_vel -5
#define MS 10
#define IMG_PATH "fondo.png"

typedef struct Nave nave;
typedef struct Misil misil;
struct Nave{
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int vx,vy; //velocidad
    Misil *misiles;
    };

 struct Misil{
    int x1,y1;
    int x2,y2;
    int vx,vy;
    };


using namespace std;


void navePinta(Nave *nave, SDL_Renderer *renderer); //Mostrar la nave
void naveAvanzaIzqDer(Nave *nave);
void naveAvanzaArrAba(Nave *nave);

int main(int argc, char *argv[]){
    ///INICIO PROGRAMA
    //Prepara el entorno para las peticiones de dibujo
    //En caso de error SLD Init devuelve -1 y cierra el programa
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){
        //Mensaje de inicio
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"OK", "SDL esta listo para ser utilizado", NULL);

        ///DEFINICIO DE ENTORNO
        int typeEvent;
        int gameOver;
        SDL_Window *window; //Referencia a la ventana principal
        SDL_Renderer *renderer;//Referencia al entorno donde se dibujara
        SDL_Event event;
        SDL_Surface* screenSurface= NULL;
        Nave nave= {XSIZE/2,YSIZE/2, XSIZE/2-nave_len,YSIZE/2+nave_len,XSIZE/2+nave_len,YSIZE/2+nave_len,nave_vel,nave_vel,NULL};



        window= SDL_CreateWindow( "Titulo de la ventana", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, //Posición x e y de ventana
        XSIZE,YSIZE, //Tamaño x e y
        SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC );

        //Los parametros, window que debe funcionar dentro de la ventana recien creada.
        //El indice es -1(De inicio)
        renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        gameOver=0;
        ///ELEMENTOS Y FLAGS DEL JUEGO

        SDL_Event ovent;

        //screenSurface= SDL_GetWindowSurface(window);
        //SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,0xFF,0XFF,0XFF));
        //SDL_Surface *sprite01= SDL_LoadBMP("sprite01.bmp");
        //SDL_BlitSurface (sprite01,NULL,screenSurface,NULL);

        const unsigned char *keys;
        keys= SDL_GetKeyboardState(NULL);

        while(!gameOver){
            ///Control de eventos mouse teclado
            if(SDL_PollEvent(&event)){
                typeEvent= event.type;
                if(typeEvent==SDL_QUIT){
                    gameOver=1;
                } else if(typeEvent== SDL_MOUSEBUTTONDOWN){
                    if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                       //Pendiente gameOver=1;
                    }
                } else if(typeEvent == SDL_KEYDOWN){
                    if(keys[SDL_SCANCODE_ESCAPE]){
                        gameOver=1;
                    }
                    else if(keys[SDL_SCANCODE_LEFT]){
                        nave.vx= -abs(nave.vx); //Convierte en negativo la vx
                        naveAvanzaIzqDer(&nave);
                    }
                    else if(keys[SDL_SCANCODE_RIGHT]){
                        nave.vx= abs(nave.vx); //Convierte en positivo la vx
                        naveAvanzaIzqDer(&nave);
                    }
                    else if(keys[SDL_SCANCODE_UP]){
                        nave.vy=-abs(nave.vy);//Convierte en negativo la vx(el eje negativo sube la nave)
                        naveAvanzaArrAba(&nave);
                    }
                    else if(keys[SDL_SCANCODE_DOWN]){
                          nave.vy=abs(nave.vy);
                        naveAvanzaArrAba(&nave);
                    }
                    else if(keys[SDL_SCANCODE_SPACE]){

                    }
                }
            }



            /// pantalla
            ///pintar el render
            SDL_SetRenderDrawColor(renderer,0,0,0,0);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer,255,255,255,0);




            SDL_UpdateWindowSurface(window);
            navePinta(&nave,renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(MS);
        }



        IMG_Init(IMG_INIT_PNG);
        //SDL_TEXTURE *imagen=NULL;
        SDL_Rect rectImag;
        int w_aux=0,h_aux=0;
        //imagen=IMG_LoadTexture(renderer,"fondo.png");
        //SDL_QueryTexture(imagen,NULL.NULL,&w_aux,&h_aux);
        rectImag.x=0;rectImag.y=0;rectImag.w=w_aux;rectImag.h=h_aux;


        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_QUIT;
        }

        ///BUCLE DE RENDER: Dentro estan los puntos 8,9,10,
        //8)Control de Eventos
       /* if(SDL_PollEvent(&event)){
                typeEvent=event.type;
                switch(typeEvent){
                    case SDL_QUIT:
                        gameOver=true;
                    break;
                    case SDL_KEYDOWN:
                    if(keys[SDL_SCANCODE_ESCAPE]){}
                }

        }*/


    return 0;
}

void navePinta(Nave *nave, SDL_Renderer *renderer){
    SDL_Point points[4]={
    {nave->x1,nave->y1},
    {nave->x2,nave->y2},
    {nave->x3,nave->y3},
    };
    points[3]=points[0];
    SDL_RenderDrawLines(renderer,points,4);

}

void naveAvanzaIzqDer(Nave *nave){
    nave->x1 += nave->vx;
    nave->x2 +=nave->vx;
    nave->x3 +=nave->vx;
}
void naveAvanzaArrAba(Nave *nave){
    nave->y1 += nave->vy;
    nave->y2 +=nave->vy;
    nave->y3 +=nave->vy;
}
