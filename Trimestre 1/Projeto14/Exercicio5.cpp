#include <iostream>
#include <string>

using namespace std;

// Struct para representar uma CPU (Processador)
struct CPU {
    string marca;
    int nucleos;
    double frequencia; // Frequencia em GHz
};

// Struct para representar uma Memoria RAM
struct RAM {
    string tipo;
    int capacidade; // Capacidade em GB
};

// Struct para representar um dispositivo de Armazenamento (HD/SSD)
struct Armazenamento {
    string tipo;
    int capacidade; // Capacidade em GB
};

// Struct para representar uma GPU (Placa de Video)
struct GPU {
    string marca;
    int memoria; // Memoria em GB
};

// Struct para representar um Sistema Operacional
struct SistemaOperacional {
    string nome;
    string versao;
};

// Struct principal que combina todas as anteriores para formar um Computador
struct Computador {
    CPU processador;
    RAM memoria;
    Armazenamento disco;
    GPU placaDeVideo;
    SistemaOperacional sistema;
};

int main() {
    // Definindo e inicializando um computador
    Computador meuPc = {
        { "Intel", 8, 3.5 },            // Informacoes da CPU
        { "DDR4", 16 },                 // Informacoes da RAM
        { "SSD", 500 },                 // Informacoes de Armazenamento
        { "NVIDIA", 6 },                // Informacoes da GPU
        { "Windows", "11 Pro" }         // Informacoes do Sistema Operacional
    };

    // Exibindo informacoes sobre o computador
    cout << "Informacoes do Computador:\n";
    cout << "Processador: " << meuPc.processador.marca << ", Nucleos: " << meuPc.processador.nucleos << ", Frequencia: " << meuPc.processador.frequencia << " GHz" << endl;
    cout << "Memoria RAM: " << meuPc.memoria.tipo << ", Capacidade: " << meuPc.memoria.capacidade << " GB" << endl;
    cout << "Armazenamento: " << meuPc.disco.tipo << ", Capacidade: " << meuPc.disco.capacidade << " GB" << endl;
    cout << "Placa de Video: " << meuPc.placaDeVideo.marca << ", Memoria: " << meuPc.placaDeVideo.memoria << " GB" << endl;
    cout << "Sistema Operacional: " << meuPc.sistema.nome << ", Versao: " << meuPc.sistema.versao << endl;

    return 0;
}
