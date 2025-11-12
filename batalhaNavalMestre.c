#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5  // tamanho das matrizes de habilidade

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio][colunaInicio + i] = 3;
    }
}

// Função para posicionar um navio vertical
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio] = 3;
    }
}

// Função para posicionar um navio diagonal principal
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio + i] = 3;
    }
}

// Função para posicionar um navio diagonal secundária
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio - i] = 3;
    }
}

// Função para aplicar uma habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = origemLinha - offset + i;
            int colunaTab = origemColuna - offset + j;

            // Verifica se a posição está dentro do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO && colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0) {
                    tabuleiro[linhaTab][colunaTab] = 5; // marca área afetada pela habilidade
                }
            }
        }
    }
}

// Função para criar a matriz de habilidade "Cone"
void criarHabilidadeCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Valor 1 se estiver dentro do "cone" central
            if (j >= (TAMANHO_HABILIDADE / 2 - i) && j <= (TAMANHO_HABILIDADE / 2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade "Cruz"
void criarHabilidadeCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == meio || j == meio) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade "Octaedro"
void criarHabilidadeOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Losango centrado
            if (abs(i - meio) + abs(j - meio) <= meio) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // área de habilidade
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    posicionarNavioHorizontal(tabuleiro, 1, 2);
    posicionarNavioVertical(tabuleiro, 4, 7);
    posicionarNavioDiagonalPrincipal(tabuleiro, 0, 0);
    posicionarNavioDiagonalSecundaria(tabuleiro, 3, 9);

    // Criar matrizes de habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);     // ponto de origem da habilidade cone
    aplicarHabilidade(tabuleiro, cruz, 5, 5);     // ponto de origem da habilidade cruz
    aplicarHabilidade(tabuleiro, octaedro, 7, 7); // ponto de origem da habilidade octaedro

    // Exibir resultado
    printf("=== TABULEIRO COM NAVIOS E HABILIDADES ===\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
