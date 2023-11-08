#ifndef EVENTO_H
#define EVENTO_H

#include <string>

class Evento {
private:
    std::string nome;
    double duracao;

public:
    Evento(std::string nome, double duracao);

    std::string getNome();
    void setNome(std::string nome);
    double getDuracao();
    void setDuracao(double duracao);
};

#endif
