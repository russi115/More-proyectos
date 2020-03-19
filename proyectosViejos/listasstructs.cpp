#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <iostream>

using namespace std;


typedef struct dato nodo;

 

nodo* crear_lista(nodo* lista);
nodo* ingresar_dato(char* nombre, int boleta, nodo* lista);

 

void mostrar_lista(nodo* lista);
void mostrar_nodo(nodo* elemento);

void menu(void);

 

void borrar_lista(nodo* lista);

nodo* borrar_nodoxnombre(char nombre, nodo lista);

nodo* borrar_nodoxnota(int boleta, nodo* lista);

 

nodo* buscar_nodo(nodo* lista, char *caracter);

void ordenar_lista(nodo* lista);

 

 

 

struct dato

   {

   char nombre[80];

   int nota;

   struct dato *sig;

   };

 

nodo* crear_lista(nodo* lista)

   {

   return (lista = NULL);

   }

 

nodo* ingresar_dato(char* nombre, int boleta, nodo* lista)

   {

   nodo *nuevo_dato;

   nodo *auxiliar = NULL;

 

   nuevo_dato = (nodo*)malloc(sizeof(nodo));

 

   if(nuevo_dato != NULL)

       {

       strcpy((nuevo_dato->nombre), nombre);

       nuevo_dato->nota = boleta;

       nuevo_dato->sig = NULL;

 

       if(lista == NULL)

           lista = nuevo_dato;

       else

           {

           auxiliar = lista;

           while(auxiliar->sig != NULL)

               auxiliar = auxiliar->sig;

           auxiliar->sig = nuevo_dato;

           }

       }

   else

        cout<<"\n\nNo se pudo reservar memoria\n\n";

   return lista;

   }

 

void mostrar_lista(nodo* lista)

   {

   nodo *auxiliar;

   int contador = 0;

 

   if(lista == NULL)

       cout<<"\n\nLa lista esta vacia\n\n";

 

   auxiliar = lista;

   while(auxiliar != NULL)

       {

        cout<<"\n\nPersona"<<(contador+1);

        cout<<"\nNombre y Apellido: "<<auxiliar->nombre;

        cout<<"\n\nBoleta:      "<< auxiliar->nota;

       contador++;

 

       auxiliar = auxiliar->sig;

       }

  cout<<"\nFin de lista\n\n";

   }

 

void borrar_lista(nodo* lista)

   {

   nodo *borra;

 

   borra = lista;

   while(borra)

       {

       lista = lista->sig;

       free(borra);

       borra = lista;

       }

   }

 

void menu(void)

   {

 

    cout<<"\n\nLista_Practica_3             3CM7:\n\n";

    cout<<"1) Ingresar dato\n";

   cout<<"2) Mostrar lista\n";

  cout<<"3) Borrar lista\n";

   cout<<"4) Borrar por nombre\n";

    cout<<"5) Borrar por boleta\n";

    cout<<"6) Buscar en lista\n";

    cout<<"7) Ordenar lista\n";

   cout<<"0)SALIR\n\n";

 

 

   }

 

nodo* borrar_nodoxnombre(char nombre, nodo lista)

    {

   if(lista != NULL)

       {

       nodo *ptraux;

       nodo *ptranterior = NULL;

       int cont;

 

       ptraux = lista;

       while(ptraux != NULL && (strcmp(ptraux->nombre, nombre) != 0))

           {

           ptranterior = ptraux;

           ptraux = ptraux->sig;

           cont++;

           }

       if(cont == 1 && ptraux->sig == NULL)

           {

           free(ptraux);

           lista = NULL;

           }

       if(ptraux == NULL)

           cout<<"\n\nNo se encontro una persona con ese nombre\n\n";

       else if(ptranterior == NULL)

           {

           lista = lista->sig;

           free(ptraux);

           }

       else

           {

           ptranterior->sig = ptraux->sig;

           free(ptraux);

           }

       }

 

   return lista;

   }

 

nodo* borrar_nodoxnota(int boleta, nodo* lista)

       {

   if(lista != NULL)

       {

       nodo *ptraux;

       nodo *ptranterior = NULL;

       int cont = 0;

 

       ptraux = lista;

       while(ptraux != NULL && ptraux->nota != boleta)

           {

           ptranterior = ptraux;

           ptraux = ptraux->sig;

           cont++;

           }

       if(cont == 1 && ptraux->sig == NULL)

           {

           free(ptraux);

           lista = NULL;

           }

       if(ptraux == NULL)

           cout<<"\n\nNo se encontro una persona con ese numero de boleta\n\n";

       else if(ptranterior == NULL)

           {

           lista = lista->sig;

           free(ptraux);

           }

       else

           {

           ptranterior->sig = ptraux->sig;

           free(ptraux);

           }

       }

 

   return lista;

   }

 

