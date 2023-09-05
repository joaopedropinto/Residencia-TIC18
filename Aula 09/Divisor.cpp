#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    int a;

    cout << "Digite um número inteiro" << endl;

    cin >> a;
    cout << "Os divisores de " << a << " são:";

    for (int i = 1; i <= a; i++){
        if (a % i == 0){
            cout << " " << i;
        }
    }
    cout << endl;
    return 0;
}