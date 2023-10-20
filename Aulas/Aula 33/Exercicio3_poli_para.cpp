#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> class Lista {
    
    private:
        vector<T> elementos;

    public:
        void adicionar(T elemento){
            elementos.push_back(elemento);
        }

        bool remover(T elemento){
           
            for (int i = 0; i < elementos.size(); ++i) {
                if (elementos[i] == elemento) {
                    elementos.erase(elementos.begin() + i);
                    return true;
                }
            }
            return false;
        }

        void listar(){
            for (const T elemento : elementos) {
                cout << elemento << " ";
            }
            cout << std::endl;
        }
};

int main(){
    Lista<int> listaInt;
    
    listaInt.adicionar(1);
    listaInt.adicionar(2);
    listaInt.adicionar(3);
    listaInt.adicionar(4);
    listaInt.adicionar(5);
    listaInt.adicionar(6);
    listaInt.adicionar(7);
    listaInt.adicionar(8);
    cout << "Lista inteiros: " << endl;
    listaInt.listar();

    listaInt.remover(8); 
    cout << "Removido 8" << endl;
    
    listaInt.listar();

    Lista<string> listaString;
    listaString.adicionar("Teste");
    listaString.adicionar("geral");
    listaString.adicionar("aula33");
    cout << "\nLista string:" << endl;
    listaString.listar();
    listaString.remover("aula33");
    cout << "Removido aula33" << endl;
    listaString.listar();

    Lista<double> listaDouble;
    listaDouble.adicionar(1.23);
    listaDouble.adicionar(4.56);
    cout << "\nLista double: " << endl;
    listaDouble.listar();
    listaDouble.remover(4.56);
    cout << "Removido 4.56" << endl;
    listaDouble.listar();

    return 0;
}