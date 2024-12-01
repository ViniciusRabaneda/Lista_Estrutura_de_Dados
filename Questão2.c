#include <stdio.h>

#define TAMANHO_TABULEIRO 3

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf(" %c ", tabuleiro[linha][coluna]);
            if (coluna < TAMANHO_TABULEIRO - 1) printf("|");
        }
        printf("\n");
        if (linha < TAMANHO_TABULEIRO - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int verificarVencedor(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2] && tabuleiro[linha][0] != ' ') {
            return tabuleiro[linha][0];
        }
    }
    
    for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna] && tabuleiro[0][coluna] != ' ') {
            return tabuleiro[0][coluna];
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return tabuleiro[0][2];
    }

    return 0;
}

int verificarEmpate(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            if (tabuleiro[linha][coluna] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int posicaoLinha, posicaoColuna;
    char jogadorAtual = 'X';
    int simboloVencedor = 0;

    inicializarTabuleiro(tabuleiro);

    printf("Jogo da Velha versão Fatec:\n");

    while (!simboloVencedor && !verificarEmpate(tabuleiro)) {
        exibirTabuleiro(tabuleiro);
        printf("Jogador: %c \n", jogadorAtual);

        do {
            printf("Escolha uma linha entre 0-2: ");
            scanf("%d", &posicaoLinha);
            printf("Escolha uma coluna entre 0-2: ");
            scanf("%d", &posicaoColuna);

            if (posicaoLinha < 0 || posicaoLinha >= TAMANHO_TABULEIRO || posicaoColuna < 0 || posicaoColuna >= TAMANHO_TABULEIRO || tabuleiro[posicaoLinha][posicaoColuna] != ' ') {
                printf("Movimento inválido, tente novamente.\n");
            } else {
                break;
            }
        } while (1);

        tabuleiro[posicaoLinha][posicaoColuna] = jogadorAtual;
        simboloVencedor = verificarVencedor(tabuleiro);
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    exibirTabuleiro(tabuleiro);

    if (simboloVencedor) {
        printf("Parabéns! O jogador %c venceu!\n", simboloVencedor);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
