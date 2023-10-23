#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Pacote.h" // Certifique-se de incluir o cabeçalho da classe Pacote se necessário.
using namespace std;

class Cliente {
private:
    string nome;
    string cpf;
    vector<Pacote*> pacotes;

public:
    Cliente(string nome, string cpf);

    void setPacotes(Pacote* pacote);
    vector<Pacote*>& getPacotes();
    string getNome();
    void setNome(string nome);
    string getCPF();
    void setCPF(string cpf);
};

#endif
