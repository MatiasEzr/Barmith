#include "Minas.h"


#include <stdlib.h>
#include <stdio.h>

using namespace std;

void crear_Minas(Minas &minas){
    minas.posX=0;
    minas.posY=0;
    minas.codItem=0;
    minas.ip=0;
    minas.seq1=0;
    minas.seq2=0;
    minas.seq3=0;
    minas.seq4=0;
    minas.seq5=0;
}
void destruir_Minas(Minas &minas){}


void setPosX(Minas &minas, int pX){
    minas.posX=pX;
}
int getPosX(Minas &minas){
    return minas.posX;
}

void setPosY(Minas &minas, int pY){
    minas.posY=pY;
}

int getPosY(Minas &minas){
    return minas.posY;
}

void setCodItem(Minas &minas, int codI){
    minas.codItem=codI;
}
int getCodItem(Minas &minas){
    return minas.codItem;
}

void setIp(Minas &minas, int i){
    minas.ip=i;
}

int getIp(Minas &minas){
    return minas.ip;
}

void setSeq1(Minas &minas, int s1){
    minas.seq1=s1;
}

int getSeq1(Minas &minas){
    return minas.seq1;
}
void setSeq2(Minas &minas, int s2){
    minas.seq2=s2;
}

int getSeq2(Minas &minas){
    return minas.seq2;
}

void setSeq3(Minas &minas, int s3){
    minas.seq3=s3;
}

int getSeq3(Minas &minas){
    return minas.seq3;
}

void setSeq4(Minas &minas, int s4){
    minas.seq4=s4;
}

int getSeq4(Minas &minas){
    return minas.seq4;
}

void setSeq5(Minas &minas, int s5){
    minas.seq5=s5;
}

int getSeq5(Minas &minas){
    return minas.seq5;
}
