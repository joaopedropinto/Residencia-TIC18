#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Livro{
    private:
        string titulo;
        string autor;
        int num_pagina;
        string genero;
        string editora;
        string data_publicacao;

    public:
        Livro(){
            titulo = "indefinido";
            autor = "indefinido";
            num_pagina = 0;
            genero = "indefinido";
            editora = "indefinido";
            data_publicacao = "indefinido";
        }


};

class Celular{

    private:
        string marca;
        string modelo;
        string polegadas;
        string imei;
        string RAM;
        string HD;
    public:

};

class Mamifero{

    private:
        string especie;
        string ordem;
        string familia;
        string genero;
    public:

        Mamifero(string _especie, string _ordem, string _familia, string _genero){
            especie = _especie;
            ordem = _ordem;
            familia = _familia;
            genero = _genero;
        }

        void andar(){
            cout << "O "<< especie << " está andando..." << endl;
        }
        void print_especie(){
            cout << "A especie é: " << especie << endl;
            
        }
};

int main() {
    Mamifero animal1("Canis lupus","Carnivora", "Canidae", "Canis");
    Mamifero animal2("Feliz catus","Carnivora","Felidae","Felis");

    animal1.andar();
    animal1.print_especie();
    animal2.andar();
    animal2.print_especie();
    
    return 0;
}