#include <iostream>

using namespace std;

int main(void){
    
    int a, b, c;
    
    cout << "Informe dois números inteiros" << endl;

    cin >> a;
    cin >> b;

    c = 4 * a + b / 3 - 5;

    cout << "A expressão c = 4 * a + b / 3 - 5, tem valor: " << c << endl;
    //A expressão acima realiza as operações de multiplicação e divisão primeiro, por possuírem maior prioridade matemática. Após isso as operações 
    //de adição e subtração são efetuadas.

    c = 4 * (a + b) / (3 - 5);

    cout << "A expressão c = 4 * (a + b) / (3 - 5), tem valor: " << c << endl;
    //A expressão acima realiza primeiro as operações que estão contidas entre os parênteses, por possuírem maior prioridade. Após isso,
    //as operações de multiplicação e divisão são realizadas e por fim adição e subtração.

    //Uma outra variação pode ser observada em c = (4 * a) + (b / 3) - 5;

    c = ((4 * a + b) / 3) - 5;

    cout << "A expressão c = ((4 * a + b) / 3) - 5, tem valor: " << c << endl;

    c = a*a + 2 * b + c;

    cout << "A expressão a² + 2 * b + c, tem valor: " << c << endl;

    return 0; 

}