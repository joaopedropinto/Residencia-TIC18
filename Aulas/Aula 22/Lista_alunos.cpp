#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Aluno {

    private:

        string nome;
        string email;
        int nota1;
        int nota2; 

    public:

        void setNome(string _nome) {
            nome = _nome;
        }
        void setEmail(string _email) {
            email = _email;
        }
        void setNota1(int _nota1) {
            nota1 = _nota1;
        }
        void setNota2(int _nota2) {
            nota2 = _nota2;
        }
        string getNome() {
            return nome;
        }
        string getEmail() {
            return email;
        }
        int getNota1() {
            return nota1;
        }
        int getNota2() {
            return nota2;
        }

        static void CriaAluno(vector<Aluno> &_aluno) {

            Aluno aluno;
            int nota1, nota2;
            string nome, email;

            cout << "Insira o nome do aluno: ";
            cin.ignore();
            getline(cin, nome);
            aluno.setNome(nome);
            
            cout << "Insira o email do aluno: ";
            cin >> email;
            aluno.setEmail(email);

            cout << "Insira a nota 1 do aluno: ";
            cin >> nota1;
            aluno.setNota1(nota1);

            cout << "Insira a nota 2 do aluno: ";
            cin >> nota2;
            aluno.setNota2(nota2);

            _aluno.push_back(aluno);
            
        }
        

};

class BancoDeDados {

    public:

        static void SalvarDados(vector<Aluno> &_aluno) {

            ofstream arquivo_saida;
            arquivo_saida.open("alunos.txt", ios_base::out);

            if(arquivo_saida.is_open()) {

                for(auto it : _aluno)
                arquivo_saida << it.getNome() << "," << it.getEmail() << ","
                <<  it.getNota1() << "," << it.getNota2() << endl;
                arquivo_saida.close();

            } else {

                cout << "Erro ao abrir arquivo de saída!" << endl;
            }
        }

        static void RecuperarDados(vector<Aluno> &_aluno) {
            Aluno aluno;
            string linha, objeto;
            vector<string> strings;
            ifstream arquivo_entrada;
            arquivo_entrada.open("alunos.txt", ios_base::in);

            if(arquivo_entrada.is_open()) {
                
                while(getline(arquivo_entrada, linha, '\n')) {
                    
                    istringstream ss(linha);
                    while(getline(ss, objeto , ',')) {
                        strings.push_back(objeto);
                    }

                    aluno.setNome(strings[0]);
                    
                }
            }
        }
        
};


int main() {

    vector<Aluno> aluno;
    vector<string> dados;
    char opcao;
    
    BancoDeDados::RecuperarDados(aluno);

    while(true) {

        cout << "Deseja inserir um aluno? (s/n)" << endl;
        cin >> opcao;

        if (opcao == 's'){
            Aluno::CriaAluno(aluno);
        } else {
            cout << "Inserção de alunos encerrada!" << endl;
            BancoDeDados::SalvarDados(aluno);
            break;
        }
    }
    
}