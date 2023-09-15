#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
  srand(time(0));

  string nome1, nome2;

  for (int i = 0; i < 10; i++)
  {
    nome1 += 'a' + rand() % ('z' - 'a');
    nome2 += 'a' + rand() % ('z' - 'a');
  }

  nome1[0] = toupper(nome1[0]);
  nome2[0] = toupper(nome2[0]);

  if (nome1 < nome2)
  {
    cout << nome1 << endl << nome2 << endl;
  }
  else
  {
    cout << nome2 << endl << nome1 << endl;
  }

  return 0;
}