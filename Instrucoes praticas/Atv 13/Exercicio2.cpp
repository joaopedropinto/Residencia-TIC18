#include <iostream>
#include <string>

using namespace std;

struct Empregado
{
  string nome;
  string sobrenome;
  string ano_nascimento;
  string RG;
  string ano_admissao;
  double salario;
};

void reajusta_dez_porcento(Empregado empregados[], int numEmpregados)
{
  for (int i = 0; i < numEmpregados; i++)
  {
    empregados[i].salario *= 1.10;
  }
}
int main(void)
{
  Empregado empregados[50];

  empregados[0] = {"João", "Gois", "1999", "1235131", "2023", 1800.0};
  empregados[1] = {"Samuel", "Pinto", "2003", "123123", "2021", 1100.0};
  empregados[2] = {"Pedro", "Santos", "1986", "123465", "2012", 5400.0};
  int n = 3; //Quantidade de empregados
  cout << endl << "Empregados antes do reajuste:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$" << empregados[i].salario << endl;
  }

  reajusta_dez_porcento(empregados, n);

  cout << endl << "Salários após reajustes:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$" << empregados[i].salario << endl;
  }

  return 0;
}