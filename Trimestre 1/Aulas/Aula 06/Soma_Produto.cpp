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
}