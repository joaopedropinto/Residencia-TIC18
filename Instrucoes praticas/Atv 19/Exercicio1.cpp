#include <iostream>
#include <vector>

using namespace std;

class ItemSet
{
private:
  vector<string> items;

public:
  void inserir(const string &s)
  {
    bool found = false;
    for (const string &item : items)
    {
      if (item == s)
      {
        found = true;
        break;
      }
    }

    if (!found)
    {
      items.push_back(s);
      cout << "Item \"" << s << "\" inserido no conjunto." << endl;
    }
    else
    {
      cout << "Item \"" << s << "\" já existe no conjunto e não pode ser inserido novamente." << endl;
    }
  }

  void excluir(const string &s)
  {

    bool found = false;
    for (int i = 0; i < items.size(); ++i)
    {
      if (items[i] == s)
      {
        items.erase(items.begin() + i);
        cout << "Item \"" << s << "\" excluído do conjunto." << endl;
        found = true;
        break;
      }
    }

    if (!found)
    {
      cout << "Item \"" << s << "\" não encontrado no conjunto." << endl;
    }
  }

  void imprimirItens()
  {
    
    for (const string &item : items)
    {
      cout << item << endl;
    }
  }
};

int main()
{
  ItemSet itens1, itens2;

  cout<< "Inserindo elementos no conjunto itens1: " << endl;
  itens1.inserir("oculos");
  itens1.inserir("lapis");
  itens1.inserir("oculos"); 
  
  cout << "\nInserindo elementos no conjunto itens2: " << endl;
  itens2.inserir("tenis");
  itens2.inserir("borracha");

  cout << "\nImprimindo itens do conjunto itens1:" << endl;
  itens1.imprimirItens();

  cout << "\nImprimindo itens do conjunto itens2:" << endl;
  itens2.imprimirItens();

  cout << "\nExcluindo itens do conjunto itens1:" << endl;
  itens1.excluir("oculos");

  cout << "\nExcluindo itens do conjunto itens2:" << endl;
  itens2.excluir("tenis");
  itens2.excluir("sapato"); 

  cout << "\nImprimindo itens do conjunto itens1:" << endl;
  itens1.imprimirItens();
  cout << "\nImprimindo itens do conjunto itens2:" << endl;
  itens2.imprimirItens();

  return 0;
}
