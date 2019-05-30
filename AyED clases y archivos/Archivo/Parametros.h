#ifndef PARAMETROS_H
#define PARAMETROS_H
#include <string>

using namespace std;

/** Definicion del tipo de datos **/
typedef struct{
    string claveS;
    string claveP;
    string claveA;
    string clavePOSXE;
    string clavePOSYE;
    string claveIM;
    string claveVM;
    string claveIB;
    string claveVB;
    string claveIP;
    string valor;
}Parametros;


void crear_parametros(Parametros &parametros);



void destruir_parametros(Parametros &parametros);


void setClaveS(Parametros &parametros, string clav);
void setClaveP(Parametros &parametros, string clav);
void setClaveA(Parametros &parametros, string clav);
void setClavePOSXE(Parametros &parametros, string clav);
void setClavePOSYE(Parametros &parametros, string clav);
void setClaveIM(Parametros &parametros, string clav);
void setClaveVM(Parametros &parametros, string clav);
void setClaveIB(Parametros &parametros, string clav);
void setClaveVB(Parametros &parametros, string clav);
void setClaveIP(Parametros &parametros, string clav);


string getClaveS(Parametros &parametros);
string getClaveP(Parametros &parametros);
string getClaveA(Parametros &parametros);
string getClavePOSXE(Parametros &parametros);
string getClavePOSYE(Parametros &parametros);
string getClaveIM(Parametros &parametros);
string getClaveVM(Parametros &parametros);
string getClaveIB(Parametros &parametros);
string getClaveVB(Parametros &parametros);
string getClaveIP(Parametros &parametros);




void setValor(Parametros &parametros, string val);


string getValor(Parametros &parametros);


#endif // CONFIGURACION_H_INCLUDED
