#ifndef PARAMETROS_H
#define PARAMETROS_H
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/** Definicion del tipo de datos **/
typedef struct{
    char claveS[20]; //
    char claveP[20]; //
    char claveA[20]; //
    char clavePOSXE[20]; //
    char clavePOSYE[20]; //
    char claveIM[20]; //
    char claveVM[20]; //
    char claveIB[20]; //
    char claveVB[20]; //
    char claveIP[20]; //
    char valor[20]; //
}Parametros;


void crear_parametros(Parametros &parametros);



void destruir_parametros(Parametros &parametros);


void setClaveS(Parametros &parametros, char* clav);
void setClaveP(Parametros &parametros, char* clav);
void setClaveA(Parametros &parametros, char* clav);
void setClavePOSXE(Parametros &parametros, char* clav);
void setClavePOSYE(Parametros &parametros, char* clav);
void setClaveIM(Parametros &parametros, char* clav);
void setClaveVM(Parametros &parametros, char* clav);
void setClaveIB(Parametros &parametros, char* clav);
void setClaveVB(Parametros &parametros, char* clav);
void setClaveIP(Parametros &parametros, char* clav);


char* getClaveS(Parametros &parametros);
char* getClaveP(Parametros &parametros);
char* getClaveA(Parametros &parametros);
char* getClavePOSXE(Parametros &parametros);
char* getClavePOSYE(Parametros &parametros);
char* getClaveIM(Parametros &parametros);
char* getClaveVM(Parametros &parametros);
char* getClaveIB(Parametros &parametros);
char* getClaveVB(Parametros &parametros);
char* getClaveIP(Parametros &parametros);




void setValor(Parametros &parametros, char* val);


char* getValor(Parametros &parametros);


#endif // CONFIGURACION_H_INCLUDED
