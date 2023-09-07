#include <iostream>
#include <cmath>
using namespace std;

int main(){

  int num, aux, digito, soma = 0, n = 0;

  cout << "Informe um número inteiro:";
  cin >> num;

  aux = num;

  // Calculando a quantidade de dígitos no número
  while (aux != 0)
  {
    aux /= 10;
    n++;
  }

  aux = num;
  // Calculando a soma de cada dígito elevado a potencia
  while (aux != 0){
    digito = aux % 10;
    soma += pow(digito, n);
    aux /= 10;
  }

  if (soma == num){
    cout << num << " é um número Armstrong" << endl;
  }else{
    cout << num << " não é um número Armstrong" << endl;
  }

  return 0;
}