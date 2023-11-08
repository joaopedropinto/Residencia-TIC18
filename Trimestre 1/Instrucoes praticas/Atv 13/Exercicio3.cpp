#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct Produto
{
  string codigo;
  string nome;
  double preco;
};

const int MAX_PRODUTOS = 300;
vector<Produto> produtos;

bool testeProduto(const string &codigo, const string &nome)
{

  for (const Produto &produto : produtos)
  {
    if (produto.codigo == codigo || produto.nome == nome)
    {
      return true;
    }
  }
  return false;
}

void inserirProduto()
{

  if (produtos.size() >= MAX_PRODUTOS)
  {

    cout << "Limite de produtos cadastrados alcançado." << endl;
    return;
  }

  Produto novoProduto;
  regex cod_valido("\\d{13}");
  
  while(true){

    cout << "Digite o código do produto (13 caracteres): ";
    cin >> novoProduto.codigo;
    if(regex_match(novoProduto.codigo,cod_valido)){
      break;
    }else{
      cout << "Código inválido, tente novamente!" << endl;
    }
  }

  cout << "Digite o nome do produto (até 20 caracteres): ";
  cin.ignore();
  getline(cin, novoProduto.nome);


  if (!testeProduto(novoProduto.codigo, novoProduto.nome))
  {

    cout << "Digite o preço do produto (com duas casas decimais): R$ ";
    cin >> novoProduto.preco;
    
    produtos.push_back(novoProduto);
    cout << "Produto cadastrado com sucesso!" << endl;
    return;
  }
  else
  {

    cout << "Produto com mesmo código ou nome já cadastrado. Cadastro não permitido." << endl;
  }
}

void excluirProduto()
{

  string codigoExcluir;

  cout << "Digite o código do produto que deseja excluir: ";
  cin >> codigoExcluir;

  for (auto it = produtos.begin(); it != produtos.end(); ++it)
  {

    if (it->codigo == codigoExcluir)
    {

      it = produtos.erase(it);
      cout << "Produto excluído com sucesso!" << endl;
      return;
    }
    else
    {
      ++it;
    }
  }
}

void listarProdutos()
{

  if (produtos.empty())
  {

    cout << "Nenhum produto foi cadastrado ainda!" << endl;
    return;
  }
  else
  {

    cout << "Lista de produtos cadastrados: " << endl;

    for (const Produto &produto : produtos)
    {

      cout << "Código: " << produto.codigo << " | Nome: " << produto.nome << " | Preço: R$ " << produto.preco << endl;
    }
  }
}

void consultarPreco()
{
  string codigoConsulta;
  cout << "Digite o código do produto para consultar o preço: ";
  cin >> codigoConsulta;

  for (const Produto &produto : produtos)
  {
    if (produto.codigo == codigoConsulta)
    {
      cout << "Produto: " << produto.nome << " | Preço: R$ " << produto.preco << endl;
      return;
    }
  }

  cout << "Produto não encontrado." << endl;
}

int main(void)
{
  int opcao;

  do
  {

    cout << "\nMenu:" << endl;
    cout << "1. Inserir um novo produto" << endl;
    cout << "2. Excluir um produto cadastrado" << endl;
    cout << "3. Listar todos os produtos" << endl;
    cout << "4. Consultar o preço de um produto por código" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
      inserirProduto();
      break;
    case 2:
      excluirProduto();
      break;
    case 3:
      listarProdutos();
      break;
    case 4:   
      consultarPreco();
      break;
    case 0:
      cout << "Encerrando o programa. Obrigado por utilizar nossos serviços!" << endl;
      break;
    default:
      cout << "Opção inválida. Tente novamente." << endl;
    }
  } while (opcao != 0);

  return 0;
}