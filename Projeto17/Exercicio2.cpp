#include <iostream>
#include <cmath>

using namespace std;

class Ponto {
private:
    double x, y;

public:
    // Construtor padrão: inicializa o ponto na origem
    Ponto() : x(0), y(0) {}

    // Construtor com parâmetros para inicializar as coordenadas x e y
    Ponto(double x, double y) : x(x), y(y) {}

    // Mehtodos setters para definir as coordenadas
    void setCoordenadas(double x, double y) {
        this->x = x;
        this->y = y;
    }

    // Mehtodos getters para obter as coordenadas
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    // Mehtodo para calcular a distancia do ponto ate a origem (0,0)
    double calcularDistancia() const {
        return sqrt(x*x + y*y);
    }
};

int main() {
    Ponto p1(3, 4);
    double distancia = p1.calcularDistancia();
    cout << "A distancia do ponto (3, 4) ate a origem eh aproximadamente " << distancia << "." << endl;

    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    distancia = p2.calcularDistancia();
    cout << "A distancia do ponto (1, 1) ate a origem eh aproximadamente " << distancia << "." << endl;

    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.calcularDistancia();
    double distancia_p4 = p4.calcularDistancia();
    cout << "A distancia do ponto (0, 3) ate a origem eh " << distancia_p3 << " e do ponto (4, 0) ate a origem eh " << distancia_p4 << "." << endl;

    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    for (int i = 0; i < 3; ++i) {
        distancia = pontos[i].calcularDistancia();
        cout << "distancia do ponto " << i + 1 << " ate a origem: " << distancia << endl;
    }

    Ponto p5;
    cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;

    return 0;
}
