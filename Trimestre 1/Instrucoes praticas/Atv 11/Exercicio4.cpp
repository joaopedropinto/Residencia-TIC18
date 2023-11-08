#include <iostream>
#include <algorithm>

using namespace std;

void calcula(int &x, int &y){
  int aux1, aux2;

  aux1 = x + y;
  aux2 = x - y;

  x = aux1;
  y = aux2;

}

int main()
{
  int x, y;

  cout << "Informe o valor de x e y: ";
  cin >> x >> y;

  calcula(x,y);

  cout << "x = " << x << endl << "y = " << y << endl;


  return 0;
}