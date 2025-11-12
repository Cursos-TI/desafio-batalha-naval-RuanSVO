#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // =========================
    // 1. Declaração do tabuleiro (matriz 10x10)
    // =========================
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com 0 (representa água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // 2. Declaração dos navios (vetores)
    // =========================
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3}; // representado pelo número 3
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // =========================
    // 3. Coordenadas iniciais dos navios
    // =========================
    // As coordenadas são definidas diretamente no código
    // (linha e coluna começam em 0)
    int linhaInicioHorizontal = 2;
    int colunaInicioHorizontal = 4;

    int linhaInicioVertical = 5;
    int colunaInicioVertical = 7;

    // =========================
    // 4. Posicionamento do navio horizontal
    // =========================
    // Verifica se o navio cabe no tabuleiro
    if (colunaInicioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaInicioHorizontal][colunaInicioHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: O navio horizontal não cabe no tabuleiro!\n");
    }

    // =========================
    // 5. Posicionamento do navio vertical
    // =========================
    // Verifica se o navio cabe no tabuleiro e não se sobrepõe
    if (linhaInicioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se há sobreposição com outro navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicioVertical + i][colunaInicioVertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Se não houver sobreposição, posiciona o navio
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaInicioVertical + i][colunaInicioVertical] = navioVertical[i];
            }
        } else {
            printf("Erro: O navio vertical se sobrepõe ao navio horizontal!\n");
        }

    } else {
        printf("Erro: O navio vertical não cabe no tabuleiro!\n");
    }

    // =========================
    // 6. Exibição do tabuleiro
    // =========================
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Parte de um navio\n");

    return 0;
}
