#include <iostream>

using namespace std;

int main(void){

    char ch1, ch2, ch3;

    cout << "Informe dois caracteres" << endl;

    cin >> ch1;
    cin >> ch2;

    ch3 = ch1 - 1;
    //Caracter que antecede ch1
    cout << "Caracter que antecede " << ch1 << endl;
    cout << "\'" << ch3 << "\'" << " - " << dec << int(ch3) << " - " << oct << int(ch3) << " - " << hex << int(ch3) << endl;

    ch3 = ch2 + 1;
    //Caracter que precede ch2
    cout << "Caracter que precede " << ch2 << endl;
    cout << "\'" << ch3 << "\'" << " - " << dec << int(ch3) << " - " << oct << int(ch3) << " - " << hex << int(ch3) << endl;
    
    ch3 = isupper(ch1) ? 'A' : ' ';

    cout << "A se ch1 for maiúscula, ' ' se não for: " << ch3 << endl;

    ch3 = islower(ch2) ? 'a' : ' ';

    cout << "a se ch2 for minúscula, ' ' se não for: " << ch3 << endl;

    ch3 = (isdigit(ch1) || isdigit(ch2)) ? '1' : ' ';

    cout << "1 se ch1 ou ch2 forem dígito, ' ' se não forem: " << ch3 << endl;

    return 0;

}

