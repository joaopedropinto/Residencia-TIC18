#include <iostream>

using namespace std;

int main(void){
    char ch1, ch2 = 81, ch3;

    cout << "Escreva um caracter: " << endl;
    cin >> ch1;

    ch3 = tolower(ch2);

    string resp = islower(ch1) ? "É minúscula" : isupper(ch1) ? "É maiúscula" : isdigit(ch1) ? "É um dígito" : "É um outro tipo de caracter";

    cout << resp << endl;

    cout  << dec << int(ch2) << " - " << oct << int(ch2) << " - " << hex << int(ch2) << " - " << "\'" << ch2 << "\'"  << endl;

    cout  << dec << int(ch3) << " - " << oct << int(ch3) << " - " << hex << int(ch3) << " - " << "\'" << ch3 << "\'"  << endl;
}

