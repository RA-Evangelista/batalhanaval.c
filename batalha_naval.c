#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --- Definições de Constantes ---
#define TAMANHO 10       // Tabuleiro 10x10
#define AGUA 0           // Representa a água (vazio)
#define NAVIO 3          // Representa a parte do navio
#define SUCESSO 1
#define FALHA 0

// Protótipos de Funções
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao);

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    printf("--- Jogo de Batalha Naval: Nível Avançado ---\n\n");
    printf("Objetivo: Posicionamento validado (Limites e Colisão).\n\n");

    // Lista de navios a serem posicionados: Tamanho e Coordenadas/Orientação
    
    // Navio 1 (Tamanho 5): Horizontal, Posição Válida
    printf("Tentativa 1: Navio 5H em [0][0]... ");
    if (posicionarNavio(tabuleiro, 0, 0, 5, 'H') == SUCESSO) {
        printf("SUCESSO!\n");
    } else {
        printf("FALHA!\n");
    }

    // Navio 2 (Tamanho 3): Vertical, Posição Válida
    printf("Tentativa 2: Navio 3V em [3][1]... ");
    if (posicionarNavio(tabuleiro, 3, 1, 3, 'V') == SUCESSO) {
        printf("SUCESSO!\n");
    } else {
        printf("FALHA!\n");
    }
    
    // Navio 3 (Tamanho 2): Horizontal, Limite Excedido (L = 9, C = 9 + 2 = 11 > 10)
    printf("Tentativa 3: Navio 2H em [9][9]... ");
    if (posicionarNavio(tabuleiro, 9, 9, 2, 'H') == SUCESSO) {
        printf("SUCESSO!\n");
    } else {
        printf("FALHA (Limite Excedido).\n");
    }

    // Navio 4 (Tamanho 3): Vertical, Colisão (Tenta ocupar [3][1] a [5][1])
    printf("Tentativa 4: Navio 3V em [3][0]... ");
    if (posicionarNavio(tabuleiro, 3, 0, 3, 'V') == SUCESSO) {
        printf("SUCESSO!\n");
    } else {
        printf("FALHA (Colisão).\n");
    }
    
    // Navio 5 (Tamanho 2): Horizontal, Posição Válida
    printf("Tentativa 5: Navio 2H em [8][3]... ");
    if (posicionarNavio(tabuleiro, 8, 3, 2, 'H') == SUCESSO) {
        printf("SUCESSO!\n");
    } else {
        printf("FALHA!\n");
    }
    
    // 6. Exibição do Tabuleiro Final
    printf("\nTabuleiro Final com Navios Validados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

// -----------------------------------------------------------------------
// Implementações das Funções
// -----------------------------------------------------------------------

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("-----------------------------------------\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
    printf("Legenda: 0 = Água | 3 = Navio\n");
}


/**
 * Função principal de validação e posicionamento de navios.
 * @param tabuleiro A matriz 10x10 do jogo.
 * @param linha Linha inicial do navio.
 * @param coluna Coluna inicial do navio.
 * @param tamanho O tamanho do navio (2, 3, 5, etc.).
 * @param orientacao 'H' para Horizontal ou 'V' para Vertical.
 * @return 1 (SUCESSO) se o navio foi colocado, 0 (FALHA) caso contrário.
 */
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    
    // Validação inicial de coordenadas
    if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
        return FALHA; // Coordenada inicial fora do tabuleiro
    }

    if (orientacao == 'H') { // Posicionamento Horizontal
        
        // 1. Verificação de Limite Horizontal
        if (coluna + tamanho > TAMANHO) {
            return FALHA; // Excede o limite da direita
        }

        // 2. Verificação de Colisão Horizontal
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiro[linha][coluna + j] == NAVIO) {
                return FALHA; // Colisão encontrada
            }
        }
        
        // Se passou nas validações, posiciona o navio
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[linha][coluna + j] = NAVIO;
        }
        return SUCESSO;
        
    } else if (orientacao == 'V') { // Posicionamento Vertical
        
        // 1. Verificação de Limite Vertical
        if (linha + tamanho > TAMANHO) {
            return FALHA; // Excede o limite de baixo
        }

        // 2. Verificação de Colisão Vertical
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                return FALHA; // Colisão encontrada
            }
        }

        // Se passou nas validações, posiciona o navio
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
        return SUCESSO;
        
    } else {
        // Orientação inválida
        return FALHA;
    }
}
