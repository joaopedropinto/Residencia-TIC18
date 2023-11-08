#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    
    int sorteio = 0, aux = 0;

    srand(time(NULL));
    sorteio = rand() % 100 + 1;

    cout << sorteio << endl;

    cout << "Informe um número para participar do sorteio: " << endl;

    while(1){
        cin >> aux;
        if(aux == sorteio){
            cout << "Acertou!" << endl;
            break;
        }else if(aux < sorteio){
            cout << "O palpite foi abaixo, tente novamente!" << endl;
            continue;
        }else if(aux > sorteio){
            cout << "O palpite foi alto, tente novamente!" << endl;
            continue;
        }
    }
    
    return 0;
}