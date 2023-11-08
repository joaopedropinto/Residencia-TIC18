#include <iostream>

using namespace std;

int main() {

    int num, aux = 0;

    cout << "Informe um número inteiro: " ;
    cin >> num;

    for(int i = 1; i < num; i++){
        if(num % i == 0){
            aux += i;
        }
    }
    if (aux == num){
        cout << num << " é um número perfeito!" << endl;
    }else{
        cout << num << " não é um número perfeito" << endl;
    }

    return 0;
}
