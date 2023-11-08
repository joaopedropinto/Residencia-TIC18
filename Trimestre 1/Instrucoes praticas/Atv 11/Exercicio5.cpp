#include <iostream>
#include <algorithm>

using namespace std;

int insere_meio(int *vetor, int qtde, int elemento){

  int meio = qtde / 2;

  for(int i = qtde; i > meio; i--){
    vetor[i] = vetor[i - 1];
  }

  vetor[meio] = elemento;
  qtde++;

  return qtde;

}


int main()
{ 
  int qtde = 6, elemento;
  int vetor[qtde] = {1,2,3,4,5,6};

  cout << "Vetor antes de inserir o elemento:" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << vetor[i] << " ";
    }

  cout << endl << "Insira um elemento para ser inserido no meio do vetor: ";
  cin >> elemento;

  qtde = insere_meio(vetor, qtde, elemento);
  
  cout << "Vetor depois de inserir o elemento:" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << vetor[i] << " ";
    }
  return 0;
}