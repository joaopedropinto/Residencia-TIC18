#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Cliente;
class Pacote;
class Dependente;
class Evento;
class Cliente
{
private:
  string nome;
  string cpf;
  vector<Pacote *> pacotes;

public:
  Cliente(string nome, string cpf)
  {
    this->cpf = cpf;
    this->nome = nome;
    this->pacotes = {};
  }

  void setPacotes(Pacote *pacote)
  {
    this->pacotes.push_back(pacote);
  }
  vector<Pacote *> &getPacotes()
  {
    return pacotes;
  }
  string getNome()
  {
    return nome;
  }

  void setNome(string nome)
  {
    this->nome = nome;
  }

  string getCPF()
  {
    return cpf;
  }

  void setCPF(string cpf)
  {
    this->cpf = cpf;
  }
};

class Dependente
{
private:
  string nome;
  Cliente *dependenteDe;

public:
  string getNome()
  {
    return nome;
  }

  void setNome(string nome)
  {
    this->nome = nome;
  }

  Cliente getDependente()
  {
    return *dependenteDe;
  }

  void setDependente(Cliente *dependenteDe)
  {
    this->dependenteDe = dependenteDe;
  }
  string getCpfResponsavel()
  {
    dependenteDe->getCPF();
  }
};

class Evento
{
private:
  string nome;
  double duracao;

public:
  Evento(string nome, double duracao)
  {
    this->nome = nome;
    this->duracao = duracao;
  }

  string getNome()
  {
    return nome;
  }

  void setNome(string nome)
  {
    this->nome = nome;
  }
  double getDuracao()
  {
    return duracao;
  }

  void setDuracao(double duracao)
  {
    this->duracao = duracao;
  }
};

class Pacote
{
private:
  string nome;
  vector<Evento *> eventos;
  vector<Cliente *> clientes;

public:
  Pacote()
  {
  }

  string getNome()
  {
    return nome;
  }

  vector<Evento *> getEventos()
  {
    return eventos;
  }

  vector<Cliente *> getClientes()
  {
    return clientes;
  }
  void setClientes(Cliente *cliente)
  {
    this->clientes.push_back(cliente);
  }
  void setNome(string nome)
  {
    this->nome = nome;
    this->clientes = {};
  }

  void adicionarEvento(Evento *evento)
  {
    eventos.push_back(evento);
  }
};

class Roteiro : public Evento
{

public:
  Roteiro(string nome, double duracao) : Evento(nome, duracao)
  {
  }
};

class Deslocamento : public Evento
{

public:
  Deslocamento(string nome, double duracao) : Evento(nome, duracao)
  {
  }
};

class Pernoite : public Evento
{

public:
  Pernoite(string nome, double duracao) : Evento(nome, duracao)
  {
  }
};

class SistemaTuristico
{

public:
  static Evento cadastrarEvento()
  {

    int opcao = 0;

    while (true)
    {
      cout << "Selecione o tipo do evento:\n"
           << "1 - Roteiro\n"
           << "2 - Deslocamento\n"
           << "3 - Pernoite\n"
           << "4 - Sair\n";
      cin >> opcao;
      cin.ignore();

      string nome;
      double duracao;

      switch (opcao)
      {
      case 1:
        cout << "Digite o nome do Roteiro: " << endl;
        getline(cin, nome);
        cout << "Digite a duração do Roteiro: " << endl;
        cin >> duracao;
        return Roteiro(nome, duracao);
        break;

      case 2:
        cout << "Digite o nome do Deslocamento: ";
        getline(cin, nome);
        cout << "Digite a duração do Deslocamento: ";
        cin >> duracao;
        return Deslocamento(nome, duracao);
        break;

      case 3:
        cout << "Digite o nome da Pernoite: ";
        getline(cin, nome);
        cout << "Digite a duração da Pernoite: ";
        cin >> duracao;

        return Pernoite(nome, duracao);
        break;

      case 4:
        cout << "Saindo do menu.\n";
        break;

      default:
        cout << "Opção inválida. Tente novamente.\n";
        break;
      }
    }
  }

