#include <stdio.h>

// Verifica se o navio pode ser posicionado sem sair do tabuleiro ou sobrepor outro
int pode_posicionar(int tabuleiro[10][10], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == 2) {
            l += i;
            c -= i;
        } else if (direcao == 0) {
            c += i;
        } else if (direcao == 1) {
            l += i;
        }

        if (l < 0 || l >= 10 || c < 0 || c >= 10 || tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == 2) {
            l += i;
            c -= i;
        } else if (direcao == 0) {
            c += i;
        } else if (direcao == 1) {
            l += i;
        }

        tabuleiro[l][c] = 3;
    }
}

// Exibe o tabuleiro no console
void exibir_tabuleiro(int tabuleiro[10][10]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com água

    // Posiciona dois navios horizontais/verticais
    if (pode_posicionar(tabuleiro, 0, 0, 0, 0))
        posicionar_navio(tabuleiro, 0, 0, 0, 0);

    if (pode_posicionar(tabuleiro, 5, 2, 1, 0))
        posicionar_navio(tabuleiro, 5, 2, 1, 0);

    // Posiciona dois navios diagonais
    if (pode_posicionar(tabuleiro, 2, 2, 0, 1))
        posicionar_navio(tabuleiro, 2, 2, 0, 1);

    if (pode_posicionar(tabuleiro, 0, 9, 0, 2))
        posicionar_navio(tabuleiro, 0, 9, 0, 2);

    exibir_tabuleiro(tabuleiro);

    return 0;
}