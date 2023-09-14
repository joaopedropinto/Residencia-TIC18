#include <iostream>

using namespace std;

int main(void){
    
    int num;

    cout << "Informe um número inteiro: ";
    cin >> num;

    short int num2 = num;

    cout << "O valor fornecido foi " << num << ((num2 == num) ? " e este valor pertence ao intervalo dos short int" : " e este valor é maior que um short int") << endl;


    return 0;
}