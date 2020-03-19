#include <iostream>
#include <vector>
#define CAPACITY 14

using namespace std;

struct object{
	int weight;
	int value;
	string name;
};

struct knapsack{
 	int capacity;
 	int value;
	vector<object> elements; // esto pueden ir leyendo (tema 6), pero pueden sustituirlo por un arrglo de un tamaño grande
};

void knapsackAlgorithm(object objects[], int n, int start, knapsack solution, knapsack &optimal){
	if(solution.value > optimal.value)
		optimal = solution;
    for(int k = start; k < n; k++){
		if(objects[k].weight <= solution.capacity){
			solution.value += objects[k].value;
			solution.capacity -= objects[k].weight;
			solution.elements.push_back(objects[k]);
			knapsackAlgorithm(objects, n, k, solution, optimal);
			solution.value -= objects[k].value;
			solution.capacity += objects[k].weight;
			solution.elements.pop_back();
		}
	}
}

int main(){
    int n = 4;
    object objects[4];
    knapsack solution, optimal;

    solution.capacity = CAPACITY;
    solution.value = 0;

    optimal.capacity = CAPACITY;
    optimal.value = 0;

    objects[0].weight = 2;
    objects[0].value = 3;
    objects[0].name = "Obj1";

    objects[1].weight = 3;
    objects[1].value = 5;
    objects[1].name = "Obj2";

    objects[2].weight = 4;
    objects[2].value = 6;
    objects[2].name = "Obj3";

    objects[3].weight = 5;
    objects[3].value = 10;
    objects[3].name = "Obj4";

    knapsackAlgorithm(objects, n, 0, solution, optimal);

    cout << "Valor total: " << optimal.value << endl;
    cout << "Elementos: " << endl;
    for (int i = 0; i < optimal.elements.size(); i++)
        cout << optimal.elements[i].name << " ";
    cout << endl;

    /* la salida sera
        Valor total: 26
        Elementos:
        Obj1, Obj1, Obj4, Obj4
    */
    return 0;
}
