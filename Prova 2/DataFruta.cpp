#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Data
{
	int dia, mes, ano;

public:
	static int compara(Data d1, Data d2)
	{
		if (d1.ano < d2.ano)
		{
			return -1;
		}
		else if (d1.ano > d2.ano)
		{
			return 1;
		}
		else
		{
			if (d1.mes < d2.mes)
			{
				return -1;
			}
			else if (d1.mes > d2.mes)
			{
				return 1;
			}
			else
			{
				if (d1.dia < d2.dia)
				{
					return -1;
				}
				else if (d1.dia > d2.dia)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}

	Data(int _dia, int _mes, int _ano)
	{
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}

	string toString() const
	{
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
	static void CriaData(string d1, string d2)
	{
		int diaExtraido, mesExtraido, anoExtraido, resultado;

		sscanf(d1.c_str(), "%d/%d/%d", &diaExtraido, &mesExtraido, &anoExtraido);
		Data novaData1(diaExtraido, mesExtraido, anoExtraido);

		sscanf(d2.c_str(), "%d/%d/%d", &diaExtraido, &mesExtraido, &anoExtraido);
		Data novaData2(diaExtraido, mesExtraido, anoExtraido);

		resultado = Data::compara(novaData1, novaData2);
		if (resultado == -1)
		{
			cout << "A data " << d1 << " é menor que a data " << d2 << "." << endl;
		}
		else if (resultado == 1)
		{
			cout << "A data " << d1 << " é maior que a data " << d2 << "." << endl;
		}
		else if (resultado == 0)
		{
			cout << "As datas " << d1 << " e " << d2 << " são iguais." << endl;
		}
	}
};

class Lista
{
public:
	virtual void entradaDeDados(const string &valor) = 0;
	virtual void mostraMediana() const = 0;
	virtual void mostraMaior() const = 0;
	virtual void mostraMenor() const = 0;
	virtual void listarEmOrdem() const = 0;
	virtual void exibirPrimeirosN(size_t quantidade) const = 0;
	virtual ~Lista() {}
};

class ListaData : public Lista
{
private:
	vector<Data> lista;

	static bool comparaDatas(const Data &data1, const Data &data2)
	{
		return Data::compara(data1, data2) < 0;
	}

public:
	void entradaDeDados(const string &valor) override
	{
		int diaExtraido, mesExtraido, anoExtraido;
		sscanf(valor.c_str(), "%d/%d/%d", &diaExtraido, &mesExtraido, &anoExtraido);
		Data novaData(diaExtraido, mesExtraido, anoExtraido);
		lista.push_back(novaData);
		sort(lista.begin(), lista.end(), comparaDatas);
	}

	void mostraMediana() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			size_t posicaoDoMeio = lista.size() / 2;
			if (lista.size() % 2 == 0)
			{
				cout << lista[posicaoDoMeio - 1].toString();
			}
			else
			{
				cout << lista[posicaoDoMeio].toString();
			}
		}
	}

	void mostraMaior() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			cout << lista.back().toString();
		}
	}

	void mostraMenor() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			cout << lista.front().toString();
		}
	}

	void listarEmOrdem() const override
	{
		for (const Data &data : lista)
		{
			cout << data.toString() << " ";
		}
		cout << endl;
	}

	void exibirPrimeirosN(size_t quantidade) const override
	{
		for (size_t i = 0; i < min(quantidade, lista.size()); i++)
		{
			cout << lista[i].toString() << " ";
		}
		cout << endl;
	}
};

class ListaNomes : public Lista
{
private:
	vector<string> lista;

public:
	void entradaDeDados(const string &valor) override
	{
		lista.push_back(valor);
		sort(lista.begin(), lista.end());
	}
	void mostraMediana() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			size_t posicaoMeio = lista.size() / 2;
			cout << ((lista.size() % 2 == 0) ? lista[posicaoMeio - 1] : lista[posicaoMeio]);
		}
	}
	void mostraMaior() const override
	{
		cout << (lista.empty() ? "" : lista.back());
	}
	void mostraMenor() const override
	{
		cout << (lista.empty() ? "" : lista.front());
	}
	void listarEmOrdem() const override
	{
		for (const string &nome : lista)
		{
			cout << nome << " ";
		}
		cout << endl;
	}
	void exibirPrimeirosN(size_t quantidade) const override
	{
		for (size_t i = 0; i < min(quantidade, lista.size()); ++i)
		{
			cout << lista[i] << " ";
		}
		cout << endl;
	}
};

