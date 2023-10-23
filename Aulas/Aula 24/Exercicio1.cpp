#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estado {
public:
    string nome;
    string sigla;

    Estado(const string& nome, const string& sigla)
        : nome(nome), sigla(sigla) {}
};

class Cidade {
public:
    string nome;
    Estado* estado;

    Cidade(const string& nome, Estado* estado)
        : nome(nome), estado(estado) {}
};

int main() {
    int numEstados, numCidades;

    // Solicita o número de estados ao usuário
    cout << "Quantos estados deseja cadastrar? ";
    cin >> numEstados;

    // Crie um vector para armazenar os Estados
    vector<Estado> estados;

    // Preenche os estados com os dados fornecidos pelo usuário
    for (int i = 0; i < numEstados; i++) {
        string nome, sigla;
        cout << "Estado " << i + 1 << ":" << endl;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Sigla (UF): ";
        cin >> sigla;

        estados.push_back(Estado(nome, sigla));
    }

    // Solicita o número de cidades ao usuário
    cout << "\nQuantas cidades deseja cadastrar? ";
    cin >> numCidades;

    // Crie um vector para armazenar as Cidades
    vector<Cidade> cidades;

    // Preenche as cidades com os dados fornecidos pelo usuário
    for (int i = 0; i < numCidades; i++) {
        string nome;
        int estadoSelecionado;

        cout << "Cidade " << i + 1 << ":" << endl;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);

        // Solicita ao usuário que selecione um estado para a cidade
        cout << "Selecione o estado (1 a " << numEstados << "): ";
        cin >> estadoSelecionado;

        if (estadoSelecionado >= 1 && estadoSelecionado <= numEstados) {
            cidades.push_back(Cidade(nome, &estados[estadoSelecionado - 1]));
        } else {
            cout << "Seleção de estado inválida. A cidade não foi associada a um estado." << endl;
        }
    }

    // Exibe os dados dos Estados e Cidades
    cout << "\nInformações dos Estados:" << endl;
    for (const Estado& estado : estados) {
        cout << "Nome: " << estado.nome << endl;
        cout << "Sigla (UF): " << estado.sigla << endl;
    }

    cout << "\nInformações das Cidades:" << endl;
    for (const Cidade& cidade : cidades) {
        cout << "Nome: " << cidade.nome << endl;
        if (cidade.estado != nullptr) {
            cout << "Estado: " << cidade.estado->nome << " (" << cidade.estado->sigla << ")" << endl;
        } else {
            cout << "Esta cidade não foi associada a um estado." << endl;
        }
    }

    return 0;
}
