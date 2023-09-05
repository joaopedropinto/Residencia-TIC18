#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main(void){

    string aux1;

    int num;

    cout << "Digite um número inteiro: " << endl;
    cin >> num;
    cout << num << endl;
    if (num){
        aux1 = to_string(num);

        for (int i = 0; i < aux1.length() / 2; i++){

            if (aux1[i] != aux1[aux1.length() - i - 1]){
                cout << "Não é palíndromo!" << endl;
                return 0;
            }
        }
        cout << "É palídromo!" << endl;

    }else{
        cout << "Não é um dígito!" << endl;
    }


    return 0;
}