#ifndef PACOTE_H
#define PACOTE_H

#include <string>
#include <vector>
#include "Evento.h" 
#include "Cliente.h" 

class Pacote {
private:
    std::string nome;
    std::vector<Evento*> eventos;
    std::vector<Cliente*> clientes;

public:
    Pacote(std::string nome);

    std::string getNome();
    std::vector<Evento*>& getEventos();
    std::vector<Cliente*>& getClientes();
    void setClientes(Cliente* cliente);
    void setNome(std::string nome);
    void adicionarEvento(Evento* evento);
};

#endif
