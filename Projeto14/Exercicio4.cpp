#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a struct Livro
struct Livro {
    string titulo;
    int numeroPagina;
    string autor;
    int anoPublicacao;
};

void adicionarLivro(vector<Livro>& biblioteca) {
    cout << "\n=== Adicionando Livros ===";
    Livro novoLivro;
    cout << "\nDigite o titulo do livro: ";
    cin.ignore();
    getline(cin, novoLivro.titulo);
    cout << "Digite o número de páginas: ";
    cin >> novoLivro.numeroPagina;
    cin.ignore();
    cout << "Digite o autor do livro: ";
    getline(cin, novoLivro.autor);
    cout << "Digite o ano de publicacao: ";
    cin >> novoLivro.anoPublicacao;
    biblioteca.push_back(novoLivro);
    cout << "Livro adicionado com sucesso!\n";
}

void listarLivros(const vector<Livro>& biblioteca) {
    cout << "\n=== Listando Livros ===";
    if (biblioteca.empty()) {
        cout << "\nBiblioteca vazia!";
    } else {
        cout << "\nLivros na Biblioteca:";
        for (const auto& livro : biblioteca) {
            cout << "\n- Título: " << livro.titulo;
            cout << "\n  Número de Páginas: " << livro.numeroPagina;
            cout << "\n  Autor: " << livro.autor;
            cout << "\n  Ano de Publicação: " << livro.anoPublicacao << endl;
        }
    }
    cout << endl;
}

void pesquisarLivro(const vector<Livro>& biblioteca) {
    cout << "\n=== Pesquisando Livro ===";
    string titulo;
    cout << "\nDigite o titulo do livro a ser pesquisado: ";
    cin.ignore();
    getline(cin, titulo);
    for (const auto& livro : biblioteca) {
        if (livro.titulo == titulo) {
            cout << "Livro encontrado:\n";
            cout << "Título: " << livro.titulo << endl;
            cout << "Número de Páginas: " << livro.numeroPagina << endl;
            cout << "Autor: " << livro.autor << endl;
            cout << "Ano de Publicação: " << livro.anoPublicacao << endl;
            return;  // Encerra a função quando o livro é encontrado
        }
    }
    cout << "Livro nao encontrado!\n";
}

void removerLivro(vector<Livro>& biblioteca) {
    cout << "\n=== Removendo Livro ===";
    string titulo;
    cout << "\nDigite o titulo do livro a ser removido: ";
    cin.ignore();
    getline(cin, titulo);
    for (auto it = biblioteca.begin(); it != biblioteca.end(); ++it) {
        if (it->titulo == titulo) {
            biblioteca.erase(it);
            cout << "Livro removido com sucesso!\n";
            return;  // Encerra a função quando o livro é removido
        }
    }
    cout << "Livro nao encontrado!\n";
}

void atualizarTituloLivro(vector<Livro>& biblioteca) {
    cout << "\n=== Atualizando titulo do Livro ===";
    string tituloAtual, novoTitulo;
    cout << "\nDigite o titulo atual do livro: ";
    cin.ignore();
    getline(cin, tituloAtual);
    for (auto& livro : biblioteca) {
        if (livro.titulo == tituloAtual) {
            cout << "\nDigite o novo titulo para o livro: ";
            getline(cin, novoTitulo);
            livro.titulo = novoTitulo;
            cout << "Titulo atualizado com sucesso!\n";
            return;  // Encerra a função depois da atualização
        }
    }
    cout << "Livro nao encontrado!\n";
}

int main() {
    vector<Livro> biblioteca;

    while (true) {
        cout << endl << "==== Menu Principal ==== " << endl;

        cout << "1. Adicionar livro " << endl;
        cout << "2. Listar livros" << endl;
        cout << "3. Pesquisar livro" << endl;
        cout << "4. Atualizar título de livro" << endl;
        cout << "5. Remover livro" << endl;
        cout << "0. Sair." << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarLivro(biblioteca);
                break;
            case 2:
                listarLivros(biblioteca);
                break;
            case 3:
                pesquisarLivro(biblioteca);
                break;
            case 4:
                atualizarTituloLivro(biblioteca);
                break;
            case 5:
                removerLivro(biblioteca);
                break;
            case 0:
                cout << "Programa finalizado!" << endl;
                return 0;
            default:
                cout << "Informe uma opção válida!" << endl;
                break;
        }
    }

    return 0;
}
