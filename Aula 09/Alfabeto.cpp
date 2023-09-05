#include <iostream>

using namespace std;

int main() {
    int altura, char_lin = 1;
    
    cout << "Digite a altura do padrão: ";
    cin >> altura;

    char letra = 'A';

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < char_lin; j++) {
            cout << letra;
            if(letra == 'Z') {
                letra = 'a';
            } else if (letra == 'z') {
                letra = '0';
            } else if (letra == '9') {
                letra = 'A';
            } else {
                letra++;
            }
        }
        cout << endl;
        char_lin++;
    }

    return 0;
}