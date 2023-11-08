#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Data{
    int dia, mes, ano;

    bool setData(string data){

        regex data_regex(R"((\d{2})/(\d{2})/(\d{4}))");
        smatch match;

        if (regex_match(data, match, data_regex)){

            dia = stoi(match[1]);
            mes = stoi(match[2]);
            ano = stoi(match[3]);
        
            if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0){

                int dia_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

                if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
                    dia_mes[2] = 29;
                }
                if (dia <= dia_mes[mes]){
                    return true;
                }
            }
        }
        
        return false;
    }

    void printData(){

        cout << to_string(dia) << '/' << to_string(mes) << '/' << to_string(ano) << endl;
    }
   

};

int main(){
    Data data;
    string datatxt;

    cout << "Insira a data (dd/mm/aaaa): ";
    cin >> datatxt;
    
    if(data.setData(datatxt)){

        data.printData();
        
    }else{

        cout << "Data inválida." << endl;
    }

    

    return 0;
}