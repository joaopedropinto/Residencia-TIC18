#include <iostream>
#include <string>

using namespace std;

class Animal {
    
    public:
        string nome;
        int idade;

        void fazerSom(string som);

};

class Cachorro : Animal {
    public:
        void fazerSom(){
            cout << "auau" << endl;
        }
};

int main() {
    Cachorro cao1;

    cao1.fazerSom();
}