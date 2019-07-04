#ifndef __ESTACION_H__
#define __ESTACION_H__
#include <SDL.h>
#include <SDL_image.h>

#define CAPACIDAD_VAGON 5

using namespace std;

/**
    AXIOMAS:
    Representa la posicion donde se compran vagones. F y C no pueden estar fuera de rango.
    La estacion "vende" vagones en relacion a la formula Peso_maximo = 5kg*cantidad_monedas.
*/

/**
    Definición del tipo de dato.
*/

/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct Estacion{
    int f;
    int c;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Estacion;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
    pre: Estacion no debe existir
    post: Estacion es creada y devuelve los valores iniciales
    estacion:Estructura de datos a utilizar
*/
void crearEstacion(Estacion &estacion,SDL_Renderer* renderer, int f,int c, int anchoCelda,
                int altoCelda);
/*----------------------------------------------------------------------------*/
/*
    pre : la estacion debe haber sido creada.
    post: se obtiene la fila donde se encuentra la estacion.
    return : fila
*/

int getFila(Estacion *estacion);

/*----------------------------------------------------------------------------*/
/*
  pre : la estacion debe haber sido creada.
  post: se setea la fila donde se encontrara de la estacion.
  estacion: estructura de datos a ser usada.
  fila: fila donde estara la estacion.
*/
void setFila(Estacion &estacion, int fila);

/*----------------------------------------------------------------------------*/
/*
  pre : la estacion debe haber sido creada.
  post: se obtiene la columna donde se encuentra la estacion.
  return : columna
*/
int getColumna(Estacion *estacion);

/*----------------------------------------------------------------------------*/
/*
  pre : la estacion debe haber sido creada.
  post: se setea la columna donde se encontrara de la estacion.
  estacion: estructura de datos a ser usada.
  columna: columna donde estara la estacion.
*/
void setColumna(Estacion &estacion, int columna);
/*----------------------------------------------------------------------------*/

/*
  pre : la estacion debe haber sido creada.
  post: se dibuja la estacion
  estacion: estructura de datos a ser usado.
  renderer
/*----------------------------------------------------------------------------*/

void dibujarEstacion(Estacion *estacion,SDL_Renderer* renderer);

/*
    pre: Estacion creada
    post: calcula y devuelve peso que soporta vagon
*/
/*----------------------------------------------------------------------------*/
int venderVagon(Estacion &estacion, int cantidadMonedas);

/*
    pre: Estacion creada
    post: Se libera la memoria de la estacion y queda inutilizable
*/
/*----------------------------------------------------------------------------*/
void destruirEstacion(Estacion &estacion);

#endif
