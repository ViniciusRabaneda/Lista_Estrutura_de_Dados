#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int maiorValor, menorValor;

    printf("Digite os valores da matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    maiorValor = matriz[0][0];
    menorValor = matriz[0][0];
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] > maiorValor) {
                maiorValor = matriz[i][j];
            }
            if (matriz[i][j] < menorValor) {
                menorValor = matriz[i][j];
            }
        }
    }

    printf("\nMaior valor: %d\n", maiorValor);
    printf("Menor valor: %d\n", menorValor);
    return 0;
}
