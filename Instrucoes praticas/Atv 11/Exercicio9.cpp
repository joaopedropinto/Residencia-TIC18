#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

float calc_serie(int n){
  float resultado = 0.0;

  for(int i = 1; i <= n; i++){
    resultado += static_cast<float> (i) / (n - i + 1);
  }
  return resultado;
}

int main()
{
  int n;
  float resultado;

  cout << "Insira o valor de n: ";
  cin >> n;

  resultado = calc_serie(n);
  
  cout << "O cálculo da série é: " << resultado << endl;
  return 0;
}