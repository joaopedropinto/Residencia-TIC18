#include <iostream>
#include <cmath>

using namespace std;

class Ponto{

  private:
    double x, y;

  public:
    Ponto(): 
      x(0), y(0) {

      }

    Ponto(double x, double y):
      x(x), y(y) {

      }

    void setx(double _x)
    {
      x = _x;
    }
    void sety(double _y)
    {
      y = _y;
    }

    double getx()
    {
      return x;
    }
    double gety()
    {
      return y;
    }
    double calcularDistancia(){
      return sqrt(x * x + y * y);
    }
    void setCoordenadas(double _x, double _y){
      x = _x;
      y = _y;
    }
};

int main(void)
{ 
  double distancia;

  Ponto p1(3.0, 4.0);
  distancia = p1.calcularDistancia();
  cout << "A distância do ponto (" << p1.getx() << ", " << p1.gety() << ") até a origem é: " << distancia << endl;
  
  Ponto p2(-2, 7);
  p2.setx(1);
  p2.sety(1);
  distancia = p2.calcularDistancia();
  cout << "A distância do ponto (" << p2.getx() << ", " << p2.gety() << ") até a origem é: " 
  << distancia << endl;

  Ponto p3(0, 3);
  Ponto p4(4, 0);
  double distancia_p3 = p3.calcularDistancia();
  double distancia_p4 = p4.calcularDistancia();

  cout << "A distância do ponto (" << p3.getx() << ", " << p3.gety() << ") até a origem é: " 
      << distancia_p3 << " e do ponto (" << p4.getx() << ", " << p4.gety() << ") até a origem é: " 
      << distancia_p4 << endl;

  Ponto pontos[3];
  pontos[0].setCoordenadas(2, 2);
  pontos[1].setCoordenadas(-1, 5);
  pontos[2].setCoordenadas(0, 0);
  
  for (int i = 0; i < 3; ++i) {
    double distancia = pontos[i].calcularDistancia();
    cout << "Distância do ponto " << i + 1 << " até a origem: " << distancia << endl;
  }

  Ponto p5;
  cout << "Coordenadas do ponto p5: (" << p5.getx() << ", " << p5.gety() << ")" << endl;
  p5.setCoordenadas(8, -3);
  cout << "Novas coordenadas do ponto p5: (" << p5.getx() << ", " << p5.gety() << ")" << endl;
  return 0;
}