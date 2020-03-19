#include <iostream>
#include <fstream>
#include <string>
#include "list.hpp"

using namespace std;

int N;//cantidad maxima de personas a la vez
char c;//signo de + or _
int M;//CANTIDAD DE PERSONJAS LLAMANDO
int in=0;//cantidad de interaciones
char n[10],a[10];
char p1[3], p2[3];
bool llamada=false;

struct personas{
    string nombre;
    string apellido;
    int piso_origen=0;
    int piso_destino=0;
};
struct lift{
    int Maxper=0;
    int passenger=0;
    int pos=0;
};

//          casting de un string a int   =     stoi  
void tusa(int &p, string piso){
if(piso=="PB"){
    p=0;
}else if(piso=="1"){
    p=1;
}else if(piso=="2"){
    p=2;
}else if(piso=="3"){
    p=3;
}
}

//          igualación del objeto      
void cuco(personas &p){
    p.nombre=n;
    p.apellido=a;
    tusa(p.piso_origen,p1);
    tusa(p.piso_destino,p2);
}

//          Función para leer el archivo
void you (personas &p,lift &l, list<personas>::pos position, list<personas> &persons, queue<personas> &q, stack<personas> &s){
    FILE *archivo_entrada; //apertura de archivo
    archivo_entrada= fopen("Entrada.in", "r");
        if(archivo_entrada==NULL){
            cout<<"no se abrio el archivo "<<endl;
            exit(1);
        }
        fscanf(archivo_entrada, "%d", &N);//cantidad maxima de personas a la vez
        if(N<=0){
            cout<<"número negativo de maximas personas en el ascensor"<<endl;
            goto aqui;
        }
        l.Maxper=N;
        while(!feof(archivo_entrada) ){
            fscanf(archivo_entrada, "%c", &c);//caracter de + or _
            if(c ==43 ){// +
                fscanf(archivo_entrada, "%d", &M);//cantidad de personas llamando
                if(M<=0){
                    cout<<"número negativo de personas llamando"<<endl;
                    goto aqui;
                }
                for(int i=0; i<M; i++){
                    fscanf(archivo_entrada, "%s %s %s %s", n, a, p1, p2);
                    cuco(p);
                    q.enqueue(p);
                    if(p.piso_origen==0 and llamada==true){
                        q.enqueue(p);//queue
                    }else if(p.piso_origen==1 and llamada==true){
                        s.push(p);
                    }else if(M%2==0 and llamada==true ){
                        position=persons.first();
                        persons.insert(p,position); //al comienzo
                    }else if(M%2!=0 and llamada==true ){
                        position=persons.last();
                        persons.insert(p,position);//al final
                    }else if(p.piso_origen==3 and llamada==true){  
                        q.enqueue(p);//priority queue
                    }    
                }
            }
        if(c== 95){
        }
}

    aqui:fclose(archivo_entrada);//cierre de archivo
}

//          validar para saber si alguien entra del ascensor
void need(queue<personas> &q, lift &l, queue<personas> &inL){
    personas aux;
    if(!q.isEmpty()){
    if(l.passenger<N){
    aux = *(q.head());
    if(l.pos== aux.piso_origen){
        ++l.passenger;
        inL.enqueue(aux);
        q.dequeue();
        need(q,l,inL);
            }
        }
    }
}

//          Escritura en el archivo de salida   
void MiLocoDelePafuera(personas aux, int in){
    /*FILE *salida;
    salida=fopen("Salida.out","w");
    fprintf(salida,"%s %s en %d intervalos", aux.nombre.c_str(), aux.apellido.c_str(), in );
    fclose(salida);*/

    fstream fs;
    fs.open("Salida.out", ios::out | ios::app );
    fs <<aux.nombre<<" "<<aux.apellido<<" en "<<in<<" intervalos"<<endl;
    fs.close();

}

//          validar para saber si alguien sale del ascensor
void buy(queue<personas> &q, lift &l){
    personas aux;
    if(!q.isEmpty()){
    aux = *(q.head());    
    if(l.pos==aux.piso_destino){
        MiLocoDelePafuera(aux, in);
        q.dequeue();
        --l.passenger;
        buy(q,l);
        }
    }
}

//          imprimir los elementos de una cola
void ImprimirCola(queue<personas> &q){
    personas aux;
    if(! q.isEmpty()){
        aux= *(q.head());
        cout<<"cola: "<< aux.nombre<<endl;
        q.dequeue();
        ImprimirCola(q);
        q.enqueue(aux);
    }
}
//          moviemiento del ascensor
void eggs(bool &S, lift &l, int &i,queue<personas> &q, queue<personas> &inL){
    if(l.pos==3)
        S=false;
    if(l.pos==0)
        S=true;
    if(S==true)
        ++l.pos;
    else
        --l.pos;
    ++i;
}

int main(){
    personas p;                     //creación de las personas
    lift l;                         //creación del ascensor
    list<personas> persons;         //creación de la lista
    list<personas>::pos position;   //creación del node position
    queue<personas> q;              //creación de la cola
    queue<personas> inL;            //cración de la cola dentro del ascensor
    stack<personas> s;              //creación de la pila
    dipolo<personas> d;             //creación del dipolo
    //                              Declaraciones                                            

    bool subiendo=true;    
    you(p,l, position, persons, q,s);   
    personas aux;
    while(!q.isEmpty() or !inL.isEmpty()){
        need(q,l,inL);
        buy(inL,l);
        eggs(subiendo, l, in,q,inL);
    }
    return 0;
}

/* g++ -o ejecutable intento1.cpp
   ./ejecutable                    */