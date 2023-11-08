#include <iostream>
#include <string>

using namespace std;

int main (void){

    float A, B, soma, subtra, multi, divi;
    cout << "Digite o primeiro número: " ;
    cin >> A;
    cout << "Digite o segundo número: " ;
    cin >> B;

    soma = A + B;
    subtra = A - B;
    multi = A * B;
    divi = A / B;

    cout << "Soma: " << soma << endl;
    cout << "Subtração: " << subtra << endl;
    cout << "Multiplicação: " << multi << endl;
    cout << "Divisão: " << divi << endl;

    cout << endl;

    return 0;
}