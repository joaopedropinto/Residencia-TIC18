#include <iostream>

using namespace std;

int main(void){

  double x, y, z;

  cout << "Informe dois números de ponto flutuante: " << endl;

  cin >> x;
  cin >> y;

  // Soma de x e y
  z = x + y;
  cout << "Soma de x e y: " << z << endl;

  // Média de x e y
  z = (x + y) / 2.0;
  cout << "Média de x e y: " << z << endl;

  // Produto de x e y
  z = x * y;
  cout << "Produto de x e y: " << z << endl;

  // Maior valor entre x e y
  z = (x > y) ? x : y;
  cout << "Maior valor entre x e y: " << z << endl;

  // Menor valor entre x e y
  z = (x < y) ? x : y;
  cout << "Menor valor entre x e y: " << z << endl;

  return 0;
}