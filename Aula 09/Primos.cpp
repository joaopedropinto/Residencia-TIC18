#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int aux, coun, div;

    for(aux = 2 ; aux <= 100 ; aux++){
        
        div=0;

        for(coun = 2 ; coun <= sqrt(aux) ; coun++)

            if(aux % coun == 0){
                div++;
            }
                

        if(!div){
            cout << aux << " ";
        }
            
    }

    cout << endl;

    return 0;
}
