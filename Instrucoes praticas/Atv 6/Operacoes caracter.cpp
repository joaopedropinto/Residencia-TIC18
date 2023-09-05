#include <iostream>

using namespace std;

int main(void){

    char ch1, ch2, ch3;

    cout << "Informe dois caracteres" << endl;

    cin >> ch1;
    cin >> ch2;

    ch3 = ch1 - 1;

    cout << "Caracter que antecede " << ch1 << endl;
    cout << "\'" << ch3 << "\'" << " - " << dec << int(ch3) << " - " << oct << int(ch3) << " - " << hex << int(ch3) << endl;

    ch3 = ch2 + 1;

    cout << "Caracter que precede " << ch2 << endl;
    cout << "\'" << ch3 << "\'" << " - " << dec << int(ch3) << " - " << oct << int(ch3) << " - " << hex << int(ch3) << endl;
    
    return 0;

}

