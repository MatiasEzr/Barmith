#include "Terreno.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;


void constructor(Terreno &terreno){
    terreno.posX=0;
    terreno.posY=0;
//    terreno.locomotora="";
}
void destructor(Terreno &terreno){}

void set_posX(Terreno &terreno, int posX){
    terreno.posX=posX;
}
int get_posX(Terreno &terreno){
    return terreno.posX;
}

void set_posY(Terreno &terreno, int posY){
    terreno.posY=posY;
}
int get_posY(Terreno &terreno){
    return terreno.posY;
}




//------------------------------------------------------
/*void set_locomotora(Terreno &terreno, string locomotora){
    terreno.locomotora=locomotora;
}
string get_locomotora(Terreno &terreno){
    return terreno.locomotora;
}
*/

