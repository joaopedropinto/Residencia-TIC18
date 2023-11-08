#include <iostream>
#include <string>

using namespace std;

class Desenhavel {
    
    public:
    virtual void desenhar() = 0;
};

class Circulo : public Desenhavel {
    public: 
        void desenhar() override {
            cout << "Desenhando circulo..." << endl;
            
        }
};

class Retangulo : public Desenhavel {
    public: 
        void desenhar() override {
            cout << "Desenhando retangulo..." << endl;
            
        }
};

class Triangulo : public Desenhavel {
    public: 
        void desenhar() override {
            cout << "Desenhando triangulo..." << endl;
            
        }
};

int main() {
    
    Circulo circulo;
    Retangulo retangulo;
    Triangulo triangulo;

    Desenhavel* item1 = &circulo;
    Desenhavel* item2 = &retangulo;
    Desenhavel* item3 = &triangulo;

    item1 -> desenhar();
    item2 -> desenhar();
    item3 -> desenhar();
    
    
    return 0;
}