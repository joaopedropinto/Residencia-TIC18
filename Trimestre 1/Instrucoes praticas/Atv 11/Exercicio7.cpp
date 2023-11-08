#include <iostream>
#include <algorithm>

using namespace std;

void multiplica(int *vet, int qtde, int n)
{
  for (int i = 0; i < qtde; i++)
  {
    vet[i] *= n;
  }
}

int main()
{
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, qtde, n;

  qtde = sizeof(vet) / sizeof(vet[0]);

  cout << "Vetor: ";
  for (int i = 0; i < qtde; i++)
  {
    cout << vet[i] << " ";
  }
  cout << endl;

  cout << "Insira um número inteiro para multiplicar por cada valor do vetor: ";
  cin >> n;

  multiplica(vet, qtde, n);

  cout << "Vetor atualizado: ";
  for (int i = 0; i < qtde; i++)
  {
    cout << vet[i] << " ";
  }
  cout << endl;
  return 0;
}