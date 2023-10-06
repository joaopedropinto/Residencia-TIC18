#include <iostream>

using namespace std;

// Função para calcular o fatorial de um número inteiro
int calcularFatorial(int n) {
    int fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

int main() {
    int numero1 = 3;
    int numero2 = 4;
    int numero3 = 5;

    int fatorial1 = calcularFatorial(numero1);
    int fatorial2 = calcularFatorial(numero2);
    int fatorial3 = calcularFatorial(numero3);

    cout << "Fatorial de " << numero1 << ": " << fatorial1 << endl;
    cout << "Fatorial de " << numero2 << ": " << fatorial2 << endl;
    cout << "Fatorial de " << numero3 << ": " << fatorial3 << endl;

    return 0;
}
