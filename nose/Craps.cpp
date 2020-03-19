#include <iostream>
#include<time.h>

using namespace std;

int main(){

    srand(time(NULL));
    int num1=0, num2=0, num3=0,prev=0;
    int cv=0,ci=0,cd=0;
    string q;
    bool newgame=false, fin=false;

    cout<<"Bienvenido al juego CRAPS"<<endl<<"para lanzar los datos presione ENTER"<<endl;
    while(true){
    if(newgame==false)
    cout<<"por favor, lanzar los dados..."<<endl<<endl;

    system("pause");
    num1 = 1 + rand() % (7 - 1);
    //cout<<num1<<endl;
    num2 = 1 + rand() % (7 - 1);
    //cout<<num2<<endl;
    num3=num1+num2;

    cout<<num3<<" vuelva a lanzar los dados..."<<endl<<endl;
    if(newgame==false)
        prev=num3;

        if(num3==7 or num3==11 and newgame==false){
            cout<<" Ganaste por sacar "<<num3<<endl;
            ++cv;
            fin=true;
        }


    if(newgame==true and fin==false){
    if(prev==num3 and newgame==true){
        cout<<" Ganaste  por igualar tus primera puntuación"<<endl;
        ++cv;
        fin=true;
    }else if(num3 == 2 or num3== 3 or num3==12){
        cout<<" PERDISTE"<<endl;
        ++cd;
        fin=true;
    }else if(num3==7){
        cout<<" PERDISTE"<<endl;
        ++cd;
        fin=true;
    }
}
    if(fin==true){
    cout<<"Desea jugar otra vez? (S/N) "<<endl;
    cin>>q;
    if(q=="s" or q=="S" ){
        num3=0;
        fin=false;
        newgame=false;
    }else if(q=="N" or q=="n"){
        cout<<"Juegos jugados "<<ci<<endl<<"juegos ganados "<<cv<<endl<<"juegos perdidos "<<cd<<endl;
        return 0;
    }
}
if(fin==false){
newgame=true;
}
++ci;

}

    return 0;
}
