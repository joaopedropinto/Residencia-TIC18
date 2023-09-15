#include <iostream>

using namespace std;

int main(void){

  int a, b;
  int maior;

  cout << "Informe dois números inteiros: " << endl;
  
  cin >> a;
  cin >> b;
  

  (a == b) ? cout << "Estes números são iguais" : 
  (a > b) ? (a % 2 == 0) ? cout << a << " é maior e par" : cout << a << " é maior e impar" : 
  (b % 2 == 0) ? cout << b << " é maior e par" : cout << b << " é maior e impar";



  return 0;
}