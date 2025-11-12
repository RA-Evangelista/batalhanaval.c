#include <stdio.h>

// Definir o tamanho do tabuleiro
#define TAMANHO 10
// Valor para representar ÁGUA
#define AGUA 0
// Valor para representar PARTE DO NAVIO (3 posições)
#define NAVIO 3

int main() {
    // 1. Representação do Tabuleiro
    // Criação da matriz 10x10 e inicialização de todas as posições com AGUA (0)
    int tabuleiro[TAMANHO][TAMANHO] = {AGUA}; // O C permite inicializar tudo com zero assim

    printf("--- Jogo de Batalha Naval: Nível Novato ---\n\n");

    // 2. Posicionamento dos Navios (Tamanho 3)
    
    // Navio 1: Horizontal
    // Início da posição: Linha 1, Coluna 4 (índices [1][4])
    // Posições: [1][4], [1][5], [1][6]
    int linha_navio_h = 1;
    int coluna_inicio_navio_h = 4;
    
    // Loop para posicionar o navio horizontalmente
    for (int i = 0; i < 3; i++) {
        // Altera o valor da matriz para NAVIO (3) nas 3 colunas seguintes
        tabuleiro[linha_navio_h][coluna_inicio_navio_h + i] = NAVIO;
    }

    // Navio 2: Vertical
    // Início da posição: Linha 5, Coluna 1 (índices [5][1])
    // Posições: [5][1], [6][1], [7][1]
    int linha_inicio_navio_v = 5;
    int coluna_navio_v = 1;
    
    // Loop para posicionar o navio verticalmente
    for (int i = 0; i < 3; i++) {
        // Altera o valor da matriz para NAVIO (3) nas 3 linhas seguintes
        tabuleiro[linha_inicio_navio_v + i][coluna_navio_v] = NAVIO;
    }
    
    // 3. Exibição do Tabuleiro
    printf("Tabuleiro 10x10:\n");
    printf("-----------------------------------------\n");
    
    // Loops aninhados para percorrer e exibir a matriz
    for (int i = 0; i < TAMANHO; i++) { // Percorre as linhas
        for (int j = 0; j < TAMANHO; j++) { // Percorre as colunas
            // Imprime o valor da célula seguido de um espaço
            printf("%d ", tabuleiro[i][j]); 
        }
        // Quebra de linha após o término de uma linha do tabuleiro
        printf("\n");
    }
    
    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Parte do Navio\n");
    printf("-----------------------------------------\n");

    return 0;
}
