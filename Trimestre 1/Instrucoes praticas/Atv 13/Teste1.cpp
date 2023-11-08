#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Passageiro
{
  string nome;
  int idade;
  int poltrona;
};

struct Viagem
{
  int numeroViagem;
  vector<Passageiro> passageiros;
};

double calcularTotalArrecadado(const Viagem &viagem)
{
  double valorPassagem = 80.0; // Valor de cada passagem
  return viagem.passageiros.size() * valorPassagem;
}

double calcularTotalArrecadadoNoMes(const vector<Viagem> &viagens)
{
  double totalArrecadado = 0.0;
  for (const Viagem &viagem : viagens)
  {
    totalArrecadado += calcularTotalArrecadado(viagem);
  }
  return totalArrecadado;
}

string obterNomePassageiro(const Viagem &viagem, int poltrona)
{
  for (const Passageiro &passageiro : viagem.passageiros)
  {
    if (passageiro.poltrona == poltrona)
    {
      return passageiro.nome;
    }
  }
  return "Poltrona não encontrada";
}

double calcularMediaIdade(const Viagem &viagem)
{
  if (viagem.passageiros.empty())
    return 0.0;

  int somaIdades = 0;
  for (const Passageiro &passageiro : viagem.passageiros)
  {
    somaIdades += passageiro.idade;
  }
  return static_cast<double>(somaIdades) / viagem.passageiros.size();
}
int encontrarViagemMaisRentavel(const vector<Viagem> &viagens)
{
  double receitaMaxima = 0.0;
  int horarioMaisRentavel = -1; // Inicializa com um valor que não corresponde a uma viagem válida

  for (const Viagem &viagem : viagens)
  {
    double receitaViagem = calcularTotalArrecadado(viagem);
    if (receitaViagem > receitaMaxima)
    {
      receitaMaxima = receitaViagem;
      horarioMaisRentavel = viagem.numeroViagem;
    }
  }

  return horarioMaisRentavel;
}

int main()
{
  srand(time(0)); // Inicializa a semente para gerar números aleatórios

  // Simulando dados de vendas para várias viagens (números de passagens vendidas para cada viagem)
  vector<Viagem> viagens;

  for (int i = 0; i < 5; i++)
  {
    Viagem viagem;
    viagem.numeroViagem = i + 1;

    for (int j = 0; j < rand() % 30 + 20; j++)
    {
      Passageiro passageiro;
      passageiro.nome = "Passageiro " + to_string(j + 1);
      passageiro.idade = rand() % 60 + 20; // Idade aleatória entre 20 e 69 anos
      passageiro.poltrona = j + 1;         // Número da poltrona
      viagem.passageiros.push_back(passageiro);
    }

    viagens.push_back(viagem);
  }

  // Exemplo de uso das funcionalidades
  for (const Viagem &viagem : viagens)
  {
    cout << "Total arrecadado para a viagem " << viagem.numeroViagem << ": $" << calcularTotalArrecadado(viagem) << endl;
  }

  cout << "Total arrecadado no mês: $" << calcularTotalArrecadadoNoMes(viagens) << endl;

  int viagemParaConsultar = rand() % 5 + 1;  // Substitua pelo número da viagem que deseja consultar.
  int assentoParaConsultar = rand() % 20 + 1; // Substitua pelo número da poltrona que deseja consultar.
  cout << "Nome do passageiro da poltrona " << assentoParaConsultar << " na viagem " << viagemParaConsultar << ": "
       << obterNomePassageiro(viagens[viagemParaConsultar - 1], assentoParaConsultar) << endl;

  int viagemMaisRentavel = encontrarViagemMaisRentavel(viagens);
  if (viagemMaisRentavel != -1)
  {
    cout << "A viagem mais rentável é a viagem " << viagemMaisRentavel << endl;
  }
  else
  {
    cout << "Nenhuma viagem encontrada." << endl;
  }

  for (const Viagem &viagem : viagens)
  {
    cout << "Média de idade dos passageiros na viagem " << viagem.numeroViagem << ": " << calcularMediaIdade(viagem) << " anos" << endl;
  }

  return 0;
}