class ListaSalarios : public Lista
{
private:
	vector<float> lista;

public:
	void entradaDeDados(const string &valor) override
	{

		lista.push_back(stof(valor));
		sort(lista.begin(), lista.end());
	}
	void mostraMediana() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			size_t posicaoMeio = lista.size() / 2;
			cout << ((lista.size() % 2 == 0) ? lista[posicaoMeio - 1] : lista[posicaoMeio]);
		}
	}
	void mostraMaior() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			cout << (*max_element(this->lista.begin(), this->lista.end()));
		}
	}
	void mostraMenor() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			cout << (*min_element(this->lista.begin(), this->lista.end()));
		}
	}
	void listarEmOrdem() const override
	{
		// sort(lista.begin(), lista.end());
		for (const float &salario : lista)
		{
			cout << salario << " ";
		}
		cout << endl;
	}
	void exibirPrimeirosN(size_t quantidade) const override
	{
		for (size_t i = 0; i < min(quantidade, lista.size()); ++i)
		{
			cout << lista[i] << " ";
		}
		cout << endl;
	}
};

class ListaIdades : public Lista
{
private:
	vector<int> lista;

public:
	void entradaDeDados(const string &valor) override
	{
		lista.push_back(stoi(valor));
		sort(lista.begin(), lista.end());
	}
	void mostraMediana() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			size_t posicaoMeio = lista.size() / 2;
			cout << ((lista.size() % 2 == 0) ? lista[posicaoMeio - 1] : lista[posicaoMeio]);
		}
	}
	void mostraMaior() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			cout << (*max_element(this->lista.begin(), this->lista.end()));
		}
	}
	void mostraMenor() const override
	{
		if (lista.empty())
		{
			cout << "";
		}
		else
		{
			cout << (*min_element(this->lista.begin(), this->lista.end()));
		}
	}
	void listarEmOrdem() const override
	{
		// sort(this->lista.begin(), this->lista.end());
		for (const int &idade : lista)
		{
			cout << idade << " ";
		}
		cout << endl;
	}
	void exibirPrimeirosN(size_t quantidade) const override
	{
		for (size_t i = 0; i < min(quantidade, lista.size()); ++i)
		{
			cout << lista[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	vector<Lista *> listaDeListas;

	ListaData listaData;
	ListaNomes listaNomes;
	ListaSalarios listaSalarios;
	ListaIdades listaIdades;
	string d1, d2;

	listaDeListas.push_back(&listaData);
	listaDeListas.push_back(&listaNomes);
	listaDeListas.push_back(&listaSalarios);
	listaDeListas.push_back(&listaIdades);

	int opcao;
	do
	{
		cout << "\nMENU - DataFruta\n";
		cout << "1. Adicionar data\n";
		cout << "2. Adicionar nome\n";
		cout << "3. Adicionar salario\n";
		cout << "4. Adicionar idade\n";
		cout << "5. Listar dados em ordem\n";
		cout << "6. Exibir primeiros N elementos\n";
		cout << "7. Exibir mediana, maior e menor valor de cada lista\n";
		cout << "8. Testar datas\n";
		cout << "9. Sair\n";
		cout << "Digite sua opção: ";
		cin >> opcao;
		cin.ignore();

		string valor;
		size_t quantidade;
		switch (opcao)
		{
		case 1:
			cout << "Digite a data: ";
			getline(cin, valor);
			listaData.entradaDeDados(valor);
			break;
		case 2:
			cout << "Digite o nome: ";
			getline(cin, valor);
			listaNomes.entradaDeDados(valor);
			break;
		case 3:
			cout << "Digite o salario: ";
			getline(cin, valor);
			listaSalarios.entradaDeDados(valor);
			break;
		case 4:
			cout << "Digite a idade: ";
			getline(cin, valor);
			listaIdades.entradaDeDados(valor);
			break;
		case 5:
			for (Lista *lista : listaDeListas)
			{
				lista->listarEmOrdem();
			}
			break;
		case 6:
			cout << "Digite o número de elementos para exibir: ";
			cin >> quantidade;
			cin.ignore();
			for (Lista *lista : listaDeListas)
			{
				lista->exibirPrimeirosN(quantidade);
			}
			break;
		case 7:
			cout << "Exibindo mediana, maior e menor valor de cada lista:\n\n";
			for (Lista *l : listaDeListas)
			{
				cout << "Mediana: ";
				l->mostraMediana();
				cout << "\nMaior: ";
				l->mostraMaior();
				cout << "\nMenor: ";
				l->mostraMenor();
				cout << "\n-------------------\n";
			}
			break;
		case 8:
			cout << "Insira a primeira data: ";
			cin >> d1;
			cout << "Insira a segunda data: ";
			cin >> d2;
			Data::CriaData(d1, d2);
			break;
		case 9:
			cout << "Saindo...\n";
			break;
		default:
			cout << "Opção inválida!\n";
		}

	} while (opcao != 9);

	return 0;
}
