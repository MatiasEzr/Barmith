#include "Parametros.h"
#include <iostream>
#include <string>

using namespace std;



/** Definicion de Primitivas **/

/** pre: la instancia Parametros no debe haberse creado ni estar destruida
post: Parametros creado y listo para ser usado
Parametros: instancia sobre la que se invoca la primitiva **/

void crear_parametros(Parametros &parametros){
/*    parametros.clave="NULL";
    parametros.valor="NULL";
    */
      parametros.claveA=parametros.valor;
       parametros.claveIM=parametros.valor;
       parametros.claveIP=parametros.valor;
       parametros.claveP=parametros.valor;
       parametros.clavePOSXE=parametros.valor;
       parametros.clavePOSYE=parametros.valor;
       parametros.claveS=parametros.valor;
       parametros.claveVB=parametros.valor;
       parametros.claveVM=parametros.valor;
}

/** pre: la instancia Parametros debe haberse creado y no debe estar destruida
post: destruye la instancia de Parametros y ya no podrá reutilizarse
Parametros: instancia sobre la que se invoca la primitiva **/

void destruir_parametros(Parametros &parametros){}

/** pre: la instancia Parametros debe haber sido creada y no debe estar destruida
post: el atributo clave queda seteado en Parametros
Parametros: instancia sobre la que se invoca la primitiva
clave: valor a asignar en Parametros **/

void setClaveS(Parametros &parametros, string clav){
    parametros.claveS=clav;
}

void setClaveP(Parametros &parametros, string clav){
parametros.claveP=clav;
}
void setClaveA(Parametros &parametros, string clav){
parametros.claveA=clav;
}

void setClavePOSXE(Parametros &parametros, string clav){
parametros.clavePOSXE=clav;
}

void setClavePOSYE(Parametros &parametros, string clav){
parametros.clavePOSYE=clav;
}

void setClaveIM(Parametros &parametros, string clav){
parametros.claveIM=clav;
}

void setClaveVM(Parametros &parametros, string clav){
parametros.claveVM=clav;
}

void setClaveIB(Parametros &parametros, string clav){
parametros.claveIB=clav;
}
void setClaveVB(Parametros &parametros, string clav){
parametros.claveVB=clav;
}
void setClaveIP(Parametros &parametros, string clav){
parametros.claveIP=clav;
}

string getClaveS(Parametros &parametros){
    return parametros.claveS;
}
string getClaveP(Parametros &parametros){
    return parametros.claveP;
}
string getClaveA(Parametros &parametros){
    return parametros.claveA;
}

string getClavePOSXE(Parametros &parametros){
    return parametros.clavePOSXE;
}
string getClavePOSYE(Parametros &parametros){
    return parametros.clavePOSYE;
}
string getClaveIM(Parametros &parametros){
    return parametros.claveIM;
}
string getClaveVM(Parametros &parametros){
    return parametros.claveVM;
}
string getClaveIB(Parametros &parametros){
    return parametros.claveVB;
}
string getClaveVB(Parametros &parametros){
    return parametros.claveVB;
}
string getClaveIP(Parametros &parametros){
    return parametros.claveIP;
}


/** pre: la instancia Parametros debe haber sido creada y no debe estar destruida
post: el atributo valor queda seteado en Parametros
Parametros: instancia sobre la que se invoca la primitiva
clave: valor a asignar en el Parametro **/

void setValor(Parametros &parametros, string val){
    parametros.valor=val;
}

/** pre: la instancia Parametros debe habe haberse creado y no debe estar destruida
post: retorna el atributo valor de Parametros
Parametros: instancia sobre la que se invoca la primitiva **/

string getValor(Parametros &parametros){
    return parametros.valor;
}



