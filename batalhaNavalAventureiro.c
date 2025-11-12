#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar sobreposição
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] != 0;
}

// Função para posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    if (colunaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // fora do tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linhaInicio, colunaInicio + i)) return 0; // sobreposição
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio][colunaInicio + i] = 3;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    if (linhaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // fora do tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linhaInicio + i, colunaInicio)) return 0; // sobreposição
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonal principal (linha e coluna aumentam)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    if (linhaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO || colunaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linhaInicio + i, colunaInicio + i)) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio + i] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonal secundária (linha aumenta, coluna diminui)
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    if (linhaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO || colunaInicio - TAMANHO_NAVIO + 1 < 0) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linhaInicio + i, colunaInicio - i)) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio - i] = 3;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // Posicionamento dos navios
    // =========================
    if (!posicionarNavioHorizontal(tabuleiro, 1, 2)) {
        printf("Erro ao posicionar navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, 4, 7)) {
        printf("Erro ao posicionar navio vertical!\n");
    }
    if (!posicionarNavioDiagonalPrincipal(tabuleiro, 0, 0)) {
        printf("Erro ao posicionar navio diagonal principal!\n");
    }
    if (!posicionarNavioDiagonalSecundaria(tabuleiro, 3, 9)) {
        printf("Erro ao posicionar navio diagonal secundária!\n");
    }

    // =========================
    // Exibição do tabuleiro
    // =========================
    printf("\n=== TABULEIRO BATALHA NAVAL COMPLETO ===\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Parte de um navio\n");

    return 0;
}
