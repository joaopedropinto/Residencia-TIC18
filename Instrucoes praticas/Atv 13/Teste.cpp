#include <iostream>

using namespace std;

string caracteres_comuns(string &A, string &B)
{
    string C;

    for (int i = 0; i < A.length(); i++)
    {
        char caractere = A[i];
        bool encontrado = false;

        for (int j = 0; j < B.length(); j++)
        {
            if (B[j] == caractere && isalpha(B[j]))
            {
                encontrado = true;
                break;
            }
        }

        if (encontrado && C.find(caractere) == string::npos)
        {
            C += caractere;
        }
    }

    return C;
}

int main()
{
    string A = "Olá tudo bem", B = "Sim, estou", C;

    C = caracteres_comuns(A, B);

    cout << "Caracteres comuns em A e B: " << C << endl;

    return 0;
}