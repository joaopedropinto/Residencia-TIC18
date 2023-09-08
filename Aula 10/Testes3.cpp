#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int num, soma = 0;

    vector<int> vec;

    string resposta = "sim";
    
    while(resposta == "sim"){
        cout << "Insira um elemento no vetor: " << endl;
        cin >> num;
        soma += num;
        vec.push_back(num);

        cout << "Deseja inserir um novo elemento? " << endl;
        cin >> resposta;
        if(resposta != "sim"){
            cout << "Os elementos inseridos foram: ";
            for(int x: vec )
            cout << x << " ";
            cout << endl << "A média dos valores inseridos foi: " << soma/vec.size() << endl;
        }

    }


    return 0;
}