#include <stdio.h>

int somaRecursiva(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + somaRecursiva(n - 1);
    }
}

int main() {
    int n;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Insira um número maior que zero.\n");
    } else {
        int soma = somaRecursiva(n);
        printf("A somatória de 1 a %d é: %d\n", n, soma);
    }

    return 0;
}
