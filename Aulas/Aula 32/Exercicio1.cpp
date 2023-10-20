#include <iostream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

// Classe abstrata para representar uma conta 
class Conta {

    protected: 
        string num_Conta;
        string nome_Correntista;
        double saldo;
        vector<Transacao> transacoes;

    public:
        virtual ~Conta() {
        }

        bool deposito(double valor) {
            if (valor > 0) {
                saldo += valor;
                return true;    
            }else{
                return false;
            }
        }
        virtual bool retirada(double valor);
        virtual void imprime_extrato() const = 0;
};

class Conta_Corrente_Comum : public Conta {
    public:
        bool retirada(double valor) override {
            if( saldo - valor >= 0){
                saldo -= valor;
                return true;
            }else{
                return false;
            }
        }
        void imprime_extrato() const override {
            cout << "Saldo da conta corrente: " << saldo << endl;
            cout << "Nome: " << nome_Correntista << endl;
            cout << "Número da conta: " << num_Conta << endl;
        }
};

class Conta_Poupança : public Conta {

    private:
        string aniversario_conta;
        
    public:

        bool retirada(double valor) override {
            if( saldo - valor >= 0){
                saldo -= valor;
                return true;
            }else{
                return false;
            }
        }
        void imprime_extrato() const override {
            cout << "Saldo da conta corrente: " << saldo << endl;
            cout << "Nome: " << nome_Correntista << endl;
            cout << "Número da conta: " << num_Conta << endl;
            cout << "Dia aniversário: " << aniversario_conta << endl;
        }
    
};

class Conta_Corrente_Limite : public Conta {
    
    private:
        double limite;

    public:
        bool retirada(double valor) override {
            if( saldo - valor <= limite){
                saldo -= valor;
                return true;
            }else{
                return false;
            }
        }
        void imprime_extrato() const override {
            cout << "Saldo da conta corrente: " << saldo << endl;
            cout << "Nome: " << nome_Correntista << endl;
            cout << "Número da conta: " << num_Conta << endl;
            cout << "Limite: " << limite << endl;
        }
};

class Transacao {
    private:
        string data, descricao;
        double valor_trans;
};