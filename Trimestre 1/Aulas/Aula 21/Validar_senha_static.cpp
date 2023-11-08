#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Senha
{

public:
    static bool ValidadorSenha(string senha)
    {

        regex senha_valida("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9]).{8,}$");

        if (regex_match(senha, senha_valida))
        {
            return true;
        }
        return false;
    }
};

int main()
{

    string senha;
    bool result;

    cout << "Insira uma senha: ";
    cin >> senha;

    result = Senha::ValidadorSenha(senha);
    if (result)
    {
        cout << "Senha válida!" << endl;
        return 0;
    }
    else
    {
        cout << "Senha inválda!" << endl;
        return 1;
    }
}