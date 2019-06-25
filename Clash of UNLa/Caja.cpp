#include "Caja.h"

void crearCaja(Caja & caja,int cantidadItem,int capacidadActual,int capacidadMaxima,string codItem){
    caja.cantidadItem=cantidadItem;
    caja.capacidadActual=capacidadActual;
    caja.capacidadMaxima=capacidadMaxima;
    caja.codItem=codItem;
}


string getCodItem (Caja &caja) {
    return caja.codItem;
    }
int getCapacidadMaxima(Caja &caja) {
    return caja.capacidadMaxima;
}
int getCapacidadActual(Caja &caja) {
    return caja.capacidadActual;
    }

int getCantidadItem(Caja &caja){
    return caja.cantidadItem;
    }
void setCantidadItem(Caja &caja, int cantidadItem) {
    caja.cantidadItem = cantidadItem;
    }
void setCapacidadMaxima(Caja &caja, int capacidadMaxima) {
    caja.capacidadMaxima=capacidadMaxima;
    }
void setCapacidadActual(Caja &caja, int capacidadActual) {
    caja.capacidadActual=capacidadActual;
    }
void setCodItem(Caja &caja, string codItem) {
    caja.codItem=codItem;
    }

void eliminarCaja(Caja & caja){

}
