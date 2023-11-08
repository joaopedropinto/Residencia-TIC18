#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int *encontra(const string &texto, char letra, int &tam)
{
  int *posicao = nullptr;

  for (int i = 0; i < texto.length(); i++)
  {
    if (texto[i] == letra)
    {
      int *vetor = new int[tam + 1];

      for (int j = 0; j < tam; j++)
      {
        vetor[j] = posicao[j];
      }

      vetor[tam] = i;

      delete[] posicao;

      posicao = vetor;
      tam++;
    }
  }

  return posicao;
}

int main()
{
  string texto;
  char letra;
  int tam = 0;

  cout << "Insira uma string: ";
  cin >> texto;

  cout << "Digite a letra que será procurada: ";
  cin >> letra;

  int *posicao = encontra(texto, letra, tam);

  cout << "Posições em que a letra foi localizada:" << endl;
  for (int i = 0; i < tam; i++)
  {
    cout << posicao[i] << " ";
  }
  cout << endl;

  delete[] posicao;

  return 0;
}