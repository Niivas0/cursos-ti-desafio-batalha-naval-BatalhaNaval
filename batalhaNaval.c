#include <stdio.h>
#include <stdlib.h>

// Exibe o tabuleiro com água (0), navio (3) e área de habilidade (5)
void exibir_tabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Aplica uma matriz de habilidade ao tabuleiro, centrando no ponto de origem
void aplicar_habilidade(int tabuleiro[10][10], int habilidade[5][5], int origem_linha, int origem_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origem_linha - 2 + i;
            int coluna = origem_coluna - 2 + j;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

// Gera matriz de habilidade em forma de cone
void gerar_cone(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 2) matriz[i][j] = 1;
            else if (i == 1 && (j >= 1 && j <= 3)) matriz[i][j] = 1;
            else if (i == 2 && (j >= 0 && j <= 4)) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

// Gera matriz de habilidade em forma de cruz
void gerar_cruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

// Gera matriz de habilidade em forma de octaedro (losango)
void gerar_octaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[10][10] = {0};

    // Posiciona navios fixos
    tabuleiro[0][0] = 3;
    tabuleiro[0][1] = 3;
    tabuleiro[0][2] = 3;
    tabuleiro[5][2] = 3;
    tabuleiro[6][2] = 3;
    tabuleiro[7][2] = 3;

    // Matrizes de habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];

    gerar_cone(cone);
    gerar_cruz(cruz);
    gerar_octaedro(octaedro);

    // Aplica habilidades em pontos fixos
    aplicar_habilidade(tabuleiro, cone, 2, 2);
    aplicar_habilidade(tabuleiro, cruz, 5, 5);
    aplicar_habilidade(tabuleiro, octaedro, 7, 7);

    // Exibe resultado final
    exibir_tabuleiro(tabuleiro);

    return 0;
}
