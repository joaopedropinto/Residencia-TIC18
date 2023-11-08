#include <iostream>
using namespace std;

int main() {
    float x, y;

    cout << "Digite as coordenadas x e y: ";
    cin >> x;
    cin >> y;

    string quadrante;

    quadrante = (x > 0 && y > 0) ? "primeiro quadrante" :
                (x < 0 && y > 0) ? "segundo quadrante" :
                (x < 0 && y < 0) ? "terceiro quadrante" :
                (x > 0 && y < 0) ? "quarto quadrante" :
                (x == 0 && y != 0) ? "sobre o eixo x" :
                (x != 0 && y == 0) ? "sobre o eixo y" :
                "na origem";

    cout << "O ponto está no " << quadrante << "." << endl;

    return 0;
}
