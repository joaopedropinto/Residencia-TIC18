#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Passageiro {
    int numero_assento;
    string data_hora;
    string cpf;
    string nome;
    int idade;
};

struct Viagem {
    int numero_viagem;
    string data;
    string horario;
    vector<Passageiro> passagens_vendidas;
};

void vender_passagem(Viagem& viagem, int numero_assento, string data_hora, string cpf, string nome, int idade) {
    Passageiro passagem;
    passagem.numero_assento = numero_assento;
    passagem.data_hora = data_hora;
    passagem.cpf = cpf;
    passagem.nome = nome;
    passagem.idade = idade;
    viagem.passagens_vendidas.push_back(passagem);
}

int total_arrecadado(const Viagem& viagem) {
    return viagem.passagens_vendidas.size() * 80;
}

string nome_passageiro_por_assento(const Viagem& viagem, int numero_assento) {
    for (const Passageiro& passagem : viagem.passagens_vendidas) {
        if (passagem.numero_assento == numero_assento) {
            return passagem.nome;
        }
    }
    return "Assento vazio";
}

int main() {
    Viagem viagem;
    viagem.numero_viagem = 1;
    viagem.data = "03/10/2023";
    viagem.horario = "08:00";

    vender_passagem(viagem, 1, "03/10/2023 07:30", "1234567890", "João", 30);
    vender_passagem(viagem, 2, "03/10/2023 07:45", "9876543210", "Maria", 25);

    cout << "Total arrecadado para a viagem: R$" << total_arrecadado(viagem) << endl;
    cout << "Nome do passageiro da poltrona 1: " << nome_passageiro_por_assento(viagem, 1) << endl;
    cout << "Nome do passageiro da poltrona 2: " << nome_passageiro_por_assento(viagem, 2) << endl;

    return 0;
}
