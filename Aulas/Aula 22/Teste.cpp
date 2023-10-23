#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Aluno
{
public:
  string nome;
  string email;
  double nota1;
  double nota2;

  Aluno(const string &nome, const string &email, double nota1, double nota2)
      : nome(nome), email(email), nota1(nota1), nota2(nota2) {}

  double calcularMedia() const
  {
    return (nota1 + nota2) / 2.0;
  }

  void mostrarDados() const
  {
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Nota 1: " << nota1 << endl;
    cout << "Nota 2: " << nota2 << endl;
    cout << "Média: " << calcularMedia() << endl;
  }
};

class BancoDeDados
{
public:
  vector<Aluno> alunos;

  void adicionarAluno(const Aluno &aluno)
  {
    alunos.push_back(aluno);
    cout << "Aluno adicionado." << endl;
  }

  void alterarAluno(const string &nome, const Aluno &novoAluno)
  {
    for (Aluno &aluno : alunos)
    {
      if (aluno.nome == nome)
      {
        aluno = novoAluno;
        cout << "Aluno alterado com sucesso." << endl;
        return;
      }
    }
    cout << "Aluno não encontrado." << endl;
  }

  void excluirAluno(const string &nome)
  {
    auto it = remove_if(alunos.begin(), alunos.end(),
                        [nome](const Aluno &aluno)
                        { return aluno.nome == nome; });
    if (it != alunos.end())
    {
      cout << "Aluno excluído com sucesso." << endl;
      alunos.erase(it, alunos.end());
    }
    else
    {
      cout << "Aluno não encontrado." << endl;
    }
  }

  void mostrarAlunos() const
  {
    cout << "\nAlunos cadastrados: \n"
         << endl;
    for (const Aluno &aluno : alunos)
    {
      aluno.mostrarDados();
      cout << "------------------------" << endl;
    }
  }

  void salvarDados(const string &nomeArquivo)
  {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open())
    {
      for (const Aluno &aluno : alunos)
      {
        arquivo << aluno.nome << ',' << aluno.email << ',' << aluno.nota1 << ',' << aluno.nota2 << endl;
      }
      arquivo.close();
      cout << "Dados salvos com sucesso." << endl;
    }
    else
    {
      cout << "Erro ao abrir o arquivo para salvar os dados." << endl;
    }
  }

  void carregarDados(const string &nomeArquivo)
  {
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open())
    {
      alunos.clear(); // Limpa os alunos existentes
      string linha;
      while (getline(arquivo, linha))
      {
        string nome, email;
        double nota1, nota2;
        size_t pos = 0;
        pos = linha.find(',');
        nome = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        pos = linha.find(',');
        email = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        pos = linha.find(',');
        nota1 = stod(linha.substr(0, pos));
        linha.erase(0, pos + 1);
        nota2 = stod(linha);
        Aluno aluno(nome, email, nota1, nota2);
        alunos.push_back(aluno);
      }
      arquivo.close();
      cout << "Dados carregados com sucesso." << endl;
    }
    else
    {
      cout << "Erro ao abrir o arquivo para carregar os dados." << endl;
    }
  }
};

int main()
{
  BancoDeDados banco;
  string nomeArquivo = "dados_alunos.txt";

  banco.carregarDados(nomeArquivo);

  int opcao;
  do
  {
    cout << "\n==Banco de Dados de Alunos==\n"
         << endl;
    cout << "1. Adicionar Aluno" << endl;
    cout << "2. Alterar Aluno" << endl;
    cout << "3. Excluir Aluno" << endl;
    cout << "4. Mostrar Alunos" << endl;
    cout << "5. Sair" << endl;
    cout << "Escolha uma opção:";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
    {
      string nome, email;
      double nota1, nota2;
      cout << "Nome: ";
      cin.ignore();
      getline(cin, nome);
      cout << "Email: ";
      cin >> email;
      cout << "Nota 1: ";
      cin >> nota1;
      cout << "Nota 2: ";
      cin >> nota2;
      Aluno novoAluno(nome, email, nota1, nota2);
      banco.adicionarAluno(novoAluno);
      banco.salvarDados(nomeArquivo);
      break;
    }
    case 2:
    {
      string nome;
      cout << "Nome do Aluno a ser alterado: ";
      cin >> nome;
      string novoNome, novoEmail;
      double novaNota1, novaNota2;
      cout << "Novo Nome: ";
      cin.ignore();
      getline(cin, novoNome);
      cout << "Novo Email: ";
      cin >> novoEmail;
      cout << "Nova Nota 1: ";
      cin >> novaNota1;
      cout << "Nova Nota 2: ";
      cin >> novaNota2;
      Aluno novoAluno(novoNome, novoEmail, novaNota1, novaNota2);
      banco.alterarAluno(nome, novoAluno);
      banco.salvarDados(nomeArquivo);
      break;
    }
    case 3:
    {
      string nome;
      cout << "Nome do Aluno a ser excluído: ";
      cin.ignore();
      getline(cin, nome);
      banco.excluirAluno(nome);
      banco.salvarDados(nomeArquivo);
      break;
    }
    case 4:
    {
      banco.mostrarAlunos();
      break;
    }
    case 5:
    {
      cout << "Saindo..." << endl;
      break;
    }
    default:
    {
      cout << "Opção inválida. Tente novamente." << endl;
    }
    }
  } while (opcao != 5);

  return 0;
}
