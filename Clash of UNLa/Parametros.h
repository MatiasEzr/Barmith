#ifndef PARAMETROS_H
#define PARAMETROS_H
#include <string>

using namespace std;

/**
    AXIOMAS:
    claveS > 0
    claveP > 0
    claveA > 0
    claveposXE >= 0
    claveposYE >= 0
    claveIM > 0
    claveVM > claveIM
    claveIB > 0
    claveVB > claveIB
    claveIP > 0
    valor > 0

*/

/** Definicion del tipo de datos **/
typedef struct{
    string claveS;
    string claveP;
    string claveA;
    string claveposXE;
    string claveposYE;
    string claveIM;
    string claveVM;
    string claveIB;
    string claveVB;
    string claveIP;
    string valor;
}Parametros;

/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/

/* pre: la instancia Parametros no debe haberse creado ni estar destruida.
post: Parametros creado y listo para ser usado.

Parametros: instancia sobre la que se invoca la primitiva .
*/

void crearParametros(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado y no debe estar destruida.
post: destruye la instancia de Parametros y ya no podrá reutilizarse.

Parametros: instancia sobre la que se invoca la primitiva.
*/
void destruirParametros(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea los segundos del intervalo.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveS(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea la cantidad Max del pedido del bandido.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveP(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea el area de ataque del bandido.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveA(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea la posicion X (fila) de la estacion.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClavePosXE(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea la posicion Y (cola) de la estacion.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClavePosYE(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea el intervalo de generacion de moneda.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveIM(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea el invervalo de vida de la moneda.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveVM(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea el intervalo maximo de generacion de bandidos.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveIB(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea el intervalo de vida del bandido.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveVB(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: setea el intervalo de produccion de las minas.

Parametros: instancia sobre la que se invoca la primitiva.
clav: dato a asignar.
*/
void setClaveIP(Parametros &parametros, string clav);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene los segundos del intervalo.

Parametros: instancia sobre la que se invoca la primitiva.
*/

string getClaveS(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene la cantidad Max que solicita el bandido.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClaveP(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene el area del ataque del bandido.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClaveA(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene la posicion X (Fila) de la estacion.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClavePosXE(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene la posicion Y (Columna) de la estacion.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClavePosYE(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene el intervalo de generacion de la moneda.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClaveIM(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene el intervalo de vida de la moneda.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClaveVM(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene el intervalo de generacion del bandido.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClaveIB(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene el intervalo de vida deñ bandido.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClaveVB(Parametros &parametros);
/*----------------------------------------------------------------------------*/
/* pre: la instancia Parametros debe haberse creado.
post: se obtiene el intervalo de produccion de las minas.

Parametros: instancia sobre la que se invoca la primitiva.
*/
string getClaveIP(Parametros &parametros);
/*----------------------------------------------------------------------------*/


//void setValor(Parametros &parametros, string val);


//string getValor(Parametros &parametros);


#endif // CONFIGURACION_H_INCLUDED
