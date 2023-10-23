//INICIO DA PARTE DE KAYQUE

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Classe para representar um Livro
class Livro {
public:
    // Construtor da classe Livro
    Livro(const string &titulo, const string &autor, int numCopias) 
        : titulo(titulo), autor(autor), numCopias(numCopias) {}

    // Métodos para obter informações do livro
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getNumCopias() const { return numCopias; }

    // Método para emprestar um livro, decrementando a quantidade disponível
    void emprestar() { if(numCopias > 0) numCopias--; }
    
    // Método para devolver um livro, incrementando a quantidade disponível
    void devolver() { numCopias++; }

private:
    string titulo;
    string autor;
    int numCopias;
};
//FIM DA PARTE DE KAYQUE


//INICIO DA PARTE DE GREGUE
// Classe para representar um Emprestimo de livr
class Emprestimo {
public:
    Emprestimo(Livro *livro, const string &data) : livro(livro), data(data) {}

    Livro* getLivro() const { return livro; }
    string getData() const { return data; }

private:
    Livro* livro;  // Ponteiro para o livro emprestado
    string data;   // Data do Emprestimo
};
//FIM DA PARTE DE GREGUE


// INICIO DA PARTE DE GABRIEL
// Classe para representar um usuario
class Usuario {
public:
    string nome;  // Nome do usuario, tornando público por simplicidade

    Usuario(const string &nome) : nome(nome) {}

    // Método para o usuario pegar um livro emprestado
    void pegarLivro(Livro &livro) {
        livro.emprestar();
        time_t now = time(0);
        string data = ctime(&now);
        data = data.substr(0, data.length()-1);  // Remover o '\n' do final
        emprestimos.push_back(Emprestimo(&livro, data));
    }

    // Método para obter os livros emprestados pelo usuario
    vector<Emprestimo> getEmprestimos() const {
        return emprestimos;
    }

private:
    vector<Emprestimo> emprestimos;  // Lista de livros emprestados pelo usuario
};
//FIM DA PARTE DE GABRIEL

//INICIO DA PARTE DE JOAO
// Classe Biblioteca para gerenciar os livros e Emprestimos
class Biblioteca {
public:
    // Método para adicionar um livro à biblioteca
    static void adicionarLivro(const string &titulo, const string &autor, int numCopias) {
        livros.push_back(Livro(titulo, autor, numCopias));
    }

    // Método para verificar a disponibilidade de um livro na biblioteca
    static bool verificarDisponibilidade(const string &titulo) {
        for(const auto &livro : livros) {
            if(livro.getTitulo() == titulo && livro.getNumCopias() > 0) {
                return true;
            }
        }
        return false;
    }

    // Método para listar os livros emprestados por um usuario específico
    static void listarLivrosEmprestados(const Usuario &usuario) {
        auto emprestimos = usuario.getEmprestimos();
        for(const auto &emprestimo : emprestimos) {
            cout << emprestimo.getLivro()->getTitulo() << " - " << emprestimo.getLivro()->getAutor() 
                 << " (Data do Emprestimo: " << emprestimo.getData() << ")" << endl;
        }
    }

    // Método para obter a lista de livros da biblioteca
    static vector<Livro>& getLivros() { return livros; }

private:
    static vector<Livro> livros;  // Lista de livros na biblioteca
};

vector<Livro> Biblioteca::livros;
//FIM DA PARTE DE JOAO


//INICIO DA PARTE DE VALBER
// Função principal
int main() {
    int opcao;
    string titulo, autor;
    int numCopias;
    Usuario* usuarioAtual = nullptr;  // Ponteiro para o usuario atual

    // Loop do menu principal
    while (true) {
        cout << "\n--- Menu Biblioteca ---\n";
        cout << "1. Adicionar livro\n";
        cout << "2. Registrar usuario\n";
        cout << "3. Pegar livro emprestado\n";
        cout << "4. Verificar disponibilidade de livro\n";
        cout << "5. Listar livros emprestados por usuario\n";
        cout << "6. Sair\n";
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        // Opções do menu
        switch (opcao) {
            case 1:
                // Adicionar livro à biblioteca
                cout << "Título: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "Número de cópias: ";
                cin >> numCopias;
                Biblioteca::adicionarLivro(titulo, autor, numCopias);
                break;
            
            case 2:
                // Registrar um novo usuario
                cout << "Nome do usuario: ";
                getline(cin, titulo);
                usuarioAtual = new Usuario(titulo);
                break;

            case 3:
                // Pegar um livro emprestado
                if (usuarioAtual) {
                    cout << "Título do livro para emprestar: ";
                    getline(cin, titulo);
                    for (auto &livro : Biblioteca::getLivros()) {
                        if (livro.getTitulo() == titulo && livro.getNumCopias() > 0) {
                            usuarioAtual->pegarLivro(livro);
                            cout << "Livro emprestado com sucesso!\n";
                            break;
                        }
                    }
                } else {
                    cout << "Primeiro, registre um usuario.\n";
                }
                break;

            case 4:
                // Verificar disponibilidade de um livro
                cout << "Título do livro para verificar disponibilidade: ";
                getline(cin, titulo);
                if (Biblioteca::verificarDisponibilidade(titulo)) {
                    cout << "O livro está disponível para Emprestimo.\n";
                } else {
                    cout << "O livro não está disponível para Emprestimo.\n";
                }
                break;

            case 5:
                // Listar livros emprestados por um usuario
                if (usuarioAtual) {
                    cout << "Livros emprestados para " << usuarioAtual->nome << ":\n";
                    Biblioteca::listarLivrosEmprestados(*usuarioAtual);
                } else {
                    cout << "Primeiro, registre um usuario.\n";
                }
                break;

            case 6:
                // Sair do programa
                if (usuarioAtual) delete usuarioAtual;
                return 0;

            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }
}
// FIM DA PARTE DE VALBER