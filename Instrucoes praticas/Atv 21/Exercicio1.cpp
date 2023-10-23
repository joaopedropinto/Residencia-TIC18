// Parte de Kayque
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Livro {
public:
    Livro(const string& titulo, const string& autor, int copiasDisponiveis)
        : titulo(titulo), autor(autor), copiasDisponiveis(copiasDisponiveis) {}

    string getTitulo() const {
        return titulo;
    }

    string getAutor() const {
        return autor;
    }

    int getCopiasDisponiveis() const {
        return copiasDisponiveis;
    }

    void emprestarLivro() {
        if (copiasDisponiveis > 0) {
            copiasDisponiveis--;
        }
    }
    // Fim da parte de Kayque

    // Parte de João
    void devolverLivro() {
        copiasDisponiveis++;
    }

private:
    string titulo;
    string autor;
    int copiasDisponiveis;
};

class Usuario {
public:
    Usuario(const string& nome) : nome(nome) {}

    string getNome() const {
        return nome;
    }
    // Fim da parte de João

    // Parte de Gabriel
    static void registrarEmprestimo(Usuario& usuario, Livro& livro) {
        time_t agora = time(nullptr);
        tm* dataEmprestimo = localtime(&agora);
        cout << "Livro '" << livro.getTitulo() << "' emprestado para '" << usuario.getNome()
                  << "' em " << dataEmprestimo->tm_mday << '/' << dataEmprestimo->tm_mon + 1 << '/'
                  << dataEmprestimo->tm_year + 1900 << endl;
        livro.emprestarLivro();
    }

    static void listarLivrosEmprestadosPorUsuario(const Usuario& usuario, const vector<Livro>& livros) {
        cout << "Livros emprestados por '" << usuario.getNome() << "':" << endl;
        for (const Livro& livro : livros) {
            if (livro.getCopiasDisponiveis() < 1) {
                cout << "- '" << livro.getTitulo() << "' de '" << livro.getAutor() << "'" << endl;
            }
        }
    }
    // Fim da parte de Gabriel

    // Parte de Felipe
private:
    string nome;
};

int main() {
    vector<Livro> biblioteca;

    // Adicionar alguns livros à biblioteca
    biblioteca.emplace_back("O Senhor dos Anéis", "J.R.R. Tolkien", 5);
    biblioteca.emplace_back("Harry Potter e a Pedra Filosofal", "J.K. Rowling", 3);
    biblioteca.emplace_back("1984", "George Orwell", 2);

    Usuario usuario1("Alice");
    // Fim da parte de Felipe

    // Parte de Valber
    Usuario usuario2("Bob");

    // Alice pega emprestado um livro
    Usuario::registrarEmprestimo(usuario1, biblioteca[0]);  

    // Bob pega emprestado um livro
    Usuario::registrarEmprestimo(usuario2, biblioteca[1]); 

    // Bob pega emprestado outro livro
    Usuario::registrarEmprestimo(usuario2, biblioteca[2]);  

    // Listar os livros emprestados por Bob
    Usuario::listarLivrosEmprestadosPorUsuario(usuario2, biblioteca);  

    return 0;
}
    // Fim da parte de Valber