nodo* buscar_nodo(nodo* lista, char *caracter)

   {

   nodo *aux;

   char noabuscar[20];

   char a[] = "a";

   char b[] = "b";

   int nabuscar;

   if(lista != NULL)

       {

       if(strcmp(caracter,a) == 0)

           {

           cout<<"\n\nIngrese el nombre a buscar: ";

           fflush(stdin);

           fgets(noabuscar, 20, stdin);

           aux = lista;

           while(aux != NULL)

               {

               if(strcmp(aux->nombre, noabuscar) == 0)

                   return aux;

               aux = aux->sig;

               }

           return aux;

           }

       else if(strcmp(caracter,b) == 0)

           {

           cout<<"\n\nIngrese la nota a buscar: ";

           fflush(stdin);

           cout<<nabuscar;

           aux = lista;

           while(aux != NULL)

               {

               if(aux->nota == nabuscar)

                   return aux;

               aux = aux->sig;

               }

           return aux;

           }

        else

           {

           cout<<"\n\nOpcion no valida\n\n";

           return 0;

           }

       }

   }

 

void mostrar_nodo(nodo* elemento)

   {

   nodo* nodoencontrado;

   nodoencontrado = elemento;

   if(nodoencontrado == NULL)

      cout<<"\n\nNo se obtuvieron resultados\n\n";

 

 

   else

       {

       cout<<"\n\nNodo encontrado:\n\n";

       cout<<"\nNompre y apellido:"<< nodoencontrado->nombre;

       cout<<"\nBoleta:  "<< nodoencontrado->nota;

 

       }

   }

/*    \n\n\n\n   */

 

void ordenar_lista(nodo* lista)

   {

   nodo *anterior;

   nodo *siguiente;

   nodo temp;

 

   anterior = lista;

 

   while(anterior->sig != NULL)

       {

       siguiente = anterior->sig;

 

       while(siguiente != NULL)

           {

           if(strcmp(anterior->nombre, siguiente->nombre) > 0)

               {

               strcpy(temp.nombre, siguiente->nombre);

               temp.nota = siguiente->nota;

               strcpy(siguiente->nombre, anterior->nombre);

               siguiente->nota = anterior->nota;

               strcpy(anterior->nombre, temp.nombre);

               anterior->nota = temp.nota;

               }

           siguiente = siguiente->sig;

           }

       anterior = anterior->sig;

       siguiente = anterior->sig;

       }

cout<<"\n\nLista ordenada\n\n";

 

 

   }

 

   int main(int argc, char** argv)

   {

   nodo *inicio;

   nodo *nodobuscado;

   char nom[20];

   char nomaborrar[20];

   int nborrar;

   int nota, i, cant, op;

   char s[2];

 

   inicio = crear_lista(inicio);

 

   menu();

   cin>>op;

   while(op != 0)

       {

       switch(op)

           {

           case 1: cout<<"\n\nQue cantidad de datos ingresara: ";

                   cin>>cant;

                   cout<<"\n\n";

 

                   cout<<"Ingreso de datos:\n\n";

                   for(i=0 ; i < cant ; i++)

                       {

                       cout<<"Nombre y apellido: ";

                       fflush(stdin);

                       fgets(nom, 80, stdin);

                      cout<<"\nBoleta:      ";

                       fflush(stdin);

                       cin>>nota;

                       cout<<"\n\n";

                       inicio = ingresar_dato(nom, nota, inicio);

                       }

                   break;

 

           case 2: mostrar_lista(inicio);

                   break;

 

           case 3: borrar_lista(inicio);

                   free(inicio);

                   cout<<"\n\nLista Borrada\n\n";

                   inicio = NULL;

                   break;

 

           case 4: cout<<"\n\nIngrese el nombre a borrar\n\n";

                   fflush(stdin);

                   fgets(nomaborrar, 80, stdin);

                   inicio = borrar_nodoxnombre(nomaborrar, inicio);

                   break;

 

           case 5: cout<<"\n\nIngrese la nota a borrar\n\n";

                   fflush(stdin);

                   cin>>nborrar;

                   inicio = borrar_nodoxnota(nborrar, inicio);

                   break;

 

           case 6: cout<<"\n\n('a') para buscar por nombre || ('b') para buscar por nota\n\n";

                   fflush(stdin);

                   fgets(s, 2, stdin);

                   nodobuscado = buscar_nodo(inicio, s);

                   mostrar_nodo(nodobuscado);

                   break;

 

           case 7: ordenar_lista(inicio);

                   break;

 

 

 

           default: cout<<"\n\n Este no es una opcion, intentelo nuevamente// \n\n";

           }

            getch();

           system("cls");

       menu();

       cin>>op;

       }

 

 

   return (EXIT_SUCCESS);

   }
