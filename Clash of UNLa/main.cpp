        #include <iostream>
        #include <stdio.h>
        #include <stdlib.h>
        #include <SDL.h>
        #include <SDL_image.h>
        #include "Sprite.h"
        #include "Bandido.h"




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
                int filas = 20;int columnas = 15; int anchoCasillero = 40;  int altoCasillero = 40;
                /********************************************/
                int anchoVentana = columnas*anchoCasillero;
                int altoVentana = filas*altoCasillero;

            if(SDL_Init(SDL_INIT_EVERYTHING)>=0){
                SDL_Window *window;
                SDL_Renderer *renderer;
                SDL_Event event; int typeEvent;

                window = SDL_CreateWindow("Juego", SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, altoVentana, anchoVentana,
                SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
                renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);



                IMG_Init(IMG_INIT_PNG);


                Sprite sprite;//aparece en el cuadrante 5,5
                crearSprite(sprite,5,5,40,40,renderer);
                Bandido bandido;
                //Atributos de bandido(Bandido &bandido,Sprite sprite,Item item, int cantidad, int intervaloVida)
                crearBandido(bandido,sprite,NULL,5,5);

                ///ELEMENTOS Y FLAGS DEL JUEGO
                const unsigned char *keys;
                keys= SDL_GetKeyboardState(NULL);



                int subIntervalo = 0; //valor de 0 a 10;
                int gameOver=0;


                while(gameOver==0){
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
                SDL_Delay(100);

                }

                destruirPersona(persona);

                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                IMG_Quit();
                SDL_Quit();
            }
            return 0;
        }

/*

        void crearPersona(Persona &persona, int f, int c, int anchoCasillero, int altoCasillero, SDL_Renderer* renderer){
            persona.f=f;//coordenada logica y
            persona.c=c;//coordenada logica x
            persona.imagen= IMG_LoadTexture(renderer,"persona.png");

            persona.rectImag.y=f* altoCasillero;//coordenada de dibujo y
            persona.rectImag.x= c* anchoCasillero;//coordenada de dibujo x
            persona.rectImag.w= anchoCasillero;//ancho
            persona.rectImag.h= altoCasillero;//alto
        }

        void dibujarPersona(Persona &persona, SDL_Renderer* renderer){
            SDL_RenderCopy(renderer, persona.imagen,NULL,&(persona.rectImag));
        }

        void destruirPersona(Persona &persona){
            SDL_DestroyTexture(persona.imagen);
        }

        void dibujarSuperficie(SDL_Renderer *renderer){
                 SDL_Surface* Loading_Surf;
                 SDL_Texture: SDL_Texture *mapa;
                 Loading_Surf=SDL_LoadBMP("mapa.bmp");
                 mapa= SDL_CreateTextureFromSurface(renderer,Loading_Surf);
                 SDL_FreeSurface(Loading_Surf);
                 SDL_RenderCopy(renderer,mapa,NULL,NULL);
        }

        void correrHaciaLaDerecha(Persona &persona, int subIntervalo){
            persona.rectImag.x= (persona.c* 40) + ((40/10)*subIntervalo) ;
        }//40 es el ancho del casillero, y 10 es la cantidad de imágenes del intervalo.

        void correrHaciaLaIzquierda(Persona &persona, int subIntervalo){
            persona.rectImag.x= (persona.c* 40) - ((40/10)*subIntervalo) ;
        }//40 es el ancho del casillero, y 10 es la cantidad de imágenes del intervalo.

        void correrHaciaAbajo(Persona &persona, int subIntervalo){
            persona.rectImag.y= (persona.f* 40) + ((40/10)*subIntervalo) ;
        }//40 es el ancho del casillero, y 10 es la cantidad de imágenes del intervalo.

        void correrHaciaArriba(Persona &persona, int subIntervalo){
            persona.rectImag.y= (persona.f* 40) - ((40/10)*subIntervalo) ;
        }//40 es el ancho del casillero, y 10 es la cantidad de imágenes del intervalo.

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
