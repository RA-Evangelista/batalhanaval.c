#include <stdio.h>

// --- Definições de Constantes ---
#define TAMANHO 10       // Tabuleiro 10x10
#define AGUA 0           // Representa a água (vazio)
#define EFEITO 1         // Representa a área de efeito da habilidade
#define NAVIO 3          // Representa a parte do navio

// Ponto central da Habilidade Especial (Ex: Míssil Teleguiado)
#define LINHA_CENTRO 5   // Centro em Linha 5 (índice 5)
#define COLUNA_CENTRO 5  // Centro em Coluna 5 (índice 5)

int main() {
    // 1. Representação e Inicialização do Tabuleiro
    // Criação da matriz 10x10 e inicialização de todas as posições com AGUA (0)
    int tabuleiro[TAMANHO][TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    printf("--- Jogo de Batalha Naval: Nível Intermediário ---\n\n");

    // 2. Posicionamento dos Navios (Tamanho 3) - Mantido do Nível Novato
    
    // Navio 1: Horizontal (Início: [1][4]) -> Posições: [1][4], [1][5], [1][6]
    tabuleiro[1][4] = NAVIO;
    tabuleiro[1][5] = NAVIO;
    tabuleiro[1][6] = NAVIO;

    // Navio 2: Vertical (Início: [5][1]) -> Posições: [5][1], [6][1], [7][1]
    tabuleiro[5][1] = NAVIO;
    tabuleiro[6][1] = NAVIO;
    tabuleiro[7][1] = NAVIO;
    
    // 3. Aplicação da Habilidade Especial (Área de Efeito 3x3)
    printf("Aplicando Habilidade Especial na área central: %d x %d\n\n", LINHA_CENTRO, COLUNA_CENTRO);

    // Loops aninhados para percorrer TODA a matriz e aplicar a lógica condicional
    for (int i = 0; i < TAMANHO; i++) { // Percorre as linhas (0 a 9)
        for (int j = 0; j < TAMANHO; j++) { // Percorre as colunas (0 a 9)
            
            // Verifica a Condição: A posição [i][j] está dentro da área 3x3?
            // A área 3x3 vai de (Centro-1) até (Centro+1)
            if (i >= LINHA_CENTRO - 1 && i <=
