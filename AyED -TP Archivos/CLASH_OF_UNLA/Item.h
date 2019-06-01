#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <stdio.h>

enum Items{oro=1,plata=2,bronce=3,platino=4,roca=5,carbon=6,NADA};
typedef struct{
    Items items;
}Item;

void constructor(Item &items);
void destructor(Item &item);

void set_items(Item &item,  Items recursos);
int get_items(Item &item);





#endif

