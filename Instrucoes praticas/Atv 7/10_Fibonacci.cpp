#include <iostream>

using namespace std;

int main() {

    int stop, fib1 = 0, fib2 = 1, fibatual = 0;

    cout << "Insira um número inteiro para limitar a sequência de Fibonacci: ";     
    
    cin >> stop;

    cout << "Sequência de Fibonacci: " << fib1 << " " << fib2 << " ";

    while (fibatual <= stop){
        
        fibatual = fib1 + fib2;

        if (fibatual <= stop){
            cout << fibatual << " ";
        }

        fib1 = fib2;
        fib2 = fibatual;
    }
    cout << endl;
    return 0;

}
