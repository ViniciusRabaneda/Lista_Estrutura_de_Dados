#include <stdio.h>

#define CIDADES 7
#define MESES 6

int main() {
    float pluviosidade[CIDADES][MESES];
    float mediaMensalCidade[CIDADES] = {0};
    float mediaMesRegiao[MESES] = {0};
    
    for (int i = 0; i < CIDADES; i++) {
        printf("Digite os índices de pluviosidade da cidade %d:\n", i + 1);
        for (int j = 0; j < MESES; j++) {
            printf("Mes %d: ", j + 1);
            scanf("%f", &pluviosidade[i][j]);
            mediaMensalCidade[i] += pluviosidade[i][j];
            mediaMesRegiao[j] += pluviosidade[i][j];
        }
    }

    for (int i = 0; i < CIDADES; i++) {
        mediaMensalCidade[i] /= MESES;
    }

    for (int j = 0; j < MESES; j++) {
        mediaMesRegiao[j] /= CIDADES;
    }
    
    for (int i = 0; i < CIDADES; i++) {
        printf("Media mensal da cidade %d: %.2f\n", i + 1, mediaMensalCidade[i]);
    }

    for (int j = 0; j < MESES; j++) {
        printf("Media da região no mês %d: %.2f\n", j + 1, mediaMesRegiao[j]);
    }

    return 0;
}
