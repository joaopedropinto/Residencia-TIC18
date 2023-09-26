#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void maxmin(int vetor[], int n, int &maximo, int &minimo){
  maximo = vetor[0];
  minimo = vetor[0];

  for(int i = 1; i < n; i++){
    if (vetor[i] > maximo){
      maximo = vetor[i];
    }
    if(vetor[i] < minimo){
      minimo = vetor[i];
    }
  }
}

int main(){

  int vetor[] = {1,2,3,4,5,10,27,87,12,11,0,31,14,11};
  int n = sizeof(vetor) / sizeof(vetor[2]);
  int maximo, minimo;
  
  maxmin(vetor, n, maximo, minimo);

  cout << "Máximo: " << maximo << endl;
  cout << "Mínimo: " << minimo << endl;

  return 0;
}