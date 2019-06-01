#include "Parametros.h"
#include <iostream>
#include <string>
#include "string.h"

using namespace std;



/** Definicion de Primitivas **/

/** pre: la instancia Parametros no debe haberse creado ni estar destruida
post: Parametros creado y listo para ser usado
Parametros: instancia sobre la que se invoca la primitiva **/

void crear_parametros(Parametros &parametros){
/*    parametros.clave="NULL";
    parametros.valor="NULL";
    */
      strcpy(parametros.claveA,parametros.valor);
        strcpy(parametros.claveIM,parametros.valor);
       strcpy(parametros.claveIP,parametros.valor);
       strcpy(parametros.claveP,parametros.valor);
       strcpy(parametros.clavePOSXE,parametros.valor);
       strcpy(parametros.clavePOSYE,parametros.valor);
       strcpy(parametros.claveS,parametros.valor);
       strcpy(parametros.claveVB,parametros.valor);
       strcpy(parametros.claveVM,parametros.valor);
}

/** pre: la instancia Parametros debe haberse creado y no debe estar destruida
post: destruye la instancia de Parametros y ya no podrá reutilizarse
Parametros: instancia sobre la que se invoca la primitiva **/

void destruir_parametros(Parametros &parametros){}

/** pre: la instancia Parametros debe haber sido creada y no debe estar destruida
post: el atributo clave queda seteado en Parametros
Parametros: instancia sobre la que se invoca la primitiva
clave: valor a asignar en Parametros **/

void setClaveS(Parametros &parametros, char* clav){
    strcpy(parametros.claveS,clav);
}

void setClaveP(Parametros &parametros, char* clav){
strcpy(parametros.claveP,clav);
}
void setClaveA(Parametros &parametros, char* clav){
strcpy(parametros.claveA,clav);
}

void setClavePOSXE(Parametros &parametros, char* clav){
strcpy(parametros.clavePOSXE,clav);
}

void setClavePOSYE(Parametros &parametros, char* clav){
strcpy(parametros.clavePOSYE,clav);
}

void setClaveIM(Parametros &parametros, char* clav){
strcpy(parametros.claveIM,clav);
}

void setClaveVM(Parametros &parametros, char* clav){
strcpy(parametros.claveVM,clav);
}

void setClaveIB(Parametros &parametros, char* clav){
strcpy(parametros.claveIB,clav);
}
void setClaveVB(Parametros &parametros, char* clav){
strcpy(parametros.claveVB,clav);
}
void setClaveIP(Parametros &parametros, char* clav){
strcpy(parametros.claveIP,clav);
}

char* getClaveS(Parametros &parametros){
    return parametros.claveS;
}
char* getClaveP(Parametros &parametros){
    return parametros.claveP;
}
char* getClaveA(Parametros &parametros){
    return parametros.claveA;
}

char* getClavePOSXE(Parametros &parametros){
    return parametros.clavePOSXE;
}
char* getClavePOSYE(Parametros &parametros){
    return parametros.clavePOSYE;
}
char* getClaveIM(Parametros &parametros){
    return parametros.claveIM;
}
char* getClaveVM(Parametros &parametros){
    return parametros.claveVM;
}
char* getClaveIB(Parametros &parametros){
    return parametros.claveVB;
}
char* getClaveVB(Parametros &parametros){
    return parametros.claveVB;
}
char* getClaveIP(Parametros &parametros){
    return parametros.claveIP;
}


/** pre: la instancia Parametros debe haber sido creada y no debe estar destruida
post: el atributo valor queda seteado en Parametros
Parametros: instancia sobre la que se invoca la primitiva
clave: valor a asignar en el Parametro **/

void setValor(Parametros &parametros, char* val){
    strcpy(parametros.valor,val);
}

/** pre: la instancia Parametros debe habe haberse creado y no debe estar destruida
post: retorna el atributo valor de Parametros
Parametros: instancia sobre la que se invoca la primitiva **/

char* getValor(Parametros &parametros){
    return parametros.valor;
}



