#include "Item.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;

void constructor(Item &items){
    items.items=NADA;
}

void destructor(Item &item){}

void set_items(Item &item,  Items recursos){
    item.items=recursos;
}
int get_items(Item &item){
    return item.items;
}



