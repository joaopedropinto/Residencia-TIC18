#include <iostream>

using namespace std;

int main(void){

    int a, b, c;

    cout << "Insira dois números inteiros" << endl;

    cin >> a; 
    cin >> b; 

    c = a + b;
    
    cout << "A soma em hexadecimal é: " << hex << c << endl;

    c = a * b;

    cout << "O produto em octal é: " << oct << c << endl;

    c = a - b;
    
    if (c < 0){
        c = - c;
    }

    cout << "O módulo da diferença em inteiro é: " << c << endl;
    
    if(b == 0){
        cout << "Divisão por zero!!!" << endl;
    }else{
        c = a / b;
        if( a % b == 0){
            cout << "A divisão é exata!" << endl;
        }else{
            cout << "A divisão não é exata!" << endl;
        }
        cout << "O valor da divisão em inteiro é: " << c << endl;
    }

    
    return 0;
}