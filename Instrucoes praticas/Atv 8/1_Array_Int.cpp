#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    int vetor[100],repete[20] = {0}, maxRepete = 0;;
    srand(time(0));

    for(int i = 0; i < 100; i++){
        vetor[i] = 1 + rand() % 20;
        cout << vetor[i] << " ";
    }

    for (int i = 0; i < 100; i++) {
        repete[vetor[i] - 1]++;
    }


   
    cout << endl << endl << "Números que mais vezes aparecem: ";
    for (int i = 0; i < 20; i++) {
        if (repete[i] > maxRepete) {
            maxRepete = repete[i];
        }
    }

    for (int i = 0; i < 20; i++) {
        if (repete[i] == maxRepete) {
            cout << i + 1 << " ";
        }
    }
    
    cout << "aparecem " << maxRepete << " vezes." << endl;
    
    return 0;
}