#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;


struct  usuarios {
    public:
      // Datos del usuario
      string nombre;
      int CantidadDeVsos;
};


int main(){



int H=0, M=0, S=0, ms=0;
int Hr=3, Mr=60, Sr=60;

usuarios usuario1;
cout<<"Cual es tu nombre?"<<endl;
cin>>usuario1.nombre;
cout<<"Cuantos vasos de agua has tomado?"<<endl;
cin>>usuario1.CantidadDeVsos;



while(true){
    cout<<"usuario: "<<usuario1.nombre<<" "<<"vasos: "<<usuario1.CantidadDeVsos<<endl;
    cout<<"horas:"<<" "<<H<<" "<<"Minutos: "<<" "<<M<<" "<<"segundos: "<<" "<<S<<endl;

    ms++;
    if(ms==20){
        ms=0;
        Sr--;
        S++;
    }
    if(S==60){
        S=0;
        M++;
    }
    if (M==60) {
        M=0;
        H++;
    }

    if(Sr<=0){
        Mr--;
        Sr=60;
    }
    if(Mr<=0){
        Hr--;
        Mr=60;
    }
    if(Hr<=0){
        cout<<"DEBES DE IR AL BANO!!"<<endl;
        Hr=3;
        system("pause");
    }

    cout<<"Cantidad de tiempor antes de ir al bano: "<<Hr<<"horas "<<Mr<<"minutos "<<Sr<<"segundos "<<endl;
    system("cls");
}

return 0;
}
