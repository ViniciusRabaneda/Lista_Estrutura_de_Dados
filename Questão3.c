#include <stdio.h>

#define NUM_ALUNOS 5
#define NUM_PROVAS 4

int main() {
    float notas[NUM_ALUNOS][NUM_PROVAS];
    float mediaAluno[NUM_ALUNOS];
    float somaTurma = 0.0;
    float mediaTurma;

    for (int aluno = 0; aluno < NUM_ALUNOS; aluno++) {
        printf("Digite as ntas do aluno %d:\n", aluno + 1);
        for (int prova = 0; prova < NUM_PROVAS; prova++) {
            printf("Nota da prova %d: ", prova + 1);
            scanf("%f", &notas[aluno][prova]);
        }
    }

    for (int aluno = 0; aluno < NUM_ALUNOS; aluno++) {
        float somaAluno = 0.0;
        for (int prova = 0; prova < NUM_PROVAS; prova++) {
            somaAluno += notas[aluno][prova];
        }
        mediaAluno[aluno] = somaAluno / NUM_PROVAS;
        somaTurma += mediaAluno[aluno];
    }

    mediaTurma = somaTurma / NUM_ALUNOS;

    printf("\nMedias dos alunos:\n");
    for (int aluno = 0; aluno < NUM_ALUNOS; aluno++) {
        printf("Aluno %d: %.2f\n", aluno + 1, mediaAluno[aluno]);
    }

    printf("\nMédia da turm: %.2f\n", mediaTurma);

    return 0;
}