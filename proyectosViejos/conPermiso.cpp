#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){
srand(time(NULL));
int num=0;
string a;


while(true){
cout<<"¿Me puedo levantar?"<<endl;
system("pause");
num = 1 + rand() % (11 - 1);
cout<<num<<"     ";//<<endl;
if(num <= 2 and num >= 0){
cout<<"Si puedes"<<endl;
}else{
    cout<<"No puedes"<<endl;
}
cout<<"¿De nuevo?"<<endl<<"S: si    N: no"<<endl;
cin>>a;
if(a== "S" or a== "s"){
    cout<<"Adelante..."<<endl;
}
if(a == "N" or a == "n"){
cout<<"programa terminado"<<endl;
system("pause");
return 0;
}
if(a != "S" and a != "s" and a!="N" and a!="n"){
    cout<<"pon una letra valida, mamon"<<endl;
}
}

return 0;
}
