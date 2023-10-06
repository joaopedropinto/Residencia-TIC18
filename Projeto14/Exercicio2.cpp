#include <iostream>

using namespace std;

// Função para converter temperatura de Celsius para Fahrenheit
double converterCelsiusParaFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Função para entrada/saída
void entradaSaida() {
    double temperaturaCelsius;
    
    cout << "Digite a temperatura em Celsius: ";
    cin >> temperaturaCelsius;
    
    double temperaturaFahrenheit = converterCelsiusParaFahrenheit(temperaturaCelsius);
    
    cout << "A temperatura em Fahrenheit é: " << temperaturaFahrenheit << " °F" << endl;
}

int main() {
    entradaSaida();

    return 0;
}
