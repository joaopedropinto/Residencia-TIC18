#include <iostream>

using namespace std;

int main(void){

    char letra = 'a'; // letra é uma variável de tipo char

    //a cada caracteres corresponde um valor inteira 
    cout << "A letra " << letra << " corresponde ao valor " << int(letra) << endl;

    cout<<"0 tipo char ocupa " << sizeof(char) << " bytes na memória.\n"; 
    letra = -120; //o tipo char pode armazenar valores negativos

    cout<<"E pode armazenar valores negativos ("<< int(letra); 
    
    letra = 120;

    cout<<" ) e positivos ("<< int(letra) << ")." << endl; 
    unsigned char letra2 = 120; // o tipo unsigned char so armazena valores positivos

    signed char letra3 = -120; // aqui o tipo signed char equivale ao tipo char 
    cout<<"0 tipo unsigned char ocupa " << sizeof(letra2) << " bytes na memória.\n"; 

    cout << "0 tipo signed char ocupa " << sizeof(letra3) << " bytes na memória.\n"; 


    wchar_t letra4 = L'c'; // o tipo wchar_t é usado para armazenar caracteres unicode 
    cout << "0 tipo wchar_t ocupa = " << sizeof(letra4) << " bytes na memória.\n"; 


    char16_t letra5 = L'c'; // o tipo char16_t é usado para armazenar caracteres unicode 

    cout << "0 tipo char16 t ocupa " << sizeof(letra5) << " bytes na memória.\n"; 
    char32_t letra6= L'c'; // o tipo char32_t é usado para armazenar caracteres unicode 
    cout<<"O tipo char32_t ocupa " << sizeof(letra6) << " bytes na memória.\n"; 
    return 0;

}