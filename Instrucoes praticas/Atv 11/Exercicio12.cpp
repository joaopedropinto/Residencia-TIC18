#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string teste_caracter(const string &a, const string &b){
  string c;

  for (char a : a) {
        for (char b : b) {
            if (a == b) {
                if (c.find(a) == string::npos) {
                    c += a;
                }
            }
        }
    }

    return c;
}


int main()
{
  string a, b, c;

  cout << "Digite a primeira string: ";
  cin >> a;

  cout << "Digite a segunda string: ";
  cin >> b;
  
  c = teste_caracter(a, b);

  cout << "Os caracteres em comum entre as duas string são: " << c << endl;


  return 0;
}