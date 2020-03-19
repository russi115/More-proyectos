#include <iostream>
#include <string>
#include "list.hpp"
using namespace std;

struct prueba
{
    int c;
    char l;
};


int main(){

    list<int> l;
    list<int>::pos pos=l.last();
    l.insert(10,pos);
    int x=*(l.first());
    cout<<x<<endl;


    return 0;
}
