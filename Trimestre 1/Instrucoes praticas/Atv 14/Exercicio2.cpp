#include <iostream>

using namespace std;

double converteCelcFahr(double tempCelc){
  return (tempCelc * 9.0 / 5.0) + 32.0;
}
int main(void){
  double tempCelc, tempFahr;

  cout << "Insira a temperatura em Celcius para que seja convertida para Fahrenheit: ";
  cin >> tempCelc;
  tempFahr = converteCelcFahr(tempCelc);
  cout << tempCelc << "º Celcius é igual a " << tempFahr << "º Fahrenheit!" << endl;
  return 0;
}