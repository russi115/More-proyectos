#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

void Write_with_fstream(){
	
	ofstream file;
	string frase;
	char rpt;
	int number;
	
	file.open("Salida.txt",ios::out); //Creamos el archivo
	
	if(file.fail()){ cout<<"Error en la creacion del archivo."; exit(1);} //Si a ocurrido algun error finaliza el programa

	do{ //esto es variable, solo lo puse para poder agregar los elementos que me diera la gana
	
		fflush(stdin);//vacia el buffer para volver a escribir en la misma variable frase
		cout<<"Digite una frase: ";
		getline(cin,frase); //Recuerda que esto sirve para que no haya problemas con las separaciones ni nada en las frases, y ademas en ilimitada la cantidad de caracteres
		cout<<"Digite un numero: ";
		cin>>number;
		file<<frase<<" "<<number<<endl;
		
		cout<<"\nDesea agregar otra frase(S/N): ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's')); //si te fijas S||s se refiere a "si" y es para ver si quieres agregar mas elementos
	
	file.close(); //Cerramos el archivo
}

int main(){
	
	Write_with_fstream();
	system("pause");
	return 0;
	
} 


