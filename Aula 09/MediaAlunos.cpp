#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){

    int i = 0, aux = 1, matri[50] = {};

    float nota1[50], nota2[50], nota3[50], media[50];

    while(aux){

        cout << "Informe a matrícula do aluno " << i+1 << endl;
        cin >> matri[i];
        cout << "Informe a nota 1: " << endl;
        cin >> nota1[i];
        cout << "Informe a nota 2: " << endl;
        cin >> nota2[i];
        cout << "Informe a nota 3: " << endl;
        cin >> nota3[i];
        cout << "Insira 0 se deseja parar, ou qualquer outro dígito para continuar" << endl;
        cin >> aux;
        i++;
        continue;
        
    }
    for (int j = 0; j < i; j++){
        std::cout << std::fixed << std::setprecision(1);
        media[j] = (nota1[j] + nota2[j] + nota3[j]) / 3.0;
        cout << "MATRICULA || NOTA 1 || NOTA 2 || NOTA 3 || MEDIA" << endl;
        cout << "===================================================" << endl;        
        cout << "   " << matri[j] << "       " << nota1[j] << "       " << nota2[j] << "       " << nota3[j] << "       " << media[j] << endl << endl;
    }
    
    return 0;

}