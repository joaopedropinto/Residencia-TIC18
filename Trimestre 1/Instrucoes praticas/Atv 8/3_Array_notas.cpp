#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
  const int alunos = 15;
  srand(time(0));
  float notas1[alunos];
  float notas2[alunos];
  float media[alunos];
  char avalia[alunos];
  std::cout << std::fixed << std::setprecision(2);

  // Preenchendo os dois arrays com notas aleatórias
  for (int i = 0; i < alunos; i++)
  {
    notas1[i] = ((float)rand() / RAND_MAX) * 10;
  }

  for (int i = 0; i < alunos; i++)
  {
    notas2[i] = ((float)rand() / RAND_MAX) * 10;
  }

  // Comparando a primeira com a segunda nota
  for (int i = 0; i < alunos; i++)
  {
    if (notas2[i] > notas1[i])
    {
      avalia[i] = 'M'; // Melhorou
    }
    else if (notas2[i] < notas1[i])
    {
      avalia[i] = 'P'; // Piorou
    }
    else
    {
      avalia[i] = 'N'; // Manteve
    }
  }

  // Calculo da média de cada aluno
  for (int i = 0; i < alunos; i++)
  {
    media[i] = (notas1[i] + notas2[i]) / 2.0;
  }

  // Exibir os resultados
  cout << "Resultados:" << endl;
  cout << "Aluno\tNota 1\tNota 2\tDesempenho\tMédia" << endl;
  for (int i = 0; i < alunos; i++)
  {
    cout << i + 1 << "\t" << notas1[i] << "\t" << notas2[i] << "\t";
    if (avalia[i] == 'M')
    {
      cout << "Melhorou\t";
    }
    else if (avalia[i] == 'P')
    {
      cout << "Piorou  \t";
    }
    else
    {
      cout << "Manteve a nota\t";
    }
    cout << media[i] << endl;
  }

  return 0;
}