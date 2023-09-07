#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    int idade; 

    cout << argc << endl;

    cout << "Bom dia " << argv[1] << endl;
    
    idade = 2023 - atoi(argv[2]);
    
    cout << "Você tem " << idade << " anos!" << endl;

    return 0;

}