#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Passageiro {
    string nome;
    string cpf;
    string idade;
};

struct Passagem {
    string data;
    string origem;
    string destino;
    Passageiro passageiro;
};

struct Viagem {
    Passagem passagem[40];
};

int main(void){
    int qtd_passageiros;
    Viagem viagens_ida[5][30];
    Viagem viagens_volta[5][30];
    srand(time(NULL));


    Passagem passagem;
    
    for(int k = 0; k < 1; k++){
        //Ida
        cout << "Viagens do dia: " << k+1 << endl;
        for(int i = 0; i < 5; i++){
            qtd_passageiros = rand() % 40 + 10;
            cout << "Viagens do horario: " << i+1 << endl;
            for(int j = 0; j < qtd_passageiros; j++){
                
                int assento;
                assento = rand() % 39;
                cout << "assento: " << assento << endl;

                if(viagens_ida[i][k].passagem[assento].data == ""){
                    viagens_ida[i][k].passagem[assento].passageiro.nome = "Passageiro " + to_string(j);
                    viagens_ida[i][k].passagem[assento].passageiro.cpf = "0710901234" + to_string(j);
                    viagens_ida[i][k].passagem[assento].passageiro.idade = to_string(85 + j);
                    viagens_ida[i][k].passagem[assento].data = "25/09/2023";
                    viagens_ida[i][k].passagem[assento].destino = "sp";
                    viagens_ida[i][k].passagem[assento].origem = "rj";

                    cout << viagens_ida[i][k].passagem[assento].passageiro.nome << endl;
                    cout << viagens_ida[i][k].passagem[assento].passageiro.cpf << endl;
                    cout << viagens_ida[i][k].passagem[assento].passageiro.idade << endl;
                    cout << viagens_ida[i][k].passagem[assento].data << endl;
                    cout << viagens_ida[i][k].passagem[assento].destino << endl;
                    cout << viagens_ida[i][k].passagem[assento].origem << endl;
                    cout << "j: " << j << endl;
                }else{
                    cout << "Assento ocupado!" << endl;
                }
            }
        }
    }


    return 0;
}