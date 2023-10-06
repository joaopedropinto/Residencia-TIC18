#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // Usando o namespace std para evitar a necessidade de prefixar.

// Definindo a classe ConjuntoItens para representar um conjunto de itens.
class ConjuntoItens {
private:
    vector<string> itens; // Vetor para armazenar os itens do conjunto.

public:
    // Método para inserir um item no conjunto. Verifica se o item já não existe antes de inserir.
    void inserir(const string& item) {
        if (find(itens.begin(), itens.end(), item) == itens.end()) {
            itens.push_back(item);
        }
    }

    // Método para excluir um item do conjunto, caso ele exista.
    void excluir(const string& item) {
        auto it = find(itens.begin(), itens.end(), item);
        if (it != itens.end()) {
            itens.erase(it);
        }
    }

    // Método para imprimir os itens do conjunto.
    void imprimir() const {
        for (const auto& item : itens) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    ConjuntoItens A, B; // Criando dois conjuntos, A e B.

    // Inserindo itens nos conjuntos.
    A.inserir("maca");
    A.inserir("banana");
    A.inserir("banana"); // Tentativa de inserir "banana" repetido no conjunto A.
    B.inserir("banana");
    B.inserir("cereja");

    // Imprimindo os conjuntos A e B.
    cout << "Conjunto A: ";
    A.imprimir();
    cout << "Conjunto B: ";
    B.imprimir();

    // Excluindo o item "maca" do conjunto A e depois imprimindo o conjunto A.
    A.excluir("maca");
    cout << "Conjunto A após excluir 'maca': ";
    A.imprimir();

    return 0;
}
