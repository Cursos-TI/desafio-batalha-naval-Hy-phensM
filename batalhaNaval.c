
#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// Definição do tamanho do tabuleiro e das habilidades
#define TAMANHO_TABULEIRO 10
#define TAMANHO_CONE 5
#define TAMANHO_CRUZ 5
#define TAMANHO_OCTAEDRO 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
    // Posicionamento dos navios (simplificado para este desafio)
    tabuleiro[2][3] = 3;
    tabuleiro[6][1] = 3;
    tabuleiro[8][7] = 3;
}

// Função para criar a matriz de habilidade em forma de cone
void criarCone(int cone[TAMANHO_CONE][TAMANHO_CONE]) {
    int centro = TAMANHO_CONE / 2;
    for (int i = 0; i < TAMANHO_CONE; i++) {
        for (int j = 0; j < TAMANHO_CONE; j++) {
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criarCruz(int cruz[TAMANHO_CRUZ][TAMANHO_CRUZ]) {
    int centro = TAMANHO_CRUZ / 2;
    for (int i = 0; i < TAMANHO_CRUZ; i++) {
        for (int j = 0; j < TAMANHO_CRUZ; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int octaedro[TAMANHO_OCTAEDRO][TAMANHO_OCTAEDRO]) {
    int centro = TAMANHO_OCTAEDRO / 2;
    for (int i = 0; i < TAMANHO_OCTAEDRO; i++) {
        for (int j = 0; j < TAMANHO_OCTAEDRO; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a habilidade ao tabuleiro
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int cone[TAMANHO_CONE][TAMANHO_CONE], int linhaOrigem, int colunaOrigem) {
    int centroHabilidade = TAMANHO_CONE / 2;
    for (int i = 0; i < TAMANHO_CONE; i++) {
        for (int j = 0; j < TAMANHO_CONE; j++) {
            if (cone[i][j] == 1) {
                int linhaTabuleiro = linhaOrigem - centroHabilidade + i;
                int colunaTabuleiro = colunaOrigem - centroHabilidade + j;
                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // 5 representa área afetada
                }
            }
        }
    }
}

// Função para aplicar a habilidade cruz ao tabuleiro
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int cruz[TAMANHO_CRUZ][TAMANHO_CRUZ], int linhaOrigem, int colunaOrigem) {
    int centroHabilidade = TAMANHO_CRUZ / 2;
    for (int i = 0; i < TAMANHO_CRUZ; i++) {
        for (int j = 0; j < TAMANHO_CRUZ; j++) {
            if (cruz[i][j] == 1) {
                int linhaTabuleiro = linhaOrigem - centroHabilidade + i;
                int colunaTabuleiro = colunaOrigem - centroHabilidade + j;
                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // 5 representa área afetada
                }
            }
        }
    }
}

// Função para aplicar a habilidade octaedro ao tabuleiro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int octaedro[TAMANHO_OCTAEDRO][TAMANHO_OCTAEDRO], int linhaOrigem, int colunaOrigem) {
    int centroHabilidade = TAMANHO_OCTAEDRO / 2;
    for (int i = 0; i < TAMANHO_OCTAEDRO; i++) {
        for (int j = 0; j < TAMANHO_OCTAEDRO; j++) {
            if (octaedro[i][j] == 1) {
                int linhaTabuleiro = linhaOrigem - centroHabilidade + i;
                int colunaTabuleiro = colunaOrigem - centroHabilidade + j;
                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // 5 representa área afetada
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case 0:
                    printf(". "); // Água
                    break;
                case 3:
                    printf("N "); // Navio
                    break;
                case 5:
                    printf("* "); // Área afetada
                    break;
                default:
                    printf("? "); // Erro ou estado desconhecido
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_CONE][TAMANHO_CONE];
    int cruz[TAMANHO_CRUZ][TAMANHO_CRUZ];
    int octaedro[TAMANHO_OCTAEDRO][TAMANHO_OCTAEDRO];

    inicializarTabuleiro(tabuleiro);
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Definindo os pontos de origem das habilidades no tabuleiro
    int linhaOrigemCone = 1;
    int colunaOrigemCone = 2;
    int linhaOrigemCruz = 4;
    int colunaOrigemCruz = 4;
    int linhaOrigemOctaedro = 7;
    int colunaOrigemOctaedro = 2;

    // Aplicando as habilidades ao tabuleiro
    aplicarHabilidadeCone(tabuleiro, cone, linhaOrigemCone, colunaOrigemCone);
    aplicarHabilidadeCruz(tabuleiro, cruz, linhaOrigemCruz, colunaOrigemCruz);
    aplicarHabilidadeOctaedro(tabuleiro, octaedro, linhaOrigemOctaedro, colunaOrigemOctaedro);

    // Exibindo o tabuleiro com as áreas de efeito das habilidades
    printf("Tabuleiro com as áreas de efeito das habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}