  static Pacote criarPacote(vector<Evento> eventos)
  {
    string nome, evento;
    Pacote pacote;
    char opcao;

    cout << "Defina o nome do Pacote: " << endl;
    getline(cin, nome);
    pacote.setNome(nome);
    listarEventos(eventos);
    do
    {
      cout << "Digite o Evento que deseja adicionar ao Pacote ou '0' para sair: " << endl;
      getline(cin, evento);

      if (evento == "0")
      {
        break; // O usuário escolheu sair
      }

      bool eventoEncontrado = false;
      for (Evento &n : eventos)
      {
        if (evento == n.getNome())
        {
          pacote.adicionarEvento(&n);
          eventoEncontrado = true;
          break; // Evento encontrado, saia do loop
        }
      }

      if (!eventoEncontrado)
      {
        cout << "Evento não encontrado. Tente novamente." << endl;
      }

      cout << "Deseja adicionar outro evento? (S/N): ";
      cin >> opcao;
      cin.ignore();
    } while (opcao == 'S' || opcao == 's');

    return pacote;
  }

  static Cliente criarCliente()
  {
    string nome, cpf;

    cout << "Digite o CPF do cliente: " << endl;
    cin >> cpf;
    cout << "Digite o nome do cliente: " << endl;
    cin.ignore();
    getline(cin, nome);

    return Cliente(nome, cpf);
  }

  static Dependente criarDependente(vector<Cliente> clientes, vector<Dependente> &dependentes)
  {
    char opcao;
    string nomeDependente, nomeCliente;
    Dependente dependente;

    cout << "Digite o nome do responsavel: " << endl;
    getline(cin, nomeCliente);
    do
    {
      bool clienteEncontrado = false;
      for (Cliente n : clientes)
      {
        if (nomeCliente == n.getNome())
        {
          cout << "Digite o nome do dependente: " << endl;
          getline(cin, nomeDependente);
          dependente.setNome(nomeDependente);
          dependente.setDependente(&n);
          clienteEncontrado = true;
          dependentes.push_back(dependente);
        }
      }
      if (!clienteEncontrado)
      {
        cout << "Cliente não encontrado. Tente novamente." << endl;
        break;
      }

      cout << "Deseja adicionar outro dependente? (S/N): ";
      cin >> opcao;
      cin.ignore();
    } while (opcao == 'S' || opcao == 's');
  }

  static void venderPacote(vector<Cliente> &clientes, vector<Pacote> &pacotes)
  {
    string cpf_cliente;
    string nome_pacote;
    cout << "Digite o CPF do cliente: ";
    cin >> cpf_cliente;
    cin.ignore();
    cout << "Digite o nome do pacote a ser vendido: ";
    getline(cin, nome_pacote);

    // Encontre o cliente com base no CPF
    for (Cliente &cliente : clientes)
    {
      if (cliente.getCPF() == cpf_cliente)
      {
        // Encontre o pacote com base no nome
        for (Pacote &pacote : pacotes)
        {
          if (pacote.getNome() == nome_pacote)
          {
            cliente.setPacotes(&pacote);
            pacote.setClientes(&cliente);
            cout << "Pacote '" << pacote.getNome() << "' vendido com sucesso para o cliente '" << cliente.getNome() << "'." << endl;
            return;
          }
        }
        cout << "Pacote não encontrado." << endl;
        return;
      }
    }
    cout << "Cliente não encontrado." << endl;
  }

  static void listarClientes(vector<Cliente> &clientes, vector<Dependente> &dependentes)
  {
    cout << "Lista de clientes:" << endl;
    for (Cliente &cliente : clientes)
    {
      cout << "Nome: " << cliente.getNome() << ", CPF: " << cliente.getCPF() << endl;
      for (Dependente &dependente : dependentes)
      {
        if (dependente.getDependente().getCPF() == cliente.getCPF())
        {
          cout << "Dependente: " << dependente.getNome() << endl;
        }
      }
    }
  }

  static void listarPacotes(vector<Pacote> &pacotes)
  {
    cout << "Lista de pacotes:" << endl;
    for (Pacote &pacote : pacotes)
    {
      cout << "Nome do pacote: " << pacote.getNome() << endl;
      cout << "Eventos do pacote:" << endl;
      for (Evento *evento : pacote.getEventos())
      {
        cout << "Nome do evento: " << evento->getNome() << ", Duração: " << evento->getDuracao() << " horas" << endl;
      }
    }
  }

