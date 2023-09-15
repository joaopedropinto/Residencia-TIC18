#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double raio, diametro, circunf, area;

    cout << "Digite o raio do círculo: ";
    cin >> raio;

    // Calculo do diâmetro do círculo
    diametro = 2 * raio;

    // Calculo da circunferência do círculo
    circunf = 2 * M_PI * raio;

    // Calculo da área do círculo
    area = M_PI * pow(raio, 2); 

    cout << "Diâmetro do círculo: " << diametro << endl;
    cout << "Circunferência do círculo: " << circunf << endl;
    cout << "Área do círculo: " << area << endl;

    return 0;
}
