#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Forma {
    
    public:
        
        double calcularArea();

};

class Retangulo : Forma {
    public:
        double x, y;

        double calcularArea(double _x, double _y){
            return _x * _y;
        }
        
};

class Circulo : Forma {
    public:
        double raio;

        double CalcularArea(double _raio){
            return M_PI * _raio * _raio;
        }
};

int main() {
    Retangulo r1;
    Circulo c1;
    double raio, area, x, y;
    
    cout << "Informe o raio do circulo: ";
    cin >> raio;
    area = c1.CalcularArea(raio);
    cout << "Area do circulo: " << area << endl;

    cout << "Informe os lados do retangulo: ";
    cin >> x >> y;
    area = r1.calcularArea(x, y);
    cout << "Area do retangulo: " << area << endl;
    
    return 0;
}