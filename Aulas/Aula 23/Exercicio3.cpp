#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class ItemBiblioteca {

  public:
    string titulo;
    string autor;
    int numCopias;

    ItemBiblioteca(const string& titulo, const string& autor, int numCopias)
          : titulo(titulo), autor(autor), numCopias(numCopias) {}
    
    void mostrarDetalhes() {
      cout << "Título: " << titulo << endl;
      cout << "Autor: " << autor << endl;
      cout << "Número de cópias disponíveis: " << numCopias << endl;
    }
};

class Livro : public ItemBiblioteca { 
  public:
    int numPaginas;
    Livro(const string& titulo, const string& autor, int numCopias, int numPaginas)
        : ItemBiblioteca(titulo, autor, numCopias), numPaginas(numPaginas) {}

    void mostrarDetalhes() {
        ItemBiblioteca::mostrarDetalhes();
        cout << "Número de páginas: " << numPaginas << endl;
    }
};

class DVD : public ItemBiblioteca {
  public: 
    int duracao;
    DVD(const string& titulo, const string& autor, int numCopias, int duracao)
          : ItemBiblioteca(titulo, autor, numCopias), duracao(duracao) {}

      void mostrarDetalhes() {
          ItemBiblioteca::mostrarDetalhes();
          cout << "Duração: " << duracao << " minutos" << endl;
      }
};



int main() {

  Livro livro1("O Nome do Vento", "Patrick Rothfuss", 27, 656);
  DVD dvd1("O Poderoso Chefão", "Francis Ford Coppola", 15, 177);
  
  cout << "Detalhes do livro 1:" << endl;
  livro1.mostrarDetalhes();

  cout << "\nDetalhes do DVD 1:" << endl;
  dvd1.mostrarDetalhes();


  return 0;
}