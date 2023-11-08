#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

  double temperatura[250], tempMax = 0, tempMin = 0, somaTemp = 0, tempMedia = 0;
  srand(time(0));

  //Atribuindo valores aleatórios para as temperaturas
  for (int i = 0; i < 250; i++) {
        temperatura[i] = 10 + 30.0 * (rand() % 100) / 100.0;
    }
  tempMax = temperatura[0];
  tempMin = temperatura[0];
  //Procurando as temperaturas máximas e mínimas, além de fazer o cálculo da temperatura média
  for (int i = 1; i < 250; i++) {
        if (temperatura[i] > tempMax) {
            tempMax = temperatura[i];
        }
        if (temperatura[i] < tempMin) {
            tempMin = temperatura[i];
        }
        somaTemp += temperatura[i];
    }

  tempMedia = somaTemp / 250;

  //impressão das temperaturas atuais
  cout << "Temperatura máxima: " << tempMax << " graus" << endl;
  cout << "Temperatura mínima: " << tempMin << " graus" << endl;
  cout << "Temperatura média: " << tempMedia << " graus" << endl;

  //Atualizando as temperaturas
  for(int i = 0; i < 250; i++){
    if(temperatura[i] > tempMedia){
      temperatura[i] += 1.0;
    }else{
      temperatura[i] += 2.0;
    }
  }

  tempMedia = 0.0;
  somaTemp = 0.0;
  tempMax = temperatura[0];
  tempMin = temperatura[0];
   //Procurando as temperaturas máximas e mínimas, além de fazer o cálculo da temperatura média
  for (int i = 1; i < 250; i++) {
        if (temperatura[i] > tempMax) {
            tempMax = temperatura[i];
        }
        if (temperatura[i] < tempMin) {
            tempMin = temperatura[i];
        }
        somaTemp += temperatura[i];
    }

  tempMedia = somaTemp / 250;

  //impressão das temperaturas atualizadas
  cout << endl << "Atualizando..." << endl;
  cout << "Temperatura máxima: " << tempMax << " graus" << endl;
  cout << "Temperatura mínima: " << tempMin << " graus" << endl;
  cout << "Temperatura média: " << tempMedia << " graus" << endl;
  
  
  return 0;
}