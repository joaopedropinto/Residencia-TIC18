#include <iostream>

using namespace std;

unsigned long calcFatorial(int n){

  unsigned long fat = 1;

  if(n < 0){

    cout << "Erro! Fatorial de número negativo não permitido!" << endl;
    return 0;
  }

  if(n == 0 || n == 1){

    return 1;
  }else{

    for(int i = 2; i <= n; ++i){
      fat *= i;
    }
    return fat;
  }

}

int main(void){
  int num1, num2, num3;
  unsigned long resultado1, resultado2, resultado3;

  cout << "Insira três números para calcular seus fatoriais: ";
  cin >> num1 >> num2 >> num3;

  resultado1 = calcFatorial(num1);
  cout << "O fatorial de " << num1 << " é: " << resultado1 << endl;

  resultado2 = calcFatorial(num2);
  cout << "O fatorial de " << num2 << " é: " << resultado2 << endl;

  resultado3 = calcFatorial(num3);
  cout << "O fatorial de " << num3 << " é: " << resultado3 << endl;

  return 0;
}