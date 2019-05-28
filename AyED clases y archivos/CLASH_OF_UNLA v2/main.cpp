#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <strings.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctype.h>

#include "Parametros.h"

void leerArchivoParametros(Parametros &parametros);
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Parametros param;
    crear_parametros(param);

setlocale(LC_CTYPE,"Spanish");

    leerArchivoParametros(param);
   // cout<<"Los Parametros se han cargado automaticamente\n\n";

//    cout<<"clave: "<<getClave(param)<<endl;
//    cout<<"valor: "<<getValor(param)<<endl;


    return 0;
}

void leerArchivoParametros(Parametros &parametros){

    const string fParam= "Parametros.txt";
    //para leer lineas del fichero
    ifstream fichero;
    fichero.open(fParam.c_str());
    int i;
int j;
    if (!fichero){
        cout << "Error en el archivo 'Parametros.txt' "<<endl;
        ofstream archivo;

        archivo<< "Error en el archivo 'Parametros.txt' "<<endl;
        archivo.close();
    }
    else{
            char* cadena = (char*) malloc(sizeof(char));
            i=0;
            j=0;
            while (!fichero.eof()){
            fichero.getline(cadena,50, '=');
            fichero.getline(cadena,50, '\n');

            if( i==0 ){
                    setClaveS(parametros,cadena);
           }
           if( i==1 ){
                    setClaveP(parametros,cadena);
           }
           if( i==2 ){
                    setClaveA(parametros,cadena);
           }
            if( i==3 ){
                    setClavePOSXE(parametros,cadena);
           }
           if( i==4 ){
                    setClavePOSYE(parametros,cadena);
           }
            if( i==5 ){
                    setClaveIM(parametros,cadena);
           }
           if( i==6 ){
                    setClaveVM(parametros,cadena);
           }
           if( i==7 ){
                    setClaveIB(parametros,cadena);
           }
           if( i==8 ){
                    setClaveVB(parametros,cadena);
           }
           if( i==9 ){
                    setClaveIP(parametros,cadena);
           }

i++;
            }
  cout<<"S: "<<getClaveS(parametros)<<endl;
  cout<<"P: "<<getClaveP(parametros)<<endl;
  cout<<"A: "<<getClaveA(parametros)<<endl;
  cout<<"posXE: "<<getClavePOSXE(parametros)<<endl;
  cout<<"posYE: "<<getClavePOSYE(parametros)<<endl;
  cout<<"IM: "<<getClaveIM(parametros)<<endl;
  cout<<"VM: "<<getClaveVM(parametros)<<endl;
  cout<<"IB: "<<getClaveIB(parametros)<<endl;
  cout<<"VB: "<<getClaveVB(parametros)<<endl;
  cout<<"IP: "<<getClaveIP(parametros)<<endl;


//    cout<<"Clave: "<<getClave(parametros)<<endl;
    fichero.close();
    cout<<  "Fichero de Parametros.txt de cargado"<< endl;
    }
}
