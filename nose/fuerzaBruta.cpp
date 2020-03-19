#include <iostream>
#include <string>
using namespace std;


string contrasena="";


void autencicacion(char arr[], string &pass, bool &sol){
    if(pass==contrasena){
        sol=true;
        cout<<pass<<endl;
    }else{
        for(int i=0; i<62 and !sol; i++){
            if(pass.length()<12){
                pass+=arr[i];
                cout<<pass<<endl;
                autencicacion(arr, pass, sol);
                pass.erase(pass.length()-1,1);
            }
        }
    }
}





int main(){
    string pass="";
    bool sol=false;
    char arr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z','1','2','3','4','5','6','7','8','9','0'};
    contrasena="clave";
    autencicacion(arr,pass,sol);
    return 0;
}