#include <iostream>
#include <algorithm>

using namespace std;

int *intercala(int *vet1, int tam1, int *vet2, int tam2)
{
  int *result = new int[tam1 + tam2], i = 0, j = 0, k = 0;

  while (i < tam1 && j < tam2)
  {
    result[k++] = vet1[i++];
    result[k++] = vet2[j++];
  }
  while (i < tam1)
  {
    result[k++] = vet1[i++];
  }
  while (j < tam2)
  {
    result[k++] = vet2[j++];
  }
  return result;
}

int main()
{
  int vet1[] = {0, 10, 20, 30, 40}, vet2[] = {5, 15, 25, 35, 45}, tam1, tam2, tamResult;

  tam1 = sizeof(vet1) / sizeof(vet1[0]);
  tam2 = sizeof(vet2) / sizeof(vet2[0]);

  int *result = intercala(vet1, tam1, vet2, tam2);
  tamResult = tam1 + tam2;
  cout << "Vetor 1: ";
  for (int i = 0; i < tam1; i++)
  {
    cout << vet1[i] << " ";
  }
  cout << endl;

  cout << "Vetor 2: ";
  for (int i = 0; i < tam2; i++)
  {
    cout << vet2[i] << " ";
  }
  cout << endl;
  cout << "Vetor intercalado: ";
  for (int i = 0; i < tamResult; i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;

  delete[] result;
  return 0;
}