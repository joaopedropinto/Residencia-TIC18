#include <iostream>

using namespace std;

int main() {
    int altura, linha = 1;

    cout << "Informe a altura do padrão: ";
    cin >> altura;

    //Padrão 1
    cout << endl << "Padrão 1" << endl;
    for (int i = 0; i < altura; i++){
        for (int j = 0; j < altura; j++){
            cout << "*";
        }
        cout << endl;
    }

    //Padrão 2
    cout << endl << "Padrão 2" << endl;

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < linha; j++){
            cout << "*";
        }
        cout << endl;
        linha++;
    }

    //Padrão 3
    cout << endl << "Padrão 3" << endl;

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < altura; j++){
            if(i == 0 || i == altura-1 || j == altura-1 || j == 0){
                cout << "*";
            }else{
                cout << " ";
            }     
        }
        cout << endl;
    }

    return 0;
}