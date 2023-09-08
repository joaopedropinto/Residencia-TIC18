#include <iostream>
#include <vector>
using namespace std;

int main(){

    int vetor[100];

    for(int i = 0; i < 100; i++){
        vetor[i] = 1 + rand() % 20;
    }
}