#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    
    string str;

    str.append(argv[1]);

    if (argc != 4){
        cout << "Argumentos inválidos!" << endl;
    } else {
        if (str == "\int"){
            int resultado = atoi(argv[2]) / atoi(argv[3]);
            cout << "O resultado da divisão de inteiros é: " << resultado << endl;
        } else if (str == "\double"){
            double resultado = atof(argv[2]) / atof(argv[3]);
            cout << "O resultado da divisão de reais é: " << resultado << endl;
        }
    }

    return 0;
}