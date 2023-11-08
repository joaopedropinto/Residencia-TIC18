#include <iostream>
#include <cmath>

using namespace std;

struct Ponto{
  double x, y;
};

double calcDist(const Ponto &p1, const Ponto &p2){

  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;

  return sqrt(dx * dx + dy * dy);
}

int main(void){
  Ponto p1, p2;
  double dist;

  cout << "Informe as coordenadas x e y do ponto 1: ";
  cin >> p1.x >> p1.y;

  cout << "Informe as coordenadas x e y do ponto 2: ";
  cin >> p2.x >> p2.y;

  dist = calcDist(p1, p2);

  cout << "A distância entre os pontos é: " << dist << endl;
  return 0;
}