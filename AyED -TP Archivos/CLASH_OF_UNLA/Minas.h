#ifndef MINAS_H
#define MINAS_H


#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int posX;
    int posY;
    int codItem;
    int ip;
    int seq1;
    int seq2;
    int seq3;
    int seq4;
    int seq5;
}Minas;

void crear_Minas(Minas &minas);
void destruir_Minas(Minas &minas);


void setPosX(Minas &minas, int pX);
int getPosX(Minas &minas);

void setPosY(Minas &minas, int pY);
int getPosY(Minas &minas);

void setCodItem(Minas &minas, int codI);
int getCodItem(Minas &minas);

void setIp(Minas &minas, int i);
int getIp(Minas &minas);

void setSeq1(Minas &minas, int s1);
int getSeq1(Minas &minas);

void setSeq2(Minas &minas, int s2);
int getSeq2(Minas &minas);

void setSeq3(Minas &minas, int s3);
int getSeq3(Minas &minas);

void setSeq4(Minas &minas, int s4);
int getSeq4(Minas &minas);

void setSeq5(Minas &minas, int s5);
int getSeq5(Minas &minas);
#endif // COMANDA_H





