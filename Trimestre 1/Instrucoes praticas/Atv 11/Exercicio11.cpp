#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string codificar(const string &texto_origin){
  string codi = texto_origin;

  for(char &c : codi){
    if(isalpha(c)){
      if(c == 'Z'){
        c = 'A';
      }else if(c == 'z'){
        c = 'a';
      }else{
        c++;
      }
    }
  }
  return codi;
}

string decodificar(const string &texto_origin){
  string decodi = texto_origin;

  for(char &c : decodi){
    if(isalpha(c)){
      if(c == 'A'){
        c = 'Z';
      }else if(c == 'a'){
        c = 'z';
      }else{
        c--;
      }
    }
  }
  return decodi;
}


int main()
{
  string texto_origin, texto_codi, texto_decodi;

  cout << "Insira o texto que será codificado: ";
  getline(cin, texto_origin);
  cout << "Texto original: " << texto_origin << endl;

  texto_codi = codificar(texto_origin);
  cout << "Texto codificado: " << texto_codi << endl;

  texto_decodi = decodificar(texto_codi);
  cout << "Texto decodificado: " << texto_decodi<< endl;


  return 0;
}