  static void consultarPacotesCliente(vector<Cliente> &clientes)
  {
    string cpf_cliente;
    cout << "Digite o CPF do cliente: ";
    cin >> cpf_cliente;
    bool clienteEncontrado = false;
    for (Cliente &cliente : clientes)
    {
      if (cliente.getCPF() == cpf_cliente)
      {
        clienteEncontrado = true;
        if (!cliente.getPacotes().empty())
        {
          cout << "Pacotes contratados por " << cliente.getNome() << ":" << endl;
          for (Pacote *pacote : cliente.getPacotes())
          {
            cout << "Nome do Pacote: " << pacote->getNome() << endl;
            cout << "Eventos no Pacote:" << endl;
            for (Evento *evento : pacote->getEventos())
            {
              cout << "Nome do Evento: " << evento->getNome() << ", Duração Prevista: " << evento->getDuracao() << " horas" << endl;
            }
            cout << "----------------------" << endl;
          }
        }
        else
        {
          cout << "O cliente '" << cliente.getNome() << "' não contratou nenhum pacote." << endl;
        }
        break;
      }
    }
    if (!clienteEncontrado)
    {
      cout << "Cliente com CPF '" << cpf_cliente << "' não encontrado." << endl;
    }
  }

  static void consultarClientesPacote(vector<Pacote> &pacotes)
  {
    string nome_pacote;
    cout << "Digite o nome do pacote: ";
    getline(cin, nome_pacote);
    bool pacoteEncontrado = false;
    for (Pacote &pacote : pacotes)
    {
      if (pacote.getNome() == nome_pacote)
      {
        pacoteEncontrado = true;
        if (!pacote.getClientes().empty())
        {
          cout << "Clientes que contrataram o pacote " << pacote.getNome() << ":" << endl;
          for (Cliente *cliente : pacote.getClientes())
          {
            cout << cliente->getNome() << endl;
          }
        }
        else
        {
          cout << "O pacote '" << pacote.getNome() << "' não foi contratado por nenhum cliente." << endl;
        }
        break;
      }
    }
    if (!pacoteEncontrado)
    {
      cout << "Pacote com nome " << nome_pacote << "' não encontrado." << endl;
    }
  }
  static void listarEventos(vector<Evento> eventos)
  {

    cout << "Evento cadastrados: " << endl;
    for (Evento n : eventos)
    {
      cout << "Nome do evento: " << n.getNome() << endl;
    }
  }
};

int main()
{
  vector<Evento> eventos;
  vector<Pacote> pacotes;
  vector<Cliente> clientes;
  vector<Dependente> dependentes;

  eventos.push_back(Roteiro("Roteiro 1", 2.0));
  eventos.push_back(Deslocamento("Deslocamento 1", 3));
  eventos.push_back(Pernoite("Pernoite 1", 1));
  while (true)
  {
    cout << "Menu:" << endl;
    cout << "1. Cadastrar evento" << endl;
    cout << "2. Criar pacote" << endl;
    cout << "3. Criar cliente" << endl;
    cout << "4. Criar dependente" << endl;
    cout << "5. Vender pacote a cliente" << endl;
    cout << "6. Listar clientes" << endl;
    cout << "7. Listar pacotes" << endl;
    cout << "8. Listar eventos" << endl;
    cout << "9. Consultar pacotes de um cliente" << endl;
    cout << "10. Consultar clientes de um pacote" << endl;
    cout << "11. Sair" << endl;

    int escolha;
    cout << "Escolha uma opção: ";
    cin >> escolha;
    cin.ignore();
    switch (escolha)
    {
    case 1:
      eventos.push_back(SistemaTuristico::cadastrarEvento());
      break;

    case 2:
      pacotes.push_back(SistemaTuristico::criarPacote(eventos));
      break;

    case 3:
      clientes.push_back(SistemaTuristico::criarCliente());
      break;

    case 4:
      SistemaTuristico::criarDependente(clientes, dependentes);
      break;

    case 5:
      SistemaTuristico::venderPacote(clientes, pacotes);
      break;

    case 6:
      SistemaTuristico::listarClientes(clientes, dependentes);
      break;

    case 7:
      SistemaTuristico::listarPacotes(pacotes);
      break;

    case 8:
      SistemaTuristico::listarEventos(eventos);
      break;

    case 9:
      SistemaTuristico::consultarPacotesCliente(clientes);
      break;

    case 10:
      SistemaTuristico::consultarClientesPacote(pacotes);
      break;

    case 11:
      return 0;

    default:
      cout << "Opção inválida." << endl;
    }
  }
  return 0;
}