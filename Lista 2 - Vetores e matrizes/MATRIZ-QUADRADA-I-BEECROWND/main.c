#include <stdio.h>
#include <stdlib.h>

int **criarMatriz(int tamanho) {
    int **matriz = (int *)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        matriz[i] = (int *)malloc(tamanho * sizeof(int));
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = 1;
        }
    }
    return matriz;
}

void transformarCamada(int camada, int **matriz, int tamanho) {
    int indiceControl = camada - 1;
    for (int linhas = indiceControl; linhas < tamanho - indiceControl; linhas++) {
        for (int colunas = indiceControl; colunas < tamanho - indiceControl; colunas++) {
            matriz[linhas][colunas] = camada;
        }
    }
}

void mostrar(int **matriz, int tamanho) {
    for (int linha = 0; linha < tamanho; linha++) {
        printf(" %d", matriz[linha][0]);
        for (int coluna = 1; coluna < tamanho; coluna++) {
            printf(" %d", matriz[linha][coluna]);
        }
        printf("\n");
    }
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);
    while (tamanho != 0) {
        int **matriz = criarMatriz(tamanho);
        for (int camada = 2; camada < tamanho; camada++) {
            transformarCamada(camada, matriz, tamanho);
        }
        mostrar(matriz, tamanho);
        for (int i = 0; i < tamanho; i++) {
            free(matriz[i]);
        }
        free(matriz);
        scanf("%d", &tamanho);
    }
    return 0;
}