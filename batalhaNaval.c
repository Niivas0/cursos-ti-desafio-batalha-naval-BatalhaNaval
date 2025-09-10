#include <stdio.h>

int main() {
    // Constantes para configuração do jogo
    int tabuleiro[10][10];
    int i, j;


    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;


    // Posiciona navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
    }

    // Posiciona navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
    }



    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}