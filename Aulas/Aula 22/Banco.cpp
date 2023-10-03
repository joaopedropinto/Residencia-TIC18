#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class BancoDeDados{
    public: 
        static void salvarDados(vector<string> dados){

        }

        static vector<string> recuperarDados(){
            
        }
};

using namespace std;


int main(){
    ofstream arquivo_saida;

    arquivo_saida.open("exemplo.txt", ios_base::out);

    if(arquivo_saida.is_open()){
        arquivo_saida << "Escrevendo no arquivo." << endl;
        arquivo_saida << 20 + 30 << endl;
        arquivo_saida.close();
    }else{
        cout << "Erro ao abrir arquivo de saída!" << endl;
        return 1;
    }

    ifstream arquivo_entrada;
    arquivo_entrada.open("exemplo.txt", ios_base::in);
    if(arquivo_entrada.is_open()){
        string linha;
        while(arquivo_entrada.eof() == false){
            getline(arquivo_entrada, linha);
            cout << linha << endl;
        }
        arquivo_entrada.close();

    }else{
        cout << "Erro ao abrir arquivo de entrada!" << endl;
    }

    return 0;
}