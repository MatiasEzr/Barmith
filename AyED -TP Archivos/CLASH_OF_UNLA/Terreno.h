#ifndef TERRENO_H
#define TERRENO_H

#include <stdlib.h>
#include <stdio.h>
#include "string.h"

using namespace std;
typedef struct{
    int posX;
    int posY;
//    string locomotora;
}Terreno;

void constructor(Terreno &terreno);
void destructor(Terreno &terreno);

void set_posX(Terreno &terreno, int posX);
int get_posX(Terreno &terreno);

void set_posY(Terreno &terreno, int posY);
int get_posY(Terreno &terreno);

//------------------------------------------------------
/*void set_locomotora(Terreno &terreno, string locomotora);
string get_locomotora(Terreno &terreno);
*/



#endif


