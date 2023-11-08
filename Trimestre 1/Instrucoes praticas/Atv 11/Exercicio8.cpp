#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool primo(int num)
{

  if (num <= 1)
  {
    return false;
  }
  if (num == 2)
  {
    return true;
  }
  if (num % 2 == 0)
  {
    return false;
  }

  int limite = static_cast<int>(sqrt(num));
  for (int i = 3; i <= limite; i += 2)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}

int conta_primo(int *vet, int tam)
{
  int qtd_primo = 0;

  for (int i = 0; i < tam; i++)
  {
    if (primo(vet[i]))
    {
      qtd_primo++;
    }
  }
  return qtd_primo;
}

int main()
{
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, tam, qtd_primo;

  tam = sizeof(vet) / sizeof(vet[0]);

  qtd_primo = conta_primo(vet, tam);

  cout << "A quantidade de primos no vetor é: " << qtd_primo;

  return 0;
}