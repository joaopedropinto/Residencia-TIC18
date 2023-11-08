//--------- João -----------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ConjuntoItens {
private:
    vector<string> itens;

public:
    ConjuntoItens() {}

    ConjuntoItens(const vector<string>& it) : itens(it) {}

    ConjuntoItens(const ConjuntoItens& outro) : itens(outro.itens) {}

    void inserir(const string& item) {
        if (!contem(item)) {
            itens.push_back(item);
        }
    }

    void excluir(const string& item) {
        for (auto it = itens.begin(); it != itens.end(); ++it) {
            if (*it == item) {
                itens.erase(it);
                break;
            }
        }
    }

//---------- Kayque -----------------

    bool contem(const string& item) const {
        for (const auto& it : itens) {
            if (it == item) {
                return true;
            }
        }
        return false;
    }

    ConjuntoItens unir(const ConjuntoItens& outro) const {
        ConjuntoItens resultado(itens);
        for (const auto& item : outro.itens) {
            resultado.inserir(item);
        }
        return resultado;
    }

// ---------------------- Gabriel --------------------

    ConjuntoItens interseccao(const ConjuntoItens& outro) const {
        ConjuntoItens resultado;
        for (const auto& item : itens) {
            if (outro.contem(item)) {
                resultado.inserir(item);
            }
        }
        return resultado;
    }
    ConjuntoItens diferenca(const ConjuntoItens& outro) const {
        ConjuntoItens resultado(itens);
        for (const auto& item : outro.itens) {
            resultado.excluir(item);
        }
        return resultado;
    }

//---------------------- Greg --------------------

    bool isEqual(const ConjuntoItens& outro) const {
        if (itens.size() != outro.itens.size()) {
            return false;
        }
        for (const auto& item : itens) {
            if (!outro.contem(item)) {
                return false;
            }
        }
        return true;
    }

    void imprimir() const {
        for (const auto& item : itens) {
            cout << item << " ";
        }
        cout << endl;
    }
};
//----------------------- Valber -----------------------------
int main() {
    ConjuntoItens A, B, C;

    A.inserir("maca");
    A.inserir("banana");
    B.inserir("banana");
    B.inserir("cereja");
    C.inserir("maca");
    C.inserir("cereja");

    cout << "Conjunto A: ";
    A.imprimir();
    cout << "Conjunto B: ";
    B.imprimir();
    cout << "Conjunto C: ";
    C.imprimir();

    ConjuntoItens D = A.unir(B);
    cout << "Conjunto D (A uniao B): ";
    D.imprimir();

    D = A.interseccao(C);
    cout << "Conjunto D (A interseccao C): ";
    D.imprimir();

    D = B.diferenca(C);
    cout << "Conjunto D (B - C): ";
    D.imprimir();

    D = A.diferenca(C).unir(C.diferenca(A)); // Diferença simétrica
    cout << "Conjunto D (Diferenca simetrica A e C): ";
    D.imprimir();

    bool saoIguais = A.isEqual(B);
    cout << "A é igual a B: " << saoIguais << endl;

    return 0;
}
