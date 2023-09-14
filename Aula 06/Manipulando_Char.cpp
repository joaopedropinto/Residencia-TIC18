#include <iostream>

using namespace std;

int main(void){

    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    char letra;

    for (int i = 33; i <= 126 ; i++){

        letra = i;

        cout << "\'" << char(i) << "\'" << " - " << dec << i << " - " << oct << i << " - " << hex << i << endl;
    }

    cin >> letra;

    cout << "\'" << letra << "\'" << " - " << dec << int(letra) << " - " << oct << int(letra) << " - " << hex << int(letra) << endl;
    
    
    
    return 0;



}