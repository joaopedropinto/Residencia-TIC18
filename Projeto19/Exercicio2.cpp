#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Classe que representa um conjunto de itens.
class ConjuntoItens {
private:
    vector<string> itens; // Vetor para armazenar os itens do conjunto.

public:
    // Construtor padrão
    ConjuntoItens() {}

    // Construtor de cópia
    ConjuntoItens(const ConjuntoItens& outro) : itens(outro.itens) {}

    // Método para inserir um item no conjunto, verificando se ele já não existe.
    void inserir(const string& s) {
        if (find(itens.begin(), itens.end(), s) == itens.end()) {
            itens.push_back(s);
        }
    }

    // Método para excluir um item do conjunto.
    void excluir(const string& s) {
        auto it = find(itens.begin(), itens.end(), s);
        if (it != itens.end()) {
            itens.erase(it);
        }
    }

    // Sobrecarga do operador de atribuição.
    ConjuntoItens& operator=(const ConjuntoItens& outro) {
        if (this != &outro) {
            itens = outro.itens;
        }
        return *this;
    }

    // Sobrecarga do operador + para representar a união de conjuntos.
    ConjuntoItens operator+(const ConjuntoItens& outro) const {
        ConjuntoItens resultado = *this;
        for (const auto& item : outro.itens) {
            resultado.inserir(item);
        }
        return resultado;
    }

    // Sobrecarga do operador * para representar a intersecção de conjuntos.
    ConjuntoItens operator*(const ConjuntoItens& outro) const {
        ConjuntoItens resultado;
        for (const auto& item : itens) {
            if (find(outro.itens.begin(), outro.itens.end(), item) != outro.itens.end()) {
                resultado.inserir(item);
            }
        }
        return resultado;
    }

    // Sobrecarga do operador - para representar a diferença entre conjuntos.
    ConjuntoItens operator-(const ConjuntoItens& outro) const {
        ConjuntoItens resultado = *this;
        for (const auto& item : outro.itens) {
            resultado.excluir(item);
        }
        return resultado;
    }

    // Sobrecarga do operador ^ para representar a diferença simétrica.
    ConjuntoItens operator^(const ConjuntoItens& outro) const {
        ConjuntoItens conjuntoUniao = *this + outro;
        ConjuntoItens conjuntoIntersecao = *this * outro;
        return conjuntoUniao - conjuntoIntersecao;
    }

    // Sobrecarga do operador == para verificar se dois conjuntos são iguais.
    bool operator==(const ConjuntoItens& outro) const {
        if (itens.size() != outro.itens.size()) {
            return false;
        }
        for (const auto& item : itens) {
            if (find(outro.itens.begin(), outro.itens.end(), item) == outro.itens.end()) {
                return false;
            }
        }
        return true;
    }

    // Método para imprimir o conjunto.
    void imprimir() const {
        for (const auto& item : itens) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    ConjuntoItens A, B, C;

    // Inserindo itens nos conjuntos A, B e C.
    A.inserir("maca");
    A.inserir("banana");
    B.inserir("banana");
    B.inserir("cereja");
    C.inserir("maca");
    C.inserir("cereja");

    // Imprimindo os conjuntos A, B e C.
    cout << "Conjunto A: ";
    A.imprimir();
    cout << "Conjunto B: ";
    B.imprimir();
    cout << "Conjunto C: ";
    C.imprimir();

    // Realizando operações de união, interseção, diferença e diferença simétrica.
    ConjuntoItens D = A + B;
    cout << "Conjunto D (A uniao B): ";
    D.imprimir();

    D = A * C;
    cout << "Conjunto D (A interseccao C): ";
    D.imprimir();

    D = B - C;
    cout << "Conjunto D (B - C): ";
    D.imprimir();

    D = A ^ C;
    cout << "Conjunto D (Diferenca simetrica A e C): ";
    D.imprimir();

    // Verificando se os conjuntos A e B são iguais.
    bool saoIguais = A == B;
    cout << "A e igual a B: " << saoIguais << endl;

    return 0;
}
