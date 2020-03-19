#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;


    int x=0,y=0;
    int N=0;
    int f=0,c=0, w=0;
    int fi=0, C1=0, C2=0;
    int X=0, row=0, column=0;
    char **map;


void leer(){
    FILE *archivo_entrada; //apertura de archivo
    archivo_entrada= fopen("mAPA.TXT", "r");
        if(archivo_entrada==NULL){
            cout<<"no se abrio el archivo "<<endl;
            exit(1);
        }//validación del archivo
            fscanf(archivo_entrada, "%d", &N);
            if(N<=0){
                cout<<"No puede haber numero negativo de casos"<<endl;
                exit(1);
            }
            for(int B=0;B<N;B++){
                //cout<<"CASO "<<B+1<<endl;

            fscanf(archivo_entrada, "%d" "%d" "%d", &f, &c, &w);//2da linea
            if(f<=0 or c<=0){
                cout<<"El mapa posee dimensiones inapropiadas"<<endl;
                goto aqui;
            }
            if(w<=0){
                cout<<"No puede haber un numero negativo de muros"<<endl;
                goto aqui;
            }
            //cout<<f<<" "<<c<<" "<<w<<endl;
            map= new char *[f];//creacion de la matriz dinamica
            for(int i=0;i<f;i++){
                map[i]= new char [c];
            }

            for(int i=0;i<f;i++){//rellenando la matriz
                for(int j=0; j<c;j++){
                    map[i][j]=46;
                }
            }

            for(int Noc=0; Noc<w; Noc++){

            fscanf(archivo_entrada, "%d" "%d" "%d", &fi, &C1, &C2);//wlineas
            if(fi<0 or fi> f-1){
                cout<<"las coordenadas del muro N "<<Noc+1<<" son invalidas"<<endl;
                goto aqui;
            }
            if(C1<0 or C1 >C2 or C2<0 or C2<C1 or C2>c-1){
                cout<<"las coordenadas del muro N "<<Noc+1<<" son invalidas"<<endl;
                goto aqui;
            }
            if(fi == f-1 and (C1==c-1 or C2==c-1 )){
                cout<<"Imposible escapar ya que hay un muro en la esquina superior derecha"<<endl;
                goto aqui;
            }

            //cout<<fi<<" "<<C1<<" "<<C2<<endl;


            //creacion de muros
                for(int j=C1;j<C2;j++){
                    if(map[fi][j]==35){
                        cout<<"Se intentó construir un muro encima de otro"<<endl;
                        goto aqui;
                    }
                    map[fi][j]=35;
                }
        }


            fscanf(archivo_entrada, "%d", &X);//3era linea
            if(X<0 or X>4){
                cout<<"El número de fixPoints es menor que 0 o mayor que 4"<<endl;
                goto aqui;
            }
            //cout<<pr<<endl;
            for(int Noc=0; Noc<X;Noc++){
                fscanf(archivo_entrada, "%d" "%d", &row, &column);//x lineas
                if(row<0 or row>f-1 or column<0 or column>c-1){
                    cout<<"Las coordenadas del fixPoint N "<< Noc+1<<" son inválidas"<<endl;
                    goto aqui;
                }
                //cout<<row<<" "<<column<<endl;
                map[row][column]=88;
            }




            //imprimir();

            aqui:cout<<endl;//salto de linea si se encuentra algún error


}

                fclose(archivo_entrada);//cierre de archivo

}
struct poss{//se declara una struc para seguir la poscision
    int x=0;
    int y=0;
};
struct player{
    string nombre;
    int vidas=3;
    poss pos;

};
void imprimir(player p1){
    //system("cls");
    cout<<"tu nombre: "<<p1.nombre<<"  "<<"vidas: "<<p1.vidas<<endl<<endl;
    for(int i=0;i<f;i++){//impresion de matriz
        for(int j=0; j<c;j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }
}
char D;

void movimiento(player &p1){
    cin>>D;
    switch(D){
        case 119://arriba
        if(map[p1.pos.x-1][p1.pos.y]==35){
            p1.vidas-=1;
            cout<<"colision"<<endl;
        }else{
        map[p1.pos.x][p1.pos.y]=46;
        p1.pos.x-=1;
        map[p1.pos.x][p1.pos.y]=p1.nombre[0];
        cout<<"avanzas hacia arriba"<<endl;
    }
        break;
        case 115://abajo
        if(map[p1.pos.x+1][p1.pos.y]==35){
            p1.vidas-=1;
            cout<<"colision"<<endl;
        }else{
        map[p1.pos.x][p1.pos.y]=46;
        p1.pos.x+=1;
        map[p1.pos.x][p1.pos.y]=p1.nombre[0];
        cout<<"avanzas hacia abajo"<<endl;
    }
        break;
        case 100://derecha
        if(map[p1.pos.x][p1.pos.y+1]==35){
            p1.vidas-=1;
            cout<<"colision"<<endl;
        }else{
        map[p1.pos.x][p1.pos.y]=46;
        p1.pos.y+=1;
        map[p1.pos.x][p1.pos.y]=p1.nombre[0];
        cout<<"avanzas hacia la derecha"<<endl;
    }
        break;
        case 97:;//izquierda
        if(map[p1.pos.x][p1.pos.y-1]==35){
            p1.vidas-=1;
            cout<<"colision"<<endl;
        }else{
        map[p1.pos.x][p1.pos.y]=46;
        p1.pos.y-=1;
        map[p1.pos.x][p1.pos.y]=p1.nombre[0];
        cout<<"avanzas hacia la izquierda"<<endl;
}
        break;
    }
}

int main(){
    player p1;//creación del personaje
    cout<<"Nombre de tu personaje: "; cin>>p1.nombre; cout<<endl;
    poss pos;//creacion del objeto
    leer();
    map[p1.pos.x][p1.pos.y]=p1.nombre[0];
    imprimir(p1);

    while(true){
    movimiento(p1);
    imprimir(p1);
}

    return 0;
}
