#include <iostream>
#include <string>
#include <vector>

class Contador
{
private:
    static int contador;

public:
    Contador()
    {
        contador++;
    }

    static int getContador()
    {
        return contador;
    }
};

using namespace std;

int Contador::contador = 0;

int main()
{

    Contador objeto1;
    Contador objeto2;
    Contador objeto3;
    Contador objeto4;

    cout << "Contador: " << Contador::getContador() << endl;
    return 0;
}