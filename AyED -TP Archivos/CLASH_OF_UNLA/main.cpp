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
#include "Comanda.h"
#include "Minas.h"
#include "Terreno.h"

#include "ListaComanda.h"
#include "ListaMinas.h"

void leerArchivoParametros(Parametros &parametros);

void imprimirComandas(Lista_Comanda& comandas);
void LeerArchivoComanda(Lista_Comanda &listarf, Comanda &comandas);
//void LeerArchivoComanda(Lista_Comanda &listarf);
//string crearTerreno(Parametros &p);

void imprimirMinas(Lista_Minas& minas);
void LeerArchivoMinas(Lista_Minas& listaminas, Minas &minas);

void llenarTodo(Lista_Comanda& comandas);

void crearT(Terreno &t);
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Parametros param;
    crear_parametros(param);

    Comanda com;
    constructor(com);
    Minas m;
    crear_Minas(m);

    Lista_Comanda lcomanda;
    crearLista_Comanda(lcomanda);

    Lista_Minas lminas;
    crearLista_Minas(lminas);


    setlocale(LC_CTYPE,"Spanish");

    leerArchivoParametros(param);
   // cout<<"Los Parametros se han cargado automaticamente\n\n";

//    cout<<"clave: "<<getClave(param)<<endl;
//    cout<<"valor: "<<getValor(param)<<endl;

 //   crearTerreno(param);
LeerArchivoComanda(lcomanda,com);
imprimirComandas(lcomanda);

LeerArchivoMinas(lminas,m);
imprimirMinas(lminas);

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
/*
string crearTerreno(Parametros p){
    string salida="";
   // int posx= (int)getClavePOSXE(p);
   // int posy= (int)getClavePOSYE(p);
    for (int i=1; i<10;i++){
        for (int j=1; i<10;j++){
            salida=i+" "+j;
        }
    }
    return salida;
}
*/
///Es necesaria para poder pasarle un int al archivo
std::string to_string(int i){
    std::stringstream ss;
    ss << i;
    return ss.str();
}

CodItem comparar(char *palabra){

    CodItem posAux;
//    enum CodItem{oro,plata,bronce,platino,roca,carbon,NADA};
    if (strcmp(palabra,"oro")==0){
        posAux=oro;
    }
    else if (strcmp(palabra,"plata")==0){
        posAux=plata;
    }
    else if (strcmp(palabra,"bronce")==0){
        posAux=bronce;
    }
    else if (strcmp(palabra,"platino")==0){
        posAux=platino;
    }
     else if (strcmp(palabra,"roca")==0){
        posAux=roca;
    }
     else if (strcmp(palabra,"carbon")==0){
        posAux=carbon;
    }
    return posAux;
}

/*
void LeerArchivoComanda(Lista_Comanda &listarf, Comanda &comandas){
    ifstream entrada("Comanda.txt");
    string strCod,strCantidad;

    CodItem cod=NADA;
    int cantidad=0;
    string cadena;
    char* cade = (char*) malloc(sizeof(char));
    while(!entrada.eof()){
          getline(entrada,cadena,'\n');
          if(cadena != ""){
          stringstream cadena2(cadena);

            getline(cadena2,strCod,';');
          cod=comparar(cade);
          set_codItem(comandas,cod);

          getline(cadena2,strCantidad, ';');
           cantidad=atoi(strCantidad.c_str());
          set_cantidad(comandas,cantidad);

          adicionarFinal_Comanda(listarf,comandas);

          cadena2.clear();
          }
    }
    entrada.close();
    fflush(stdin);
}
*/
void LeerArchivoComanda(Lista_Comanda &listarf, Comanda &comandas){
    int idaux=0,idclubaux=0;
    CodItem posaux=NADA;
    long valoraux=0;
    const string fJugadores= "Comanda.txt";
    //para leer lineas del fichero
    ifstream fichero;
    fichero.open(fJugadores.c_str());

//    Jugador jugador; -->comandas
    constructor(comandas);

            char* cadena = (char*) malloc(sizeof(char));
            while (!fichero.eof()){
            //getline para tener en cuenta tambien los espacios
            //actuan como delimitadores, toma lo que esta entre el = y el espacio


            fichero.getline(cadena,50, ';');
            posaux=comparar(cadena);
            set_codItem(comandas,posaux);

            fichero.getline(cadena,50, '\n');
            idaux = atof(cadena);
            set_cantidad(comandas,idaux);
/*
 getline(cadena2,strCantidad, ';');
           cantidad=atoi(strCantidad.c_str());
          set_cantidad(comandas,cantidad);
  */
         adicionarFinal_Comanda(listarf,comandas);
         destructor(comandas);

        }

    fichero.close();
    cout<<  "Fichero comanda cargado"<< endl;
    }

