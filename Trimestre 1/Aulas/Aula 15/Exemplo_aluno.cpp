#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct para representar as notas de um aluno
struct Notas {
    float teoria1;
    float teoria2;
    float pratica1;
    float pratica2;
};

// Struct para representar um aluno
struct Aluno {
    int matricula;
    string nome;
    struct Notas notas;
    float media;
};

// Struct para representar a turma
struct Turma {
    vector<Aluno> alunos;
};

// Struct para representar as estatísticas da turma
struct EstatisticasTurma {
    float mediaTurma;
    int numAprovados;
    int numReprovados;
};

// Função para calcular a média de um aluno
float calcularMedia(Aluno aluno) {
    return (aluno.notas.teoria1 * 2 + aluno.notas.teoria2 * 2 + aluno.notas.pratica1 + aluno.notas.pratica2) / 6.0;
}

// Função para listar os alunos aprovados e reprovados
EstatisticasTurma listarAprovadosReprovados(Turma turma) {
    EstatisticasTurma estatisticas;
    estatisticas.mediaTurma = 0.0;
    estatisticas.numAprovados = 0;
    estatisticas.numReprovados = 0;

    cout << "\nAlunos Aprovados:" << endl;
    cout << "Matricula | Nome | Notas | Media" << endl;
    for (auto& aluno : turma.alunos) {
        aluno.media = calcularMedia(aluno);
        estatisticas.mediaTurma += aluno.media;

        if (aluno.media >= 7.0) {
            cout << aluno.matricula << " | " << aluno.nome << " | " << aluno.notas.teoria1 << " "
                 << aluno.notas.teoria2 << " " << aluno.notas.pratica1 << " " << aluno.notas.pratica2 << " | "
                 << aluno.media << endl;
            estatisticas.numAprovados++;
        } else {
            cout << aluno.matricula << " | " << aluno.nome << " | " << aluno.notas.teoria1 << " "
                 << aluno.notas.teoria2 << " " << aluno.notas.pratica1 << " " << aluno.notas.pratica2 << " | "
                 << aluno.media << " (Reprovado)" << endl;
            estatisticas.numReprovados++;
        }
    }

    estatisticas.mediaTurma /= turma.alunos.size();

    return estatisticas;
}

// Função para listar alunos acima da média da turma
void listarAcimaMediaTurma(Turma turma, float mediaTurma) {
    cout << "\nAlunos Acima da Media da Turma:" << endl;
    cout << "Matricula | Nome | Notas | Media" << endl;
    for (const auto& aluno : turma.alunos) {
        if (aluno.media > mediaTurma) {
            cout << aluno.matricula << " | " << aluno.nome << " | " << aluno.notas.teoria1 << " "
                 << aluno.notas.teoria2 << " " << aluno.notas.pratica1 << " " << aluno.notas.pratica2 << " | "
                 << aluno.media << endl;
        }
    }
}

int main() {
    Turma turma;

    cout << "Informe o numero de alunos na turma: ";
    int numAlunos;
    cin >> numAlunos;

    turma.alunos.resize(numAlunos);

    // Preencher informações dos alunos
    for (int i = 0; i < numAlunos; i++) {
        cout << "Informe a matricula do aluno " << i + 1 << ": ";
        cin >> turma.alunos[i].matricula;
        cout << "Informe o nome do aluno " << i + 1 << ": ";
        cin >> turma.alunos[i].nome;
        cout << "Informe as notas das duas provas teoricas do aluno " << i + 1 << ": ";
        cin >> turma.alunos[i].notas.teoria1 >> turma.alunos[i].notas.teoria2;
        cout << "Informe as notas das duas provas praticas do aluno " << i + 1 << ": ";
        cin >> turma.alunos[i].notas.pratica1 >> turma.alunos[i].notas.pratica2;
    }

    // Calcular estatísticas da turma
    EstatisticasTurma estatisticas = listarAprovadosReprovados(turma);

    // Listar alunos acima da média da turma
    listarAcimaMediaTurma(turma, estatisticas.mediaTurma);

    return 0;
}