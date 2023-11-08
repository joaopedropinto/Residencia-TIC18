#include <iostream>
#include <string>
#include <vector>

class Calculadora
{

public:
    static float soma(float a, float b)
    {
        return a + b;
    }

    static float sub(float a, float b)
    {
        return a - b;
    }

    static float div(float a, float b)
    {
        return a / b;
    }

    static float multi(float a, float b)
    {
        return a * b;
    }
};

using namespace std;

int main()
{
    Calculadora objeto1;
    float x, y, result;
    char opera;

    cout << "Insira dois números: ";
    cin >> x >> y;
    cout << "Selecione a operação a ser realizada (+, -, *, /): ";
    cin >> opera;

    if (opera == '+')
    {
        result = Calculadora::soma(x, y);
    }
    else if (opera == '-')
    {
        result = objeto1.sub(x, y);
    }
    else if (opera == '*')
    {
        result = objeto1.multi(x, y);
    }
    else if (opera == '/')
    {
        result = objeto1.div(x, y);
    }
    else
    {
        cout << "Erro!" << endl;
        return 1;
    }

    cout << "Resultado: " << result << endl;
    return 0;
}