void imprimirComandas(Lista_Comanda& comandas){
    PtrNodoLista_Comanda cursor = primero_Comanda(comandas);
    Comanda comanda;

    constructor(comanda);

    while (cursor!=NULL){
            obtenerDato_Comanda(comandas,comanda,cursor);
            cout<<"Cod "<<get_codItem(comanda)<<" cantidad "<<get_cantidad(comanda)<<endl;
            cursor=siguiente_Comanda(comandas,cursor);
    }
    cout<<endl;
}

void LeerArchivoMinas(Lista_Minas& listaminas, Minas &minas){
    ifstream entrada("Minas.txt");


    string strposx,strposy,strcoditem,strip,strseq1,strseq2,strseq3,strseq4,strseq5;
   int posX,posY,codItem,ip,seq1,seq2,seq3,seq4,seq5;
   string cadena;
    while(!entrada.eof()){
          getline(entrada,cadena,'\n');
          if(cadena != ""){
          stringstream cadena2(cadena);

          getline(cadena2,strposx,';');
          posX=atoi(strposx.c_str());
          setPosX(minas,posX);

           getline(cadena2,strposy,';');
          posY=atoi(strposx.c_str());
          setPosY(minas,posY);

           getline(cadena2,strcoditem,';');
          codItem=atoi(strcoditem.c_str());
          setPosX(minas,codItem);

          getline(cadena2,strip,';');
          ip=atoi(strip.c_str());
          setIp(minas,ip);

          getline(cadena2,strseq1,';');
          seq1=atoi(strseq1.c_str());
          setSeq1(minas,seq1);

          getline(cadena2,strseq2,';');
          seq2=atoi(strseq2.c_str());
          setSeq2(minas,seq2);

          getline(cadena2,strseq3,';');
          seq3=atoi(strseq3.c_str());
          setSeq3(minas,seq3);

          getline(cadena2,strseq4,';');
          seq4=atoi(strseq4.c_str());
          setSeq4(minas,seq4);

          getline(cadena2,strseq5,';');
          seq5=atoi(strseq5.c_str());
          setSeq5(minas,seq5);



          adicionarFinal_Minas(listaminas,minas);

          cadena2.clear();
          }
    }
    entrada.close();
    fflush(stdin);
}

void imprimirMinas(Lista_Minas& minas){
    PtrNodoLista_Minas cursor = primero_Minas(minas);
    Minas m;

    crear_Minas(m);

    while (cursor!=NULL){
            obtenerDato_Minas(minas,m,cursor);
            cout<<getPosX(m)<<" "<<getPosY(m)<<" "<<getCodItem(m)<<" "<<getIp(m)<<" "<<getSeq1(m)<<" "<<getSeq2(m)<<" "<<getSeq3(m)<<" "<<getSeq4(m)<<" "<<getSeq5(m) <<endl;

            cursor=siguiente_Minas(minas,cursor);
    }
    cout<<endl;
}

void llenarTodo(Lista_Comanda& comandas){
    imprimirComandas(comandas);
}


/*
void crearT(Terreno &t){
    int creart;
    for(t.posX=0; t.posX<=3;t.posX++){
        for(t.posY=0; t.posY<=3;t.posY++){
        cout<<t.posX<<" "<<t.posY;
        }
    }
}
*/
