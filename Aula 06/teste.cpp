#include <iostream>

using namespace std;

int main(){

    int num1, num2, res=0, i=0, s, s1=1, s2=1;
    
    cout << "Digite o primeiro numero: ";
    cin >> num1;
    cout << "Digite o primeiro numero: ";
    cin >> num2;
    
    if (num1 < 0){
        num1 = -num1;
        s1 = -1;    
    }

    if (num2 < 0){

        num2 = -num2;
        s2 = -1;
    }

    s = s1 * s2;

    while(i < num2){

        res += num1;
        i++;
    }

    cout << "Resultado " << res*s << endl;

    return 0;
}
