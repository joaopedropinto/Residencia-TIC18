#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Ponto{
    private:

        float x, y, z;

    public:
        Ponto(){
            x = 0.0;
            y = 0.0;
            z = 0.0;
        }
        void setx(float _x){
            x = _x;
        }
        void sety(float _y){
            y = _y;
        }
        void setz(float _z){
            z = _z;
        }
        float getx(){
            return x;
        }
        float gety(){
            return y;
        }
        float getz(){
            return z;
        }
};

class Poligono{
    private:

        vector<Ponto> pontos;

    public:
        Poligono(){
            pontos = {};
        }
        void setPoli(Ponto _pontos){
            pontos.push_back(_pontos);
        }

        vector<Ponto> getPoli(){
            return pontos;
        }
};

int main(){
    Poligono poli;
    float valorx, valory, valorz;
    cout << "Criando um poligono!" << endl;
    char sn;
    
    do{
        cout << "Digite as coordenadas x, y e z do ponto: ";
        Ponto p;
        cin >> valorx >> valory >> valorz;
        p.setx(valorx);
        p.sety(valory);
        p.setz(valorz);

        poli.setPoli(p);

        cout << "Deseja inserir mais pontos (s/n)?";
        cin >> sn;

    }while(sn!='n');
    cout << "As coordenadas digitadas foram" << endl;

    for (Ponto p:poli.getPoli()){
        cout << "(" << p.getx() << "," << p.gety() << "," << p.getz() << ")" << endl;
    }
}